#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
	map<int, map<int, int>> points_cnt;
	map<double, map<double, set<vector<int>>>> storage;
	map<int, set<int>> vertical;
	
	void cntPoints(vector<vector<int>>& points){
		for(auto point : points){
			if(points_cnt.find(point[0]) == points_cnt.end()){
				points_cnt[point[0]] = map<int, int>{{point[1], 1}};
			}else{
				if(points_cnt[point[0]].find(point[1]) == points_cnt[point[0]].end()){
					points_cnt[point[0]][point[1]] = 1;
				}else{
					points_cnt[point[0]][point[1]] ++;
				}
			}
		}
	}

	void getSlope(vector<int> a, vector<int> b){
		cout<<"--------------"<<endl;
		cout<<a[0]<<" "<<a[1]<<"\t"<<b[0]<<" "<<b[1]<<endl;
		if(b[0] == a[0]){
			if (vertical.find(a[0]) == vertical.end()){
				vertical[a[0]] = set<int> {a[1], b[1]};
			}else{
				vertical[a[0]].insert(a[1]);
				vertical[a[0]].insert(b[1]);
			}
		}else{
			double slope = double(b[1] - a[1])/double(b[0] - a[0]);
			double height = double(a[1]*b[0] - a[0]*b[1])/double(b[0] - a[0]);
			cout<<"slope"<<slope<<"  height: "<<height<<endl;
			if(storage.find(slope) == storage.end()){
				map<double, set<vector<int>>> temp;
				temp[height] = set<vector<int>>{a, b};
				storage[slope] = temp;
			}else{
				if(storage[slope].find(height) == storage[slope].end()){
					storage[slope][height] = set<vector<int>>{a, b};

				}else{
					storage[slope][height].insert(a);
					storage[slope][height].insert(b);
				}
			}
			cout<<"size: "<<storage[slope][height].size()<<endl;
		}
	}

	int maxPoints(vector<vector<int>>& points){
		int size = points.size();
		if(size <= 1)
			return size;
		cntPoints(points);
		cout<<"points count"<<endl;
		for(auto x_y: points_cnt){
			for(auto y_cnt: x_y.second){
				cout<<x_y.first<<"  "<<y_cnt.first<<" : "<<y_cnt.second<<endl;
			}
		}
		for(int i = 0; i < size; i++){
			for(int k = i + 1; k < size; k++){
				getSlope(points[i], points[k]);
			}
		}

		int max = 2;
		for(auto x_ys: vertical){
			//int s = m.second.size();
			int sum = 0;
			for(auto y: x_ys.second){
				sum += points_cnt[x_ys.first][y];
			}
			if(sum > max)
				max = sum;
		}
		for(auto slope_heightMap: storage){
			cout<<"slope: "<<slope_heightMap.first<<endl;
			for(auto height_pointSet: slope_heightMap.second){
				cout<<"height: "<<height_pointSet.first<<endl;
				int sum = 0;
				for(auto point: height_pointSet.second){
					cout<<point[0]<<" "<<point[1]<<endl;
					sum += points_cnt[point[0]][point[1]];
				}
				cout<<"cnt: "<<sum<<endl;
				if(sum > max)
					max = sum;
			}
		}
		return max;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<vector<int>> points{vector<int>{0, 0}, vector<int>{94911151,94911150}, vector<int>{94911152,94911151}};
	int ans = s.maxPoints(points);
	cout<<"ans: "<<ans<<endl;
    return 0;
}
