/*  
    Best-case time complexity O(nlogn)
    Average-case time complexity O(nlogn)
    worst-case time complexity O(nlogn)
    space complexity O(n)
    not stable
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void merge(int *arr, int *L, int nL,int *R, int nR){ 
    int i=0,j=0,k=0;

    while(i<nL && j<nR){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[i];
            j++;
        }
        k++;
    }

    while(i<nL){
        arr[k]=L[i]; i++; k++;
    }
    while(j<nR){
        arr[k]=R[j]; j++; k++;
    }
}


void merge_sort(int *arr,int n){
    if(n<2) return;
    int mid, *L, *R;
    mid=n/2;
    L=(int*)malloc(mid*sizeof(int));
    R=(int*)malloc((n-mid)*sizeof(int));

    for(int i=0;i<mid;++i){
        L[i]=arr[i];
    }
    for(int i=mid;i<n;++i){
        R[i-mid]=arr[i];
    }
    merge_sort(L,mid);
    merge_sort(R,n-mid);
    merge(arr,L,mid,R,n-mid);
    free(L);
    free(R);
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
    merge_sort(arr,n);

    cout<<"sorted array: ";
    for(i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;

}