//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPS(string& s) {
        int n = s.size(), res = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = true;
            for (int j = i + 1; j < n; ++j)
                if (s[i] == s[j] && (j - i == 1 || dp[i + 1][j - 1]))
                    dp[i][j] = true, res++;
        }
        return res;
    }
};

2)
class Solution {
public:
    int countPS(string& s) {
        int n = s.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            for (int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; --l, ++r) res++;
            for (int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; --l, ++r) res++;
        }
        return res - n;
    }
};


3)
class Solution {
public:
    int countPS(string s) {
        string t = "#";
        for (char c : s) t += c + string("#");
        int n = t.size(), res = 0;
        vector<int> p(n, 0);
        int c = 0, r = 0;

        for (int i = 1; i < n - 1; i++) {
            int mirr = 2 * c - i;
            if (i < r) p[i] = min(r - i, p[mirr]);

            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) 
                p[i]++;

            if (i + p[i] > r) {
                c = i;
                r = i + p[i];
            }

            res += (p[i] / 2);
        }

        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
