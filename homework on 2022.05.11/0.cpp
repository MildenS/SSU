//в конце использовал вектор для более удобного вывода текущего состояния
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void fillWagons(stack<char>& q);
void distributionSystem(stack<char>& q, int n);

int main() {
	int n;
	stack<char> wagons;
	cout << "Enter wagons: ";
	fillWagons(wagons);
	cout << "\nEnter count of requests: ";
	cin >> n;
	distributionSystem(wagons, n);
	if (!wagons.empty()) {
		string s;
		cout << "\nThe remaining wagons:\n";
		while (!wagons.empty()) {
			s += wagons.top();
			wagons.pop();
		}
		reverse(s.begin(), s.end());
		cout << s;
	}
	else {
		cout<<"\nWagons is end!";
	}
}

void fillWagons(stack<char>& q)
{
	string temp;
	cin >> temp;
	for (int i = 0; i<temp.size(); i++) {
		q.push(temp[i]);
	}
}

void distributionSystem(stack<char>& q, int n)
{
	vector<char> first;
	vector<char> second;
	char wag; int deadEndNum;
	for (int i = 0; i < n; i++) {
		cout << "\nEnter " << i + 1 << " request: ";
		cin >> wag >> deadEndNum;
		if (q.top()== wag) {
			if (deadEndNum == 1) {
				first.emplace(first.begin(),q.top());
				q.pop();
			}
			else {
				second.emplace(second.begin(),q.top());
				q.pop();
			}
		}
		cout << "\nCurrent status: \n First dead end: ";
		for (int i = 0; i < first.size(); i++)
			cout << first[i] << ' ';
		cout << "\nSecond dead end: ";
		for (int i = 0; i < second.size(); i++)
			cout << second[i] << ' ';
		cout << '\n';
	}
}
