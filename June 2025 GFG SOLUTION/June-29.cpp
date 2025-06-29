class Solution {
public:
    bool canSplit(vector<int>& arr, int k, int maxSum) {
        int subarrays = 1, currentSum = 0;
        for (int num : arr) {
            if (num > maxSum) return false;
            if (currentSum + num <= maxSum) {
                currentSum += num;
            } else {
                subarrays++;
                currentSum = num;
                if (subarrays > k) return false;
            }
        }
        return true;
    }

    int splitArray(vector<int>& arr, int k) {
        int left = *max_element(arr.begin(), arr.end());
        int right = accumulate(arr.begin(), arr.end(), 0);

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canSplit(arr, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};


2)
class Solution {
public:
    int splitArray(vector<int>& a, int k) {
        int l = *max_element(a.begin(), a.end()), r = accumulate(a.begin(), a.end(), 0);
        while (l < r) {
            int m = (l + r) / 2, s = 0, c = 1;
            for (int x : a) {
                if (s + x > m) c++, s = 0;
                s += x;
            }
            if (c <= k) r = m;
            else l = m + 1;
        }
        return l;
    }
};


3)
class Solution {
public:
    bool check(int mid, vector<int>& arr, int k) {
        int count = 1, sum = 0;
        for (int a : arr) {
            if (a > mid) return false;
            if (sum + a > mid) count++, sum = 0;
            sum += a;
        }
        return count <= k;
    }

    int splitArray(vector<int>& arr, int k) {
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0), ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(mid, arr, k)) ans = mid, high = mid - 1;
            else low = mid + 1;
        }
        return ans;
    }
};

