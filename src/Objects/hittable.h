#ifndef HITTABLE_H_

#define HITTABLE_H_ 

#include "../Vec3/vec3.h"
#include "../Utils/utils.h"

class ray{
	public:
		point3 orig;
		vec3 direc;

		ray(){}

		ray(const point3& ori ,const vec3 &direc):orig(ori),direc(direc){};

		// get the origin point
		point3 origin() const;

		// get the firection vector
		vec3 direction() const;

		// get the point where the ray is at some give distance t 
		// from the origin along the direction vector 
		point3 at(double t) const;
};
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

// The ray_color(ray) function linearly blends white and blue depending on the height of the y coordinate after scaling the ray direction to unit length 
// (so −1.0<y<1.0). Because we're looking at the y height after normalizing the vector, you'll notice a horizontal gradient to the color in addition to the
//  vertical gradient.
// The lerp (liner interpolation ) is of the from :
//  			blendedValue=(1−t)⋅startValue+t⋅endValue,

// DEPRECATED in favor of ray_color(const ray& r,con)
color ray_color(const ray& r);

color ray_color(const ray& r, const hittable& world);


// Function to check if the ray intersects the sphere with a given center and radius.
// The math for the function is explained in the link below
// https://raytracing.github.io/books/RayTracingInOneWeekend.html#addingasphere/ray-sphereintersection
// But TL;DR:  equation of a sphere is (x-Cx)^2 + (y-Cy)^2 + (z-Cz)^2 = r^2  for a sphere with radius r and center C(Cx,Cy,Cz)
// The vector form is  (P-C).(P-C) = r^2 [ note . is the dot product]
// but P = (A + t*b)  where A = origin of the ray and B is the direction vector
//  so the vector equation of the circle becomes  (A+ tb - C).(A + tb -C) = r^2
// expanding this gives us t^2(b.b) + 2tb.(A-C) + (A - C).(A - C) - r^2 = 0
// this is of the form a^2 + b^2 + 2ab = 0; a  quadratic equation
// So if the ray intersects the sphere there shoudl exists roots for the equation to give the values of t
// for roots to exist we check the determinant D = b^2 - 4ac. if D > 0 then it intersects
double hit_sphere(const point3& center, double radius, const ray& r);
#endif