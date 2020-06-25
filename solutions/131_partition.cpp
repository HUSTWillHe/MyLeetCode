#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void print_ans(vector<vector<string>> vvs){
	for(auto vs: vvs){
		for(auto s: vs){
			cout<<s<<'\t';
		}
		cout<<endl;
	}
}

class Solution {
public:
	bool is_palindrome(const string& s, int begin, int end){
		for(int i = begin++, k = end --; i < k; i ++, k --){
			if(s[i] != s[k])
				return false;
		}
		return true;
	}

	vector<vector<string>> partition(string s){
		if(s.size() == 0)
			return vector<vector<string> >{};
		map<char, vector<int>> idxs;
		vector<vector<vector<string>>> dp{};

		for(int i = 0; i < s.size(); i++){
			vector<vector<string>> current;
			if(idxs.find(s[i]) == idxs.end()){
				idxs[s[i]] = vector<int>{i};
			}else{
				idxs[s[i]].push_back(i);
			}
			vector<int> possible_idxs = idxs[s[i]];
			for(auto idx: possible_idxs){
				if(is_palindrome(s, idx, i)){
					if(idx == 0){
						current.push_back(vector<string>{s.substr(idx, i - idx + 1)});
					}else{
						for(auto old: dp[idx - 1]){
							old.push_back(s.substr(idx, i - idx + 1));
							current.push_back(old);
						}
					}
				}
			}
			dp.push_back(current);
			cout<<"======================="<<endl;
			cout<<"i: "<<i<<endl;
			//print_ans(current);
		}
		return dp[s.size() - 1];
	}
};



int main(int argc,char** argv){
	Solution s;
	vector<vector<string>> ans = s.partition("ababa");
	cout<<"ans: "<<endl;
	print_ans(ans);
    return 0;
}
