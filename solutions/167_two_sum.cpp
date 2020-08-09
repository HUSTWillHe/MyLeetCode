#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& sum, int target) {
		int size = sum.size();
		if(size == 0)
			return vector<int>();
		int begin = 0, end = size -1;
		while(begin < end){
			if(sum[begin] + sum[end] > target){
				end --;
			}else if(sum[begin] + sum[end] < target){
				begin ++;
			}else{
				return vector<int>{begin + 1, end + 1};
			}
		}
		return vector<int>();
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> sum{2, 7, 11, 15};
	int target = 9;
	vector<int> ans = s.twoSum(sum, target);
	for(auto a: ans)
		cout<<a<<endl;
    return 0;
}
