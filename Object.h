#ifndef _OBJECT_H
#define _OBJECT_H

#include "Ray.h"
#include "Color.h"

class Object {
public:
	virtual const Color &getColor() const = 0;
	virtual Vect getNormalAt(const Vect &point) const = 0;
	virtual double findIntersection(const Ray &ray) const = 0;
};

#endif

