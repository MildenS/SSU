#include <iostream> 
//вторая задача из второго варианта

using namespace std;

void printArray(double* arr, int n);

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите кол-во элементов: ";
	int n;
	int minnum=0, negnum=-1;
	cin >> n;
	if (n < 0) {
		cout << "Отрицательного размера массива не бывает";
		return 0;
	}
	double* arr = new double[n];
	cout << "Введите сами элементы:\n";
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] < 0)
			negnum = i;
		if (arr[i] < arr[minnum])
			minnum = i;
	}
	cout << "Ваш массив до изменений:\n";
	printArray(arr, n);
	for (int i = minnum+1; i < negnum; i++) {
		arr[i] = 0;
	}
	cout << "Ваш массив после изменений:\n";
	printArray(arr, n);
}

void printArray(double* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}
