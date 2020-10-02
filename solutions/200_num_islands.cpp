#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
private:
	void markIsland(vector<vector<char>>& grid, int height, int width){
		vector<pair<int, int>> points{pair<int, int>{height, width}};
		while(!points.empty()){
			cout<<"----------------"<<endl;
			for(auto p: points) {
				cout<<p.first<<":"<<p.second<<'\t';
			}
			cout<<endl;
			vector<pair<int, int>> temp;
			for(auto p: points) {
				cout<<"p: "<<p.first<<": "<<p.second<<endl;
				if(p.first < 0 || p.first > grid.size() - 1 || p.second < 0 || p.second > grid[0].size() - 1 || grid[p.first][p.second] != '1')
					continue;
				cout<<"pass"<<endl;
				grid[p.first][p.second] = '2';
				temp.push_back(pair<int, int>{p.first - 1, p.second});
				temp.push_back(pair<int, int>{p.first + 1, p.second});
				temp.push_back(pair<int, int>{p.first, p.second - 1});
				temp.push_back(pair<int, int>{p.first, p.second + 1});
			}
			points = temp;
		}
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		if(grid.size() == 0)
			return 0;
		if(grid[0].size() == 0)
			return 0;
		int height = grid.size(), width = grid[0].size(), island_cnt = 0;
		cout<<"height: "<<height<<"  width: "<<width<<endl;
		for(int i = 0; i < height; i++) {
			for(int k = 0; k < width; k++) {
				if(grid[i][k] == '1'){
					island_cnt++;
					cout<<"*************************"<<endl;
					cout<<"island count"<<island_cnt<<endl;
					markIsland(grid, i, k);
				}
			}
		}
		return island_cnt;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<vector<char>> grid{	{'1', '1', '1', '1', '0'},
								{'1', '1', '0', '1', '0'}, 
								{'1', '1', '0', '0', '0'}, 
								{'0', '0', '0', '0', '0'}};
	int ans = s.numIslands(grid);
	cout<<"ANS:  ============="<<endl;
	cout<<ans<<endl;
    return 0;
}
