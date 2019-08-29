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

bool sortFunc(const ListNode* a, const ListNode* b){
    return a->val<b->val;
}

int insertIndex(int target, deque<ListNode*> d, int begin, int end){
    if(end == begin + 1) return begin;
    int mid = (begin + end)/2;
    if(target > d.at(mid)->val){
        return insertIndex(target,d,mid,end);
    }else if(target < d.at(mid)->val){
        return insertIndex(target,d,begin,mid);
    }else{
        return mid;
    }
}

void insertListNode(const ListNode* l, deque<ListNode*>& d){
    int size = d.size();
    int idx = insertIndex(l->val, d, 0, size -1);
    d.insert(d.begin() + idx, l);
}

ListNode* mergeKLists(vector<ListNode*> & lists){
    ListNode* ans;
    sort(lists.begin(), lists.end(), sortFunc);
    deque<ListNode*> d(lists.begin(), lists.end());
    ans = d[0];
    ListNode* currentNode = ans;
    while(1){
        d.pop_front();
    }
}

int main(int argc,char** argv){
    ListNode* ln[5];
    for(int i = 4; i >=0;i--){
        ln[i] = new ListNode(i);
        if(i != 4){
            ln[i]->next = ln[i+1];
        }
    }

    return 0;
}
