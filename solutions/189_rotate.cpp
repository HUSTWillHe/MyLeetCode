#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if(nums.size() < 2 || k == 0 || k == nums.size())
			return;
		int cur_idx = 0, next_idx, size = nums.size(), cur_head = 0, last = nums[0];
		for(int i = 0; i < size; i++) {
			next_idx = (cur_idx + k) % size;
			int temp = nums[next_idx];
			nums[next_idx] = last;
			last = temp;
			cur_idx = next_idx;
			if(cur_idx == cur_head){
				cur_idx ++;
				cur_head ++;
				last = nums[cur_idx];
			}
			
		}
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> v{-1, -100, 3, 99};
	s.rotate(v, 2);
	for(auto a: v) {
		cout<<a<<endl;
	}
    return 0;
}
