class Solution {
public:
    int countSubarrays(vector<int>& arr) {
        int n = arr.size(), top = -1, ans = 0;
        vector<int> st(n);
        for (int i = n - 1; i >= 0; i--) {
            while (top >= 0 && arr[st[top]] >= arr[i]) top--;
            ans += ((top < 0 ? n : st[top]) - i);
            st[++top] = i;
        }
        return ans;
    }
};

2)
class Solution {
public:
    int countSubarrays(vector<int>& arr) {
        stack<int> st;
        int ans = 0, n = arr.size();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            int nxt = st.empty() ? n : st.top();
            ans += nxt - i;
            st.push(i);
        }
        return ans;
    }
};

3)
class Solution {
public:
    int countSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> nxt(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (!st.empty()) nxt[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) ans += nxt[i] - i;
        return ans;
    }
};

4)
class Solution {
public:
    int countSubarrays(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j + 1 < n && arr[i] <= arr[j + 1]) j++;
            ans += j - i + 1;
        }
        return ans;
    }
};
