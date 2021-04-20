#ifndef COLOR_H_

#define COLOR_H_
#include <sstream>
#include "../Utils/utils.h"
#include "../Vec3/vec3.h"

// DEPRECATED IN FAVOR OF void write_color(std::ostringstream &out,color pixel_color, int samples_per_pixel);
void write_color(std::ostringstream &out,color pixel_color);

void write_color(std::ostringstream &out,color pixel_color, int samples_per_pixel);

#endif