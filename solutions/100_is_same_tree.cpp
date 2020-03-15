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
public:
	bool isSameTree(TreeNode* p, TreeNode* q){
		if(p == NULL && q == NULL)
			return true;
		if(p == NULL || q == NULL)
			return false;
		if(p->val != q->val)
			return false;
		else
			return isSameTree(p->left, q->left) & isSameTree(p->right, q->right);
	}
};

int main(int argc,char** argv){
	TreeNode tn[4]{0, 1, 2, 3};
	tn[0].left = &(tn[1]);
	tn[0].right = &(tn[2]);
	tn[2].left = &(tn[3]);

	TreeNode tm[4]{0, 1, 2, 2};
	tm[0].left = &(tm[1]);
	tm[0].right = &(tm[2]);
	tm[2].left = &(tm[3]);

	Solution s;
	bool ans = s.isSameTree(&(tn[0]), &(tm[0]));
	cout<<"ans: "<<ans<<endl;
    return 0;
}
