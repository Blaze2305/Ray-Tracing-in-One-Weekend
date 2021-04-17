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
	vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}