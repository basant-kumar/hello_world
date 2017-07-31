/*  
    Best-case time complexity O(n)
    Average-case time complexity O(n^2)
    worst-case time complexity O(n^2)
    space complexity O(1)
    it is inplace and stable sorting algorithm
*/

/* hint to remember:-
    take the biggest element to the end by swapping between nearest element. (i.e. 1&2, 2&3, 3&4....)
*/

#include <iostream>

using namespace std;

int main(){
    cout<<"enter the size of array?"<<endl;
    int n,k;
    cin>>n;
    cout<<"enter the elements of the array......."<<endl;
    int arr[n],flag;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    for(int i=0;i<n-1;++i){
        for(int k=0;k<n-1-i;++k){
            flag=0;
            if(arr[k] > arr[k+1]){
                int temp=arr[k];
                arr[k]=arr[k+1];
                arr[k+1]=temp;
                flag=1;
            }
        }
        if(flag==0) break;
    }
    cout<<"sorted array: ";
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}