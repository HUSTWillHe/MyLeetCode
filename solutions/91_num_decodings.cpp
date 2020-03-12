#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int numDecodings(string s){
		int size = s.size();
		if(size == 0)
			return 0;
		if(s[0] == '0')
			return 0;
		if(size == 1){
			return 1;
		}
		int former_one = 1, former_two = 1;
		for(int i = 1; i < size; i++){
			int temp;
			if(s[i] == '0'){
				if(s[i - 1] == '1' || s[i - 1] == '2')
					temp = former_two;
				else
					return 0;
			}else{
				if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] - '0' <= 6)){
					temp = former_one + former_two;
				}else{
					temp = former_one;
				}
			}
			former_two = former_one;
			former_one = temp;
		}
		return former_one;
	}
};

int main(int argc,char** argv){
	Solution s;
	int ans = s.numDecodings("10");
	cout<<"ans: "<<ans<<endl;
    return 0;
}
