#include "vec3.h"

// ----------------------- CLASS FUNCTIONS -------------------------------------------
double vec3::x() const{
	return axis[0];
}

double vec3::y() const{
	return axis[1];
}

double vec3::z() const{
	return axis[2];
}

vec3 vec3::operator-() const {
	return vec3(-1*axis[0], -1*axis[1], -1*axis[2]);
}

double vec3::operator[](int i) const{
	return axis[i];
}

double& vec3::operator[](int i){
	return axis[i];
}

vec3& vec3::operator+=(const vec3 &v){
	axis[0]+=v.axis[0];	
	axis[1]+=v.axis[1];	
	axis[2]+=v.axis[2];
	return *this;	
}

vec3& vec3::operator*=(const double t){
	axis[0]*=t;
	axis[1]*=t;
	axis[2]*=t;
	return *this;
}

vec3& vec3::operator/=(const double t){
	axis[0]/=t;
	axis[1]/=t;
	axis[2]/=t;
	return *this;
}

double vec3::length() const{
	return std::sqrt(length_squared());
}

double vec3::length_squared() const{
	return axis[0]*axis[0] +  axis[1]*axis[1] + axis[2]*axis[2] ;
}

// -----------------------------------------------------------------------------------

inline std::ostream& operator<<(std::ostream&out, const vec3 &v){
	return out << v.axis[0] << " "<< v.axis[1] << " " << v.axis[2] << '\n';
}

inline vec3 operator+(const vec3 &u, const vec3 &v){
	return vec3(u.axis[0] + v.axis[0], u.axis[1] + v.axis[1],u.axis[2] + v.axis[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v){
	return vec3(u.axis[0] - v.axis[0], u.axis[1] - v.axis[1],u.axis[2] - v.axis[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v){
	return vec3(u.axis[0] * v.axis[0], u.axis[1] * v.axis[1],u.axis[2] * v.axis[2]);
}

inline vec3 operator*(const double t,const vec3 &v){
	return vec3(v.axis[0] * t, v.axis[1] * t,v.axis[2] * t);
}

inline vec3 operator*(const vec3 &u,const double t){
	return u * t;
}

inline vec3 operator/(const vec3 &u,const double t){
	return (1/t) * u;
}

inline double dot(const vec3 &u,const vec3 &v){
	return u.axis[0] * v.axis[0] + u.axis[1] * v.axis[1] + u.axis[2] * v.axis[2];
}

inline vec3 cross(const vec3 &u,const vec3 &v){
	return vec3(u.axis[1]*v.axis[2] - u.axis[2]*v.axis[1],
				u.axis[0]*v.axis[2] - u.axis[2]*v.axis[0],
				u.axis[0]*v.axis[1] - u.axis[1]*v.axis[0]);
}

inline vec3 unit_vector(const vec3 &u){
	return u / u.length();
}