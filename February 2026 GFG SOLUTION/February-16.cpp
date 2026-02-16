class Solution {
public:
    bool canAttend(vector<vector<int>> &arr) {
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++)
            if (arr[i - 1][1] > arr[i][0]) return false;
        return true;
    }
};

2)
class Solution {
public:
    bool canAttend(vector<vector<int>> &arr) {
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) { return a[1] < b[1]; });
        for (int i = 1; i < arr.size(); i++)
            if (arr[i][0] < arr[i - 1][1]) return false;
        return true;
    }
};

3)
class Solution {
public:
    bool canAttend(vector<vector<int>> &arr) {
        if (arr.size() < 2) return true;
        sort(arr.begin(), arr.end());
        int end = arr[0][1];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i][0] < end) return false;
            end = arr[i][1];
        }
        return true;
    }
};

4)
class Solution {
public:
    bool canAttend(vector<vector<int>> &arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (!(arr[i][1] <= arr[j][0] || arr[j][1] <= arr[i][0]))
                    return false;
        return true;
    }
};
