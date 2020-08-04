#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
	void RadixSort(vector<int>& nums){
		int exp = 1;
		int size = nums.size();
		int max_val = *max_element(nums.begin(), nums.end());
		vector<int> aux(size);
		while(max_val / exp > 0){
			vector<int> count(10);
			// 计算每尾数包含的个数
			for(int i = 0; i < size; i++){
				count[(nums[i]/exp) % 10] ++;
			}
			// 计算小于或等于这个尾数的个数
			for(int i = 1; i < 10; i++){
				count[i] += count[i - 1];
			}
			// aux的对应值获取那个值
			for(int i = size - 1; i >= 0; i--){
				aux[--count[(nums[i]/exp)%10]] = nums[i];
			}
			// 将aux的值给nums
			for(int i = 0; i < size; i++){
				nums[i] = aux[i];
			}
			exp *= 10;
		}
	}

public:
	int maximumGap(vector<int>& nums){
		int size = nums.size();
		if(size < 2)
			return 0;
		RadixSort(nums);
		int maxGap = 0;
		for(int i = 1; i < size; i++){
			maxGap = max(nums[i] - nums[i - 1], maxGap);
			cout<<nums[i]<<endl;
		}
		return maxGap;

	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> nums {15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740};
	int ans = s.maximumGap(nums);
	cout<<"ans"<<ans<<endl;
    return 0;
}
