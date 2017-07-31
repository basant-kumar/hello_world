/*  
    Best-case time complexity O(n^2)
    Average-case time complexity O(n^2)
    worst-case time complexity O(n^2)
    space complexity O(1)
    it is inplace and unstable sorting algorithm but with help of another array it can be stable.
*/

/* hint to remember :-
    select one element (A), find the most lowest element than A and track the position of lowest
    element using j. after one pass swap values of A and j position.
    #in nutshell bring smallest element to front first.
*/

#include <iostream>

using namespace std;

int main(){
    cout<<"enter the size of array?"<<endl;
    int n,k;
    cin>>n;
    cout<<"enter the elements of the array......."<<endl;
    int arr[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    for(int i=0;i<n-1;++i){
        k=i;
        for(int j=i+1;j<n;++j){
            if(arr[j]<arr[k]){
                k=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[k];
        arr[k]=temp;
    }
    cout<<"sorted array: ";
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}