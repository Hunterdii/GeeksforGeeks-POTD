//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    long long reversedBits(long long x) {
        long long ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans = (ans << 1) | (x & 1); // Shift ans left by 1 and OR it with the least significant bit of x
            x >>= 1; // Shift x right by 1 to process the next bit
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends
