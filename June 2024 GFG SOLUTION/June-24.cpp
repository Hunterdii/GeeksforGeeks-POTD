//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// GFG POTD :
class Solution {
public:
    long long sumMatrix(long long n, long long q) {
        if (q > 2 * n) {
            return 0;
        } else if (q <= n + 1) {
            return q - 1;
        } else {
            return 2 * n - q + 1;
        }
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}
// } Driver Code Ends
