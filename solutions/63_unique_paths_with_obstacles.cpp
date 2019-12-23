#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int height = obstacleGrid.size();
		if(height == 0) return 0;
		int width = obstacleGrid[0].size();
		if(width == 0) return 0;
		if(obstacleGrid[0][0] == 1) return 0;
		obstacleGrid[0][0] = 1 - obstacleGrid[0][0];
		for(int i = 1; i < height; i++){
			obstacleGrid[i][0] = 1 - obstacleGrid[i][0];
		}
		for(int i = 1; i < width; i++){
			obstacleGrid[0][i] = 1 - obstacleGrid[0][i];
		}
		for(int i = 1; i < height; i++){
			for(int k = 1; k < width; k++){
				obstacleGrid[i][k] = (obstacleGrid[i][k] == 1)?0:obstacleGrid[i - 1][k] + obstacleGrid[i][k - 1];
			}
		}
		return obstacleGrid[height - 1][width - 1];
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> v(3, 0);
	vector<vector<int>> vv(4, v); 
	vv[1][1] = 1;
	vector<int> n(1,0);
	vector<vector<int>> vn(1,n);
	int result = s.uniquePathsWithObstacles(vn);
	cout<<"result: "<<result<<endl;
    return 0;
}
