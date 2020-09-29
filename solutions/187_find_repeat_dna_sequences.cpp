#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		set<string> storage;
		set<string> ans;
		if(s.size() < 11)
			return vector<string>();
		for(int i = 0; i < s.size() - 9; i++) {
			string cur = s.substr(i, 10);
			if(storage.find(cur) != storage.end()){
				ans.insert(cur);
			}else{
				storage.insert(cur);
			}
		}
		return vector<string>(ans.begin(), ans.end());
	}
};

int main(int argc,char** argv){
	Solution s;
	auto ans = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCAAAAAGGGTTT");
	for(auto a: ans){
		cout<<a<<endl;
	}
    return 0;
}
