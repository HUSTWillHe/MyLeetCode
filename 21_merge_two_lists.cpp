#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    ListNode * head;
    if(l1->val < l2->val){
        head = l1;
        l1 = l1 -> next;
    }else{
        head = l2;
        l2 = l2 -> next;
    }
    ListNode* current = head;
    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2 -> val){
            current -> next = l1;
            current = l1;
            l1 = l1 -> next;
        }else{
            current -> next = l2;
            current = l2;
            l2 = l2 -> next;
        }
    }
    if(l1 == NULL){
        current ->next = l2;
    }else{
        current -> next = l1;
    }
    return head;
}

int main(int argc,char** argv){
    ListNode* l1[6];
    ListNode* l2[6];
    for(int i = sizeof(l1)/sizeof(l1[0]) - 1; i>=0; i--){
        l1[i] = new ListNode(3*i*i);
        if(i != sizeof(l1)/sizeof(l1[0]) - 1){
            l1[i]->next = l1[i+1];
        }
    }
    for(int i = sizeof(l2)/sizeof(l2[0]) - 1; i>=0; i--){
        l2[i] = new ListNode(i + 10);
        if(i != sizeof(l2)/sizeof(l2[0]) - 1){
            l2[i]->next = l2[i+1];
        }
    }
    ListNode* l = mergeTwoLists(l1[0], l2[0]);
    while(l!= NULL){
        cout<<l->val<<" -> ";
        l = l->next;
    }
    cout<<endl;
    return 0;
}
