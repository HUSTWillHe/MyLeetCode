#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
private:
	vector<string> ans;

	void backtrace(string s, int last, string& cur){
		cout<<"new round---------------------------"<<endl;
		cout<<"current s: "<<s<<endl;
		cout<<"current last: "<<last<<endl;
		cout<<"current cur: "<<cur<<endl;
		if(s.size() == 0)
			return;
		if(last == 1){
			if(s.size() > 3)
				return;
			int tail = stoi(s);
			if(tail >= 0 && tail <= 255){
				if(s.size() > 1 && s[0] == '0')
					return;
				int len = cur.size();
				cur += s;
				ans.push_back(cur);
				cur = cur.substr(0, len);
				return;
			}else{
				return;
			}
		}else{
			for(int i = 1; i <= 3; i++){
				if(s.size() < i)
					return;
				string sub = s.substr(0, i);
				int mid = stoi(sub);
				if(mid >= 0 && mid <= 255){
					if(i > 1 && sub[0] == '0')
						return;
					int len = cur.size();
					cur = cur + sub + "."; 
					backtrace(s.substr(i), last - 1, cur);
					cur = cur.substr(0, len);
				}
			}
		}
	}
public:

	vector<string> restoreIpAddresses(string s){
		string cur = "";
		backtrace(s, 4, cur);
		return ans;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<string> ans = s.restoreIpAddresses("0279245587303");
	cout<<"answer: "<<endl;
	for(auto a: ans){
		cout<<a<<endl;
	}
    return 0;
}
