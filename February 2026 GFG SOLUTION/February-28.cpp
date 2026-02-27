class Solution {
public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int i = 0, j = arr2.size() - 1, minDiff = INT_MAX;
        vector<int> res(2);
        while (i < arr1.size() && j >= 0) {
            int sum = arr1[i] + arr2[j], diff = abs(sum - x);
            if (diff < minDiff) minDiff = diff, res = {arr1[i], arr2[j]};
            (sum < x) ? i++ : j--;
        }
        return res;
    }
};

2)
class Solution {
public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int minDiff = INT_MAX;
        vector<int> res(2);
        for (int i = 0; i < arr1.size(); i++) {
            for (int j = 0; j < arr2.size(); j++) {
                int sum = arr1[i] + arr2[j];
                int diff = abs(sum - x);
                if (diff < minDiff) {
                    minDiff = diff;
                    res[0] = arr1[i];
                    res[1] = arr2[j];
                }
            }
        }
        return res;
    }
};

3)
class Solution {
public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int minDiff = INT_MAX;
        vector<int> res(2);
        for (int i = 0; i < arr1.size(); i++) {
            int target = x - arr1[i];
            auto it = lower_bound(arr2.begin(), arr2.end(), target);
            
            if (it != arr2.end()) {
                int diff = abs(arr1[i] + *it - x);
                if (diff < minDiff) {
                    minDiff = diff;
                    res = {arr1[i], *it};
                }
            }
            
            if (it != arr2.begin()) {
                --it;
                int diff = abs(arr1[i] + *it - x);
                if (diff < minDiff) {
                    minDiff = diff;
                    res = {arr1[i], *it};
                }
            }
        }
        return res;
    }
};

4)
class Solution {
public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        int l = 0, r = arr2.size() - 1, diff = INT_MAX;
        vector<int> result(2);
        
        while (l < arr1.size() && r >= 0) {
            int sum = arr1[l] + arr2[r];
            int currDiff = abs(sum - x);
            
            if (currDiff < diff) {
                diff = currDiff;
                result[0] = arr1[l];
                result[1] = arr2[r];
                if (diff == 0) return result;
            }
            
            if (sum > x) r--;
            else l++;
        }
        
        return result;
    }
};
