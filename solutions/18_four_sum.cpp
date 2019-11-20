#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > twoSum(vector<int> nums, int target, int bgn_idx)
{
    cout<<"small circle----------------------------"<<endl;
    cout<<"target: "<<target<<"bgn_idx: "<<bgn_idx<<endl;
    vector< vector<int> > vvi;
    int size = nums.size();
    for(int i = bgn_idx, k = size - 1; i < k; ){
        cout<<"begin: "<<i<<" end: "<<k<<endl;
        int sum = nums[i] + nums[k];
        cout<<"sum: "<<sum<<endl;
        if(sum > target){
            k--;
        }else if(sum < target){
            i++;
        }else{
            vector<int> v;
            v.push_back(nums[i]);
            v.push_back(nums[k]);
            vvi.push_back(v);
            i++;
        }
    }
    return vvi;
}

vector<vector<int> > fourSum(vector<int>& nums, int target){
    vector<vector<int> > vvi;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for(int i = 0; i < size - 3; i++){
        for(int k = i + 1; k < size - 2; k++){
            cout<<"circle============================"<<endl;
            cout<<"1: "<<i<<" 2: "<<k<<endl;
            int sum = nums[i] + nums[k];
            cout<<"sum: "<<sum<<" target: "<<target - sum<<endl;
            vector< vector<int> > inner_vvi = twoSum(nums, target - sum, k + 1);
            cout<<"size: "<<inner_vvi.size()<<endl;
            if(inner_vvi.size() > 0){
                for(auto a : inner_vvi){
                    cout<<"two sum: "<<a[0]<<", "<<a[1]<<endl;
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[k]);
                    v.insert(v.end(), a.begin(), a.end());
                    cout<<"one result::::::"<<endl;
                    for(auto b: v)
                        cout<<b<<"\t";
                    cout<<endl;
                    vvi.push_back(v);
                }
            }
        }
    }
    vector<vector<int> >::iterator iter = unique(vvi.begin(), vvi.end());
    vvi.erase(iter, vvi.end());
    return vvi;
}

int main(int argc,char** argv){
    vector<int> nums = {-5, -4, -3, -2, -1, 0, 0, 1, 2, 3, 4, 5};
    vector<vector<int> > vvi = fourSum(nums, 0);
    for( auto a : vvi ){
        for( auto b: a ){
            cout<<b<<'\t';
        }
        cout<<endl;
    }
    return 0;
}
