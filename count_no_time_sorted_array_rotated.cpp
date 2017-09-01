#include<iostream>

using namespace std;

int get_start_index_of_the_sorted_rotated_array(int arr[], int n){
	int low=0, high=n-1;

	
	while(low<=high){
		if(arr[low]<=arr[high]){
			return low;
		}
		int mid=(low+high)/2;
		int next=(mid+1)%n, prev=(mid+n-1)%n;
		if(arr[mid]<=arr[next] && arr[mid]<=arr[prev]){
			return mid;
		}
		else if(arr[mid]<=arr[high]){
			high=mid-1;
		}
		else if(arr[low]<=arr[mid]){
			low=mid+1;
		}
	}

}


int count_no_of_rotations(int arr[], int n){
	return get_start_index_of_the_sorted_rotated_array(arr, n)+1;
}


int main(){

	int arr[8]={5,6,7,8,1,2,3,4};
	cout<<"No of rotations: "<<count_no_of_rotations(arr, 8)<<endl;
}