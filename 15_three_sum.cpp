#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums){
    vector<vector<int>> vv;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for(int i = 0; i<nums.size();i++){
        int a = i+1;
        int b = size -1;
        while(b > a){
            if(nums[a] + nums[b] > -nums[i]){
                b--;
            }else if(nums[a] + nums[b] < -nums[i]){
                a++;
            }else{
                vv.push_back({nums[i], nums[a], nums[b]});
                b--;
            }
        }
    }
    vv.erase(unique(vv.begin(), vv.end()), vv.end());
    return vv;
}

int main(int argc,char** argv){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> vv = threeSum(nums);
    for(auto v: vv){
        for(auto a: v){
            cout<<a<<endl;
        }
        cout<<"\n\n"<<endl;
    }
    return 0;
}
