/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    int nodeSum(Node* root, int l, int r) {
        if (!root) return 0;
        if (root->data < l) return nodeSum(root->right, l, r);
        if (root->data > r) return nodeSum(root->left, l, r);
        return root->data + nodeSum(root->left, l, r) + nodeSum(root->right, l, r);
    }
};

2)
class Solution {
public:
    int nodeSum(Node* root, int l, int r) {
        if (!root) return 0;
        queue<Node*> q;
        q.push(root);
        int sum = 0;
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            if (cur->data >= l && cur->data <= r) sum += cur->data;
            if (cur->left && cur->data > l) q.push(cur->left);
            if (cur->right && cur->data < r) q.push(cur->right);
        }
        return sum;
    }
};

3)
class Solution {
public:
    int nodeSum(Node* root, int l, int r) {
        int sum = 0;
        Node* cur = root;
        while (cur) {
            if (!cur->left) {
                if (cur->data >= l && cur->data <= r) sum += cur->data;
                cur = cur->right;
            } else {
                Node* pre = cur->left;
                while (pre->right && pre->right != cur) pre = pre->right;
                if (!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = nullptr;
                    if (cur->data >= l && cur->data <= r) sum += cur->data;
                    cur = cur->right;
                }
            }
        }
        return sum;
    }
};

4)
class Solution {
public:
    int nodeSum(Node* root, int l, int r) {
        if (!root) return 0;
        stack<Node*> st;
        st.push(root);
        int sum = 0;
        while (!st.empty()) {
            Node* cur = st.top();
            st.pop();
            if (cur->data >= l && cur->data <= r) sum += cur->data;
            if (cur->right && cur->data < r) st.push(cur->right);
            if (cur->left && cur->data > l) st.push(cur->left);
        }
        return sum;
    }
};
