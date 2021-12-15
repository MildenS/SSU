#include <iostream> 

using namespace std;

bool changer(int& a, int& b, int& c);

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите числа\n";
	int a, b, c;
	cin >> a >> b >> c;
	if (changer(a, b, c)) {
		cout << "Что-то изменилось. Новые значения переменных: a=" << a << ", b=" << b << ", c=" << c;
	}
	else {
		cout << "Все введённые числа положительные, изменений не произошло";
	}
}

bool changer(int& a, int& b, int& c) {
	bool isChanged = false;
	if (a < 0) {
		a = 0;
		isChanged = true;
	}
	if (b < 0) {
		b = 0;
		isChanged = true;
	}
	if (c < 0) {
		c = 0;
		isChanged = true;
	}
	return isChanged;
}
