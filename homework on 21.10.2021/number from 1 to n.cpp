#include <iostream>

int main()
{
	int n;
	std:: cin >> n;
	if (n > 0) {
		for (int i = 1; i <= n; ++i) {
			std::cout << i << std:: endl;
		}
	}
	else {
		for (int i = n; i <= 0; ++i) {
		std:: cout << i << std::endl;
		}
	}
}

