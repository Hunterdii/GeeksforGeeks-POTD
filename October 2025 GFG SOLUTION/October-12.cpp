/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    int distCandy(Node* root) {
        int moves = 0;
        function<int(Node*)> dfs = [&](Node* n) {
            if (!n) return 0;
            int bal = n->data - 1 + dfs(n->left) + dfs(n->right);
            moves += abs(bal);
            return bal;
        };
        dfs(root);
        return moves;
    }
};

2)
class Solution {
public:
    int distCandy(Node* root) {
        int result = 0;
        auto balance = [&](auto& self, Node* node) -> int {
            if (!node) return 0;
            int left = self(self, node->left);
            int right = self(self, node->right);
            int excess = node->data + left + right - 1;
            result += abs(left) + abs(right);
            return excess;
        };
        balance(balance, root);
        return result;
    }
};

3)
class Solution {
public:
    int distCandy(Node* root) {
        if (!root) return 0;
        stack<Node*> st;
        unordered_map<Node*, int> bal;
        Node* last = nullptr;
        Node* curr = root;
        int moves = 0;
        while (!st.empty() || curr) {
            if (curr) {
                st.push(curr);
                curr = curr->left;
            } else {
                Node* top = st.top();
                if (top->right && last != top->right) {
                    curr = top->right;
                } else {
                    int l = top->left ? bal[top->left] : 0;
                    int r = top->right ? bal[top->right] : 0;
                    bal[top] = top->data + l + r - 1;
                    moves += abs(l) + abs(r);
                    last = top;
                    st.pop();
                }
            }
        }
        return moves;
    }
};

4)
class Solution {
public:
    int distCandy(Node* root) {
        int moves = 0;
        unordered_map<Node*, int> balance;
        function<void(Node*)> postorder = [&](Node* n) {
            if (!n) return;
            postorder(n->left);
            postorder(n->right);
            int l = n->left ? balance[n->left] : 0;
            int r = n->right ? balance[n->right] : 0;
            balance[n] = n->data + l + r - 1;
            moves += abs(l) + abs(r);
        };
        postorder(root);
        return moves;
    }
};

5)
class Solution {
public:
    int helper(Node* n, int& moves) {
        if (!n) return 0;
        int l = helper(n->left, moves);
        int r = helper(n->right, moves);
        moves += abs(l) + abs(r);
        return n->data + l + r - 1;
    }
    
    int distCandy(Node* root) {
        int moves = 0;
        helper(root, moves);
        return moves;
    }
};
