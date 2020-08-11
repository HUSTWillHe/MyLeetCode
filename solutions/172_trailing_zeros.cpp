#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int trailingZeroes(int n){
		int ans = 0;
		int cnt = n;
		while(cnt > 0){
			cnt /= 5;
			ans += cnt;
		}
		return ans;
	}
};

int main(int argc,char** argv){
	Solution s;
	int ans = s.trailintZeros(50);
	cout<<"ans: "<<ans<<endl;
    return 0;
}
