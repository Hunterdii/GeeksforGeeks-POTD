class Solution {
public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        vector<bool> present(high - low + 1, false);
        for (int x : arr) {
            if (x >= low && x <= high) present[x - low] = true;
        }
        vector<int> ans;
        for (int i = 0; i <= high - low; i++) {
            if (!present[i]) ans.push_back(low + i);
        }
        return ans;
    }
};

2)
class Solution {
public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        unordered_set<int> s(arr.begin(), arr.end());
        vector<int> ans;
        for (int x = low; x <= high; x++) {
            if (s.find(x) == s.end()) ans.push_back(x);
        }
        return ans;
    }
};

3)
class Solution {
public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        sort(arr.begin(), arr.end());
        vector<int> ans;
        int j = 0, n = arr.size();
        for (int i = low; i <= high; i++) {
            while (j < n && arr[j] < i) j++;
            if (j >= n || arr[j] != i) ans.push_back(i);
        }
        return ans;
    }
};

4)
class Solution {
public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (int x = low; x <= high; x++) {
            if (!binary_search(arr.begin(), arr.end(), x)) ans.push_back(x);
        }
        return ans;
    }
};

5)
class Solution {
public:
    vector<int> missinRange(vector<int>& arr, int low, int high) {
        unordered_set<int> s;
        for (int x : arr) {
            if (x >= low && x <= high) s.insert(x);
        }
        vector<int> ans;
        for (int i = low; i <= high; i++) {
            if (s.find(i) == s.end()) ans.push_back(i);
        }
        return ans;
    }
};
