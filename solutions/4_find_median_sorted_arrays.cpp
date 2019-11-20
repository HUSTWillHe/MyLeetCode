#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> v,int b, int e, int target){
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
    int index = find(v, -1,size,a);
    return index;
}

int findRst(vector<int> v1, vector<int> v2, int b, int e, int target_index){
    int mid = (b + e)/2;
    int index_in_2 = findIndexInArr(v1[mid],v2);
    if(index_in_2 + mid == target_index){
        return v1[mid];
    }

    if(e - b == 1){
        if(b == -1){
            return v2[target_index];
        }else{
            return v2[target_index - mid - 1];
        }
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
    if(size1 == 0){
        int idx = size2/2;
        if(size2 %2 == 0){
            double ret = ( (double)nums2[idx]+(double)nums2[idx-1] )/2;
            return ret;
        }else{
            return nums2[idx];
        }
    }
    if(size2 == 0){
        int idx = size1/2;
        if(size1%2 == 0){
            double ret = ((double)nums1[idx]+(double)nums1[idx - 1])/2;
            return ret;
        }else{
            return nums1[idx];
        }
    }
    int sum_size = size1 + size2;
    int index = sum_size /2;
    double ret = 0;
    if(sum_size %2 == 0){
        int r1 = findRst(nums1, nums2, -1, size1, index);
        int r2 = findRst(nums1, nums2, -1, size1, index - 1);
        ret = ((double)r1 + (double)r2)/2;
    }else{
        ret = findRst(nums1, nums2, -1, size1, index);
    }
    return ret;
}

int main(){
    vector<int> v{3};
    vector<int> vv{1,2,4};
    double d = findMedianSortedArrays(v,vv);
    cout<<"d: "<<d<<endl;
    return 0;
}
