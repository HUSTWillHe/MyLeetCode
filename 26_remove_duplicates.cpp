#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int removeDuplicates(vector<int>& nums){
    int size = nums.size();
    for(int i = size - 1; i > 0; i--){
        if(nums[i] == nums[i-1]){ nums.erase(nums.begin()+i); }
    }
    return nums.size();
}

int main(int argc,char** argv){
    vector<int> v{1,1,1,1,2,2,2,3,3,3,4,5,6,7,7,8};
    int i = removeDuplicates(v);
    cout<<i<<endl;
    return 0;
}
