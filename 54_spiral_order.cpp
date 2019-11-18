#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	struct Boundary{
		size_t top = 0;
		size_t bottom = 0;
		size_t left = 0;
		size_t right = 0;
	};

	struct Position{
		size_t col = 0;
		size_t row = 0;
	};
	
	enum Direction{
		right = 0,
		down,
		left,
		up
	};

	Boundary boundary;
	Direction direction;
	Position current;
	vector<vector<int>> mat;
	vector<int> result;

public:
	void processOneLine(){
		cout<<"======================"<<endl;
		cout<<"dirction: "<<direction<<endl;
		cout<<"current position: "<<current.col<<'\t'<<current.row<<endl;
		cout<<"boundary: "<<boundary.top<<'\t'<<boundary.left<<'\t'<<boundary.bottom<<'\t'<<boundary.right<<endl;

		switch(direction){
			case Direction::right:
				for(int i = current.row; i < boundary.right; i++){
					result.push_back(mat[current.col][i]);
					cout<<mat[current.col][i]<<'\t';
				}
				cout<<endl;
				current.row = boundary.right;
				boundary.top ++;
				direction = Direction::down;
				break;
			case Direction::left:
				for(int i = current.row; i > boundary.left; i--){
					result.push_back(mat[current.col][i]);
					cout<<mat[current.col][i]<<'\t';
				}
				cout<<endl;
				current.row = boundary.left;
				boundary.bottom --;
				direction = Direction::up;
				break;
			case Direction::down:
				for(int i = current.col; i < boundary.bottom; i++){
					result.push_back(mat[i][current.row]);
					cout<<mat[i][current.row]<<'\t';
				}
				cout<<endl;
				current.col = boundary.bottom;
				boundary.right --;
				direction = Direction::left;
				break;
			case Direction::up:
				for(int i = current.col; i > boundary.top; i--){
					result.push_back(mat[i][current.row]);
					cout<<mat[i][current.row]<<'\t';
				}
				cout<<endl;
				current.col = boundary.top;
				boundary.left ++;
				direction = Direction::right;
				break;
			default:
				break;
		}
	}

	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		mat = matrix;
		current.col = 0;
		current.row = 0;
		size_t h = matrix.size();
		if(h == 0)
			return result;
		size_t w = matrix[0].size();
		if(w == 0)
			return result;
		if(h == 1){
			return matrix[0];
		}
		if(w == 1){
			for(auto v: matrix){
				for(auto a: v){
					result.push_back(a);
				}
			}
			return result;
		}
		boundary.bottom = h - 1;
		boundary.right = w - 1;
		direction = Direction::right;
		while(boundary.bottom >= boundary.top && boundary.right >= boundary.left){
			processOneLine();
		}
		result.push_back(matrix[current.col][current.row]);
		return result;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> v{1,2,3,4};
	vector<vector<int>> matrix(4, v);
	for(int i = 0; i < matrix.size(); i++){
		for(int k = 0; k < v.size(); k++){
			matrix[i][k] = i *v.size() + k;
		}
	}
	cout<<"origin matrix"<<endl;
	for(auto vi: matrix){
		for(auto a: vi){
			cout<<a<<'\t';
		}
		cout<<endl;
	}
	vector<vector<int>> m(4, vector<int>(2, 3));
	//m.push_back(vector<int>(1, 1));
	vector<int> result = s.spiralOrder(m);
	cout<<"result: "<<endl;
	for(auto a: result){
		cout<<a<<'\t';
	}
	cout<<endl;
    return 0;
}
