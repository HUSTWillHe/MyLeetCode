#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> findLeftBoundary(const vector<int>& nums){
		vector<int> leftBoundary;
		for(int i = 0; i < nums.size(); i++){
			if((i-1 == -1 || nums[i-1] <= 0) && nums[i] > 0){
				leftBoundary.push_back(i);
			}
		}
		return leftBoundary;
	}

	vector<int> findRightBoundary(vector<int> nums){
		reverse(nums.begin(), nums.end());
		vector<int> reverse_boundary = findLeftBoundary(nums);
		int size = nums.size();
		for(int i = 0; i < reverse_boundary.size(); i++){
			reverse_boundary[i] = size - 1 - reverse_boundary[i];
		}
		return reverse_boundary;
	}

	bool isAllNegative(const vector<int>& nums){
		for(auto a: nums)
			if(a > 0)
				return false;
		return true;
	}

	int findMaxIndividual(vector<int>& nums){
		if(isAllNegative(nums)){
			cout<<"all negative"<<endl;
			vector<int>::iterator max_it = max_element(nums.begin(), nums.end());
			return *max_it;
		}
		int local_sum = 0;
		int max = 0;
		for(int i = 0; i < nums.size(); i++){
			if(nums[i] <= 0){
				if(i > 0 && nums[i-1] > 0){
					if(local_sum > max){
						max = local_sum;
						local_sum = 0;
					}
				}else{
					continue;
				}
			}else{
				local_sum += nums[i];
				cout<<"======================"<<endl;
				cout<<"current value: "<<nums[i]<<"  local_sum: "<<local_sum<<endl;
			}
		}
		return max;
	}
	
	int range_sum(const vector<int>& nums, int left, int right){
		int sum = 0;
		for(int i = left; i <= right; i++){
			sum += nums[i];
		}
		return sum;
	}

	int maxSubArray(vector<int>& nums){
		if(nums.size() == 0)
			return 0;
		vector<int> leftBoundary = findLeftBoundary(nums);
		vector<int> rightBoundary = findRightBoundary(nums);
		if(leftBoundary.size() == 0 || rightBoundary.size() == 0){
			return findMaxIndividual(nums);
		}else{
			int max_sum = 0;
			for(auto l: leftBoundary){
				for(auto r: rightBoundary){
					if(r >= l){
						int cur_sum = range_sum(nums, l, r);
						if(cur_sum > max_sum){
							max_sum = cur_sum;
						};
					}
				}
			}
			return max_sum;
		}
	}
};

void test_find_max(vector<int>& nums){
	Solution s;
	int result = s.findMaxIndividual(nums);
	cout<<"the max is: "<<result<<endl;
}

void test_findLeftBoundary(const vector<int>& nums){
	Solution s;
	vector<int> left = s.findLeftBoundary(nums);
	cout<<"left boundary"<<endl;
	for(auto a: left){
		cout<<a<<'\t';
	}
	cout<<endl;
}

void test_findRightBoundary(const vector<int>& nums){
	Solution s;
	vector<int> rightBoundary = s.findRightBoundary(nums);
	cout<<"right boundary: "<<endl;
	for(auto a: rightBoundary){
		cout<<a<<'\t';
	}
	cout<<endl;
}

int main(int argc,char** argv){
	Solution s;
	vector<int> v{0, 2, 0, 2};
	//test_find_max(v);
	test_findRightBoundary(v);
	test_findLeftBoundary(v);
	s.maxSubArray(v);
    return 0;
}
