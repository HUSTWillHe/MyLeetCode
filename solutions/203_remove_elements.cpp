#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
private:
	ListNode* findFirstValid(ListNode* head, int val) {
		while(head != NULL && head->val == val){
			head = head->next;
		}
		return head;
	}

public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* new_head = findFirstValid(head, val);
		if(new_head == NULL)
			return NULL;
		ListNode* cur = new_head->next, *last = new_head;
		while(cur != NULL) {
			if(cur->val == val) {
				cur = cur->next;
				last->next = cur;
			}else{
				last = cur;
				cur = cur->next;
			}
		}
		return new_head;
	}
};

void printNodes(ListNode* head){
	while(head != NULL){
		cout<<head->val<<'\t';
		head = head->next;
	}
	cout<<endl;
}

int main(int argc,char** argv){
	Solution s;
	vector<ListNode> vln{0, 0, 1, 2, 3, 0, 4, 3, 3};
	for(int i = 0; i < vln.size() - 1; i++){
		vln[i].next = &(vln[i + 1]);
	}
	cout<<"before:  "<<endl;
	printNodes(vln.data());
	string ss = argv[1];
	cout<<"remove: "<<ss<<endl;
	auto ans = s.removeElements(vln.data(), stoi(ss));
	cout<<"after:  "<<endl;
	printNodes(ans);
    return 0;
}
