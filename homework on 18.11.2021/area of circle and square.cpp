#include <iostream>
#include <cmath>
const double PI = 3.141592653589793238463;
void valid(double r, double a);

int main()
{
	double r, a;
	std::cin >> r >> a;
	valid(r, a);
}
void valid(double r, double a) {
	if (r < 0 || a < 0) {
		std::cout << "incorrect input";
		return;
	}
	double scircle = PI * r * r;
	double ssquare = a * a;
	if (scircle > ssquare) std::cout << "area of the circle is larger than square's area";
	else if (scircle == ssquare) std::cout << "circle's area equal square's area";
	else std::cout << "square's area larger than circle's area";
}
