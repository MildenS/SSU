//случайно увлёкся и сделал 5-ое задание, забыв залить 4-ое 
#include <iostream>
#include <algorithm>

using namespace std;

class Triangle
{
public:
	Triangle();
	Triangle(double a, double b, double c);
	~Triangle();
	//вот методы
	double area();
	double perimeter();
	//
	//вот операторы
	bool operator==(const Triangle& t);
	bool operator!=(const Triangle& t);
	//
private:
	double a, b, c;
	friend bool isSidesRight(double a, double b, double c);
	//вот счётчик
	static int rightTrianglesCount;
	//
	friend bool isRight(const Triangle& t);
};
bool isSidesRight(double a, double b, double c);
bool isRight(const Triangle& t);

int Triangle::rightTrianglesCount = 0;

Triangle::Triangle()
{
	a = b = c = 1;
}

Triangle::Triangle(double a, double b, double c)
{
	if (isSidesRight(a, b, c)) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	else {
		cout << "uncorrect input data, members of object will difine by 1\n";
		*this = Triangle();
	}
	if (isRight(*this))
		rightTrianglesCount++;
}

Triangle::~Triangle()
{
	if (isRight(*this))
		rightTrianglesCount--;
}

double Triangle::area()
{
	double p = (a + b + c) * 0.5;
	return sqrt(p*(p-a)*(p-b)*(p-b));
}

double Triangle::perimeter()
{
	return a+b+c;
}

bool Triangle::operator==(const Triangle& t)
{
	return((a == t.a && b == t.b && c == t.c) ||
		(a == t.a && b == t.c && c == t.b) ||
		(a == t.c && b == t.a && c == t.b) ||
		(a == t.c && b == t.b && c == t.a) ||
		(a == t.b && b == t.c && c == t.a) ||
		(a == t.b && b == t.a && c == t.c));;
}

bool Triangle::operator!=(const Triangle& t)
{
	return !(*this==t);
}

int main()
{
	Triangle t1(-1, 1, 1);
	Triangle t2(1, 0.5, 0.3);
	Triangle t3(3, 4, 5);
    return 0;
}

bool isSidesRight(double a, double b, double c)
{
	return (a<b+c)&&(b<a+c)&&(c<a+b)&&(a>0)&&(b>0)&&(c>0);
}

bool isRight(const Triangle& t)
{
	double arr[] = { t.a, t.b, t.c };
	sort(arr, arr + 3);
	if (arr[0]*arr[0]+arr[1]*arr[1]==arr[2]*arr[2])
		return true;
	return false;
}
