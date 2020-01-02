#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b){
		int size_a = a.size();
		int size_b = b.size();
		if(size_a == 0 && size_b == 0)
			return "";
		if(size_a == 0)
			return b;
		if(size_b == 0)
			return a;
		if(size_a > size_b){
			b = string(size_a - size_b, '0') + b; 
		}else{
			a = string(size_b - size_a, '0') + a;
		}
		bool flag = false;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		cout<<"after reverse a: "<<a<<" b: "<<b<<endl;
		string ans = "";
		for(int i = 0; i < a.size(); i++){
			if(flag){
				if(a[i] == '1' && b[i] == '1'){
					ans += '1';
					flag = true;
				}else if(a[i] == '1' || b[i] == '1'){
					ans += '0';
					flag = true;
				}else{
					ans += '1';
					flag = false;
				}
			}else{
				if(a[i] == '1' && b[i] == '1'){
					ans += '0';
					flag = true;
				}else if(a[i] == '1' || b[i] == '1'){
					ans += '1';
					flag = false;
				}else{
					ans += '0';
					flag = false;
				}
			}
		}
		if(flag)
			ans += '1';
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main(int argc,char** argv){
	Solution s;
	string a = "101", b = "100";
	string c = s.addBinary(a, b);
    return 0;
}
