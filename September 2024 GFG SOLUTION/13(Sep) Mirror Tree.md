# **13. Mirror Tree**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/mirror-tree/1)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

Given a Binary Tree, convert it into its mirror image. The mirror image of a tree is a new tree where the left and right children of all nodes are swapped.

**Example:**

Input:

```
      1
    /  \
   2    3
```

Output: `3 1 2`

Explanation: The tree is

```
  1    (mirror)     1
 /  \    =>        /  \
2    3           3   2
```

The inorder traversal of the mirrored tree is `3 1 2`.

Input:

```
      10
     /  \
    20   30
   /  \
  40  60
```

Output: `30 10 60 20 40`

Explanation: The tree is

```
      10               10
    /    \  (mirror)    /    \
   20    30    =>   30    20
  /  \                     /   \
 40  60                 60   40
```

The inorder traversal of the mirrored tree is `30 10 60 20 40`.

### My Approach

1. **Recursive Approach:**

   - Traverse the tree using a recursive function.
   - For each node, swap its left and right children.
   - Recursively apply the same process to the left and right subtrees.

2. **Implementation Details:**
   - If the current node is `NULL`, return.
   - Swap the left and right children of the node.
   - Recursively call the mirror function on the left and right children.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the number of nodes in the tree. Each node is visited once.
- **Expected Auxiliary Space Complexity:** O(height of the tree), due to the recursion stack. In the worst case, this is equal to O(n) if the tree is completely unbalanced (like a linked list).

### Code (C++)

```cpp
void mirror(struct Node* node) {
    if (node == NULL) return;
    struct Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
    mirror(node->left);
    mirror(node->right);
}
```

### Code (Java)

```java
class Solution {
    void mirror(Node node) {
        if (node == null) return;
        Node temp = node.left;
        node.left = node.right;
        node.right = temp;
        mirror(node.left);
        mirror(node.right);
    }
}
```

### Code (Python)

```python
class Solution:
    def mirror(self, root):
        if root is None:
            return
        root.left, root.right = root.right, root.left
        self.mirror(root.left)
        self.mirror(root.right)
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
