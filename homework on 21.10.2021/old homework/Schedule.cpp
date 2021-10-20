// Schedule.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    setlocale(LC_ALL, "ru");
    int day, parity;
    std::cout << "Введите чётность недели (1 - числитель, 2 - знаменатель) ";
    std::cin >> parity;
    std::cout << "Введите номер дня недели (1 - понедельник, 2 - вторник и т.д.) ";
    std::cin >> day;
    if (parity == 1) {
        switch (day) {
            case(1): 
                std::cout << "По расписанию у вас 1 пара, если вы в первой подгруппе, и 2 пары, если в другой" << std::endl;
                break;
            case(2):
                std::cout << "По расписанию у вас 3 пары" << std::endl;
                break;
            case(3):
                std::cout << "По расписанию у вас 3 пары или 4, если вы переводчик" << std::endl;
                break;
            case(4):
                std::cout << "По расписанию у вас 2 пары" << std::endl;
                break;
            case(5):
                std::cout << "По расписанию у вас 3 пары или 4, если вы в первой подгруппе" << std::endl;
                break;
            default:
                std::cout << "У вас нет пар или такого дня не существует" << std::endl;
                break;
        }
    }
    else {
        switch (day) {
        case(1):
            std::cout << "По расписанию у вас 1 пара, если вы в первой подгруппе, и 2 пары, если в другой" << std::endl;
            break;
        case(2):
            std::cout << "По расписанию у вас 3 пары" << std::endl;
            break;
        case(3):
            std::cout << "По расписанию у вас 3 пары или 4, если вы переводчик" << std::endl;
            break;
        case(4):
            std::cout << "По расписанию у вас 3 пары" << std::endl;
            break;
        case(5):
            std::cout << "По расписанию у вас 2 пары или 3, если вы в первой подгруппе" << std::endl;
            break;
        default:
            std::cout << "У вас нет пар или такого дня не существует" << std::endl;
            break;
        }
    }

    return 0;
}

