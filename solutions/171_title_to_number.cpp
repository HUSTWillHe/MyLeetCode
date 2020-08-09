#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int titleToNumber(string s){
		if(s.size() == 0)
			return 0;
		reverse(s.begin(), s.end());
		long ans = 0;
		long level = 1;
		for(auto a: s){
			ans += (a - 'A' + 1) * level;
			level *= 26;
		}
		return ans;
	}
};

int main(int argc,char** argv){
	Solution s;
	int ans = s.titleToNumber("CFDGSXM");
	cout<<"ans: "<<ans<<endl;
    return 0;
}
