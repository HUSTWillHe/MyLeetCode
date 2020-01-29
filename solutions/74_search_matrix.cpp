#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int recursive_line(const vector<vector<int>>& matrix, int target, int begin, int end){
		if(end - begin == 1)
			return begin;
		int mid = (begin + end)/2;
		if(matrix[mid][0] == target){
			return mid;
		}else if(matrix[mid][0] > target){
			return recursive_line(matrix, target, begin, mid);
		}else{
			return recursive_line(matrix, target, mid, end);
		}
	}

	int recursive_row(const vector<int>& v, int target, int begin, int end){
		if(end - begin == 1)
			return begin;
		int mid = (begin + end)/2; 
		if(v[mid] == target)
			return mid;
		if(v[mid] > target)
			return recursive_row(v, target, begin, mid);
		return recursive_row(v, target, mid, end);
	}

	int find_line(const vector<vector<int>>& matrix, int target){
	int height = matrix.size();
	return recursive_line(matrix, target, 0, height);
	}
	
	int find_row(const vector<int>& v, int target){
		int width = v.size();
		return recursive_row(v, target, 0, width);
	}

	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int height = matrix.size();
		if(height == 0)
			return false;
		int width = matrix[0].size();
		if(width == 0)
			return false;
		int target_line = find_line(matrix, target);
		int target_row = find_row(matrix[target_line], target);
		if(matrix[target_line][target_row] == target){
			return true;
		}
		else{
			return false;
		}
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<vector<int>> matrix{{1,3,5,7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
	int test_num = 0;
	while(test_num != -1){
		cout<<"Input test number."<<endl;
		cin>>test_num;
		bool ans = s.searchMatrix(matrix, test_num);
		cout<<"ans is: "<<ans<<endl;
	}

    return 0;
}
