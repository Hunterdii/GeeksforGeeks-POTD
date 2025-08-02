class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size(), ans = 0, sum = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            sum += arr[i] <= k ? -1 : 1;
            if (sum > 0) ans = i + 1;
            else if (mp.count(sum - 1)) ans = max(ans, i - mp[sum - 1]);
            if (!mp.count(sum)) mp[sum] = i;
        }
        return ans;
    }
};

2)
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int ans = 0, balance = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < arr.size(); ++i) {
            balance += arr[i] <= k ? -1 : 1;
            if (balance > 0) ans = i + 1;
            else if (mp.count(balance - 1)) ans = max(ans, i - mp[balance - 1]);
            if (!mp.count(balance)) mp[balance] = i;
        }
        return ans;
    }
};


3)
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        int s = 0, res = 0;
        m[0] = -1;
        for (int i = 0; i < arr.size(); ++i) {
            s += arr[i] <= k ? -1 : 1;
            if (s > 0) res = i + 1;
            else if (m.find(s - 1) != m.end()) res = max(res, i - m[s - 1]);
            if (m.find(s) == m.end()) m[s] = i;
        }
        return res;
    }
};

4)
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            int countGreater = 0, countLessEqual = 0;
            for (int j = i; j < n; j++) {
                if (arr[j] > k) countGreater++;
                else countLessEqual++;
                if (countGreater > countLessEqual) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};
