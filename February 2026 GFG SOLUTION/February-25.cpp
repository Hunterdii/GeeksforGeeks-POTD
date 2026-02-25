class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int sum = 0, ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += (arr[i] > k) ? 1 : -1;
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
        int n = arr.size();
        unordered_map<int, int> mp;
        int ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= k) sum--;
            else sum++;
            if (sum > 0) ans = i + 1;
            else {
                if (mp.find(sum - 1) != mp.end())
                    ans = max(ans, i - mp[sum - 1]);
            }
            if (mp.find(sum) == mp.end())
                mp[sum] = i;
        }
        return ans;
    }
};

3)
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            int greater = 0, lessEqual = 0;
            for (int j = i; j < n; j++) {
                if (arr[j] > k) greater++;
                else lessEqual++;
                if (greater > lessEqual)
                    maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};

4)
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> trans(n);
        for (int i = 0; i < n; i++)
            trans[i] = (arr[i] > k) ? 1 : -1;
        
        unordered_map<int, int> mp;
        int sum = 0, maxLen = 0;
        for (int i = 0; i < n; i++) {
            sum += trans[i];
            if (sum > 0) maxLen = i + 1;
            else if (mp.count(sum - 1))
                maxLen = max(maxLen, i - mp[sum - 1]);
            if (!mp.count(sum)) mp[sum] = i;
        }
        return maxLen;
    }
};
