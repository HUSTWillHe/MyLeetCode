#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int> &nums){
		for(int i = 1; i < nums.size(); i++){
			nums[0] ^= nums[i];
		}
		return nums[0];
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> vi{2, 2, 1};
	int ans = s.singleNumber(vi);
	cout<<"ans: "<<ans<<endl;
    return 0;
}
