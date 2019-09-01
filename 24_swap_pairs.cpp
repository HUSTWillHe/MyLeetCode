#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* swapPairs(ListNode* head){
    if(head == NULL) return NULL;
    if(head -> next == NULL) return head;
    ListNode* left = head;
    ListNode* ans = head->next;
    ListNode* last_left = NULL;
    while(left!=NULL && left->next != NULL){
        ListNode* right = left->next;
        ListNode* next_left = right->next;
        if(last_left != NULL)
            last_left->next = right;
        right->next = left;
        left->next = next_left;
        last_left = left;
        left = next_left;
    }
    return ans;
}

int main(int argc,char** argv){
    ListNode* l[9];
    for(int i = 8; i>=0; i--){
        l[i] = new ListNode(i);
        if(i != 8) l[i]->next = l[i+1];
    }
    ListNode* ans = swapPairs(l[0]);
    while(ans != NULL){
        cout<<ans->val<<" -> ";
        ans = ans->next;
    }
    cout<<endl;
    return 0;
}
