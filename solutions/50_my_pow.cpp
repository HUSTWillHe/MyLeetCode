#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <assert.h>

using namespace std;
const int MIN_INT = 0x80000000;
const int MAX_INT = 0x7FFFFFFF;

class Solution {
public:
	double positivePow(double x, int n){
		assert(n > 0);
		double ans = 1.0;
		double cur_mul = x;
		while(n != 0){
			cout<<"========================="<<endl;
			cout<<"current mul: "<<cur_mul<<endl;
			cout<<"current n: "<<n<<endl;
			cout<<"current n \% 2: "<<n%2<<endl;
			if(n % 2){
				ans *= cur_mul;
			}
			n = n >> 1;
			cur_mul = cur_mul * cur_mul;
		}
		return ans;
	}

	double myPow(double x, int n){
		if(x == 0) return 0;
		if(n == 0) return 1;
		if(n > 0){
			return positivePow(x, n);
		}
		if(n == MIN_INT){
			return 1 / positivePow(x, MAX_INT) / x;
		}
		if(n < 0){
			return 1/positivePow(x, -n);
		}
	}
};

int main(int argc,char** argv){
	Solution s;
	double ans = s.myPow(1, MIN_INT);
	cout<<"ans: "<< ans<<endl;
    return 0;
}
