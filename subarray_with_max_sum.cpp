#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

int subarray_with_max_sum(vector<int> &arr){
	int max_sum=arr[0];
	int curr_max=arr[0];
	for(int i=1;i<arr.size();++i){
		curr_max=max(arr[i],curr_max+arr[i]);
		max_sum=max(max_sum,curr_max);
	}
	return max_sum;
}

int main(){
	int n;
	cout<<"Enter the size of the array"<<endl;
	cin>>n;
	vector<int> arr(n);
	cout<<"Enter the elements of the array"<<endl;
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}

	cout<<"Max sum is "<<subarray_with_max_sum(arr)<<endl;
	return 0;
}