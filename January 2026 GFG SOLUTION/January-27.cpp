class Solution {
public:
    bool isWordExist(vector<vector<char>>& b, string w) {
        int m = b.size(), n = b[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (search(b, w, i, j, 0)) return true;
        return false;
    }
    
    bool search(vector<vector<char>>& b, string& w, int r, int c, int idx) {
        if (idx == w.size()) return true;
        if (r < 0 || c < 0 || r >= b.size() || c >= b[0].size() || b[r][c] != w[idx]) return false;
        char tmp = b[r][c];
        b[r][c] = '*';
        bool res = search(b, w, r + 1, c, idx + 1) || search(b, w, r - 1, c, idx + 1) ||
                   search(b, w, r, c + 1, idx + 1) || search(b, w, r, c - 1, idx + 1);
        b[r][c] = tmp;
        return res;
    }
};

2)
class Solution {
public:
    bool isWordExist(vector<vector<char>>& b, string w) {
        unordered_map<char, int> boardFreq, wordFreq;
        for (auto& row : b)
            for (char c : row) boardFreq[c]++;
        for (char c : w) wordFreq[c]++;
        for (auto& [ch, cnt] : wordFreq)
            if (boardFreq[ch] < cnt) return false;
        if (boardFreq[w[0]] > boardFreq[w.back()]) {
            reverse(w.begin(), w.end());
        }
        for (int i = 0; i < b.size(); i++)
            for (int j = 0; j < b[0].size(); j++)
                if (b[i][j] == w[0] && dfs(b, w, i, j, 0)) return true;
        return false;
    }
    
    bool dfs(vector<vector<char>>& b, string& w, int i, int j, int k) {
        if (k == w.size()) return true;
        if (i < 0 || j < 0 || i >= b.size() || j >= b[0].size() || b[i][j] != w[k]) return false;
        char t = b[i][j];
        b[i][j] = '#';
        bool f = dfs(b, w, i + 1, j, k + 1) || dfs(b, w, i - 1, j, k + 1) ||
                 dfs(b, w, i, j + 1, k + 1) || dfs(b, w, i, j - 1, k + 1);
        b[i][j] = t;
        return f;
    }
};
