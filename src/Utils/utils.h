#ifndef UTILS_H_

#define UTILS_H_

#include <cmath>
#include <limits>
#include <memory>


const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// --- UTILITY FUNCTIONS-----
inline double degree_to_radians(double degree){
	return degree* pi /180.0;
}

#endif