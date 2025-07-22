class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] <= 0) arr[i] = n + 1;
        }
        for (int i = 0; i < n; i++) {
            int idx = abs(arr[i]) - 1;
            if (idx < n && arr[idx] > 0) arr[idx] = -arr[idx];
        }
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) return i + 1;
        }
        return n + 1;
    }
};

2)
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        for (int i = 1; i <= arr.size() + 1; i++) {
            if (s.find(i) == s.end()) return i;
        }
        return arr.size() + 1;
    }
};

3)
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int missing = 1;
        for (int x : arr) {
            if (x == missing) missing++;
            else if (x > missing) break;
        }
        return missing;
    }
};

4)
class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) if (a[i] <= 0) a[i] = n + 1;
        for (int i = 0; i < n; i++) {
            int x = abs(a[i]);
            if (x <= n) a[x - 1] = -abs(a[x - 1]);
        }
        for (int i = 0; i < n; i++) if (a[i] > 0) return i + 1;
        return n + 1;
    }
};

5)
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        vector<bool> present(n+2, false);
        for (int x : arr) if (x > 0 && x <= n) present[x] = true;
        for (int i = 1; i <= n+1; i++)
            if (!present[i]) return i;
        return n+1;
    }
};


6)
class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n; ++i)
            while (a[i] > 0 && a[i] <= n && a[i] != a[a[i] - 1])
                swap(a[i], a[a[i] - 1]);
        for (int i = 0; i < n; ++i)
            if (a[i] != i + 1) return i + 1;
        return n + 1;
    }
};
