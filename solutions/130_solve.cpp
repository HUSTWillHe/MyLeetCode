#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;
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
		if(p.x == 0 || p.x == board.size() || p.y == 0 || p.y == board[0].size()){
			board[p.x][p.y] = 'a';
			return false;
		}
		bool ans = true;
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				Point new_p = Point(p.x + pow(-1, i), p.y + pow(-1, j));
				if(used_point.find(new_p) == used_point.end()){
					used_point.insert(new_p);
					ans &= is_surround(board, new_p, used_point);
				}
			}
		}
		if(ans)
			board[p.x][p.y] = 'X';
		else
			board[p.x][p.y] = 'a';
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
					set<Point> used_point;
					is_surround(board, Point(i, j), used_point);
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
	board[0][2] = 'O';
	board[1][2] = 'O';
	board[1][1] = 'O';
	s.solve(board);
	for(auto line: board){
		for(auto c : line){
			cout<<c<<'\t';
		}
		cout<<endl;
	}
    return 0;
}
