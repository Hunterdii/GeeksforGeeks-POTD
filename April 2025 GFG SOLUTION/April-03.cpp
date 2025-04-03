//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), t = 0, f = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(a[i][j] == 2) q.push({i, j});
                else if(a[i][j] == 1) f++;
            }
        if(!f) return 0;
        int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            int sz = q.size();
            bool ch = false;
            while(sz--){
                auto p = q.front(); q.pop();
                int i = p.first, j = p.second;
                for(auto &dir : d){
                    int x = i + dir[0], y = j + dir[1];
                    if(x < 0 || y < 0 || x >= n || y >= m || a[x][y] != 1) continue;
                    a[x][y] = 2; q.push({x,y}); f--; ch = true;
                }
            }
            if(ch) t++;
        }
        return f ? -1 : t;
    }
};

2)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), t = 0, f = 0;
        queue<pair<int,int>> curr, next;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(a[i][j] == 2) curr.push({i, j});
                else if(a[i][j] == 1) f++;
            }
        if(!f) return 0;
        int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!curr.empty()){
            bool changed = false;
            while(!curr.empty()){
                auto p = curr.front(); curr.pop();
                int i = p.first, j = p.second;
                for(auto &dir : d){
                    int x = i + dir[0], y = j + dir[1];
                    if(x < 0 || y < 0 || x >= n || y >= m || a[x][y] != 1) continue;
                    a[x][y] = 2; next.push({x,y}); f--; changed = true;
                }
            }
            if(changed) t++;
            swap(curr, next);
        }
        return f ? -1 : t;
    }
};

3)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), t = 0, f = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                if(a[i][j] == 2) q.push({i, j});
                else if(a[i][j] == 1) f++;
            }
        if(!f) return 0;
        q.push({-1, -1});
        int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            auto p = q.front(); q.pop();
            if(p.first == -1) {
                if(q.empty()) break;
                t++;
                q.push({-1, -1});
                continue;
            }
            int i = p.first, j = p.second;
            for(auto &dir : d){
                int x = i + dir[0], y = j + dir[1];
                if(x < 0 || y < 0 || x >= n || y >= m || a[x][y] != 1) continue;
                a[x][y] = 2; q.push({x,y}); f--;
            }
        }
        return f ? -1 : t;
    }
};

4)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), f = 0;
        vector<vector<int>> time(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                if(a[i][j] == 2)
                    q.push({i, j});
                else if(a[i][j] == 1)
                    f++;
            }
        if(!f) return 0;
        int d[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}, ans = 0;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            for(auto &dir : d){
                int x = i + dir[0], y = j + dir[1];
                if(x < 0 || y < 0 || x >= n || y >= m || a[x][y] != 1) continue;
                a[x][y] = 2;
                time[x][y] = time[i][j] + 1;
                ans = max(ans, time[x][y]);
                q.push({x,y});
                f--;
            }
        }
        return f ? -1 : ans;
    }
};
//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
