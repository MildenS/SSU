//1 задание (начало создания SimpleVectоr)
#include <iostream>

using namespace std;

template <typename T>
class SimpleVector
{
public:
	SimpleVector(int n);
	//~SimpleVector();
	void push_back(T a);
	T& operator[](int n);

private:
	T* arr;
	//текущее количество элементов в векторе
	int elementCount;
	//размер вектора
	int capacity;
};


int main()
{
	SimpleVector<int> myVector(3);
	myVector.push_back(5);
	cout << myVector[0];
	myVector.push_back(3);
	cout << myVector[1];
	myVector.push_back(1);
	cout << myVector[2];
	myVector.push_back(1);
}

template<typename T>
SimpleVector<T>::SimpleVector(int n)
{
	if (n < 1)
		n = 1;
	this->arr = new T[n];
	capacity = n;
	elementCount = 0;
}

template<typename T>
void SimpleVector<T>::push_back(T a)
{
	if (elementCount >= capacity) {
		cout << "Your vector is overflow\n";
		return;
	}
	arr[elementCount] = a;
	elementCount++;
}

template<typename T>
T& SimpleVector<T>::operator[](int n)
{
	return arr[n];
}

