#include "sphere.h"

// -------------- CLASS METHODS ----------------

bool sphere::hit(const ray& r,double t_min, double t_max, hit_record& rec) const {
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

	// if no roots exist , there's no intersection so we return false
	if(discriminant<0){
		return false;
	}


	// get one root and check if it lies between the min and max t
	//  the hit only “counts” if tmin<t<tmax
	double root =  (-half_b - std::sqrt(discriminant))/a;
	if(root < t_min || t_max < root){
		// if it doesnt , find the other root and do the same check
		root = (-half_b + std::sqrt(discriminant))/a;
		if(root < t_min || t_max < root){
			return false;
		}
	}

	// if a root is found and passes the checks , set the hit record values
	// the distance at which the root is there is root,
	rec.t = root;
	// the the point at that position is P =  A + bt
	// we get that using ray::at(t)
	rec.p = r.at(root);
	// the normal at a point P is P - C, we divide by the radius to make it a unit vector
	vec3 outward_normal = (rec.p - center)/radius;

	// set the face normal to always be the outwards facing normal
	rec.set_face_normal(r,outward_normal);

	return true;
}

// ---------------------------------------------