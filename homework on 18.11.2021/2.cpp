#include <iostream>
#include <cmath>

bool root(double &a) {
	if (a >= 0) {
		a = sqrt(a);
		return true;
	}
	else return false;
}

int main()
{
	double a;
	std::cin >> a;
	if (root(a)) {
		std::cout << "square root of input number is " << a << std::endl;
		return 0;
	}
	std::cout << "incorrect input" << std::endl;
}
