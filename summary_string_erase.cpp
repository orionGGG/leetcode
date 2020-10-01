#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<assert.h>
#include<stack>
#include<algorithm>
#include<queue>

using namespace std;


int main() {
	string s = "12345";
	s.erase(0, 1);
	cout << s << endl;
	s.erase(1, 2);
	cout << s << endl;
	/*对于sting类的erase方法的erase(first,last)模式
	如果first的下标是0则删除的范围是[first,last)
	而如果不是0则删除的范围是[first,last]
	*/
	return 0;
}