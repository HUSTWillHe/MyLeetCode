#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

static bool sortFunc(const ListNode* a, const ListNode* b){
    return a->val<b->val;
}

int insertIndex(int target, deque<ListNode*> d, int begin, int end){
    if(d.size() == 0) return 0;
    if(target < d[0] -> val) return 0;
    if(target > d[d.size() - 1] -> val) return end + 1;
    if(end == begin + 1) return end;
    int mid = (begin + end)/2;
    if(target > d.at(mid)->val){
        return insertIndex(target,d,mid,end);
    }else if(target < d.at(mid)->val){
        return insertIndex(target,d,begin,mid);
    }else{
        return mid;
    }
}

ListNode* mergeKLists(vector<ListNode*> & lists){
    for(int i = lists.size()-1; i >= 0; i--){
        if(lists[i] == NULL) lists.erase(lists.begin()+i);
    }
    if(lists.size() == 0) return NULL;
    ListNode* ans;
    sort(lists.begin(), lists.end(), sortFunc);
    deque<ListNode*> d(lists.begin(), lists.end());
    ans = d[0];
    for(auto a: d){
        cout<<a->val<<endl;
    }
    ListNode* currentNode;
    while(d.size() != 0){
        currentNode = d[0];
        cout<<"circle:----------------"<<endl;
        cout<<"current d[0]"<<endl;
        cout<<d[0]->val<<endl;
        d.pop_front();
        if(currentNode->next != NULL){
            int i = insertIndex(currentNode->next->val, d, 0, d.size()-1);
            cout<<"next val: "<<currentNode->next->val<<endl;
            cout<<"insert index: "<<i<<endl;
            d.insert(d.begin()+i, currentNode->next);
        }
        if(d.size() == 0) break;
        currentNode->next = d[0];
    }
    return ans;
}

int main(int argc,char** argv){
    ListNode* ln[5];
    for(int i = 4; i >=0;i--){
        ln[i] = new ListNode(i * 5);
        if(i != 4){
            ln[i]->next = ln[i+1];
        }
    }

    ListNode* ln1[6];
    for(int i = 5; i >=0; i--){
        ln1[i] = new ListNode( i * i );
        if(i != 5){
            ln1[i]->next = ln1[i+1];
        }
    }

    ListNode* ln2[7];
    for(int i = 6; i >= 0; i--){
        ln2[i] = new ListNode( int(i * i * i / 4) );
        if(i != 6){
            ln2[i]->next = ln2[i+1];
        }
    }

    vector<ListNode*> v = {ln2[0], ln1[0], ln[0]};
    ListNode *ans = mergeKLists(v);

    while(ans != NULL){
        cout<<ans->val<<" -> ";
        ans = ans->next;
    }
    cout<<endl;
    return 0;
}
