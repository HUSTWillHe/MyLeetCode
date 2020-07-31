# include <iostream>
# include <deque>
using namespace std;

struct Node{
	int val;
	Node* next;
	Node* prev;
	Node(int x): val(x), next(NULL), prev(NULL) {}
	Node(): val(0), next(NULL), prev(NULL) {}
};

class MinStack {
private:
	const int MIN_INT = 0x7FFFFFFF;
	void insertNode(Node* node){
		if(head == NULL){
			head = node;
			return;
		}
		Node* cur = head;
		Node* last = NULL;
		while(cur != NULL && node -> val > cur -> val){
			last = cur;
			cur = cur -> next;
		}
		if(last == NULL){
			node -> next = cur;
			cur -> prev = node;
			head = node;
		}else if(cur == NULL){
			last -> next = node;
			node -> prev = last;
		}else{
			last -> next = node;
			node -> prev = last;
			node -> next = cur;
			cur -> prev = node;
		}
	}
	
	void deleteNode(Node* node){
		if(node == head){
			head = node -> next;
			if(head != NULL){
				head -> prev = NULL;
			}
		}else if(node -> next == NULL){
			Node* prev = node -> prev;
			prev -> next = NULL;
		}else{
			Node* prev = node -> prev;
			Node* next = node -> next;
			prev -> next = next;
			next -> prev = prev;
		}
		delete(node);
	}
	
public:
	deque<Node*> dn;
	Node* head;
	int min = MIN_INT;
	MinStack() {
		head = NULL;
	}
	
	void push(int x){
		Node* cur = new Node(x);
		dn.push_back(cur);
		insertNode(cur);
	}

	void pop() {
		Node* cur = dn.back();
		dn.pop_back();
		deleteNode(cur);
	}

	int top() {
		return dn.back() -> val;
	}

	int getMin() {
		if(head == NULL){
			return min;
		}else{
			return head -> val;
		}	
	}
};

int main(){
	MinStack ms;
	ms.push(3);
	ms.push(5);
	ms.push(1);
	cout << ms.top() << endl;
	ms.pop();
	cout<<ms.getMin()<<endl;
	ms.pop();
	cout<<ms.getMin()<<endl;
	ms.pop();
	ms.push(10);
	cout << ms.top() << endl;
	cout<<ms.getMin()<<endl;
	ms.push(4);
	cout << ms.top() << endl;
	cout<<ms.getMin()<<endl;
	ms.pop();
	cout<<ms.getMin()<<endl;

	return 0;
}
