#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	size_t getLength(int i) {
		size_t cnt = 0;
		while(i != 0){
			i = i >> 1;
			cnt ++;
		}
		return cnt;
	}

public:
	int rangeBitwiseAnd(int m, int n) {
		size_t m_size = getLength(m);
		size_t n_size = getLength(n);
		if(m_size != n_size || m_size == 0)
			return 0;
		int bit = 1 << (m_size - 1);
		int ans = 0;
		while(bit != 0) {
			if((m & bit) != (n & bit)) {
				break;
			}
			ans += (m & bit);
			bit = bit >> 1;
		}
		return ans;
	}
};

int main(int argc,char** argv){
	Solution s;
	int ans = s.rangeBitwiseAnd(5, 7);
	cout<<"ans: "<<ans<<endl;
    return 0;
}
