#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

struct Node {
	int one_side_max = 0;
	int double_side_max = 0;
};

class Solution {
private:
	map<TreeNode*, Node*> mtn;
	int cur_max = 0;

	void findMax(TreeNode* root){
		if(root == NULL)
			return;
		findMax(root -> left);
		findMax(root -> right);
		int l, r;
		l = root -> left == NULL ? 0 : mtn[root -> left]->one_side_max;
		r = root -> right == NULL ? 0 : mtn[root -> right]->one_side_max;
		Node* cur = new Node();
		if(l > 0 && r > 0){
			if(l > r){
				cur->one_side_max = root -> val + l;
			}else{
				cur->one_side_max = root -> val + r;
			}
			cur->double_side_max = root -> val + r + l;
		}else if(l > 0 && r <= 0){
			cur->one_side_max = root -> val + l;
			cur->double_side_max = cur->one_side_max;
		}else if(r > 0 && l <= 0){
			cur->one_side_max = root -> val + r;
			cur->double_side_max = cur->one_side_max;
		}else if(l <= 0 && r <= 0){
			cur->one_side_max = root -> val;
			cur->double_side_max = root -> val;
		}
		if(cur->double_side_max > cur_max){
			cur_max = cur->double_side_max;
		}
		mtn[root] = cur;
		cout<<"===================="<<endl;
		cout<<"root: "<<root ->val<<endl;
		cout<<"one side max: "<<cur->one_side_max<<endl;
		cout<<"double side max: "<<cur->double_side_max<<endl;
		cout<<"left: "<<l<<endl;
		cout<<"right: "<<r<<endl;
	}

public:
	int maxPathSum(TreeNode* root){
		if(root == NULL)
			return 0;
		cur_max = root -> val;
		findMax(root);
		for(map<TreeNode*, Node*>::iterator it = mtn.begin(); it != mtn.end(); it++){
			delete(it->second);
		}
		return cur_max;
	}
};

int main(int argc,char** argv){
	Solution s;
	TreeNode tn[5] {-10, 9, 20, 15, 7};
	tn[0].left = tn + 1;
	tn[0].right = tn + 2;
	tn[2].left = tn + 3;
	tn[2].right = tn + 4;
	int ans = s.maxPathSum(tn);
	cout<<"ans is: "<<ans<<endl;
    return 0;
}
