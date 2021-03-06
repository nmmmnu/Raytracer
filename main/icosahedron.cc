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

	const Camera &camera = Camera::create(width, height, { 6.00, 3.00, -8.00 } );

	// Lights
	raytracer::Light scene_light	( { -7.00, 10.00, -10.00 }, Color::WHITE	);

	raytracer::SceneLights lights = {
		&scene_light
	};

	// Scene objects

	using raytracer::Sphere;

	Color color1{ 0.25, 1.00, 0.25, 0.3 };
	Color color2{ 0.25, 0.25, 1.00, 0.3 };

	constexpr auto r    = 1.10;

	constexpr auto M_PHI = 1.6180339887;

	constexpr auto phi  = 1 - M_PHI;
	constexpr auto Phi  = M_PHI;

	const Sphere scene_icocahedron[] = {
		{ {    0,   +1, +Phi }, r, color2 },
		{ {    0,   +1, -Phi }, r, color2 },
		{ {    0,   -1, +Phi }, r, color2 },
		{ {    0,   -1, -Phi }, r, color2 },

		{ {   +1, +Phi,    0 }, r, color2 },
		{ {   +1, -Phi,    0 }, r, color2 },
		{ {   -1, +Phi,    0 }, r, color2 },
		{ {   -1, -Phi,    0 }, r, color2 },

		{ { +Phi,    0,   +1 }, r, color2 },
		{ { -Phi,    0,   +1 }, r, color2 },
		{ { +Phi,    0,   -1 }, r, color2 },
		{ { -Phi,    0,   -1 }, r, color2 }
	};

	const Sphere scene_dodecahedron[] = {
		{ { +1, +1, +1 }, r, color1 },
		{ { +1, +1, -1 }, r, color1 },
		{ { +1, -1, +1 }, r, color1 },
		{ { +1, -1, -1 }, r, color1 },
		{ { -1, +1, +1 }, r, color1 },
		{ { -1, +1, -1 }, r, color1 },
		{ { -1, -1, +1 }, r, color1 },
		{ { -1, -1, -1 }, r, color1 },

		{ {    0, +Phi, +phi }, r, color1 },
		{ {    0, +Phi, -phi }, r, color1 },
		{ {    0, -Phi, +phi }, r, color1 },
		{ {    0, -Phi, -phi }, r, color1 },

		{ { +phi,    0, +Phi }, r, color1 },
		{ { -phi,    0, +Phi }, r, color1 },
		{ { +phi,    0, -Phi }, r, color1 },
		{ { -phi,    0, -Phi }, r, color1 },

		{ { +Phi,  +phi,   0 }, r, color1 },
		{ { +Phi,  -phi,   0 }, r, color1 },
		{ { -Phi,  +phi,   0 }, r, color1 },
		{ { -Phi,  -phi,   0 }, r, color1 }
	};

	using raytracer::Plane;

	const Plane  scene_plane	( -3, { 0.1, 0.1, 0.1, 0.2 }, { 0.9, 0.9, 0.9, 0.2 }	);

	raytracer::SceneObjects scene_objects;

	scene_objects.reserve( sizeof(scene_icocahedron) / sizeof(Sphere) + sizeof(scene_dodecahedron) / sizeof(Sphere) + 1);

	for (const auto &sphere : scene_icocahedron)
		scene_objects.push_back(&sphere);

	for (const auto &sphere : scene_dodecahedron)
		scene_objects.push_back(&sphere);

	scene_objects.push_back(&scene_plane);

	// Render

	raytracer::render("data/icosahedron.ppm", width, height, scene_objects, lights, camera);
}

