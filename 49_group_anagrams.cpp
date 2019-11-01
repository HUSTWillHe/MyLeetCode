#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
private:
	void inner_sort(vector<pair<int, string&>> &vpis){
		for(auto a : vpis){
			sort(a.second.begin(), a.second.end());
		}
	}

	vector<vector<string>> transInt2Str(const vector<vector<int>>& vvi, const vector<string>& strs){
		vector<vector<string>> vvs;
		for(auto a : vvi){
			vector<string> vs;
			for(int i : a){
				vs.push_back(strs[i]);
			}
			vvs.push_back(vs);
		}
		return vvs;
	}
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<pair<int, string&>> vpis;
		vector<vector<string>> vvs;
		if (strs.size() == 0){
			return vvs;
		}
		vector<string> new_vs(strs);
		for(int i = 0; i < strs.size(); i++){
			vpis.push_back(pair<int, string&>(i,new_vs[i]));
		}
		
		inner_sort(vpis);
		cout<<"after inner sort======================="<<endl;
		for(auto a: vpis){
			cout<<a.first<<" : "<<a.second<<endl;
		}
		cout<<"strs"<<endl;
		for(auto a: strs){
			cout<<a<<endl;
		}
		sort(vpis.begin(), vpis.end(), [](const pair<int, string&>& a, const pair<int, string&>& b) -> bool { return a.second < b.second;});
		cout<<"after out sort============somethin went wrong================="<<endl;
		for(auto a:vpis){
			cout<<a.first<<" : "<<a.second<<endl;
		}
		cout<<"strs"<<endl;
		for(auto a: strs){
			cout<<a<<endl;
		}
		vector<vector<int>> vvi;
		vector<int> vi;
		vi.push_back(vpis[0].first);
		for(int i = 1; i < vpis.size(); i++){
			if(vpis[i].second == vpis[i-1].second){
				vi.push_back(vpis[i].first);
			}else{
				vvi.push_back(vi);
				vi.clear();
				vi.push_back(vpis[i].first);
			}
		}
		vvi.push_back(vi);
		cout<<"get vvi "<<endl;
		for(auto a: vvi){
			cout<<"one level: "<<endl;
			for(auto b: a){
				cout<<b<<" : "<<strs[b]<<'\t';
			}
			cout<<endl;
		}
		cout<<"strs"<<endl;
		for(auto a: strs){
			cout<<a<<endl;
		}
		vvs = transInt2Str(vvi, strs);

		return vvs;
	}
};

int main(int argc,char** argv){
	vector<string> vs = {"cccd", "a", "ab", "aabb", "baba", "ba", "abba",  "cdcc"};
	Solution s;
	vector<vector<string>> vvs = s.groupAnagrams(vs);
	for(auto a : vvs){
		cout<<"same level: "<<endl;
		for(auto s : a){
			cout<<s<<'\t';
		}
		cout<<endl;
	}
    return 0;
}
