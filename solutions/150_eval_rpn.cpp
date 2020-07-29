#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>
#include <assert.h>

using namespace std;

class Solution {
public:
	deque<int> numbers;

	bool is_digit(const string &str){
		if(str[0] == '-' && str.size() > 1){
			return all_of(str.begin() + 1, str.end(), ::isdigit);
		}else{
			return all_of(str.begin(), str.end(), ::isdigit);
		}
	}

	int evalRPN(vector<string>& tokens){
		if(tokens.size() == 0)
			return 0;
		for(auto a: tokens){
			if(is_digit(a)){
				numbers.push_back(stoi(a));
			}else{
				int second = numbers.back();
				numbers.pop_back();
				int first = numbers.back();
				numbers.pop_back();
				int ans = 0;
				if(a == "+")
					ans = first + second;
				else if(a == "-")
					ans = first - second;
				else if(a == "*")
					ans = first * second;
				else if(a == "/")
					ans = first/second;
				numbers.push_back(ans);
			}
		}
		return numbers.back();
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<string> vs{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
	int ans = s.evalRPN(vs);
	cout<<"ans: "<<ans<<endl;
    return 0;
}
