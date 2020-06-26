#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}

	Node(int _val){
		val = _val;
		neighbors = vector<Node*>();
	}

	Node(int _val, vector<Node*> _neighbors){
		val = _val;
		neighbors = _neighbors;
	}
};

int printNodes(Node* node, set<Node*> &used_nodes){
	if(used_nodes.find(node) == used_nodes.end()){
		used_nodes.insert(node);
		cout<<node->val<<endl;
		cout<<"neighbors"<<endl;
		for(auto neighbor: node -> neighbors){
			cout<<neighbor -> val<<'\t';
		}
		cout<<endl;
		for(auto neighbor: node -> neighbors){
			printNodes(neighbor, used_nodes);
		}
	}
	return node -> val;
}

class Solution {
private:
	map<Node*, Node*> node_pair;
	Node* clone(Node* node){
		if(node_pair.find(node) == node_pair.end()){
			Node* cur = new Node(node -> val);
			node_pair[node] = cur;
			for(Node* neighbor: node -> neighbors){
				cur->neighbors.push_back(clone(neighbor));
			}
			return cur;
		}else{
			return node_pair[node];
		}
	}

public:
	Node* cloneGraph(Node* node){
		if(node == NULL)
			return NULL;
		return clone(node);
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<Node> vn;
	for(int i = 0; i < 5; i++){
		vn.push_back(Node(i));
	}
	for(int i = 0; i < 5; i++){
		vn[i].neighbors = vector<Node*>{&(vn[(i + 1) % 5]), &(vn[(i + 4) % 5])};
	}
	vn[0].neighbors.push_back(&(vn[3]));
	vn[3].neighbors.push_back(&(vn[0]));
	set<Node*> used_nodes{};
	cout<<"original: "<<endl;
	printNodes(vn.data(), used_nodes);
	Node* ans = s.cloneGraph(vn.data());
	cout<<"result: "<<endl;
	printNodes(ans, used_nodes);
    return 0;
}
