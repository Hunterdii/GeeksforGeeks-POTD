class Solution {
public:
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size(), res = 0, left = 0;
        unordered_map<int, int> freq;
        for (int right = 0; right < n; right++) {
            if (freq[arr[right]]++ == 0) k--;
            while (k < 0) {
                if (--freq[arr[left]] == 0) k++;
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};


2)
class Solution {
public:
    int countAtMostK(vector<int> &arr, int k) {
        int maxVal = *max_element(arr.begin(), arr.end());
        vector<int> freq(maxVal + 1, 0);
        int n = arr.size(), res = 0, left = 0, distinct = 0;
        for (int right = 0; right < n; right++) {
            if (freq[arr[right]]++ == 0) distinct++;
            while (distinct > k) {
                if (--freq[arr[left]] == 0) distinct--;
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};


3)
class Solution {
public:
    int countAtMostK(vector<int> &arr, int k) {
        unordered_set<int> distinct;
        unordered_map<int, int> freq;
        int n = arr.size(), res = 0, left = 0;
        for (int right = 0; right < n; right++) {
            freq[arr[right]]++;
            distinct.insert(arr[right]);
            while (distinct.size() > k) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) distinct.erase(arr[left]);
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};


4)
class Solution {
public:
    int countAtMostK(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        int n = arr.size(), res = 0, left = 0;
        for (int right = 0; right < n; right++) {
            mp[arr[right]]++;
            while (mp.size() > k) {
                if (--mp[arr[left]] == 0) mp.erase(arr[left]);
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};


5)
class Solution {
public:
    int countAtMostK(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        int n = arr.size(), res = 0, left = 0, distinctCount = 0;
        for (int right = 0; right < n; right++) {
            if (freq[arr[right]]++ == 0) distinctCount++;
            while (distinctCount > k) {
                if (--freq[arr[left]] == 0) distinctCount--;
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};
