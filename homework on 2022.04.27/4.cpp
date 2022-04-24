#include <iostream>
#include<stack>
#include<queue>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

template<typename T>
void vectorFunc(vector<T>& v);
template<typename T>
void listFunc(list<T>& lst);
template<typename T>
void queueFunc(queue<T>& q);
template<typename T>
void stackFunc(stack<T>& s);

int main() {
	int n, temp;
	cin >> n;
	stack<int> s;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		s.push(temp);
	}
	stackFunc(s);
	cout << "------------------------------\n";
	while(!s.empty()){
		int temp=s.top();
		cout << temp<<' ';
		s.pop();
	}
}

template<typename T>
void vectorFunc(vector<T>& v)
{
	if (v.size() == 0) {
		cout << "Your vector is too small";
		return;
	}
	auto minIt = min_element(v.begin(), v.end());
	auto insertIt = v.begin();
	insertIt++;
	v.insert(insertIt, *minIt);
}

template<typename T>
void listFunc(list<T>& lst)
{
	if (lst.size() == 0) {
		cout << "Your list is too small";
		return;
	}
	auto minIt= min_element(lst.begin(), lst.end());
	auto insertIt = lst.begin();
	insertIt++;
	lst.insert(insertIt, *minIt);
}

template<typename T>
void queueFunc(queue<T>& q)
{
	if (q.empty()) {
		cout << "Your queue is too small";
		return;
	}
	queue<T> temp = q;
	T min = q.front();
	while (!temp.empty()) {
		if (temp.front() < min)
			min = temp.front();
		temp.pop();
	}
	T el;
	for (int i = 0; !q.empty(); i++) {
		el = q.front();
		if (i == 0) {
			temp.push(el);
			temp.push(min);
		}
		else
			temp.push(el);
		q.pop();
	}
	swap(temp, q);
}

template<typename T>
void stackFunc(stack<T>& s)
{
	if (s.empty()) {
		cout << "Yout stack is too small";
		return;
	}
	stack<int> temp = s;
	T min=s.top();
	while (!temp.empty()) {
		if (temp.top() < min)
			min = temp.top();
		temp.pop();
	}
	for (int i = 0; !s.empty(); i++) {
		if (s.size()==1) {
			temp.push(min);
			temp.push(s.top());
		}
		else
			temp.push(s.top());
		s.pop();
	}
	swap(temp,s);
}
