#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		int i = 0;
		ListNode* p;
		ListNode* q;
		p = head;
		q = head;
		if (head->val == val)
		{
			head->val = head->next->val;
			head->next = head->next->next;
			return head;
		}
		while (p->val != val)
		{
			i++;
			p = p->next;
		}
		for (int j = 0; j < i - 1; j++)
		{
			q = q->next;
		}
		q->next = q->next->next;
		return head;
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

ListNode* stringToListNode(string input) {
	// Generate list from the input
	vector<int> list = stringToIntegerVector(input);

	// Now convert that list into linked list
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for (int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

int stringToInteger(string input) {
	return stoi(input);
}

string listNodeToString(ListNode* node) {
	if (node == nullptr) {
		return "[]";
	}

	string result;
	while (node) {
		result += to_string(node->val) + ", ";
		node = node->next;
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
	string line;
	while (getline(cin, line)) {
		ListNode* head = stringToListNode(line);
		getline(cin, line);
		int val = stringToInteger(line);

		ListNode* ret = Solution().deleteNode(head, val);

		string out = listNodeToString(ret);
		cout << out << endl;
	}
	return 0;
}