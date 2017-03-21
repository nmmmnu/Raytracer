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

	const Camera &camera = Camera::create(width, height, { -4.00, 1.50, -4.00 } );

	// Lights
	raytracer::Light scene_light	( { -7.00, 10.00, -10.00 }, Color::WHITE	);

	raytracer::SceneLights lights = {
		&scene_light
	};

	// Scene objects
	double const refl      = 0.3;
	double const refl_ball = 0.9;

	using raytracer::Sphere;
	const Sphere scene_sphere	( {  1.00,  0.00, 1.00 },  1.00, { 0.0, 0.0, 1.0, refl_ball } );

	using raytracer::Vect;
	using Plane = raytracer::CheckerboardPlane;

/*
	const Plane  scene_plane	( Vect{ 1, 1, 0 }.normalize(), -2.0,
							{ 1, 1, 1, refl },
							{ 0, 0, 1, refl } );

*/
	const Plane  scene_plane1	( -2.0,	{ 0.3, 0.3, 0.3, refl }, { 0.9, 0.9, 0.9, refl } );
	const Plane  scene_plane2	( +2.0, { 0.1, 0.1, 0.3, refl }, { 0.7, 0.7, 0.9, refl } );

	using raytracer::iObject;

	const raytracer::SceneObjects scene_objects = {
		dynamic_cast<const iObject*>(&scene_sphere	)

	,	dynamic_cast<const iObject*>(&scene_plane1	)
	,	dynamic_cast<const iObject*>(&scene_plane2	)
	};

	// Render

	raytracer::render("data/plane.ppm", width, height, scene_objects, lights, camera);
}

