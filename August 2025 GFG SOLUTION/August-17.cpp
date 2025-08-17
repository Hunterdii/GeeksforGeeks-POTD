class Solution {
public:
    void rearrange(vector<int> &arr, int x) {
        stable_sort(arr.begin(), arr.end(), [x](int a, int b) {
            return abs(a - x) < abs(b - x);
        });
    }
};

2)
class Solution {
public:
    void rearrange(vector<int> &arr, int x) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < arr.size(); i++) {
            pairs.push_back({abs(arr[i] - x), i});
        }
        sort(pairs.begin(), pairs.end());
        vector<int> temp(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            temp[i] = arr[pairs[i].second];
        }
        arr = temp;
    }
};

3)
class Solution {
public:
    void rearrange(vector<int> &arr, int x) {
        int maxDist = 0;
        for (int val : arr) maxDist = max(maxDist, abs(val - x));
        if (maxDist > 1000000) {
            stable_sort(arr.begin(), arr.end(), [x](int a, int b) {
                return abs(a - x) < abs(b - x);
            });
            return;
        }
        vector<vector<int>> buckets(maxDist + 1);
        for (int val : arr) buckets[abs(val - x)].push_back(val);
        int idx = 0;
        for (auto& bucket : buckets) {
            for (int val : bucket) arr[idx++] = val;
        }
    }
};

4)
class Solution {
public:
    void rearrange(vector<int> &arr, int x) {
        map<int, vector<int>> buckets;
        for (int val : arr) {
            buckets[abs(val - x)].push_back(val);
        }
        int idx = 0;
        for (auto& [distance, elements] : buckets) {
            for (int val : elements) {
                arr[idx++] = val;
            }
        }
    }
};
