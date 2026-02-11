class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        vector<pair<int,int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {heights[i], cost[i]};
        sort(v.begin(), v.end());
        long long total = 0;
        for (int x : cost) total += x;
        long long sum = 0, res = 0;
        for (int i = 0; i < n; i++) {
            sum += v[i].second;
            if (sum >= (total + 1) / 2) {
                for (int j = 0; j < n; j++) res += (long long)abs(heights[j] - v[i].first) * cost[j];
                return res;
            }
        }
        return 0;
    }
};

2)
class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int lo = *min_element(heights.begin(), heights.end());
        int hi = *max_element(heights.begin(), heights.end());
        long long res = LLONG_MAX;
        while (lo <= hi) {
            int m1 = lo + (hi - lo) / 3, m2 = hi - (hi - lo) / 3;
            long long c1 = 0, c2 = 0;
            for (int i = 0; i < heights.size(); i++) {
                c1 += (long long)abs(heights[i] - m1) * cost[i];
                c2 += (long long)abs(heights[i] - m2) * cost[i];
            }
            res = min({res, c1, c2});
            if (c1 < c2) hi = m2 - 1;
            else lo = m1 + 1;
        }
        return res;
    }
};

3)
class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size();
        vector<pair<int,int>> v(n);
        for (int i = 0; i < n; i++) v[i] = {heights[i], cost[i]};
        sort(v.begin(), v.end());
        vector<long long> pre(n + 1);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + v[i].second;
        long long res = LLONG_MAX, curr = 0;
        for (int i = 0; i < n; i++) curr += (long long)abs(heights[i] - v[0].first) * cost[i];
        res = curr;
        for (int i = 1; i < n; i++) {
            long long diff = v[i].first - v[i - 1].first;
            curr += diff * (pre[i] - (pre[n] - pre[i]));
            res = min(res, curr);
        }
        return res;
    }
};
