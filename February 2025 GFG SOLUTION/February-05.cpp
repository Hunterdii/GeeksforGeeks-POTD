//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
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

// Generate output as level order of tree
string levelOrder(Node *root) {
    if (root == nullptr)
        return "N\n";

    string str;
    queue<Node *> qq;
    qq.push(root);

    while (!qq.empty()) {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr) {
            str += "N ";
            continue;
        }
        str += (to_string(curr->data) + " ");
        qq.push(curr->left);
        qq.push(curr->right);
    }
    while (!str.empty() && !isdigit(str.back())) {
        str.pop_back();
    }
    return str;
}


// } Driver Code Ends
// Full function Template for C++
/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    void mirror(Node* node) {
        if (!node) return;
        mirror(node->left);
        mirror(node->right);
        swap(node->left, node->right);
    }
};

2)
class Solution {
public:
    void mirror(Node* root) {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            swap(cur->left, cur->right);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
};

3)
class Solution {
public:
    void mirror(Node* root) {
        if (!root) return;
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            Node* cur = s.top(); s.pop();
            swap(cur->left, cur->right);
            if (cur->left) s.push(cur->left);
            if (cur->right) s.push(cur->right);
        }
    }
};
//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str;
        getline(cin, str);
        Node *root = buildTree(str);
        Solution ob;
        ob.mirror(root);
        cout << levelOrder(root);
        cout << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
