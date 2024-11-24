//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {
public:
    std::vector<long long> jugglerSequence(long long n) {
        std::vector<long long> res;
        res.push_back(n);

        while (n > 1) {
            if (n % 2)
                n = static_cast<long long>(std::sqrt(n) * n);
            else
                n = static_cast<long long>(std::sqrt(n));

            res.push_back(n);
        }

        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
