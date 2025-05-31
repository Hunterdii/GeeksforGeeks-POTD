class Solution {
  public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> flat;
        for (auto& row : matrix)
            flat.insert(flat.end(), row.begin(), row.end());
        sort(flat.begin(), flat.end());
        return flat[k - 1];
    }
};

2)
class Solution {
  public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        for (int i = 0; i < n; ++i) 
            pq.emplace(matrix[i][0], i, 0);

        while (--k) {
            T top = pq.top(); 
            pq.pop();
            int val = get<0>(top), r = get<1>(top), c = get<2>(top);
            if (c + 1 < n) 
                pq.emplace(matrix[r][c + 1], r, c + 1);
        }
        return get<0>(pq.top());
    }
};

3)
class Solution {
  public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), l = matrix[0][0], r = matrix[n-1][n-1];
        while (l < r) {
            int m = l + (r - l) / 2, cnt = 0;
            for (int i = 0, j = n - 1; i < n; ++i) {
                while (j >= 0 && matrix[i][j] > m) --j;
                cnt += j + 1;
            }
            if (cnt < k) l = m + 1;
            else r = m;
        }
        return l;
    }
};

