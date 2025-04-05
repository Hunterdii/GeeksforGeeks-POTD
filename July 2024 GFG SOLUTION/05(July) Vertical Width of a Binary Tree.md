## 05. Vertical Width of a Binary Tree

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/vertical-width-of-a-binary-tree/1)

### Problem Description

Given a Binary Tree, find and return the vertical width of the tree.

**Examples:**

**Input:**

```
         1
       /   \
      2     3
     / \   / \
    4   5 6   7
           \   \
            8   9
```

**Output:**

```
6
```

**Explanation:**
The width of a binary tree is the number of vertical paths in that tree. The above tree contains 6 vertical lines.

<p align="center">
  <img src="https://github.com/Hunterdii/GeeksforGeeks-POTD/assets/124852522/d6a8468f-8bef-4d5f-8ffb-88daf8a36c1d" alt="Image" width="370" />
</p>

### Approach

1. **Initialization:**

   - Define a helper function `solve` that traverses the tree and updates the maximum and minimum horizontal distances from the root.
   - Use `maxi` and `mini` to track the maximum and minimum horizontal distances respectively.
   - Initialize `maxi` and `mini` to 0.

2. **Tree Traversal:**

   - Perform a pre-order traversal (DFS) of the tree.
   - For each node, update `maxi` and `mini` based on the current horizontal distance `x`.
   - For the left child, the horizontal distance is `x - 1`.
   - For the right child, the horizontal distance is `x + 1`.

3. **Return:**
   - The vertical width of the tree is `maxi - mini + 1`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we traverse all the nodes of the tree once.
- **Expected Auxiliary Space Complexity:** O(height of the tree), due to the recursion stack space used during the DFS traversal.

### Code (C++)

```cpp
class Solution {
public:
    void solve(Node* root, int x, int &maxi, int &mini) {
        if (!root) return;
        maxi = max(maxi, x);
        mini = min(mini, x);
        solve(root->left, x - 1, maxi, mini);
        solve(root->right, x + 1, maxi, mini);
    }

    int verticalWidth(Node* root) {
        if (!root) return 0;
        int maxi = 0, mini = 0;
        solve(root, 0, maxi, mini);
        return maxi - mini + 1;
    }
};
```

### Code (Java)

```java
class Solution {
    private void solve(Node root, int x, int[] bounds) {
        if (root == null) {
            return;
        }
        bounds[0] = Math.max(bounds[0], x);
        bounds[1] = Math.min(bounds[1], x);
        solve(root.left, x - 1, bounds);
        solve(root.right, x + 1, bounds);
    }

    public int verticalWidth(Node root) {
        if (root == null) {
            return 0;
        }
        int[] bounds = {0, 0};
        solve(root, 0, bounds);
        return bounds[0] - bounds[1] + 1;
    }
}
```

### Code (Python)

```python
def solve(root, x, bounds):
    if not root:
        return
    bounds[0] = max(bounds[0], x)
    bounds[1] = min(bounds[1], x)
    solve(root.left, x - 1, bounds)
    solve(root.right, x + 1, bounds)

def verticalWidth(root):
    if not root:
        return 0
    bounds = [0, 0]
    solve(root, 0, bounds)
    return bounds[0] - bounds[1] + 1
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
