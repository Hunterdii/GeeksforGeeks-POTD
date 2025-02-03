//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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
    // string after splitting by space
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


// } Driver Code Ends
// User function template for C++

/*
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
*/
class Solution {
public:
    int height(Node* node) {
        return node ? 1 + max(height(node->left), height(node->right)) : -1;
    }
};

2)
class Solution {
public:
    int height(Node* root) {
        if (!root) return -1;
        queue<Node*> q({root});
        int h = -1;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                Node* n = q.front(); q.pop();
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            h++;
        }
        return h;
    }
};

3)
class Solution {
public:
    int height(Node* node) {
        if (!node) return -1;
        int l = height(node->left), r = height(node->right);
        return 1 + max(l, r);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string treeString;
        getline(cin, treeString);
        Node* root = buildTree(treeString);
        Solution ob;
        cout << ob.height(root) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
