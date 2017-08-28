#include<iostream>

using namespace std;

int get_max(int arr[], int n){
	int max=arr[0];
	for(int i=1;i<n;++i){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}

void count_sort(int arr[], int n, int exp){
	int output[n];
	int i, count[10]={0};

	for(int i=0;i<n;++i){
		count[(arr[i]/exp)%10]++;
	}

	for(int i=1;i<10;++i){
		count[i]+=count[i-1];
	}

	for(int i=n-1;i>=0;--i){
		output[ count[(arr[i]/exp)%10] - 1 ]=arr[i];
		count[(arr[i]/exp)%10]--;
	}

	for(int i=0;i<n;++i){
		arr[i]=output[i];
	}
}


void radix_sort(int arr[], int n){
	int m= get_max(arr, n);

	for(int i=1; m/i >0 ; i*=10){
		count_sort(arr, n, i);
	}
}

void print(int arr[], int n){
	for(int i=0;i<n;++i){
		cout<<arr[i]<<" ";
	}cout<<endl;
}

int main(){

	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radix_sort(arr, n);
    print(arr, n);

	return 0;
}