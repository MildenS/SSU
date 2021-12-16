#include <iostream> 
//первая задача из второго варианта

using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	int chet = 0, nechet = 0, cur;
	cin >> cur;
	while (cur > 0) {
		if (cur % 2 == 0)
			chet++;
		else 
			nechet++;
		cin >> cur;
	}
	if (chet > nechet) {
		cout << "Чётных чисел среди введёный больше.";
	}
	else if (chet == nechet) {
		cout << "Количество чётных чисел равно количеству нечётных.";
	}
	else {
		cout << "Нечётных чисел среди введённых больше.";
	}
}

