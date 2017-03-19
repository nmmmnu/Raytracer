#ifndef _RAY_H
#define _RAY_H

#include "Vect.h"

class Ray {
	Vect origin;
	Vect dir;

public:
	Ray(const Vect &origin, const Vect &dir) :
			origin(origin),
			dir(dir){}

public:
	const Vect &getRayOrigin() const	{ return origin; }
	const Vect &getRayDirection() const	{ return dir;	 }

};

#endif

