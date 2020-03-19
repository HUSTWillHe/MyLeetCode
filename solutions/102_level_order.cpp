#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root){
		if(root == NULL)
			return vector<vector<int>>();
		vector<vector<int>> vvi;
		deque<TreeNode*> dt;
		dt.push_back(root);
		while(!dt.empty()){
			vector<int> vi;
			for(auto a: dt)
				vi.push_back(a -> val);
			int size = dt.size();
			for(auto a: dt){
				if(a -> left != NULL)
					dt.push_back(a -> left);
				if(a -> right != NULL)
					dt.push_back(a -> right);
			}
			for(int i = 0; i < size; i++)
				dt.pop_front();
			vvi.push_back(vi);
		}
		return vvi;
	}
};

int main(int argc,char** argv){
	Solution s;
	TreeNode tn[5]{1,2,3,4,5};
	tn[0].left = &(tn[1]);
	tn[0].right = &(tn[2]);
	tn[1].left = &(tn[3]);
	tn[2].left = &(tn[4]);
	vector<vector<int>> ans = s.levelOrder(tn);
	cout<<"ans: "<<endl;
	for(auto vi: ans){
		for(auto a: vi){
			cout<<a<<'\t';
		}
		cout<<endl;
	}

    return 0;
}
