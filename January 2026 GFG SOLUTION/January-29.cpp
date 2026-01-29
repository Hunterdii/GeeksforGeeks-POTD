class Solution {
public:
    string firstNonRepeating(string &s) {
        int freq[26] = {0};
        queue<char> q;
        string res = "";
        for (char c : s) {
            freq[c - 'a']++;
            q.push(c);
            while (!q.empty() && freq[q.front() - 'a'] > 1) q.pop();
            res += q.empty() ? '#' : q.front();
        }
        return res;
    }
};

2)
class Solution {
public:
    string firstNonRepeating(string &s) {
        list<char> dll;
        unordered_map<char, pair<int, list<char>::iterator>> mp;
        string res = "";
        for (char c : s) {
            if (mp.find(c) == mp.end()) {
                dll.push_back(c);
                mp[c] = {1, --dll.end()};
            } else if (mp[c].first == 1) {
                dll.erase(mp[c].second);
                mp[c].first = 2;
            }
            res += dll.empty() ? '#' : dll.front();
        }
        return res;
    }
};

3)
class Solution {
public:
    string firstNonRepeating(string &s) {
        int freq[26] = {0}, pos[26];
        fill(pos, pos + 26, -1);
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (pos[s[i] - 'a'] == -1) pos[s[i] - 'a'] = i;
            freq[s[i] - 'a']++;
            int mn = INT_MAX;
            char ch = '#';
            for (int j = 0; j < 26; j++) {
                if (freq[j] == 1 && pos[j] < mn) {
                    mn = pos[j];
                    ch = 'a' + j;
                }
            }
            res += ch;
        }
        return res;
    }
};

4)
class Solution {
public:
    string firstNonRepeating(string &s) {
        int cnt[26] = {0};
        deque<char> dq;
        string res = "";
        for (char c : s) {
            cnt[c - 'a']++;
            if (cnt[c - 'a'] == 1) dq.push_back(c);
            while (!dq.empty() && cnt[dq.front() - 'a'] > 1) dq.pop_front();
            res += dq.empty() ? '#' : dq.front();
        }
        return res;
    }
};
