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

### Approach 1 (Iterative Inorder Traversal):

1. **Traversal:**

   - Start traversing the BST from the root.
   - At each node, if the node's value is less than or equal to \( n \), update the maximum value found so far and move to the right subtree.
   - If the node's value is greater than \( n \), move to the left subtree.

2. **Return:**
   - After traversing the entire tree, return the maximum value found.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(height of the BST), as we perform traversal up to the height of the BST.
- **Expected Auxiliary Space Complexity:** O(1), as we use only constant extra space.

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

### Approach 2 (Recursive Inorder Traversal):

1. **Recursion:**

   - Perform an inorder traversal of the BST.
   - While traversing, keep track of the maximum value found so far less than or equal to \( n \).

2. **Return:**
   - After completing the traversal, return the maximum value found.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(height of the BST), as we perform traversal up to the height of the BST.
- **Expected Auxiliary Space Complexity:** O(height of the BST), as the recursive stack space will be proportional to the height of the BST.

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

### Approach 3 (Recursive Single Traversal):

1. **Recursion with Optimization:**

   - Recursively traverse the BST.
   - At each node, if the node's value is less than or equal to \( n \), move to the right subtree and update the maximum value found so far.
   - If the node's value is greater than \( n \), move to the left subtree.

2. **Return:**
   - After traversing the entire tree, return the maximum value found.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(height of the BST), as we perform traversal up to the height of the BST.
- **Expected Auxiliary Space Complexity:** O(height of the BST), as the recursive stack space will be proportional to the height of the BST.

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

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
