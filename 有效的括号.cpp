#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<assert.h>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if (s.length() == 0)
		{
			return true;
		}
		if (s.length() % 2 != 0)
		{
			return false;
		}
		stack<char> st1;
		int num = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				st1.push(s[i]);
			}
			if (s[i] == ')' || s[i] == ']' || s[i] == '}')
			{
				if (st1.empty())
					return false;
				if (st1.top() + 2 == s[i] || st1.top() + 1 == s[i])
				{
					num++;
					st1.pop();
				}
			}
		}
		if (num == s.length() / 2)
		{
			return true;
		}
		else
			return false;
	}
};

string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);

		bool ret = Solution().isValid(s);

		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}