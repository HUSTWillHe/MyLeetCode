#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int height = matrix.size();
		if(height == 0)
			return;
		int width = matrix[0].size();
		bool first_line = false;
		bool first_row = false;
		if(matrix[0][0] == 0){
			first_row = true;
			first_line = true;
		}else{
			for(int i = 1; i < height; i++){
				if(matrix[i][0] == 0){
					first_row = true;
					break;
				}
			}
			for(int i = 1; i < width; i++){
				if(matrix[0][i] == 0){
					first_line = true;
					break;
				}
			}
		}

		for(int i = 1; i < height; i++){
			for(int k = 1; k < width; k++){
				if(matrix[i][k] == 0){
					matrix[i][0] = 0;
					matrix[0][k] = 0;
				}
			}
		}
		for(int i = 1; i < height; i++){
			if(matrix[i][0] == 0){
				for(int k = 1; k < width; k++){
					matrix[i][k] = 0;
				}
			}
		}
		for(int i = 1; i < width; i++){
			if(matrix[0][i] == 0){
				for(int k = 1; k < height; k++){
					matrix[k][i] = 0;
				}
			}
		}
		if(first_line){
			for(int i = 0; i < width; i++){
				matrix[0][i] = 0;
			}
		}
		if(first_row){
			for(int i = 0; i < height; i++){
				matrix[i][0] = 0;
			}
		}
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<vector<int>> vvi{{1,1,1},{2,0,2},{3,3,3}};
	s.setZeroes(vvi);
    return 0;
}
