#ifndef VECTOR_H_

#define VECTOR_H_

#include <cmath>
#include <iostream>
class vec3 {
	public:
		float axis[3];

		// default vector
		vec3():axis{0,0,0}{};
		// vector with x y z given
		vec3(float x,float y,float z): axis{x,y,z}{};


		// axis getters
		double x() const;
		double y() const;
		double z() const;

		// operator overloading

		// negate the vector
		vec3 operator-() const;
		// get the ith axis  as a const
		float operator[](int i) const;
		// get the reference to the ith axis
		float& operator[](int i);

		// += operator
		vec3& operator+=(const vec3 &v);
		// *= operator
		vec3& operator*=(const float t);
		// /= operator
		vec3& operator/=(const float t);


		// vector length functions

		float length() const;

		float length_squared() const;
};



// type alias for the vectors
using point3 = vec3;
using color  = vec3;

#endif