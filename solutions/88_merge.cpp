#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if(m == 0){
			nums1 = nums2;
			return;
		}
		if(n == 0)
			return;
		int i = 0, k = 0;
		vector<int> ans;
		while(i < m | k < n){
			if(i == m){
				ans.insert(ans.end(), nums2.begin() + k, nums2.begin() + n);
				break;
			}
			if(k == n){
				ans.insert(ans.end(), nums1.begin() + i, nums1.begin() + m);
				break;
			}
			if(nums1[i] < nums2[k]){
				ans.push_back(nums1[i]);
				i++;
			}else{
				ans.push_back(nums2[k]);
				k++;
			}
		}
		nums1 = ans;
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
