#include <iostream>

using namespace std;

class Point2D
{
public:
	Point2D(double x, double y);
	double x, y;
private:
};

class Point3D
{
public:
	Point3D(double x, double y, double z);
	double x, y, z;
};

double distance(double x1, double y1, double x2, double y2);
double distance(double x1, double y1, double z1, double x2, double y2, double z2);
double distance(Point2D p1, Point2D p2);
double distance(Point3D p1, Point3D p2);



int main()
{
	Point2D p1(1, 2);
	Point2D p2(2, 3);
	Point3D p3(1, 2,3);
	Point3D p4(2, 3,4);
	cout << distance(p1.x, p1.y, p2.x, p2.y)<<endl;
	cout << distance(p1, p2) << endl;
	cout << distance(p3.x, p3.y, p3.z, p4.x, p4.y, p4.z)<<endl;
	cout << distance(p3,p4)<<endl;

}

Point2D::Point2D(double x, double y)
{
	this->x = x;
	this->y = y;
}

Point3D::Point3D(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

double distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2-x1,2)+ pow(y2 - y1, 2));
}

double distance(double x1, double y1, double z1, double x2, double y2, double z2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)+ pow(z2 - z1, 2));
}

double distance(Point2D p1, Point2D p2)
{
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double distance(Point3D p1, Point3D p2)
{
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)+ pow(p2.z - p1.z, 2));
}
