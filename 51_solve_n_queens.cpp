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
	
	void recursive(vector<int>& cur, vector<vector<int>>& result, int n){
		if(cur.size() == n)
			result.push_back(cur);
		for(int i = 0; i < n; i++){
			if(find(cur.begin(), cur.end(), i) == cur.end()){
				cur.push_back(i);
				recursive(cur, result, n);
				cur.pop_back();
			}
		}
	}

	bool isAttack(vector<int> one_result){
		int col = 0;
		set<int> sum;
		set<int> delta;
		for(auto i: one_result){
			if(find(sum.begin(), sum.end(), i + col) == sum.end()){
				sum.insert(i + col);
			}else{
				return true;
			}
			if(find(delta.begin(), delta.end(), i - col) == delta.end()){
				delta.insert(i - col);
			}else{
				return true;
			}
			col ++;
		}
		return false;
	}

	/**
	 * @function: 检查对角线攻击
	 * @param[in][out]: int_result
	 * @return void 
	 **/
	void recheckResult(vector<vector<int>>& int_result){
		for(int i = int_result.size() - 1; i >= 0; i--){
			vector<vector<int>>::iterator it = int_result.begin() + i;
			if(isAttack(*it)){
				int_result.erase(it);
			}
		}
	}

	vector<vector<string>> solveNQueens(int n){
		vector<vector<int>> int_result;
		vector<vector<string>> string_result;
		vector<int> cur;
		recursive(cur, int_result, n);
		recheckResult(int_result);
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
