/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
public:
    int getMaxSum(Node* root) {
        function<pair<int,int>(Node*)> dfs = [&](Node* node) -> pair<int,int> {
            if (!node) return {0, 0};
            auto [li, le] = dfs(node->left);
            auto [ri, re] = dfs(node->right);
            return {node->data + le + re, max(li, le) + max(ri, re)};
        };
        auto [inc, exc] = dfs(root);
        return max(inc, exc);
    }
};

2)
class Solution {
public:
    unordered_map<Node*, pair<int,int>> dp;
    int getMaxSum(Node* root) {
        if (!root) return 0;
        if (dp.count(root)) return max(dp[root].first, dp[root].second);
        getMaxSum(root->left);
        getMaxSum(root->right);
        int inc = root->data + (root->left ? dp[root->left].second : 0) + (root->right ? dp[root->right].second : 0);
        int exc = (root->left ? max(dp[root->left].first, dp[root->left].second) : 0) + (root->right ? max(dp[root->right].first, dp[root->right].second) : 0);
        dp[root] = {inc, exc};
        return max(inc, exc);
    }
};

3)
class Solution {
public:
    vector<int> solve(Node* root) {
        if (!root) return {0, 0};
        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);
        return {root->data + l[1] + r[1], max(l[0], l[1]) + max(r[0], r[1])};
    }
    int getMaxSum(Node* root) {
        vector<int> res = solve(root);
        return max(res[0], res[1]);
    }
};

4)
class Solution {
public:
    int getMaxSum(Node* root) {
        if (!root) return 0;
        stack<Node*> st;
        unordered_map<Node*, pair<int,int>> m;
        st.push(root);
        while (!st.empty()) {
            Node* node = st.top();
            if ((node->left && !m.count(node->left)) || (node->right && !m.count(node->right))) {
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
            } else {
                st.pop();
                int inc = node->data + (node->left ? m[node->left].second : 0) + (node->right ? m[node->right].second : 0);
                int exc = (node->left ? max(m[node->left].first, m[node->left].second) : 0) + (node->right ? max(m[node->right].first, m[node->right].second) : 0);
                m[node] = {inc, exc};
            }
        }
        return max(m[root].first, m[root].second);
    }
};
