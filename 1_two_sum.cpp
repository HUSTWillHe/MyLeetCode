#include <iostream>
#include <vector>
using namespace std;

int recursion(int begin, int end, vector<int> nums, int target){
    cout<<"recurdion"<<endl;
    int rst = -1;
    if(end < begin) return rst;
    if(nums[begin] > target || nums[end] < target)
        return rst;
    if(begin == end){
        if(nums[end] == target)
            return end;
        else
            return rst;
    }
    int mid = end + begin;
    mid /= 2;
    if(nums[mid] > target)
        return recursion(begin, mid, nums, target);
    else if(nums[mid] < target)
        return recursion(mid, end, nums, target);
    else return mid;
}

/**
 * find two numbers add to target;
 * 思路是先排序，然后从小到大找合适的，时间复杂度为O(n log (n))
 */
vector<int> twoSum(vector<int>& nums, int target){
    vector<int> rst;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size() - 1; i++){
        cout<<"cycle: "<< i <<endl;
        int suit = recursion(i + 1, nums.size()-1, nums, target - nums[i]);
        if(suit != -1){
            rst.push_back(nums[i]);
            rst.push_back(nums[suit]);
        }
    }
    return rst;
}
int main(){
    int inpArr[] = {1, 7, 11, 15};
    int target = 22;
    vector<int> inp(inpArr, inpArr + sizeof(inpArr) / sizeof(inpArr[0]));
    vector<int> rst;
    //rst = twoSum(inp, target);
    cout << recursion(0, 3, inp, 10);
    for(auto a : rst)
        cout<< a << endl;
    return 0;
}
