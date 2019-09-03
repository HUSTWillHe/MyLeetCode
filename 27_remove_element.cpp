#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int removeElement(vector<int>&nums, int val){
    int size = nums.size();
    for(int i = size -1; i>=0;i--){
        if(nums[i]==val)
            nums.erase(nums.begin()+i);
    }
    return nums.size();
}

int main(int argc,char** argv){

    return 0;
}
