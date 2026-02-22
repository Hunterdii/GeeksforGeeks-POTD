class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        int xorSum = 0;
        long cnt = 0;
        mp[0] = 1;
        for (int x : arr) {
            xorSum ^= x;
            cnt += mp[xorSum ^ k];
            mp[xorSum]++;
        }
        return cnt;
    }
};

2)
class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        long res = 0;
        int prefXOR = 0;
        for (int val : arr) {
            prefXOR ^= val;
            if (prefXOR == k) res++;
            res += freq[prefXOR ^ k];
            freq[prefXOR]++;
        }
        return res;
    }
};

3)
class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
        map<int, int> m;
        m[0] = 1;
        int xr = 0;
        long count = 0;
        for (int i = 0; i < arr.size(); i++) {
            xr ^= arr[i];
            int target = xr ^ k;
            count += m[target];
            m[xr]++;
        }
        return count;
    }
};
