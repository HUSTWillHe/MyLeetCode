#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <cstring>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printTree(TreeNode* root){
	if(root == NULL)
		return;
	cout<<"Print Tree"<<endl;
	deque<TreeNode*> dt{root};
	while(dt.size() > 0){
		int size = dt.size();
		for(auto a: dt){
			if(a != NULL){
				string left = a -> left == NULL ? "NULL" : to_string(a -> left -> val);
				string right = a -> right == NULL ? "NULL" : to_string(a -> right -> val);
				cout<<"value: "<<a->val<<'\t'<<"left: "<<left<<'\t'<<"right: "<<right<<endl;
			}
			else
				cout<<"NULL"<<'\t'<<endl;
		}
		for(int i = 0; i < size; i++){
			if(dt[i] != NULL){
				dt.push_back(dt[i] -> left);
				dt.push_back(dt[i] -> right);
			}
		}
		for(int i = 0; i < size; i++){
			dt.pop_front();
		}
	}
}

class Solution {
//private:
public:
	vector<vector<TreeNode*>> dp;
	TreeNode* cloneTree(const TreeNode* root, int increase){
		if(root == NULL)
			return NULL;
		TreeNode* newRoot = new TreeNode(0);
		newRoot -> left = cloneTree(root->left, increase);
		newRoot -> val = root -> val + increase;
		newRoot -> right = cloneTree(root->right, increase);
		return newRoot;
	}

public:
	vector<TreeNode*> generateTrees(int n) {
		if(n <= 0)
			return vector<TreeNode*>();
		TreeNode* first = new TreeNode(1);
		vector<TreeNode*> vfirst{first};
		vector<TreeNode*> vhead;
		dp.push_back(vhead);
		dp.push_back(vfirst);
		if(n == 1)
			return dp[1];
		for(int i = 2; i <= n; i++){
			dp.push_back(vector<TreeNode*>());
			for(int k = 0; k < i; k++){
				if(k == 0){
					for(auto right: dp[i-1]){
						TreeNode* root = new TreeNode(1);
						root -> right = cloneTree(right, 1);
						dp[i].push_back(root);
					}
				}else if(k == i-1){
					for(auto left: dp[i - 1]){
						TreeNode* root = new TreeNode(i);
						root -> left = cloneTree(left, 0);
						dp[i].push_back(root);
					}
				}else{
					for(auto left: dp[k]){
						for(auto right: dp[i - k - 1]){
							TreeNode* root = new TreeNode(k + 1);
							root -> left = cloneTree(left, 0);
							root -> right = cloneTree(right, k + 1);
							dp[i].push_back(root);
						}
					}
				}
			}
//			cout<<"round: "<<i<<" ================="<<endl;
//			cout<<"size of dp"<<i<<": "<<dp[i].size()<<endl;
//			for(auto a: dp[i]){
//				cout<<"inner round: ----------------"<<endl;
//				printTree(a);
//			}
		}
		return dp[n];
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<TreeNode*> ans = s.generateTrees(stoi(argv[1]));
    return 0;
}
