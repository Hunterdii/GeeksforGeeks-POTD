class Solution {
public:
    int minSquares(int n) {
        if(int s = sqrt(n); s * s == n) return 1;
        for(int i = 1; i * i <= n; i++)
            if(int r = sqrt(n - i * i); r * r == n - i * i) return 2;
        while(n % 4 == 0) n /= 4;
        return n % 8 == 7 ? 4 : 3;
    }
};

2)
class Solution {
public:
    int minSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j * j <= i; j++)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        return dp[n];
    }
};

3)
class Solution {
public:
    int minSquares(int n) {
        queue<int> q;
        vector<bool> vis(n + 1);
        q.push(n);
        vis[n] = true;
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            level++;
            while(sz--) {
                int cur = q.front();
                q.pop();
                for(int i = 1; i * i <= cur; i++) {
                    int next = cur - i * i;
                    if(next == 0) return level;
                    if(!vis[next]) {
                        vis[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        return level;
    }
};

4)
class Solution {
public:
    int minSquares(int n) {
        int s = sqrt(n);
        if(s * s == n) return 1;
        int temp = n;
        while(temp % 4 == 0) temp /= 4;
        if(temp % 8 == 7) return 4;
        for(int i = 1; i * i <= n; i++)
            if(s = sqrt(n - i * i); s * s == n - i * i) return 2;
        return 3;
    }
};
