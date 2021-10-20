#include <iostream>

int main()
{
    int m, s=0;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int a;
        std::cin >> a;
        if (a < 0) s += a;
    }
    std::cout << s;
}

