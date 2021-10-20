#include <iostream>
double f(double a, double b, double x) {
    return a * x * x * x + b / (x - 1);
}

int main()
{
    double a, b, c, d, h;
    std::cin >> a >> b >> c >> d>>h;
    std::cout << "a= " << a << "   b= " << b << std::endl;
    for (double i = c; i <= d; i += h) {
        std::cout << "x= " << i << "   f= " << f(a, b, i) << std::endl;
    }

}

