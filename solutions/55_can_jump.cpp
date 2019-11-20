#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

class Solution {
private:
	vector<int> ori;
	deque<int> zeros;
public:
	void findZeros(){
		int size = ori.size();
		for(int i = 0; i < size; i++){
			if(ori[i] == 0){
				zeros.push_back(i);
			}
		}
	}

	int recursive(int left, int right, int cur){
		if(right == left + 1){
			return right;	
		}
		int mid = (left + right)/2;
		if(cur > zeros[mid]){
			return recursive(mid, right, cur);
		}else if(cur < zeros[mid]){
			return recursive(left, mid, cur);
		}else{
			return mid;
		}
	}

	int findIndex(int i){
		int size = zeros.size();
		if(i > zeros[size - 1])
			return size;
		if(i == zeros[size - 1])
			return size - 1;
		if(i <= zeros[0])
			return 0;
		return recursive(0, size - 1, i);
	}
	
	bool canJump(vector<int>& nums) {
		ori = nums;
		findZeros();
		if(zeros.empty())
			return true;
		int size = nums.size();
		if(size <= 1)
			return true;
		for(int i = 0; i < zeros[0]; i++){
			if(i + nums[i] > zeros[0]){
				int front = findIndex(i + nums[i]);
				for(int i = 0; i < front; i++)
					zeros.pop_front();
			}
		}
		if(zeros.empty())
			return true;
		else if(zeros.size() == 1 && zeros[0] == size - 1)
			return true;
		else
			return false;
	}
};

//void test_findIndex(){
//	deque<int> d{1, 2, 4, 6};
//	Solution s;
//	s.zeros = d;
//	int idx = s.findIndex(3);
//	cout<<"find idx: "<<idx<<endl;
//}

int main(int argc,char** argv){
	Solution s;
	//test_findIndex();
	vector<int> v{0};
	bool b = s.canJump(v);
	cout<<"result: "<<b<<endl;
    return 0;
}
