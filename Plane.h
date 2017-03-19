#ifndef _Plane_H
#define _Plane_H

#include "Object.h"

#include <cmath>

class Plane : public Object {
	Vect   normal;
	Color  color;
	double distance;

public:
	Plane(const Vect &normal, double distance, const Color &color) :
			normal		(normal		),
			color		(color		),
			distance	(distance	){}

public:
	const Vect &getPlaneNormal() const	{ return normal;		}
	double getPlaneDistance() const		{ return distance;		}

	const Color &getColor() const override{
		return color;
	}

	Vect getNormalAt(const Vect &point) const override {
		return normal;
	}

	double findIntersection(const Ray &ray) const override{
		double const a = ray.getRayDirection().dotProduct(normal);

		if (a == 0) {
			// ray is parallel to the plane
			return -1;
		}

		double const b = normal.dotProduct(ray.getRayOrigin().vectAdd(normal.vectMult(distance).negative()));
		return - b / a;
	}
};

#endif
