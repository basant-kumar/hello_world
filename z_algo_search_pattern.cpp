#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

void z_array(char *str, int Z[]){
	int i, L=0,R=0,k;
	int n=strlen(str);
	for(i=1;i<n;++i){
		if(i>R){
			L=R=i;

			while(R<n && str[R-L]==str[R])
				R++;
			Z[i]=R-L;
			R--;
		}
		else{
			k=i-L;
			if(Z[k]<R-i+1){
				Z[i]=Z[k];
			}
			else{
				L=i;
				while(R<n && str[R-L]==str[R])
					R++;
				Z[i]=R-L;
				R--;
			}

		}
	}
}


void z_search(char* txt, char* pat){
	int n=strlen(txt);
	int m=strlen(pat);
	char *concate=(char*)malloc(sizeof(char)*(n+m+2));
	strcpy(concate,pat);
	strcat(concate,"$");
	strcat(concate,txt);
	int l=strlen(concate);
	int Z[l];
	z_array(concate,Z);

	for(int i=0;i<l;++i){
		if(Z[i]==m){
			cout<<"pattern found at index: "<<i-m-1<<endl;
		}
	}

}

int main(){
	char *txt = "AAAAAAA";
    char *pat = "AAAA";
    z_search(txt, pat);
	return 0;
}