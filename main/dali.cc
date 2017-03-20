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

	const Camera &camera = Camera::create(width, height, { 3.00, 1.50, -4.00 } );

	// Lights
	raytracer::Light scene_light	( { -7.00, 10.00, -10.00 }, Color::WHITE	);

	const raytracer::SceneLights lights = {
		&scene_light
	};

	// Scene objects

	using raytracer::Sphere;

	const Color color = { 0.5, 1.0, 0.5 };
	double const radius = 1;
	double const c = 0.40;

	const Sphere scene_spheres[] = {
		{ {  -c,  -c, -c },  radius, color	},
		{ {   c,  -c, -c },  radius, color	},
		{ {  -c,   c, -c },  radius, color	},
		{ {   c,   c, -c },  radius, color	},

		{ {  -c,  -c,  c },  radius, color	},
		{ {   c,  -c,  c },  radius, color	},
		{ {  -c,   c,  c },  radius, color	},
		{ {   c,   c,  c },  radius, color	}
	};

	using raytracer::Plane;

	const Plane plane{ -1.8, Color::GREY	};

	using raytracer::Object;

	raytracer::SceneObjects scene_objects;

	for (const Sphere &sphere : scene_spheres)
		scene_objects.push_back( dynamic_cast<const Object*>(&sphere) );

		scene_objects.push_back( dynamic_cast<const Object*>(&plane) );

	// Render

	raytracer::render("data/dali.ppm", width, height, scene_objects, lights, camera);
}

