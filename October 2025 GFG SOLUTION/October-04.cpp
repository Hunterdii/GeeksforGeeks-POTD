class Solution {
public:
    vector<string> findExpr(string& s, int target) {
        vector<string> res;
        function<void(int, long, long, string)> dfs = [&](int i, long val, long prev, string path) {
            if (i == s.size()) {
                if (val == target) res.push_back(path);
                return;
            }
            for (int j = i; j < s.size(); j++) {
                if (j > i && s[i] == '0') break;
                long cur = stol(s.substr(i, j - i + 1));
                if (i == 0) dfs(j + 1, cur, cur, to_string(cur));
                else {
                    dfs(j + 1, val + cur, cur, path + "+" + to_string(cur));
                    dfs(j + 1, val - cur, -cur, path + "-" + to_string(cur));
                    dfs(j + 1, val - prev + prev * cur, prev * cur, path + "*" + to_string(cur));
                }
            }
        };
        dfs(0, 0, 0, "");
        return res;
    }
};

2)
class Solution {
public:
    vector<string> findExpr(string& s, int target) {
        vector<string> res;
        stack<tuple<int, string, long, long>> st;
        st.push({0, "", 0, 0});
        while (!st.empty()) {
            auto [i, expr, val, prev] = st.top(); st.pop();
            if (i == s.size()) {
                if (val == target) res.push_back(expr);
                continue;
            }
            for (int j = i; j < s.size(); j++) {
                if (j > i && s[i] == '0') break;
                long cur = stol(s.substr(i, j - i + 1));
                string num = to_string(cur);
                if (i == 0) st.push({j + 1, num, cur, cur});
                else {
                    st.push({j + 1, expr + "*" + num, val - prev + prev * cur, prev * cur});
                    st.push({j + 1, expr + "-" + num, val - cur, -cur});
                    st.push({j + 1, expr + "+" + num, val + cur, cur});
                }
            }
        }
        return res;
    }
};

3)
class Solution {
public:
    vector<string> findExpr(string& s, int target) {
        unordered_map<string, vector<string>> memo;
        function<vector<string>(int, long, long)> solve = [&](int i, long val, long prev) -> vector<string> {
            string key = to_string(i) + "," + to_string(val) + "," + to_string(prev);
            if (memo.count(key)) return memo[key];
            vector<string> res;
            if (i == s.size()) {
                if (val == target) res.push_back("");
                return memo[key] = res;
            }
            for (int j = i; j < s.size(); j++) {
                if (j > i && s[i] == '0') break;
                long cur = stol(s.substr(i, j - i + 1));
                string num = to_string(cur);
                if (i == 0) {
                    for (auto& x : solve(j + 1, cur, cur))
                        res.push_back(num + x);
                } else {
                    for (auto& x : solve(j + 1, val + cur, cur))
                        res.push_back("+" + num + x);
                    for (auto& x : solve(j + 1, val - cur, -cur))
                        res.push_back("-" + num + x);
                    for (auto& x : solve(j + 1, val - prev + prev * cur, prev * cur))
                        res.push_back("*" + num + x);
                }
            }
            return memo[key] = res;
        };
        return solve(0, 0, 0);
    }
};
