class Solution {
public:
    int maxSum(vector<int> &arr) {
        int ans = 0;
        for (int i = 1; i < arr.size(); i++)
            ans = max(arr[i] + arr[i - 1], ans);
        return ans;
    }
};


2)
class Solution {
public:
    int maxSum(vector<int> &arr) {
        int maxSum = arr[0] + arr[1], n = arr.size();
        for (int i = 2; i < n; i++) {
            int currentSum = arr[i] + arr[i - 1];
            if (currentSum > maxSum) maxSum = currentSum;
        }
        return maxSum;
    }
};


3)
class Solution {
public:
    int maxSum(vector<int> &arr) {
        int result = 0;
        for (auto it = arr.begin() + 1; it != arr.end(); ++it)
            result = max(result, *it + *(it - 1));
        return result;
    }
};


4)
class Solution {
public:
    int maxSum(vector<int> &arr) {
        int n = arr.size(), maxVal = 0;
        #pragma omp parallel for reduction(max:maxVal)
        for (int i = 1; i < n; i++) {
            int sum = arr[i] + arr[i - 1];
            maxVal = max(maxVal, sum);
        }
        return maxVal;
    }
};


5)
class Solution {
public:
    int maxSum(vector<int> &arr) {
        int ans = 0, n = arr.size();
        for (int i = 1; i < n; i++) {
            int sum = arr[i] + arr[i - 1];
            ans = (sum > ans) ? sum : ans;
        }
        return ans;
    }
};


6)
class Solution {
public:
    int maxSum(vector<int> &arr) {
        int n = arr.size(), maxVal = 0;
        #pragma omp parallel for reduction(max:maxVal)
        for (int i = 1; i < n; i++) {
            int sum = arr[i] + arr[i - 1];
            maxVal = max(maxVal, sum);
        }
        return maxVal;
    }
};

7)
class Solution {
public:
    int maxSum(vector<int> &arr) {
        int result = arr[0] + arr[1];
        for (int i = 2; i < arr.size(); i++)
            result = max(result, arr[i] + arr[i - 1]);
        return result;
    }
};


