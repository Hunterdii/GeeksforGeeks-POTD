class Solution {
public:
    int celebrity(vector<vector<int>>& m) {
        int n = m.size(), c = 0;
        for (int i = 1; i < n; i++) if (m[c][i]) c = i;
        for (int i = 0; i < n; i++) if (i != c && (m[c][i] || !m[i][c])) return -1;
        return c;
    }
};

2)
class Solution {
public:
    int celebrity(vector<vector<int>>& m) {
        int n = m.size();
        vector<int> rowSum(n, 0), colSum(n, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    rowSum[i] += m[i][j];
                    colSum[j] += m[i][j];
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (rowSum[i] == 0 && colSum[i] == n - 1) return i;
        }
        return -1;
    }
};

3)
class Solution {
private:
    int findCelebrity(vector<vector<int>>& m, int l, int r) {
        if (l == r) return l;
        int mid = (l + r) / 2;
        int left = findCelebrity(m, l, mid);
        int right = findCelebrity(m, mid + 1, r);
        if (left == -1) return right;
        if (right == -1) return left;
        return m[left][right] ? right : left;
    }
public:
    int celebrity(vector<vector<int>>& m) {
        int n = m.size();
        int c = findCelebrity(m, 0, n - 1);
        if (c == -1) return -1;
        for (int i = 0; i < n; i++) if (i != c && (m[c][i] || !m[i][c])) return -1;
        return c;
    }
};

4)
class Solution {
public:
    int celebrity(vector<vector<int>>& m) {
        int n = m.size();
        stack<int> st;
        for (int i = 0; i < n; i++) st.push(i);
        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            st.push(m[a][b] ? b : a);
        }
        int c = st.top();
        for (int i = 0; i < n; i++) if (i != c && (m[c][i] || !m[i][c])) return -1;
        return c;
    }
};
