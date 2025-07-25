class Solution {
public:
    int maxCircularSum(vector<int>& arr) {
        int n = arr.size();
        int maxKadane = kadane(arr);
        int totalSum = 0;
        for (int& x : arr) {
            totalSum += x;
            x = -x;
        }
        int maxCircular = totalSum + kadane(arr);
        return maxCircular == 0 ? maxKadane : max(maxKadane, maxCircular);
    }
private:
    int kadane(vector<int>& arr) {
        int maxSum = arr[0], currSum = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            currSum = max(arr[i], currSum + arr[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};

2)
class Solution {
public:
    int maxCircularSum(vector<int>& arr) {
        int total = 0, maxSum = INT_MIN, minSum = INT_MAX;
        int currMax = 0, currMin = 0;
        for (int x : arr) {
            total += x;
            currMax = max(x, currMax + x);
            currMin = min(x, currMin + x);
            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);
        }
        return total == minSum ? maxSum : max(maxSum, total - minSum);
    }
};

3)
class Solution {
public:
    int maxCircularSum(vector<int>& arr) {
        int n = arr.size();
        int maxLinear = kadane(arr);
        deque<int> dq;
        vector<int> prefixSum(2*n + 1, 0);
        for (int i = 0; i < 2*n; i++) {
            prefixSum[i+1] = prefixSum[i] + arr[i % n];
        }
        int maxCircular = INT_MIN;
        for (int i = 0; i < 2*n; i++) {
            while (!dq.empty() && prefixSum[dq.back()] >= prefixSum[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            while (!dq.empty() && dq.front() <= i - n) {
                dq.pop_front();
            }
            if (i >= n-1) {
                maxCircular = max(maxCircular, prefixSum[i+1] - prefixSum[dq.front()]);
            }
        }
        return max(maxLinear, maxCircular);
    }
private:
    int kadane(vector<int>& arr) {
        int maxSum = arr[0], currSum = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            currSum = max(arr[i], currSum + arr[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
