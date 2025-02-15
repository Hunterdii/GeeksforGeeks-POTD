//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

// Function to Build Tree


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
public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        while (root && (root->data > max(n1->data, n2->data) || root->data < min(n1->data, n2->data)))
            root = (root->data > n1->data) ? root->left : root->right;
        return root;
    }
};

2)
class Solution {
public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if (!root || root->data == n1->data || root->data == n2->data) return root;
        if (root->data > n1->data && root->data > n2->data) return LCA(root->left, n1, n2);
        if (root->data < n1->data && root->data < n2->data) return LCA(root->right, n1, n2);
        return root;
    }
};

3)
class Solution {
public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        stack<Node*> st;
        while (root) {
            if (root->data > n1->data && root->data > n2->data) root = root->left;
            else if (root->data < n1->data && root->data < n2->data) root = root->right;
            else return root;
        }
        return nullptr;
    }
};



//{ Driver Code Starts.

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

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        int l, h;
        getline(cin, s);
        scanf("%d ", &l);
        scanf("%d ", &h);
        Node* n1 = new Node(l);
        Node* n2 = new Node(h);
        Node* root = buildTree(s);
        Solution sol;
        int ans = sol.LCA(root, n1, n2)->data;
        cout << ans << endl;
        cout << "~"
             << "\n";
    }
    return 1;
}
// } Driver Code Ends
