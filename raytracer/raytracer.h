
#include "camera.h"
#include "light.h"
#include "object.h"

#include "rgb.h"

#include <utility>	// pair

namespace raytracer{

using SceneLights  = std::vector<const Light*>;
using SceneObjects = std::vector<const Object*>;

void render(const char *filename,
		int const width, int const height,
		const SceneObjects &scene_objects, const SceneLights &scene_lights,
		const Camera &camera);

} //namespace raytracer

