#ifndef _Plane_H
#define _Plane_H

#include "Object.h"

class Plane : public Object {
private:
	static const Vect Y;

public:
	Vect   normal;
	double distance;
	Color  color;

public:
	// the normala is perpendicular to the plane
	// the distance is the distance from the (0, 0, 0)
	constexpr
	Plane(const Vect &normal, double const distance, const Color &color) :
			normal		(normal		),
			distance	(distance	),
			color		(color		){}

	constexpr
	Plane(double const distance, const Color &color):
			Plane(Vect::Y, distance, color){}

public:
	const char *getName() const override{
		return "plane";
	}

	const Color &getColor() const override{
		return color;
	}

	Vect normalAt(const Vect &point) const override {
		return normal;
	}

private:
	bool intersection_(const Ray &ray, double &t) const override{
		double const a = ray.dir.dotProduct(normal);

		if (a == 0) {
			// ray is parallel to the plane
			return false;
		}

		double const b = normal.dotProduct(
			ray.origin + (normal * distance).negative()
		);

		t =  - b / a;

		return true;
	}


};

#endif

