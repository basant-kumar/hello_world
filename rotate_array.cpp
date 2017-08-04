#include <iostream>
#include <vector>
using namespace std;

int gcd(int a,int b)
{
   if(b==0)
     return a;
   else
     return gcd(b, a%b);
}

void rotate(vector<int> &arr,int n,int d){
    /*  time complexity O(n)
        spcae complexity O(1) 
    */
    int i, j, k, temp;
    for (i = 0; i < gcd(d, n); i++)
    {
   
    temp = arr[i];
    j = i;
    while(1)
    {
      k = j + d;
      if (k >= n)
        k = k - n;
      if (k == i)
        break;
      arr[j] = arr[k];
      j = k;
    }
    arr[j] = temp;
    }
    
    
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        cin>>d;
        rotate(arr,n,d);
        for(int i=0;i<n;++i){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }
	return 0;
}