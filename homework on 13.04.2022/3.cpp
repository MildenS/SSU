//3 задание (продолжение создания SimpleVectоr, find, remove, insert_after)
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
	int find(T a);
	void remove(T a);
	bool insert_after(T x, T y);

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
	myVector.push_back(2);
	myVector.push_back(1);
	//myVector.push_back(2);
	for (int i = 0; i < myVector.size(); i++)
		cout << myVector[i] << ' ';
	myVector.remove(5);
	cout << endl;
	for (int i = 0; i < myVector.size(); i++)
		cout << myVector[i] << ' ';
	myVector.insert_after(10, 1);
	cout << endl;
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

template<typename T>
int SimpleVector<T>::find(T a)
{
	for (int i = 0; i < elementCount; i++) {
		if (arr[i] == a)
			return i;
	}
	return -1;
}

template<typename T>
void SimpleVector<T>::remove(T a)
{
	int k = find(a);
	if (k == -1)
		return;
	for (int i = k; i < elementCount - 1; i++)
		arr[i] = arr[i + 1];
	elementCount--;
}

template<typename T>
bool SimpleVector<T>::insert_after(T x, T y)
{
	int k = find(y);
	if (k == -1)
		return false;
	if (k == capacity-1 || elementCount==capacity) {
		T* temp = new T[capacity * 2];
		for (int i = 0; i < elementCount; i++) {
			temp[i] = arr[i];
		}
		delete[]arr;
		arr = temp;
		capacity *= 2;
	}
	for (int i = elementCount; i > k+1; i--) {
		arr[i] = arr[i - 1];
	}
	arr[k+1] = x;
	elementCount++;
	return true;
}
