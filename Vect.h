#ifndef _VECT_H
#define _VECT_H

#include "math.h"

class Vect {
	double x;
	double y;
	double z;

public:
	Vect (double x, double y, double z) :
			x(x),
			y(y),
			z(z){}

public:
	double getVectX() const { return x; }
	double getVectY() const { return y; }
	double getVectZ() const { return z; }

public:
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
		double m = magnitude();
		return Vect (
			x / m,
			y / m,
			z / m
		);
	}

	Vect negative() const{
		return Vect (-x, -y, -z);
	}

	double dotProduct(Vect v) const{
		return x*v.getVectX() + y*v.getVectY() + z*v.getVectZ();
	}

	Vect crossProduct(Vect v) const{
		return Vect (y*v.getVectZ() - z*v.getVectY(), z*v.getVectX() - x*v.getVectZ(), x*v.getVectY() - y*v.getVectX());
	}

	Vect vectAdd(Vect v) const{
		return Vect (x + v.getVectX(), y + v.getVectY(), z + v.getVectZ());
	}

	Vect vectMult(double scalar) const{
		return Vect (x*scalar, y*scalar, z*scalar);
	}
};

#endif

