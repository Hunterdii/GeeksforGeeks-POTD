class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if (n == 1) return 0;
        int a = 0, b = abs(height[1] - height[0]);
        for (int i = 2; i < n; i++) {
            int c = min(b + abs(height[i] - height[i - 1]), a + abs(height[i] - height[i - 2]));
            a = b;
            b = c;
        }
        return b;
    }
};

2)
class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if (n == 1) return 0;
        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = abs(height[1] - height[0]);
        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 1] + abs(height[i] - height[i - 1]),
                        dp[i - 2] + abs(height[i] - height[i - 2]));
        }
        return dp[n - 1];
    }
};

3)
class Solution {
public:
    int solve(vector<int>& h, int i, vector<int>& memo) {
        if (i >= h.size() - 1) return 0;
        if (memo[i] != -1) return memo[i];
        int one = abs(h[i + 1] - h[i]) + solve(h, i + 1, memo);
        int two = (i + 2 < h.size()) ? abs(h[i + 2] - h[i]) + solve(h, i + 2, memo) : INT_MAX;
        return memo[i] = min(one, two);
    }
    int minCost(vector<int>& height) {
        vector<int> memo(height.size(), -1);
        return solve(height, 0, memo);
    }
};

4)
class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if (n == 1) return 0;
        int second_prev = 0;
        int prev = abs(height[1] - height[0]);
        for (int i = 2; i < n; i++) {
            int jump_one = prev + abs(height[i] - height[i - 1]);
            int jump_two = second_prev + abs(height[i] - height[i - 2]);
            int current = min(jump_one, jump_two);
            second_prev = prev;
            prev = current;
        }
        return prev;
    }
};
