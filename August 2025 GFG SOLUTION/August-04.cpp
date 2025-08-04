class Solution {
public:
    int maxRectSum(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = INT_MIN;
        for (int l = 0; l < n; l++) {
            vector<int> temp(m, 0);
            for (int r = l; r < n; r++) {
                for (int i = 0; i < m; i++) temp[i] += mat[i][r];
                int sum = 0, maxSum = temp[0];
                for (int x : temp) {
                    sum = max(x, sum + x);
                    maxSum = max(maxSum, sum);
                }
                res = max(res, maxSum);
            }
        }
        return res;
    }
};

2)
class Solution {
public:
    int maxRectSum(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = INT_MIN;
        for (int r1 = 0; r1 < m; r1++) {
            for (int c1 = 0; c1 < n; c1++) {
                for (int r2 = r1; r2 < m; r2++) {
                    for (int c2 = c1; c2 < n; c2++) {
                        int sum = 0;
                        for (int i = r1; i <= r2; i++)
                            for (int j = c1; j <= c2; j++)
                                sum += mat[i][j];
                        res = max(res, sum);
                    }
                }
            }
        }
        return res;
    }
};


3)
class Solution {
public:
    int maxRectSum(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = INT_MIN;
        for (int top = 0; top < m; top++) {
            vector<int> temp(n, 0);
            for (int bottom = top; bottom < m; bottom++) {
                for (int j = 0; j < n; j++) temp[j] += mat[bottom][j];
                int sum = 0, maxSum = temp[0];
                for (int x : temp) {
                    sum = max(x, sum + x);
                    maxSum = max(maxSum, sum);
                }
                res = max(res, maxSum);
            }
        }
        return res;
    }
};

4)
class Solution {
public:
    int maxRectSum(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = INT_MIN;
        for (int l = 0; l < n; l++) {
            vector<int> temp(m, 0);
            for (int r = l; r < n; r++) {
                int currMax = INT_MIN, sum = 0;
                for (int i = 0; i < m; i++) {
                    temp[i] += mat[i][r];
                    sum = max(temp[i], sum + temp[i]);
                    currMax = max(currMax, sum);
                }
                res = max(res, currMax);
            }
        }
        return res;
    }
};
