#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;
	Node(): val(0), left(NULL), right(NULL), next(NULL) {}
	Node(int _val): val(_val), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	Node* connect(Node* root){
		if(root == NULL)
			return NULL;
		Node* last_level = root;
		while(last_level != NULL){
			Node* last_cur = last_level;
			Node* head = NULL, *cur = NULL;
			while(last_cur != NULL){
				if(last_cur -> left != NULL){
					if(head == NULL){
						head = last_cur -> left;
						cur = head;
					}else{
						cur -> next = last_cur -> left;
						cur = cur -> next;
					}
				}
				if(last_cur -> right != NULL){
					if(head == NULL){
						head = last_cur -> right;
						cur = head;
					}else{
						cur -> next = last_cur -> right;
						cur =  cur -> next;
					}
				}
				last_cur = last_cur->next;
			}
			last_level = head;
		}
		return root;
	}
};

void printNode(Node* n){
	if(n == NULL)
		return;
	cout<<"val: "<<n -> val<<endl;
	if(n->next != NULL)
		cout<<"next: "<<n -> next -> val <<endl;
	else
		cout<<"next: NULL"<<endl;
	printNode(n -> left);
	printNode(n -> right);
}

int main(int argc, char** argv){
	Solution s;
	Node n[6] {1, 2, 3, 4, 5, 6};
	n[0].left = n + 1;
	n[0].right = n + 2;
	n[1].left = n + 3;
	n[1].right = n + 4;
	n[2].right = n + 5;
	Node* ans = s.connect(n);
	printNode(ans);
    return 0;
}
