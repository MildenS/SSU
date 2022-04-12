//2 задание (продолжение создания SimpleVectоr, деструктор и улучшенный push_back)
#include <iostream>

using namespace std;

template <typename T>
class SimpleVector
{
public:
	SimpleVector(int n);
	~SimpleVector();
	void push_back(T a);
	T& operator[](int n);
	//для удобства тестов
	int size();

private:
	T* arr;
	//текущее количество элементов в векторе
	int elementCount;
	//размер вектора
	int capacity;
};


int main()
{
	SimpleVector<int> myVector(1);
	myVector.push_back(5);
	myVector.push_back(3);
	myVector.push_back(1);
	myVector.push_back(1);
	myVector.push_back(2);
	for (int i = 0; i < myVector.size(); i++)
		cout << myVector[i] << ' ';
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
SimpleVector<T>::~SimpleVector()
{
	delete[] arr;
}

template<typename T>
void SimpleVector<T>::push_back(T a)
{
	if (elementCount == capacity) {
		T* temp = new T[capacity * 2];
		for(int i = 0; i < elementCount; i++) {
			temp[i] = arr[i];
		}
		delete[]arr;
		arr = temp;
		capacity *= 2;
	}
	arr[elementCount] = a;
	elementCount++;
}

template<typename T>
T& SimpleVector<T>::operator[](int n)
{
	return arr[n];
}

template<typename T>
int SimpleVector<T>::size()
{
	return elementCount;
}
