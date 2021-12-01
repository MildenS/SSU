#include <iostream>  

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите количество чисел ";
	cin >> n;
	int* arr = new int[n];
	cout << "Введите числа\n";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "\nBаша последовательность чисел до изменения:\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	if (n % 2 == 0) {
		double temp = arr[n / 2];
		arr[n / 2] = arr[n / 2 - 1];
		arr[n / 2 - 1] = temp;
	}
	else {
		arr[n / 2] *= 2;
	}
	cout << "\nВаша последовательность после изменения:\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i]<<" ";
	}

}
