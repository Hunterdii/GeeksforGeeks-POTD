class Solution {
public:
    vector<string> binstr(int n) {
        vector<string> res;
        for (int i = 0; i < (1 << n); i++) {
            string s = "";
            for (int j = n - 1; j >= 0; j--) s += ((i >> j) & 1) ? '1' : '0';
            res.push_back(s);
        }
        return res;
    }
};

2)
class Solution {
public:
    void solve(string cur, int n, vector<string>& res) {
        if (cur.size() == n) {
            res.push_back(cur);
            return;
        }
        solve(cur + "0", n, res);
        solve(cur + "1", n, res);
    }
    vector<string> binstr(int n) {
        vector<string> res;
        solve("", n, res);
        return res;
    }
};

3)
class Solution {
public:
    vector<string> binstr(int n) {
        vector<string> res;
        queue<string> q;
        q.push("");
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            if (cur.size() == n) res.push_back(cur);
            else {
                q.push(cur + "0");
                q.push(cur + "1");
            }
        }
        return res;
    }
};

4)
class Solution {
public:
    void generate(string &s, int i, vector<string> &res) {
        if (i == s.size()) {
            res.push_back(s);
            return;
        }
        s[i] = '0';
        generate(s, i + 1, res);
        s[i] = '1';
        generate(s, i + 1, res);
    }
    vector<string> binstr(int n) {
        string s(n, '0');
        vector<string> res;
        generate(s, 0, res);
        return res;
    }
};
