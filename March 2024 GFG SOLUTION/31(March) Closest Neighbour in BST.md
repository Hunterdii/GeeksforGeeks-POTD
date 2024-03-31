## 31. Closest Neighbor in BST

### Problem Description

Given the root of a binary search tree and a number \( N \), find the greatest number in the binary search tree that is less than or equal to \( N \).

**Example:**

Input:
```
N = 24
```
Output:
```
21
```
Explanation: 
The greatest element in the tree which is less than or equal to 24 is 21. Searching will be like 5 -> 12 -> 21.

#### Approach 1:

1. **Traversal:**
   - Start traversing the BST from the root.
   - At each node, if the node's value is less than or equal to \( n \), update the maximum value found so far and move to the right subtree.
   - If the node's value is greater than \( n \), move to the left subtree.

2. **Return:**
   - After traversing the entire tree, return the maximum value found.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \( O(\text{Height of the BST}) \), as we traverse the BST till we find the greatest number less than or equal to \( N \).
- **Expected Auxiliary Space Complexity:** \( O(1) \), as we use only a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    int findMaxForN(Node* root, int N) {
        int maxVal = -1;
        while (root) {
            if (root->key <= N) {
                maxVal = max(maxVal, root->key);
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return maxVal;
    }
};
```

#### Approach 2:

1. **Recursion:**
   - Perform an inorder traversal of the BST.
   - While traversing, keep track of the maximum value found so far less than or equal to \( n \).

2. **Return:**
   - After completing the traversal, return the maximum value found.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \( O(\text{Height of the BST}) \), as we traverse the BST till we find the greatest number less than or equal to \( N \).
- **Expected Auxiliary Space Complexity:** \( O(\text{Height of the BST}) \), due to the recursive function call stack.

### Code (C++)

```cpp
class Solution {
public:
    void fun(Node *root, int N, int &ans) {
        if (root == NULL) return;
        fun(root->right, N, ans);
        if (root->key <= N && ans == -1) {
            ans = root->key;
        }
        fun(root->left, N, ans);
    }

    int findMaxForN(Node* root, int N) {
        int ans = -1;
        fun(root, N, ans);
        return ans;
    }
};
```

#### Approach 3:

1. **Recursion with Optimization:**
   - Recursively traverse the BST.
   - At each node, if the node's value is less than or equal to \( n \), move to the right subtree and update the maximum value found so far.
   - If the node's value is greater than \( n \), move to the left subtree.

2. **Return:**
   - After traversing the entire tree, return the maximum value found.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \( O(\text{Height of the BST}) \), as we traverse the BST till we find the greatest number less than or equal to \( N \).
- **Expected Auxiliary Space Complexity:** \( O(\text{Height of the BST}) \), due to the recursive function call stack.

### Code (C++)

```cpp
class Solution {
public:
    int findMaxForN(Node* root, int N) {
        if (!root) return -1;
        if (root->key <= N) {
            int rightMax = findMaxForN(root->right, N);
            if (rightMax != -1) return max(root->key, rightMax);
            else return root->key;
        } else {
            return findMaxForN(root->left, N);
        }
    }
};
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/het-patel-8b110525a/).
Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
