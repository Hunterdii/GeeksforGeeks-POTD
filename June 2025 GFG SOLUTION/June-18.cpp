class Solution {
public:
    vector<vector<string>> palinParts(string& s) {
        int n = s.size();
        vector<vector<bool>> d(n, vector<bool>(n));
        for (int i = 0; i < n; i++) d[i][i] = true;
        for (int i = 0; i < n - 1; i++) d[i][i + 1] = s[i] == s[i + 1];
        for (int l = 3; l <= n; l++)
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                d[i][j] = s[i] == s[j] && d[i + 1][j - 1];
            }
        vector<vector<string>> r;
        vector<string> c;
        function<void(int)> b = [&](int i) {
            if (i == n) { r.push_back(c); return; }
            for (int j = i; j < n; j++)
                if (d[i][j]) {
                    c.push_back(s.substr(i, j - i + 1));
                    b(j + 1);
                    c.pop_back();
                }
        };
        b(0);
        return r;
    }
};

2)
class Solution {
public:
    vector<vector<string>> palinParts(string& s) {
        int n = s.size();
        vector<vector<bool>> p(n, vector<bool>(n, false));
        for (int c = 0; c < n; c++) {
            for (int l = c, r = c; l >= 0 && r < n && s[l] == s[r]; l--, r++) p[l][r] = true;
            for (int l = c, r = c + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) p[l][r] = true;
        }
        vector<vector<string>> res;
        vector<string> cur;
        function<void(int)> dfs = [&](int i) {
            if (i >= n) { res.push_back(cur); return; }
            for (int j = i; j < n; j++) {
                if (p[i][j]) {
                    cur.push_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    cur.pop_back();
                }
            }
        };
        dfs(0);
        return res;
    }
};


3)
class Solution {
public:
    bool isPalin(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    vector<vector<string>> palinParts(string& s) {
        vector<vector<string>> res;
        vector<string> cur;

        function<void(int)> dfs = [&](int start) {
            if (start == s.size()) {
                res.push_back(cur);
                return;
            }
            for (int end = start; end < s.size(); end++) {
                if (isPalin(s, start, end)) {
                    cur.push_back(s.substr(start, end - start + 1));
                    dfs(end + 1);
                    cur.pop_back();
                }
            }
        };

        dfs(0);
        return res;
    }
};


4)
class Solution {
public:
    vector<vector<string>> palinParts(string& s) {
        int n = s.size();
        unordered_map<string, bool> palMemo;
        vector<vector<string>> res;
        vector<string> cur;

        auto isPal = [&](const string& sub) {
            if (palMemo.count(sub)) return palMemo[sub];
            int l = 0, r = sub.size() - 1;
            while (l < r) {
                if (sub[l++] != sub[r--]) return palMemo[sub] = false;
            }
            return palMemo[sub] = true;
        };

        function<void(int)> dfs = [&](int idx) {
            if (idx == s.size()) {
                res.push_back(cur);
                return;
            }
            for (int j = idx; j < s.size(); j++) {
                string part = s.substr(idx, j - idx + 1);
                if (isPal(part)) {
                    cur.push_back(part);
                    dfs(j + 1);
                    cur.pop_back();
                }
            }
        };

        dfs(0);
        return res;
    }
};
