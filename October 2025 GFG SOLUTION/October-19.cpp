/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int> in;
        stack<Node*> s;
        Node* curr = root;
        while (curr || !s.empty()) {
            while (curr) s.push(curr), curr = curr->left;
            curr = s.top(); s.pop();
            in.push_back(curr->data);
            curr = curr->right;
        }
        int n = in.size(), pos = lower_bound(in.begin(), in.end(), target) - in.begin();
        if (pos > 0 && (pos == n || abs(in[pos - 1] - target) <= abs(in[pos] - target))) pos--;
        vector<int> res;
        int l = pos, r = pos + 1;
        while (k--) {
            if (r >= n || (l >= 0 && abs(in[l] - target) <= abs(in[r] - target)))
                res.push_back(in[l--]);
            else
                res.push_back(in[r++]);
        }
        return res;
    }
};

2)
class Solution {
public:
    void dfs(Node* node, int t, int k, priority_queue<pair<int,int>>& pq) {
        if (!node) return;
        int d = abs(node->data - t);
        if (pq.size() < k) pq.push({d, node->data});
        else if (d < pq.top().first || (d == pq.top().first && node->data < pq.top().second)) {
            pq.pop();
            pq.push({d, node->data});
        }
        dfs(node->left, t, k, pq);
        dfs(node->right, t, k, pq);
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        priority_queue<pair<int,int>> pq;
        dfs(root, target, k, pq);
        vector<int> res;
        while (!pq.empty()) res.push_back(pq.top().second), pq.pop();
        return res;
    }
};

3)
class Solution {
public:
    void inorder(Node* node, vector<int>& v) {
        if (!node) return;
        inorder(node->left, v);
        v.push_back(node->data);
        inorder(node->right, v);
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int> v;
        inorder(root, v);
        int n = v.size(), l = 0, r = n - 1, pos = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (v[m] <= target) pos = m, l = m + 1;
            else r = m - 1;
        }
        vector<int> res;
        l = pos; r = pos + 1;
        while (k--) {
            if (r >= n || (l >= 0 && abs(v[l] - target) <= abs(v[r] - target)))
                res.push_back(v[l--]);
            else
                res.push_back(v[r++]);
        }
        return res;
    }
};

4)
class Solution {
public:
    void pushLeft(Node* node, stack<Node*>& s) {
        while (node) s.push(node), node = node->left;
    }
    void pushRight(Node* node, stack<Node*>& s) {
        while (node) s.push(node), node = node->right;
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        stack<Node*> pred, succ;
        Node* curr = root;
        while (curr) {
            if (curr->data < target) pred.push(curr), curr = curr->right;
            else succ.push(curr), curr = curr->left;
        }
        vector<int> res;
        while (k--) {
            if (pred.empty()) {
                Node* node = succ.top(); succ.pop();
                res.push_back(node->data);
                pushLeft(node->right, succ);
            } else if (succ.empty()) {
                Node* node = pred.top(); pred.pop();
                res.push_back(node->data);
                pushRight(node->left, pred);
            } else {
                int pVal = pred.top()->data, sVal = succ.top()->data;
                if (abs(pVal - target) <= abs(sVal - target)) {
                    res.push_back(pVal);
                    Node* node = pred.top(); pred.pop();
                    pushRight(node->left, pred);
                } else {
                    res.push_back(sVal);
                    Node* node = succ.top(); succ.pop();
                    pushLeft(node->right, succ);
                }
            }
        }
        return res;
    }
};
