#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(): val(0), next(NULL) {}
	ListNode(int x): val(x), next(NULL) {}
	ListNode(int x, ListNode *next): val(x), next(next) {}
};

void printNodes(ListNode* head){
	while(head != NULL){
		cout<<head->val<<" -> ";
		head = head -> next;
	}
	cout<<"NULL"<<endl;
}

class Solution {
private:
	ListNode* towardMid(ListNode* head){
		ListNode *fast = head, *slow = head;
		while(true){
			fast = fast -> next;
			if(fast == NULL)
				break;
			fast = fast -> next;
			if(fast == NULL)
				break;
			slow = slow -> next;
		}
		cout<<"mid val: "<<slow -> val<<endl;
		ListNode* cur_next = slow -> next;
		ListNode* cur = slow;
		while(! cur_next){
			ListNode* next_next = cur_next -> next;
			cur_next -> next = cur;
			cur = cur_next;
			cur_next = next_next;
		}
		slow -> next = NULL;
		cout<<"tail val: "<<cur -> val<<endl;
		return cur;
	}
public:
	void reorderList(ListNode* head){
		if(head == NULL)
			return;
		ListNode* tail = towardMid(head);
		while(head != NULL && head != tail){
			ListNode* head_next = head -> next;
			ListNode* tail_next = tail -> next;
			head -> next = tail;
			tail -> next = head_next;
			head = head_next;
			tail = tail_next;
		}
	}	
};

int main(int argc,char** argv){
	Solution s;
	vector<ListNode> vln;
	for(int i = 0; i < 5; i++){
		vln.push_back(ListNode(i));
	}
	for(int i = 0; i < vln.size() - 1; i++){
		vln[i].next = &(vln[i + 1]);
	}
	printNodes(vln.data());
	s.reorderList(vln.data());
	printNodes(vln.data());
    return 0;
}
