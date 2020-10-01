#include<iostream>
#include<string>
#include<assert.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int a = num1.length() - 1, b = num2.length() - 1;
        int add = 0, x = 0, y = 0, z = 0;
        string result = "";
        while (a >= 0 || b >= 0 || add != 0)
        {
            if (a >= 0)
            {
                x = num1[a] - '0';
            }
            else
            {
                x = 0;
            }
            if (b >= 0)
            {
                y = num2[b] - '0';
            }
            else
            {
                y = 0;
            }
            z = x + y + add;
            result.push_back(z % 10 + '0');
            add = z / 10;
            a--;
            b--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
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
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);

        string ret = Solution().addStrings(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}