#ifndef _Camera_H
#define _Camera_H

#include "Vect.h"

class Camera {
	Vect pos;
	Vect dir;
	Vect right;
	Vect down;

public:
	Camera(const Vect &pos, const Vect &dir, const Vect &right, const Vect &down) :
				pos	(pos	),
				dir	(dir	),
				right	(right	),
				down	(down	){}

public:
	const Vect &getCameraPosition() const	{ return pos;	}
//	const Vect &getCameraDirection() const	{ return dir;	}
//	const Vect &getCameraRight() const	{ return right;	}
//	const Vect &getCameraDown() const	{ return down;	}
};

#endif

