class Solution {
public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size(), max = 0, res = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) sum += mat[i][j];
            max = sum > max ? sum : max;
        }
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) sum += mat[i][j];
            max = sum > max ? sum : max;
        }
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) sum += mat[i][j];
            res += max - sum;
        }
        return res;
    }
};

2)
class Solution {
public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size(), max = 0, res = 0;
        vector<int> rowSum(n, 0), colSum(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            max = rowSum[i] > max ? rowSum[i] : max;
            max = colSum[i] > max ? colSum[i] : max;
        }
        for (int i = 0; i < n; i++) res += max - rowSum[i];
        return res;
    }
};

3)
class Solution {
public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size(), max = 0, res = 0;
        vector<vector<int>> trans(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += mat[i][j];
                trans[j][i] = mat[i][j];
            }
            max = sum > max ? sum : max;
        }
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) sum += trans[i][j];
            max = sum > max ? sum : max;
        }
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) sum += mat[i][j];
            res += max - sum;
        }
        return res;
    }
};

4)
class Solution {
public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size(), max = 0, res = 0;
        vector<int> rowSums(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) rowSums[i] += mat[i][j];
            max = rowSums[i] > max ? rowSums[i] : max;
        }
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) sum += mat[i][j];
            max = sum > max ? sum : max;
        }
        for (int sum : rowSums) res += max - sum;
        return res;
    }
};
