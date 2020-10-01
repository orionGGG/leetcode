#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<sstream>
#include<algorithm>
#include<assert.h>

using namespace std;

class Solution {
public:
	string removeOuterParentheses(string S) {
		int left = 0, right = 0, start = 0, length = 0;
		vector<string> sum;
		string result = "";
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] == '(')
			{
				left++;
				length++;
			}
			if (S[i] == ')')
			{
				right++;
				length++;
			}
			if (left == right)
			{
				sum.push_back(S.substr(start, length));
				length = 0;
				start = 2 * left;
				continue;
			}
		}
		for (int i = 0; i < sum.size(); i++)
		{
			result = result + sum[i].substr(1, sum[i].size() - 2);
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
		string S = stringToString(line);

		string ret = Solution().removeOuterParentheses(S);

		string out = (ret);
		cout << out << endl;
	}
	return 0;
}