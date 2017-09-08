#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

int get_mid(int s, int e){ return s + (e-s)/2; }

void update_value_utils(int st[], int ss, int se, int idx, int diff, int si){
	if(idx<ss || idx>se) return;

	st[si]=st[si]+diff;
	if(ss!=se){
		int mid=get_mid(ss,se);
		update_value_utils(st, ss, mid, idx, diff, 2*si+1);
		update_value_utils(st, mid+1, se, idx, diff, 2*si+2);
	}
}

void update_value(int arr[], int st[], int n, int idx, int value){
	if(idx<0 || idx > n-1){
		cout<<"Invaild input"<<endl;
		return;
	}
	int diff=value-arr[idx];
	arr[idx]=value;
	update_value_utils(st, 0, n-1, idx, diff, 0);
}



int get_sum_utils(int st[], int ss, int se, int qs, int qe, int si){
	if(qs<=ss && qe>=se){
		return st[si];
	}
	if(se<qs || ss>qe){
		return 0;
	}
	int mid= get_mid(ss,se);
	return get_sum_utils(st, ss, mid, qs, qe, 2*si+1) + get_sum_utils(st, mid+1, se, qs, qe, 2*si+2);
}

int get_sum(int st[], int n, int qs, int qe){
	if(qs<0 || qe>=n || qs>qe){
		cout<<"Invaild range"<<endl;
		return -1;
	}
	return get_sum_utils(st, 0, n-1, qs, qe, 0);
}


int construct_segement_tree_utils(int arr[], int ss, int se, int st[], int si){
	if(ss==se){
		st[si]=arr[ss];
		return arr[ss];
	}
	int mid= get_mid(ss,se);
	st[si]=construct_segement_tree_utils(arr, ss, mid, st, 2*si+1) +
			construct_segement_tree_utils(arr, mid+1, se, st, 2*si+2);
	return st[si];
}

int* construct_segement_tree(int arr[], int n){
	int height=(int)(ceil(log2(n)));
	int max_size=2*(int)pow(2,height) - 1;
	int *st=new int[max_size];

	construct_segement_tree_utils(arr, 0, n-1, st, 0);
	return st;
}


int main(){
	int arr[]={0,3,5,7,9,11};
	int n=sizeof(arr)/sizeof(arr[0]);
	int *st=construct_segement_tree(arr,n);
	cout<<"sum range between 1 and 2: "<<get_sum(st, n, 1, 2)<<endl;
	update_value(arr, st, n, 1, 10);
	cout<<"sum range between 1 and 2: "<<get_sum(st, n, 1, 2)<<endl;
	return 0;
}