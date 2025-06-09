/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool dfs(Node* root, int l, int r) {
        if (!root) return false;
        if (!root->left && !root->right && l == r) return true;
        return dfs(root->left, l, root->data - 1) || dfs(root->right, root->data + 1, r);
    }
    bool isDeadEnd(Node* root) {
        return dfs(root, 1, INT_MAX);
    }
};

2)
class Solution {
  public:
    void traverse(Node* root, unordered_set<int>& all, unordered_set<int>& leaf) {
        if (!root) return;
        all.insert(root->data);
        if (!root->left && !root->right) leaf.insert(root->data);
        traverse(root->left, all, leaf);
        traverse(root->right, all, leaf);
    }
    
    bool isDeadEnd(Node* root) {
        unordered_set<int> all, leaf;
        all.insert(0);
        traverse(root, all, leaf);
        for (int val : leaf)
            if (all.count(val - 1) && all.count(val + 1))
                return true;
        return false;
    }
};

3)
class Solution {
  public:
    bool check(Node* root, int min, int max) {
        if (!root) return false;
        if (min == max) return true;
        return check(root->left, min, root->data - 1) || 
               check(root->right, root->data + 1, max);
    }
    bool isDeadEnd(Node* root) {
        return check(root, 1, INT_MAX);
    }
};
