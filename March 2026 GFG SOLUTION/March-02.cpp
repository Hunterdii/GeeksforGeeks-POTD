class Solution {
public:
    int maxWater(vector<int> &arr) {
        int l = 0, r = arr.size() - 1, lmax = 0, rmax = 0, res = 0;
        while (l < r) {
            if (arr[l] < arr[r]) {
                lmax = max(lmax, arr[l]);
                res += lmax - arr[l++];
            } else {
                rmax = max(rmax, arr[r]);
                res += rmax - arr[r--];
            }
        }
        return res;
    }
};

2)
class Solution {
public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        if (n <= 2) return 0;
        vector<int> lmax(n), rmax(n);
        lmax[0] = arr[0];
        for (int i = 1; i < n; i++)
            lmax[i] = max(lmax[i - 1], arr[i]);
        rmax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rmax[i] = max(rmax[i + 1], arr[i]);
        int res = 0;
        for (int i = 0; i < n; i++)
            res += min(lmax[i], rmax[i]) - arr[i];
        return res;
    }
};

3)
class Solution {
public:
    int maxWater(vector<int> &arr) {
        stack<int> st;
        int res = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break;
                int dist = i - st.top() - 1;
                int height = min(arr[i], arr[st.top()]) - arr[top];
                res += dist * height;
            }
            st.push(i);
        }
        return res;
    }
};

4)
class Solution {
public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        if (n <= 2) return 0;
        vector<int> left(n);
        left[0] = arr[0];
        for (int i = 1; i < n; i++)
            left[i] = max(left[i - 1], arr[i]);
        int res = 0, rmax = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rmax = max(rmax, arr[i]);
            res += min(left[i], rmax) - arr[i];
        }
        return res;
    }
};
