class Solution {
public:
    int cntSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int sum = 0, cnt = 0;
        mp[0] = 1;
        for (int x : arr) {
            sum += x;
            cnt += mp[sum - k];
            mp[sum]++;
        }
        return cnt;
    }
};

2)
class Solution {
public:
    int cntSubarrays(vector<int>& arr, int k) {
        vector<int> prefix(arr.size() + 1, 0);
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < arr.size(); i++) {
            prefix[i + 1] = prefix[i] + arr[i];
            pos[prefix[i + 1]].push_back(i + 1);
        }
        pos[0].push_back(0);
        int res = 0;
        for (int i = 1; i <= arr.size(); i++) {
            int target = prefix[i] - k;
            for (int j : pos[target]) {
                if (j < i) res++;
            }
        }
        return res;
    }
};

3)
class Solution {
public:
    int cntSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        int sum = 0, result = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum == k) result++;
            auto it = freq.find(sum - k);
            if (it != freq.end()) result += it->second;
            freq[sum]++;
        }
        return result;
    }
};

4)
class Solution {
public:
    int cntSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> cnt;
        int prefixSum = 0, ans = 0;
        cnt[0]++;
        for (int val : arr) {
            prefixSum += val;
            ans += cnt[prefixSum - k];
            cnt[prefixSum]++;
        }
        return ans;
    }
};

5)
class Solution {
public:
    int cntSubarrays(vector<int>& arr, int k) {
        int n = arr.size(), count = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == k) count++;
            }
        }
        return count;
    }
};
