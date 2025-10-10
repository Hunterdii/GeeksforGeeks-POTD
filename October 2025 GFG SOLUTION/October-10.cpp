/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> res;
        if (!root) return res;
        queue<Node*> q;
        q.push(root);
        bool ltr = true;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> lvl(sz);
            for (int i = 0; i < sz; i++) {
                Node* node = q.front();
                q.pop();
                int idx = ltr ? i : sz - 1 - i;
                lvl[idx] = node->data;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ltr = !ltr;
            res.insert(res.end(), lvl.begin(), lvl.end());
        }
        return res;
    }
};

2)
class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> res;
        if (!root) return res;
        deque<Node*> dq;
        dq.push_back(root);
        bool ltr = true;
        while (!dq.empty()) {
            int sz = dq.size();
            for (int i = 0; i < sz; i++) {
                if (ltr) {
                    Node* node = dq.front();
                    dq.pop_front();
                    res.push_back(node->data);
                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                } else {
                    Node* node = dq.back();
                    dq.pop_back();
                    res.push_back(node->data);
                    if (node->right) dq.push_front(node->right);
                    if (node->left) dq.push_front(node->left);
                }
            }
            ltr = !ltr;
        }
        return res;
    }
};

3)
class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> res;
        if (!root) return res;
        stack<Node*> s1, s2;
        s1.push(root);
        while (!s1.empty() || !s2.empty()) {
            while (!s1.empty()) {
                Node* node = s1.top();
                s1.pop();
                res.push_back(node->data);
                if (node->left) s2.push(node->left);
                if (node->right) s2.push(node->right);
            }
            while (!s2.empty()) {
                Node* node = s2.top();
                s2.pop();
                res.push_back(node->data);
                if (node->right) s1.push(node->right);
                if (node->left) s1.push(node->left);
            }
        }
        return res;
    }
};

4)
class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> res;
        if (!root) return res;
        queue<Node*> q;
        q.push(root);
        int lvl = 0;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            for (int i = 0; i < sz; i++) {
                Node* node = q.front();
                q.pop();
                temp.push_back(node->data);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (lvl % 2) reverse(temp.begin(), temp.end());
            res.insert(res.end(), temp.begin(), temp.end());
            lvl++;
        }
        return res;
    }
};
