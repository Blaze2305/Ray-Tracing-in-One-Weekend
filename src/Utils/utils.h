#ifndef UTILS_H_

#define UTILS_H_

#include <cmath>
#include <limits>
#include <memory>
#include <random>


const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// ----- UTILITY FUNCTIONS -----
inline double degree_to_radians(double degree){
	return degree* pi /180.0;
}

// random number generator
inline double random_double(){
	// create a uniform distribution of real numbers between 0 and 1;
	static std::uniform_real_distribution<double> distribution(0,1);
	// create a random generator engine
	static std::mt19937 generator;

	return distribution(generator);
}

// clamp the value of x between the given min and max values
inline double clamp(double x, double min, double max){
	if(x<min){
		return min;
	}
	if (x>max){
		return max;
	}
	return x;
}

#endif