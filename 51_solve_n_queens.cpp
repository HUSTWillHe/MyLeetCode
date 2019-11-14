#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<string>> allDots(int n){
		vector<string> vs(n, '.');
		vecotr<vector<string>> vvs(n, vs);
		return vvs;
	}

	vector<vector<string>> convertStringFormating(vector<vector<pair<int, int>>> int_result, int n){
		vector<vector<string>> string_result = allDots(n);
		for(auto vi: int_result){
			for(auto i: vi){
				string s = int2Str(i, n);
				sub_result.push_back(s);
			}
			string_result.push_back(sub_result);
		}
		return string_result;
	}
	
	bool isFirstInCur(int i, vector<pair<int, int>> cur){
		for(auto a: cur){
			if(i == a.first)
				return true;
		}
		return false;
	}

	bool isAttack(int i, int k, vector<pair<int, int>> cur){
		for(auto a: cur){
			if(k == cur.second || k + i == cur.first + cur.second ||
					i - k == cur.first - cur.second)
				return true;
		}
		return false;
	}

	void recursive(vector<pair<int, int>>& cur, vector<vector<pair<int, int>>>& result, int n){
		if(cur.size() == n)
			result.push_back(cur);
		for(int i = 0; i < n; i++){
			if(isFirstInCur(i, cur))
				continue;
			for(int k  = 0; k < n; k++){
				if(isAttack(i, k, cur))
					continue;
				else{
					cur.push_back(pair(i, k));
					recursive(cur, result, n);
					cur.pop_back();
				}
			}
		}
	}

	vector<vector<string>> solveNQueens(int n){
		vector<vector<pair<int, int>>> int_result;
		vector<vector<string>> string_result;
		vector<pair<int, int>> cur;
		recursive(cur, int_result, n);
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
	vector<vector<string>> result = s.solveNQueens(3);
	displayQueen(result);
    return 0;
}
