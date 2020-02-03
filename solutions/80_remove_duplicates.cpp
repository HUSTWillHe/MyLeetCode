#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums){
		int size = nums.size();
		if(size == 0)
			return 0;
		int repeat = 1;
		int move = 0;
		for(int i = 1; i < size; i++){
			if(nums[i] == nums[i - 1]){
				repeat++;
				if(repeat > 2)
					move ++;
			}else{
				repeat = 1;
			}
			if(move != 0 && repeat <= 2){
				nums[i - move] = nums[i];
			}
			cout<<"one round=============="<<endl;
			cout<<"repeat: "<<repeat<<endl;
			cout<<"move: "<<move<<endl;
			cout<<"current: "<<nums[i]<<endl;
		}
		for(int i = 0; i < move; i++){
			nums.pop_back();
		}
		return size - move;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> vi {1, 1, 1, 2, 2, 3, 3, 3, 3, 5};
	int ans = s.removeDuplicates(vi);
	cout<<"ans: "<< ans<<endl;
    return 0;
}
