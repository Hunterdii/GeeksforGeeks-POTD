class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size(), i = 0, cnt = 0, maxi = -1;
        vector<int> fre(26, 0);
        for (int j = 0; j < n; j++) {
            if (fre[s[j] - 'a']++ == 0) cnt++;
            while (cnt > k) {
                if (--fre[s[i] - 'a'] == 0) cnt--;
                i++;
            }
            if (cnt == k) maxi = max(maxi, j - i + 1);
        }
        return maxi;
    }
};


2)
class Solution {
public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> mp;
        int i = 0, maxLen = -1;
        for (int j = 0; j < s.size(); j++) {
            mp[s[j]]++;
            while (mp.size() > k) {
                if (--mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            if (mp.size() == k) maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};


3)
class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size(), maxLen = -1;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int distinct = 0;
            for (int j = i; j < n; j++) {
                if (freq[s[j] - 'a']++ == 0) distinct++;
                if (distinct == k) maxLen = max(maxLen, j - i + 1);
                else if (distinct > k) break;
            }
        }
        return maxLen;
    }
};


4)
class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int freq[26] = {0}, distinct = 0, left = 0, maxLen = -1;
        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right] - 'a']++ == 0) distinct++;
            while (distinct > k) {
                if (--freq[s[left] - 'a'] == 0) distinct--;
                left++;
            }
            if (distinct == k) maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
