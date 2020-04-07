#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

class Solution {
private:
public:
	bool isSelfCrossing(vector<int>& x){
		int size = x.size();
		if(size < 4)
			return false;
		if(size == 4)
			return x[0] >= x[2] && x[3] >= x[1];
		if(size == 5)
			return (x[0] >= x[2] && x[3] >= x[1]) || (x[1] >= x[3] && x[4] >= x[2]) || (x[1] == x[3] && x[0] + x[4] >= x[2]);
		for(int i = 5; i < size; i++){
			if((x[i - 3] >= x[i - 1] && x[i] >= x[i - 2]) || (x[i - 3] == x[i - 1] && x[i - 4] + x[i] >= x[i - 2]) || 
					(x[i - 2] > x[i - 4] && x[i - 2] > x[i] && x[i - 3] > x[i - 1] && x[i - 3] > x[i - 5] && x[i] + x[i - 4] >= x[i - 2] && x[i - 5] + x[i - 1] >= x[i - 3]))
				return true;
		}
		return false;
	}
};

int main(int argc,char** argv){
	Solution s;
	vector<int> vi{4, 4, 2, 2};
	bool ans = s.isSelfCrossing(vi);
	cout<<boolalpha<<ans<<endl;
    return 0;
}
