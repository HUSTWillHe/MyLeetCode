#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;

void print_board(const vector<vector<char>> &board){
	for(auto v: board){
		for(auto c: v){
			cout<<c<<'\t';
		}
		cout<<endl;
	}
}

struct Point {
	int x, y;
	Point(int xx, int yy): x(xx), y(yy){}
	bool operator<(const Point& p) const{
		if(x < p.x) return true;
		if(x > p.x) return false;
		if(y < p.y) return true;
		return false;
	}
};
class Solution {
private:
	bool is_surround(vector<vector<char>>& board, Point p, set<Point>& used_point){
		cout<<"is surround:================= "<<endl;
		cout<<"current point: x: "<<p.x<<" y: "<<p.y<<endl;
		cout<<"current board"<<endl;
		print_board(board);
		if(board[p.x][p.y] == 'X')
			return true;
		if(board[p.x][p.y] == 'a')
			return false;
		used_point.insert(p);
		if(p.x == 0 || p.x == board.size() - 1 || p.y == 0 || p.y == board[0].size() - 1){
			return false;
		}
		bool ans = true;
		vector<Point> points_around{Point(p.x, p.y + 1), Point(p.x, p.y - 1), Point(p.x + 1, p.y), Point(p.x - 1, p.y)};
		for(auto new_p : points_around){
			if(used_point.find(new_p) == used_point.end()){
				ans &= is_surround(board, new_p, used_point);
			}
		}
		return ans;
	}
public:
	void solve(vector<vector<char>>& board) {
		int height = board.size();
		if(height == 0)
			return;
		int width = board[0].size();
		if(width == 0)
			return;
		for(int i = 0; i < height; i++){
			for(int j = 0; j < width; j++){
				if(board[i][j] == 'O'){
					set<Point> used_point{};
					bool b = is_surround(board, Point(i, j), used_point);
					cout<<"b: "<<b<<endl;
					for(set<Point>::iterator it = used_point.begin(); it != used_point.end(); it++){
						board[(*it).x][(*it).y] = b ? 'X': 'a';
					}
				}
			}
		}
		for(int i = 0; i < height; i++){
			for(int k = 0; k < width; k++){
				if(board[i][k] == 'a'){
					board[i][k] = 'O';
				}
			}
		}
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<char> line(4, 'X');
	vector<vector<char>> board(4, line);
	board[1][1] = 'O';
	board[1][2] = 'O';
	board[2][2] = 'O';
	board[3][1] = 'O';
	cout<<"before:======="<<endl;
	print_board(board);
	s.solve(board);
	cout<<"after:======="<<endl;
	print_board(board);
    return 0;
}
