#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
double arifm(double a, double b);
double geom(double a, double b);
bool maxmiddle(double arifm, double geom);

int main()
{
	double a, b, c, d, max1, max2, arifm1,arifm2, geom1, geom2;
	std::cin >> a >> b >> c >> d; //ввод двух пар чисел
	if (a * b < 0 || c * d < 0) {
		std::cout << "incorrect input" << std::endl;
		return 1;  //1 возвращается, потому что неверный ввод (невозможно посчитать среднее геометрическое, если элементы разных знаков)
	}
	arifm1 = arifm(a, b);
	geom1 = geom(a, b);
	if (maxmiddle(arifm1, geom1)) {
		max1 = arifm1;
	}
	else max1 = geom1;
	arifm2 = arifm(c, d);
	geom2 = geom(c, d);
	if (maxmiddle(arifm2, geom2)) {
		max2 = arifm2;
	}
	else max2 = geom2;
	std::cout << (maxmiddle(max1, max2)? max1: max2);
}
double arifm(double a, double b) {
	return (a + b) / 2;
}
double geom(double a, double b) {
	return sqrt(a * b);
}
bool maxmiddle(double arifm, double geom) {
	return (arifm > geom);
}
