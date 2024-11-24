//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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
/* Tree node structure  used in the program*/
struct Info {
    bool isBST;
    int size;
    int minVal;
    int maxVal;
};

Info largestBSTHelper(Node* root) {
    if (root == nullptr) {
        return {true, 0, INT_MAX, INT_MIN};
    }

    Info leftInfo = largestBSTHelper(root->left);
    Info rightInfo = largestBSTHelper(root->right);

    Info currentInfo;
    if (leftInfo.isBST && rightInfo.isBST && root->data > leftInfo.maxVal && root->data < rightInfo.minVal) {
        currentInfo.isBST = true;
        currentInfo.size = 1 + leftInfo.size + rightInfo.size;
        currentInfo.minVal = std::min(root->data, leftInfo.minVal);
        currentInfo.maxVal = std::max(root->data, rightInfo.maxVal);
    } else {
        currentInfo.isBST = false;
        currentInfo.size = std::max(leftInfo.size, rightInfo.size);
        currentInfo.minVal = INT_MAX;
        currentInfo.maxVal = INT_MIN;
    }

    return currentInfo;
}

class Solution {
public:
    int largestBst(Node* root) {
        return largestBSTHelper(root).size;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends
