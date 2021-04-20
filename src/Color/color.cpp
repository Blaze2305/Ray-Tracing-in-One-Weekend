#include "color.h"

void write_color(std::ostringstream &out,color pixel_color){
	out << static_cast<int>(255.999 * pixel_color.x()) << " "
		<< static_cast<int>(255.999 * pixel_color.y()) << " "
		<< static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

// To handle the multi-sampled color computation, we'll update the write_color() function. 
// Rather than adding in a fractional contribution each time we accumulate more light to the color, 
// just add the full color each iteration, and then perform a single divide at the end (by the number of samples) 
// when writing out the color.
void write_color(std::ostringstream &out,color pixel_color, int samples_per_pixel){
	double r = pixel_color.x();
	double g = pixel_color.y();
	double b = pixel_color.z();

	// divide the color by the number of samples and
	double scale = 1.0/samples_per_pixel;
	r *= scale;
	g *= scale;
	b *= scale;

	out << static_cast<int>(256 * clamp(r,0.0,0.999)) << " "
		<< static_cast<int>(256 * clamp(g,0.0,0.999)) << " "
		<< static_cast<int>(256 * clamp(b,0.0,0.999)) << '\n';
}