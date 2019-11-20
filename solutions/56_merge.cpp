#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isIndependent(const vector<int>& v1, const vector<int>& v2){
		assert(v1.size() == 2 && v2.size() == 2);
		assert(v1[1] >= v1[0] && v2[1] >= v2[0]);
		if(v1[1] < v2[0] || v1[0] > v2[1])
			return true;
		return false;
	}

	static bool sort_function(const vector<int>& v1, const vector<int>& v2){
		return v1[0] < v2[0];
	}

	vector<int> merge_two(vector<int> v1, vector<int> v2){
		int begin = min(v1[0], v2[0]);
		int end = max(v1[1], v2[1]);
		vector<int> result{begin, end};
		return result;
	}

	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if(intervals.size() == 0){
			return vector<vector<int>>();
		}
		sort(intervals.begin(), intervals.end(), sort_function);
		vector<vector<int>> result;
		result.push_back(intervals[0]);
		int index = 1;
		while(index < intervals.size()){
			if(isIndependent(*(result.end() - 1), intervals[index])){
				result.push_back(intervals[index]);
			}else{
				vector<int> merged = merge_two(*(result.end() - 1), intervals[index]);
				result.pop_back();
				result.push_back(merged);
			}
			index ++;
		}
		return result;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<vector<int>> vvi{{0, 30}, {1, 4}, {4, 5}, {8,9}, {7, 10}};
	vector<vector<int>> result = s.merge(vvi);
	for(auto a: result){
		for(auto b: a){
			cout<<b<<'\t';
		}
		cout<<endl;
	}
    return 0;
}
