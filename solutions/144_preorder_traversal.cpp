#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void traversalRecursively(TreeNode* root, vector<int>& ans){
		if(root == NULL)
			return;
		ans.push_back(root -> val);
		traversalRecursively(root -> left, ans);
		traversalRecursively(root -> right, ans);
	}
public:
	vector<int> preorderTraversal(TreeNode* root){
		vector<int> ans;
		if(root == NULL)
			return ans;
		traversalRecursively(root, ans);
		return ans;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<TreeNode> vtn;
	for(int i = 0; i < 3; i++){
		vtn.push_back(TreeNode(i));
	}
	vtn[0].left = &(vtn[1]);
	vtn[0].right = &(vtn[2]);
	vector<int> ans = s.preorderTraversal(vtn.data());
	for(auto a: ans)
		cout<<a<<endl;
    return 0;
}
