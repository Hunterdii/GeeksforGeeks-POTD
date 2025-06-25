class Solution {
public:
    bool sameFreq(string& s) {
        vector<int> freq(26);
        for (char c : s) freq[c - 'a']++;
        unordered_map<int, int> m;
        for (int f : freq) if (f) m[f]++;
        if (m.size() == 1) return true;
        if (m.size() == 2) {
            auto a = m.begin(), b = next(a);
            int f1 = a->first, c1 = a->second;
            int f2 = b->first, c2 = b->second;
            return (f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1) ||
                  (abs(f1 - f2) == 1 && ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1)));
        }
        return false;
    }
};


2)
class Solution {
public:
    bool sameFreq(string& s) {
        int f[26] = {};
        for (char c : s) f[c - 'a']++;
        unordered_set<int> sfx;
        for (int i = 0; i < 26; i++) {
            if (f[i]) {
                sfx.insert(f[i]);
                if (sfx.size() > 2) return false;
            }
        }
        if (sfx.size() == 1) return true;
        vector<int> v(sfx.begin(), sfx.end());
        sort(v.begin(), v.end());
        int c1 = 0, c2 = 0;
        for (int i = 0; i < 26; i++) {
            if (f[i] == v[0]) c1++;
            else if (f[i] == v[1]) c2++;
        }
        return (v[0] == 1 && c1 == 1) || (v[1] - v[0] == 1 && c2 == 1);
    }
};


3)
class Solution {
public:
    bool sameFreq(string& s) {
        int f[26] = {};
        for (char c : s) f[c - 'a']++;
        int m = 0, hi = 0, lo = INT_MAX;
        for (int x : f) {
            if (x) {
                m |= 1 << (x & 31);
                hi = max(hi, x);
                lo = min(lo, x);
            }
        }
        if (__builtin_popcount(m) == 1) return true;
        if (__builtin_popcount(m) != 2) return false;
        int c1 = 0, c2 = 0;
        for (int x : f) {
            if (x == lo) c1++;
            else if (x == hi) c2++;
        }
        return (lo == 1 && c1 == 1) || (hi - lo == 1 && c2 == 1);
    }
};
