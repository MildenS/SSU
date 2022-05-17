// i и j из исходной задачи (границы отрезка суммирования) я представляю, как индексы в векторе
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

void exercize_func(const vector<int>& v, int m);
//функция для проверки корректности запроса
bool isRight(int i, int j, const vector<int>& v);

int main()
{
	vector<int> nums;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	cin >> m;
	exercize_func(nums, m);
	
}

void exercize_func(const vector<int>& v, int m)
{
	if (m < 1) {
		cout << "Too few request.\n";
		return;
	}
	int l, j;
	for (int i = 1; i <= m; i++) {
		cout << "Entered i and j for " << i << " request: ";
		cin >> l >> j;
		if (!isRight(l, j, v)) {
			cout << "\nRequest #" << i << " is incorrect\n";
			continue;
		}
		//+1 в accumulate нужно, чтобы j оставалось индексом в векторе
		auto sum = accumulate(v.begin() + l, v.begin() + j+1, 0);
		cout << "\nRequest #" << i << ": sum="<<sum<<'\n';
	}
}

bool isRight(int i, int j, const vector<int>& v)
{
	return (i>=0 && j>=0 && i<v.size() && j<v.size());
}
