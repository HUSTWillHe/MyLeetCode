#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Solution {
public:
	string add(string num1, string num2){
		cout<<num1<<" add "<<num2;
		int size1 = num1.size(), size2 = num2.size();
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		string ans;
		bool flag = false;
		for(int i = 0; i < size1 || i < size2 || flag == true; i++){
			int sum = 0;
			sum += i >= size1 ? 0: num1[i] - '0';
			sum += i >= size2 ? 0: num2[i] - '0';
			sum += flag ? 1: 0;
			if(sum > 9){
				flag = true;
				ans += '0' + (sum - 10);
			}else{
				flag = false;
				ans += '0' + sum;
			}
		}
		reverse(ans.begin(), ans.end());
		cout<<" is "<<ans<<endl;
		return ans;
	}
	
	string char_multiply_string(char c, string s){
		cout<<c<<" mul "<<s;
		string ans;
		reverse(s.begin(), s.end());
		int ii = c - '0';
		int size = s.size();
		int plus = 0;
		for(int i = 0; i < size; i++){
			int cur = ii * (s[i] - '0') + plus;
			plus = cur / 10;
			ans += '0' + (cur % 10);
		}
		if(plus != 0)
			ans += '0' + plus;
		reverse(ans.begin(), ans.end());
		cout<<" is "<<ans<<endl;
		return ans;
	}

	string multiply(string num1, string num2){
		if(num1 == "0" || num2 == "0")
			return "0";
		string ans = "0";
		int size1 = num1.size(), size2 = num2.size();
		string post = "";
		for(int i = size1 - 1; i >= 0; i--){
			ans = add(char_multiply_string(num1[i], num2) + post, ans);
			post += '0';
			cout<<"-------------"<<endl;
			cout<<"round i: "<<i<<"  ans:  "<<ans << "  post: "<<post<<endl;
		}
		return ans;
	}
};

int main(int argc,char** argv){
	Solution s;
	string ans = s.multiply(argv[1], argv[2]);
	cout<<argv[1]<<" multiply "<<argv[2]<<"  ans is: "<<ans<<endl;
	//string ans = s.add(argv[1], argv[2]);
	//cout<<argv[1]<<"  add  "<<argv[2]<<"  is  "<<ans<<endl;
    return 0;
}
