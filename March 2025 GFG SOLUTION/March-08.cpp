//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &s) {
        int n = s.size(), start = 0, maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int l : {i, i + 1}) {
                int j = i;
                while (j >= 0 && l < n && s[j] == s[l]) j--, l++;
                if (l - j - 1 > maxLen) start = j + 1, maxLen = l - j - 1;
            }
        }
        return s.substr(start, maxLen);
    }
};

2)
class Solution {
public:
    string longestPalindrome(string &s) {
        int n = s.size(), start = 0, maxLen = 0;
        auto expand = [&](int i, int j) {
            while (i >= 0 && j < n && s[i] == s[j]) i--, j++;
            if (j - i - 1 > maxLen) start = i + 1, maxLen = j - i - 1;
        };
        for (int i = 0; i < n; i++) expand(i, i), expand(i, i + 1);
        return s.substr(start, maxLen);
    }
};


3)
class Solution {
public:
    string longestPalindrome(string &s) {
        string t = "#";
        for (char c : s) t += c, t += "#";
        int n = t.size(), center = 0, right = 0, maxLen = 0, start = 0;
        vector<int> p(n, 0);

        for (int i = 0; i < n; i++) {
            int mirror = 2 * center - i;
            if (i < right) p[i] = min(right - i, p[mirror]);
            while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1])
                p[i]++;
            if (i + p[i] > right) center = i, right = i + p[i];
            if (p[i] > maxLen) maxLen = p[i], start = (i - maxLen) / 2;
        }
        return s.substr(start, maxLen);
    }
};

4)
class Solution {
public:
    string longestPalindrome(string &s) {
        if (s.empty()) return "";
        string t = "#";
        for (char c : s) t += c, t += "#";

        int n = t.size(), C = 0, R = 0, maxLen = 0, center = 0;
        vector<int> p(n, 0);

        for (int i = 0; i < n; i++) {
            int mirror = 2 * C - i;
            if (i < R) p[i] = min(R - i, p[mirror]);

            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1])
                p[i]++;

            if (i + p[i] > R) C = i, R = i + p[i];

            if (p[i] > maxLen) maxLen = p[i], center = i;
        }

        int start = (center - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
