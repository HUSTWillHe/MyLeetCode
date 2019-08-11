#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int> & nums, int target){
    sort(nums.begin(), nums.end());
    int size = nums.size();
    int min_delta = -1;
    int rst_sum;
    for(int i = 0; i < size; i++){
        for(int b = i + 1, e = size -1; b < e; ){
            if(nums[i] + nums[b] + nums[e] > target){
                int delta = nums[i] + nums[b] + nums[e] - target;
                if(min_delta == -1){
                    min_delta = delta;
                    rst_sum = nums[i] + nums[b] + nums[e];
                }else{
                    if(delta < min_delta){
                        min_delta = delta;
                        rst_sum = target + delta;
                    }
                }
                e--;
            }else if(nums[i] + nums[b] + nums[e] < target){
                int delta = target - nums[i] - nums[b] - nums[e];
                if(min_delta == -1){
                    min_delta = delta;
                    rst_sum = nums[i] + nums[b] + nums[e];
                }else{
                    if(delta < min_delta){
                        min_delta = delta;
                        rst_sum = target - delta;
                    }
                }
                b++;
            }else{
                return target;
            }
        }
    }
    return rst_sum;
}

int main(int argc,char** argv){
    vector<int> v{1,1,-1};
    int i = threeSumClosest(v, 2);
    cout<<"rst: "<<i<<endl;

    return 0;
}
