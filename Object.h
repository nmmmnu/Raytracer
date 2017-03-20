#ifndef _OBJECT_H
#define _OBJECT_H

#include "Ray.h"
#include "Color.h"

class Object {
public:
	virtual const char *getName() const = 0;

	virtual const Color &getColor() const = 0;
	virtual Vect normalAt(const Vect &point) const = 0;

	// find only positive intersections
	bool intersection(const Ray &ray, double &t) const{
		bool const result = intersection_(ray, t);

		return result && t < 0 ? false : result;
	}

private:
	virtual bool intersection_(const Ray &ray, double &t) const = 0;

};

#endif

