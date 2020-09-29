#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if(nums.size() == 0)
			return 0;
		if(nums.size() == 1)
			return nums[0];
		int last = nums[0], last2 = 0;
		for(int i = 1; i < nums.size(); i++) {
			int cur_max = max(nums[i] + last2, last);
			last2 = last;
			last = cur_max;
		}
		return last;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> nums{2, 7, 9, 3, 1};
	int ans = s.rob(nums);
	cout<<ans<<endl;
    return 0;
}
