#ifndef VECT_H_
#define VECT_H_

#include <cmath>

namespace raytracer{

class Vect {
public:
	double x = 0;
	double y = 0;
	double z = 0;

public:
	static const Vect O;
	static const Vect X;
	static const Vect Y;
	static const Vect Z;

public:
	constexpr Vect() = default;

	constexpr Vect(double const x, double const y, double const z) :
			x(x),
			y(y),
			z(z){}

public:
	constexpr
	double magnitude2() const{
		return	x * x +
			y * y +
			z * z
		;
	}

	double magnitude() const{
		return sqrt(magnitude2());
	}

	Vect normalize() const{
		double const m = magnitude();
		return Vect (
			x / m,
			y / m,
			z / m
		);
	}

	constexpr
	Vect negative() const{
		return operator *(-1);
	}

	constexpr
	double dotProduct(const Vect &v) const{
		return
			x * v.x +
			y * v.y +
			z * v.z;
	}

	constexpr
	Vect crossProduct(const Vect &v) const{
		return Vect(
			y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x
		);
	}

	constexpr
	Vect operator + (const Vect &v) const{
		return Vect(
			x + v.x,
			y + v.y,
			z + v.z
		);
	}

	constexpr
	Vect operator - (const Vect &v) const{
		return Vect(
			x - v.x,
			y - v.y,
			z - v.z
		);
	}

	constexpr
	Vect operator * (double const scalar) const{
		return Vect(
			x * scalar,
			y * scalar,
			z * scalar
		);
	}
};

constexpr
inline Vect operator * (double const scalar, const Vect &vector){
	return vector * scalar;
}

} //namespace raytracer

#endif

