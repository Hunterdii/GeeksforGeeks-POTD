/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    int findMaxSum(Node *root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
    
    int dfs(Node *node, int &res) {
        if (!node) return 0;
        int l = max(0, dfs(node->left, res));
        int r = max(0, dfs(node->right, res));
        res = max(res, node->data + l + r);
        return node->data + max(l, r);
    }
};

2)
class Solution {
public:
    int findMaxSum(Node *root) {
        if (!root) return 0;
        stack<Node*> st;
        unordered_map<Node*, int> mp;
        int res = root->data;
        st.push(root);
        while (!st.empty()) {
            Node* node = st.top();
            if ((node->left && !mp.count(node->left)) || (node->right && !mp.count(node->right))) {
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
            } else {
                st.pop();
                int l = node->left ? max(0, mp[node->left]) : 0;
                int r = node->right ? max(0, mp[node->right]) : 0;
                res = max(res, node->data + l + r);
                mp[node] = node->data + max(l, r);
            }
        }
        return res;
    }
};

3)
class Solution {
public:
    int findMaxSum(Node *root) {
        return helper(root).first;
    }
    
    pair<int, int> helper(Node* node) {
        if (!node) return {INT_MIN, 0};
        auto [lMax, lPath] = helper(node->left);
        auto [rMax, rPath] = helper(node->right);
        int pathThrough = node->data + max(0, lPath) + max(0, rPath);
        int maxSoFar = max({lMax, rMax, pathThrough});
        int pathEnd = node->data + max({0, lPath, rPath});
        return {maxSoFar, pathEnd};
    }
};

4)
class Solution {
public:
    int findMaxSum(Node *root) {
        int res = INT_MIN;
        function<int(Node*)> solve = [&](Node* n) {
            if (!n) return 0;
            int l = max(0, solve(n->left)), r = max(0, solve(n->right));
            res = max(res, n->data + l + r);
            return n->data + max(l, r);
        };
        solve(root);
        return res;
    }
};
