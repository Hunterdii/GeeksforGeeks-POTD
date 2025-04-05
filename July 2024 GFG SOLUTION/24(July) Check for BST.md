## 24. Check for BST

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/check-for-bst/1)

### Problem Description

Given the root of a binary tree, check whether it is a Binary Search Tree (BST) or not. Note that BSTs cannot contain duplicate nodes. A BST is defined as follows:

- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree of a node contains only nodes with keys greater than the node's key.
- Both the left and right subtrees must also be binary search trees.

**Examples:**

Input:

```
   2
 /   \
1     3
      \
       5
```

Output:

```
true
```

Explanation:
The left subtree of every node contains smaller keys and the right subtree of every node contains greater keys. Hence, the tree is a BST.

### My Approach

1. **Base Case:**

   - If the node is `nullptr`, return `true`.

2. **Boundary Check:**

   - If the node's value is less than or equal to the minimum allowed value or greater than or equal to the maximum allowed value, return `false`.

3. **Recursive Check:**

   - Recursively check the left subtree ensuring all nodes are less than the current node's value.
   - Recursively check the right subtree ensuring all nodes are greater than the current node's value.

4. **Return Result:**
   - Return the combined result of the left and right subtree checks.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we visit each node exactly once where `n` is the number of nodes in the tree.
- **Expected Auxiliary Space Complexity:** O(Height of the tree), as the recursion stack will hold at most one branch of the tree at a time.

### Code (C++)

```cpp
class Solution {
public:
    bool isBST(Node* node) {
        return isBSTUtil(node, nullptr, nullptr);
    }

private:
    bool isBSTUtil(Node* node, Node* minNode, Node* maxNode) {
        if (node == nullptr) {
            return true;
        }

        if ((minNode && node->data <= minNode->data) || (maxNode && node->data >= maxNode->data)) {
            return false;
        }

        return isBSTUtil(node->left, minNode, node) && isBSTUtil(node->right, node, maxNode);
    }
};
```

### Code (Java)

```java
class Solution {
    public boolean isBST(Node node) {
        return isBSTUtil(node, null, null);
    }

    private boolean isBSTUtil(Node node, Node minNode, Node maxNode) {
        if (node == null) {
            return true;
        }

        if ((minNode != null && node.data <= minNode.data) || (maxNode != null && node.data >= maxNode.data)) {
            return false;
        }

        return isBSTUtil(node.left, minNode, node) && isBSTUtil(node.right, node, maxNode);
    }
}
```

### Code (Python)

```python
class Solution:
    def isBST(self, node):
        return self.isBSTUtil(node, None, None)

    def isBSTUtil(self, node, minNode, maxNode):
        if not node:
            return True

        if (minNode and node.data <= minNode.data) or (maxNode and node.data >= maxNode.data):
            return False

        return self.isBSTUtil(node.left, minNode, node) and self.isBSTUtil(node.right, node, maxNode)
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
