#include <iostream>  //вычислить суммы i от 1 до inf s=(i+3)/i!

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	double eps, e = 1e-6, sum=0, fact=1, i=1;
	cout << "Введите точность вычисления ";
	cin >> eps;
	while ((i + 3) / fact > (eps+e)) {
		sum += (i + 3) / fact;
		i++;
		fact *= i;
	}
	cout <<fixed<<"Искомая сумма с точностью " << eps << " равна " << sum<<'\n';
}
