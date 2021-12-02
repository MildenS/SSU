#include <iostream>  //для N кол-ва отрезков найти  количество горизонтальных, вертикальных и наклонных
					 //у наклонных найти координаты середины, все задачи я выполнил по порядку	
using namespace std;

double midx(double x1, double x2) {
	return (x1 + x2) / 2;
}
double midy(double y1, double y2) {
	return (y1 + y2) / 2;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n, vert = 0, gor = 0, nakl=0;
	double x1, y1, x2, y2;
	cout << "Введите количество отрезков ";
	cin >> n;
	cout << "Введите координаты концов отрезков\n";
	for (int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 - x2 == 0 && abs(y2 - y1) != 0) {
			vert++;
		}
		else if (abs(x1 - x2) != 0 && y1 - y2 == 0) {
			gor++;
		}
		else if (abs(x1 - x2) != 0 && abs(y1 - y2) != 0) {
			nakl++;
			cout << "Середина отрезка с координатами концов (" << x1 << ";" << y1 << ") и (" 
			<< x2 << ";" << y2 << ") имеет координаты (" << midx(x1,x2) << ";" << midy(y1,y2) / 2 << ")\n";
		}
	}
	cout << "Количество вертикальных отрезков равно " << vert << '\n';
	cout << "Количество горизонтальных отрезко равно " << gor << '\n';
	cout << "Количество наклонных отрезков равно " << nakl << '\n';
	

}
