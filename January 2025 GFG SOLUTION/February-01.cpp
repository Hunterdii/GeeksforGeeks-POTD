//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    bool dfs(vector<vector<char>> &b, string &w, int i, int j, int k) {
        if(k == w.size()) return true;
        if(i < 0 || j < 0 || i >= b.size() || j >= b[0].size() || b[i][j] != w[k]) return false;
        char t = b[i][j]; 
        b[i][j] = '#';
        bool f = dfs(b, w, i-1, j, k+1) || dfs(b, w, i+1, j, k+1) ||
                 dfs(b, w, i, j-1, k+1) || dfs(b, w, i, j+1, k+1);
        b[i][j] = t;
        return f;
    }
    
    bool isWordExist(vector<vector<char>> &b, string w) {
        for(int i = 0; i < b.size(); i++)
            for(int j = 0; j < b[0].size(); j++)
                if(b[i][j] == w[0] && dfs(b, w, i, j, 0))
                    return true;
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
