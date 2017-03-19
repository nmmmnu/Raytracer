#ifndef _RGB_H
#define _RGB_H

#include <vector>
#include <fstream>
#include <iostream>

struct RGB {
	double r;
	double g;
	double b;
};

using RGBVector = std::vector<RGB>;

inline std::ostream& operator <<(std::ostream& os, const RGB& rgb){
//	os	<< (unsigned char) (std::min<double>(1, rgb.r) * 255)
//		<< (unsigned char) (std::min<double>(1, rgb.g) * 255)
//		<< (unsigned char) (std::min<double>(1, rgb.b) * 255)

	os	<< (int) (std::min<double>(1, rgb.r) * 255) << " "
		<< (int) (std::min<double>(1, rgb.g) * 255) << " "
		<< (int) (std::min<double>(1, rgb.b) * 255) << "    "
	;

	return os;
}

inline void saveRGB(const char *filename, size_t const width, size_t const height, const RGBVector &data) {
	std::ofstream ofs("./untitled.ppm", std::ios::out | std::ios::binary);

//	ofs << "P6\n" << width << " " << height << "\n255\n";
	ofs << "P3\n" << width << " " << height << "\n255\n";

	for(auto it = data.rbegin(); it != data.rend(); ++it){
    		ofs << *it;
	}
}

#endif

