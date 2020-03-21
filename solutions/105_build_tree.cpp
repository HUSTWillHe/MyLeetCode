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

void printInorder(TreeNode* root){
	if(root == NULL)
		return;
	printInorder(root -> left);
	cout<<root -> val<<'\t';
	printInorder(root -> right);
	cout<<endl;
}

void printPreorder(TreeNode* root){
	if(root == NULL)
		return;
	cout<<root -> val <<'\t';
	printPreorder(root -> left);
	printPreorder(root -> right);
	cout<<endl;
}

class Solution {
private:
	void build(vector<int> preorder, vector<int> inorder, TreeNode* root){
		cout<<"new round ====================="<<endl;
		cout<<"preorder"<<endl;
		for(auto a: preorder)
			cout<<a<<'\t';
		cout<<endl;
		cout<<"inorder:"<<endl;
		for(auto a: inorder)
			cout<<a<<'\t';
		cout<<endl;
		cout<<"------------------------"<<endl;
		root -> val = preorder[0];
		vector<int>::iterator it = find(inorder.begin(), inorder.end(), preorder[0]);
		vector<int> left_inorder(inorder.begin(), it); 
		vector<int> right_inorder(it + 1, inorder.end());
		int left_size = left_inorder.size();
		int right_size = right_inorder.size();
		if(left_size != 0){
			root -> left = new TreeNode(0);
			vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + left_size);
			build(left_preorder, left_inorder, root -> left);
		}
		if(right_size != 0){
			root -> right = new TreeNode(0);
			vector<int> right_preorder(preorder.begin() + 1 + left_size, preorder.end());
			build(right_preorder, right_inorder, root -> right);
		}
	}

public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
		int size = preorder.size();
		if(preorder.empty() || inorder.empty() || size != inorder.size())
			return NULL;
		TreeNode* root = new TreeNode(0);
		build(preorder, inorder, root);
		return root;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> preorder{1, 2, 4, 5, 3, 6, 7};
	vector<int> inorder{4, 2, 5, 1, 6, 3, 7};
	TreeNode* ans = s.buildTree(preorder, inorder);

	cout<<"ans preorder: "<<endl;
	printPreorder(ans);
	cout<<"ans inorder: "<<endl;
	printInorder(ans);
	
//	TreeNode* ans = func();
//	cout<<"+++++++++++++++"<<endl;
//	printPreorder(ans);
    return 0;
}
