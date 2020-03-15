#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	TreeNode* left = NULL;
	TreeNode* right = NULL;
	TreeNode* last = NULL;
	void switchTree(TreeNode* root){
		if(root == NULL)
			return;
		switchTree(root -> left);
		if(last == NULL){
			last = root;
		}else{
			if(left == NULL){
				if(root -> val <= last -> val){
					left = last;
					right = root;
				}
			}else{
				if(root -> val <= last -> val){
					right = root;
				}
			}
			last = root;
		}
		switchTree(root -> right);
	}

public:
	void recoverTree(TreeNode* root){
		switchTree(root);
		int temp = left -> val;
		left -> val = right -> val;
		right -> val = temp;
	}
};

int main(int argc,char** argv){
	Solution s;
	TreeNode tn[3]{1, 3, 2};
	tn[0].left = &(tn[1]);
	tn[2].right = &(tn[2]);
	s.recoverTree(&(tn[0]));
    return 0;
}
