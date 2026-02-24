class Solution {
public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int diff = 0, maxLen = 0;
        for (int i = 0; i < a1.size(); i++) {
            diff += a1[i] - a2[i];
            if (mp.count(diff)) maxLen = max(maxLen, i - mp[diff]);
            else mp[diff] = i;
        }
        return maxLen;
    }
};

2)
class Solution {
public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size(), maxLen = 0;
        unordered_map<int, int> diffMap;
        int prefixSum1 = 0, prefixSum2 = 0;
        for (int i = 0; i < n; i++) {
            prefixSum1 += a1[i];
            prefixSum2 += a2[i];
            int currentDiff = prefixSum1 - prefixSum2;
            if (currentDiff == 0) maxLen = max(maxLen, i + 1);
            else if (diffMap.find(currentDiff) != diffMap.end())
                maxLen = max(maxLen, i - diffMap[currentDiff]);
            else diffMap[currentDiff] = i;
        }
        return maxLen;
    }
};

3)
class Solution {
public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        vector<int> diff(n);
        for (int i = 0; i < n; i++) diff[i] = a1[i] - a2[i];
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0, maxLen = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i];
            if (mp.count(sum)) maxLen = max(maxLen, i - mp[sum]);
            else mp[sum] = i;
        }
        return maxLen;
    }
};

4)
class Solution {
public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        int n = a1.size(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            int sum1 = 0, sum2 = 0;
            for (int j = i; j < n; j++) {
                sum1 += a1[j];
                sum2 += a2[j];
                if (sum1 == sum2) maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};
