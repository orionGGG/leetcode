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
	/*����sting���erase������erase(first,last)ģʽ
	���first���±���0��ɾ���ķ�Χ��[first,last)
	���������0��ɾ���ķ�Χ��[first,last]
	*/
	return 0;
}