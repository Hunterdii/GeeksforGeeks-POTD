## 22. Largest BST

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/largest-bst/1)

### Problem Description

Given a binary tree, find the size of its largest subtree that is a Binary Search Tree (BST). Note: Here, size equals the number of nodes in the subtree.

**Examples:**

Input:

```
    1
   / \
  4   4
 / \
6   8
```

Output:

```
1
```

Explanation:
There's no subtree with size greater than 1 that forms a BST. All the leaf nodes are BSTs with size equal to 1.

### My Approach

1. **Helper Function:**

- Define a helper function `largestBSTHelper` that returns information about whether the subtree is a BST, its size, and the minimum and maximum values in the subtree.

2. **Base Case:**

- If the current node is `None`, return `Info(True, 0, float('inf'), float('-inf'))`.

3. **Recursive Calculation:**

- Recursively calculate the information for the left and right subtrees.
- If both subtrees are BSTs and the current node's value is greater than the maximum value in the left subtree and less than the minimum value in the right subtree, the current subtree is a BST.

4. **Update Information:**

- If the current subtree is a BST, update its size and the minimum and maximum values.
- Otherwise, the size is the maximum size of the left or right subtree.

5. **Return the Result:**

- The `largestBst` function returns the size of the largest BST in the tree by calling `largestBSTHelper`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as each node is visited once.
- **Expected Auxiliary Space Complexity:** O(h), where `h` is the height of the tree, due to the recursion stack.

### Code (C++)

```cpp
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
```

### Code (Java)

```java
class Info {
    boolean isBST;
    int size;
    int minVal;
    int maxVal;

    Info(boolean isBST, int size, int minVal, int maxVal) {
        this.isBST = isBST;
        this.size = size;
        this.minVal = minVal;
        this.maxVal = maxVal;
    }
}

class Solution {
    private Info largestBSTHelper(Node root) {
        if (root == null) {
            return new Info(true, 0, Integer.MAX_VALUE, Integer.MIN_VALUE);
        }

        Info leftInfo = largestBSTHelper(root.left);
        Info rightInfo = largestBSTHelper(root.right);

        if (leftInfo.isBST && rightInfo.isBST && root.data > leftInfo.maxVal && root.data < rightInfo.minVal) {
            return new Info(true, 1 + leftInfo.size + rightInfo.size, Math.min(root.data, leftInfo.minVal), Math.max(root.data, rightInfo.maxVal));
        } else {
            return new Info(false, Math.max(leftInfo.size, rightInfo.size), Integer.MAX_VALUE, Integer.MIN_VALUE);
        }
    }

    public int largestBst(Node root) {
        return largestBSTHelper(root).size;
    }
}
```

### Code (Python)

```python
class Info:
    def __init__(self, is_bst, size, min_val, max_val):
        self.is_bst = is_bst
        self.size = size
        self.min_val = min_val
        self.max_val = max_val

class Solution:
    def largestBSTHelper(self, root):
        if root is None:
            return Info(True, 0, float('inf'), float('-inf'))

        left_info = self.largestBSTHelper(root.left)
        right_info = self.largestBSTHelper(root.right)

        if left_info.is_bst and right_info.is_bst and root.data > left_info.max_val and root.data < right_info.min_val:
            return Info(True, 1 + left_info.size + right_info.size, min(root.data, left_info.min_val), max(root.data, right_info.max_val))
        else:
            return Info(False, max(left_info.size, right_info.size), float('inf'), float('-inf'))

    def largestBst(self, root):
        return self.largestBSTHelper(root).size
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
