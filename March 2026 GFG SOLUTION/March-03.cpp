class Solution {
public:
    int totalElements(vector<int> &arr) {
        unordered_map<int, int> mp;
        int i = 0, maxLen = 0;
        for (int j = 0; j < arr.size(); j++) {
            mp[arr[j]]++;
            while (mp.size() > 2) {
                if (--mp[arr[i]] == 0) mp.erase(arr[i]);
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};

2)
class Solution {
public:
    int totalElements(vector<int> &arr) {
        int n = arr.size(), maxLen = 0, left = 0;
        int first = -1, second = -1, firstIdx = -1, secondIdx = -1;
        for (int right = 0; right < n; right++) {
            if (arr[right] == first) firstIdx = right;
            else if (arr[right] == second) secondIdx = right;
            else if (first == -1) first = arr[right], firstIdx = right;
            else if (second == -1) second = arr[right], secondIdx = right;
            else {
                left = min(firstIdx, secondIdx) + 1;
                if (firstIdx < secondIdx) first = arr[right], firstIdx = right;
                else second = arr[right], secondIdx = right;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

3)
class Solution {
public:
    int totalElements(vector<int> &arr) {
        int n = arr.size(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> s;
            for (int j = i; j < n; j++) {
                s.insert(arr[j]);
                if (s.size() <= 2)
                    maxLen = max(maxLen, j - i + 1);
                else
                    break;
            }
        }
        return maxLen;
    }
};

4)
class Solution {
public:
    int totalElements(vector<int> &arr) {
        map<int, int> mp;
        int i = 0, maxLen = 0;
        for (int j = 0; j < arr.size(); j++) {
            mp[arr[j]]++;
            while (mp.size() > 2) {
                if (--mp[arr[i]] == 0) mp.erase(arr[i]);
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};
