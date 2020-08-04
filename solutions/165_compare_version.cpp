#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	void splitString(const string &s, vector<string>& token, const string& delimiters = "."){
		string::size_type lastPos= s.find_first_not_of(delimiters, 0);
		string::size_type pos = s.find_first_of(delimiters, lastPos);
		while(string::npos != pos || string::npos != lastPos){
			token.push_back(s.substr(lastPos, pos - lastPos));
			lastPos = s.find_first_not_of(delimiters, pos);
			pos = s.find_first_of(delimiters, lastPos);
		}
	}
	
	bool allZero(const vector<string> clips){
		for(auto s: clips){
			if(stoi(s) != 0)
				return false;
		}
		return true;
	}

public:
	int compareVersion(string version1, string version2) {
		vector<string> versionClips1, versionClips2;
		splitString(version1, versionClips1);
		splitString(version2, versionClips2);
		for(int i = 0; i < versionClips1.size() || i < versionClips2.size(); i++){
			if(i >= versionClips1.size()){
				vector<string> last(versionClips2.begin() + i, versionClips2.end());
				if(allZero(last))
					return 0;
				return -1;
			}
			if(i >= versionClips2.size()){
				vector<string> last(versionClips1.begin() + i, versionClips1.end());
				if(allZero(last))
					return 0;
				return 1;
			}
			if(stoi(versionClips1[i]) > stoi(versionClips2[i]))
				return 1;
			if(stoi(versionClips1[i]) < stoi(versionClips2[i]))
				return -1;
		}
		return 0;
	}
};

int main(int argc,char** argv){
	Solution s;
	int ans = s.compareVersion("1.0", "1");
	cout<<"ans : "<<ans<<endl;
    return 0;
}
