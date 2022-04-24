#include <iostream>
#include<stack>
#include<queue>

using namespace std;

void exerciseFunc(int n);

int main() {
	int n;
	cin >> n;
	exerciseFunc(n);
}

void exerciseFunc(int n)
{
	int temp;
	queue<int> even;
	stack<int> odd;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		if (abs(temp) % 2 == 0)
			even.push(temp);
		else
			odd.push(temp);
	}
	cout << "------------------------\n";
	while (!even.empty()) {
		cout << even.front()<<' ';
		even.pop();
	}
	while (!odd.empty()) {
		cout << odd.top()<<' ';
		odd.pop();
	}
}

