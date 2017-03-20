#ifndef _COLOR_H
#define _COLOR_H

class Color {
public:
	double r;
	double g;
	double b;

	double special;

public:
	static const Color BLACK	;
	static const Color GREY		;
	static const Color WHITE	;

	static const Color RED		;
	static const Color GREEN	;
	static const Color BLUE		;

	static const Color YELLOW	;

public:
	constexpr Color(double const r, double const g, double const b, double const special = 0) :
			r(r),
			g(g),
			b(b),
			special(special){}

public:
	constexpr
	double brightness2() const {
		return r + g + b;
	}

	constexpr
	double brightness() const {
		return brightness2() / 3;
	}

	constexpr
	Color operator + (const Color &c) const{
		return Color(
				r + c.r,
				g + c.g,
				b + c.b,
				special
		);
	}

	constexpr
	Color operator * (const Color &c) const{
		return Color(
				r * c.r,
				g * c.g,
				b * c.b,
				special
		);
	}

	constexpr
	Color operator * (double const scalar) const{
		return Color(
				r * scalar,
				g * scalar,
				b * scalar,
				special
		);
	}

	constexpr
	Color colorAverage(const Color &c) const{
		return Color(
			(r + c.r) / 2,
			(g + c.g) / 2,
			(b + c.b) / 2,
			special
		);
	}

	constexpr
	Color clip() const{
		double const all_light    = brightness2();
		double const excess_light = all_light - 3;

		if (excess_light <= 0)
			return *this;

		return Color(
			clip__(r, all_light, excess_light),
			clip__(g, all_light, excess_light),
			clip__(b, all_light, excess_light),

			special
		);
	}

private:
	constexpr
	inline static double clip__(double const a, double const all_light, double const excess_light){
		return clamp__( a + excess_light * (a / all_light) );
	}

	template <typename T>
	constexpr
	static T clamp__(T const val, T const min = 0, T const max = 1){
		if (val < min)
			return min;

		if (val > max)
			return max;

		return val;
	}
};

constexpr Color Color::BLACK	{ 0.0, 0.0, 0.0 };
constexpr Color Color::GREY	{ 0.5, 0.5, 0.5 };
constexpr Color Color::WHITE	{ 1.0, 1.0, 1.0 };

constexpr Color Color::RED	{ 1.0, 0.0, 0.0 };
constexpr Color Color::GREEN	{ 0.0, 1.0, 0.0 };
constexpr Color Color::BLUE	{ 0.0, 0.0, 1.0 };

constexpr Color Color::YELLOW	= Color::RED + Color::GREEN;

#endif
