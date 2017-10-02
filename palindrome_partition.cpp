#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string str;
	    cin>>str;
	    int n=str.size();
	    int cost[n];
	    bool pali[n][n];
	    for(int i=0;i<n;++i){
	        pali[i][i]=true;
	    }
	    
	    for(int l=2;l<=n;++l){
	        for(int i=0;i<n-l+1;++i){
	            int j=i+l-1;
	            if(l==2){
	                pali[i][j] = (str[i]==str[j]);
	            }
	            else{
	                pali[i][j] = (str[i]==str[j]) && pali[i+1][j-1];
	            }
	        }
	    }
	    
	    for(int i=0;i<n;++i){
	            if(pali[0][i]){
	                cost[i]=0;
	            }
	            else{
	                cost[i]=INT_MAX;
	                for(int k=0;k<i;++k){
	                    if(pali[k+1][i]){
	                        cost[i]=min(cost[i], cost[k]+1);
	                    }
	                }
	            }
	   }
	    
	    cout<<cost[n-1]<<endl;
	}
	return 0;
}