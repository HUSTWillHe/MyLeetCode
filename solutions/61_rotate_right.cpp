#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k){
		if(head == NULL)
			return NULL;
		ListNode* right = head;
		ListNode* left = head;
		int size = 0;
		for(int i = 0; i < k; i++){
			if(right -> next == NULL){
				size = i + 1;
				break;
			}
			right = right -> next;
		}
		if(size != 0){
			k %= size;
			right = head;
			for(int i = 0; i < k; i++){
				right = right -> next;
			}
		}
		while(right -> next != NULL){
			right = right -> next;
			left = left -> next;
		}
		right -> next = head;
		ListNode* result = left -> next;
		left -> next = NULL;
		return result;
	}
};

void printList(ListNode* head){
	while(head != NULL){
		cout<<head->val<<'\t';
		head = head -> next;
	}
	cout<<endl;
}

int main(int argc,char** argv){
	Solution s;
	ListNode* l[6];
	for(int i = 5; i >= 0; i--){
		l[i] = new ListNode(i);
		if(i != 5){
			l[i] -> next = l[i+1];
		}
	}
	l[5] -> next = NULL;
	printList(l[0]);
	ListNode* result = s.rotateRight(l[0], 10);
	printList(result);
    return 0;
}
