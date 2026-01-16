class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                v.push_back({max(0, i - arr[i]), min(n - 1, i + arr[i])});
            }
        }
        if (v.empty()) return -1;
        sort(v.begin(), v.end());
        int cnt = 0, pos = -1, i = 0;
        while (pos < n - 1) {
            if (i >= v.size() || v[i].first > pos + 1) return -1;
            int reach = pos;
            while (i < v.size() && v[i].first <= pos + 1) reach = max(reach, v[i++].second);
            cnt++;
            pos = reach;
        }
        return cnt;
    }
};

2)
class Solution {
public:
    int minMen(vector<int>& arr) {
        vector<pair<int, int>> intervals;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                intervals.push_back({i - arr[i], i + arr[i]});
            }
        }
        if (intervals.empty()) return -1;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a.first != b.first ? a.first < b.first : a.second > b.second;
        });
        int workers = 0, covered = -1, idx = 0;
        while (covered < n - 1) {
            if (idx == intervals.size() || intervals[idx].first > covered + 1) return -1;
            int farthest = covered;
            while (idx < intervals.size() && intervals[idx].first <= covered + 1) {
                farthest = max(farthest, min(n - 1, intervals[idx++].second));
            }
            if (farthest == covered) return -1;
            workers++;
            covered = farthest;
        }
        return workers;
    }
};

3)
class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> worker;
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) worker.push_back({max(0, i - arr[i]), min(n - 1, i + arr[i])});
        }
        if (worker.empty()) return -1;
        sort(worker.begin(), worker.end());
        int ans = 0, curr = -1, i = 0, m = worker.size();
        while (curr < n - 1 && i < m) {
            if (worker[i].first > curr + 1) return -1;
            int extend = curr;
            while (i < m && worker[i].first <= curr + 1) extend = max(extend, worker[i++].second);
            if (extend <= curr) return -1;
            ans++;
            curr = extend;
        }
        return curr >= n - 1 ? ans : -1;
    }
};
