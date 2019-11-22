#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
private:
	int size;
	vector<int> source;
	vector<int> fact;
	string result;
public:
	void factorial(){
		if(size == 0)
			return;
		if(size == 1){
			fact.push_back(0);
			return;
		}
		if(size == 2){
			fact.push_back(0);
			fact.push_back(1);
			return;
		}
		fact.push_back(0);
		fact.push_back(1);
		for(int i = 2; i < size; i++){
			fact.push_back(i * fact[i-1]);
		}
	}

	void getSource(){
		for(int i = 1; i <= size; i++){
			source.push_back(i);
		}
	}

	string getPermutation(int n, int k){
		result = "";
		size = n;
		factorial();
		getSource();
		int cur_idx, last = k - 1;
		for(int i = n; i > 1; i--){
			cur_idx = last / fact[i - 1];
			last = last % fact[i - 1];
			result += to_string(source[cur_idx]);
			source.erase(source.begin() + cur_idx);
		}
		result += to_string(source[0]);
		return result;
	}
};

int main(int argc,char** argv){
	Solution s, s1, s2, s3, s4, s5;
	cout<<s1.getPermutation(3, 1)<<endl;
	cout<<s2.getPermutation(3, 2)<<endl;
	cout<<s3.getPermutation(3, 3)<<endl;
	cout<<s4.getPermutation(3, 4)<<endl;
	cout<<s5.getPermutation(3, 5)<<endl;
	cout<<s.getPermutation(3, 6)<<endl;
    return 0;
}
