// Distance from a point to a circle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
int main()
{
    double x1, y1, x2, y2, R, D;
    std::cin >> x1 >> y1 >> x2 >> y2 >> R;
    D = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2))-R;
    std::cout << D<<std::endl;
    return 0;
}

