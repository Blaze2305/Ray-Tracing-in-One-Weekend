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
		vec3 direcion() const;

		// get the point where the ray is at some give distance t 
		// from the origin along the direction vector 
		point3 at(double t) const;
};

#endif