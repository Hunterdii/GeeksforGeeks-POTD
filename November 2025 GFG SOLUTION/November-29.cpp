class Solution {
public:
    int countSetBits(int n) {
        if (!n) return 0;
        int x = log2(n);
        return x * (1 << (x - 1)) + (n - (1 << x) + 1) + countSetBits(n - (1 << x));
    }
};

2)
class Solution {
public:
    int countSetBits(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i <<= 1) {
            int total = n + 1;
            int pairs = total / (i << 1);
            int rem = total % (i << 1);
            cnt += pairs * i + max(0, rem - i);
        }
        return cnt;
    }
};

3)
class Solution {
public:
    int countSetBits(int n) {
        n++;
        int cnt = 0, pw = 1;
        while (pw <= n) {
            int total = (n / (pw * 2)) * pw;
            int rem = n % (pw * 2);
            if (rem > pw) total += rem - pw;
            cnt += total;
            pw <<= 1;
        }
        return cnt;
    }
};

4)
class Solution {
public:
    unordered_map<int, int> memo;
    int countSetBits(int n) {
        if (n == 0) return 0;
        if (memo.count(n)) return memo[n];
        int x = log2(n);
        int pw = 1 << x;
        int res = x * (pw >> 1) + (n - pw + 1) + countSetBits(n - pw);
        return memo[n] = res;
    }
};
