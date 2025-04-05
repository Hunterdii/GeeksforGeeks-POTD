//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
public:
    int countIslands(vector<vector<char>>& g){
        int n = g.size(), m = g[0].size(), ans = 0;
        function<void(int,int)> f = [&](int i, int j){
            if(i < 0 || i >= n || j < 0 || j >= m || g[i][j] == 'W') return;
            g[i][j] = 'W';
            for(int a = -1; a <= 1; a++) 
                for(int b = -1; b <= 1; b++) 
                    f(i + a, j + b);
        };
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(g[i][j] == 'L') { ans++; f(i, j); }
        return ans;
    }
};

2)
class Solution {
public:
    int countIslands(vector<vector<char>>& g) {
        int n = g.size(), m = g[0].size(), ans = 0;
        vector<pair<int,int>> d = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g[i][j] == 'L') {
                    ans++;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i, j));
                    g[i][j] = 'W';
                    while(!q.empty()) {
                        pair<int,int> curr = q.front(); q.pop();
                        int x = curr.first, y = curr.second;
                        for(int k = 0; k < 8; k++) {
                            int nx = x + d[k].first, ny = y + d[k].second;
                            if(nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] == 'L') {
                                g[nx][ny] = 'W';
                                q.push(make_pair(nx, ny));
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};


3)
class Solution {
public:
    int countIslands(vector<vector<char>>& g) {
        int n = g.size(), m = g[0].size(), ans = 0;
        vector<pair<int,int>> d = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(g[i][j] == 'L') {
                    ans++;
                    stack<pair<int,int>> stk;
                    stk.push(make_pair(i, j));
                    g[i][j] = 'W';
                    while(!stk.empty()) {
                        pair<int,int> curr = stk.top(); stk.pop();
                        int x = curr.first, y = curr.second;
                        for(int k = 0; k < 8; k++) {
                            int nx = x + d[k].first, ny = y + d[k].second;
                            if(nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] == 'L') {
                                g[nx][ny] = 'W';
                                stk.push(make_pair(nx, ny));
                            }
                        }
                    }
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
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
