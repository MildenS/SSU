#include <iostream>
#include<string>
#include<set>
#include<unordered_set>
#include<sstream>
#include<iterator>
#include<algorithm>

using namespace std;

//helpful functions
bool isCaps(string s);
set<char> allChars(string s);
unordered_set<char> allCharsUn(string s);

//for a
set<char> capsLettersSet(string& s);
//for b
unordered_set<char> capsLettersUnSet(string& s);

int main()
{
	string s;
	getline(cin, s);
	cout << "----------------------------------------------------\n";
	/*set<char> _set = capsLettersSet(s);
	for (auto it = _set.begin(); it != _set.end(); ++it)
		cout << *it << ' ';*/
	unordered_set<char> _set = capsLettersUnSet(s);
	for (auto it = _set.begin(); it != _set.end(); ++it)
		cout << *it << ' ';
}

bool isCaps(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (!isupper(s[i]))
			return false;
	}
	return true;
}
set<char> allChars(string s)
{
	set<char> ans;
	while (!s.empty()) {
		ans.insert(s[s.size() - 1]);
		s.pop_back();
	}
	return ans;
}
unordered_set<char> allCharsUn(string s) {
	unordered_set<char> ans;
	while (!s.empty()) {
		ans.insert(s[s.size() - 1]);
		s.pop_back();
	}
	return ans;
}

set<char> capsLettersSet(string& s) {
	set<char> anotherLetters, capsLetters, ans;
	string temp;
	istringstream sin(s);
	while (sin >> temp) {
		if (isCaps(temp)) {
			transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			set<char> tempSet = allChars(temp);
			set_union(capsLetters.begin(), capsLetters.end(), tempSet.begin(), tempSet.end(), inserter(capsLetters, capsLetters.begin()));
		}
		else {
			transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			set<char> tempSet = allChars(temp);
			set_union(anotherLetters.begin(), anotherLetters.end(), tempSet.begin(), tempSet.end(), inserter(anotherLetters, anotherLetters.begin()));
		}
	}
	set_difference(capsLetters.begin(), capsLetters.end(), anotherLetters.begin(), anotherLetters.end(), inserter(ans, ans.begin()));
	return ans;
}
unordered_set<char> capsLettersUnSet(string& s) {
	unordered_set<char> anotherLetters, capsLetters;
	string temp;
	istringstream sin(s);
	while (sin >> temp) {
		if (isCaps(temp)) {
			transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			unordered_set<char> tempSet = allCharsUn(temp);
			for (const auto& el : tempSet)
				capsLetters.insert(el);
		}
		else {
			transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			unordered_set<char> tempSet = allCharsUn(temp);
			for (const auto& el : tempSet)
				anotherLetters.insert(el);
		}
	}
	for (const auto& el : anotherLetters)
		capsLetters.erase(el);
	return capsLetters;
	//у unordered_set нет объединения или разницы, поэтому пришлось ручками через for each циклы
}
