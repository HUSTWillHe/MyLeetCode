#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int size = nums.size();
		if(size == 0)
			return 0;
		map<int, int> nums_cnt;
		for(auto a: nums){
			if(nums_cnt.find(a) != nums_cnt.end()){
				nums_cnt[a] ++;
			}else{
				nums_cnt[a] = 1;
			}
		}
		for(auto a: nums_cnt){
			if(a.second > size/2)
				return a.first;
		}
		return nums[0];
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> nums{2,2, 1, 1, 1, 2, 2};
	int ans = s.majorityElement(nums);
	cout<<"ans: "<<ans<<endl;
    return 0;
}
