//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}


// } Driver Code Ends
/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        if (!root) return {};
        queue<Node *> q({root});
        vector<vector<int>> res;
        while (!q.empty()) {
            res.push_back({});
            for (int i = q.size(); i > 0; i--) {
                Node *n = q.front(); q.pop();
                res.back().push_back(n->data);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
        }
        return res;
    }
};


1)
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        queue<Node*> q({root});
        vector<vector<int>> res;
        while (!q.empty()) {
            vector<int> level;
            for (int i = q.size(); i > 0; i--) {
                auto n = q.front(); q.pop();
                level.push_back(n->data);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            res.push_back(move(level));
        }
        return res;
    }
};

2)
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        return res;
    }
private:
    void dfs(Node* root, int lvl, vector<vector<int>>& res) {
        if (!root) return;
        if (lvl == res.size()) res.push_back({});
        res[lvl].push_back(root->data);
        dfs(root->left, lvl + 1, res);
        dfs(root->right, lvl + 1, res);
    }
};

3)
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> res;
        while (!q.empty()) {
            vector<int> level;
            int n = q.size();
            while (n--) {
                auto node = q.front(); q.pop();
                level.push_back(node->data);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(move(level));
        }
        return res;
    }
};


//{ Driver Code Starts.

/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
void inOrder(Node* node) {
    if (node == nullptr)
        return;

    inOrder(node->left);
    printf("%d ", node->data);

    inOrder(node->right);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return nullptr;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<vector<int>> res = ob.levelOrder(root);
        for (auto level : res) {
            for (int ele : level)
                cout << ele << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
