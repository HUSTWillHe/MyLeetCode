#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int height = grid.size();
		if(height == 0)
			return 0;
		int width = grid[0].size();
		if(width == 0) 
			return 0;
		for(int i = 1; i < width; i++){
			grid[0][i] += grid[0][i-1];
		}
		for(int i = 1; i < height; i++){
			grid[i][0] += grid[i-1][0];
		}
		for(int i = 1; i < height; i++){
			for(int k = 1; k < width; k++){
				grid[i][k] += min(grid[i-1][k], grid[i][k-1]);
			}
		}
		return grid[height - 1][width - 1];
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<vector<int>> v{{1, 3, 1},{1, 5, 1},{4, 2, 1}};
	int result = s.minPathSum(v);
	cout<<"result: "<<result<<endl;
    return 0;
}
