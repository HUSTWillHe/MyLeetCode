#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
private:
	bool isPalindorme(const string &s, int begin, int end){
		for(int i = begin++, k = end --; i < k; i++, k --){
			if(s[i] != s[k])
			return false;
		}
		return true;
	}
public:
	int minCut(string s){
		if(s.size() == 0){
			return 0;
		}
		vector<int> dp;
		map<char, vector<int>> idxs;
		for(int i = 0; i < s.size(); i++){
			if(idxs.find(s[i]) == idxs.end()){
				idxs[s[i]] = vector<int>{i};
			}else{
				idxs[s[i]].push_back(i);
			}
			vector<int> possible_idxs = idxs[s[i]];
			int current_min_cut = 0;
			for(auto idx: possible_idxs){
				if(isPalindorme(s, idx, i)){
					if(idx == 0){
						current_min_cut = 0;
						break;
					}else{
						if(current_min_cut == 0){
							current_min_cut = dp[idx - 1] + 1;
						}else{
							current_min_cut = min(current_min_cut, dp[idx - 1] + 1);
						}
					}
				}
			}
			dp.push_back(current_min_cut);
		}
		for(auto a: dp){
			cout<<a<<endl;
		}
		return dp[s.size() - 1];
	}
};

int main(int argc,char** argv){
	Solution s;
	int ans = s.minCut("aabaa");
	cout<<"ans is : "<<ans<<endl;
    return 0;
}
