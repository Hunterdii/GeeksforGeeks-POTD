class Solution {
public:
    int findPages(vector<int> &arr, int k) {
        if (k > arr.size()) return -1;
        int l = *max_element(arr.begin(), arr.end());
        int r = accumulate(arr.begin(), arr.end(), 0);
        while (l < r) {
            int m = l + (r - l) / 2;
            int s = 1, p = 0;
            for (int x : arr) {
                if (p + x > m) { s++; p = x; } 
                else p += x;
            }
            s <= k ? r = m : l = m + 1;
        }
        return l;
    }
};

2)
class Solution {
public:
    bool canAllocate(vector<int> &arr, int k, int limit) {
        int cnt = 1, sum = 0;
        for (int x : arr) {
            if (sum + x > limit) cnt++, sum = x;
            else sum += x;
        }
        return cnt <= k;
    }
    
    int solve(vector<int> &arr, int k, int l, int r) {
        if (l >= r) return l;
        int m = l + (r - l) / 2;
        return canAllocate(arr, k, m) ? solve(arr, k, l, m) : solve(arr, k, m + 1, r);
    }
    
    int findPages(vector<int> &arr, int k) {
        if (k > arr.size()) return -1;
        return solve(arr, k, *max_element(arr.begin(), arr.end()), 
                     accumulate(arr.begin(), arr.end(), 0));
    }
};

3)
class Solution {
public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1;
        
        int l = 0, r = 0;
        for (int x : arr) l = max(l, x), r += x;
        
        while (l < r) {
            int m = l + (r - l) / 2;
            int cnt = 1, sum = 0;
            bool possible = true;
            
            for (int x : arr) {
                if (sum + x > m) {
                    if (++cnt > k) { possible = false; break; }
                    sum = x;
                } else sum += x;
            }
            
            possible ? r = m : l = m + 1;
        }
        return l;
    }
};

4)
class Solution {
public:
    int findPages(vector<int> &arr, int k) {
        if (k > arr.size()) return -1;
        
        auto feasible = [&](int limit) {
            int students = 1, pages = 0;
            for (int book : arr) {
                if (pages + book > limit) students++, pages = book;
                else pages += book;
            }
            return students <= k;
        };
        
        int left = *max_element(arr.begin(), arr.end()) - 1;
        int right = accumulate(arr.begin(), arr.end(), 0) + 1;
        
        while (right - left > 1) {
            int mid = left + (right - left) / 2;
            (feasible(mid) ? right : left) = mid;
        }
        return right;
    }
};
