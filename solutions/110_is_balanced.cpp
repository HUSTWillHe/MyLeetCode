#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int getDeep(TreeNode* root){
		if(root == NULL)
			return 0;
		return max(getDeep(root -> left), getDeep(root -> right)) + 1;
	}

public:
	bool isBalanced(TreeNode* root){
		if(root == NULL)
			return true;
		cout<<"----------------------"<<endl;
		cout<<"root val: "<<root -> val<<endl;
		cout<<"left depth: "<< getDeep(root -> left)<<endl;
		cout<<"right depth: "<< getDeep(root -> right)<<endl;
		if(abs(getDeep(root -> right) - getDeep(root -> left)) > 1)
			return false;
		return isBalanced(root -> left) && isBalanced(root -> right);
	}
};

int main(int argc,char** argv){
	Solution s;
	TreeNode tn[5]{0, 1, 2, 3, 4};
	tn[0].left = tn + 1;
	tn[0].right = tn + 4;
	tn[1].left = tn + 2;
	tn[1].right = tn + 3;
	bool ans = s.isBalanced(tn);
	cout<<boolalpha<<ans<<endl;
    return 0;
}
