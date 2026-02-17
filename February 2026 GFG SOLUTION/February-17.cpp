class Solution {
public:
    int overlapInt(vector<vector<int>>& arr) {
        int mx = 0;
        for (auto& a : arr) mx = max(mx, a[1]);
        vector<int> diff(mx + 2, 0);
        for (auto& a : arr) { diff[a[0]]++; diff[a[1] + 1]--; }
        int res = 0, cur = 0;
        for (int x : diff) res = max(res, cur += x);
        return res;
    }
};

2)
class Solution {
public:
    int overlapInt(vector<vector<int>> &arr) {
        int n = arr.size();
        vector<int> starts(n), ends(n);
        for (int i = 0; i < n; i++) starts[i] = arr[i][0], ends[i] = arr[i][1];
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int i = 0, j = 0, cur = 0, ans = 0;
        while (i < n) {
            if (starts[i] <= ends[j]) { cur++; i++; }
            else { cur--; j++; }
            ans = max(ans, cur);
        }
        return ans;
    }
};

3)
class Solution {
public:
    int overlapInt(vector<vector<int>> &arr) {
        vector<pair<int,int>> events;
        for (auto& a : arr) {
            events.push_back({a[0], 1});
            events.push_back({a[1] + 1, -1});
        }
        sort(events.begin(), events.end());
        int cur = 0, ans = 0;
        for (auto& [pos, delta] : events) {
            cur += delta;
            ans = max(ans, cur);
        }
        return ans;
    }
};
