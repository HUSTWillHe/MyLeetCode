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
	bool hasCycle(ListNode* head){
		ListNode* fast = head, *slow = head;
		while(fast != NULL){
			for(int i = 0; i < 2; i++){
				fast = fast -> next;
				if(!fast)
					return false;
			}
			slow = slow -> next;
			if(fast == slow)
				return true;
		}
		return false;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> vi{1, 2, 3, 4};
	vector<ListNode> vln;
	for(auto a: vi){
		vln.push_back(ListNode(a));
	}
	for(int i = 0; i < vln.size() - 1; i++){
		vln[i].next = &(vln[i + 1]);
	}
	vln[3].next = &(vln[1]);
	bool ans = s.hasCycle(vln.data());
	cout<<"ans: "<<ans<<endl;
    return 0;
}
