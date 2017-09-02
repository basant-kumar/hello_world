#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

void swap(int *x, int *y){
	int *temp=x;
	x=y; y=temp;
}


int* partition(int arr[], int start, int end){
	int pivot=arr[end];
	int j=start;
	
	for(int i=start;i<end;++i){
		if(arr[i]<=pivot){
			swap(arr[i],arr[j]);
			j++;
		}
	}
	swap(arr[j],arr[end]);

	return (arr+j);
	
}


int *median_of_three(int * a, int * b, int * c){
    if (*a < *b && *b < *c)
        return (b);
 
    if (*a < *c && *c <= *b)
        return (c);
 
    if (*b <= *a && *a < *c)
        return (a);
 
    if (*b < *c && *c <= *a)
        return (c);
 
    if (*c <= *a && *a < *b)
        return (a);
 
    if (*c <= *b && *b <= *c)
        return (b);
}

void insertion_sort(int arr[], int *begin, int *end){
	int left=begin-arr;
	int right=end-arr;

	for(int i=left+1;i<=right;++i){
		int key=arr[i];
		int j=i-1;

		while(j>=left && arr[j]>key){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
}

void introsort_utils(int arr[], int *begin, int *end, int depth_limit){

	int size=end-begin;

	if(size < 16){
		insertion_sort(arr, begin, end);
		return;
	}
	if(depth_limit==0){
		make_heap(begin, end+1);
		sort_heap(begin, end+1);
		return;
	}

	int *pivot=median_of_three(begin, begin+size/2, end);

	swap(pivot, end);

	int *partition_point=partition(arr, begin-arr, end-arr);
	introsort_utils(arr, begin, partition_point-1, depth_limit-1);
	introsort_utils(arr, partition_point+1, end, depth_limit-1);
}


void introsort(int arr[], int *begin, int *end){
	int depth_limit= 2*log(end-begin);

	introsort_utils(arr, begin, end, depth_limit);
}

void print(int arr[], int begin, int end){
	for(int i=begin;i<end;++i){
		cout<<arr[i]<<" ";
	}cout<<endl;
}


int main(){

	int arr[] = {3, 1, 23, -9, 233, 23, -313, 32, -9};
    int n = sizeof(arr) / sizeof(arr[0]);

    introsort(arr, arr, arr+n-1);
    print(arr, 0, n);

	return 0;
}