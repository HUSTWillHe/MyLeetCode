#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left, *right;
	TreeNode(int i):val(i), left(NULL), right(NULL) {}
};

class Solution {
private:
	vector<int> ans;
	vector<TreeNode*> storage; 
public:
	vector<int> rightSideView(TreeNode* root) {
		if(root == NULL)
			return vector<int>();
		storage.push_back(root);
		while(storage.size() != 0){
			cout<<"----------------"<<endl;
			for(auto a: storage){
				cout<<a->val<<'\t';
			}
			cout<<endl;
			ans.push_back(storage.back()->val);
			vector<TreeNode*> temp;
			for(auto s: storage){
				if(s->left != NULL)
					temp.push_back(s->left);
				if(s->right != NULL)
					temp.push_back(s->right);
			}
			storage = temp;
		}
		return ans;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<TreeNode> vtn{0, 1, 2, 3, 4, 5, 6};
	vtn[0].left = &(vtn[1]);
	vtn[0].right = &(vtn[2]);
	vtn[1].left = &(vtn[3]);
	vtn[1].right = &(vtn[4]);
	vtn[2].left = &(vtn[5]);
	vtn[2].right = &(vtn[6]);

	auto ans = s.rightSideView(&vtn[0]);
	cout<<"ANS:==================="<<endl;
	for(auto a: ans)
		cout<<a<<'\t';
	cout<<endl;

    return 0;
}
