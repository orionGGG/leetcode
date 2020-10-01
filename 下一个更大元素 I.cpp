#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<assert.h>
#include<stack>
#include<algorithm>
#include<queue>

using namespace std;

 class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		int j = 0;
		vector<int> res;
		bool judge = false;
		for (int i = 0; i < nums1.size(); i++)
		{
			judge = false;
			j = 0;
			while (nums2[j] != nums1[i])
			{
				j++;
			}
			for (int k = j; k < nums2.size(); k++)
			{
				if (nums2[k] > nums1[i])
				{
					judge = true;
					res.push_back(nums2[k]);
					break;
				}
			}
			if (judge == false)
			{
				res.push_back(-1);
			}
		}
		return res;
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
		vector<int> nums1 = stringToIntegerVector(line);
		getline(cin, line);
		vector<int> nums2 = stringToIntegerVector(line);

		vector<int> ret = Solution().nextGreaterElement(nums1, nums2);

		string out = integerVectorToString(ret);
		cout << out << endl;
	}
	return 0;
}