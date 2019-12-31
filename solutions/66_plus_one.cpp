#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int size = digits.size();
		if(size == 0)
			return digits;
		reverse(digits.begin(), digits.end());
		for(auto a: digits){
			cout<<a<<'\t';
		}
		cout<<endl;
		bool increase = true;
		for(int i = 0; i < size; i++){
			if(increase){
				digits[i]++;
				increase = false;
			}
			if(digits[i] == 10){
				digits[i] = 0;
				increase = true;
			}
		}
		if(increase)
			digits.push_back(1);

		for(auto a: digits){
			cout<<a<<'\t';
		}

		cout<<endl;
		reverse(digits.begin(), digits.end());
		return digits;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> v{9,9,9};
	s.plusOne(v);
	for(auto a:v){
		cout<<a<<'\t';
	}
	cout<<endl;
    return 0;
}
