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
	//для а
	int findMin();
	void insertAroundMin(int minIndex);
	//
	// 
	//для b
	int findMaxNeg();
	void changeMidElement(int maxNegIndex);
	//

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
	myVector.push_back(-5);
	myVector.push_back(3);
	myVector.push_back(2);
	myVector.push_back(2);
	myVector.push_back(-1);
	myVector.push_back(2);
	myVector.push_back(2);
	//myVector.insertAroundMin(myVector.findMin());
	myVector.changeMidElement(myVector.findMaxNeg());
	for(int i = 0; i < myVector.size(); i++) {
		cout << myVector[i] << ' ';
	}
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
		for (int i = 0; i < elementCount; i++) {
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
	if (k == capacity - 1 || elementCount == capacity) {
		T* temp = new T[capacity * 2];
		for (int i = 0; i < elementCount; i++) {
			temp[i] = arr[i];
		}
		delete[]arr;
		arr = temp;
		capacity *= 2;
	}
	for (int i = elementCount; i > k + 1; i--) {
		arr[i] = arr[i - 1];
	}
	arr[k + 1] = x;
	elementCount++;
	return true;
}

template<typename T>
int SimpleVector<T>::findMin()
{
	
	if (elementCount == 0)
		return -1;
	T minIndex = 0;
	for (int i = 0; i < elementCount; i++) {
		if (arr[i] < arr[minIndex])
			minIndex = i;
	}
	return minIndex;
}

template<typename T>
void SimpleVector<T>::insertAroundMin(int minIndex)
{
	if (minIndex == -1)
		return;
	if (elementCount == capacity) {
		T* temp = new T[capacity * 2];
		for (int i = 0; i < elementCount; i++) {
			temp[i] = arr[i];
		}
		delete[]arr;
		arr = temp;
		capacity *= 2;
	}
	for (int i = elementCount; i > minIndex+1; i--) {
		arr[i] = arr[i - 1];
	}
	arr[minIndex + 1] = 0;
	elementCount++;
	if (elementCount == capacity) {
		T* temp = new T[capacity * 2];
		for (int i = 0; i < elementCount; i++) {
			temp[i] = arr[i];
		}
		delete[]arr;
		arr = temp;
		capacity *= 2;
	}
	for (int i = elementCount; i > minIndex; i--) {
		arr[i] = arr[i - 1];
	}
	arr[minIndex] = 0;
	elementCount++;
}

template<typename T>
int SimpleVector<T>::findMaxNeg()
{
	if (elementCount == 0)
		return-1;
	int maxNegIndex = -1;
	for (int i = 0; i < elementCount; i++) {
		if (arr[i] < 0 && maxNegIndex == -1)
			maxNegIndex = i;
		else if (arr[i]<0 && arr[i]>arr[maxNegIndex])
			maxNegIndex = i;
	}
	return maxNegIndex;
}

template<typename T>
void SimpleVector<T>::changeMidElement(int maxNegIndex)
{
	if (maxNegIndex == -1 || elementCount % 2 == 0) {
		cout << "Something is wrong!";
		return;
	}
	arr[elementCount / 2] = arr[maxNegIndex];
}
