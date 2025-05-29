/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void sumOfRootToLeaf(Node* r, int s, int l, int& ml, int& ms) {
        if (!r) {
            if (l > ml) ml = l, ms = s;
            else if (l == ml && s > ms) ms = s;
            return;
        }
        sumOfRootToLeaf(r->left, s + r->data, l + 1, ml, ms);
        sumOfRootToLeaf(r->right, s + r->data, l + 1, ml, ms);
    }
    int sumOfLongRootToLeafPath(Node* root) {
        int ms = INT_MIN, ml = 0;
        sumOfRootToLeaf(root, 0, 0, ml, ms);
        return ms;
    }
};

2)
class Solution {
  public:
    pair<int, int> dfs(Node* root) {
        if (!root) return {0, 0};
        auto l = dfs(root->left), r = dfs(root->right);
        if (l.first > r.first) return {l.first + 1, l.second + root->data};
        if (r.first > l.first) return {r.first + 1, r.second + root->data};
        return {l.first + 1, max(l.second, r.second) + root->data};
    }
    int sumOfLongRootToLeafPath(Node* root) {
        return dfs(root).second;
    }
};


