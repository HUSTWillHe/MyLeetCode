#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    bool over = false;
    ListNode* ans = new ListNode(0);
    ListNode* bgn = ans;
    ListNode* last;
    int cnt = 0;
    while(1){
        cnt++;
        if(l1 != NULL && l2 != NULL){
            int sum = l1->val + l2 -> val + int(over);
            if (sum > 9){
                sum -= 10;
                over = true;
            }else{
                over = false;
            }
            cout<<"cnt: "<<cnt<<"\ttype: "<<1<<"\tsum: "<<sum<<endl;
            ans -> val = sum;
            ListNode* n = new ListNode(0);
            ans -> next = n;
            last = ans;
            ans = n;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }else if(l1 == NULL && l2 == NULL){
            if(over){
                ans -> val = 1;
            }else{
                last -> next = NULL;
                delete(ans);
                over = false;
            }
            cout<<"cnt: "<<cnt<<"\ttype: "<<3<<endl;
            break;
        }else{
            int val = 0;
            if (l1 == NULL){
                val = l2 -> val;
            }else{
                val = l1 -> val;
            }

            int sum = val + int(over);
            if(sum > 9){
                sum -= 10;
                over = true;
            }else{
                over = false;
            }
            ans -> val = sum;
            ListNode *n = new ListNode(0);
            ans -> next = n;
            last = ans;
            ans = n;
            cout<<"cnt: "<<cnt<<"\ttype: "<<2<<"\tsum: "<<sum<<endl;
            if(l1 == NULL){
                l2 = l2 -> next;
            }else{
                l1  = l1 -> next;
            }
        }
    }
    return bgn;
}

int main(){
    ListNode *l1 = new ListNode(4);
    l1 -> next = new ListNode(8);
    l1 -> next -> next = new ListNode(5);
    ListNode *l2 = new ListNode(7);
    l2 -> next = new ListNode(2);
    ListNode *ans = addTwoNumbers(l1, l2);
    cout<<"========================="<<endl;
    while(ans != NULL){
        cout<<ans->val<<endl;
        ans = ans ->next;
    }
}
