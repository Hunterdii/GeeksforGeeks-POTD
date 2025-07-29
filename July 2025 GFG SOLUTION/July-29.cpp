class Solution {
public:
    vector<int> asciirange(string& s) {
        vector<int> result;
        int n = s.size();
        for (int i = 0; i < 26; i++) {
            int first = -1, last = -1;
            for (int j = 0; j < n; j++) {
                if (s[j] - 'a' == i) {
                    if (first == -1) first = j;
                    last = j;
                }
            }
            if (first != -1 && last > first) {
                int sum = 0;
                for (int k = first + 1; k < last; k++) sum += s[k];
                if (sum) result.push_back(sum);
            }
        }
        return result;
    }
};

2)
class Solution {
public:
    vector<int> asciirange(string& s) {
        vector<int> first(26, -1), last(26, -1), result;
        for (int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            if (first[ch] == -1) first[ch] = i;
            last[ch] = i;
        }
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1 && last[i] > first[i]) {
                int sum = 0;
                for (int j = first[i] + 1; j < last[i]; j++) sum += s[j];
                if (sum) result.push_back(sum);
            }
        }
        return result;
    }
};

3)
class Solution {
public:
    vector<int> asciirange(string& s) {
        int n = s.size();
        vector<int> prefix(n + 1, 0), first(26, -1), last(26, -1), result;
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + s[i];
            int ch = s[i] - 'a';
            if (first[ch] == -1) first[ch] = i;
            last[ch] = i;
        }
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1 && last[i] > first[i]) {
                int sum = prefix[last[i]] - prefix[first[i] + 1];
                if (sum) result.push_back(sum);
            }
        }
        return result;
    }
};

4)
class Solution {
public:
    vector<int> asciirange(string& s) {
        unordered_map<char, pair<int, int>> positions;
        vector<int> result;
        for (int i = 0; i < s.size(); i++) {
            if (positions.find(s[i]) == positions.end()) {
                positions[s[i]] = {i, i};
            } else {
                positions[s[i]].second = i;
            }
        }
        for (auto& p : positions) {
            if (p.second.second > p.second.first) {
                int sum = 0;
                for (int j = p.second.first + 1; j < p.second.second; j++) {
                    sum += s[j];
                }
                if (sum) result.push_back(sum);
            }
        }
        return result;
    }
};
