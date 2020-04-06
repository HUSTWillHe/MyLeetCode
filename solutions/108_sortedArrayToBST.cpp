#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums){
		if(nums.empty())
			return NULL;
		int size = nums.size();
		int half = size/2;
		TreeNode* root = new TreeNode(nums[half]);
		vector<int> l(nums.begin(), nums.begin() + half);
		vector<int> r(nums.begin() + half + 1, nums.end());
		root -> left = sortedArrayToBST(l);
		root -> right = sortedArrayToBST(r);
		return root;
	}
};

void printTree(TreeNode* root){
	if(root == NULL)
		return;
	printTree(root -> left);
	cout<<root -> val<<endl;
	printTree(root -> right);
}

int main(int argc,char** argv){
	Solution s;
	vector<int> vi{1, 2, 3, 4, 5};
	TreeNode* ans = s.sortedArrayToBST(vi);
	printTree(ans);
    return 0;
}
