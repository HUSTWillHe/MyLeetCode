#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef vector<pair<string*, string>> VPSPS;

class Solution {
public:
	VPSPS vs2vpsps(const vector<string>& strs) {
		VPSPS vpsps;
		vector<string> vs(strs);
		for(auto a : strs){
			vs.push_back(a);
			vpsps.push_back(pair<string*, string>(vs.data()+(vs.size()-1), a));
		}
		return vpsps;
	}

	void innerSort(VPSPS& vpsps) {
		for(auto v : vpsps){
			sort((*(v.first)).begin(), (*(v.first)).end());		
		}
	}
	
	void outterSort(VPSPS& vpsps) {
		sort(vpsps.begin(), vpsps.end(), [](const pair<string*, string>& a, const pair<string*, string>& b) -> bool {return *(a.first) > *(b.first);});
	}

	vector<vector<string>> vpsps2vvs(const VPSPS& vpsps) {
		vector<vector<string>> vvs;
		vector<string> vs;
		string last = "";
		for(auto v : vpsps){
			string cur_str = *(v.first);
			if(cur_str != last){
				vvs.push_back(vs);
				last = cur_str;
				vs.clear();
				vs.push_back(v.second);
			}else{
				vs.push_back(v.second);
			}
		}
		vvs.push_back(vs);
		return vvs;
	}

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		VPSPS vpsps = vs2vpsps(strs);
		innerSort(vpsps);
		outterSort(vpsps);
		vector<vector<string>> vvs;
		vvs = vpsps2vvs(vpsps);
		return vvs;
	}
	
};

void printVpsps(const VPSPS& vpsps, string s){
	cout<<s<<endl;
	for(auto a: vpsps){
			cout<<*a.first<<'\t'<<a.second<<endl;
		}
}

void test(){
	Solution s;
	vector<string> vs;
	vs.push_back("heliwei");
	vs.push_back("liweihe");
	vs.push_back("longwei");
	vs.push_back("weilong");
	VPSPS vpsps = s.vs2vpsps(vs);
	printVpsps(vpsps, "make vector pair");

	s.innerSort(vpsps);
	printVpsps(vpsps, "after inner sort");

	s.outterSort(vpsps);
	printVpsps(vpsps, "after outter sort");

	vector<vector<string>> vvs = s.vpsps2vvs(vpsps);
	cout<<"the result: "<<endl;
	for(auto vs: vvs){
		for(auto s: vs){
			cout<<s<<'\t';
		}
		cout<<endl;
	}
}

void test2(){
	vector<string> vs;
	vs.push_back("heliwei");
	vs.push_back("liweihe");
	vs.push_back("longwei");
	vs.push_back("weilong");

	groupAnagrams(vs);
}

int main(int argc,char** argv){
	//test();
	test2();
    return 0;
}
