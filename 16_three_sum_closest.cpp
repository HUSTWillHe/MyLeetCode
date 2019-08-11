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
        cout<<"circle index: "<<i<<"===================================== "<<endl;
        for(int b = i + 1, e = size -1; b < e; ){
            cout<<"begin index: "<<b<<" end index: "<<e<<endl;
            if(nums[i] + nums[b] + nums[e] > target){
                int delta = nums[i] + nums[b] + nums[e] - target;
                if(min_delta == -1){
                    min_delta = delta;
                    rst_sum = target + delta;
                }else{
                    if(delta < min_delta){
                        min_delta = delta;
                        rst_sum = target + delta;
                        cout<<"find smaller large: "<<"begin idx: "<<b<<" end idx: "<<e<<endl;
                        cout<<"large is: "<<rst_sum<<endl;
                    }
                }
                e--;
            }else if(nums[i] + nums[b] + nums[e] < target){
                int delta = target - nums[i] + nums[b] + nums[e];
                if(min_delta == -1){
                    min_delta = delta;
                    rst_sum = target - delta;
                }else{
                    if(delta < min_delta){
                        min_delta = delta;
                        rst_sum = target - delta;
                        cout<<"find smaller less: "<<"begin idx: "<<b<<" end idx: "<<e<<endl;
                        cout<<"less is: "<<rst_sum<<endl;
                    }
                }
                b++;
            }else{
                cout<<"find smaller equal: "<<"begin idx: "<<b<<" end idx: "<<e<<endl;
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
