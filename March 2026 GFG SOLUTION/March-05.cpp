class Solution {
public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> mp;
        int l = 0, res = -1;
        for (int r = 0; r < s.size(); r++) {
            mp[s[r]]++;
            while (mp.size() > k) {
                if (--mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            if (mp.size() == k) res = max(res, r - l + 1);
        }
        return res;
    }
};

2)
class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        int cnt = 0;
        int maxi = -1;
        vector<int> fre(26, 0);
        while (j < n) {
            fre[s[j] - 'a']++;
            if (fre[s[j] - 'a'] == 1)
                cnt++;
            while (cnt > k) {
                fre[s[i] - 'a']--;
                if (fre[s[i] - 'a'] == 0)
                    cnt--;
                i++;
            }
            if (cnt == k) {
                maxi = max(maxi, j - i + 1);
            }
            j++;
        }
        return maxi;
    }
};

3)
class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size(), maxLen = -1;
        for (int i = 0; i < n; i++) {
            unordered_set<char> distinct;
            for (int j = i; j < n; j++) {
                distinct.insert(s[j]);
                if (distinct.size() == k)
                    maxLen = max(maxLen, j - i + 1);
                else if (distinct.size() > k)
                    break;
            }
        }
        return maxLen;
    }
};

4)
class Solution {
public:
    int longestKSubstr(string &s, int k) {
        unordered_set<char> allChars(s.begin(), s.end());
        if (allChars.size() < k) return -1;
        
        unordered_map<char, int> mp;
        int l = 0, res = -1;
        for (int r = 0; r < s.size(); r++) {
            mp[s[r]]++;
            while (mp.size() > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            if (mp.size() == k)
                res = max(res, r - l + 1);
        }
        return res;
    }
};
