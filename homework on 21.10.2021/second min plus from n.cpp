#include <iostream>


int main()
{
    
    int min = 100000;
    int predmin = 100001;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int cur, temp;
        std::cin >>cur;
        if (cur > 0) {
            temp = cur;
            if (cur < min) {
                temp = min;
                min = cur;
            }
            if (predmin > temp) predmin = temp;
        }
    }
    std::cout << predmin;
}

