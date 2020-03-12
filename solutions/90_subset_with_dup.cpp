#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums){
		vector<vector<int>> ans;
		int size = nums.size();
		if(size == 0)
			return ans;
		sort(nums.begin(), nums.end());
		ans.push_back(vector<int>());
		ans.push_back(vector<int>{nums[0]});
		for(int i = 1; i < size; i++){
			vector<vector<int>> v_temp;
			for(auto a: ans){
				vector<int> temp = a;
				temp.push_back(nums[i]);
				if(find(ans.begin(), ans.end(), temp) == ans.end()){
					v_temp.push_back(temp);
				}
			}
			ans.insert(ans.end(), v_temp.begin(), v_temp.end());
		}
		return ans;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> n{1, 1, 2, 3};
	vector<vector<int>> ans = s.subsetsWithDup(n);
	cout<<"ans: "<<endl;
	for(auto vi: ans){
		for(auto i: vi){
			cout<<i<<'\t';
		}
		cout<<endl;
	}
    return 0;
}
