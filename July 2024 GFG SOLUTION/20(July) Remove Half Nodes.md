## 20. Remove Half Nodes

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/remove-half-nodes/1)

### Problem Description

You are given a binary tree, and you need to remove all the half nodes (nodes with only one child). Return the root node of the modified tree after removing all the half nodes.

**Example:**

Input:

```
tree = 5
       / \
      7   8
     /
    2
```

Output:

```
2 5 8
```

Explanation: In the above tree, the node 7 has only a single child. After removing the node, the tree becomes 2<-5->8. Hence, the answer is 2 5 8 in inorder traversal.

### My Approach

1. **Base Case:**

   - If the current node is `nullptr`, return `nullptr`.

2. **Recursive Case:**

   - Recursively call `RemoveHalfNodes` on the left and right children.
   - Update the left and right children of the current node with the results from the recursive calls.

3. **Removal of Half Nodes:**
   - If the current node is a half node (only one child is `nullptr`), return the non-null child after deleting the current node.
   - If the current node has both children or no children, return the current node itself.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we traverse each node once in the binary tree.
- **Expected Auxiliary Space Complexity:** O(h), where h is the height of the binary tree, due to the recursive call stack.

### Code (C++)

```cpp
class Solution {
public:
    Node* RemoveHalfNodes(Node* root) {
        if (root == nullptr)
            return nullptr;

        root->left = RemoveHalfNodes(root->left);
        root->right = RemoveHalfNodes(root->right);

        if (root->left == nullptr && root->right == nullptr)
            return root;

        if (root->left == nullptr) {
            Node* new_root = root->right;
            delete root;
            return new_root;
        }
        if (root->right == nullptr) {
            Node* new_root = root->left;
            delete root;
            return new_root;
        }

        return root;
    }
};
```

### Code (Java)

```java
class Solution {
    public Node RemoveHalfNodes(Node root) {
        if (root == null) {
            return null;
        }

        root.left = RemoveHalfNodes(root.left);
        root.right = RemoveHalfNodes(root.right);

        if (root.left == null && root.right == null) {
            return root;
        }

        if (root.left == null) {
            Node newRoot = root.right;
            return newRoot;
        }

        if (root.right == null) {
            Node newRoot = root.left;
            return newRoot;
        }

        return root;
    }
}
```

### Code (Python)

```python
class Solution:
    def RemoveHalfNodes(self, node):
        if node is None:
            return None

        node.left = self.RemoveHalfNodes(node.left)
        node.right = self.RemoveHalfNodes(node.right)

        if node.left is None and node.right is None:
            return node

        if node.left is None:
            new_node = node.right
            node = None
            return new_node

        if node.right is None:
            new_node = node.left
            node = None
            return new_node

        return node
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
