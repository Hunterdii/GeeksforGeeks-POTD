class Solution {
  public:
    int atMostK(string &s, int k) {
        unordered_map<char, int> mp;
        int i = 0, res = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (++mp[s[j]] == 1) --k;
            while (k < 0)
                if (--mp[s[i++]] == 0) ++k;
            res += j - i + 1;
        }
        return res;
    }

    int countSubstr(string &s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};

2)
class Solution {
  public:
    int count(string &s, int k) {
        int n = s.length(), ans = 0;
        vector<int> freq(26, 0);
        int i = 0, distinct = 0;
        for (int j = 0; j < n; ++j) {
            if (++freq[s[j] - 'a'] == 1) ++distinct;
            while (distinct > k)
                if (--freq[s[i++] - 'a'] == 0) --distinct;
            ans += j - i + 1;
        }
        return ans;
    }
    
    int countSubstr(string &s, int k) {
        return count(s, k) - count(s, k - 1);
    }
};

3)
class Solution {
  public:
    int countSubstr(string &s, int k) {
        int n = s.length(), ans = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0);
            int distinct = 0;
            for (int j = i; j < n; ++j) {
                if (++freq[s[j] - 'a'] == 1) ++distinct;
                if (distinct == k) ++ans;
                if (distinct > k) break;
            }
        }
        return ans;
    }
};
