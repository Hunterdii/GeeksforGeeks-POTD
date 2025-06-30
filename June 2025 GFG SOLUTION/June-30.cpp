class Solution {
public:
    bool isPossible(vector<int> &arr, int k, int w, int maxHeight) {
        int n = arr.size();
        vector<int> water(n, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0) water[i] = water[i - 1];
            int currHeight = arr[i] + water[i];
            if (i >= w) currHeight -= water[i - w];
            if (currHeight < maxHeight) {
                int add = maxHeight - currHeight;
                water[i] += add;
                k -= add;
                if (k < 0) return false;
            }
        }
        return true;
    }
    
    int maxMinHeight(vector<int> &arr, int k, int w) {
        int n = arr.size();
        int low = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < low) low = arr[i];
        }
        int high = low + k, ans = low;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, w, mid)) {
                ans = max(ans, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};


2)
class Solution {
public:
    bool canAchieve(vector<int>& arr, int k, int w, int target) {
        int n = arr.size();
        vector<int> added(n, 0);
        int windowSum = 0;
        
        for (int i = 0; i < n; i++) {
            if (i >= w) windowSum -= added[i - w];
            
            int currentHeight = arr[i] + windowSum;
            if (currentHeight < target) {
                int need = target - currentHeight;
                added[i] = need;
                windowSum += need;
                k -= need;
                if (k < 0) return false;
            }
        }
        return true;
    }
    
    int maxMinHeight(vector<int>& arr, int k, int w) {
        int minVal = *min_element(arr.begin(), arr.end());
        int left = minVal, right = minVal + k, result = minVal;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAchieve(arr, k, w, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};


3)
class Solution {
public:
    bool solve(vector<int>& heights, int days, int range, int minHeight) {
        int n = heights.size();
        vector<long long> water(n + range, 0);
        long long used = 0;
        
        for (int i = 0; i < n; i++) {
            long long current = heights[i] + water[i];
            if (current < minHeight) {
                long long need = minHeight - current;
                used += need;
                if (used > days) return false;
                water[i] += need;
                if (i + range < n + range) water[i + range] -= need;
            }
            if (i + 1 < n + range) water[i + 1] += water[i];
        }
        return true;
    }
    
    int maxMinHeight(vector<int>& arr, int k, int w) {
        int low = *min_element(arr.begin(), arr.end());
        int high = low + k;
        int answer = low;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (solve(arr, k, w, mid)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return answer;
    }
};
