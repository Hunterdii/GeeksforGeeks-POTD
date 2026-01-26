class Solution {
public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        do {
            res.push_back(arr);
        } while (next_permutation(arr.begin(), arr.end()));
        return res;
    }
};

2)
class Solution {
public:
    void solve(vector<int>& arr, int idx, vector<vector<int>>& res) {
        if (idx == arr.size()) {
            res.push_back(arr);
            return;
        }
        for (int i = idx; i < arr.size(); i++) {
            swap(arr[idx], arr[i]);
            solve(arr, idx + 1, res);
            swap(arr[idx], arr[i]);
        }
    }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> res;
        solve(arr, 0, res);
        return res;
    }
};

3)
class Solution {
public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> res;
        int n = arr.size();
        vector<int> c(n, 0);
        res.push_back(arr);
        int i = 0;
        while (i < n) {
            if (c[i] < i) {
                if (i % 2 == 0) swap(arr[0], arr[i]);
                else swap(arr[c[i]], arr[i]);
                res.push_back(arr);
                c[i]++;
                i = 0;
            } else {
                c[i] = 0;
                i++;
            }
        }
        return res;
    }
};

4)
class Solution {
public:
    bool nextPerm(vector<int>& arr) {
        int i = arr.size() - 2;
        while (i >= 0 && arr[i] >= arr[i + 1]) i--;
        if (i < 0) return false;
        int j = arr.size() - 1;
        while (arr[j] <= arr[i]) j--;
        swap(arr[i], arr[j]);
        reverse(arr.begin() + i + 1, arr.end());
        return true;
    }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        res.push_back(arr);
        while (nextPerm(arr)) res.push_back(arr);
        return res;
    }
};
