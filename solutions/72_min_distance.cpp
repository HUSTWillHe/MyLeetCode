#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void printAns(const string& word1, const string& word2, const vector<vector<int>> vvi){
		int len1 = word1.size();
		int len2 = word2.size();
		cout<<'\t';
		cout<<"\"\""<<'\t';
		for(auto a: word2)
			cout<<a<<'\t';
		cout<<endl;
		for(int i = 0; i < len1 + 1; i++){
			if(i == 0)
				cout<<"\"\""<<'\t';
			else
				cout<<word1[i - 1]<<'\t';
			for(int k = 0; k < len2 + 1; k++){
				cout<<vvi[i][k]<<'\t';
			}
			cout<<endl;
		}
	}

	int minDistance(string word1, string word2){
		int len1 = word1.size();
		int len2 = word2.size();
		vector<int> vi(len2 + 1, 0);
		vector<vector<int>> vvi(len1 + 1, vi);
		cout<<"after init"<<endl;
		printAns(word1, word2, vvi);
		for(int i = 0; i < len1 + 1; i++){
			vvi[i][0] = i;
		}
		for(int i = 0; i < len2 + 1; i++){
			vvi[0][i] = i;
		}
		cout<<"before action: "<<endl;
		printAns(word1, word2, vvi);

		for(int i = 1; i < len1 + 1; i++){
			for(int k  = 1; k < len2 + 1; k++){
				if(word1[i - 1] == word2[k - 1]){
					vvi[i][k] = vvi[i - 1][k - 1];
				}else{
					vvi[i][k] = min(min(vvi[i - 1][k - 1], vvi[i - 1][k]), vvi[i][k - 1]) + 1;
				}
			}
		}

		cout<<"ANSWER: "<<endl;
		printAns(word1, word2, vvi);
		return vvi[len1][len2];
	}
};

int main(int argc,char** argv){
	Solution s;
	cout<<"argc: "<<argc<<endl;
	
	string s1 = argv[1];
	string s2 = argv[2];
	int ans = s.minDistance(s1, s2);
    return 0;
}
