#ifndef _SPHERE_H
#define _SPHERE_H

#include "math.h"
#include "Object.h"
#include "Vect.h"
#include "Color.h"

class Sphere : public Object {
	Vect   center;
	Color  color;
	double radius;

public:
	Sphere (const Vect &center, double radius, const Color &color) :
				center	(center	),
				color	(color	),
				radius	(radius	){}

public:
	const Vect &getSphereCenter() const	{ return center;	}
	double getSphereRadius() const		{ return radius;	}

	const Color &getColor() const override{
		return color;
	}

	Vect getNormalAt(const Vect &point) const override{
		// normal always points away from the center of a sphere
		return point.vectAdd(center.negative()).normalize();
	}

	double findIntersection(const Ray &ray) const override{
		const Vect &ray_origin = ray.getRayOrigin();

		double ray_origin_x = ray_origin.getVectX();
		double ray_origin_y = ray_origin.getVectY();
		double ray_origin_z = ray_origin.getVectZ();

		const Vect &ray_direction = ray.getRayDirection();

		double ray_direction_x = ray_direction.getVectX();
		double ray_direction_y = ray_direction.getVectY();
		double ray_direction_z = ray_direction.getVectZ();

		const Vect &sphere_center = center;

		double sphere_center_x = sphere_center.getVectX();
		double sphere_center_y = sphere_center.getVectY();
		double sphere_center_z = sphere_center.getVectZ();

		double a = 1; // normalized

		double b =	(2 * (ray_origin_x - sphere_center_x) * ray_direction_x) +
				(2 * (ray_origin_y - sphere_center_y) * ray_direction_y) +
				(2 * (ray_origin_z - sphere_center_z) * ray_direction_z);

		double c =	sqr__(ray_origin_x - sphere_center_x) +
				sqr__(ray_origin_y - sphere_center_y) +
				sqr__(ray_origin_z - sphere_center_z) - sqr__(radius);

		double discriminant = b * b - 4 * c;

		if (discriminant > 0) {
			// the ray intersects the sphere

			double sqrt_discriminant = sqrt(discriminant);

			double const ZERO = 0.000001;

			// the first root
			double root_1 = (- b - sqrt_discriminant) / 2 - ZERO;

			if (root_1 > 0) {
				// the first root is the smallest positive root
				return root_1;
			}

			// the second root is the smallest positive root
			double root_2 = (- b + sqrt_discriminant) / 2 - ZERO;
			return root_2;
		}

		// the ray missed the sphere
		return -1;
	}

private:
	template <typename T>
	static T sqr__(T const a){
		return a * a;
	}
};

#endif

