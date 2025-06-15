class Solution {
public:
    int smallestDivisor(vector<int>& arr, int k) {
        int l = 1, h = *max_element(arr.begin(), arr.end()), n = arr.size();
        while (l < h) {
            int m = (l + h) >> 1, s = 0;
            for (int i = 0; i < n; ++i) s += (arr[i] + m - 1) / m;
            s <= k ? h = m : l = m + 1;
        }
        return l;
    }
};

2)
class Solution {
public:
    int smallestDivisor(vector<int>& arr, int k) {
        int l = 1, h = *max_element(arr.begin(), arr.end()), n = arr.size();
        while (l < h) {
            int m = l + (h - l) / 2, s = 0;
            for (int i = 0; i < n; ++i)
                s += (arr[i] + m - 1) / m;
            if (s <= k) h = m;
            else l = m + 1;
        }
        return l;
    }
};

3)
class Solution {
public:
    int smallestDivisor(vector<int>& arr, int k) {
        int l = 1, h = *max_element(arr.begin(), arr.end()), n = arr.size();
        while (l < h) {
            int m = (l + h) >> 1, s = 0;
            for (int i = 0; i < n; ++i) s += (arr[i] + m - 1) / m;
            s <= k ? h = m : l = m + 1;
        }
        return l;
    }
};

4)
class Solution {
public:
    int smallestDivisor(vector<int>& arr, int k) {
        int l = 1, h = *max_element(arr.begin(), arr.end()), r = h;
        while (l <= h) {
            int m = l + (h - l) / 2, s = 0;
            for (int x : arr) s += (x % m == 0) ? x / m : x / m + 1;
            if (s <= k) r = m, h = m - 1;
            else l = m + 1;
        }
        return r;
    }
};

5)
class Solution {
public:
    int smallestDivisor(vector<int>& arr, int k) {
        int l = 1, h = *max_element(arr.begin(), arr.end());
        while (h - l > 2) {
            int m1 = l + (h - l) / 3, m2 = h - (h - l) / 3, s1 = 0, s2 = 0;
            for (int x : arr) s1 += (x + m1 - 1) / m1, s2 += (x + m2 - 1) / m2;
            if (s1 <= k) h = m1;
            else if (s2 <= k) l = m1, h = m2;
            else l = m2;
        }
        for (int d = l; d <= h; d++) {
            int s = 0;
            for (int x : arr) s += (x + d - 1) / d;
            if (s <= k) return d;
        }
        return h;
    }
};

6)
class Solution {
public:
    int smallestDivisor(vector<int>& arr, int k) {
        int n = arr.size(), b = sqrt(n) + 1;
        vector<vector<int>> blocks(b);
        for (int i = 0; i < n; i++) blocks[i / b].push_back(arr[i]);
        
        int l = 1, h = *max_element(arr.begin(), arr.end());
        while (l < h) {
            int m = l + (h - l) / 2, s = 0;
            for (auto& block : blocks)
                for (int x : block) s += (x + m - 1) / m;
            s <= k ? h = m : l = m + 1;
        }
        return l;
    }
};
