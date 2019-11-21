#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	vector<vector<int>> result;
	int size;
public:
	enum Boundary{
		up=0,
		right,
		bottom,
		left
	};

	struct Position{
		int round;
		Boundary boundary;
	};

	void initMatrix(){
		vector<int> v(size, 0);
		vector<vector<int>> matrix(size, v);
		result = matrix;
	}

	Position getPosition(int col, int row){

	}

	vector<vector<int>> generateMatric(int n) {
		size = n;
		initMatrix();
		for(int i = 0; i < n; i++) {
			for(int k = 0; k < n; k++){

			}
		}
		for(auto a: result){
			for(auto b: a){
				cout<<b<<'\t';
			}
			cout<<endl;
		}
		return result;
	}
};

int main(int argc,char** argv){
	Solution s;
	s.generateMatric(3);
    return 0;
}
