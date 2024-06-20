//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    long long boundaryPoints(long long x1, long long y1, long long x2, long long y2) {
        return gcd(abs(x2 - x1), abs(y2 - y1)) + 1;
    }

    long long InternalCount(long long p[], long long q[], long long r[]) {
        long long area = abs(p[0] * (q[1] - r[1]) + q[0] * (r[1] - p[1]) + r[0] * (p[1] - q[1]));

        long long B = boundaryPoints(p[0], p[1], q[0], q[1]) +
                      boundaryPoints(q[0], q[1], r[0], r[1]) +
                      boundaryPoints(r[0], r[1], p[0], p[1]) - 3;
        long long I = (area - B + 2) / 2;

        return I;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends
