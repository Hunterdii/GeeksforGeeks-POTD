//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        vector<vector<int>> v1(n,vector<int>(n,0));
        vector<vector<int>> v2(n,vector<int>(n,0));
        
        // col
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=n-1;j>=0;j--)
            {
                if(a[i][j]=='O')
                {
                    sum=0;
                    v1[i][j]=0;
                }
                else
                {
                    sum++;
                    v1[i][j]=sum;
                }
            }
        }
        
        // rows
        int maxi=10002;
        for(int j=0;j<n;j++)
        {
            int sum=0;
            for(int i=n-1;i>=0;i--)
            {
                if(a[i][j]=='O')
                sum=0;
                else
                {
                    sum++;
                    v2[i][j]=sum;
                }
            }
        }
        
        
        //finding max submatrix
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='O')
                continue;
                
                int size=min(v1[i][j],v2[i][j]);
                
                while(size>ans)
                {
                    if((v1[i+size-1][j])>=size and (v2[i][j+size-1])>=size)
                    ans=size;
                    
                    size--;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends
