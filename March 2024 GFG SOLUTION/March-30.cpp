//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
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
// User function Template for C++

// Function to find the minimum element in the given BST.


// struct Node {
//     int data;
//     struct Node* left;
//     struct Node* right;
// };
// // Utility function to create a new Tree Node
// Node* newNode(int val) {
//     Node* temp = new Node;
//     temp->data = val;
//     temp->left = NULL;
//     temp->right = NULL;

//     return temp;
// }
## Below I Have Solved The Same Program Different Ways
1)
class Solution {
public:
    int minValue(Node* root) {
        if (root == nullptr)
            return INT_MAX;
        
        int leftMin = minValue(root->left);
        int rightMin = minValue(root->right);
        
        return std::min(root->data, std::min(leftMin, rightMin));
    }
};
2)
class Solution {
public:  
int min=INT_MAX;
    int minValue(Node* root) {
      if(root==NULL)
        return INT_MAX;
        
        if(root->data < min){
            min=root->data;
        }
         minValue(root->left);
          minValue(root->left);
        return min;
    }
};

3)
class Solution {
public:
    int minValue(Node* root) {
        if (root == nullptr)
            return INT_MAX;
        
        int leftMin = minValue(root->left);
        int rightMin = minValue(root->right);
        
        int minVal = std::min(root->data, std::min(leftMin, rightMin));
        
        // only traverse the subtree with smaller minimum value.
        if (leftMin < minVal)
            return leftMin;
        else if (rightMin < minVal)
            return rightMin;
        else
            return minVal;
    }
};



//{ Driver Code Starts.


int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.minValue(root) << endl;
    }
    return 1;
}
// } Driver Code Ends
