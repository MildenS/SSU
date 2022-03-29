//0 задание (класс прямоугольника и коллекция прямоугольников)
#include <iostream>
#include <vector>

using namespace std;

class Rectangle
{
public:
	Rectangle();
	Rectangle(int x, int y, int width=1, int height=1);
	void move(int x, int y);
	void reposition(int x, int y);
	void resize(int x, int y);
	void resize(int a);

private:
	int x, y, width, height;
};

Rectangle::Rectangle()
{
	//по умолчанию создаётся квадрат размером 1 на 1 пиксельв левом верхнем углу
	x = y = 0;
	width = height = 1;
}

Rectangle::Rectangle(int x, int y, int width, int height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

void Rectangle::move(int x, int y)
{
	this->x += x;
	this->y += y;
}

void Rectangle::reposition(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Rectangle::resize(int x, int y)
{
	this->width *= x;
	this->height *= y;
}

void Rectangle::resize(int a)
{
	this->width *= a;
	this->height *= a;
}

class RectangleCollection
{
public:
	Rectangle& operator[](int i);
	int size();
	void add(Rectangle &x);
	bool empty();
private:
	vector<Rectangle> v;
};


int main() {
	Rectangle a(25, 30, 128, 256);
	RectangleCollection collection;
	collection.add(a);
	return 0;
}

Rectangle& RectangleCollection::operator[](int i)
{
	if (i < v.size())
		return v[i];
	Rectangle temp = Rectangle();
	return temp;
}

int RectangleCollection::size()
{
	return v.size();
}

void RectangleCollection::add(Rectangle& x)
{
	v.push_back(x);
}

bool RectangleCollection::empty()
{
	return v.size()==0;
}
