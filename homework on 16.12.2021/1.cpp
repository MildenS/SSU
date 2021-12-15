#include <iostream> 

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
	cout << "\nИндексы чётных элементов:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] % 2 == 0)
				cout << i << ' ' << j << '\n';
		}
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

