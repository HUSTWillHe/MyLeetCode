#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		for(int i = 0; i < 16; i++){
			bool left = (n & 0x1<<(31 - i)) != 0;
			bool right = (n & (0x1<<i)) != 0;
			if(left){
				n |= 0x1<<i;
			}else{
				n &= ~(0x1<<i);
			}
			if(right){
				n |= 0x1<<(31 - i);
			}else{
				n &= ~(0x1<<(31 - i));
			}
		}
		return n;
	}
};

int main(int argc,char** argv){
	Solution s;
	uint32_t ans = s.reverseBits(43261596);
	cout<<ans<<endl;
    return 0;
}
