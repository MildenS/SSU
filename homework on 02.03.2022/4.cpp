#include <iostream>

using namespace std;

template <typename T> T* createarray(int n);
template <typename T> T** createarray2D(int n, int m);

int main()
{
    int* arr1 = createarray<int>(5);
    int** arr2 = createarray2D<int>(3, 4);
}

template <typename T> T* createarray(int n) {
    T* mas = new T[n];
    return mas;
}
template <typename T> T** createarray2D(int n, int m) {
    T** mas = new T * [n];
    for (int i = 0; i < n; i++) {
        mas[i] = new T[m];
    }
    return mas;
}
