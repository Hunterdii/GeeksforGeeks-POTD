class Solution {
public:
    int numberOfWays(int n) {
        if (n <= 1) return 1;
        int a = 1, b = 1;
        while (n-- > 1) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};

2)
class Solution {
public:
    int numberOfWays(int n) {
        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }
    int solve(int n, vector<int>& memo) {
        if (n <= 1) return 1;
        if (memo[n] != -1) return memo[n];
        return memo[n] = solve(n - 1, memo) + solve(n - 2, memo);
    }
};

3)
class Solution {
public:
    int numberOfWays(int n) {
        double phi = (1 + sqrt(5)) / 2;
        return round(pow(phi, n + 1) / sqrt(5));
    }
};

4)
class Solution {
public:
    int numberOfWays(int n) {
        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }
    int solve(int n, vector<int>& memo) {
        if (n <= 1) return 1;
        if (memo[n] != -1) return memo[n];
        return memo[n] = solve(n - 1, memo) + solve(n - 2, memo);
    }
};
