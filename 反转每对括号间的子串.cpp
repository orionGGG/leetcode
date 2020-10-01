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
	string reverseParentheses(string s) {
		stack<string> stack1;
		string result;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
			{
				stack1.push(result);
				result = "";
			}
			if (s[i] == ')')
			{
				reverse(result.begin(), result.end());
				result = stack1.top() + result;
				stack1.pop();
			}
			if (s[i] != '(' && s[i] != ')')
			{
				result.push_back(s[i]);
			}
		}
		return result;
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

int main() {
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);

		string ret = Solution().reverseParentheses(s);

		string out = (ret);
		cout << out << endl;
	}
	return 0;
}