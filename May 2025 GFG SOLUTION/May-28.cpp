
class Solution {
  public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < m; ++k)
                    cnt += mat[i][k] & mat[j][k];
                if (cnt > 1) return true;
            }
        return false;
    }
};

2)
class Solution {
  public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<bitset<1000>> bs(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (mat[i][j]) bs[i].set(j);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if ((bs[i] & bs[j]).count() > 1) return true;
        return false;
    }
};

3)
class Solution {
  public:
    bool ValidCorner(vector<vector<int>>& mat) {
        int m = mat[0].size();
        unordered_map<long long,int> cnt;
        for (auto& row : mat) {
            vector<int> ones;
            for (int j = 0; j < m; ++j)
                if (row[j]) ones.push_back(j);
            for (int a = 0; a < ones.size(); ++a)
                for (int b = a + 1; b < ones.size(); ++b) {
                    long long key = (long long)ones[a] << 32 | ones[b];
                    if (++cnt[key] > 1) return true;
                }
        }
        return false;
    }
};
