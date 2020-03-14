#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
	int numTrees(int n){
		if(n <= 0)
			return 0;
		if(n == 1)
			return 1;
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for(int i = 2; i <= n; i++){
			for(int k = 0; k < i; k++){
				dp[i] += dp[k] * dp[i - k - 1];
			}
		}
		return dp[n];
	}
};

int main(int argc,char** argv){
	Solution s;
	int ans = s.numTrees(stoi(argv[1]));
    return 0;
}
