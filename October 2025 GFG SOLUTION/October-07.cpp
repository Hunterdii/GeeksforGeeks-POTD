/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    vector<int> bottomView(Node* root) {
        if (!root) return {};
        map<int, int> m;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();
            m[hd] = node->data;
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        vector<int> res;
        for (auto& [k, v] : m) res.push_back(v);
        return res;
    }
};

2)
class Solution {
public:
    vector<int> bottomView(Node* root) {
        map<int, pair<int, int>> m;
        dfs(root, 0, 0, m);
        vector<int> res;
        for (auto& [k, p] : m) res.push_back(p.second);
        return res;
    }
    void dfs(Node* node, int hd, int lvl, map<int, pair<int, int>>& m) {
        if (!node) return;
        if (m.find(hd) == m.end() || m[hd].first <= lvl) 
            m[hd] = {lvl, node->data};
        dfs(node->left, hd - 1, lvl + 1, m);
        dfs(node->right, hd + 1, lvl + 1, m);
    }
};

3)
class Solution {
public:
    vector<int> bottomView(Node* root) {
        if (!root) return {};
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                auto [curr, dist] = q.front();
                q.pop();
                mp[dist] = curr->data;
                if (curr->left) q.push({curr->left, dist - 1});
                if (curr->right) q.push({curr->right, dist + 1});
            }
        }
        vector<int> ans;
        for (auto& p : mp) ans.push_back(p.second);
        return ans;
    }
};

4)
class Solution {
public:
    vector<int> bottomView(Node* root) {
        if (!root) return {};
        int mn = 0, mx = 0;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();
            mn = min(mn, hd);
            mx = max(mx, hd);
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        vector<int> v(mx - mn + 1);
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();
            v[hd - mn] = node->data;
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        return v;
    }
};
