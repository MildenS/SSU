#include <iostream> 

using namespace std;

void printArray(int* arr, int n);

int main()
{
	setlocale(LC_ALL, "rus");
	int n, lastneg=1;
	cout << "Введите количество чисел ";
	cin >> n;
	if (n < 1) {
		cout << "Такого количества чисел ввести нельзя (либо вы вообще не хотите вводить числа:))";
		return 0;
	}
	int* arr = new int[n];
	cout << "Введите поочерёдно числа\n";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] < 0)
			lastneg = arr[i];
	}
	if (lastneg == 1) {
		cout << "Вы не ввели ни одного отрицательного числа. Ваш массив:\n";
		printArray(arr, n);
		return 0;
	}
	cout << "Ваш массив до изменений:\n";
	printArray(arr, n);
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0)
			arr[i] = lastneg;
	}
	cout << "Ваш массив после изменений:\n";
	printArray(arr, n);
	delete [] arr;
}

void printArray(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}
