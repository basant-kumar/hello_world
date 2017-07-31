/*  
    Best-case time complexity O(n)
    Average-case time complexity O(n^2)
    worst-case time complexity O(n^2)
    space complexity O(1)
    it is inplace and stable sorting algorithm
*/

/* hint :-
    have two parts :- sorted and unsorted
    sorted part has one element the first one and unsorted part have rest of the elements.
    select each element of the unsorted part and save that value in a vairable(make a hole) then
    start compairing with elements of the sorted part and shift sorted element accordingly 
*/


#include <iostream>

using namespace std;

int main(){
    cout<<"enter the size of array?"<<endl;
    int n,i,j,k;
    cin>>n;
    cout<<"enter the elements of the array......."<<endl;
    int arr[n];
    for(i=0;i<n;++i){
        cin>>arr[i];
    }
    int value,hole;
    for(i=1;i<n;++i){
        value=arr[i];
        hole=i;
        while(hole>0 && arr[hole-1] > arr[hole]){
            arr[hole]=arr[hole-1];
            hole--;
        }
        arr[hole]=value;
    }
    cout<<"sorted array: ";
    for(i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}