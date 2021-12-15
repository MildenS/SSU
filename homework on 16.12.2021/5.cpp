#include <iostream> 

using namespace std;

void printArray(int* arr, int n);

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
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
	}
	int last = arr[n - 1];
	cout << "Ваш массив до изменений:\n";
	printArray(arr, n);
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0)
			arr[i] = last;
	}
	cout << "Ваш массив после изменений:\n";
	printArray(arr, n);
}

void printArray(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}
