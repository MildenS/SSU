#include <iostream>  

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "Введите количество чисел ";
	cin >> n;
	int* arr = new int[n];
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i < n; i++) {
		arr[i] = arr[i - 2] + arr[i - 1];
	}
	cout << "Числа Фибоначчи от 1 до вашего числа в обратном порядке:\n";
	for (int i = n-1; i>=0; i--) {
		cout << arr[i] << " ";
	}

}
