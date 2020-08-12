#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void print(vector<TreeNode*> vi){
	for(auto i: vi){
		cout<<i -> val<<'\t';
	}
	cout<<endl;
}

class BSTIterator {
private:
public:
	vector<TreeNode*> tree_list;
	void insert(TreeNode* root){
		if(root == NULL)
			return;
		tree_list.push_back(root);
		insert(root -> left);
	}

public:
	BSTIterator(TreeNode* root) {
		insert(root);
	}

	int next() {
		//cout<<"-------------"<<endl;
		//print(tree_list);
		if(tree_list.empty())
			return -1;
		TreeNode* tail = tree_list.back();
		tree_list.pop_back();
		insert(tail->right);
		return tail -> val;
	}

	bool hasNext() {
		return !tree_list.empty();
	}
};

int main(int argc,char** argv){
	vector<TreeNode> vtn{4, 1, 5, 0, 3, 2};
	vtn[0].left = vtn.data() + 1;
	vtn[0].right = vtn.data() + 2;
	vtn[1].left = vtn.data() + 3;
	vtn[1].right = vtn.data() + 4;
	vtn[4].left = vtn.data() + 5;
	BSTIterator s(vtn.data());
	while(s.hasNext()){
		cout<<s.next()<<endl;
	}
    return 0;
}
