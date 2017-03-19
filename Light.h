#ifndef _Light_H
#define _Light_H

#include "Vect.h"
#include "Color.h"


class Light {
	Vect  pos;
	Color color;

public:
	Light(const Vect &pos, const Color &color) :
			pos(pos),
			color(color){}

public:
	const Vect &getLightPosition() const {
//	Vect getLightPosition() const{
		return pos;
	}

	const Color &getLightColor() const {
		return color;
	}
};

#endif

