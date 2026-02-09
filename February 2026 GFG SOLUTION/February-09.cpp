class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (arr[m] > arr[r]) l = m + 1;
            else r = m;
        }
        return l;
    }
};

2)
class Solution {
public:
    int helper(vector<int> &arr, int l, int r) {
        if (l >= r) return l;
        int m = l + (r - l) / 2;
        if (arr[m] > arr[r]) return helper(arr, m + 1, r);
        return helper(arr, l, m);
    }
    int findKRotation(vector<int> &arr) {
        return helper(arr, 0, arr.size() - 1);
    }
};

3)
class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int l = 0, r = arr.size() - 1, idx = 0, minVal = INT_MAX;
        while (l <= r) {
            if (arr[l] <= arr[r]) {
                if (arr[l] < minVal) {
                    minVal = arr[l];
                    idx = l;
                }
                break;
            }
            int m = l + (r - l) / 2;
            if (arr[l] <= arr[m]) {
                if (arr[l] < minVal) {
                    minVal = arr[l];
                    idx = l;
                }
                l = m + 1;
            } else {
                if (arr[m] < minVal) {
                    minVal = arr[m];
                    idx = m;
                }
                r = m - 1;
            }
        }
        return idx;
    }
};

4)
class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1]) return i + 1;
        return 0;
    }
};

5)
class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int l = 0, r = arr.size() - 1;
        while (l <= r) {
            if (arr[l] <= arr[r]) return l;
            int m = l + (r - l) / 2;
            int next = (m + 1) % arr.size();
            int prev = (m - 1 + arr.size()) % arr.size();
            if (arr[m] <= arr[next] && arr[m] <= arr[prev]) return m;
            if (arr[m] <= arr[r]) r = m - 1;
            else l = m + 1;
        }
        return 0;
    }
};
