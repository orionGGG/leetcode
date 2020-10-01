#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;


class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int cur_sum = nums[0];
		int max_sum = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			cur_sum = max(cur_sum + nums[i], nums[i]);
			max_sum = max(max_sum, cur_sum);
		}
		return max_sum;
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

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);

		int ret = Solution().maxSubArray(nums);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}