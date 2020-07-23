#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode;
void printNodes(ListNode*);

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	vector<ListNode*> insertSorted(ListNode* head, ListNode* sorted_tail, ListNode* cur){
		cout<<"invoke insertSorted"<<endl;
		cout<<"head: "<<head -> val<<" sorted_tail: "<<sorted_tail-> val<<" cur: "<<cur -> val<<endl;
		ListNode* ln = head;
		ListNode* prev = NULL;
		while(ln != cur){
			cout<<"ln: "<<ln -> val<<endl;
			if(cur -> val < ln -> val){
				if(ln == head){
					sorted_tail -> next = cur -> next;
					cur -> next = head;
					return vector<ListNode*>{cur, sorted_tail};
				}else{
					sorted_tail -> next = cur -> next;
					prev -> next = cur;
					cur -> next = ln;
				}
				break;
			}
			prev = ln;
			ln = ln -> next;
		}
		if(ln == cur){
			return vector<ListNode*>{head, cur};
		}
		return vector<ListNode*>{head, sorted_tail};
	}

	ListNode* insertionSortList(ListNode* head){
		if(head == NULL)
			return NULL;
		ListNode* cur = head -> next;
		ListNode* sorted_tail = head;
		while(cur != NULL){
			cout<<"====================="<<endl;
			cout<<"cur: "<<cur -> val<<endl;
			ListNode* next = cur -> next;
			vector<ListNode*> ln = insertSorted(head, sorted_tail, cur);
			head = ln[0];
			sorted_tail = ln[1];
			cur = next;
			printNodes(head);
		}
		return head;
	}
};

void printNodes(ListNode* head){
	if(head == NULL){
		cout<<endl;
		return;
	}
	cout<<head -> val<<"->";
	printNodes(head -> next);
}

int main(int argc,char** argv){
	Solution s;
	vector<ListNode> vln;
	vector<int> vi{4, 2, 1, 3};
	for(auto i: vi){
		vln.push_back(ListNode(i));
	}
	for(int i = 0; i < vln.size() - 1; i++){
		vln[i].next = &(vln[i + 1]);
	}
	printNodes(vln.data());
	ListNode* head = s.insertionListNode(vln.data());
	printNodes(head);
    return 0;
}
