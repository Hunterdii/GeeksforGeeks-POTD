//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution {
public:
    vector<int> twoRepeated(int arr[], int N) {
        unordered_set<int> seen;
        vector<int> result;
        
        for (int i = 0; i < N + 2; ++i) {
            if (seen.count(arr[i])) {
                result.push_back(arr[i]);
            } else {
                seen.insert(arr[i]);
            }
        }
        
        return result;
    }
};


//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}

// } Driver Code Ends
