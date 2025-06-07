class Solution {
  public:
    int longestCommonSum(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size(), res = 0;
        unordered_map<int, int> diffMap;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += arr1[i];
            sum2 += arr2[i];
            int diff = sum1 - sum2;
            if (diff == 0) res = max(res, i + 1);
            else if (diffMap.count(diff)) res = max(res, i - diffMap[diff]);
            else diffMap[diff] = i;
        }
        return res;
    }
};

2)
class Solution {
  public:
    int longestCommonSum(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size(), res = 0;
        vector<int> diff(n);
        for (int i = 0; i < n; i++)
            diff[i] = arr1[i] - arr2[i];

        unordered_map<int, int> prefix;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i];
            if (sum == 0)
                res = i + 1;
            else if (prefix.count(sum))
                res = max(res, i - prefix[sum]);
            else
                prefix[sum] = i;
        }
        return res;
    }
};
