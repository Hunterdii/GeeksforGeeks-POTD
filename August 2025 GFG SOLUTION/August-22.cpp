class Solution {
public:
    int median(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> all;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                all.push_back(mat[i][j]);
        sort(all.begin(), all.end());
        return all[(n * m) / 2];
    }
};

2)
class Solution {
public:
    int median(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int lo = mat[0][0], hi = mat[0][m-1];
        for (int i = 1; i < n; i++) {
            lo = min(lo, mat[i][0]);
            hi = max(hi, mat[i][m-1]);
        }
        int req = (n * m + 1) >> 1;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1), cnt = 0;
            for (int i = 0; i < n; i++)
                cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            if (cnt < req) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};

3)
class Solution {
public:
    int median(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        priority_queue<pair<int, pair<int, int>>, 
                      vector<pair<int, pair<int, int>>>, 
                      greater<pair<int, pair<int, int>>>> pq;
        
        for (int i = 0; i < n; i++)
            pq.push({mat[i][0], {i, 0}});
        
        for (int cnt = 0; cnt < (n * m) / 2; cnt++) {
            auto top = pq.top(); pq.pop();
            int i = top.second.first, j = top.second.second;
            if (j + 1 < m)
                pq.push({mat[i][j + 1], {i, j + 1}});
        }
        return pq.top().first;
    }
};


4)
class Solution {
public:
    int median(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        auto count = [&](int x) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                int pos = upper_bound(mat[i].begin(), mat[i].end(), x) - mat[i].begin();
                cnt += pos;
            }
            return cnt;
        };
        
        int lo = INT_MAX, hi = INT_MIN;
        for (int i = 0; i < n; i++) {
            lo = min(lo, mat[i][0]);
            hi = max(hi, mat[i][m-1]);
        }
        
        int target = (n * m + 1) / 2;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (count(mid) >= target) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    }
};
