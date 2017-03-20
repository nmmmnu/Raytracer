#include "color.h"

namespace raytracer{

const Color Color::BLACK	{ 0.0, 0.0, 0.0 };
const Color Color::GREY		{ 0.5, 0.5, 0.5 };
const Color Color::WHITE	{ 1.0, 1.0, 1.0 };

const Color Color::RED		{ 1.0, 0.0, 0.0 };
const Color Color::GREEN	{ 0.0, 1.0, 0.0 };
const Color Color::BLUE		{ 0.0, 0.0, 1.0 };

const Color Color::YELLOW	= Color::RED + Color::GREEN;

} //namespace raytracer

