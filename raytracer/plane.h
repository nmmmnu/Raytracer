#ifndef PLANE_H_
#define PLANE_H_

#include "iobject.h"

namespace raytracer{

class Plane : public iObject {
private:
	static const Vect Y;

public:
	Vect   normal;
	double distance;
	Color  color1;
	Color  color2;

public:
	// the normala is perpendicular to the plane
	// the distance is the distance from the (0, 0, 0)
	constexpr
	Plane(const Vect &normal, double const distance, const Color &color1, const Color &color2) :
			normal		(normal		),
			distance	(distance	),
			color1		(color1		),
			color2		(color2		){}

	constexpr
	Plane(double const distance, const Color &color1, const Color &color2):
			Plane(Vect::Y, distance, color1, color2){}

	constexpr
	Plane(double const distance, const Color &color):
			Plane(distance, color, color){}

public:
	const char *getName() const override{
		return "plane";
	}

	const Color &getColor() const override{
		return color1;
	}

	const Color &getColor(const Vect &point) const override{
		int const x = (int) floor(point.x);
		int const z = (int) floor(point.z);

		return ( x + z ) % 2 == 0 ? color1 : color2;
	};

private:
	Vect normalAt_(const Vect &point) const override {
		return normal;
	}

	bool intersection_(const Ray &ray, double &t) const override{
		double const a = ray.dir.dotProduct(normal);

		if (a > -ACCURACY && a < +ACCURACY) {
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

} //namespace raytracer

#endif

