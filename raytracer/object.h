#ifndef OBJECT_H_
#define OBJECT_H_

#include "ray.h"
#include "color.h"
#include "config.h"

namespace raytracer{

class Object {
public:
	virtual const char *getName() const = 0;
	virtual const Color &getColor() const = 0;

	virtual const Color &getColor(const Vect &) const = 0;

public:
	Vect normalAt(const Vect &point) const{
		return normalAt_(point);
	}
	
	bool intersection(const Ray &ray, double &t) const{
		bool const result = intersection_(ray, t);
		
		return t < ACCURACY ? false : result;
	}

private:
	virtual Vect normalAt_(const Vect &point) const = 0;
	virtual bool intersection_(const Ray &ray, double &t) const = 0;
};

} //namespace raytracer

#endif

