//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int maxLength(string s) {
        stack<int> st; st.push(-1);
        int m = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i]=='(') st.push(i);
            else { st.pop(); if (st.empty()) st.push(i); else m = max(m, i - st.top()); }
        return m;
    }
};

1)
class Solution {
public:
    int maxLength(string s) {
        stack<int> st; st.push(-1);
        int m = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '(') st.push(i);
            else { 
                st.pop(); 
                if (st.empty()) st.push(i); 
                else m = max(m, i - st.top()); 
            }
        return m;
    }
};

2)
class Solution {
public:
    int maxLength(string s) {
        int l = 0, r = 0, m = 0;
        for (char c : s) {
            if (c == '(') l++;
            else r++;
            if (l == r) m = max(m, 2 * r);
            else if (r > l) l = r = 0;
        }
        l = r = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') l++;
            else r++;
            if (l == r) m = max(m, 2 * l);
            else if (l > r) l = r = 0;
        }
        return m;
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
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
