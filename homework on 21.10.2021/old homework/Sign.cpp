// Sign.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    double num;
    char sign;
    std::cout << "Enter a number ";
    std::cin >> num;
    sign = num > 0 ? '+' : (num < 0 ? '-' : '0');
    std::cout << "Sign of number is "<<sign<<std::endl;
}

