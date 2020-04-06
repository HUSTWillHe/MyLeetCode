#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left, *right;
	TreeNode(int x): left(NULL), right(NULL), val(x) {}
};

class Solution {
private:
	TreeNode* core(vector<int> inorder, vector<int> postorder){
		if(inorder.empty() || postorder.empty() || inorder.size() != postorder.size())
			return NULL;
		int root_val = *(postorder.end() - 1);
		TreeNode* root = new TreeNode(root_val);
		vector<int>::iterator it = find(inorder.begin(), inorder.end(), root_val);
		vector<int> l_in(inorder.begin(), it);
		vector<int> r_in(it + 1, inorder.end());
		int left_len = l_in.size();
		vector<int> l_post(postorder.begin(), postorder.begin() + left_len);
		vector<int> r_post(postorder.begin() + left_len, postorder.end() - 1);
		root -> left = core(l_in, l_post);
		root -> right = core(r_in, r_post);
		return root;
	}

public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return core(inorder, postorder);
	}
};

void printTreeInorder(TreeNode* root){
	if(!root)
		return;
	printTreeInorder(root -> left);
	cout<<root->val<<endl;
	printTreeInorder(root -> right);
}

void printTreePostorder(TreeNode* root){
	if(!root)
		return;
	printTreePostorder(root -> left);
	printTreePostorder(root -> right);
	cout<<root -> val<<endl;
}

int main(int argc,char** argv){
	Solution s;
	vector<int> in{9, 3, 15, 20, 7};
	vector<int> post{9, 15, 7, 20, 3};
	TreeNode* ans = s.buildTree(in, post);
	cout<<"inorder"<<endl;
	printTreeInorder(ans);
	cout<<"postorder"<<endl;
	printTreePostorder(ans);
    return 0;
}
