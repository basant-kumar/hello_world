#include<bits/stdc++.h>
using namespace std;
 
int findMedian(vector<vector<int> > &A) {
    int mid, req = (int)A.size() * (int)A[0].size();
    assert(req % 2);

    int min = INT_MAX, max = INT_MIN;
    for (int i=0; i<A.size(); i++)
    {
        // Finding the minimum element
        if (A[i][0] < min)
            min = A[i][0];
 
        // Finding the maximum element
        if (A[i][A[0].size()-1] > max)
            max = A[i][A[0].size()-1];
    }

    while(max - min > 1){
        mid = min + (max - min) / 2;
        int cnt = 0;
        for(auto &i: A){ 
            //using upper bound in a sorted array to count number of elements smaller than mid
            int p = upper_bound(i.begin(), i.end(), mid) - i.begin();
            cnt += p;
        }
        if(cnt >= (req/2 +1)) max = mid;
        else min = mid;
    }   
    return max;
}
 
// driver program to check above functions
int main()
{
    int r = 3, c = 3;
    vector< vector<int> > A(r, vector<int>(c) );
    A = { {1,3,5}, {2,6,9}, {3,6,9} };
    cout << "Median is " << findMedian(A) << endl;
    return 0;
}