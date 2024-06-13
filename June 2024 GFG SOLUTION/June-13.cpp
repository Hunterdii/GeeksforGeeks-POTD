//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

1)
class Solution {
public:
    int padovanSequence(int n) {
        const int MOD = 1000000007;
        if (n == 0 || n == 1 || n == 2)
            return 1;

        int p[3] = {1, 1, 1};
        for (int i = 3; i <= n; ++i) {
            int p_next = (p[0] + p[1]) % MOD;
            p[0] = p[1];
            p[1] = p[2];
            p[2] = p_next;
        }
        return p[2];
    }
};

2)
class Solution {
public:
    int padovanSequence(int n) {
        const int MOD = 1000000007;
        if (n == 0 || n == 1 || n == 2)
            return 1;
        int p0 = 1, p1 = 1, p2 = 1;
        for (int i = 3; i <= n; ++i) {
            int p3 = (p0 + p1) % MOD;
            p0 = p1;
            p1 = p2;
            p2 = p3;
        }
        return p2;
    }
};

3)
class Solution {
public:
    int padovanSequence(int n) {
        const int MOD = 1000000007;
        if (n < 3) return 1;
        
        int p[3] = {1, 1, 1};  // Initialize first three elements

        for (int i = 3; i <= n; ++i) {
            int next = (p[0] + p[1]) % MOD;
            p[0] = p[1];
            p[1] = p[2];
            p[2] = next;
        }
        
        return p[2];
    }
};

4)
class Solution {
public:
    int padovanSequence(int n) {
        const int MOD = 1000000007;
        if (n == 0 or n == 1 or n == 2)
            return 1;
        int p0=1, p1=1, p2=1;
        int p3;
        for (int i=3; i<=n; ++i) {
            p3 = (p1+p0) % MOD;
            p0 = p1;
            p1 = p2;
            p2 = p3;
        }
        return p2;
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
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
