class Solution {
public:
    int maxPeople(vector<int>& arr) {
        int n = arr.size(), res = 0;
        vector<int> l(n, 1), r(n, 1);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] < arr[i]) l[i] += l[s.top()], s.pop();
            s.push(i);
        }
        s = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] < arr[i]) r[i] += r[s.top()], s.pop();
            s.push(i);
        }
        for (int i = 0; i < n; i++) res = max(res, l[i] + r[i] - 1);
        return res;
    }
};

2)
class Solution {
public:
    int maxPeople(vector<int>& arr) {
        int n = arr.size(), ans = 1;
        vector<int> vis(n, 1);
        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++) {
            int cnt = 1;
            while (!s.empty() && s.top().first < arr[i]) {
                cnt += s.top().second;
                s.pop();
            }
            s.push({arr[i], cnt});
            vis[i] = cnt;
        }
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; i--) {
            int cnt = 1;
            while (!s.empty() && s.top().first < arr[i]) {
                cnt += s.top().second;
                s.pop();
            }
            s.push({arr[i], cnt});
            ans = max(ans, vis[i] + cnt - 1);
        }
        return ans;
    }
};

3)
class Solution {
public:
    int maxPeople(vector<int>& arr) {
        int n = arr.size(), mx = 0;
        vector<int> dp(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            while (!st.empty() && arr[st.top()] < arr[i]) 
                dp[i] += dp[st.top()], st.pop();
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            int r = 1;
            while (!st.empty() && arr[st.top()] < arr[i]) 
                r += dp[st.top()], st.pop();
            mx = max(mx, dp[i] + r - 1);
            dp[i] = r;
            st.push(i);
        }
        return mx;
    }
};

4)
class Solution {
public:
    int maxPeople(vector<int>& arr) {
        int n = arr.size(), mx = 0;
        for (int i = 0; i < n; i++) {
            int cnt = 1;
            for (int j = i - 1; j >= 0 && arr[j] < arr[i]; j--) cnt++;
            for (int j = i + 1; j < n && arr[j] < arr[i]; j++) cnt++;
            mx = max(mx, cnt);
        }
        return mx;
    }
};
