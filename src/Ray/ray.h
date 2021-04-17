#ifndef RAY_H_

#define RAY_H_

#include "../Vec3/vec3.h"

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

// The ray_color(ray) function linearly blends white and blue depending on the height of the y coordinate after scaling the ray direction to unit length 
// (so −1.0<y<1.0). Because we're looking at the y height after normalizing the vector, you'll notice a horizontal gradient to the color in addition to the
//  vertical gradient.
// The lerp (liner interpolation ) is of the from :
//  			blendedValue=(1−t)⋅startValue+t⋅endValue,
color ray_color(const ray& r);

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