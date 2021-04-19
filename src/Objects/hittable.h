#ifndef HITTABLE_H_

#define HITTABLE_H_ 

#include "../Ray/ray.h"
#include "../Vec3/vec3.h"

// maintain  a record of the ray hits to the object
struct hit_record{
	point3 p;
	vec3 normal;
	double t;
	bool front_face;

	// https://raytracing.github.io/books/RayTracingInOneWeekend.html#surfacenormalsandmultipleobjects/frontfacesversusbackfaces
	// we need to choose whether the normal we get is facing inwards the object or outwards. 
	// this is neccesary to determine what to color/shade
	// if we decide that the normal is alwas pointing outwards, to determine whether the ray is inside or outside the object, we
	//  use the dotproduct. the rayDirection . outwardNormal will be -ve if outside the sphere
	// else it is +ve
	inline void set_face_normal(const ray& r , const vec3& outward_normal){
		front_face = dot(r.direction(),outward_normal) < 0;
		normal = front_face ? outward_normal : - outward_normal;
	}
};


// an abstract class to signify that the object is hittable by a ray.
class hittable{
	public:
		virtual bool hit(const ray& r,double t_min, double t_max, hit_record& rec) const  = 0;
};


#endif