#ifndef _Light_H
#define _Light_H

#include "Vect.h"
#include "Color.h"


class Light {
public:
	Vect  pos;
	Color color;

public:
	Light(const Vect &pos, const Color &color) :
			pos(pos),
			color(color){}
};

#endif

