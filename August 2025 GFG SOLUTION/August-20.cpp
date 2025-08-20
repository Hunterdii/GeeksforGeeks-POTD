class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size();
        int l = 0, r = n * m - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mat[mid / m][mid % m];
            if (val == x) return true;
            if (mat[l / m][l % m] <= val) {
                if (mat[l / m][l % m] <= x && x < val) r = mid - 1;
                else l = mid + 1;
            } else {
                if (val < x && x <= mat[r / m][r % m]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return false;
    }
};

2)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size();
        int pivot = findPivot(mat, n, m);
        if (pivot == 0) return binarySearch(mat, 0, n * m - 1, x, n, m);
        if (mat[0][0] <= x && x <= mat[(pivot-1)/m][(pivot-1)%m])
            return binarySearch(mat, 0, pivot - 1, x, n, m);
        return binarySearch(mat, pivot, n * m - 1, x, n, m);
    }
    int findPivot(vector<vector<int>>& mat, int n, int m) {
        int l = 0, r = n * m - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mat[mid/m][mid%m] > mat[r/m][r%m]) l = mid + 1;
            else r = mid;
        }
        return l;
    }
    bool binarySearch(vector<vector<int>>& mat, int l, int r, int x, int n, int m) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mat[mid/m][mid%m];
            if (val == x) return true;
            if (val < x) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};

3)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        for (auto& row : mat) {
            if (searchInRotatedArray(row, x)) return true;
        }
        return false;
    }
    bool searchInRotatedArray(vector<int>& arr, int x) {
        int l = 0, r = arr.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x) return true;
            if (arr[l] <= arr[mid]) {
                if (arr[l] <= x && x < arr[mid]) r = mid - 1;
                else l = mid + 1;
            } else {
                if (arr[mid] < x && x <= arr[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return false;
    }
};
