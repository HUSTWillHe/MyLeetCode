#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex){
		if(rowIndex == 0)
			return vector<int>{1};
		vector<int> cur, last;
		for(int i = 0; i < rowIndex + 1; i++){
			cur.clear();
			for(int k = 0; k < i + 1; k++){
				if(k == 0 || k == i){
					cur.push_back(1);
				}else{
					cur.push_back(last[k - 1] + last[k]);
				}
			}
			last = cur;
		}
		return cur;
	}
};

int main(int argc,char** argv){
	Solution s;
	for(int i = 0; i < 5; i++){
		cout<<"-------------------"<<endl;
		cout<<"current i: "<<i<<endl;
		vector<int> ans = s.getRow(i);
		for(auto a: ans){
			cout<<a<<'\t';
		}
		cout<<endl;
	}
    return 0;
}
