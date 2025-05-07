//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

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

        // Get the current node's value from the string
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node *inputTree() {
    string treeString;
    getline(cin, treeString);
    Node *root = buildTree(treeString);
    return root;
}

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> res;
        vector<int> path;
        function<void(Node*)> dfs = [&](Node* node) {
            if (!node) return;
            path.push_back(node->data);
            if (!node->left && !node->right) res.push_back(path);
            else {
                dfs(node->left);
                dfs(node->right);
            }
            path.pop_back();
        };
        dfs(root);
        return res;
    }
};

2)
class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        stack<pair<Node*, vector<int>>> st;
        st.push(make_pair(root, vector<int>{root->data}));
        while (!st.empty()) {
            pair<Node*, vector<int>> curr = st.top(); st.pop();
            Node* node = curr.first;
            vector<int> path = curr.second;
            if (!node->left && !node->right) {
                res.push_back(path);
            }
            if (node->right) {
                vector<int> rightPath = path;
                rightPath.push_back(node->right->data);
                st.push(make_pair(node->right, rightPath));
            }
            if (node->left) {
                vector<int> leftPath = path;
                leftPath.push_back(node->left->data);
                st.push(make_pair(node->left, leftPath));
            }
        }
        return res;
    }
};


3)
class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, path, res);
        return res;
    }
  private:
    void dfs(Node* node, vector<int>& path, vector<vector<int>>& res) {
        if (!node) return;
        
        path.push_back(node->data);
        if (!node->left && !node->right) {
            res.push_back(path);
        } else {
            dfs(node->left, path, res);
            dfs(node->right, path, res);
        }
        path.pop_back();
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        Node *root = inputTree();

        Solution obj;
        vector<vector<int>> res = obj.Paths(root);

        Matrix::print(res);

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
