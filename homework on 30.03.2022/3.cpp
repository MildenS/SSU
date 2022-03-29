//3 задание (сортировка строк) 
#include <iostream>
#include<string>

using namespace std;

bool sortComp(string s1, string s2);

void insertionSort(string* a, int n)
{
    for (int i = 1; i < n; i++)
        for (int j = i; j > 0 && sortComp(a[j], a[j - 1]); j--)
            swap(a[j - 1], a[j]);
}

int main()
{
    int n;
    string temp;
    cin >> n;
    string* sarr = new string[n];
    for (int i = 0; i < n; i++) {
        cin>> temp;
        sarr[i] = temp;
    }
    cout <<"Your string before sort:\n";
    for (int i = 0; i < n; i++) {
        cout << sarr[i]<<' ';
    }
    insertionSort(sarr, n);
    cout << "\nYour strings after sort:\n";
    for (int i = 0; i < n; i++) {
        cout << sarr[i] << ' ';
    }
    delete[] sarr;
}

bool sortComp(string s1, string s2)
{
    return (s1.size()<s2.size() || (s1.size() == s2.size() && s1<s2));
}
