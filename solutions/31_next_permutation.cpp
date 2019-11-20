#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> & nums){
    int size = nums.size();
    if(size == 0 || size == 1) return;
    int pnt;
    for(int i = size - 2; i >= 0; i--){
        if(nums[i] >= nums[i + 1]){
            if(i == 0) pnt = -1;
            continue;
        }
        else{
            pnt = i;
            break;
        }
    }
    cout<<"pnt is: "<<pnt<<endl;
    if(pnt != -1){
        for(int i = size -1; i >= pnt + 1; i--){
                if(nums[i] > nums[pnt]){
                    int tmp = nums[i];
                    nums[i] = nums[pnt];
                    nums[pnt] = tmp;
                    break;
                }else
                    continue;
            }
    }

    cout<<"after swap pnt and larger: "<<endl;
    for(auto a: nums){
        cout<<a<<endl;
    }
    for(int i = pnt + 1, j = size -1; i < j; i++,j--){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    cout<<"finished "<<endl;
    for(auto a:nums){
        cout<<a<<endl;
    }
}

int main(int argc,char** argv){
    vector<int> v1{3, 2, 1};
    nextPermutation(v1);
    for(auto a: v1){
        cout<<a<<endl;
    }
    return 0;
}
