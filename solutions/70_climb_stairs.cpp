#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int climbStairs(int n){
		if(n == 0)
			return 0;
		if(n == 1)
			return 1;
		if(n == 2)
			return 2;
		int former = 1, latter = 2, temp;
		for(int i = 3; i <= n; i++){
			temp = latter;
			latter += former;
			former = temp;
		}
		return latter;
	}
};

int main(int argc,char** argv){
	Solution s;
	int result = s.climbStairs(3);
	cout<<"result"<<result<<endl;
	result = s.climbStairs(4);
	cout<<"result"<<result<<endl;
	result = s.climbStairs(6);
	cout<<"result"<<result<<endl;
    return 0;
}
