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
    int findMaxFork(Node* root, int k) {
        int res = -1;
        while (root) {
            if (root->data == k) return k;
            if (root->data < k) {
                res = root->data;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return res;
    }
};


2)
class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        if (!root) return -1;
        if (root->data == k) return k;
        if (root->data < k) {
            int x = findMaxFork(root->right, k);
            return x == -1 ? root->data : x;
        }
        return findMaxFork(root->left, k);
    }
};


3)
class Solution {
  public:
    int res;
    void inorder(Node* node, int k) {
        if (!node) return;
        inorder(node->left, k);
        if (node->data > k) return;
        res = node->data;
        inorder(node->right, k);
    }
    int findMaxFork(Node* root, int k) {
        res = -1;
        inorder(root, k);
        return res;
    }
};
