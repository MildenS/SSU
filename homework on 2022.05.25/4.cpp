#include<iostream>
#include<set>
#include<algorithm>
#include<numeric>
#include<iterator>

using namespace std;

const set<int> evenDig = { 0,2,4,6,8 };
const set<int> oddDig = { 1,3,5,7,9 };
const set<int> allDig = { 1,3,5,7,9,0,2,4,6,8 };

const set<char> vowelLetters = { 'a','e','i','u','o', 'y'};
const set<char> consonantLetters = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' };

//for a
set<int> allDigits(int n);
set<char> allChars(string s);
//for б
set<int> evenDigits(int n);
set<char> vowelChars(string s);
//for в
set<int> oddDigits(int n);
set<char> consonantChars(string s);
//for г
set<int> notFindedDigits(int n);
set<char> notFindedChars(string s);
//for д
set<int> notFindedOddDigits(int n);
set<char> notFindedConsonantChars(string s);

int main()
{
	/*int n;
	cin >> n;
	set<int> s = notFindedOddDigits(n);
	for (auto it = s.begin(); it != s.end(); it++)
		cout << *it << ' ';*/
	string s;
	cin >> s;
	set<char> _s = notFindedConsonantChars(s);
	for (auto it = _s.begin(); it != _s.end(); it++)
		cout << *it << ' ';
}

set<int> allDigits(int n)
{
	set<int> ans;
	n = abs(n);
	if (n == 0) {
		ans.insert(n);
		return ans;
	}
	while (n > 0) {
		ans.insert(n % 10);
		n /= 10;
	}
	return ans;
}

set<char> allChars(string s)
{
	set<char> ans;
	while (!s.empty()) {
		ans.insert(s[s.size()-1]);
		s.pop_back();
	}
	return ans;
}

set<int> evenDigits(int n)
{
	set<int> temp = allDigits(n);
	set<int> ans;
	set_difference(begin(temp), end(temp), begin(oddDig), end(oddDig), inserter(ans, begin(ans)));
	return ans;
}

set<char> vowelChars(string s)
{
	set<char> temp=allChars(s);
	set<char> ans;
	set_intersection(temp.begin(), temp.end(), vowelLetters.begin(), vowelLetters.end(), inserter(ans, ans.begin()));
	return ans;
}

set<int> oddDigits(int n)
{
	set<int> temp = allDigits(n);
	set<int> ans;
	set_difference(begin(temp), end(temp), begin(evenDig), end(evenDig), inserter(ans, begin(ans)));
	return ans;
}

set<char> consonantChars(string s)
{
	set<char> temp = allChars(s);
	set<char> ans;
	set_difference(temp.begin(), temp.end(), vowelLetters.begin(), vowelLetters.end(), inserter(ans, ans.begin()));
	return ans;
}

set<int> notFindedDigits(int n)
{
	set<int> temp = allDigits(n);
	set<int> ans;
	set_difference(begin(allDig), end(allDig), begin(temp), end(temp), inserter(ans, begin(ans)));
	return ans;
}

set<char> notFindedChars(string s)
{
	set<char> temp = allChars(s);
	set<char> ans;
	set_difference(vowelLetters.begin(), vowelLetters.end(), temp.begin(), temp.end(), inserter(ans, ans.begin()));
	set_difference(consonantLetters.begin(), consonantLetters.end(), temp.begin(), temp.end(), inserter(ans, ans.begin()));
	return ans;

}

set<int> notFindedOddDigits(int n)
{
	set<int> temp = oddDigits(n);
	set<int> ans;
	set_difference(begin(oddDig), end(oddDig), begin(temp), end(temp), inserter(ans, begin(ans)));
	return ans;
}

set<char> notFindedConsonantChars(string s)
{
	set<char> temp = consonantChars(s);
	set<char> ans;
	set_difference(begin(consonantLetters), end(consonantLetters), begin(temp), end(temp), inserter(ans, begin(ans)));
	return ans;
}
