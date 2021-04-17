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
	double intersection = hit_sphere(point3(0,0,-1),0.4,r);
	// we're only handling t>0 because t is the distance on the rays direction vector at where the intersection happens
	// so if t is -ve that means that the intersection is behind us , and that is not something we want to show on the screen
	// so if it is less than 0 , we just ignore it as it wont be visible anyway
	if (intersection > 0){
		// the normal vector at any point P is (P - C) where C is the center of the sphere
		vec3 N = unit_vector(r.at(intersection) - vec3(0,0,-1));
		return 0.5*color(N.x()+1, N.y()+1, N.z()+1);
	}
	vec3 unit_direction = unit_vector(r.direction());
    double t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

double hit_sphere(const point3 & center,double radius,const ray& r){
	// expanded form of the vector equation of the sphere
	// ==> t^2(b.b) + 2tb.(A-C) + (A - C).(A - C) - r^2 = 0
	// where C is the center of the sphere

	// oc is equal to (A - C)
	vec3 oc = r.origin() - center;

	// a => b . b where b = ray direction vec
	// a vector dotted with itself is the same as its length squared
	// so we replace b.b with b.direction().length_squared()
	double a = r.direction().length_squared();

	// b => 2 * b . (A - C) , b = ray direction vec
	double half_b = dot(r.direction(),oc);

	// c => (A - C).(A - C) - radius^2
	double c = oc.length_squared() - radius * radius;

	double discriminant = half_b * half_b - a * c;
	
	
	// returning boolean true or false will give all the sides of the sphere the same color
	// so we wont get any shading
	// to get shading we return one of the closests roots and find the normal at that point
	// and use that to shade the sphere
	// // reutrn true if roots exist
	// return discriminant>0;


	if(discriminant<0){
		return -1;
	}else{
		return (-half_b- sqrt(discriminant))/a;
	}
}