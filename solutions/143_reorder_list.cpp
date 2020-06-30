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

void printListNode(ListNode* head){
	while(head != NULL){
		cout<<head -> val<<" -> ";
		head =  head -> next;
	}
	cout<<"NULL"<<endl;
}

class Solution {
private:
	ListNode* flip_tail(ListNode* head){
		ListNode* fast = head;
		ListNode* slow = head;
		while(true){
			fast = fast -> next;
			if(fast == NULL)
				break;
			fast = fast -> next;
			if(fast == NULL)
				break;
			slow = slow -> next;
		}
		ListNode* cur_next = slow -> next;
		slow -> next = NULL;
		while(cur_next != NULL){
			ListNode* next_next = cur_next -> next;
			cur_next -> next = slow;
			slow = cur_next;
			cur_next = next_next;
		}
		return slow;
	}
public:
	void reorderList(ListNode* head){
		if(head == NULL)
			return;
		ListNode* tail;
		tail = flip_tail(head);
		while(head != NULL && head != tail){
			ListNode *head_next = head -> next, *tail_next = tail -> next;
			head -> next = tail;
			tail -> next = head_next;
			head = head_next;
			tail = tail_next;
		}
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> vi{1, 2, 3, 4, 5};
	vector<ListNode> vln;
	for(int i = 0; i < vi.size(); i++){
		vln.push_back(ListNode(vi[i]));
	}
	for(int i = 0; i < vi.size() - 1; i++){
		vln[i].next = &(vln[i + 1]);
	}
	printListNode(vln.data());
	s.reorderList(vln.data());
	cout<<"after =============="<<endl;
    return 0;
	printListNode(vln.data());
}
