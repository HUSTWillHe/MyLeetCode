#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int begin, int end){
		if(end - begin == 1 || end == begin)
			return min(nums[begin], nums[end]);
		int mid = (begin + end)/2;
		if(nums[mid] > nums[begin]){
			return search(nums, mid, end);
		}else if(nums[mid] < nums[end]){
			return search(nums, begin, mid);
		}
		return 0;
	}

	int findMin(vector<int>& nums){
		if(nums.size() == 0)
			return 0;
		int size = nums.size();
		if(nums[0] < nums[size - 1])
			return nums[0];
		return search(nums, 0, size - 1);
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> vi{2};
	int ans = s.findMin(vi);
	cout<<"ans : "<<ans<<endl;
    return 0;
}
