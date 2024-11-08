//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    struct cell {
        int x, y, distance;
        bool operator>(const cell& other) const {
            return distance > other.distance;
        }
    };
    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<cell, vector<cell>, greater<cell>> pq;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        dp[0][0] = grid[0][0];
        pq.push({0, 0, dp[0][0]});
        while (!pq.empty()) {
            cell cur = pq.top();
            pq.pop();
            int x = cur.x;
            int y = cur.y;
            int dist = cur.distance;
            if (dist > dp[x][y]) continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newDist = dp[x][y] + grid[nx][ny];
                    if (newDist < dp[nx][ny]) {
                        dp[nx][ny] = newDist;
                        pq.push({nx, ny, newDist});
                    }
                }
            }
        }

        return dp[n-1][m-1];
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
