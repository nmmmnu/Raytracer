#ifndef PLANE_H_
#define PLANE_H_

#include "iobject.h"

namespace raytracer{

class iPlane : public iObject {
private:
	static const Vect Y;

private:
	Vect   normal;
	double distance;

public:
	// the normala is perpendicular to the plane
	// the distance is the distance from the (0, 0, 0)
	constexpr
	iPlane(const Vect &normal, double const distance) :
			normal		(normal		),
			distance	(distance	){}

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

// =====================

class SimplePlane : public iPlane {
private:
	Color  color;
public:
	constexpr
	SimplePlane(const Vect &normal, double const distance, const Color &color) :
			iPlane(normal, distance),
				color(color){}

	constexpr
	SimplePlane(double const distance, const Color &color):
			SimplePlane(Vect::Y, distance, color){}

	// compatibility c-tor
	constexpr
	SimplePlane(const Vect &normal, double const distance, const Color &color, const Color & ) :
			SimplePlane(normal, distance, color){}

	constexpr
	SimplePlane(double const distance, const Color &color, const Color & ):
			SimplePlane(Vect::Y, distance, color){}

public:
	const char *getName() const override{
		return "plane.simple";
	}

	const Color &getColor() const override{
		return color;
	}

	const Color &getColor(const Vect &point) const override{
		return color;
	}
};

// =====================

class CheckerboardPlane : public iPlane {
private:
	Color  color[2];

public:
	constexpr
	CheckerboardPlane(const Vect &normal, double const distance, const Color &color1, const Color &color2) :
			iPlane(normal, distance),
				color{ color1, color2 }{}

	constexpr
	CheckerboardPlane(double const distance, const Color &color1, const Color &color2):
			CheckerboardPlane(Vect::Y, distance, color1, color2){}

public:
	const char *getName() const override{
		return "plane.checkerboard";
	}

	const Color &getColor() const override{
		return color[0];
	}

	const Color &getColor(const Vect &point) const override{
		int const x = (int) round(point.x);
		int const y = (int) round(point.y);
		int const z = (int) round(point.z);

		int const index = ( x + y + z ) % 2 == 0;

		// branchless ;)
		return color[index];
	};
};

// =====================

using Plane = CheckerboardPlane;

} //namespace raytracer

#endif

