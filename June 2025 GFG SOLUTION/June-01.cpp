class Solution {
  public:
    int countPairs(vector<vector<int>> &a, vector<vector<int>> &b, int x) {
        int r1 = 0, c1 = 0, r2 = b.size() - 1, c2 = b[0].size() - 1, cnt = 0;
        while (r1 < a.size() && r2 >= 0) {
            int sum = a[r1][c1] + b[r2][c2];
            if (sum == x) ++cnt, ++c1, --c2;
            else if (sum < x) ++c1;
            else --c2;
            if (c1 == a[0].size()) c1 = 0, ++r1;
            if (c2 < 0) c2 = b[0].size() - 1, --r2;
        }
        return cnt;
    }
};

2)
class Solution {
  public:
    int countPairs(vector<vector<int>> &a, vector<vector<int>> &b, int x) {
        unordered_map<int, int> freq;
        for (auto &row : b)
            for (int val : row) ++freq[val];
        int cnt = 0;
        for (auto &row : a)
            for (int val : row) cnt += freq[x - val];
        return cnt;
    }
};

3)
class Solution {
  public:
    int countPairs(vector<vector<int>> &a, vector<vector<int>> &b, int x) {
        vector<int> v1, v2;
        for (auto &r : a) v1.insert(v1.end(), r.begin(), r.end());
        for (auto &r : b) v2.insert(v2.end(), r.begin(), r.end());
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end(), greater<int>());
        int i = 0, j = 0, cnt = 0;
        while (i < v1.size() && j < v2.size()) {
            int sum = v1[i] + v2[j];
            if (sum == x) ++cnt, ++i, ++j;
            else if (sum < x) ++i;
            else ++j;
        }
        return cnt;
    }
};

4)
class Solution {
  public:
    int countPairs(vector<vector<int>> &a, vector<vector<int>> &b, int x) {
        int cnt = 0;
        for (auto &row1 : a)
            for (int val1 : row1)
                for (auto &row2 : b)
                    for (int val2 : row2)
                        if (val1 + val2 == x) ++cnt;
        return cnt;
    }
};
