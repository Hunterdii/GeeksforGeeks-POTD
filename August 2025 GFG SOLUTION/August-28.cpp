class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {
        int l = 0, zeros = 0, maxLen = 0;
        for (int r = 0; r < arr.size(); r++) {
            zeros += (arr[r] == 0);
            while (zeros > k) zeros -= (arr[l++] == 0);
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};

2)
class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size(), maxLen = 0;
        vector<int> zeros;
        for (int i = 0; i < n; i++) if (arr[i] == 0) zeros.push_back(i);
        if (zeros.size() <= k) return n;
        for (int i = 0; i <= zeros.size() - k; i++) {
            int start = (i == 0) ? 0 : zeros[i - 1] + 1;
            int end = (i + k == zeros.size()) ? n - 1 : zeros[i + k] - 1;
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};

3)
class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {
        deque<int> zeroPos;
        int l = 0, maxLen = 0;
        for (int r = 0; r < arr.size(); r++) {
            if (arr[r] == 0) zeroPos.push_back(r);
            while (zeroPos.size() > k) {
                l = zeroPos.front() + 1;
                zeroPos.pop_front();
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};

