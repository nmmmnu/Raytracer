#include <iostream>

#include "raytracer.h"

#include "sphere.h"
#include "plane.h"

constexpr int width  = 640;
constexpr int height = 480;

const char *hello[] = {
	"x  x  xxxx  x     x     xxxx" ,
	"x  x  x     x     x     x  x" ,
	"x  x  x     x     x     x  x" ,
	"xxxx  xxxx  x     x     x  x" ,
	"x  x  x     x     x     x  x" ,
	"x  x  x     x     x     x  x" ,
	"x  x  xxxx  xxxx  xxxx  xxxx" ,
	nullptr
};

int main (){
	std::cout << "rendering ..." << '\n';

	using raytracer::Color;

	// Camera eye
	using raytracer::Camera;

	const Camera &camera = Camera::create(width, height, { 3.00, -0.50, -6.00 } );

	// Lights
	raytracer::Light scene_light	( { -7.00, 10.00, -10.00 }, Color::WHITE	);

	const raytracer::SceneLights lights = {
		&scene_light
	};

	// Scene objects

	using raytracer::Sphere;


	const Color color = { 1.0, 1.0, 0.7, 0.33 };

	double const radius = 0.25;
	double const c = - radius * 1.20;
	double const cx = 2.5;
	double const cy = 0.5;

	std::vector<Sphere> scene_spheres;

	for(int y = 0; hello[y]; ++y){
		for(int x = 0; hello[y][x]; ++x){
			std::cout << hello[y][x];

			if (hello[y][x] == 'x'){
				scene_spheres.push_back( { { cx + x * c, cy + y * c, 0 }, radius * 1.25, color } );
			}
		}

		std::cout << '\n';
	}


	using raytracer::Plane;

	const Plane  scene_plane{ -1.8, { 0.1, 0.1, 0.3, 0.2 }, { 0.7, 0.7, 0.9, 0.2 }	};

	using raytracer::Object;

	raytracer::SceneObjects scene_objects;

	for (const Sphere &sphere : scene_spheres)
		scene_objects.push_back( dynamic_cast<const Object*>(&sphere) );

		scene_objects.push_back( dynamic_cast<const Object*>(&scene_plane) );

	// Render

	raytracer::render("data/hello.ppm", width, height, scene_objects, lights, camera);
}

