class Solution {
public:
    int countPS(string &s) {
        int n = s.size(), ans = 0;
        auto go=[&](int l,int r){
            while(l>=0&&r<n&&s[l--]==s[r++]) ans++;
        };
        for(int i=0;i<n;i++) go(i-1,i+1), go(i,i+1);
        return ans;
    }
};

2)
class Solution {
public:
    int countPS(string &s) {
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            for(int l = i - 1, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) ans++;
            for(int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) ans++;
        }
        return ans;
    }
};

3)
class Solution {
public:
    int countPS(string &s) {
        int n = s.size(), ans = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) dp[i][i + 1] = true, ans++;
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len == 3 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};

4)
class Solution {
public:
    int countPS(string &s) {
        string t = "#";
        for (char c : s) t += c, t += '#';
        int n = t.size(), ans = 0, center = 0, right = 0;
        vector<int> p(n, 0);
        for (int i = 0; i < n; i++) {
            if (i < right) p[i] = min(right - i, p[2 * center - i]);
            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && 
                  t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
            if (i + p[i] > right) center = i, right = i + p[i];
            ans += p[i] / 2;
        }
        return ans;
    }
};

5)
class Solution {
public:
    int countPS(string &s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int l = i, r = j;
                bool isPalin = true;
                while (l < r) {
                    if (s[l] != s[r]) {
                        isPalin = false;
                        break;
                    }
                    l++, r--;
                }
                if (isPalin) ans++;
            }
        }
        return ans;
    }
};
