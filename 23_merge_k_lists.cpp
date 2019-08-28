#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool sortFunc(ListNode a, ListNode b){
    return a.val<b.val;
}

ListNode* mergeKLists(vector<ListNode*> & lists){
    ListNode* ans;
    sort(lists.begin(), lists.end(), sortFunc);
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
