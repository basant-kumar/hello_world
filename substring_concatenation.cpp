/*
You are given a string, S, and a list of words, L, that are all of the same length. 
Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly 
once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

*/

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

vector<int> substring_concatenation(string &S, vector<string> &L){
	int n=S.size(), m=L.size();
	vector<int> res;
	if(n<=0 || m<=0) return res;

	unordered_map<string,int> hash;

	for(int i=0;i<m;++i) hash[L[i]]++;

	int wl=L[0].size();
	
	for(int i=0;i<wl;++i){
		int left=i, cnt=0;
		unordered_map<string, int> t_hash;
		for(int j=i;j<n-wl;j+=wl){
			string str=S.substr(j, wl);
			if(hash.count(str)){ // is present in hash
				t_hash[str]++;
				if(t_hash[str] <= hash[str]){
					cnt++;
				}
				else{

					while(t_hash[str]>hash[str]){
						string str1=S.substr(left, wl);
						t_hash[str1]--;
						if(t_hash[str1] < hash[str1]) cnt--;
						left+=wl;
					}
				}
				if(cnt==m){
					res.push_back(left);
					t_hash[S.substr(left,wl)]--;
					cnt--;
					left+=wl;
				}
			}
			else{
				t_hash.clear();
				cnt=0;
				left=j+wl;
			}
		}
	}
	return res;
}


int main(){

	string S="barfoothefoobarman";
	vector<string> L={"foo","bar"};
	vector<int> res;
	res=substring_concatenation(S,L);
	for(int i=0;i<res.size();++i){
		cout<<res[i]<<" ";
	}cout<<endl;

	return 0;
}