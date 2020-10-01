#include<iostream>
#include<string>
#include<assert.h>
#include<vector>
#include<sstream>

using namespace std;

class Solution {
public:
	vector<int> addToArrayForm(vector<int>& A, int K) {
		vector<int> B;
		while (K != 0)
		{
			B.push_back(K % 10);
			K = K / 10;
		}
		reverse(B.begin(), B.end());
		int a = A.size() - 1, b = B.size() - 1, add = 0;
		vector<int> ans;
		while (a >= 0 || b >= 0 || add != 0)
		{
			int x = 0, y = 0;
			if (a >= 0)
			{
				x = A[a];
			}
			if (b >= 0)
			{
				y = B[b];
			}
			int result = x + y + add;
			add = result / 10;
			ans.push_back(result%10);
			a--;
			b--;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

void trimLeftTrailingSpaces(string& input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
		}));
}

void trimRightTrailingSpaces(string& input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
		}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int stringToInteger(string input) {
	return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}

	if (length == 0) {
		return "[]";
	}

	string result;
	for (int index = 0; index < length; index++) {
		int number = list[index];
		result += to_string(number) + ", ";
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> A = stringToIntegerVector(line);
		getline(cin, line);
		int K = stringToInteger(line);

		vector<int> ret = Solution().addToArrayForm(A, K);

		string out = integerVectorToString(ret);
		cout << out << endl;
	}
	return 0;
}