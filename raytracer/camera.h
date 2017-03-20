#ifndef CAMERA_H_
#define CAMERA_H_

#include "ray.h"

#include <utility>

namespace raytracer{

class Camera {
private:
	Vect pos;
	Vect dir;
	Vect right;
	Vect down;

	int width;
	int height;

	double aspectratio   = 0;
	double aspectratio_h = 0;

private:
	constexpr
	Camera(int const width, int const height,
		const Vect &pos, const Vect &dir, const Vect &right, const Vect &down) :
				pos	(pos	),
				dir	(dir	),
				right	(right	),
				down	(down	),
				width	(width	),
				height	(height	){

		calc_aspectratio_();
	}

public:
	static Camera create(int const width, int const height,
			const Vect &pos, const Vect &look = { 0, 0, 0 }){

		const Vect &diff  = pos - look;
		const Vect &dir   = diff.negative().normalize();
		const Vect &right = Vect::Y.crossProduct(dir).normalize();
		const Vect &down  =  right.crossProduct(dir);

		return Camera{
			width, height,
			pos, dir, right, down
		};
	}

public:
	Ray getRay(int const x, int const y) const{
		const auto &p = calcAspectRatio_(x, y);
		double const xx = p.first;
		double const yy = p.second;

		double const c = 0.5;

		const Vect &origin = pos;

		const Vect &direction = dir + right * (xx - c) + down * (yy - c);

		return { origin, direction.normalize() };
	}

private:
	constexpr
	std::pair<double, double> calcAspectRatio_(int const x, int const y) const{
		double const c = 0.5;

		// the image is wider
		if (width > height) {
			return {
				((x + c) / width) * aspectratio - aspectratio_h, /* (((width - height) / (double) height) / 2), */
				((height - y) + c) / height
			};
		}

		// the imager is taller
		if (width < height) {
			return {
				(x + c) / width,
				(((height - y) + c) / height) / aspectratio - aspectratio_h /* (((height - width) / (double) width) / 2) */
			};
		}

		// the image is square
		return{
			(x + c) / width,
			((height - y) + c) / height
		};
	}

	constexpr
	void calc_aspectratio_(){
		this->aspectratio = (double) width / (double) height;

		if (width > height) {
			// the image is wider
			this->aspectratio_h = ((width - height) / (double) height) / 2;
		}

		if (width < height) {
			// the imager is taller
			this->aspectratio_h = ((height - width) / (double) width) / 2;
		}

		// the image is square, not relevant
	}
};

} //namespace raytracer

#endif

