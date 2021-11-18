#include <iostream>
#include <cmath>
#include <iomanip>
const int n = 10000;


int main()
{
	double sum = 0, sum1;
	for (int i = 1; i <= n; i++) {
		sum +=  1./i;
	}
	std::cout << std::fixed << std::setprecision(15) << sum << std::endl;
	sum1 = sum;
	sum = 0;
	for (int i = n; i >= 1; i--) {
		sum +=  1./i;
	}
	std::cout << std::fixed << std::setprecision(15) << sum << std::endl;
	std::cout << "difference is " << abs(sum1 - sum) << std::endl;
}
