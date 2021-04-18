#ifndef HITTABLE_H_

#define HITTABLE_H_ 

#include "../Ray/ray.h"
#include "../Vec3/vec3.h"

// maintain  a record of the ray hits to the object
struct hit_record{
	point3 p;
	vec3 normal;
	double t;
};


// an abstract class to signify that the object is hittable by a ray.
class hittable{
	public:
		virtual bool hit(const ray& r,double t_min, double t_max, hit_record& rec) const  = 0;
};


#endif