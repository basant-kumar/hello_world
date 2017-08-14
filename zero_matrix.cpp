#include<iostream>
#include<vector>

using namespace std;

void nullfy_row(vector< vector<int> > &matrix,int row,int n){
	for(int i=0;i<n;++i){
		matrix[row][i]=0;
	}
}

void nullfy_col(vector< vector<int> > &matrix,int col,int m){
	for(int i=0;i<m;++i){
		matrix[i][col]=0;
	}
}

void zero_matrix(vector< vector<int> > &matrix,int m, int n){

	int is_col_zero=0,is_row_zero=0;
	for(int i=0;i<m;++i){
		if(matrix[i][0]==0){
			is_col_zero=1;break;
		}
	}
	for(int i=0;i<n;++i){
		if(matrix[0][i]==0){
			is_row_zero=1;break;
		}
	}
	for(int i=1;i<m;++i){
		for(int j=1;j<n;++j){
			if(matrix[i][j]==0){
				matrix[i][0]=0;
				matrix[0][j]=0;
			}
		}
	}
	for(int i=0;i<m;++i){
		if(matrix[i][0]==0){
			nullfy_row(matrix,i,n);
		}
	}
	
	for(int i=0;i<n;++i){
		if(matrix[0][i]==0){
			nullfy_col(matrix,i,m);
		}
	}
	
	if(is_row_zero==1){
		nullfy_row(matrix,0,n);
	}

	if(is_col_zero==1){
		nullfy_col(matrix,0,m);
	}

}

int main(){

	cout<<"enter dimensions of the matrix"<<endl;
	int m,n;
	cin>>m>>n;
	vector< vector<int> > matrix(m,vector<int>(n));
	cout<<"enter the elements of the matrix"<<endl;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cin>>matrix[i][j];
		}
	}

	zero_matrix(matrix,m,n);

	cout<<endl;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cout<<matrix[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;

	return 0;
}