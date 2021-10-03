#define _USE_MATH_DEFINES

#include "astro.h"

namespace P2 {
	astroid::astroid(double radius)	{
		if (radius <= 0)
			throw std::runtime_error("invalid radius");
		r = radius;
	}

	void astroid::setR(double a0) {
		if (a0 <= 0)
			throw std::exception("Invalid radius");
		r = a0;
	}

	double astroid::arcLen(double t) const {
		if (t < 0 || t > 90)
			throw std::exception("Invalid radius");
		return 6.0 * r * pow(sin(t*M_PI/180),2);
	}

	double astroid::allLen() const {
		return 24 * r;
	}

	double astroid::curvRad(double t) const {
		return 6 * r * abs(sin(t * M_PI / 90));
	}

	double astroid::astroidArea() const {
		return (3.0 / 8.0) * M_PI * 16 * r * r;
	}

	double astroid::coordX(double t) const {
		return 4 * r * pow(cos(t * M_PI / 180),3);
	}
	double astroid::coordY(double t) const {
		return 4 * r * pow(sin(t * M_PI / 180), 3);
	}

	double astroid::YfromX(double x) const {
		return pow(pow((4*r),(2.0/3.0)) - pow(abs(x), (2.0 / 3.0)), (1.5));
	}
}
