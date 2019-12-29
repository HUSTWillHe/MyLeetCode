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
		bool findOne = false;
		for(int i = 1; i < height; i++){
			if(obstacleGrid[i][0]){
				findOne = true;
			}
			obstacleGrid[i][0] = findOne ? 0 : 1;
		}
		findOne = false;
		for(int i = 1; i < width; i++){
			if(obstacleGrid[0][i]){
				findOne = true;
			}
			obstacleGrid[0][i] = findOne?0:1;
		}
		vector<long long int> vlli(obstacleGrid[0].begin(), obstacleGrid[0].end());
		for(int i = 1; i < height; i++){
			vlli[0] = obstacleGrid[i][0];
			for(int k = 1; k < width; k++){
				if(obstacleGrid[i][k] == 1)
					vlli[k] = 0;
				else
					vlli[k] += vlli[k-1];
			}
		}
		return vlli[width - 1];
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> v(13, 0);
	vector<vector<int>> vv(14, v); 
	vv[1][0] = 1;
	vv[1][1] = 1;
	vv[1][2] = 1;
	int result = s.uniquePathsWithObstacles(vv);
	cout<<"result: "<<result<<endl;
    return 0;
}
