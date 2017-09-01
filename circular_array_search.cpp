#include<iostream>

using namespace std;

int circular_array_search(int arr[], int n, int k){
	int low=0, high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]==k){
			return mid;
		}
		if(arr[mid]<=arr[high]){
			if(arr[mid] > k && arr[high]<=k){
				low=mid+1;
			}
			else{
				high=mid-1;
			}
		}
		if(arr[low]<=arr[mid]){
			if(arr[low]>=k && arr[mid]<k){
				high=mid-1;
			}
			else{
				low=mid+1;
			}
		}
	}
	return -1;
}


void find_element(int arr[], int n, int k){
	int res=circular_array_search(arr, n, k);
	if(res!=-1){
		cout<<"Found "<<k<<" at "<<res+1<<" position"<<endl;
	}
	else{
		cout<<"element not found"<<endl;
	}
}	

int main(){

	int arr[8]={5,6,7,8,1,2,3,4};
	find_element(arr, 8, 8);
}