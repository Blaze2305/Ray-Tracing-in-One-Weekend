// i couldnt get magick c++ api to work in windows or WSL , so i scrapped the idea of outputting a png
// instead i'll ouput a ppm and convert it to png manually
// might revisit this in the future. not sure tho
// #include <Magick++.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "src/Color/color.h"
#include "src/Vec3/vec3.h"

std::ofstream outputFile;

int main() {

    // Image
    const int image_width = 1080;
    const int image_height = 1080;
	std::ostringstream out;


    // Magick::Image image;



    // Render
    out << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr<<"\rScan Lines remaining: "<<j<<" "<<std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.25;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            out << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    std::cerr<<"Done!\n";

    // convert the image from string to a Blob
    // got the solution form here https://stackoverflow.com/questions/26097220/how-to-construct-image-from-char-buffer-or-string-in-magick
    // Magick::Blob blob(static_cast<const void *>(out.str().c_str()),out.str().size());
    // image.read(blob);
	// image.write("logo.png");

    // use the imageMagick cli to convert the ppm to a png or jpeg.
    // $ magick output.ppm output.png
	outputFile.open("output.ppm",std::ios::trunc);
	outputFile<<out.str();
    
}