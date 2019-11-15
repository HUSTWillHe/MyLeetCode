#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

class Solution {
public:
	string int2str(int i, int length){
		string s(length, '.');
		s[i] = 'Q';
		return s;
	}

	vector<vector<string>> convertStringFormating(vector<vector<int>> int_result, int n){
		vector<vector<string>> string_result;
		vector<string> sub_result;
		for(auto vi: int_result){
			sub_result.clear();
			for(auto i: vi){
				sub_result.push_back(int2str(i, n));
			}
			string_result.push_back(sub_result);
		}
		return string_result;
	}
	
	void recursive(vector<int>& cur, set<int> sum, set<int> delta, vector<vector<int>>& result, int n){
		if(cur.size() == n)
			result.push_back(cur);
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

	vector<vector<string>> solveNQueens(int n){
		vector<vector<int>> int_result;
		vector<vector<string>> string_result;
		vector<int> cur;
		set<int> sum;
		set<int> delta;
		recursive(cur, sum, delta, int_result, n);
		string_result = convertStringFormating(int_result, n);
		return string_result;
	}
};

void displayQueen(vector<vector<string>> queen){
	for(auto vs: queen){
		cout<<"one queen===================="<<endl;
		for(auto s: vs){
			cout<<s<<endl;
		}
		cout<<endl;
	}
}

int main(int argc,char** argv){
	Solution s;
	vector<vector<string>> result = s.solveNQueens(4);
	displayQueen(result);
    return 0;
}
