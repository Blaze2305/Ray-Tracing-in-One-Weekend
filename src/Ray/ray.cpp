#include "ray.h"

// -------------- CLASS METHODS ----------------

point3 ray::origin() const{
	return this->orig;
}

vec3 ray::direction() const{
	return this->direc;
}

point3 ray::at(double t) const{
	return orig + t*direc;
}

// ------------------------------------------------

color ray_color(const ray& r){
	if(hit_sphere(point3(0,0,1),0.6,r)){
		return color(1,0,0);
	}
	vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

bool hit_sphere(const point3 & center,double radius,const ray& r){
	// expanded form of the vector equation of the sphere
	// ==> t^2(b.b) + 2tb.(A-C) + (A - C).(A - C) - r^2 = 0
	// where C is the center of the sphere

	// oc is equal to (A - C)
	vec3 oc = r.origin() - center;

	// a => b . b where b = ray direction vec
	double a = dot(r.direction(),r.direction());

	// b => 2 * b . (A - C) , b = ray direction vec
	double b = 2 * dot(r.direction(),oc);

	// c => (A - C).(A - C) - radius^2
	double c = dot(oc,oc) - radius * radius;

	double discriminant = b * b - 4 * a * c;
	// reutrn true if roots exist
	return discriminant>0;
}