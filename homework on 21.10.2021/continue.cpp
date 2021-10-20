#include <iostream>
#include <vector>
int main()
{
    int a;
    std::vector <int> v;
    do {
        std::cin >> a;
        if (a % 2 != 0) continue;
        v.push_back(a);
    } while (a != 0);
    for (int i = 0; i < v.size(); ++i) {
        std:: cout << v[i] << ' ';
    }
}


