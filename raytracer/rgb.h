#ifndef RGB_H_
#define RGB_H_

#include <vector>
#include <fstream>

namespace raytracer{

struct RGB {
	double r;
	double g;
	double b;

	static std::ofstream writeRGBHeader(const char *filename, int const width, int const height) {
		std::ofstream ofs(filename, std::ios::out | std::ios::binary);

		ofs << "P6\n" << width << " " << height << "\n255\n";

		return ofs;
	}

	friend
	std::ostream& operator <<(std::ostream& os, const RGB& rgb){
		os	<< fix_(rgb.r)
			<< fix_(rgb.g)
			<< fix_(rgb.b)
		;

		return os;
	}

private:
	constexpr
	static unsigned char fix_(double const channel){
		return (unsigned char) (std::min<double>(1, channel) * 255);
	}
};

} //namespace raytracer

#endif

