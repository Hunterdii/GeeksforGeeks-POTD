//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000
#define MAX_SIZE 100000

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
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
    Node* root = new Node(stoi(ip[0]));

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


// } Driver Code Ends
/*
Node is as follows
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
    bool findTarget(Node* root, int target) {
        unordered_set<int> seen;
        return dfs(root, target, seen);
    }
    
    bool dfs(Node* root, int target, unordered_set<int>& seen) {
        if (!root) return false;
        if (seen.count(target - root->data)) return true;
        seen.insert(root->data);
        return dfs(root->left, target, seen) || dfs(root->right, target, seen);
    }
};

2)
class Solution {
public:
    bool findTarget(Node* root, int target) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        int left = 0, right = inorder.size() - 1;
        while (left < right) {
            int sum = inorder[left] + inorder[right];
            if (sum == target) return true;
            sum < target ? left++ : right--;
        }
        return false;
    }

private:
    void inorderTraversal(Node* root, vector<int>& inorder) {
        if (!root) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->data);
        inorderTraversal(root->right, inorder);
    }
};

3)
class Solution {
public:
    bool findTarget(Node* root, int target) {
        vector<int> inorder;
        function<void(Node*)> traverse = [&](Node* node) {
            if (!node) return;
            traverse(node->left);
            inorder.push_back(node->data);
            traverse(node->right);
        };
        traverse(root);
        int left = 0, right = inorder.size() - 1;
        while (left < right) {
            int sum = inorder[left] + inorder[right];
            if (sum == target) return true;
            sum < target ? left++ : right--;
        }
        return false;
    }
};

4)
class Solution {
public:
    bool findTarget(Node* root, int target) {
        unordered_set<int> seen;
        function<bool(Node*)> traverse = [&](Node* node) {
            if (!node) return false;
            if (seen.count(target - node->data)) return true;
            seen.insert(node->data);
            return traverse(node->left) || traverse(node->right);
        };
        return traverse(root);
    }
};

5)
class Solution {
public:
    bool findTarget(Node* root, int target) {
        unordered_set<int> seen;
        return dfs(root, target, seen);
    }
    
    bool dfs(Node* root, int target, unordered_set<int>& seen) {
        if (!root) return false;
        if (seen.count(target - root->data)) return true;
        seen.insert(root->data);
        return dfs(root->left, target, seen) || dfs(root->right, target, seen);
    }
};

6)
class BSTIterator {
    stack<Node*> st;
    bool reverse;
public:
    BSTIterator(Node* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        Node* node = st.top(); st.pop();
        if (!reverse) pushAll(node->right);
        else pushAll(node->left);
        return node->data;
    }
    
    bool hasNext() { return !st.empty(); }

private:
    void pushAll(Node* node) {
        while (node) {
            st.push(node);
            node = reverse ? node->right : node->left;
        }
    }
};

7)
class Solution {
public:
    bool findTarget(Node* root, int target) {
        BSTIterator l(root, false), r(root, true);
        int i = l.next(), j = r.next();
        while (i < j) {
            int sum = i + j;
            if (sum == target) return true;
            sum < target ? i = l.next() : j = r.next();
        }
        return false;
    }
};
//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        getline(cin, s);
        int k = stoi(s);
        // getline(cin, s);
        Solution obj;
        cout << obj.findTarget(root, k) << endl;
        // cout<<"~"<<endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
