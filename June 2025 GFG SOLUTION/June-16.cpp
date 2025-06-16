class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int l = 0, h = *max_element(heights.begin(), heights.end());
        while (l < h) {
            int m = l + (h - l) / 2;
            long long c1 = 0, c2 = 0;
            for (int i = 0; i < heights.size(); ++i) {
                c1 += (long long)abs(heights[i] - m) * cost[i];
                c2 += (long long)abs(heights[i] - m - 1) * cost[i];
            }
            c1 <= c2 ? h = m : l = m + 1;
        }
        long long ans = 0;
        for (int i = 0; i < heights.size(); ++i)
            ans += (long long)abs(heights[i] - l) * cost[i];
        return ans;
    }
};

2)
class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int l = 0, h = *max_element(heights.begin(), heights.end());
        while (h - l > 2) {
            int m1 = l + (h - l) / 3, m2 = h - (h - l) / 3;
            long long c1 = 0, c2 = 0;
            for (int i = 0; i < heights.size(); ++i) {
                c1 += (long long)abs(heights[i] - m1) * cost[i];
                c2 += (long long)abs(heights[i] - m2) * cost[i];
            }
            c1 <= c2 ? h = m2 : l = m1;
        }
        long long ans = LLONG_MAX;
        for (int i = l; i <= h; ++i) {
            long long c = 0;
            for (int j = 0; j < heights.size(); ++j)
                c += (long long)abs(heights[j] - i) * cost[j];
            ans = min(ans, c);
        }
        return ans;
    }
};

3)
class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        vector<pair<int, int>> hc;
        long long total = 0;
        for (int i = 0; i < heights.size(); ++i) {
            hc.push_back({heights[i], cost[i]});
            total += cost[i];
        }
        sort(hc.begin(), hc.end());
        
        long long sum = 0, ans = 0;
        for (auto& p : hc) {
            sum += p.second;
            if (sum >= (total + 1) / 2) {
                for (int i = 0; i < heights.size(); ++i)
                    ans += (long long)abs(heights[i] - p.first) * cost[i];
                return ans;
            }
        }
        return 0;
    }
};

4)
class Solution {
public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        int n = heights.size(), l = 0, r = *max_element(heights.begin(), heights.end()), ans = INT_MAX;
        auto getCost = [&](int h) {
            int total = 0;
            for (int i = 0; i < n; ++i)
                total += abs(heights[i] - h) * cost[i];
            return total;
        };
        while (l < r) {
            int m = l + (r - l) / 2;
            int c1 = getCost(m), c2 = getCost(m + 1);
            ans = min({ans, c1, c2});
            if (c1 < c2) r = m;
            else l = m + 1;
        }
        return ans;
    }
};
