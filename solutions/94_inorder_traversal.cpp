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
	vector<int> ans;
	void recursive(TreeNode* nood){
		if(nood == NULL)
			return;
		recursive(nood -> left);
		ans.push_back(nood -> val);
		recursive(nood -> right);
	}
public:
	vector<int> inorderTraversal(TreeNode* root){
		if(root == NULL)
			return ans;
		recursive(root);
		return ans;
	}
};

int main(int argc,char** argv){
	Solution s;
	TreeNode tn[3]{1,2,3};
	tn[0].right = &(tn[1]);
	tn[1].left = &(tn[2]);
	vector<int> ans = s.inorderTraversal(tn);
	for(auto a: ans){
		cout<<a<<endl;
	}
    return 0;
}
