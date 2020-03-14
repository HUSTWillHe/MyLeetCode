#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	vector<vector<TreeNode*>> dp;
	void cloneTree(TreeNode* root, int& head){
		if(root == NULL)
			return;
		cloneTree(root->left, head);
		root -> val = head;
		head ++;
		cloneTree(root->right, head);
	}

public:
	vector<TreeNode*> generateTrees(int n) {
		if(n <= 0)
			return NULL;
		TreeNode first = 1;
		vector<TreeNode*> vfirst{&first};
		vector<TreeNode*> vhead;
		dp.push_back(vhead);
		dp.push_back(vfirst);
		if(n == 1)
			return dp[1];
		for(int i = 2; i <= n; i++){

		}
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<TreeNode*> ans = s.generateTrees(3);
    return 0;
}
