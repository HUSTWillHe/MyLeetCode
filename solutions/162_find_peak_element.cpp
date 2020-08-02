#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	int search(vector<int>& nums, int beg, int end){
		cout<<"-------------------"<<endl;
		cout<<"begin: "<<beg<<"  end: "<<end<<endl;
		if(end - beg == 1 || beg == end)
			return nums[beg]> nums[end]?beg:end;
		int mid = (beg + end)/2;
		if(nums[mid] == nums[mid + 1]){
			while(nums[mid] == nums[mid + 1])
				mid += 1;
		}
		cout<<"mid: "<<mid<<endl;
		if(nums[mid] > nums[mid + 1])
			return search(nums, beg, mid);
		if(nums[mid] < nums[mid + 1])
			return search(nums, mid, end);
		else 
			return mid;
	}
public:
	int findPeakElement(vector<int>& nums){
		if(nums.size() == 0)
			return 0;
		return search(nums, 0, nums.size() - 1);
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> vi{1};
	int ans = s.findPeakElement(vi);
	cout<<"ans: "<<vi[ans]<<endl;
    return 0;
}
