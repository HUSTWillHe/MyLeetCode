#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int> &cost){
		int size = gas.size();
		if(size == 0){
			return 0;
		}
		int sum = 0;
		int accumulate = 0;
		int start_idx = 0;
		for(int i = 0; i < size; i++){
			int cur = gas[i] - cost[i];
			accumulate += cur;
			if(accumulate < 0){
				accumulate = 0;
				start_idx = i + 1;
			}
			sum += cur;
		}
		if(sum < 0)
			return -1;
		return start_idx;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> gas{1, 2, 3, 4, 5};
	vector<int> cost{3, 4, 5, 1, 2};
	int ans = s.canCompleteCircuit(gas, cost);
	cout<<"ans is: "<<ans<<endl;
    return 0;
}
