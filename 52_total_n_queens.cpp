#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

class Solution {
public:
	void recursive(vector<int>& cur, set<int> sum, set<int> delta, int& result, int n){
		if(cur.size() == n)
			result++;
		for(int i = 0; i < n; i++){
			int size = cur.size();
			if(find(cur.begin(), cur.end(), i) == cur.end() &&
					find(sum.begin(), sum.end(), size + i) == sum.end() &&
					find(delta.begin(), delta.end(), size - i) == delta.end()){
				sum.insert(size + i);
				delta.insert(size - i);
				cur.push_back(i);
				recursive(cur, sum, delta, result, n);
				sum.erase(size + i);
				delta.erase(size - i);
				cur.pop_back();
			}
		}
	}

	int totalNQueens(int n){
		int result = 0;
		vector<int> cur;
		set<int> sum;
		set<int> delta;
		recursive(cur, sum, delta, result, n);
		return result;
	}
};

int main(int argc,char** argv){
	Solution s;
	int result = s.totalNQueens(4);
	cout<<"result: "<<result<<endl;
    return 0;
}
