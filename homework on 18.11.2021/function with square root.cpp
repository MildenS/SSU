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
	double a, b, c;
	std::cin >> a>>b>>c;
	if (root(a)&&root(b)&&root(c)) {
		std::cout << "square root of input numbers is " << a <<" "<<b<<" "<<c<< std::endl;
		return 0;
	}
	std::cout << "incorrect input" << std::endl;
}
