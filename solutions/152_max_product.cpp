#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if(nums.size() == 0)
			return 0;
		int size = nums.size();
		int max_multiply = nums[0];
		int last_min = nums[0];
		int last_max = nums[0];
		for(int i = 1; i < size; i++){
			int cur_max, cur_min;
			if(nums[i] == 0){
				cur_max = 0;
				cur_min = 0;
			}else if(nums[i] > 0){
				cur_max = max(nums[i], last_max * nums[i]);
				cur_min = min(nums[i], last_min * nums[i]);
			}else{
				cur_max = max(nums[i], last_min * nums[i]);
				cur_min = min(nums[i], last_max * nums[i]);
			}
			if(cur_max > max_multiply)
				max_multiply = cur_max;
			last_max = cur_max;
			last_min = cur_min;
		}
		return max_multiply;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> vi{2, 3, -2, 4};
	int ans = s.maxProduct(vi);
	cout<<"ans: "<<ans<<endl;
    return 0;
}
