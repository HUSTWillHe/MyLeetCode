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
	bool first = true;
	int cur = 0x80000000;
	bool ans = true;
	void getVal(TreeNode* root){
		if(root == NULL)
			return;
		getVal(root -> left);
		if(first){
			cur = root -> val;
			first = false;
		}else{
			if(root -> val <= cur)
				ans = false;
			cur = root -> val;
		}
		getVal(root -> right);
	}
public:
	bool isValidBST(TreeNode* root){
		getVal(root);
		return ans;
	}
};

int main(int argc,char** argv){
	Solution s;
	TreeNode tn[2]{0, -1};
	tn[0].left = &(tn[1]);
	bool ans = s.isValidBST(tn);
	cout<<"ans is: "<<boolalpha<<ans<<endl;
    return 0;
}
