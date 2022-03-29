//1 задание (наивная сортировка) 
#include <iostream>
#include<vector>

using namespace std;

void sort(vector<int>& v) {
	while (!v.empty()) {
		int minNum = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] < v[minNum])
				minNum = i;
		}
		cout << v[minNum] << ' ';
		v.erase(v.begin() + minNum);
	}
}


int main()
{
	int n, temp;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	cout << "Your nums before sort:\n";
	for (int i = 0; i < n; i++) {
		cout << v[i]<<' ';
	}
	cout << "\nYour nums after sort:\n";
	sort(v);
}
