//про сохранение порядка простых чисел в задании не сказано:)
//почему-то copy_if не захотел работаьть с вынесённой в отдельную функцию провркой на простоту
//и пришлось везде лепить лямбду
//movePrimeToBeginVectorHand не компилюруется в MSVS, но в онлайн компиляторе работает (так и не понял, почему)
#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;

bool isPrime(int a);
//for a
void movePrimeToBeginVectorHand(vector<int>& v);
void movePrimeToBeginVectorAlg(vector<int>& v);
//for b
void movePrimeToBeginListHand(list<int>& lst);
void movePrimeToBeginListAlg(list<int>& lst);


int main()
{
	/*list<int> lst = { 2, 4, 6, 8, 10, 1, 2, 3, 7, 11 };
	movePrimeToBeginListAlg(lst);
	for (auto it = lst.begin(); it != lst.end(); ++it)
		cout << *it << ' ';*/
	vector<int> v = { 12, 2, 4, 6, 8, 10, 1, 2, 3, 7, 11 };
	movePrimeToBeginVectorAlg(v);
	for (auto it = v.begin(); it != v.end(); ++it)
		cout << *it << ' ';
}

bool isPrime(int a)
{
	a = abs(a);
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0)
			return false;
	}
	return true;
}

void movePrimeToBeginVectorHand(vector<int>& v)
{
	auto it = v.begin();
	while (it != v.end()) {
		if (isPrime(*it)) {
			int temp = *it;
			it = v.erase(it);
			v.emplace(v.begin(),temp);
			continue;
		}
		++it;
	}
}

void movePrimeToBeginVectorAlg(vector<int>& v)
{
	vector<int> ans;
	copy_if(v.begin(), v.end(), back_inserter(ans), [](int a) {
		a = abs(a);
		for (int i = 2; i * i <= a; i++) {
			if (a % i == 0)
				return false;
		}
		return true;
		});
	copy_if(v.begin(), v.end(), back_inserter(ans), [](int a) {
		a = abs(a);
		for (int i = 2; i * i <= a; i++) {
			if (a % i == 0)
				return true;
		}
		return false;
		});
	v = ans;
}

void movePrimeToBeginListHand(list<int>& lst)
{
	auto it = lst.begin();
	while (it != lst.end()) {
		if (isPrime(*it)) {
			int temp = *it;
			it = lst.erase(it);
			lst.push_front(temp);
			continue;
		}
		++it;
	}
}

void movePrimeToBeginListAlg(list<int>& lst)
{
	list<int> ans;
	copy_if(lst.begin(), lst.end(), back_inserter(ans), [](int a) {
		a = abs(a);
		for (int i = 2; i * i <= a; i++) {
			if (a % i == 0)
				return false;
		}
		return true;
		});
	copy_if(lst.begin(), lst.end(), back_inserter(ans), [](int a) {
		a = abs(a);
		for (int i = 2; i * i <= a; i++) {
			if (a % i == 0)
				return true;
		}
		return false;
		});
	lst = ans;
}
