#include <iostream>
#include <cmath>
const double PI = 3.141592653589793238463;

int main()
{
	double scircle, ssquare;
	double r, a;
	std::cin >> r >> a;
	if (r > 0 && a > 0) {
		scircle = PI * r * r;
		ssquare = a * a;
	}
	else {
		std::cout << "incorrect input " << std::endl;
		return 0;
	}
	if (scircle > ssquare) std::cout << "area of the circle is larger than square's area";
	else if (scircle == ssquare) std::cout << "circle's area equal square's area";
	else std::cout << "square's area larger than circle's area";
}

