#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		int x1 = 0;
		int res = 0;
		int fin = x;
		std::vector<int> vec;
		if (x > 0)
		{
			while (x != 0)
			{
				x1 = x % 10;
				vec.push_back(x1);
				x = x / 10;
			}
			for (int i = 0; i < vec.size(); i++)
			{
				res = res * 10 + vec[i];
			}
			if (res == fin)
			{
				return true;
			}
		}
		if (x < 0)
		{
			return false;
		}
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		int x = stringToInteger(line);

		bool ret = Solution().isPalindrome(x);

		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}