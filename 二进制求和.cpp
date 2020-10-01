#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include <assert.h>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int i = a.length() - 1, j = b.length() - 1;
		int add = 0, x = 0, y = 0;
		int result = 0;
		string ans = "";
		while (i >= 0 || j >= 0 || add != 0)
		{
			if (i >= 0)
			{
				x = a[i] - '0';
			}
			else {
				x = 0;
			}
			if (j >= 0)
			{
				y = b[j] - '0';
			}
			else {
				y = 0;
			}
			result = (x + y + add) % 2;
			add = (x + y + add) / 2;
			ans.push_back(result + '0');
			i--;
			j--;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

string stringToString(string input) {
	string result;
	for (int i = 0; i < input.length(); i++) {
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
		string a = stringToString(line);
		getline(cin, line);
		string b = stringToString(line);

		string ret = Solution().addBinary(a, b);

		string out = (ret);
		cout << out << endl;
	}
	return 0;
}