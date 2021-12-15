#include <iostream> 
#include <iomanip>

using namespace std;

int** createArray(int n, int m);
void fillArray(int** &arr, int n, int m);
void deleteArray(int**& arr, int n, int m);

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите размеры массива ";
	int n, m;
	cin >> n >> m;
	int** arr = createArray(n, m);
	cout << "\nВведите поочерёдно элементы массива\n";
	fillArray(arr, n, m);
	cout << "\n№ столбца   Сумма отрицательных элементов массива   Позиция максимального отрицательного:\n";
	for (int j = 0; j < m; j++) {
		int sum = 0, maxX = -1, maxY = -1;
		for (int i = 0; i < n; i++) {
			if (arr[i][j] < 0)
				sum += arr[i][j];
			if (arr[i][j] < 0 && maxX == -1) {
				maxX = i;
				maxY = j;
			}
			else if (arr[i][j]<0 && arr[i][j]>arr[maxX][maxY]) {
				maxX = i;
				maxY = j;
			}
		}
		cout<<setw(10) << j + 1 << '\t' << sum << '\t' << maxX << ' ' << maxY << '\n';
	}
	deleteArray(arr, n, m);
}

int** createArray(int n, int m) {
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	return arr;
}
void fillArray(int**& arr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}
void deleteArray(int**& arr, int n, int m) {
	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}
