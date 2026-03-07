class Solution {
public:
    string minWindow(string &s, string &p) {
        int n = s.size(), m = p.size();
        if (n < m) return "";
        vector<int> fp(256, 0), fs(256, 0);
        for (char c : p) fp[c]++;
        int l = 0, cnt = 0, minLen = INT_MAX, start = -1;
        for (int r = 0; r < n; r++) {
            fs[s[r]]++;
            if (fp[s[r]] && fs[s[r]] <= fp[s[r]]) cnt++;
            while (cnt == m) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                fs[s[l]]--;
                if (fp[s[l]] && fs[s[l]] < fp[s[l]]) cnt--;
                l++;
            }
        }
        return start == -1 ? "" : s.substr(start, minLen);
    }
};

2)
class Solution {
public:
    string minWindow(string &s, string &p) {
        if (s.length() < p.length()) return "";
        unordered_map<char, int> pCount, sCount;
        for (char c : p) pCount[c]++;
        int required = pCount.size(), formed = 0;
        int l = 0, r = 0, minLen = INT_MAX, minStart = 0;
        
        while (r < s.length()) {
            char c = s[r];
            sCount[c]++;
            if (pCount.count(c) && sCount[c] == pCount[c])
                formed++;
            
            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minStart = l;
                }
                char leftChar = s[l];
                sCount[leftChar]--;
                if (pCount.count(leftChar) && sCount[leftChar] < pCount[leftChar])
                    formed--;
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};

3)
class Solution {
public:
    string minWindow(string &s, string &p) {
        vector<int> map(128, 0);
        for (char c : p) map[c]++;
        int counter = p.size(), begin = 0, end = 0, minLen = INT_MAX, head = 0;
        
        while (end < s.size()) {
            if (map[s[end++]]-- > 0) counter--;
            
            while (counter == 0) {
                if (end - begin < minLen) {
                    minLen = end - begin;
                    head = begin;
                }
                if (map[s[begin++]]++ == 0) counter++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(head, minLen);
    }
};

4)
class Solution {
public:
    bool isValid(string& sub, string& p) {
        vector<int> freq(256, 0);
        for (char c : p) freq[c]++;
        for (char c : sub) freq[c]--;
        for (char c : p) {
            if (freq[c] > 0) return false;
        }
        return true;
    }
    
    string minWindow(string &s, string &p) {
        int n = s.size(), m = p.size();
        if (n < m) return "";
        string result = "";
        int minLen = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + m - 1; j < n; j++) {
                string sub = s.substr(i, j - i + 1);
                if (isValid(sub, p) && sub.length() < minLen) {
                    minLen = sub.length();
                    result = sub;
                }
            }
        }
        return result;
    }
};
