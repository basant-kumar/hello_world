#include<iostream>
#include<cstring>

using namespace std;

void construct_lps_array(char* pat, int m, int *lps){
	int len=0;
	lps[0]=0;
	
	int i=1;
	while(i<m){
		if(pat[i]==pat[len]){
			len++;
			lps[i]=len;
			i++;
		}
		else{
			if(len!=0){
				len=lps[len-1];
			}
			else{
				lps[i]=0;
				i++;
			}
		}
	}
}

void kmp_search(char *txt, char *pat){
	int n=strlen(txt);
	int m=strlen(pat);
	int lps[m];

	construct_lps_array(pat, m, lps);
	int i=0,j=0;

	while(i<n){
		if(txt[i]==pat[j]){
			i++;
			j++;
		}
		if(j==m){
			cout<<"Pattern found at index: "<<i-j<<endl;
			j=lps[j-1];
		}
		else if(i<n && txt[i]!=pat[j]){
			if(j!=0){
				j=lps[j-1];
			}
			else{
				i++;
			}
		}
	}
}

int main(){
	char *txt = "AAAAAAA";
    char *pat = "AAAA";
    kmp_search(txt, pat);
	return 0;
}