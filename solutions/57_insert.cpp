#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

class Solution {
public:
	/**
	* @return 返回新区间在原始区间中的位置，整形表示在第几个元素的前面或者中间，如果布尔值为真，表示在此元素之前，否则表示落在此元素中间
	**/
	vector<pair<int, bool>>findIndex(vector<vector<int>>& intervals, vector<int>& newInterval){
		vector<pair<int, bool>> result;
		int size = intervals.size();
		int i;
		for(i = 0; i < size; i++){
			if(intervals[i][0] > newInterval[0]){
				result.push_back(pair<int, bool>(i, true));
				break;
			}else if(intervals[i][1] > newInterval[0]){
				result.push_back(pair<int, bool>(i, false));
				break;
			}
		}
		for(int k = i; k < size; k++){
			if(intervals[k][0] > newInterval[1]){
				result.push_back(pair<int, bool>(k, true));
				break;
			}else if(intervals[k][1] > newInterval[1]){
				result.push_back(pair<int, bool>(k, false));
				break;
			}
		}
		if(result.empty()){
			result.push_back(pair<int, bool>(size, true));
			result.push_back(pair<int, bool>(size, true));
		}
		if(result.size() == 1){
			result.push_back(pair<int, bool>(size, true));
		}
		return result;
	}

	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
		int size = intervals.size();
		if(intervals.size() == 0){
			return vector<vector<int>>{newInterval};
		}
		vector<pair<int, bool>> position = findIndex(intervals, newInterval);

		cout<<"position:\n begin index: "<<position[0].first<<" front or mid: "<<position[0].second<<"\nend index: "<<position[1].first<<" front or mid: "<<position[1].second<<endl;;

		vector<vector<int>> result;
		if(position[0].first == size){
			//边界条件，newInterval在intervals所有值的后面
			result = vector<vector<int>>(intervals.begin(), intervals.end());
			result.push_back(newInterval);
			return result;
		}else if(position[0].first == position[1].first){
			//newInterval左右边界与一个值有关
			if(position[0].second == position[1].second && position[0].second == true){
				result = vector<vector<int>>(intervals.begin(), intervals.end());
				result.insert(intervals.begin() + position[0].first, newInterval);
				return result;
			}else{
				if(position[0].second == false){
					return intervals;
				}else{
					result = vector<vector<int>>(intervals.begin(), intervals.end());
					vector<int> merge_two{newInterval[0], intervals[position[0].first][1]};
					result[position[0].first] = merge_two;
					return result;
				}
			}
		}else{
			//newInterval与多个值有关
			//result.reserve(size + 1);
			result.insert(result.end(), intervals.begin(), intervals.begin() + position[0].first);
			//copy(intervals.begin(), intervals.begin() + position[0].first, result.begin());
			cout<<"head copy"<<endl;
			for(auto a: result){
				cout<<a[0]<<'\t'<<a[1]<<endl;
			}
			int left, right;
			if(position[0].second == true){
				left = newInterval[0];
			}else{
				left = intervals[position[0].first][0];
			}
			if(position[1].second == true){
				right = newInterval[1];
			}else{
				right = intervals[position[1].first][1];
			}
			vector<int> merge_some{left, right};
			cout<<"merge info: "<<left<<", "<<right<<endl;
			result.push_back(merge_some);
			if(position[1].second){
				result.insert(result.end(), intervals.begin() + position[1].first, intervals.end());
				//copy(intervals.begin() + position[1].first, intervals.end(), result.end() - 1);
			}else{
				result.insert(result.end(), intervals.begin() + position[1].first + 1, intervals.end());
				//copy(intervals.begin() + position[1].first + 1, intervals.end(), result.end() - 1);
			}
			cout<<"tail copyed"<<endl;
			for(auto a: result){
				cout<<a[0]<<' '<<a[1]<<endl;;
			}
			return result;
		}
		
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> v{3, 7};
	vector<vector<int>> vv{{1,2},{3,4},{5,6},{7,8},{9, 10}};
	vector<vector<int>> result = s.insert(vv, v);
	cout<<"the result: "<<endl;
	cout<<"result size: "<<result.size()<<endl;
	for(auto a: result){
		for(auto b: a){
			cout<<b<<'\t';
		}
		cout<<endl;
	}
    return 0;
}
