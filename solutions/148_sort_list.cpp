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


void printListNodes(ListNode* head){
	if(head == NULL){
		cout<<endl;
		return;
	}
		
	cout<<head -> val<<" -> ";
	printListNodes(head -> next);
}

class Solution {
public:
	void switchNode(ListNode* left, ListNode* right){
		if(left == right)
			return;
		int tmp = left -> val;
		left -> val = right -> val;
		right -> val = tmp;
	}

	vector<ListNode*> quickSort(ListNode* head, ListNode* tail){
		cout<<"---------------------------"<<endl;
		if(head == NULL || tail == NULL)
			cout<<"head NULL or tail NULL"<<endl;
		cout<<"head: "<<head->val<<" tail: "<<tail -> val<<endl;
		if(head == tail)
			return vector<ListNode*>{head, tail};
		ListNode* cur = head -> next;
		ListNode* mid = head;
		ListNode* last_cur = head;
		while(cur != tail -> next){
			if(cur -> val < head -> val){
				switchNode(mid -> next, cur);
				mid = mid -> next;
			}
			last_cur = cur;
			cur = cur -> next;
		}
		vector<ListNode*> left, right;
		if(mid == head){ // only right
			cout<<"right side:"<<endl;
			right = quickSort(mid -> next, last_cur);
			head -> next = right[0];
			right[1] -> next = NULL;
			printListNodes(head);
			return vector<ListNode*>{head, right[1]};
		}
		if(mid == tail){ // only left
			cout<<"left side:"<<endl;
			left = quickSort(head -> next, mid); 
			left[1]->next = head;
			head -> next = NULL;
			printListNodes(head);
			return vector<ListNode*> {left[0], head};
		}
		cout<<"bose sides"<<endl;
		ListNode* mid_next = mid -> next;
		left = quickSort(head -> next, mid); 
		cout<<"mid next"<<mid -> next<<endl;
		cout<<"last_cur"<<last_cur -> val<<endl;
		right = quickSort(mid_next, last_cur);
		left[1] -> next = head;
		right[1] -> next = NULL;
		head -> next = right[0];
		printListNodes(head);
		return vector<ListNode*>{left[0], right[1]};
	}

	ListNode* getTail(ListNode* head){
		ListNode* cur = head;
		while(cur -> next != NULL){
			cur = cur -> next;
		}
		return cur;
	}

	ListNode* sortList(ListNode* head){
		if(head == NULL)
			return NULL;
		ListNode* tail = getTail(head);
		cout<<"tail: "<<tail -> val<<endl;
		return quickSort(head, tail)[0];
	}
};

int main(int argc,char** argv){
	Solution s;
	//vector<ListNode> vln{4,19,14,5,-3,1,8,5,11,15};
	vector<ListNode> vln{4, 2, 1, 3};
	for(int i = 0; i < vln.size() - 1; i++){
		vln[i].next = &(vln[i + 1]);
	}
	printListNodes(vln.data());
	ListNode* ans = s.sortList(vln.data());
	printListNodes(ans);
    return 0;
}
