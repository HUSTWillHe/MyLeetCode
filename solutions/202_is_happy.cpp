#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

class Solution {
private:
	int calSum(int n) {
		int sum = 0;
		while(n != 0) {
			sum += pow(n % 10, 2);
			n /= 10;
		}
		return sum;
	}
public:
	bool isHappy(int n) {
		set<int> storage;
		int cur = n;
		while(true) {
			cout<<"cur: "<<cur<<endl;
			if(storage.find(cur) != storage.end()) 
				return false;
			if(cur == 1)
				return true;
			storage.insert(cur);
			cur = calSum(cur);
		}
	}
};

int main(int argc,char** argv){
	Solution s;
	bool ans = s.isHappy(82);
	cout<<"ANS: "<<ans<<endl;
    return 0;
}
