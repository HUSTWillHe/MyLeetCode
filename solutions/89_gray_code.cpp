#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n){
		vector<int> ans(1, 0);
		if(n == 0)
			return ans;
		for(int i = 1; i <= n; i++){
			vector<int> mirror = ans;
			reverse(mirror.begin(), mirror.end());
			for(int& a: mirror){
				a+=pow(2, i - 1);
			}
			ans.insert(ans.end(), mirror.begin(), mirror.end());
		}
		return ans;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> ans = s.grayCode(3);
	cout<<"ans: "<<endl;
	for(auto a: ans){
		cout<<a<<'\t';
	}
	cout<<endl;
    return 0;
}
