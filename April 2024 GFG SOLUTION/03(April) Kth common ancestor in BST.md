## 03. Kth Common Ancestor in BST

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/kth-common-ancestor-in-bst/1)

### Problem Description

Given a Binary Search Tree (BST) with \( n \) (\( n \geq 2 \)) nodes, find the \( k \)th common ancestor of nodes \( x \) and \( y \) in the given tree. Return -1 if the \( k \)th ancestor does not exist.

Nodes \( x \) and \( y \) will always be present in the input BST, and \( x \neq y \).

**Example:**

Input:

<p align="center">
<img src="https://github.com/Hunterdii/GeeksforGeeks-POTD/assets/124852522/a710495f-4a16-4e6a-bbbe-5a1d57112631" alt="Image" width="450" />
</p>
<br/>
k = 2, x = 70, y = 60  
<br/>

<!--
```
Input tree:

      80
     /  \
    40   90
   /  \
  20   70
     /  \
    60  75

k = 2, x = 70, y = 60
```!-->

Output:

```
-1
```

Explanation:
LCA of 70 and 60 is 40, which is root itself. There does not exist a 2nd common ancestor in this case.

### My Approach

1. **Find Lowest Common Ancestor (LCA):**

   - Implement a function to find the Lowest Common Ancestor (LCA) of nodes \( x \) and \( y \) in the BST.
   - Start from the root and traverse down the tree:
     - If both \( x \) and \( y \) are less than the current node's value, move to the left subtree.
     - If both \( x \) and \( y \) are greater than the current node's value, move to the right subtree.
     - If one value is less than the current node's value and the other is greater, then the current node is the LCA.

2. **Find Path to LCA:**

   - After finding the LCA, trace the path from the root to the LCA node and store the values in a vector.

3. **Kth Common Ancestor:**
   - Reverse the path vector.
   - If the size of the path vector is less than \( k \), return -1.
   - Otherwise, return the \( k \)th element from the reversed path.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \( O(\text{Height of the BST}) \), as we traverse down the tree to find the LCA.
- **Expected Auxiliary Space Complexity:** \( O(\text{Height of the BST}) \), for storing the path from the root to the LCA.

### Code (C++)

```cpp
class Solution
{
    public:

    Node* findLowestCommonAncestor(Node* root, int x, int y) {
        if (root == NULL) return NULL;
        if (x < root->data && y < root->data) return findLowestCommonAncestor(root->left, x, y);
        if (x > root->data && y > root->data) return findLowestCommonAncestor(root->right, x, y);
        return root;
    }

    void findPathToNode(Node* root, Node* node, vector<int>& path) {
        path.push_back(root->data);
        if (root->data == node->data) return;
        else if (node->data > root->data) findPathToNode(root->right, node, path);
        else findPathToNode(root->left, node, path);
    }

    int kthCommonAncestor(Node* root, int k, int x, int y) {
        Node* lca = findLowestCommonAncestor(root, x, y);
        vector<int> path;
        findPathToNode(root, lca, path);
        reverse(path.begin(), path.end());
        if (path.size() < k) return -1;
        return path[k - 1];
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
