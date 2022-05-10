//для сдвига я выбрал понятную человеку индексацию с 1 (т.е. чтобы повторить контейнер нужен сдвиг размер+1)
#include<iostream>
#include<list>
#include<vector>
#include<algorithm>

using namespace std;

//for a
template <typename T>
void vectorShiftHand(vector<T>& v, int n);
template <typename T>
void vectorShiftAlg(vector<T>& v, int n);
//for b
template <typename T>
void listShiftHand(list<T>& lst, int n);
template <typename T>
void listShiftAlg(list<T>& lst, int n);


int main()
{
	/*vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	vectorShiftAlg(v, 3);
	for (auto it = v.begin(); it != v.end(); ++it) {
		cout << *it << ' ';
	}*/
	list<int> lst = { 1,2,3,4,5,6,7,8,9,10 };
	listShiftAlg(lst, 11);
	for (auto it = lst.begin(); it != lst.end(); ++it) {
		cout << *it << ' ';
	}
}

template<typename T>
void vectorShiftHand(vector<T>& v, int n)
{
	vector<T> ans;
	for (int i = 0; i < v.size(); i++)
		ans.push_back(v[(i + n-1) % v.size()]);
	v = ans;
}

template<typename T>
void vectorShiftAlg(vector<T>& v, int n)
{
	n = n % v.size()-1;
	rotate(v.begin(), v.begin() + n, v.end());
}

template<typename T>
void listShiftHand(list<T>& lst, int n)
{
	list<T> ans;
	auto it = lst.begin();
	for (int i = 0; i < n-1; i++) {
		if (it == lst.end())
			it = lst.begin();
		++it;
	}
	for (int i = 0; i < lst.size(); i++) {
		if (it == lst.end())
			it = lst.begin();
		ans.push_back(*it);
		++it;
	}
	lst = ans;
}

template<typename T>
void listShiftAlg(list<T>& lst, int n)
{
	//у list отстутсвует доступ у случайному элементу, поэтому приходится циклом
	for (int i=0; i<n-1; i++)
		rotate(lst.begin(), next(lst.begin()), lst.end());
}
