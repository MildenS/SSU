#include <iostream> 
#include <vector>
//четвёртая задача из второго варианта

using namespace std;

vector<int> vectorOfDels (int a, int b);

int main()
{
	setlocale(LC_ALL, "rus");
	int a,b;
	cout << "Введите ваши числа: ";
	cin >> a >> b;
	if (a == 0 && b == 0) {
		cout << "Оба ваши числа равны нулю. Они имеют бесконечное количество общих делителей.";
		return 0;
	}
	vector<int> dels = vectorOfDels(a, b);
	cout << "Общие делители ваших чисел:\n";
	for (int i = 0; i < dels.size(); i++) {
		cout << dels[i] << ' ';
	}
}

vector<int> vectorOfDels(int a, int b) {
	if (a == 0 && b != 0) {
		return vectorOfDels(b, b);
	}
	else if (a != 0 && b == 0) {
		return vectorOfDels(a, a);
	}
	else {
		vector<int> dels;
		a = abs(a);
		b = abs(b);
		for (int i = 1; i <= min(a, b); i++) {
			if (a % i == 0 && b % i == 0)
				dels.push_back(i);
		}
		return dels;
	}
}
