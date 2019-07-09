#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> v,int b, int e, int target){
    //cout<<"b: "<<b<<"e: "<<e<<endl;
    //cout<<"mid: "<<v[(b+e)/2]<<endl;
    if(e - b == 1){
        return e;
    }
    if(target > v[(e + b)/2]){
        return find(v,(e+b)/2,e,target);
    }else{
        return find(v,b,(e + b)/2,target);
    }
}

int findIndexInArr(int a,vector<int> v){
    int size = v.size();
    int index = find(v,-1,size,a);
    return index;
}

int findRst(vector<int> v1, vector<int> v2, int b, int e, int target_index){
    int mid = (b + e)/2;
    int index_in_2 = findIndexInArr(v1[mid],v2);
    if(e - b == 1){
        return v2[target_index - mid];
    }
    if(index_in_2 + mid == target_index){
        return v1[mid];
    }
    if(mid + index_in_2 > target_index){
        return findRst(v1,v2,b,mid,target_index);
    }else{
        return findRst(v1,v2,mid,e,target_index);
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    int sum_size = size1 + size2;
    int index = sum_size /2;
    int ret = 0;
    cout<<"index: "<<index<<endl;
    if(sum_size %2 == 0){
        int r1 = findRst(nums1, nums2, -1, size1, index);
        int r2 = findRst(nums1, nums2, -1, size1, index - 1);
        cout<<"r1: "<<r1<<" r2: "<<r2<<endl;
        ret = (r1 + r2)/2;
    }else{
        ret = findRst(nums1, nums2, -1, size1, index);
        cout<<"ret: "<<ret<<endl;
    }
    return ret;
}

int main(){
    vector<int> v{1,3,5,7,9};
    vector<int> vv{2,4,6,8};
    double d = findMedianSortedArrays(v,vv);
    cout<<"rst: "<<d<<endl;
    return 0;
}
