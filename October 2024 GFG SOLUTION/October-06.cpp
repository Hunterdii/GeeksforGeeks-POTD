//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<int> dx = {-1, 0, 1, 0, 1, -1, -1, 1};
    vector<int> dy = {0, -1, 0, 1, 1, 1, -1, -1};

    bool isValid(int x, int y, int n, int m) {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }

    void dfs(int x, int y, vector<vector<char>>& grid, int n, int m) {
        grid[x][y] = '0'; 
        
        for (int k = 0; k < 8; k++) {
            int newX = x + dx[k];
            int newY = y + dy[k];
            
            if (isValid(newX, newY, n, m) && grid[newX][newY] == '1') {
                dfs(newX, newY, grid, n, m);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    ans++;  
                    dfs(i, j, grid, n, m);  
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends
