#include <iostream>

using namespace std;

int rec(int arr[], int n) {
    if (n - 1 >= 0)
        return rec(arr, n - 1) * arr[n - 1];
    return 1;
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    cout << rec(arr, 5);
}

