#include <iostream>

using namespace std;

class Triangle
{
public:
	Triangle();
	Triangle(int a, int b, int c);
	~Triangle();

private:
	double a, b, c;
	friend bool isSidesRight(double a, double b, double c);
};
bool isSidesRight(double a, double b, double c);

Triangle::Triangle()
{
	a = b = c = 1;
}

Triangle::Triangle(int a, int b, int c)
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
}

Triangle::~Triangle()
{
}

int main()
{
	Triangle t1(-1, 1, 1);
	Triangle t2(1, 0.5, 0.3);
    return 0;
}

bool isSidesRight(double a, double b, double c)
{
	return (a<b+c)&&(b<a+c)&&(c<a+b)&&(a>0)&&(b>0)&&(c>0);
}
