#include <iostream>  

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	double k;
	int n, count=0;
	cout << "Введите количество лыж и k ";
	cin >> n >> k;
	double* lengths = new double[n];
	cout << "\nBведите длины лыж\n";
	for (int i = 0; i < n; i++) {
		cin >> lengths[i];
	}
	for (int i = 0; i < (n-1); i++) {
		for (int j = (i + 1); j < n; j++) {
			if (lengths[i] + lengths[j] == k)
				count++;			
		}
	}
	cout << "Количество возможны пар равно " << count << '\n';
}
