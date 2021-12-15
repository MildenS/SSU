#include <iostream> 
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Вводите числа\n";
	int cur, proizv = 1;
	while (true) {
		cin >> cur;
		if (cur % 13 == 0)
			break;
		if (cur != 0 && cur % 10 == 0)
			proizv *= cur;
	}
	if (proizv == 1) {
		cout << "Вы не ввели ни одного ненулевого элемента, оканчивающегося на 0";
		return 0;
	}
	cout << "Ответ: " << proizv;
}
