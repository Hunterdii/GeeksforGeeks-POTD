//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<string> findPermutation(string s) {
        vector<string> res;
        sort(s.begin(), s.end());
        do {
            res.push_back(s);
        } while (next_permutation(s.begin(), s.end()));
        return res;
    }
};

2)
class Solution {
public:
    void dfs(string &s, vector<bool> &used, string &curr, vector<string> &res) {
        if (curr.size() == s.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            // Skip used characters or duplicates
            if (used[i] || (i > 0 && s[i] == s[i - 1] && !used[i - 1])) continue;
            used[i] = true;
            curr += s[i];
            dfs(s, used, curr, res); // Recursive call
            used[i] = false; // Backtrack
            curr.pop_back();
        }
    }

    vector<string> findPermutation(string s) {
        vector<string> res;
        sort(s.begin(), s.end()); // Step 1: Sort to handle duplicates
        vector<bool> used(s.size(), false);
        string curr;
        dfs(s, used, curr, res); // Start backtracking
        return res;
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
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
