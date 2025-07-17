class Solution {
public:
    int maxKPower(int n, int k) {
        int ans = INT_MAX;
        if (k % 2 == 0) {
            int twos = __builtin_ctz(k);
            k >>= twos;
            int leg = n - __builtin_popcount(n);
            ans = min(ans, leg / twos);
        }
        for (int i = 3; i * i <= k; i += 2) {
            if (k % i == 0) {
                int exp = 0;
                while (k % i == 0) k /= i, exp++;
                int leg = 0;
                for (int p = i; p <= n; p *= i) leg += n / p;
                ans = min(ans, leg / exp);
            }
        }
        if (k > 1) {
            int leg = 0;
            for (int p = k; p <= n; p *= k) leg += n / p;
            ans = min(ans, leg);
        }
        return ans;
    }
};


2)
class Solution {
public:
    int maxKPower(int n, int k) {
        int result = INT_MAX;
        for (int i = 2; i * i <= k && k > 1; i++) {
            if (k % i == 0) {
                int count = 0;
                while (k % i == 0) k /= i, count++;
                int legendre = 0;
                for (long long p = i; p <= n; p *= i) legendre += n / p;
                result = min(result, legendre / count);
                if (result == 0) return 0;
            }
        }
        if (k > 1) {
            int legendre = 0;
            for (long long p = k; p <= n; p *= k) legendre += n / p;
            result = min(result, legendre);
        }
        return result == INT_MAX ? 0 : result;
    }
};


3)
class Solution {
public:
    int maxKPower(int n, int k) {
        int ans = INT_MAX;
        for (int d = 2; d * d <= k; d++) {
            int exp = 0;
            while (k % d == 0) k /= d, exp++;
            if (exp) {
                int leg = 0;
                for (int pw = d; pw <= n; pw *= d) leg += n / pw;
                ans = min(ans, leg / exp);
            }
        }
        if (k > 1) {
            int leg = 0;
            for (int pw = k; pw <= n; pw *= k) leg += n / pw;
            ans = min(ans, leg);
        }
        return ans;
    }
};


4)
class Solution {
public:
    int maxKPower(int n, int k) {
        int res = INT_MAX;
        for (int i = 2; i * i <= k; i++) {
            if (k % i == 0) {
                int cnt = 0;
                while (k % i == 0) k /= i, cnt++;
                int fact = 0;
                for (int p = i; p <= n; p *= i) fact += n / p;
                res = min(res, fact / cnt);
            }
        }
        if (k > 1) {
            int fact = 0;
            for (int p = k; p <= n; p *= k) fact += n / p;
            res = min(res, fact);
        }
        return res == INT_MAX ? 0 : res;
    }
};
