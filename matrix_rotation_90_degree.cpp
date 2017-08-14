#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

void rotate_90_degree(vector< vector<int> > &matrix,int n,int m){
	int first,last;
	for(int layer=0;layer<n/2;++layer){
		first=layer;
		last=n-1-layer;
		for(int i=first;i<last;++i){
			int offset= i-first;
			int top=matrix[first][i];
			matrix[first][i]=matrix[last-offset][first];
			matrix[last-offset][first]=matrix[last][last-offset];
			matrix[last][last-offset]=matrix[first+offset][last];
			matrix[first+offset][last]=top;
		}
	}
}

int main(){

	cout<<"enter the size of matrix"<<endl;
	int n,m;
	cin>>m>>n;
	//int matrix[m][n];
	vector< vector<int> > matrix(m,vector<int>(n));
	cout<<"enter the elements of the matrix"<<endl;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cin>>matrix[i][j];
		}
	}

	rotate_90_degree(matrix,n,m);
	cout<<endl;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cout<<matrix[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;

	return 0;
}