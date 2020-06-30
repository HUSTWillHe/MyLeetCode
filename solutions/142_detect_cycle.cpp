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
	ListNode* detectCycle(ListNode* head){
		if(head == NULL)
			return NULL;
		ListNode* fast = head, *slow = head;
		ListNode* right, *left = head;
		while(true){
			for(int i = 0; i < 2; i++){
				fast = fast -> next;
				if(!fast)
					return NULL;
			}
			slow = slow -> next;
			if(fast == slow){
				right = fast;
				break;
			}
		}
		while(true){
			if(right == left)
				return right;
			right = right -> next;
			left = left -> next;
		}
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> vi{1, 2};
	vector<ListNode> vln;
	for(int i = 0; i < vi.size(); i++){
		vln.push_back(ListNode(vi[i]));
	}
	for(int i = 0; i < vi.size() - 1; i++){
		vln[i].next = &(vln[i + 1]);
	}
	vln[vln.size() - 1].next = &(vln[0]);
	ListNode* ans = s.detectCycle(vln.data());
	cout<<"ans: "<<ans -> val<<endl;
    return 0;
}
