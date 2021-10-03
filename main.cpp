#define _USE_MATH_DEFINES
#define _CRTDBG_MAP_ALLOC

#include "C:\Users\User\source\repos\oop_2\Libary1\astro.h"     

using namespace P2;

int main() {
	double r;
	std::cout << "Enter radius: ";
	getNum(r);

	try {
		astroid astro(r);
	}
	catch (std::exception & ex) {
		std::cout << ex.what() << std::endl;
		return 0;
	}
	astroid astro(r);

	const char* msgs[] = { "0. Quit", "1. Input new radius", "2. Arc len from 0 to t (0 <= t <= 90)", "3. Full arc len", "4. Curve radius", "5. Astroid area", "6. Coordinates", "7. Y from X" };

	int d;
	while (1) {
		for (int i = 0; i < 8; i++)	{
			std::cout << msgs[i] << std::endl;
		}
		P2::getNum(d);
		switch (d) {
		case 0:
			std::cout << "Bye" << std::endl;
			return 0;
		case 1:
			std::cout << "Enter radius: ";
			getNum(r);
			try {
				astro.setR(r);
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
				r = 0;
			}
			continue;
		case 2:
			std::cout << "Enter angle t: " << std::endl;
			double t2;
			getNum(t2);
			try {
				astro.arcLen(t2);
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
				continue;
			}
			std::cout << "Arc len from 0 to " << t2 << " is: " << astro.arcLen(t2) << std::endl;
			continue;
		case 3:
			std::cout << "Full arc len is: " << astro.allLen() << std::endl;
			continue;
		case 4:
			std::cout << "Enter angle t: " << std::endl;
			double t4;
			getNum(t4);
			std::cout << "Curve radius is: " << astro.curvRad(t4) << std::endl;
			continue;
		case 5:
			std::cout << "Astroid area is: " << astro.astroidArea() << std::endl;
			continue;
		case 6:
			std::cout << "Enter parameter t: " << std::endl;
			double t6;
			getNum(t6);
			std::cout << "x: " << astro.coordX(t6) << " y: " << astro.coordY(t6) << std::endl;
			continue;
		case 7:
			std::cout << "Enter x: " << std::endl;
			double x;
			getNum(x);
			if (abs(x) > (4 * r)) {
				std::cout << "X is out of range" << std::endl;
				continue;
			}
			else {
				std::cout << "y: " << astro.YfromX(x) << std::endl;
				continue;
			}			
		default:
			continue;
		}
	}	
}
