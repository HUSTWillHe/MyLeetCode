#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left, *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root){
		vector<vector<int>> ans;
		if(root == NULL)
			return ans;
		ans.push_back(vector<int>{root -> val});
		vector<TreeNode*> vtn;
		vtn.push_back(root);
		for(int i = 0; ;i++){
			if(ans.size() == i)
				break;
			vector<int> temp;
			vector<TreeNode*> temp_vtn;
			for(auto a: vtn){
				if(a->left != NULL){
					temp.push_back(a->left->val);
					temp_vtn.push_back(a -> left);
				}
				if(a->right != NULL){
					temp.push_back(a->right->val);
					temp_vtn.push_back(a -> right);
				}
			}
			if(!temp.empty())
				ans.push_back(temp);
			vtn = temp_vtn;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main(int argc,char** argv){
	Solution s;
	TreeNode tn[5]{3, 9, 20, 15, 7};
	tn[0].left = tn + 1;
	tn[0].right = tn + 2;
	tn[2].left = tn + 3;
	tn[2].right = tn + 4;
	vector<vector<int>> ans = s.levelOrderBottom(tn);
	for(auto vi: ans){
		for(auto i: vi){
			cout<<i<<'\t';
		}
		cout<<endl;
	}
    return 0;
}
