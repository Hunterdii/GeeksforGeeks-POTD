class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        deque<int> minQ, maxQ;
        int n = arr.size(), l = 0, r = 0, start = 0, len = 0;
        while (r < n) {
            while (!minQ.empty() && arr[minQ.back()] >= arr[r]) minQ.pop_back();
            while (!maxQ.empty() && arr[maxQ.back()] <= arr[r]) maxQ.pop_back();
            minQ.push_back(r);
            maxQ.push_back(r);
            while (arr[maxQ.front()] - arr[minQ.front()] > x) {
                if (l == minQ.front()) minQ.pop_front();
                if (l == maxQ.front()) maxQ.pop_front();
                l++;
            }
            if (r - l + 1 > len) {
                len = r - l + 1;
                start = l;
            }
            r++;
        }
        return vector<int>(arr.begin() + start, arr.begin() + start + len);
    }
};

2)
class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size(), maxLen = 0, bestStart = 0;
        for (int i = 0; i < n; i++) {
            int minVal = arr[i], maxVal = arr[i];
            for (int j = i; j < n; j++) {
                minVal = min(minVal, arr[j]);
                maxVal = max(maxVal, arr[j]);
                if (maxVal - minVal > x) break;
                if (j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    bestStart = i;
                }
            }
        }
        return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + maxLen);
    }
};

3)
class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        map<int, int> freq;
        int n = arr.size(), l = 0, start = 0, maxLen = 0;
        for (int r = 0; r < n; r++) {
            freq[arr[r]]++;
            while (freq.rbegin()->first - freq.begin()->first > x) {
                freq[arr[l]]--;
                if (freq[arr[l]] == 0) freq.erase(arr[l]);
                l++;
            }
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start = l;
            }
        }
        return vector<int>(arr.begin() + start, arr.begin() + start + maxLen);
    }
};

4)
class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size(), maxLen = 0, bestStart = 0;
        vector<vector<int>> minSt(n, vector<int>(20));
        vector<vector<int>> maxSt(n, vector<int>(20));
        
        for (int i = 0; i < n; i++) minSt[i][0] = maxSt[i][0] = arr[i];
        
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                minSt[i][j] = min(minSt[i][j-1], minSt[i + (1 << (j-1))][j-1]);
                maxSt[i][j] = max(maxSt[i][j-1], maxSt[i + (1 << (j-1))][j-1]);
            }
        }
        
        auto query = [&](int l, int r) -> pair<int,int> {
            int len = r - l + 1, k = 31 - __builtin_clz(len);
            int minVal = min(minSt[l][k], minSt[r - (1 << k) + 1][k]);
            int maxVal = max(maxSt[l][k], maxSt[r - (1 << k) + 1][k]);
            return {minVal, maxVal};
        };
        
        for (int i = 0; i < n; i++) {
            int left = i, right = n - 1, best = i;
            while (left <= right) {
                int mid = (left + right) / 2;
                auto [minVal, maxVal] = query(i, mid);
                if (maxVal - minVal <= x) {
                    best = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (best - i + 1 > maxLen) {
                maxLen = best - i + 1;
                bestStart = i;
            }
        }
        return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + maxLen);
    }
};

