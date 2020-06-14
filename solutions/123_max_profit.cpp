#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& price){
		int size = price.size();
		int days = 0;
		if(size < 2){
			return 0;
		}else if(size < 4){
			days = size;
		}else{
			days = 4;
		}
		vector<int> profit(size, 0);
		vector<vector<int>> days_profit(4, profit);
		int current_max = 0;
		int last_line_max = 0;
		for(int i = 0; i < days; i++){
			if(i == 0){
				last_line_max = 0;
			}
			else{
				last_line_max = days_profit[i - 1][i - 1];
			}
			for(int k = i; k < size; k++){
				if(i != 0){
					if(days_profit[i - 1][k - 1] > last_line_max){
						last_line_max = days_profit[i - 1][k - 1];
					}
				}
				if(i % 2 == 0){
					days_profit[i][k] = last_line_max - price[k];
				}else{
					days_profit[i][k] = last_line_max + price[k];
					if(days_profit[i][k] > current_max){
						current_max = days_profit[i][k];
					}
				}
			}
		}
		return current_max;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> price{3, 3, 5, 0, 0, 3, 1, 4};
	int max_profit =  s.maxProfit(price);
	cout<<"max_profit"<<max_profit<<endl;
    return 0;
}
