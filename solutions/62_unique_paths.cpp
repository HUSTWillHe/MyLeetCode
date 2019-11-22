#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n){
		vector<vector<int>> record(m, vector<int>(n, 0));
		if(m == 0 || n == 0){
			return 0;
		}
		if(m == 1 || n == 1){
			return 1;
		}
		for(int i = 1; i < m; i++){
			record[i][0] = 1;
		}
		for(int i = 1; i < n; i++){
			record[0][i] = 1;
		}
		for(int i = 1; i < m; i++){
			for(int k = 1; k < n; k++){
				record[i][k] = record[i - 1][k] + record[i][k - 1];
			}
		}
		return record[m-1][n-1];
	}
};

int main(int argc,char** argv){
	Solution s;
	cout<<s.uniquePaths(3,2)<<endl;
    return 0;
}
