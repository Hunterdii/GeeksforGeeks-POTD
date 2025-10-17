/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
public:
    void transformTree(Node* root) {
        int s = 0;
        function<void(Node*)> f = [&](Node* n) {
            if (!n) return;
            f(n->right);
            int temp = n->data;
            n->data = s;
            s += temp;
            f(n->left);
        };
        f(root);
    }
};


2)
class Solution {
public:
    void transformTree(Node* root) {
        stack<Node*> st;
        Node* curr = root;
        int sum = 0;
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->right;
            }
            curr = st.top();
            st.pop();
            int temp = curr->data;
            curr->data = sum;
            sum += temp;
            curr = curr->left;
        }
    }
};

3)
class Solution {
public:
    void transformTree(Node* root) {
        int sum = 0;
        Node* curr = root;
        while (curr) {
            if (!curr->right) {
                int temp = curr->data;
                curr->data = sum;
                sum += temp;
                curr = curr->left;
            } else {
                Node* pred = curr->right;
                while (pred->left && pred->left != curr)
                    pred = pred->left;
                if (!pred->left) {
                    pred->left = curr;
                    curr = curr->right;
                } else {
                    pred->left = nullptr;
                    int temp = curr->data;
                    curr->data = sum;
                    sum += temp;
                    curr = curr->left;
                }
            }
        }
    }
};

4)
class Solution {
public:
    void helper(Node* n, int& sum) {
        if (!n) return;
        helper(n->right, sum);
        int temp = n->data;
        n->data = sum;
        sum += temp;
        helper(n->left, sum);
    }
    
    void transformTree(Node* root) {
        int sum = 0;
        helper(root, sum);
    }
};
