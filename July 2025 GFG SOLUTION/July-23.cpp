class Solution {
public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size(), sum = 0;
        for (int i = 0; i < n; ++i)
            sum += arr[i] * (i + 1) * (n - i);
        return sum;
    }
};

2)
class Solution {
public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size(), result = 0;
        for (int i = 0; i < n; ++i) {
            int leftCount = i + 1;
            int rightCount = n - i;
            result += arr[i] * leftCount * rightCount;
        }
        return result;
    }
};

3)
class Solution {
public:
    int subarraySum(vector<int>& arr) {
        int total = 0;
        for (int i = 0; i < arr.size(); ++i)
            total += arr[i] * (i + 1) * (arr.size() - i);
        return total;
    }
};

4)
class Solution {
public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            int pos = it - arr.begin();
            ans += *it * (pos + 1) * (n - pos);
        }
        return ans;
    }
};

5)
class Solution {
public:
    int subarraySum(vector<int>& arr) {
        int total = 0, size = arr.size();
        for (int idx = size - 1; idx >= 0; --idx)
            total += arr[idx] * (idx + 1) * (size - idx);
        return total;
    }
};

6)
class Solution {
public:
    int subarraySum(vector<int>& arr) {
        int sum = 0, n = arr.size(), i = 0;
        for (auto val : arr)
            sum += val * ++i * (n - i + 1);
        return sum;
    }
};

7)
class Solution {
public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size(), total = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                for (int k = i; k <= j; ++k) {
                    total += arr[k];
                }
            }
        }
        return total;
    }
};
