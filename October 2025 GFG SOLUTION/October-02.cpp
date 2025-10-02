class Solution {
public:
    vector<vector<int>> combinationSum(int n, int k) {
        if (n < k || n > 9 * k) return {};
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int, int, int)> dfs = [&](int start, int sum, int cnt) {
            if (cnt == k) {
                if (sum == n) res.push_back(cur);
                return;
            }
            for (int i = start; i <= 9; i++) {
                if (sum + i > n) break;
                cur.push_back(i);
                dfs(i + 1, sum + i, cnt + 1);
                cur.pop_back();
            }
        };
        dfs(1, 0, 0);
        return res;
    }
};

2)
class Solution {
public:
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> res;
        for (int mask = 0; mask < 512; mask++) {
            if (__builtin_popcount(mask) != k) continue;
            int sum = 0;
            vector<int> cur;
            for (int i = 0; i < 9; i++) {
                if (mask & (1 << i)) {
                    cur.push_back(i + 1);
                    sum += i + 1;
                }
            }
            if (sum == n) res.push_back(cur);
        }
        return res;
    }
};
