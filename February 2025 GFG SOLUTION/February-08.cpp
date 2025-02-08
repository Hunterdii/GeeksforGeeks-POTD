//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
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


// } Driver Code Ends
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    void lb(Node* r, vector<int>& v) {
        if (!r || (!r->left && !r->right)) return;
        v.push_back(r->data);
        lb(r->left ? r->left : r->right, v);
    }
    void rb(Node* r, vector<int>& v) {
        if (!r || (!r->left && !r->right)) return;
        rb(r->right ? r->right : r->left, v);
        v.push_back(r->data);
    }
    void leaf(Node* r, vector<int>& v) {
        if (!r) return;
        leaf(r->left, v);
        if (!r->left && !r->right) v.push_back(r->data);
        leaf(r->right, v);
    }
public:
    vector<int> boundaryTraversal(Node* r) {
        if (!r) return {};
        vector<int> v = {r->data};
        lb(r->left, v);
        leaf(r->left, v);
        leaf(r->right, v);
        rb(r->right, v);
        return v;
    }
};

2)
class Solution {
public:
    vector<int> boundaryTraversal(Node* root) {
        if (!root) return {};
        vector<int> res;
        if (root->left || root->right) res.push_back(root->data);

        stack<Node*> s;
        Node* cur = root->left;
        while (cur) {
            if (cur->left || cur->right) res.push_back(cur->data);
            s.push(cur);
            cur = cur->left ? cur->left : cur->right;
        }

        function<void(Node*)> leafNodes = [&](Node* node) {
            if (!node) return;
            leafNodes(node->left);
            if (!node->left && !node->right) res.push_back(node->data);
            leafNodes(node->right);
        };
        leafNodes(root);

        stack<int> rightBoundary;
        cur = root->right;
        while (cur) {
            if (cur->left || cur->right) rightBoundary.push(cur->data);
            cur = cur->right ? cur->right : cur->left;
        }

        while (!rightBoundary.empty()) {
            res.push_back(rightBoundary.top());
            rightBoundary.pop();
        }

        return res;
    }
};

3)
class Solution {
public:
    vector<int> boundaryTraversal(Node* root) {
        if (!root) return {};
        vector<int> res;
        if (root->left || root->right) res.push_back(root->data);
        
        Node* cur = root->left;
        while (cur) {
            if (cur->left || cur->right) res.push_back(cur->data);
            cur = cur->left ? cur->left : cur->right;
        }

        function<void(Node*)> leafNodes = [&](Node* node) {
            if (!node) return;
            leafNodes(node->left);
            if (!node->left && !node->right) res.push_back(node->data);
            leafNodes(node->right);
        };
        leafNodes(root);

        stack<int> rightBoundary;
        cur = root->right;
        while (cur) {
            if (cur->left || cur->right) rightBoundary.push(cur->data);
            cur = cur->right ? cur->right : cur->left;
        }

        while (!rightBoundary.empty()) {
            res.push_back(rightBoundary.top());
            rightBoundary.pop();
        }

        return res;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s, ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector<int> res = ob.boundaryTraversal(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
