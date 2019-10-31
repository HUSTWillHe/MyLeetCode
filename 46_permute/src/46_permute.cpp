#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution{
	public:
		void one_step(set<int> s, vector<int> v, vector<vector<int>>& vv){
			cout<<"one step:====================="<<endl;
			cout<<"size of s: "<<s.size()<<endl;
			cout<<"size of v: "<<v.size()<<endl;
			cout<<"member of v: "<<endl;
			for(int i = 0; i < v.size(); i++){
				cout<<v[i]<<'\t'<<endl;
			}
			if(s.empty()){
				cout<<"now push answer to vv."<<endl;
				vv.push_back(v);
			}else{
				for(set<int>::iterator it = s.begin(); it != s.end(); it++){
					v.push_back(*it);
					s.erase(it);
					one_step(s, v, vv);
				}
			}
		}
		vector<vector<int>> permute(vector<int>& nums) {
			vector<vector<int>> vv;
			vector<int> v;
			set<int> s(nums.begin(), nums.end());
			one_step(s, v, vv);
			return vv;
		}
};

int main(int argc,char** argv){
	vector<int> v{1,2,3};
	Solution s;
	vector<vector<int>> vv = s.permute(v); 
	for(auto a : vv){
		for(auto b : a){
			cout<<b<<'\t';
		}
		cout<<endl;
	}
    return 0;
}
