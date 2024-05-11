//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<int> jugglerSequence(int n) {
        vector<int> ans;
        ans.push_back(n);

        while (ans.back() > 1) {
            double sqrt_n = sqrt(ans.back());
            int next_term = (ans.back() % 2 == 0) ? static_cast<int>(sqrt_n) : static_cast<int>(pow(sqrt_n, 3));
            ans.push_back(next_term);
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

        Solution ob;
        vector<int> ans = ob.jugglerSequence(n);
        for (int u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
