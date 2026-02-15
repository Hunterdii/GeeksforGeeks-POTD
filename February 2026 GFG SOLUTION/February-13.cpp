class Solution {
public:
    int getCount(int n, int d) {
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2, sum = 0, temp = mid;
            while (temp) sum += temp % 10, temp /= 10;
            if (mid - sum >= d) hi = mid - 1;
            else lo = mid + 1;
        }
        return n - hi;
    }
};

2)
class Solution {
public:
    int sumOfDigit(int K) {
        int sod = 0;
        while (K) {
            sod += K % 10;
            K /= 10;
        }
        return sod;
    }
    
    int getCount(int n, int d) {
        int low = 1, high = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mid - sumOfDigit(mid) < d)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return n - high;
    }
};

3)
class Solution {
public:
    int getCount(int n, int d) {
        int l = 1, r = n, ans = n + 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int digitSum = 0, x = m;
            while (x > 0) digitSum += x % 10, x /= 10;
            if (m - digitSum >= d) ans = m, r = m - 1;
            else l = m + 1;
        }
        return n - ans + 1;
    }
};

4)
class Solution {
public:
    int getCount(int n, int d) {
        auto digitSum = [](int num) {
            int sum = 0;
            for (; num; num /= 10) sum += num % 10;
            return sum;
        };
        
        int left = 1, right = n, threshold = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid - digitSum(mid) >= d) threshold = mid, right = mid - 1;
            else left = mid + 1;
        }
        return threshold ? n - threshold + 1 : 0;
    }
};
