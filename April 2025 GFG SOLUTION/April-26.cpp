//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
  public:
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

// User Function template for C++

// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
    int c(Node* r) { return r ? 1 + c(r->left) + c(r->right) : 0; }
    bool p(Node* r, int i, int n) {
        return !r
            || (i < n
                && (!r->left  || r->data >= r->left->data)
                && (!r->right || r->data >= r->right->data)
                && p(r->left,  2*i+1, n)
                && p(r->right, 2*i+2, n)
              );
    }
  public:
    bool isHeap(Node* tree) {
        return p(tree, 0, c(tree));
    }
};



2)
class Solution {
  public:
    bool isHeap(Node* root) {
        if (!root) return true;
        queue<Node*> q;
        q.push(root);
        bool leafOnly = false;
        while (!q.empty()) {
            Node* u = q.front(); q.pop();
            if (u->left) {
                if (leafOnly || u->data < u->left->data) return false;
                q.push(u->left);
            } else leafOnly = true;
            if (u->right) {
                if (leafOnly || u->data < u->right->data) return false;
                q.push(u->right);
            } else leafOnly = true;
        }
        return true;
    }
};


3)
class Solution {
  public:
    bool isHeap(Node* root) {
        if (!root) return true;

        queue<Node*> q;
        q.push(root);
        bool nullSeen = false;

        while (!q.empty()) {
            Node* current = q.front(); q.pop();

            if (current->left) {
                if (nullSeen || current->data < current->left->data) return false;
                q.push(current->left);
            } else {
                nullSeen = true;
            }

            if (current->right) {
                if (nullSeen || current->data < current->right->data) return false;
                q.push(current->right);
            } else {
                nullSeen = true;
            }
        }

        return true;
    }
};


4)
class Solution {
  public:
    int count(Node* root) {
        return root ? 1 + count(root->left) + count(root->right) : 0;
    }

    bool isCompleteAndHeap(Node* root, int index, int total) {
        if (!root) return true;
        if (index >= total) return false;

        if ((root->left && root->data < root->left->data) ||
            (root->right && root->data < root->right->data)) return false;

        return isCompleteAndHeap(root->left, 2*index + 1, total) &&
              isCompleteAndHeap(root->right, 2*index + 2, total);
    }

    bool isHeap(Node* root) {
        int totalNodes = count(root);
        return isCompleteAndHeap(root, 0, totalNodes);
    }
};


5)
class Solution {
  public:
    int count(Node* r) {
        return r ? 1 + count(r->left) + count(r->right) : 0;
    }
    
    bool check(Node* r, int i, int n) {
        return !r || (i < n &&
            (!r->left || r->data >= r->left->data) &&
            (!r->right || r->data >= r->right->data) &&
            check(r->left, 2*i + 1, n) &&
            check(r->right, 2*i + 2, n)
        );
    }
    
    bool isHeap(struct Node* root) {
        return check(root, 0, count(root));
    }
};
//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
