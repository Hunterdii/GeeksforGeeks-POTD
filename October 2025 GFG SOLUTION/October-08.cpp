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
};
*/

class Solution {
public:
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        int i = 0;
        return build(pre, post, i, 0, post.size() - 1);
    }
    
    Node* build(vector<int>& pre, vector<int>& post, int& i, int l, int r) {
        Node* root = new Node(pre[i++]);
        if (l != r) root->left = build(pre, post, i, l, find(post.begin() + l, post.begin() + r, pre[i]) - post.begin());
        if (l != r && i < pre.size()) root->right = build(pre, post, i, find(post.begin() + l, post.begin() + r, root->left->data) - post.begin() + 1, r - 1);
        return root;
    }
};

2)
class Solution {
public:
    int idx = 0;
    Node* constructTree(vector<int>& pre, vector<int>& post) {
        return build(pre, post, 0, post.size() - 1);
    }
    Node* build(vector<int>& pre, vector<int>& post, int l, int r) {
        Node* root = new Node(pre[idx++]);
        
        if (l != r && idx < pre.size()) {
            int pos = l;
            while (post[pos] != pre[idx]) pos++;
            
            root->left  = build(pre, post, l, pos);
            root->right = build(pre, post, pos + 1, r - 1);
        }
        return root;
    }
};

3)
class Solution {
public:
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        unordered_map<int, int> m;
        for (int i = 0; i < post.size(); i++) m[post[i]] = i;
        int idx = 0;
        return build(pre, post, m, idx, 0, post.size() - 1);
    }
    
    Node* build(vector<int>& pre, vector<int>& post, unordered_map<int,int>& m, int& idx, int l, int r) {
        Node* root = new Node(pre[idx++]);
        if (l == r || idx >= pre.size()) return root;
        int pos = m[pre[idx]];
        if (pos <= r) {
            root->left = build(pre, post, m, idx, l, pos);
            root->right = build(pre, post, m, idx, pos + 1, r - 1);
        }
        return root;
    }
};

4)
class Solution {
public:
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        stack<Node*> s;
        Node* root = new Node(pre[0]);
        s.push(root);
        for (int i = 1, j = 0; i < pre.size(); i++) {
            Node* node = new Node(pre[i]);
            while (s.top()->data == post[j]) {
                s.pop();
                j++;
            }
            if (!s.top()->left) s.top()->left = node;
            else s.top()->right = node;
            s.push(node);
        }
        return root;
    }
};

5)
class Solution {
public:
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        return build(pre, post, 0, pre.size() - 1, 0, post.size() - 1);
    }
    
    Node* build(vector<int>& pre, vector<int>& post, int preL, int preR, int postL, int postR) {
        if (preL > preR) return nullptr;
        Node* root = new Node(pre[preL]);
        if (preL == preR) return root;
        int idx = postL;
        while (post[idx] != pre[preL + 1]) idx++;
        int leftSize = idx - postL + 1;
        root->left = build(pre, post, preL + 1, preL + leftSize, postL, idx);
        root->right = build(pre, post, preL + leftSize + 1, preR, idx + 1, postR - 1);
        return root;
    }
};
