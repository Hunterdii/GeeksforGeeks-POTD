class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), res = 0;
        vector<int> h(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) 
                h[j] = mat[i][j] ? h[j] + 1 : 0;
            stack<int> st;
            for (int j = 0; j <= m; j++) {
                int cur = j == m ? 0 : h[j];
                while (!st.empty() && h[st.top()] > cur) {
                    int tp = st.top(); st.pop();
                    int w = st.empty() ? j : j - st.top() - 1;
                    res = max(res, h[tp] * w);
                }
                st.push(j);
            }
        }
        return res;
    }
};

2)
class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), res = 0;
        vector<int> h(m, 0), l(m, 0), r(m, m);
        for (int i = 0; i < n; i++) {
            int cl = 0, cr = m;
            for (int j = 0; j < m; j++) {
                h[j] = mat[i][j] ? h[j] + 1 : 0;
                l[j] = mat[i][j] ? max(l[j], cl) : (cl = j + 1, 0);
            }
            for (int j = m - 1; j >= 0; j--) {
                r[j] = mat[i][j] ? min(r[j], cr) : (cr = j, m);
                res = max(res, h[j] * (r[j] - l[j]));
            }
        }
        return res;
    }
};

3)
class Solution {
private:
    int divide(vector<int>& h, int l, int r) {
        if (l > r) return 0;
        int mid = l;
        for (int i = l + 1; i <= r; i++)
            if (h[i] < h[mid]) mid = i;
        return max({h[mid] * (r - l + 1), 
                  divide(h, l, mid - 1), 
                  divide(h, mid + 1, r)});
    }
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), res = 0;
        vector<int> h(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                h[j] = mat[i][j] ? h[j] + 1 : 0;
            res = max(res, divide(h, 0, m - 1));
        }
        return res;
    }
};

4)
class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), res = 0;
        vector<int> h(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                h[j] = mat[i][j] ? h[j] + 1 : 0;
            deque<int> dq;
            for (int j = 0; j <= m; j++) {
                int cur = j == m ? 0 : h[j];
                while (!dq.empty() && h[dq.back()] > cur) {
                    int tp = dq.back(); dq.pop_back();
                    int w = dq.empty() ? j : j - dq.back() - 1;
                    res = max(res, h[tp] * w);
                }
                dq.push_back(j);
            }
        }
        return res;
    }
};
