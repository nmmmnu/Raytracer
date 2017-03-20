#ifndef _RGB_H
#define _RGB_H

#include <vector>
#include <fstream>

struct RGB {
	double r;
	double g;
	double b;

	static std::ofstream writeRGBHeader(const char *filename, size_t const width, size_t const height) {
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


#endif

