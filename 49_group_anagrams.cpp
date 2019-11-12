#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
	public:
		vector<vector<string>> groupAnagrams(vector<string>& strs) {
			map<string, vector<string>> msvs;
			for(auto a: strs){
				string s = a;
				sort(s.begin(), s.end());
				msvs[s].push_back(a);
			}
			vector<vector<string>> vvs;
			for(auto a: msvs){
				vvs.push_back(a.second);
			}
			return vvs;
		}
};

int main(){
	vector<string> strs;
	strs.push_back("heliwei");
	strs.push_back("liweihe");
	strs.push_back("longwei");
	strs.push_back("weilong");
	Solution s;
	vector<vector<string>> vvs = s.groupAnagrams(strs);
	for(auto a: vvs){
		for(auto b: a){
			cout<<b<<'\t';
		}
		cout<<endl;
	}
	return 0;
}
