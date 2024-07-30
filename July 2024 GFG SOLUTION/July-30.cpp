//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<vector<int>> visited;
    vector<string> result;

    void path(vector<vector<int>>& m, int x, int y, string dir, int n) {
        if (x == n - 1 && y == n - 1) {
            result.push_back(dir);
            return;
        }
        if (m[x][y] == 0 || visited[x][y] == 1)
            return;
        visited[x][y] = 1;
        if (x > 0)
            path(m, x - 1, y, dir + 'U', n);
        if (y > 0)
            path(m, x, y - 1, dir + 'L', n);
        if (x < n - 1)
            path(m, x + 1, y, dir + 'D', n);
        if (y < n - 1)
            path(m, x, y + 1, dir + 'R', n);
        visited[x][y] = 0;
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        int n = mat.size();
        visited = vector<vector<int>>(n, vector<int>(n, 0));
        result.clear();
        if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0)
            return result;
        path(mat, 0, 0, "", n);
        sort(result.begin(), result.end());
        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
