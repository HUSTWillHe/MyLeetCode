#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	public:
		int candy(vector<int>& ratings){
			int size = ratings.size();
			if(size == 0)
				return 0;
			vector<int> forward(size, 0);
			vector<int> backward(size, 0);
			for(int i = 0, j = size - 1; i < size, j >= 0; i ++, j --){
				if(i == 0){
					forward[0] = 1;
				}else{
					if(ratings[i] > ratings[i - 1]){
						forward[i] = forward[i - 1] + 1;
					}else{
						forward[i] = 1;
					}
				}
				if(j==size - 1){
					backward[j] = 1;
				}else{
					if(ratings[j] > ratings[j + 1]){
						backward[j] = backward[j + 1] + 1;
					}else{
						backward[j] = 1;
					}
				}
			}
			cout<<"forward"<<endl;
			for(auto a: forward)
				cout<<a<<'\t';
			cout<<endl;
			cout<<"backward"<<endl;
			for(auto a: backward)
				cout<<a<<'\t';
			cout<<endl;
			int sum = 0;
			for(int i = 0; i < size; i++){
				sum += forward[i] > backward[i] ? forward[i] : backward[i];
			}
			return sum;
		}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> ratings{1, 3, 5, 4, 3, 2, 1, 7};
	int ans = s.candy(ratings);
	cout<<"ans is: "<<ans<<endl;
    return 0;
}
