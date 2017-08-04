#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> &arr,int n,int d){
    /*  time complexity O(n)
        spcae complexity O(1)
    */
    int first=a[0], i=0, index;
    while(1) {
        index = (i+d)%n;
        if(!index) {
            a[i] = first;
            break;
        }
        a[i] = a[index];
        i = index;
    }
    
    
}

int main() {
    int n,d;
    cin>>n>>d;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    rotate(arr,n,d);
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }cout<<endl;
	return 0;
}