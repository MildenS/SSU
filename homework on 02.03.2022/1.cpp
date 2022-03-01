//эта задачка добавила мне седых волос
#include <iostream>

using namespace std;

void drawLine(int x);
void rec(int x, int n=1) {
    drawLine(n);
    if (x>n) {
        rec(x, n + 1);
        drawLine(n);
    }
}

int main()
{
    rec(4);
}

void drawLine(int x)
{
    if (x % 2 != 0)
        for (int i = 0; i < x; i++)
            cout << '0';
    else 
        for (int i = 0; i < x; i++)
            cout << '1';
    cout << endl;
}




