# include <iostream>
# include <map>

using namespace std;

class Node{
	public:
	int key, val;
	Node* next;
	Node* previous;
	Node(int k, int v): key(k), val(v), next(NULL), previous(NULL) {}
};

void printMap(map<int, Node*> m);
void printNodes(Node* head, bool);

class LRUCache{
	public:
	map<int, Node*> storage;
	int capacity = 0;
	int count = 0;
	Node* head = NULL;
	Node* tail = NULL;

	LRUCache(int capacity){
		this -> capacity = capacity;
	}
	
	Node* switchHead(Node* cur, Node* head){
		if(head == cur || cur == NULL || head == NULL)
			return head;
		Node* next = cur -> next;
		Node* pre = cur -> previous;
		pre -> next = next;
		if(next != NULL){
			next -> previous = pre;
		}else{
			tail = pre;
		}
		cur -> next = head;
		head -> previous = cur;
		cur -> previous = NULL;
		return cur;
	}

	int get(int key){
		if(storage.find(key) == storage.end()){
			return -1;
		}else{
			head = switchHead(storage[key], head);
			return storage[key] -> val;
		}
	}
	void put(int key, int value){
		if(storage.find(key) == storage.end()){
			if(count == capacity){
				storage.erase(tail -> key);
				Node* pre = tail -> previous;
				if(pre == NULL){
					head = NULL;
					tail = NULL;
				}else{
					pre -> next = NULL;
				}
				delete(tail);
				tail = pre;
			}else{
				count ++;
			}
			if(head == NULL){
				head = new Node(key, value);
				tail = head;
				storage[key] = head;
			}else{
				Node* node = new Node(key, value);
				node -> next = head;
				head -> previous = node;
				head = node;
				storage[key] = node;
			}
		}else{
			storage[key] -> val = value;
			head = switchHead(storage[key], head);
		}
		printMap(storage);
		printNodes(head, false);
		printNodes(tail, true);
	}
};

void printMap(map<int, Node*> m){
	cout<<"==="<<endl;
	for(auto mm: m){
		cout<<mm.second -> key<<" : "<<mm.second -> val<<endl;
	}
}

void printNodes(Node* head, bool reverse){
	cout<<"xxx"<<endl;
	Node* cur = head;
	while(cur!= NULL){
		cout<<cur -> key<<" -> ";
		if(reverse){
			cur = cur -> previous;
		}else{
			cur = cur -> next;
		}
	}
	cout<<endl;
}

int main(){
	LRUCache lru = LRUCache(1);
	lru.put(2, 1);
	lru.get(2);
	lru.put(3, 2);
	lru.get(2);
	lru.get(3);
	return 0;
}
