class Solution {
public:
    vector<string> possibleWords(vector<int> &arr) {
        vector<string> res = {""};
        string keys[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int d : arr) {
            if (d < 2 || d > 9) continue;
            vector<string> temp;
            for (string &s : res)
                for (char c : keys[d])
                    temp.push_back(s + c);
            res = move(temp);
        }
        return res;
    }
};

2)
class Solution {
    void solve(vector<int> &arr, int i, string cur, string keys[], vector<string> &ans) {
        if (i == arr.size()) { ans.push_back(cur); return; }
        if (arr[i] < 2 || arr[i] > 9) { solve(arr, i + 1, cur, keys, ans); return; }
        for (char c : keys[arr[i]]) solve(arr, i + 1, cur + c, keys, ans);
    }
public:
    vector<string> possibleWords(vector<int> &arr) {
        vector<string> ans;
        string keys[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(arr, 0, "", keys, ans);
        return ans;
    }
};

3)
class Solution {
public:
    vector<string> possibleWords(vector<int> &arr) {
        queue<string> q;
        q.push("");
        string keys[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int d : arr) {
            if (d < 2 || d > 9) continue;
            int sz = q.size();
            while (sz--) {
                string cur = q.front(); q.pop();
                for (char c : keys[d]) q.push(cur + c);
            }
        }
        vector<string> res;
        while (!q.empty()) { res.push_back(q.front()); q.pop(); }
        return res;
    }
};

4)
class Solution {
public:
    vector<string> possibleWords(vector<int> &arr) {
        string keys[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> dp = {""};
        for (int d : arr) {
            if (d < 2 || d > 9) continue;
            vector<string> next;
            next.reserve(dp.size() * keys[d].size());
            for (const string &s : dp)
                for (char c : keys[d])
                    next.push_back(s + c);
            dp = move(next);
        }
        return dp;
    }
};
