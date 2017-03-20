#ifndef SPHERE_H_
#define SPHERE_H_

#include "object.h"

namespace raytracer{

class Sphere : public Object {
public:
	Vect   center;
	Color  color;
	double radius;

public:
	constexpr
	Sphere (const Vect &center, double radius, const Color &color) :
				center	(center	),
				color	(color	),
				radius	(radius	){}

public:
	const char *getName() const override{
		return "sphere";
	}

	const Color &getColor() const override{
		return color;
	}

	const Color &getColor(const Vect &) const override{
		return color;
	}

private:
	Vect normalAt_(const Vect &point) const override{
		// normal always points away from the center of a sphere
		return ( point + center.negative() ).normalize();
	}

	bool intersection_(const Ray &ray, double &t) const override{
		double const a = 1; // normalized

		double const b =
			(2 * (ray.origin.x - center.x) * ray.dir.x) +
			(2 * (ray.origin.y - center.y) * ray.dir.y) +
			(2 * (ray.origin.z - center.z) * ray.dir.z);

		double const c =
			square__(ray.origin.x - center.x) +
			square__(ray.origin.y - center.y) +
			square__(ray.origin.z - center.z) - square__(radius);

		double t0, t1;

		if ( solveQuadratic__(a, b, c, t0, t1) == false){
			// the ray missed the sphere
			return false;
		}

		if (t0 > t1){
			using std::swap;
			swap(t0, t1);
		}

		if (t0 > ACCURACY){
			t = t0;
			return true;
		}

		if (t1 > ACCURACY){
			t = t1;
			return true;
		}

		// both roots are negative
		return false;
	}

private:
	template <typename T>
	static T square__(T const a){
		return a * a;
	}

	// https://www.scratchapixel.com/code.php?id=10&origin=/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes
	static bool solveQuadratic__(double const a, double const b, double const c, double &x0, double &x1){
		double const discriminant = b * b - 4 * a * c;

		if (discriminant < 0)
			return false;

		if (discriminant == 0) {
			x0 = x1 = - 0.5 * b / a;
		}

		double const q = b > 0 ?
			-0.5 * (b + sqrt(discriminant)) :
			-0.5 * (b - sqrt(discriminant));

		x0 = q / a;
		x1 = c / q;

		return true;
	}

};

} //namespace raytracer

#endif

