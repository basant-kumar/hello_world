#include<iostream>
#include<cstring>
#define d 256
using namespace std;

void rabin_karp_search(char* txt, char* pat, int q){
	int t=0, p=0, h=1,j;
	int n=strlen(txt);
	int m=strlen(pat);
	
	for(int i=0;i<m-1;++i){
		h=(h*d)%q;
	}	
	for(int i=0;i<m;++i){
		p=(d*p + pat[i])%q;
		t=(d*t + txt[i])%q;
	}
	for(int i=0;i<=n-m;++i){
		if(p==t){
			for(j=0;j<m;++j){
				if(pat[j]!=txt[i+j]){
					break;
				}
			}
			if(j==m){
				cout<<"pattern found at index: "<<i<<endl;
			}
		}
		if(i<n-m){
			t=(d*(t - txt[i]*h) + txt[i+m])%q;
			if(t<0){
				t=t+q;
			}
		}
	}
}

int main(){
	char *txt = "AAAAAAA";
    char *pat = "AAAA";
    rabin_karp_search(txt, pat, 11);
	return 0;
}