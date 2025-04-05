# _9. Maximum Path Sum from Any Node_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1)

## Problem Description

Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

## Examples:

**Input:**  
`root[] = [10, 2, 10, 20, 1, N, -25, N, N, N, N, 3, 4]`  
**Output:**  
`42`  
**Explanation:**

<img src="https://github.com/user-attachments/assets/c3753c3d-a5a4-422d-8309-8d18099f5f6b" width="40%">

The maximum path sum is represented using the green colored nodes in the binary tree.

**Input:**  
`root[] = [-17, 11, 4, 20, -2, 10]`  
**Output:**  
`31`  
**Explanation:**

<img src="https://github.com/user-attachments/assets/eab45812-cd7f-4020-9e00-e39bb5481183" width="40%">

The maximum path sum is represented using the green colored nodes in the binary tree.

## Constraints:

- 1 ≤ number of nodes ≤ $10^3$
- -10^4 ≤ node->data ≤ $10^4$

## My Approach

1. **DFS Post-Order Traversal:**  
   Use a recursive DFS (post-order) approach to calculate, for each node:
   - **maxSingle:** The maximum path sum including the node and at most one of its subtrees.
   - **Global Maximum:** Update a global result with the sum of the node value and the maximum contributions from both left and right subtrees.
2. **Steps:**
   - Recursively compute the maximum path sum from the left and right children.
   - Discard negative sums by taking `max(0, value)`.
   - Update the global maximum with `left + right + node->data`.
   - Return `node->data + max(left, right)` to allow parent nodes to include the maximum available contribution.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as each node is visited exactly once.
- **Expected Auxiliary Space Complexity:** O(h), where `h` is the height of the tree (due to the recursion stack). In the worst-case (skewed tree), this can be O(n).

## Code (C++)

```cpp
class Solution {
    int dfs(Node* r, int& res) {
        if (!r) return 0;
        int l = max(0, dfs(r->left, res)), rgt = max(0, dfs(r->right, res));
        res = max(res, l + rgt + r->data);
        return max(l, rgt) + r->data;
    }
public:
    int findMaxSum(Node* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
};
```

<details>
  <summary><h2 align="center">🌲 Alternative Approaches</h2></summary>

## **2️⃣ Bottom-Up Dynamic Programming Approach**

### **Algorithm**

- Use post-order traversal to compute two values for each node:
  - **maxSingle**: Maximum path sum including the current node and at most one child.
  - **maxTop**: Maximum path sum where the current node is the highest node (root of the path).
- Recursively compute these values and return the global maximum.

```cpp
class Solution {
    pair<int, int> dfs(Node* r) {
        if (!r) return {0, INT_MIN};
        auto [lMax, lRes] = dfs(r->left);
        auto [rMax, rRes] = dfs(r->right);
        int maxSingle = max({r->data, r->data + lMax, r->data + rMax});
        int maxTop = max(maxSingle, r->data + lMax + rMax);
        return {maxSingle, max({maxTop, lRes, rRes})};
    }
public:
    int findMaxSum(Node* root) {
        return dfs(root).second;
    }
};
```

## **3️⃣ Iterative Post-Order Traversal Using Stack**

### **Algorithm**

- Perform an **iterative post-order traversal** using a stack.
- Maintain a map to store the maximum path sum for each node.
- For each node, compute:
  - **maxSingle**: Max sum including the node and one child.
  - **maxTop**: Max sum through the node with both children.

```cpp
class Solution {
public:
    int findMaxSum(Node* root) {
        if (!root) return 0;
        stack<Node*> s;
        unordered_map<Node*, int> mp;
        Node* last = nullptr;
        int res = INT_MIN;

        while (root || !s.empty()) {
            if (root) s.push(root), root = root->left;
            else {
                Node* node = s.top();
                if (node->right && last != node->right) root = node->right;
                else {
                    s.pop();
                    int l = max(0, mp[node->left]);
                    int r = max(0, mp[node->right]);
                    res = max(res, l + r + node->data);
                    mp[node] = max(l, r) + node->data;
                    last = node;
                }
            }
        }
        return res;
    }
};
```

## 🔍 **Comparison of Approaches**

| **Approach**                     | **Time Complexity** | **Space Complexity**  | **Pros**                          | **Cons**                      |
| -------------------------------- | ------------------- | --------------------- | --------------------------------- | ----------------------------- |
| **Recursive DFS (Optimized)**    | 🟢 O(N)             | 🟡 O(H) (stack space) | Clean, concise, easy to implement | Stack overflow for deep trees |
| **Bottom-Up DP**                 | 🟢 O(N)             | 🟡 O(H)               | Explicit DP states, easy to debug | Slightly verbose              |
| **Iterative Post-Order (Stack)** | 🟢 O(N)             | 🟡 O(H)               | Avoids recursion stack overflow   | More complex logic, verbose   |

### 🚀 **Best Choice?**

- ✅ **Balanced Trees:** Recursive DFS is simple and fast.
- ✅ **Very Deep Trees:** Iterative post-order avoids stack overflow.
- ✅ **For Debugging/DP:** Bottom-Up DP gives clear intermediate states.

</details>

## Code (Java)

```java
class Solution {
    int dfs(Node r, int[] res) {
        if (r == null) return 0;
        int l = Math.max(0, dfs(r.left, res)), rgt = Math.max(0, dfs(r.right, res));
        res[0] = Math.max(res[0], l + rgt + r.data);
        return Math.max(l, rgt) + r.data;
    }
    int findMaxSum(Node root) {
        int[] res = {Integer.MIN_VALUE};
        dfs(root, res);
        return res[0];
    }
}
```

## Code (Python)

```python
class Solution:
    def findMaxSum(self, root):
        def dfs(node):
            if not node: return 0
            l = max(0, dfs(node.left))
            r = max(0, dfs(node.right))
            nonlocal res
            res = max(res, l + r + node.data)
            return max(l, r) + node.data
        res = float('-inf')
        dfs(root)
        return res
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
