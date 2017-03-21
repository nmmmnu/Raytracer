#include <iostream>

#include "raytracer.h"

#include "sphere.h"
#include "plane.h"

constexpr int width  = 640;
constexpr int height = 480;

int main (){
	std::cout << "rendering ..." << '\n';

	using raytracer::Color;

	// Camera eye
	using raytracer::Camera;

	const Camera &camera = Camera::create(width, height, { 0.00, 4.00, -4.00 } );

	// Lights
	raytracer::Light scene_light	( { 0.00, 10.00, -10.00 }, Color::WHITE	);

	raytracer::SceneLights lights = {
		&scene_light
	};

	// Scene objects

	using raytracer::Sphere;

	double const c = 1.2;
	double const s = c * M_SQRT2;

	const Sphere scene_sphere1	{ { -c, 0, 0 }, 1.00, { 0.25, 1.00, 0.25, 0.3 }	};
	const Sphere scene_sphere2	{ { +c, 0, 0 }, 1.00, { 1.00, 0.25, 0.25, 0.3 }	};
	const Sphere scene_sphere3	{ {  0, 0, s }, 1.00, { 0.25, 0.25, 1.00, 0.3 }	};

	using raytracer::Plane;

	const Plane  scene_plane	( -1.2, { 0.1, 0.1, 0.1, 0.2 }, { 0.9, 0.9, 0.9, 0.2 }	);

	using raytracer::iObject;

	const raytracer::SceneObjects scene_objects = {
		dynamic_cast<const iObject*>(&scene_sphere1	)
	,	dynamic_cast<const iObject*>(&scene_sphere2	)
	,	dynamic_cast<const iObject*>(&scene_sphere3	)
	,	dynamic_cast<const iObject*>(&scene_plane	)
	};

	// Render

	raytracer::render("data/reflect.ppm", width, height, scene_objects, lights, camera);
}

