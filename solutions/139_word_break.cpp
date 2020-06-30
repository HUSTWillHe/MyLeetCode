#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict){
		int size = s.size();
		set<string> wordSet(wordDict.begin(), wordDict.end());
		if(size == 0)
			return true;
		vector<int> match_points{0};
		for(int i = 0; i < size; i++){
			for(int begin: match_points){
				string sub = s.substr(begin, i - begin + 1);
				if(wordSet.find(sub) != wordSet.end()){
					match_points.push_back(i + 1);
					break;
				}
			}
		}
		cout<<"match points: "<<endl;
		for(auto a: match_points)
			cout<<a<<endl;
		if(*(match_points.end() - 1) == size)
			return true;
		else
			return false;
	}
};

int main(int argc,char** argv){
	Solution s;
	//vector<string> vs{"cat", "dog", "cats", "sands", "and"};
	//string st = "catsandog";
	vector<string> vs{"leet", "code"};
	string st = "leetcode";
	bool ans = s.wordBreak(st, vs);
	cout<<"ans is : "<<ans<<endl;
    return 0;
}
