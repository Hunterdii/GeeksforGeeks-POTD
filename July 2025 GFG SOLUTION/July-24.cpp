class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;
        for (int i = 0; i < left.size(); ++i) {
            result = result > left[i] ? result : left[i];
        }
        for (int i = 0; i < right.size(); ++i) {
            int val = n - right[i];
            result = result > val ? result : val;
        }
        return result;
    }
};

2)
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int leftMax = left.empty() ? 0 : *max_element(left.begin(), left.end());
        int rightMin = right.empty() ? n : *min_element(right.begin(), right.end());
        return max(leftMax, n - rightMin);
    }
};

3)
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for (int x : left) ans = max(ans, x);
        for (int x : right) ans = max(ans, n - x);
        return ans;
    }
};

4)
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int leftMax = left.empty() ? 0 : *max_element(left.begin(), left.end());
        int rightMax = 0;
        for (int pos : right) rightMax = max(rightMax, n - pos);
        return max(leftMax, rightMax);
    }
};

5)
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;
        for (auto& pos : left) result = max(result, pos);
        for (auto& pos : right) result = max(result, n - pos);
        return result;
    }
};

6)
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;
        for (int i = 0; i < left.size(); ++i) {
            result = result > left[i] ? result : left[i];
        }
        for (int i = 0; i < right.size(); ++i) {
            int val = n - right[i];
            result = result > val ? result : val;
        }
        return result;
    }
};

6)
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int leftMax = left.empty() ? 0 : *max_element(left.begin(), left.end());
        
        int rightMax = 0;
        if (!right.empty()) {
            vector<int> rightTimes(right.size());
            transform(right.begin(), right.end(), rightTimes.begin(), 
                     [n](int pos) { return n - pos; });
            rightMax = *max_element(rightTimes.begin(), rightTimes.end());
        }
        
        return max(leftMax, rightMax);
    }
};

7)
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int leftTime = left.empty() ? 0 : *max_element(left.begin(), left.end());
        int rightTime = 0;
        if (!right.empty()) {
            rightTime = n - *min_element(right.begin(), right.end());
        }
        return max(leftTime, rightTime);
    }
};

