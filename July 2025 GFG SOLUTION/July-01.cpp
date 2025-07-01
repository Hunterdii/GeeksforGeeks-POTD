class Solution {
public:
    int substrCount(string &s, int k) {
        if (k > s.length()) return 0;
        vector<int> cnt(26);
        int ans = 0, d = 0, n = s.length();
        for (int i = 0; i < k - 1; i++) if (++cnt[s[i]-'a'] == 1) d++;
        for (int i = k - 1; i < n; i++) {
            if (++cnt[s[i]-'a'] == 1) d++;
            if (d == k - 1) ans++;
            if (--cnt[s[i-k+1]-'a'] == 0) d--;
        }
        return ans;
    }
};


2)
class Solution {
public:
    int substrCount(string &s, int k) {
        if (k > s.length()) return 0;
        unordered_map<char, int> mp;
        int ans = 0;
        for (int i = 0; i < k - 1; i++) mp[s[i]]++;
        for (int i = k - 1; i < s.length(); i++) {
            mp[s[i]]++;
            if (mp.size() == k - 1) ans++;
            if (--mp[s[i - k + 1]] == 0) mp.erase(s[i - k + 1]);
        }
        return ans;
    }
};


3)
class Solution {
public:
    int substrCount(string &s, int k) {
        if (k > s.length()) return 0;
        unordered_map<char, int> freq;
        int ans = 0, distinct = 0;
        for (int i = 0; i < k - 1; i++) {
            if (++freq[s[i]] == 1) distinct++;
        }
        for (int i = k - 1; i < s.length(); i++) {
            if (++freq[s[i]] == 1) distinct++;
            if (distinct == k - 1) ans++;
            if (--freq[s[i - k + 1]] == 0) distinct--;
        }
        return ans;
    }
};


4)
class Solution {
public:
    int substrCount(string &s, int k) {
        if (k > s.length() || k <= 0) return 0;
        if (k == 1) return s.length();
        bitset<26> present;
        vector<int> cnt(26, 0);
        int ans = 0, distinct = 0;
        for (int i = 0; i < k - 1; i++) {
            int idx = s[i] - 'a';
            if (!present[idx]) {
                present[idx] = 1;
                distinct++;
            }
            cnt[idx]++;
        }
        for (int i = k - 1; i < s.length(); i++) {
            int addIdx = s[i] - 'a';
            int remIdx = s[i - k + 1] - 'a';
            if (!present[addIdx]) {
                present[addIdx] = 1;
                distinct++;
            }
            cnt[addIdx]++;
            if (distinct == k - 1) ans++;
            if (--cnt[remIdx] == 0) {
                present[remIdx] = 0;
                distinct--;
            }
        }
        return ans;
    }
};
