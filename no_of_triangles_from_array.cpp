#include<iostream>
#include<algorithm>

using namespace std;

int no_triangles(vector<int> &arr){
	int n=arr.size();
	sort(arr.begin(),arr.end());

	int cnt=0,k;

	for(int i=0;i<n-2;++i){
		k=i+2;
		for(int j=i+1;j<n-1;++j){
			while(k<n && arr[i]+arr[j] > arr[k]){
				k++;
			}
			cnt+=(k-j-1);
		}
	}
	return cnt;
}

int main(){
    int n=7;
    vector<int> arr(7);
    arr={10, 21, 22, 100, 101, 200, 300};

    cout<<"No of Triangles possible: "<<no_triangles(arr)<<endl;

	return 0;
}