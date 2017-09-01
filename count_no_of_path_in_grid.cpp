#include<iostream>

using namespace std;

int count_paths(int m, int n){
	int dp[m][n];
	for(int i=0;i<m;++i){
		dp[i][0]=1;
	}
	for(int i=0;i<n;++i){
		dp[0][i]=1;
	}
	for(int i=1;i<m;++i){
		for(int j=1;j<n;++j){
			dp[i][j]=dp[i-1][j] + dp[j][i-1];
		}
	}
	return dp[m-1][n-1];
}

void print_all_paths_utils(int *mat, int i, int j, int m, int n, int *path, int idx){
	if(i==m-1){
		for(int k=j;k<n;++k){
			path[idx+k-j]=*((mat+i*n)+k);
		}
		for(int k=0;k<idx+n-j;++k){
			cout<<path[k]<<" ";
		}cout<<endl;
		return;
	}
	if(j==n-1){
		for(int k=i;k<m;++k){
			path[idx+k-i]=*((mat+k*n)+j);
		}
		for(int k=0;k<idx+m-i;++k){
			cout<<path[k]<<" ";
		}cout<<endl;
		return;
	}
	path[idx]=*((mat+i*n)+j);

	print_all_paths_utils(mat, i+1, j, m, n, path, idx+1);
	print_all_paths_utils(mat, i, j+1, m, n, path, idx+1);
}

void print_all_paths(int *mat, int m, int n){
	int *path=new int[m*n];
	print_all_paths_utils(mat, 0, 0, m, n, path, 0);
}

int main(){
	int m=3, n=3;
	int mat[m][n]={{1,2,3},{4,5,6},{7,8,9}};
	cout<<"No of paths: "<<count_paths(m,n)<<endl;
	print_all_paths(*mat,m,n);
	return 0;
}