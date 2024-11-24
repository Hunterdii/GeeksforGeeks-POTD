//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
public:
    int longestSubseq(int n, vector<int> &a) {
        unordered_map<int, int> dp;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int x = a[i];
            int len1 = dp[x - 1] + 1;
            int len2 = dp[x + 1] + 1;
            dp[x] = max(dp[x], max(len1, len2));
            ans = max(ans, dp[x]);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends
