//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int findShortestPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), d[4] = {1, -1, 0, 0};

        // Marking obstacles and starting points
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!mat[i][j]) {
                    for (int k = 0; k < 4; k++) {
                        int x = i + d[k], y = j + d[3 - k];
                        if (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1)
                            mat[x][y] = 2;
                    }
                }

        // Starting BFS from the leftmost column
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            if (mat[i][0] == 1)
                mat[i][0] = 2, q.push({i, 0});

        int ans = 1;

        // Performing BFS
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                pair<int, int> current = q.front();
                q.pop();
                int i = current.first;
                int j = current.second;
                if (j == m - 1)
                    return ans; // Found shortest path
                for (int k = 0; k < 4; k++) {
                    int x = i + d[k], y = j + d[3 - k];
                    if (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] == 1)
                        mat[x][y] = 2, q.push({x, y});
                }
            }
            ans++;
        }
        return -1; // No path found
    }
};




//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
