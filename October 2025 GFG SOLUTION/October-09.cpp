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
    vector<int> postOrder(Node *root) {
        vector<int> res;
        Node *curr = root;
        while (curr) {
            if (!curr->right) {
                res.push_back(curr->data);
                curr = curr->left;
            } else {
                Node *pred = curr->right;
                while (pred->left && pred->left != curr) pred = pred->left;
                if (!pred->left) {
                    res.push_back(curr->data);
                    pred->left = curr;
                    curr = curr->right;
                } else {
                    pred->left = NULL;
                    curr = curr->left;
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

2)
class Solution {
public:
    vector<int> postOrder(Node *root) {
        vector<int> res;
        if (!root) return res;
        stack<Node*> s1, s2;
        s1.push(root);
        while (!s1.empty()) {
            Node* node = s1.top();
            s1.pop();
            s2.push(node);
            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }
        while (!s2.empty()) {
            res.push_back(s2.top()->data);
            s2.pop();
        }
        return res;
    }
};

3)
class Solution {
public:
    vector<int> postOrder(Node *root) {
        vector<int> res;
        if (!root) return res;
        stack<Node*> st;
        Node* curr = root;
        Node* last = nullptr;
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            Node* peek = st.top();
            if (peek->right && last != peek->right) {
                curr = peek->right;
            } else {
                res.push_back(peek->data);
                last = peek;
                st.pop();
            }
        }
        return res;
    }
};

4)
class Solution {
public:
    void dfs(Node* node, vector<int>& res) {
        if (!node) return;
        dfs(node->left, res);
        dfs(node->right, res);
        res.push_back(node->data);
    }
    
    vector<int> postOrder(Node *root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};
