#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int size = nums1.size();
		if(m + n != size){
			return;
		}
		int i = m - 1, k = n - 1;
		while(1){
			if(k < 0)
				return;
			if(i < 0){
				for(int ii = 0; ii <= k; ii ++){
					nums1[ii] = nums2[ii];
				}
				return;
			}
			if(nums1[i] > nums2[k]){
				nums1[i + k + 1] = nums1[i];
				i--;
			}else{
				nums1[i + k + 1] = nums2[k];
				k--;
			}
		}
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> vi1 = {1, 5, 7, 0, 0, 0, 0};
	vector<int> vi2 = {2, 3, 6, 8};
	s.merge(vi1, 3, vi2, 4);
	for(auto a: vi1){
		cout<<a<<'\t';
	}
	cout<<endl;
    return 0;
}
