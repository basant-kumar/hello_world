#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

int get_sum(int bit[], int index){
	index+=1;
	int sum=0;
	while(index>0){
		sum+=bit[index];
		index-= index & (-index);
	}
	return sum;
}

void update_bit(int bit[], int n, int index, int value){
	index=index+1;
	while(index<=n){
		bit[index]+=value;
		index+= index &(-index);
	}
}

int * construct_binary_index_tree(int arr[], int n){
	int *bit=new int[n+1];
	for(int i=0;i<n+1;++i){
		bit[i]=0;
	}
	for(int i=0;i<n;++i){
		update_bit(bit, n, i, arr[i]);
	}
	return bit;
}


int main(){
	int arr[]={0,3,5,7,9,11};
	int n=sizeof(arr)/sizeof(arr[0]);
	int *bit=construct_binary_index_tree(arr,n);
	cout<<"sum range between 1 and 2: "<<get_sum(bit, 2)<<endl;
	update_bit(bit, n, 0, 10);
	cout<<"sum range between 1 and 2: "<<get_sum(bit, 2)<<endl;
	return 0;
}