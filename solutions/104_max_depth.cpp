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
	int depth = 0;
	void discover(TreeNode* root, int d){
		if(root == NULL)
			return;
		depth = max(depth, d);
		discover(root -> left, d + 1);
		discover(root -> right, d + 1);
	}

public:
	int maxDepth(TreeNode* root){
		discover(root, 1);
		return depth;
	}
};

int main(int argc,char** argv){
	Solution s;
	TreeNode tn[4]{0, 1, 2, 3};
	tn[0].left = &(tn[1]);
	tn[1].left = &(tn[2]);
	tn[2].left = &(tn[3]);
	int ans = s.maxDepth(tn);
	cout<<"ans: "<<ans<<endl;
    return 0;
}
