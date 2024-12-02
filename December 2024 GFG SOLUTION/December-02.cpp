//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> search(string& pat, string& txt) {
        int m = pat.size();
        int n = txt.size();
        vector<int> lps(m, 0);  
        vector<int> result;
        int len = 0; 
        for (int i = 1; i < m; ) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        int i = 0; 
        int j = 0; 
        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }
            if (j == m) {
                result.push_back(i - j); 
                j = lps[j - 1];
            } else if (i < n && txt[i] != pat[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return result;
    }
};
//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends
