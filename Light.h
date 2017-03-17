#ifndef _Light_H
#define _Light_H

#include "Vect.h"
#include "Color.h"


class Light {
	Vect  pos	= Vect(0, 0, 0);
	Color color	= Color(1, 1, 1, 0);

public:
	Light() = default;

	Light(const Vect &pos, const Color &color) :
			pos(pos),
			color(color){}

public:
//	const Vect &getLightPosition() const {
	Vect getLightPosition() const{
		return pos;
	}

	const Color &getLightColor() const {
		return color;
	}
};

#endif

