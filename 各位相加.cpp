#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include <assert.h>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int result = 0;
        while (num >= 10)
        {
            vector<int> numgw;
            while (num > 0)
            {
                numgw.push_back(num % 10);
                num = num / 10;
            }
            for (int i = 0; i < numgw.size(); i++)
            {
                result = result + numgw[i];
            }
            num = result;
            result = 0;
        }
        return num;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        int ret = Solution().addDigits(num);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}