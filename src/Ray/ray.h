#ifndef RAY_H_

#define RAY_H_

#include "../Vec3/vec3.h"

class ray{
	public:
		point3 orig;
		vec3 direc;

		ray(){}

		ray(const point3& ori ,const vec3 &direc):orig(ori),direc(direc){};

		// get the origin point
		point3 origin() const;

		// get the firection vector
		vec3 direction() const;

		// get the point where the ray is at some give distance t 
		// from the origin along the direction vector 
		point3 at(double t) const;
};

// The ray_color(ray) function linearly blends white and blue depending on the height of the y coordinate after scaling the ray direction to unit length 
// (so −1.0<y<1.0). Because we're looking at the y height after normalizing the vector, you'll notice a horizontal gradient to the color in addition to the
//  vertical gradient.
// The lerp (liner interpolation ) is of the from :
//  			blendedValue=(1−t)⋅startValue+t⋅endValue,
color ray_color(const ray& r);


#endif