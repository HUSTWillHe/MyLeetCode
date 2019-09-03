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

bool fillVec(vector<ListNode*>& vl, ListNode* l){
    int size = vl.size();
    for(int i = 0; i < size; i++){
        if(l!=NULL){
            vl[i] = l;
        }else{
            return false;
        }
        l = l->next;
    }
    for(auto a: vl){
        cout<<a->val<<" -> ";
    }
    cout<<endl;
    cout<<"fillVec end"<<endl;
    return true;
}

ListNode* reverseKGroup(ListNode* head, int k){
    if(k <= 1) return head;
    if(head == NULL) return NULL;
    vector<ListNode*> vl(k);
    cout<<"size: "<<vl.size()<<endl;
    ListNode* left = head;
    ListNode* last_left = NULL;
    ListNode* ans;
    if(fillVec(vl, left)) ans = vl[k-1];
    else ans = head;
    while(fillVec(vl, left)){
        ListNode* next_left = vl[k-1]->next;
        if(last_left != NULL)
            last_left->next = vl[k-1];
        for(int i = 1; i< k;i++){
            vl[i]->next = vl[i-1];
        }
        vl[0]->next = next_left;
        last_left = left;
        left = next_left;
    }
    return ans;
}

int main(int argc,char** argv){
    ListNode* l[12];
    for(int i = 11; i>=0; i--){
        l[i] = new ListNode(i);
        if(i != 11){
            l[i]->next = l[i+1];
        }
    }

/*    cout<<"2-----------------"<<endl;*/
    //ListNode* ans = reverseKGroup(l[0], 2);
    //while(ans!=NULL){
        //cout<<ans->val<<" -> ";
        //ans = ans->next;
    //}
    //cout<<endl;

    cout<<"3-----------------"<<endl;
    ListNode* ans = reverseKGroup(l[0], 3);
    while(ans!=NULL){
        cout<<ans->val<<" -> ";
        ans = ans->next;
    }
    cout<<endl;

/*    cout<<"4-----------------"<<endl;*/
    //ans = reverseKGroup(l[0], 4);
    //while(ans!=NULL){
        //cout<<ans->val<<" -> ";
        //ans = ans->next;
    //}
    /*cout<<endl;*/
    return 0;
}
