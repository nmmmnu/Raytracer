#ifndef LIGHT_H_
#define LIGHT_H_

#include "vect.h"
#include "color.h"

namespace raytracer{

class Light {
public:
	Vect  pos;
	Color color;

public:
	Light(const Vect &pos, const Color &color) :
			pos(pos),
			color(color){}
};

} //namespace raytracer

#endif

