#ifndef RAY_H_
#define RAY_H_

#include "vect.h"

namespace raytracer{

class Ray {
public:
	Vect origin;
	Vect dir;

public:
	constexpr
	Ray(const Vect &origin, const Vect &dir) :
			origin(origin),
			dir(dir){}
};

} //namespace raytracer

#endif

