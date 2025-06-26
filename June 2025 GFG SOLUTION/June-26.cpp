class Solution {
public:
    int minValue(string &s, int k) {
        int f[26] = {}, m = 0;
        for (char c : s) m = max(m, ++f[c - 'a']);
        vector<int> b(m + 1);
        for (int x : f) if (x) b[x]++;
        while (k && m) {
            if (b[m] <= k) k -= b[m], b[m - 1] += b[m], b[m--] = 0;
            else b[m] -= k, b[m - 1] += k, k = 0;
        }
        int r = 0;
        for (int i = 1; i <= m; i++) r += i * i * b[i];
        return r;
    }
};

2)
class Solution {
public:
    int minValue(string &s, int k) {
        unordered_map<char, int> f;
        for (char c : s) f[c]++;
        priority_queue<int> pq;
        for (auto& p : f) pq.push(p.second);
        while (k-- && pq.top()) {
            int x = pq.top(); pq.pop();
            pq.push(x - 1);
        }
        int r = 0;
        while (!pq.empty()) r += pq.top() * pq.top(), pq.pop();
        return r;
    }
};

3)
class Solution {
public:
    int minValue(string &s, int k) {
        int f[26] = {};
        for (char c : s) f[c - 'a']++;
        while (k--) {
            int m = max_element(f, f + 26) - f;
            if (f[m]) f[m]--;
        }
        int r = 0;
        for (int i = 0; i < 26; i++) r += f[i] * f[i];
        return r;
    }
};
