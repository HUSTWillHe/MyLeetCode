#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum){
		if(root == NULL){
			return false;
		}
		if(root -> left == NULL && root -> right == NULL && sum == root ->val)
			return true;
		int last = sum - root->val;
		return hasPathSum(root -> right, last) || hasPathSum(root -> left, last);
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<TreeNode>tn{5, 4, 8, 11, 13, 4, 7, 2, 1};
	tn[0].left = tn.data() + 1;
	tn[0].right = tn.data() + 2;
	tn[1].left = tn.data() + 3;
	tn[2].left = tn.data() + 4;
	tn[2].right = tn.data() + 5;
	tn[3].left = tn.data() + 6;
	tn[3].right = tn.data() + 7;
	tn[5].right = tn.data() + 8;
	bool ans = s.hasPathSum(tn.data(), 22);
	cout<<boolalpha<<ans<<endl;
    return 0;
}
