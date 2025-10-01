class Solution {
public:
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        do {
            res.push_back(arr);
        } while (next_permutation(arr.begin(), arr.end()));
        return res;
    }
};

2)
class Solution {
public:
    void solve(vector<int>& arr, vector<bool>& vis, vector<int>& temp, vector<vector<int>>& res) {
        if (temp.size() == arr.size()) {
            res.push_back(temp);
            return;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (vis[i] || (i > 0 && arr[i] == arr[i-1] && !vis[i-1])) continue;
            vis[i] = true;
            temp.push_back(arr[i]);
            solve(arr, vis, temp, res);
            temp.pop_back();
            vis[i] = false;
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> vis(arr.size(), false);
        solve(arr, vis, temp, res);
        return res;
    }
};

3)
class Solution {
public:
    void solve(vector<int>& arr, int idx, vector<vector<int>>& res) {
        if (idx == arr.size()) {
            res.push_back(arr);
            return;
        }
        unordered_set<int> used;
        for (int i = idx; i < arr.size(); i++) {
            if (used.count(arr[i])) continue;
            used.insert(arr[i]);
            swap(arr[idx], arr[i]);
            solve(arr, idx + 1, res);
            swap(arr[idx], arr[i]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        vector<vector<int>> res;
        solve(arr, 0, res);
        sort(res.begin(), res.end());
        return res;
    }
};

4)
class Solution {
public:
    void solve(vector<int>& arr, int idx, set<vector<int>>& res) {
        if (idx == arr.size()) {
            res.insert(arr);
            return;
        }
        for (int i = idx; i < arr.size(); i++) {
            swap(arr[idx], arr[i]);
            solve(arr, idx + 1, res);
            swap(arr[idx], arr[i]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        set<vector<int>> st;
        solve(arr, 0, st);
        return vector<vector<int>>(st.begin(), st.end());
    }
};

