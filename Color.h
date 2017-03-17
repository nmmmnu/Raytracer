#ifndef _COLOR_H
#define _COLOR_H

class Color {
	double r	= 0.5;
	double g	= 0.5;
	double b	= 0.5;

	double special	= 0;

public:
	Color() = default;

	Color(double const r, double const g, double const b, double const special = 0) :
			r(r),
			g(g),
			b(b),
			special(special){}

public:
	double getColorRed()		const { return r; }
	double getColorGreen()		const { return g; }
	double getColorBlue()		const { return b; }
	double getColorSpecial()	const { return special; }

	double setColorRed(double rv) { r = rv; }
	double setColorGreen(double gv) { g = gv; }
	double setColorBlue(double bv) { b = bv; }
	double setColorSpecial(double sv) { special = sv; }

	double brightness() const {
		return(r + g + b) / 3;
	}

	Color colorScalar(double const scalar) const{
		return Color(
				r * scalar,
				g * scalar,
				b * scalar,
				special
		);
	}

	Color colorAdd(const Color &color) const{
		return Color(
				r + color.r,
				g + color.g,
				b + color.b,
				special
		);
	}

	Color colorMultiply(const Color &color) const{
		return Color(
				r * color.r,
				g * color.g,
				b * color.b,
				special
		);
	}

	Color colorAverage(const Color &color) const{
		return Color(
			(r + color.r) / 2,
			(g + color.g) / 2,
			(b + color.b) / 2,
			special
		);
	}

	Color clip() const{
		double const alllight    = r + g + b;
		double const excesslight = alllight - 3;

		double rr = r;
		double gg = g;
		double bb = b;

		if (excesslight > 0) {
			rr += excesslight * (r / alllight);
			gg += excesslight * (g / alllight);
			bb += excesslight * (b / alllight);
		}

		return Color(
			clamp_(rr),
			clamp_(gg),
			clamp_(bb),
			special
		);
	}

private:
	template <typename T>
	static T clamp_(T const val, T const min = 0, T const max = 1){
		if (val < min)
			return min;

		if (val > max)
			return max;

		return val;
	}
};

#endif
