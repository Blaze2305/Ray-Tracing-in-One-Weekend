#ifndef VECTOR_H_

#define VECTOR_H_

#include <cmath>
#include <iostream>
class vec3 {
	public:
		double axis[3];

		// default vector
		vec3():axis{0,0,0}{};
		// vector with x y z given
		vec3(double x,double y,double z): axis{x,y,z}{};


		// axis getters
		double x() const;
		double y() const;
		double z() const;

		// operator overloading

		// negate the vector
		vec3 operator-() const;
		// get the ith axis  as a const
		double operator[](int i) const;
		// get the reference to the ith axis
		double& operator[](int i);

		// += operator
		vec3& operator+=(const vec3 &v);
		// *= operator
		vec3& operator*=(const double t);
		// /= operator
		vec3& operator/=(const double t);


		// vector length functions

		double length() const;

		double length_squared() const;
};

// overload the << operator to push to cout
inline std::ostream& operator<<(std::ostream&out, const vec3 &v);

// overload addition
inline vec3 operator+(const vec3 &u,const vec3 &v);

// overload subtraction
inline vec3 operator-(const vec3 &u,const vec3 &v);

// overload multiplication 
// NOTE:  This refers to multiplication of the two vectors , axis wise
// it is not the cross product or the dot product
inline vec3 operator*(const vec3 &u,const vec3 &v);

// overload multiplication for number and vector
// NOTE: This refers to the normal scalar multiplication
inline vec3 operator*(const double t,const vec3 &v);

// overload multiplication for vector and number
// NOTE: This is different from above in position, ie above is <vec3>*<double> 
// this is <double>*<vec3>
inline vec3 operator*(const vec3 &u,const double t);

// overload division for vector and number
inline vec3 operator/(const vec3 &u,const double t);

// dot product of two vectors
inline double dot(const vec3 &u, const vec3 &v);

// cross product of two vectors
inline vec3 cross(const vec3 &u,const vec3 &v);

// get the vector in its unit length
inline vec3 unit_vector(const vec3 &u);

// type alias for the vectors
using point3 = vec3;
using color  = vec3;

#endif