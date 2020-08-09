#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string convertToTitle(int n){
		string ans;
		while(n > 0){
			int remainder = n % 26;
			if(remainder == 0){
				ans = 'Z' + ans;
				n /= 26;
				n -= 1;
			}else{
				char cur = 'A' + remainder - 1;
				ans = cur + ans;
				n /= 26;
			}
		}
		return ans;
	}
};

int main(int argc,char** argv){
	Solution s;
	string ans = s.convertToTitle(701);
	cout<<"ans: "<<ans<<endl;
    return 0;
}
