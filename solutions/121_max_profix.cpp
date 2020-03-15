#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices){
		if(prices.size() == 0)
			return 0;
		int min = prices[0];
		int profit = 0;
		for(auto a: prices){
			if(a < min){
				min = a;
			}
			int cur = a - min;
			if(cur > profit)
				profit = cur;
		}
		return profit;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> vi{7, 1, 5, 3, 6, 4};
	int ans = s.maxProfit(vi);
	cout<<"ans: "<<ans<<endl;
    return 0;
}
