#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n){
		ListNode* return_head = head;
		ListNode* before = NULL;
		ListNode* top = head;
		if(m != 0){
			for(int i = 0; i < m - 1; i++){
				top = top -> next;
			}
			before = top;
			top = top -> next;
		}
		ListNode* cur = top -> next, *last = top;
		for(int i = 0; i < n - m - 1; i++){
			ListNode* next = cur -> next;
			cur -> next = last;
			last = cur;
			cur = next;
		}
		top -> next = cur;
		if(before != NULL)
			before -> next = last;
		if(m == 0)
			return_head = last;
		return return_head;
	}
	
};

int main(int argc,char** argv){
	Solution s;
	ListNode* pln[10];
	for(int i = 9; i >= 0; i--){
		pln[i] = new ListNode(i);
		if(i != 9){
			pln[i] -> next = pln[i+1];
		}
	}
	ListNode* head = new ListNode(0);
	cout<<"before: ===================="<<endl;
	ListNode* node = pln[0];
	while(node != NULL){
		cout<<node->val<<" -> ";
		node = node -> next;
	}
	cout<<endl;

	ListNode* ans = s.reverseBetween(pln[0], 3, 5);

	node = ans;
	while(node != NULL){
		cout<<node->val<<" -> ";
		node = node -> next;
	}
	cout<<endl;
	for(int i = 0; i < 10; i++){
		delete pln[i];
	}
    return 0;
}
