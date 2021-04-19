// i couldnt get magick c++ api to work in windows or WSL , so i scrapped the idea of outputting a png
// instead i'll ouput a ppm and convert it to png manually
// might revisit this in the future. not sure tho
// #include <Magick++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

#include "src/Color/color.h"
#include "src/Vec3/vec3.h"
#include "src/Objects/hittable_list.h"
#include "src/Objects/hittable.h"
#include "src/Objects/sphere.h"

std::ofstream outputFile;

int main() {

    // Image
    // const int image_width = 1080;
    // const int image_height = 1080;
    // Magick::Image image;

    // Image
    const double aspect_ratio = 16.0/9.0;
    const int image_width = 1080;
    const int image_height = static_cast<int>(image_width/aspect_ratio);
	std::ostringstream out;


    // World
    hittable_list world;
    world.add(std::make_shared<sphere>(point3(0,0,-1),0.5));
    world.add(std::make_shared<sphere>(point3(0.4,0,-0.5),0.08));
    world.add(std::make_shared<sphere>(point3(0,-100.5,-1),100));


    // Camera

    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    point3 origin = point3(0,0,0);
    vec3 horizontal = vec3(viewport_width,0,0);
    vec3 vertical = vec3(0,viewport_height,0);
    vec3 lower_left_corner = origin - horizontal/2 - vertical/2 -vec3(0,0,focal_length);


    // Render
    // write the PPM header data 
    // since we have Ascii RGB color we go with P3
    out << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cout<<"\rScan Lines remaining: "<<j<<" "<<std::flush;
        for (int i = 0; i < image_width; ++i) {
            double u =double(i)/(image_width-1);
            double v =double(j)/(image_height-1);
            ray r(origin,lower_left_corner + u * horizontal + v * vertical - origin);
            // color pixel_color(double(i)/(image_width-1),double(j) / (image_height-1),0.25);
            color pixel_color = ray_color(r,world);
            write_color(out,pixel_color);
        }
    }

    std::cout<<"\nDone!\n";

    // convert the image from string to a Blob
    // got the solution form here https://stackoverflow.com/questions/26097220/how-to-construct-image-from-char-buffer-or-string-in-magick
    // Magick::Blob blob(static_cast<const void *>(out.str().c_str()),out.str().size());
    // image.read(blob);
	// image.write("logo.png");

    // Write the ppm data to the file.
    // NOTE : use the imageMagick cli to convert the ppm to a png or jpeg.
    //        $ magick output.ppm output.png
	outputFile.open("output.ppm",std::ios::trunc);
	outputFile<<out.str();
    outputFile.close();
}