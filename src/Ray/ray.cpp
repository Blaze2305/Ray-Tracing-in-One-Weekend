#include "ray.h"

// -------------- CLASS METHODS ----------------

point3 ray::origin() const{
	return this->orig;
}

vec3 ray::direcion() const{
	return this->direc;
}

point3 ray::at(double t) const{
	return orig + t*direc;
}

// ------------------------------------------------