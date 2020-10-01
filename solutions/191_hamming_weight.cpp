#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int cnt = 0;
		while(n != 0){
			n &= n - 1;
			cnt++;
		}
		return cnt;
	}
};

int main(int argc,char** argv){
	Solution s;
	int ans = s.hammingWeight(3);
	cout<<ans<<endl;
    return 0;
}
