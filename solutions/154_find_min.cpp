#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int cntEqual(vector<int>& nums, bool reverse = false){
		if(!reverse){
			for(int i = 1; i < nums.size(); i++){
				if(nums[i] != nums[0])
					return i - 1;
			}
			return nums.size() - 1;
		}else{
			for(int i = nums.size() - 2; i >= 0; i--){
				if(nums[i] != nums[nums.size() - 1])
					return i + 1;
			}
			return 0;
		}
		return 0;
	}
	
	int search(vector<int>& nums, int begin, int end){
		if(end - begin == 1)
			return min(nums[begin], nums[end]);
		int mid = (begin + end)/ 2;
		if(nums[mid] >= nums[begin])
			return search(nums, mid, end);
		if(nums[mid] <= nums[end])
			return search(nums, begin, mid);
		return 0;
	}

	int findMin(vector<int>& nums){
		int size = nums.size();
		if(size == 0)
			return 0;
		if(size == 1 || nums[0] < nums[size - 1])
			return nums[0];
		int begin = 0, end = size - 1;
		if(nums[0] == nums[size - 1]){
			begin = cntEqual(nums);
			end = cntEqual(nums, true);
		}
		if(begin > end)
			return nums[0];
		return search(nums, begin, end);
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> vi{1, 1};
	int ans = s.findMin(vi);
	cout<<"ans: "<<ans<<endl;
    return 0;
}
