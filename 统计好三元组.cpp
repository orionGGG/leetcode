#include<iostream>
#include<string>
#include <cmath>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
	int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
		int num = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			for (int j = i + 1; j < arr.size(); j++)
			{
				for (int k = j + 1; k < arr.size(); k++)
				{
					if (abs(arr[i] - arr[j]) <= a &&
						abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
					{
						num++;
					}
				}
			}
		}
		return num;
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

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> arr = stringToIntegerVector(line);
		getline(cin, line);
		int a = stringToInteger(line);
		getline(cin, line);
		int b = stringToInteger(line);
		getline(cin, line);
		int c = stringToInteger(line);

		int ret = Solution().countGoodTriplets(arr, a, b, c);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}