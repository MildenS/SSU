#include <iostream>

int main()
{
	int kolvo = 0;
	int a;
	std::cin >> a;
	if (a != 0) {
		do {
			if (a % 2 != 0) kolvo++;
			std::cin >> a;
		} while (a != 0);
	}
	std::cout << kolvo;
}

