#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	bool isMirror(TreeNode* left, TreeNode* right){
		if(left == NULL && right == NULL)
			return true;
		if(left == NULL || right == NULL)
			return false;
		if(left -> val != right -> val)
			return false;
		return isMirror(left -> left, right -> right) && isMirror(left -> right, right -> left);
	}
public:
	bool isSymmetric(TreeNode* root){
		if(root == NULL)
			return true;
		return isMirror(root -> left, root -> right);
	}
};

int main(int argc,char** argv){
	Solution s;
	TreeNode tn[6]{0, 1, 1, 2, 3, 3};
	tn[0].left = &(tn[1]);
	tn[0].right = &(tn[2]);
	tn[1].left = &(tn[3]);
	tn[1].right = &(tn[4]);
	tn[2].left = &(tn[5]);
//	tn[2].right = &(tn[6]);
	bool ans = s.isSymmetric(tn);
	cout<<boolalpha<<ans<<endl;
    return 0;
}
