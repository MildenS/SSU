#include <iostream>

using namespace std;

void printFloor(int n, int k); //n - номер этажа, k - размер отступа
void printLine(int n, int k, char a = '*'); //n - длина половины строки (я люблю костыли:)), k - размер отступа
void tree(int n, int k=1)//n - количество секций (этажей), k - счётчик этажей (чтобы вовремя остановиться)
{ 
	printFloor(k, n);
	if (k+1<=n)
		tree(n, k + 1);
} 


int main()
{
	tree(4);
}

void printFloor(int n, int k)
{
	for (int i = 0; i <= n; i++)
		printLine(i+1, k-i);
}

void printLine(int n, int k, char a)
{
	for (int i = 0; i < k; i++)
		cout << ' ';
	for (int i = 0; i < 2*n-1; i++)
		cout << a;
	cout << endl;
}

