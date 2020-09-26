#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> dailyTemperature(vector<int>& T) {
		vector<int> storage;
		vector<int> ans(T.size(), 0);
		for(int i = 0; i < T.size(); i++){
			if(storage.empty()){
				storage.push_back(i);
				continue;
			}
			while(!storage.empty() && T[i] > T[storage.back()]) {
				ans[storage.back()] = i - storage.back();
				storage.pop_back();
			}
			storage.push_back(i);
		}
		return ans;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> T{73, 74, 75, 71, 69, 72, 76, 73};
	vector<int> ans = s.dailyTemperature(T);
	for(auto a: ans)
		cout<<a<<'\t';
	cout<<endl;
    return 0;
}
