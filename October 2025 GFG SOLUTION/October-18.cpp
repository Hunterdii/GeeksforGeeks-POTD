/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    int findMedian(Node* root) {
        int n = 0, k = 0, med = -1;
        Node* c = root;
        while (c) {
            if (!c->left) { n++; c = c->right; }
            else {
                Node* p = c->left;
                while (p->right && p->right != c) p = p->right;
                if (!p->right) { p->right = c; c = c->left; }
                else { p->right = nullptr; n++; c = c->right; }
            }
        }
        k = (n + 1) / 2;
        c = root;
        while (c) {
            if (!c->left) {
                if (++med == k - 1) return c->data;
                c = c->right;
            } else {
                Node* p = c->left;
                while (p->right && p->right != c) p = p->right;
                if (!p->right) { p->right = c; c = c->left; }
                else {
                    p->right = nullptr;
                    if (++med == k - 1) return c->data;
                    c = c->right;
                }
            }
        }
        return -1;
    }
};

2)
class Solution {
public:
    void inorder(Node* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    int findMedian(Node* root) {
        vector<int> v;
        inorder(root, v);
        return v[(v.size() - 1) / 2];
    }
};

3)
class Solution {
public:
    int countNodes(Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    void findKth(Node* root, int& k, int& res) {
        if (!root || k == 0) return;
        findKth(root->left, k, res);
        if (--k == 0) res = root->data;
        findKth(root->right, k, res);
    }
    int findMedian(Node* root) {
        int n = countNodes(root);
        int k = (n + 1) / 2, res = -1;
        findKth(root, k, res);
        return res;
    }
};

4)
class Solution {
public:
    int findMedian(Node* root) {
        stack<Node*> st;
        Node* c = root;
        int cnt = 0;
        while (c || !st.empty()) {
            while (c) { st.push(c); c = c->left; }
            c = st.top(); st.pop();
            cnt++;
            c = c->right;
        }
        int k = (cnt + 1) / 2;
        c = root; cnt = 0;
        while (c || !st.empty()) {
            while (c) { st.push(c); c = c->left; }
            c = st.top(); st.pop();
            if (++cnt == k) return c->data;
            c = c->right;
        }
        return -1;
    }
};
