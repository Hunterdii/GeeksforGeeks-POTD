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
    Node* removekeys(Node* root, int l, int r) {
        if (!root) return NULL;
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        if (root->data < l) return root->right;
        if (root->data > r) return root->left;
        return root;
    }
};

2)
class Solution {
public:
    Node* removekeys(Node* root, int l, int r) {
        if (!root) return NULL;
        stack<Node*> st;
        st.push(root);
        unordered_map<Node*, Node*> processed;
        while (!st.empty()) {
            Node* curr = st.top();
            if ((curr->left && !processed.count(curr->left)) || 
                (curr->right && !processed.count(curr->right))) {
                if (curr->right) st.push(curr->right);
                if (curr->left) st.push(curr->left);
            } else {
                st.pop();
                Node* left = curr->left ? processed[curr->left] : NULL;
                Node* right = curr->right ? processed[curr->right] : NULL;
                if (curr->data >= l && curr->data <= r) {
                    curr->left = left;
                    curr->right = right;
                    processed[curr] = curr;
                } else if (curr->data < l) {
                    processed[curr] = right;
                } else {
                    processed[curr] = left;
                }
            }
        }
        return processed[root];
    }
};

3)
class Solution {
public:
    Node* removekeys(Node* root, int l, int r) {
        root = trimLeft(root, l);
        root = trimRight(root, r);
        return root;
    }
    Node* trimLeft(Node* n, int l) {
        if (!n) return NULL;
        if (n->data < l) return trimLeft(n->right, l);
        n->left = trimLeft(n->left, l);
        return n;
    }
    Node* trimRight(Node* n, int r) {
        if (!n) return NULL;
        if (n->data > r) return trimRight(n->left, r);
        n->right = trimRight(n->right, r);
        return n;
    }
};

4)
class Solution {
public:
    Node* removekeys(Node* root, int l, int r) {
        return filter(root, l, r);
    }
    
    Node* filter(Node* node, int l, int r) {
        if (!node) return NULL;
        if (node->data < l) return filter(node->right, l, r);
        if (node->data > r) return filter(node->left, l, r);
        node->left = filter(node->left, l, r);
        node->right = filter(node->right, l, r);
        return node;
    }
};
