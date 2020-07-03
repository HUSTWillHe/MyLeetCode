#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
private:
	static bool compare(const int& a, const int& b){
		string astr = to_string(a), bstr = to_string(b);
		int max_len = astr.size() > bstr.size() ? astr.size() : bstr.size();
		while(astr.size() < max_len){
			astr += astr[0];
		}
		while(bstr.size() < max_len){
			bstr += bstr[0];
		}
		int aint = stoi(astr), bint = stoi(bstr);
		return aint < bint;
	}

	int changeLength(int i, int len){
		string ori_str = to_string(i);
		while(ori_str.size() < len){
			ori_str += ori_str[0];
		}
		return stoi(ori_str);
	}
public:
	string largestNumber(vector<int>& nums) {
		int size = nums.size();
		if(size == 0)
			return "";
		int max_len = 0;
		for(int i = 0; i < size; i++){
			int len = to_string(nums[i]).size();
			if(len > max_len){
				max_len = len;
			}
		}
		sort(nums.rbegin(), nums.rend(), compare);
		string ans;
		for(auto a: nums){
			ans += to_string(a);
		}
		return ans;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> vi{3, 30, 34, 5, 9};
	string ans = s.largestNumber(vi);
	cout<<"ans is: "<<ans<<endl;
    return 0;
}
