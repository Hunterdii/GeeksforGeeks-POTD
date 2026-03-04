class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int xr = 0, res = 0;
        for (int i = 0; i < arr.size(); i++) {
            xr ^= arr[i];
            if (i >= k) xr ^= arr[i - k];
            if (i >= k - 1) res = max(res, xr);
        }
        return res;
    }
};

2)
class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        int currXor = 0;
        for (int i = 0; i < k; i++)
            currXor ^= arr[i];
        int maxXor = currXor;
        for (int i = k; i < n; i++) {
            currXor ^= arr[i];
            currXor ^= arr[i - k];
            maxXor = max(maxXor, currXor);
        }
        return maxXor;
    }
};

3)
class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size(), maxXor = 0;
        for (int i = 0; i <= n - k; i++) {
            int xr = 0;
            for (int j = i; j < i + k; j++)
                xr ^= arr[j];
            maxXor = max(maxXor, xr);
        }
        return maxXor;
    }
};

4)
class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] ^ arr[i];
        int maxXor = 0;
        for (int i = 0; i <= n - k; i++)
            maxXor = max(maxXor, prefix[i + k] ^ prefix[i]);
        return maxXor;
    }
};
