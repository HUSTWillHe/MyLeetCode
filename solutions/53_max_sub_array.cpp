#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums){
		int size = nums.size();
		if(size == 0)
			return 0;
		int max = nums[0];
		for(int i = 1; i < size; i++){
			if(nums[i-1] > 0){
				nums[i] = nums[i-1] + nums[i];
			}
			if(nums[i] > max)
				max = nums[i];
		}
		return max;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> v{1,2,3,-6,7,-4,-8,9};
	int max = s.maxSubArray(v);
	cout<<max<<endl;
    return 0;
}
