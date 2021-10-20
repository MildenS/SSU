// P and S triangle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <iomanip>
const double PI = 3.14159265;
int main()
{
    double c, ang, a, b, P, S;
    std::cin >> c >> ang;
    a = sin(ang * PI/180) * c;
    b = cos(ang * PI/180) * c;
    P = a + b + c;
    S = (a * b) / 2;
    std::cout <<std::fixed<<std::setprecision(5)<< "P=" << P << std::endl << "S=" << S;
    return 0;
}

