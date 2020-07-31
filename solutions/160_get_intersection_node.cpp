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
	int getLen(ListNode* head){
		int cnt = 0;
		while(head != NULL){
			cnt ++;
			head = head -> next;
		}
		return cnt;
	}

	ListNode* forward(ListNode* head, int len){
		for(int i = 0; i < len; i++){
			head = head -> next;
		}
		return head;
	}

public:
	ListNode *getIntersectionNode(ListNode* headA, ListNode* headB){
		int lena = getLen(headA);
		cout<<"len a: "<<lena<<endl;
		int lenb = getLen(headB);
		cout<<"lenb: "<<lenb<<endl;
		if(lena > lenb){
			headA = forward(headA, lena - lenb);
		}
		else if(lenb > lena){
			headB = forward(headB, lenb - lena);
		}
		cout<<"head a: "<<headA -> val<<endl;
		cout<<"head b: "<<headB -> val<<endl;
		while(headA != NULL){
			if(headA == headB)
				return headA;
			headA = headA -> next;
			headB = headB -> next;
		}
		return NULL;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<ListNode> vln{0, 1, 2, 3, 4, 5, 6, 7};
	vln[0].next = &(vln[1]);
	vln[1].next = &(vln[2]);
	vln[3].next = &(vln[4]);
	vln[4].next = &(vln[5]);
	vln[5].next = &(vln[2]);
	vln[2].next = &(vln[6]);
	vln[6].next = &(vln[7]);
	ListNode* ans = s.getIntersectionNode(&(vln[0]), &(vln[3]));
	cout<<"ans: "<<ans -> val<<endl;
    return 0;
}
