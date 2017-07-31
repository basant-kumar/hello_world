/*  
    Best-case time complexity O(nlogn)
    Average-case time complexity O(nlogn)
    worst-case time complexity O(n^2)
    space complexity O(logn) ~ O(1)
    it is stable
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void swap(int *i,int *j){
    int temp=*i; *i=*j; *j=temp;
}

int partition(int *arr,int start,int end){
    int pivot=arr[end];
    int pindex=start;
    for(int i=start;i<end;++i){
        if(arr[i]<=pivot){
            swap(&arr[i],&arr[pindex]);
            pindex++;
        }
    }
    swap(&arr[pindex],&arr[end]);
    return pindex;
}

void quicksort(int *arr,int start, int end){
    if(start>=end) return;
    int pivot=partition(arr,start,end);
    quicksort(arr,start,pivot-1);
    quicksort(arr,pivot+1,end);
}

int main(){
    cout<<"enter the size of array?"<<endl;
    int n,i,j,k;
    cin>>n;
    cout<<"enter the elements of the array......."<<endl;
    int arr[n];
    for(i=0;i<n;++i){
        cin>>arr[i];
    }
    
    quicksort(arr,0,n-1);

    cout<<"sorted array: ";
    for(i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;

}