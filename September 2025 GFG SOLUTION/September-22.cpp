class Solution {
public:
    vector<int> maxOfMins(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n), mx(n + 1);
        stack<int> st;
        
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || a[st.top()] >= a[i])) {
                int mid = st.top(); st.pop();
                int w = i - (st.empty() ? -1 : st.top()) - 1;
                mx[w] = max(mx[w], a[mid]);
            }
            st.push(i);
        }
        
        for (int i = 1; i <= n; i++) ans[i-1] = mx[i];
        for (int i = n-2; i >= 0; i--) ans[i] = max(ans[i], ans[i+1]);
        return ans;
    }
};


2)
class Solution {
public:
    vector<int> maxOfMins(vector<int>& a) {
        int n = a.size();
        vector<int> result(n);
        
        for (int k = 1; k <= n; k++) {
            int maxOfMin = 0;
            for (int i = 0; i <= n - k; i++) {
                int minVal = INT_MAX;
                for (int j = i; j < i + k; j++) {
                    minVal = min(minVal, a[j]);
                }
                maxOfMin = max(maxOfMin, minVal);
            }
            result[k-1] = maxOfMin;
        }
        return result;
    }
};


3)
class Solution {
public:
    vector<int> maxOfMins(vector<int>& a) {
        int n = a.size();
        vector<int> prev(n, -1), next(n, n), res(n), len(n+1);
        stack<int> s;
        
        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[s.top()] >= a[i]) s.pop();
            prev[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        
        while (!s.empty()) s.pop();
        
        for (int i = n-1; i >= 0; i--) {
            while (!s.empty() && a[s.top()] >= a[i]) s.pop();
            next[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        
        for (int i = 0; i < n; i++) {
            int w = next[i] - prev[i] - 1;
            len[w] = max(len[w], a[i]);
        }
        
        for (int i = 1; i <= n; i++) res[i-1] = len[i];
        for (int i = n-2; i >= 0; i--) res[i] = max(res[i], res[i+1]);
        return res;
    }
};
