//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution {
public:
    long long maximumAmount(int n, int arr[]) {
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        for (int gap = 0; gap < n; ++gap) {
            for (int i = 0, j = gap; j < n; ++i, ++j) {
                long long x = (i + 2 <= j) ? dp[i + 2][j] : 0;
                long long y = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
                long long z = (i <= j - 2) ? dp[i][j - 2] : 0;
                dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
            }
        }

        return dp[0][n - 1];
    }
};
1)
class Solution{
    public:
    int help(int arr[], int start, int end, vector<vector<int>> &dp)
    {
        if(end == start) return arr[start];
        if(start>end) return 0;

        if(dp[start][end] != -1) return dp[start][end];

        int left = arr[start] + min( help(arr, start+1, end-1, dp), help(arr, start+2, end, dp) );
        int right = arr[end] + min( help(arr, start, end-2, dp), help(arr, start+1, end-1, dp) );

        return dp[start][end] = max(left, right);
    }

    long long maximumAmount(int n,int arr[]){
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return help(arr, 0, n-1, dp);

    }
};
2)
class Solution {
public:
    long long maximumAmount(int n, int arr[]) {
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = arr[i];
        }
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                long long x = (i + 2 <= j) ? dp[i + 2][j] : 0;
                long long y = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
                long long z = (i <= j - 2) ? dp[i][j - 2] : 0;
                dp[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
            }
        }
        
        return dp[0][n - 1];
    }
};


//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends
