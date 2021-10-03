#ifndef _ASTRO_H_
#define _ASTRO_H_

#include <iostream>
#include <cmath>
#include <strstream>

namespace P2 {

	template <class T>
	int getNum(T& a) {
		std::cin >> a;
		while (!std::cin.good()) {
			std::cout << "Error, try again" << std::endl;
			if (std::cin.eof())
				return -1;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		return 1;
	}

	class astroid {
	private:
		double r;
	public:
		astroid() :r(1) {};
		astroid(double radius);

		void setR(double r0);
		double getR() const { return r; };

		double arcLen(double t) const;      // 2
		double allLen() const;				      // 3
		double curvRad(double t) const;     // 4
		double astroidArea() const;         // 5
		double coordX(double t) const;      // 6.x
		double coordY(double t) const;		  // 6.y
		double YfromX(double x) const;		  // 7
	};
}
#endif
