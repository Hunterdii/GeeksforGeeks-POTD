//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int n;
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};

    int solve(int i, int j, vector<vector<int>>& grid, int k) {
        grid[i][j] = k;
        int count = 1;
        for (int l = 0; l < 4; ++l) {
            int x = i + dx[l];
            int y = j + dy[l];
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1) {
                count += solve(x, y, grid, k);
            }
        }
        return count;
    }

    int MaxConnection(vector<vector<int>>& grid) {
        n = grid.size();
        int k = 2;
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    int size = solve(i, j, grid, k);
                    mp[k] = size;
                    ans = max(ans, size);
                    ++k;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> unique_neighbors;
                    int potential_size = 1;
                    for (int l = 0; l < 4; ++l) {
                        int x = i + dx[l];
                        int y = j + dy[l];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] > 1) {
                            int neighbor_component = grid[x][y];
                            if (unique_neighbors.insert(neighbor_component).second) {
                                potential_size += mp[neighbor_component];
                            }
                        }
                    }
                    ans = max(ans, potential_size);
                }
            }
        }

        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends
