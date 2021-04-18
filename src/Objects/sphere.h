#ifndef SPHERE_H_

#define SPHERE_H_

#include <cmath>
#include "hittable.h"
#include "../Vec3/vec3.h"


class sphere : public  hittable{
	public:
		point3 center;
		double radius;

		sphere(){}

		sphere(point3& cen,double rad):center(cen),radius(rad){}

		virtual bool hit(const ray& r,double t_min, double t_max, hit_record& rec) const override;
};

#endif