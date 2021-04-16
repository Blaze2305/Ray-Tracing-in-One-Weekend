#ifndef RAY_H_

#define RAY_H_

#include "../Vec3/vec3.h"

class ray{
	public:
		point3 origin;
		vec3 direction;

		ray(){}

		ray(const point3& ori ,const vec3 &direc);
};

#endif