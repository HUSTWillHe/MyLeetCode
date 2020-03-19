#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root){
		if(root == NULL)
			return vector<vector<int>>();
		vector<vector<int>> vvi;
		deque<TreeNode*> dt{root};
		bool isRight = false;
		while(!dt.empty()){
			int size = dt.size();
			vector<int> vi;
			for(auto a: dt){
				vi.push_back(a->val);
			}
			for(auto a: dt){
				if(a -> left != NULL)
					dt.push_back(a -> left);
				if(a -> right != NULL)
					dt.push_back(a -> right);
			}
			if(isRight)
				reverse(vi.begin(), vi.end());
			isRight = !isRight;
			vvi.push_back(vi);
			for(int i = 0; i < size; i++)
				dt.pop_front();
		}
		return vvi;
	}
};

int main(int argc,char** argv){
	Solution s;
	TreeNode tn[7]{1, 2, 3, 4, 5, 6, 7};
	tn[0].left = &(tn[1]);
	tn[0].right = &(tn[2]);
	tn[1].left = &(tn[3]);
	tn[1].right = &(tn[4]);
	tn[2].left = &(tn[5]);
	tn[2].right = &(tn[6]);
	vector<vector<int>> ans = s.zigzagLevelOrder(tn);
	for(auto vi: ans){
		for(auto a: vi){
			cout<<a<<'\t';
		}
		cout<<endl;
	}
    return 0;
}
