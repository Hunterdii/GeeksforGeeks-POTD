//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int mod = 1e9 + 7;
    long long int findMaxProduct(vector<int>& arr) {
        int negCount = 0;
        int maxNeg = INT_MIN;
        long long posProduct = 1;
        long long negProduct = 1;
        bool hasNonZero = false;

        for (int num : arr) {
            if (num < 0) {
                negCount++;
                maxNeg = max(maxNeg, num);
            }
        }
        bool skipMaxNeg = (negCount % 2 == 1);

        for (int num : arr) {
            if (num < 0) {
                if (skipMaxNeg && num == maxNeg) {
                    skipMaxNeg = false;
                    continue;
                }
                negProduct = (negProduct * abs(num)) % mod;
            } else if (num > 0) {
                posProduct = (posProduct * num) % mod;
                hasNonZero = true;
            }
        }
        if (!hasNonZero && negCount <= 1) return 0;
        return (negProduct * posProduct) % mod;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends
