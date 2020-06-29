#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val){
		val = _val;
		next = NULL;
		random = NULL;
	}
};

void printNodes(Node* head){
	Node* cur = head;
	while(cur != NULL){
		if(cur -> random){
			cout<<cur -> val << "(" << cur -> random -> val << ") -> ";
		}else{
			cout<<cur -> val << "(NULL) -> ";
		}
		cur = cur -> next;
	}
	cout<<"NULL"<<endl;
}

class Solution {
public:
	Node* copyRandomList(Node* head){
		if(head == NULL)
			return NULL;
		vector<Node*> ans;	
		vector<Node*> rand;
		map<Node*, Node*> old_new;
		Node* cur = head;
		while(cur != NULL){
			Node* new_cur = new Node(cur -> val);
			ans.push_back(new_cur);
			rand.push_back(cur -> random);
			old_new[cur] = new_cur;
			cur = cur -> next;
		}
		int size = ans.size();
		for(int i = 0; i < size; i ++){
			if(i != size -1){
				ans[i] -> next = ans[i + 1];
			}
			ans[i] -> random  = old_new[rand[i]];
		}
		return ans[0];
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<Node*> vn;
	vector<int> vi{7, 13, 11, 10, 1};
	for(int a: vi){
		vn.push_back(new Node(a));
	}
	for(int i = 0; i < vn.size() - 1; i++){
		vn[i] -> next = vn[i + 1];
	}
	vn[1] -> random = vn[0];
	vn[2] -> random = vn[4];
	vn[3] -> random = vn[2];
	vn[4] -> random = vn[0];
	Node* ans = s.copyRandomList(vn[0]);
	printNodes(ans);
    return 0;
}
