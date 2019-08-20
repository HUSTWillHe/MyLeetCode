#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* removeNthFromEnd(ListNode* head, int n){
    if(head == NULL) return NULL;
    ListNode* right = head;
    for(int i = 0; i < n; i++){
        right = right-> next;
        if(right == NULL){
            if(i == n - 1){
                cout<<"end null"<<endl;
                return head->next;
            }
            cout<<"null"<<endl;
            return head;
        }
    }
    cout<<"right index: "<<right->val<<endl;
    ListNode* left = head;
    while(right -> next != NULL){
        right = right->next;
        left = left->next;
    }
    cout<<"end index: "<<right->val<<endl;
    cout<<"to be del: "<<left->next->val<<endl;
    left->next = left->next->next;
    return head;
}

void printLN(ListNode* head){
    while(head != NULL){
        cout<<head->val<<" -> ";
        head = head -> next;
    }
    cout<<endl;
}

int main(int argc,char** argv){
    ListNode* ln[5];
    for(int i = 4; i >= 0; i--){
        ln[i] = new ListNode(i);
        if(i != 4)
            ln[i]->next = ln[i+1];
    }
    printLN(ln[0]);
    ListNode* head =  removeNthFromEnd(ln[0], 4);
    printLN(head);
    return 0;
}
