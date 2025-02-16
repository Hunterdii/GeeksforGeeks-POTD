//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    void serializeUtil(Node *root, vector<int> &a) {
        if (!root) { a.push_back(-1); return; }
        a.push_back(root->data);
        serializeUtil(root->left, a);
        serializeUtil(root->right, a);
    }

    vector<int> serialize(Node *root) {
        vector<int> a;
        serializeUtil(root, a);
        return a;
    }

    Node *buildTree(vector<int> &a, int &i) {
        if (i >= a.size() || a[i] == -1) return i++, nullptr;
        Node *root = new Node(a[i++]);
        root->left = buildTree(a, i);
        root->right = buildTree(a, i);
        return root;
    }

    Node *deSerialize(vector<int> &a) {
        int i = 0;
        return buildTree(a, i);
    }
};

2)
class Solution {
public:
    vector<int> serialize(Node* root) {
        vector<int> res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front(); q.pop();
            if (node) {
                res.push_back(node->data);
                q.push(node->left);
                q.push(node->right);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }

    Node* deSerialize(vector<int>& data) {
        if (data.empty() || data[0] == -1) return nullptr;
        Node* root = new Node(data[0]);
        queue<Node*> q;
        q.push(root);
        int i = 1;
        while (!q.empty()) {
            Node* node = q.front(); q.pop();
            if (data[i] != -1) {
                node->left = new Node(data[i]);
                q.push(node->left);
            }
            i++;
            if (data[i] != -1) {
                node->right = new Node(data[i]);
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};


3)
class Solution {
public:
    vector<int> serialize(Node* root) {
        vector<int> a;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            if (cur) {
                a.push_back(cur->data);
                q.push(cur->left);
                q.push(cur->right);
            } else {
                a.push_back(-1);
            }
        }
        return a;
    }

    Node* deSerialize(vector<int>& a) {
        if (a.empty() || a[0] == -1) return nullptr;
        Node* root = new Node(a[0]);
        queue<Node*> q;
        q.push(root);
        int i = 1;
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            if (i < a.size() && a[i] != -1) cur->left = new Node(a[i]);
            if (cur->left) q.push(cur->left);
            i++;
            if (i < a.size() && a[i] != -1) cur->right = new Node(a[i]);
            if (cur->right) q.push(cur->right);
            i++;
        }
        return root;
    }
};

4)
class Solution {
public:
    vector<int> serialize(Node* root) {
        vector<int> res;
        function<void(Node*)> dfs = [&](Node* node) {
            if (!node) { res.push_back(-1); return; }
            res.push_back(node->data);
            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);
        return res;
    }

    Node* deSerialize(vector<int>& data) {
        int i = 0;
        function<Node*()> dfs = [&]() -> Node* {
            if (i >= data.size() || data[i] == -1) { i++; return nullptr; }
            Node* node = new Node(data[i++]);
            node->left = dfs();
            node->right = dfs();
            return node;
        };
        return dfs();
    }
};

5)
class Solution {
public:
    vector<int> serialize(Node* root) {
        vector<int> res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front(); q.pop();
            if (!node) { res.push_back(-1); continue; }
            res.push_back(node->data);
            q.push(node->left);
            q.push(node->right);
        }
        return res;
    }

    Node* deSerialize(vector<int>& data) {
        if (data.empty() || data[0] == -1) return nullptr;
        queue<Node*> q;
        Node* root = new Node(data[0]);
        q.push(root);
        for (int i = 1; i < data.size(); i++) {
            Node* parent = q.front();
            q.pop();
            if (data[i] != -1) {
                parent->left = new Node(data[i]);
                q.push(parent->left);
            }
            if (++i < data.size() && data[i] != -1) {
                parent->right = new Node(data[i]);
                q.push(parent->right);
            }
        }
        return root;
    }
};


//{ Driver Code Starts.

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node *node) {
    if (node == NULL)
        return;

    /* first delete both subtrees */
    _deleteTree(node->left);
    _deleteTree(node->right);

    /* then delete the node */
    // cout << "Deleting node: " << node->data << endl;
    delete node;
}

/* Deletes a tree and sets the root as NULL */
void deleteTree(Node **node_ref) {
    _deleteTree(*node_ref);
    *node_ref = NULL;
}

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);

        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        Node *temp = root;
        deleteTree(&root);
        Node *getRoot = deserial.deSerialize(A);
        inorder(getRoot);

        cout << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
