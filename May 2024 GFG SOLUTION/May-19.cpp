//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends



1)
class Solution {
public:
    int findClosest(int n, int k, int arr[]) {
        int left = 0, right = n - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if (left > 0 && abs(arr[left - 1] - k) < abs(arr[left] - k)) {
            return arr[left - 1];
        } else {
            return arr[left];
        }
    }
};
2)
class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        int r = lower_bound(arr,arr+n,k)-arr;
        int l = r-1;
        if(l < 0){
            return arr[r];
        } else {
            int diff1 = abs(k-arr[r]);
            int diff2 = abs(k-arr[l]);
            if(diff1 <= diff2){
                return arr[r];
            }
          return arr[l];
        }
    } 
};

3)
class Solution {
public:
    int findClosest(int n, int k, int arr[]) {
        int left = 0, right = n - 1;
        
        if (k <= arr[left]) {
            return arr[left];
        } else if (k >= arr[right]) {
            return arr[right];
        }
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == k) {
                return arr[mid];
            } else if (arr[mid] < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        if (abs(arr[left] - k) <= abs(arr[right] - k)) {
            return arr[left];
        } else {
            return arr[right];
        }
    }
};


//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends
