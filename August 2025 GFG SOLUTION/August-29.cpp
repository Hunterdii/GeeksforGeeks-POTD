class Solution {
public:
    string smallestWindow(string &s, string &p) {
        int m = s.size(), n = p.size();
        if (m < n) return "";
        int freq[256] = {0}, window[256] = {0};
        for (char c : p) freq[c]++;
        int formed = 0, required = 0;
        for (int i = 0; i < 256; i++) if (freq[i] > 0) required++;
        int l = 0, r = 0, minLen = INT_MAX, minStart = 0;
        while (r < m) {
            window[s[r]]++;
            if (freq[s[r]] > 0 && window[s[r]] == freq[s[r]]) formed++;
            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minStart = l;
                }
                window[s[l]]--;
                if (freq[s[l]] > 0 && window[s[l]] < freq[s[l]]) formed--;
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};

2)
class Solution {
public:
    string smallestWindow(string &s, string &p) {
        if (s.empty() || p.empty() || s.size() < p.size()) return "";
        unordered_map<char, int> patternCount, windowCount;
        for (char c : p) patternCount[c]++;
        int left = 0, minStart = 0, minLen = INT_MAX, matched = 0;
        for (int right = 0; right < s.size(); right++) {
            windowCount[s[right]]++;
            if (patternCount.count(s[right]) && windowCount[s[right]] == patternCount[s[right]]) {
                matched++;
            }
            while (matched == patternCount.size()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                windowCount[s[left]]--;
                if (patternCount.count(s[left]) && windowCount[s[left]] < patternCount[s[left]]) {
                    matched--;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};

3)
class Solution {
public:
    string smallestWindow(string &s, string &p) {
        vector<int> need(128, 0);
        for (char c : p) need[c]++;
        int missing = p.size(), start = 0, minStart = 0, minLen = INT_MAX;
        for (int end = 0; end < s.size(); end++) {
            if (need[s[end]]-- > 0) missing--;
            while (!missing) {
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    minStart = start;
                }
                if (++need[s[start++]] > 0) missing++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};


4)
class Solution {
public:
    string smallestWindow(string &s, string &p) {
        unordered_map<char, int> pCount;
        for (char c : p) pCount[c]++;
        int required = pCount.size(), formed = 0;
        int l = 0, r = 0, minLen = INT_MAX, minL = 0;
        unordered_map<char, int> windowCount;
        while (r < s.length()) {
            char c = s[r];
            windowCount[c]++;
            if (pCount.count(c) && windowCount[c] == pCount[c]) formed++;
            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minL = l;
                }
                char leftChar = s[l];
                windowCount[leftChar]--;
                if (pCount.count(leftChar) && windowCount[leftChar] < pCount[leftChar]) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(minL, minLen);
    }
};
