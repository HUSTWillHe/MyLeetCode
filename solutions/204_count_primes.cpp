#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		if(n <= 2)
			return 0;
		vector<int> primes{2};
		for(int i = 3; i < n; i += 2) {
			bool isPrimes = true;
			for(auto a: primes){
				if(a * a > i)
					break;
				if(i % a == 0){
					isPrimes = false;
					break;
				}
			}
			if(isPrimes) {
				primes.push_back(i);
			}
		}
		return primes.size();
	}
};

int main(int argc,char** argv){
	Solution s;
	int ans = s.countPrimes(stoi(string(argv[1])));
	cout<<"ans: "<<ans<<endl;
    return 0;
}
