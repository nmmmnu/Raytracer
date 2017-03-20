#ifndef _RAY_H
#define _RAY_H

#include "Vect.h"

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

#endif

