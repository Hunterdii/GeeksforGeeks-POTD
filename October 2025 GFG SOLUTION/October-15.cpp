/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    int kthSmallest(Node *root, int k) {
        stack<Node*> s;
        Node* n = root;
        int c = 0;
        while (n || !s.empty()) {
            while (n) {
                s.push(n);
                n = n->left;
            }
            n = s.top(); s.pop();
            if (++c == k) return n->data;
            n = n->right;
        }
        return -1;
    }
};

2)
class Solution {
public:
    int kthSmallest(Node* root, int k) {
        Node* c = root;
        int cnt = 0;
        while (c) {
            if (!c->left) {
                if (++cnt == k) return c->data;
                c = c->right;
            } else {
                Node* p = c->left;
                while (p->right && p->right != c) p = p->right;
                if (!p->right) {
                    p->right = c;
                    c = c->left;
                } else {
                    p->right = NULL;
                    if (++cnt == k) return c->data;
                    c = c->right;
                }
            }
        }
        return -1;
    }
};

3)
class Solution {
public:
    int kthSmallest(Node* root, int k) {
        if (!root) return -1;
        int lc = countNodes(root->left);
        if (k == lc + 1) return root->data;
        if (k <= lc) return kthSmallest(root->left, k);
        return kthSmallest(root->right, k - lc - 1);
    }
    
    int countNodes(Node* n) {
        return n ? 1 + countNodes(n->left) + countNodes(n->right) : 0;
    }
};

4)
class Solution {
public:
    int kthSmallest(Node* root, int k) {
        int n = countNodes(root);
        int c = 0;
        return helper(root, c, n - k + 1);
    }
    
    int helper(Node* r, int& c, int k) {
        if (!r) return -1;
        int ri = helper(r->right, c, k);
        if (ri != -1) return ri;
        if (++c == k) return r->data;
        return helper(r->left, c, k);
    }
    
    int countNodes(Node* n) {
        return n ? 1 + countNodes(n->left) + countNodes(n->right) : 0;
    }
};
