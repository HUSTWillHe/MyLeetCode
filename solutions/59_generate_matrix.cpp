#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	vector<vector<int>> result;
	int size;
	int current = 1;

public:
	void initMatrix(){
		vector<int> v(size, 0);
		vector<vector<int>> matrix(size, v);
		result = matrix;
	}

	void oneRound(int n){
		result[n][n] = current;
		int col = n;
		int row = n;
		for(int i = 0; i < size - 1 - n * 2; i++){
			result[col][++row] = ++current;
		}
		for(int i = 0; i < size - 1 - n * 2; i++){
			result[++col][row] = ++current;
		}
		for(int i = 0; i < size - 1 - n * 2; i++){
			result[col][--row] = ++current;
		}
		for(int i = 0; i < size - 2 - n * 2; i++){
			result[--col][row] = ++current;
		}
		current ++;
		//cout<<"-------------------------"<<endl;
		//printResult();
	}

	void printResult(){
		for(auto a: result){
			for(auto b: a){
				cout<<b<<'\t';
			}
			cout<<endl;
		}
	}

	vector<vector<int>> generateMatrix(int n) {
		size = n;
		initMatrix();

		for(int i = 0; i < (size + 1)/2; i++){
			oneRound(i);
		}

		//printResult();
		return result;
	}
};

int main(int argc,char** argv){
	Solution s;
	s.generateMatrix(5);
    return 0;
}
