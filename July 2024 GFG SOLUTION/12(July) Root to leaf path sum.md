## 12. Root to Leaf Path Sum

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/root-to-leaf-path-sum/1)

### Problem Description

Given a binary tree and an integer `target`, check whether there is a root-to-leaf path with its sum equal to the target.

**Examples:**

Input:

```
tree = [1, 2, 3]
target = 2
```

Output:

```
false
```

Explanation:
There is no root to leaf path with sum 2.

### My Approach

1. **Base Case:**

   - If the `node` is `None`, return `false`.

2. **Target Adjustment:**

   - Subtract the value of the current `node` from the `target`.

3. **Leaf Node Check:**

   - If the current `node` is a leaf (i.e., it has no left or right child), check if the adjusted `target` is zero.

4. **Recursive Call:**
   - Recursively check the left and right subtrees to see if any path matches the target sum.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we need to visit each node once in the worst case.
- **Expected Auxiliary Space Complexity:** O(h), where `h` is the height of the tree. This is due to the recursive call stack.

### Code (C++)

```cpp
class Solution {
public:
    bool hasPathSum(Node *node, int target) {
        if (!node) return false;
        target -= node->data;
        if (!node->left && !node->right) return target == 0;
        return hasPathSum(node->left, target) || hasPathSum(node->right, target);
    }
};
```

### Code (Java)

```java
class Solution {
    boolean hasPathSum(Node root, int target) {
        if (root == null) return false;
        target -= root.data;
        if (root.left == null && root.right == null) return target == 0;
        return hasPathSum(root.left, target) || hasPathSum(root.right, target);
    }
}
```

### Code (Python)

```python
class Solution:
    def hasPathSum(self, root, target):
        if root is None:
            return False
        target -= root.data
        if root.left is None and root.right is None:
            return target == 0
        return self.hasPathSum(root.left, target) or self.hasPathSum(root.right, target)
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
