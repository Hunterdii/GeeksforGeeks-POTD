class Solution {
public:
    int cntCoprime(vector<int>& arr) {
        int mx = *max_element(arr.begin(), arr.end());
        vector<int> cnt(mx + 1), div(mx + 1), mu(mx + 1, 1);
        vector<bool> vis(mx + 1);
        for (int x : arr) cnt[x]++;
        for (int i = 1; i <= mx; ++i)
            for (int j = i; j <= mx; j += i)
                div[i] += cnt[j];
        for (int i = 2; i <= mx; ++i) {
            if (!vis[i]) {
                for (int j = i; j <= mx; j += i) {
                    mu[j] *= -1;
                    vis[j] = 1;
                }
                for (long long j = (long long)i * i; j <= mx; j += (long long)i * i)
                    mu[j] = 0;
            }
        }
        int ans = 0;
        for (int i = 1; i <= mx; ++i)
            if (mu[i] && div[i] > 1)
                ans += mu[i] * div[i] * (div[i] - 1) / 2;
        return ans;
    }
};

2)
class Solution {
public:
    int cntCoprime(vector<int>& arr) {
        int n = *max_element(arr.begin(), arr.end());
        vector<int> f(n + 1), d(n + 1), mu(n + 1, 1);
        vector<bool> vis(n + 1);
        for (int x : arr) f[x]++;
        for (int i = 2; i <= n; ++i) {
            if (!vis[i]) {
                for (int j = i; j <= n; j += i) {
                    mu[j] *= -1;
                    vis[j] = 1;
                }
                for (long long j = (long long)i * i; j <= n; j += (long long)i * i)
                    mu[j] = 0;
            }
        }
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; j += i)
                d[i] += f[j];
        int res = 0;
        for (int i = 1; i <= n; ++i)
            if (mu[i] && d[i] > 1)
                res += mu[i] * d[i] * (d[i] - 1) / 2;
        return res;
    }
};


3)
class Solution {
public:
    int cntCoprime(vector<int>& arr) {
        int mx = *max_element(arr.begin(), arr.end());
        vector<int> freq(mx + 1), cnt(mx + 1);
        for (int x : arr) freq[x]++;
        for (int g = 1; g <= mx; ++g) {
            for (int mul = g; mul <= mx; mul += g)
                cnt[g] += freq[mul];
        }
        vector<int> coprime(mx + 1);
        for (int g = mx; g >= 1; --g) {
            coprime[g] = cnt[g] * (cnt[g] - 1) / 2;
            for (int mul = g + g; mul <= mx; mul += g)
                coprime[g] -= coprime[mul];
        }
        return coprime[1];
    }
};


4)
class Solution {
public:
    int cntCoprime(vector<int>& arr) {
        int n = *max_element(arr.begin(), arr.end());
        vector<int> spf(n + 1), f(n + 1), d(n + 1);
        iota(spf.begin(), spf.end(), 0);
        for (int i = 2; i * i <= n; ++i)
            if (spf[i] == i)
                for (int j = i * i; j <= n; j += i)
                    if (spf[j] == j) spf[j] = i;
        for (int x : arr) f[x]++;
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; j += i)
                d[i] += f[j];
        auto mobius = [&](int x) {
            int res = 1, prev = -1;
            while (x > 1) {
                int p = spf[x], cnt = 0;
                while (x % p == 0) x /= p, cnt++;
                if (cnt > 1) return 0;
                res *= -1;
            }
            return res;
        };
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (d[i] > 1) {
                int mu = mobius(i);
                if (mu) ans += mu * d[i] * (d[i] - 1) / 2;
            }
        }
        return ans;
    }
};


5)
class Solution {
public:
    int cntCoprime(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (__gcd(arr[i], arr[j]) == 1) {
                    count++;
                }
            }
        }
        
        return count;
    }
};


