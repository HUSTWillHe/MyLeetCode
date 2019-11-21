#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatric(int n) {
		vector<int> v(n, 0);
		vector<vector<int>> result(n, v);
		for(auto a: result){
			for(auto b: a){
				cout<<b<<'\t';
			}
			cout<<endl;
		}
		return result;
	}
};

int main(int argc,char** argv){
	Solution s;
	s.generateMatric(3);
    return 0;
}
