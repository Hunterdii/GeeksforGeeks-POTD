class Solution {
public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        if ((long long)k * m > arr.size()) return -1;
        int l = *min_element(arr.begin(), arr.end());
        int r = *max_element(arr.begin(), arr.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            int flowers = 0, bouquets = 0;
            for (int bloom : arr) {
                if (bloom <= mid) {
                    if (++flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else flowers = 0;
            }
            if (bouquets >= m) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};


2)
class Solution {
public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        if ((long long)k * m > arr.size()) return -1;
        auto canMake = [&](int days) {
            int consecutive = 0, made = 0;
            for (int x : arr) {
                consecutive = (x <= days) ? consecutive + 1 : 0;
                if (consecutive == k) {
                    made++;
                    consecutive = 0;
                }
            }
            return made >= m;
        };
        
        int lo = 1, hi = 1e9, ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canMake(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};


3)
class Solution {
public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        int n = arr.size();
        if ((long long)k * m > n) return -1;
        
        int left = 1, right = *max_element(arr.begin(), arr.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            int bouquets = 0, consecutive = 0;
            
            for (int i = 0; i < n; i++) {
                if (arr[i] <= mid) {
                    consecutive++;
                    if (consecutive == k) {
                        bouquets++;
                        consecutive = 0;
                    }
                } else {
                    consecutive = 0;
                }
            }
            
            if (bouquets >= m) right = mid;
            else left = mid + 1;
        }
        
        return left;
    }
};


4)
class Solution {
public:
    int minDaysBloom(vector<int>& arr, int k, int m) {
        int n = arr.size();
        if (k > n || (long long)k * m > n) return -1;
        
        int minDay = *min_element(arr.begin(), arr.end());
        int maxDay = *max_element(arr.begin(), arr.end());
        
        while (minDay < maxDay) {
            int midDay = minDay + (maxDay - minDay) / 2;
            int bouquets = 0, flowers = 0;
            
            for (int day : arr) {
                if (day <= midDay) {
                    flowers++;
                    if (flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
            }
            
            if (bouquets >= m) {
                maxDay = midDay;
            } else {
                minDay = midDay + 1;
            }
        }
        
        return minDay;
    }
};
