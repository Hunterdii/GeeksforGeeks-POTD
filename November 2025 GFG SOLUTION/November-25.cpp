class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int xor_sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (((i + 1) * (n - i)) & 1) xor_sum ^= arr[i];
        }
        return xor_sum;
    }
};

2)
class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int res = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            int cnt = (i + 1) * (n - i);
            if (cnt % 2) res ^= arr[i];
        }
        return res;
    }
};

3)
class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            if ((i + 1) % 2 && (arr.size() - i) % 2) ans ^= arr[i];
        }
        return ans;
    }
};

4)
class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int result = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (((i + 1) & 1) && ((arr.size() - i) & 1)) result ^= arr[i];
        }
        return result;
    }
};
