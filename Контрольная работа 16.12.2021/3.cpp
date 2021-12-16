#include <iostream> 
//третья задача из второго варианта

using namespace std;

void printArray(double** arr, int n, int m);

int main()
{
	setlocale(LC_ALL, "rus");
	int n, m;
	cout << "Введите размеры матрицы: ";
	cin >> n >> m;
	if (n < 0 || m < 0) {
		cout << "Отрицательных размеров матриц не бывает:(";
		return 0;
	}
	double** arr = new double* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new double [m];
	}
	cout << "Введите элементы массива:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	double first = arr[0][m - 1];
	cout << "Ваша матрица до изменений:\n";
	printArray(arr, n, m);
	for (int i = 0; i < n - 1; i++) {
		arr[i][m - 1] = arr[i + 1][m - 1];
	}
	arr[n - 1][m - 1] = first;
	cout << "Ваша матрица после изменений:\n";
	printArray(arr, n, m);
}

void printArray(double** arr, int n, int m) {
	for (int i = 0; i < n; i++, cout<<'\n') {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j]<<' ';
		}
	}
	cout << '\n';
}
