//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
1)
class Solution {
public:
    int maxDotProduct(int n, int m, int a[], int b[]) { 
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, a, b, dp);
    }

    int solve(int n, int m, int a[], int b[], vector<vector<int>>& dp) {
        if (m == 0) {
            return 0;
        }
        if (n < m) {
            return INT_MIN;
        }
        if (dp[n][m] != -1) {
            return dp[n][m];
        }
        int t2 = solve(n - 1, m, a, b, dp);
        int t3 = a[n - 1] * b[m - 1] + solve(n - 1, m - 1, a, b, dp);
        return dp[n][m] = max(t2, t3);
    }
};
2)
class Solution{
	public:
	int solve(int n,int m,int a[],int b[],vector<vector<int>>&dp){
	    if(m==0){
	        return 0;
	    }
	    if(n<m){
	        return INT_MIN;
	    }
	    if(dp[n][m]!=-1){
	        return dp[n][m];
	    }
	    int t2 = solve(n-1,m,a,b,dp);
	    int t3 = a[n-1]*b[m-1] + solve(n-1,m-1,a,b,dp);
	    return dp[n][m] = max(t2,t3);
	}
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
	    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
		return solve(n,m,a,b,dp);
	} 
};




//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
