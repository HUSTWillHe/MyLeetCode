#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3){
		if(s1.size() == 0)
			return s2 == s3;
		if(s2.size() == 0)
			return s1 == s3;
		if(s1.size() + s2.size() != s3.size())
			return false;
		int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
		vector<vector<bool>> vvb;
		for(int i = 0; i < l1 + 1; i ++){
			vvb.push_back(vector<bool>(l2 + 1, false));
		}
		vvb[0][0] = true;
		for(int i = 1; i < l1 + 1; i++){
			if(!vvb[i - 1][0])
				vvb[i][0] = false;
			else if(s1[i - 1] == s3[i - 1]){
				vvb[i][0] = true;
			}else{ vvb[i][0] = false;
			}
		}
		for(int i = 1; i < l2 + 1; i++){
			if(! vvb[0][i - 1]){
				vvb[0][i] = false;
			}else if(s2[i - 1] == s3[i - 1]){
				vvb[0][i] = true;
			}else{
				vvb[0][i] = false;
			}
		}
		for(int i = 1; i < l1 + 1; i ++){
			for(int k = 1; k < l2 + 1; k++){
				if(vvb[i - 1][k] == false && vvb[i][k - 1] == false){
					vvb[i][k] =  false;
				}else if(vvb[i - 1][k] == true && vvb[i][k - 1] == false){
					vvb[i][k] = s1[i - 1] == s3[i + k - 1];
				}else if(vvb[i - 1][k] == false && vvb[i][k - 1] == true){
					vvb[i][k] = s2[k - 1] == s3[i + k - 1];
				}else{
					vvb[i][k] = (s1[i - 1] == s3[i + k - 1])||(s2[k - 1] == s3[i + k - 1]);
				}
			}
		}
//		cout<<"THE ANSWER"<<endl;
//		cout<<s3<<endl;
//		cout<<"\t"<<'\t';
//		for(auto a: s2){
//			cout<<a<<'\t';
//		}
//		cout<<endl;
//		int idx = 0;
//		for(auto vb: vvb){
//			if(idx == 0)
//				cout<<'\t';
//			else
//				cout<<s1[idx - 1]<<'\t';
//			idx ++;
//			for(auto b: vb){
//				cout<<boolalpha<<b<<'\t';
//			}
//			cout<<endl;
//		}

		return vvb[l1][l2];
	}
};

int main(int argc,char** argv){
	Solution s;
	bool ans = s.isInterleave("aabcc", "dbbca", "aadbbcbcac");
	cout<<"ans: "<<ans<<endl;
    return 0;
}
