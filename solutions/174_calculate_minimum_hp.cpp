#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon){
		int height = dungeon.size();
		if(height == 0)
			return 0;
		int width = dungeon[0].size();
		if(width == 0)
			return 0;
		dungeon[height - 1][width - 1] = max(1, 1 - dungeon[height - 1][width - 1]);
		for(int i = height - 2; i >= 0; i--){
			dungeon[i][width - 1] = max(1, dungeon[i + 1][width - 1] - dungeon[i][width - 1]);
		}
		for(int i = width - 2; i >= 0; i--){
			dungeon[height - 1][i] = max(1, dungeon[height - 1][i + 1] - dungeon[height - 1][i]);
		}
		for(int i = height - 2; i >= 0; i--){
			for(int k = width - 2; k >= 0; k--){
				dungeon[i][k] = max(1, min(dungeon[i + 1][k], dungeon[i][k + 1]) - dungeon[i][k]);
			}
		}
		return dungeon[0][0];
	}
};

int main(int argc,char** argv){
	Solution s;
//	vector<vector<int>> vvi{{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
	vector<vector<int>> vvi{{100}};
	int ans = s.calculateMinimumHP(vvi);
	cout<<"ans: "<<ans<<endl;
    return 0;
}
