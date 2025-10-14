---
title: "🌳 Sum of Nodes in BST Range | GFG Solution 🔍"
keywords🏷️: ["🌳 binary search tree", "🔍 range sum", "🎯 BST traversal", "📊 tree algorithms", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Sum of Nodes in BST Range problem: efficiently calculate sum of all nodes within a given range using BST properties. 🚀"
date: 📅 2025-10-14
---

# *14. Sum of Nodes in BST Range*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/range-sum-of-bst/1)

## **🧩 Problem Description**

You are given the root of a **Binary Search Tree** and two integers `l` and `r`. Your task is to find the **sum of all nodes** that lie between `l` and `r`, including both `l` and `r`.

A Binary Search Tree (BST) is a binary tree where for each node, all values in the left subtree are less than the node's value, and all values in the right subtree are greater than the node's value. This property allows efficient searching and range queries.

## **📘 Examples**

### Example 1

```cpp
Input: root = [22, 12, 30, 8, 20], l = 10, r = 22
Output: 54
Explanation: The nodes in the given Tree that lies in the range [10, 22] are {12, 20, 22}. 
Therefore, the sum of nodes is 12 + 20 + 22 = 54.
```

### Example 2

```cpp
Input: root = [8, 5, 11, 3, 6, N, 20], l = 11, r = 15
Output: 11
Explanation: The nodes in the given Tree that lies in the range [11, 15] is {11}. 
Therefore, the sum of node is 11.
```

## **🔒 Constraints**

* $0 \le \text{number of nodes} \le 10^4$
* $0 \le \text{node->data} \le 10^4$
* $0 \le l \le r \le 10^4$

## **✅ My Approach**

The optimal approach leverages the **Binary Search Tree property** to efficiently prune unnecessary branches during traversal:

### **Optimized DFS with BST Property**

1. **Base Case:**
   * If the current node is null, return 0 (no contribution to sum).

2. **Prune Left Subtree:**
   * If the current node's value is less than `l`, all nodes in the left subtree will also be less than `l`.
   * Therefore, skip the left subtree and recursively search only the right subtree.

3. **Prune Right Subtree:**
   * If the current node's value is greater than `r`, all nodes in the right subtree will also be greater than `r`.
   * Therefore, skip the right subtree and recursively search only the left subtree.

4. **Node Within Range:**
   * If the current node's value lies within `[l, r]`, include it in the sum.
   * Recursively calculate sum from both left and right subtrees.
   * Return the total: `current node value + left subtree sum + right subtree sum`.

5. **Efficiency:**
   * By leveraging BST properties, we avoid visiting nodes that are guaranteed to be outside the range.
   * This significantly reduces the number of nodes visited compared to a simple tree traversal.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of nodes in the BST. In the worst case (skewed tree or all nodes in range), we visit all nodes. However, on average, the BST property allows us to prune branches and visit only O(h + k) nodes, where h is the height and k is the number of nodes in range.
* **Expected Auxiliary Space Complexity:** O(h), where h is the height of the tree, due to the recursion call stack. In the worst case of a skewed tree, h = n, but for a balanced BST, h = log(n).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int nodeSum(Node* root, int l, int r) {
        if (!root) return 0;
        if (root->data < l) return nodeSum(root->right, l, r);
        if (root->data > r) return nodeSum(root->left, l, r);
        return root->data + nodeSum(root->left, l, r) + nodeSum(root->right, l, r);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Iterative Approach with Stack**

### 💡 Algorithm Steps:

1. Use a stack to simulate the recursive call stack iteratively.
2. Push root node and traverse using stack-based depth-first search.
3. Check each node's value against the range and add to sum if valid.
4. Push left and right children to stack based on range conditions.

```cpp
class Solution {
public:
    int nodeSum(Node* root, int l, int r) {
        if (!root) return 0;
        stack<Node*> st;
        st.push(root);
        int sum = 0;
        while (!st.empty()) {
            Node* cur = st.top();
            st.pop();
            if (cur->data >= l && cur->data <= r) sum += cur->data;
            if (cur->right && cur->data < r) st.push(cur->right);
            if (cur->left && cur->data > l) st.push(cur->left);
        }
        return sum;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Visit each relevant node once
* **Auxiliary Space:** 💾 O(h) - Stack space proportional to tree height

### ✅ **Why This Approach?**

* Avoids recursion overhead and stack overflow risk
* Explicit control over traversal order
* Better for very deep trees

## 📊 **3️⃣ Morris Traversal (Space-Optimized)**

### 💡 Algorithm Steps:

1. Use Morris inorder traversal to traverse tree without recursion or stack.
2. Create temporary links to navigate back to parent nodes.
3. Add node values to sum when they fall within the range.
4. Restore tree structure by removing temporary links after traversal.

```cpp
class Solution {
public:
    int nodeSum(Node* root, int l, int r) {
        int sum = 0;
        Node* cur = root;
        while (cur) {
            if (!cur->left) {
                if (cur->data >= l && cur->data <= r) sum += cur->data;
                cur = cur->right;
            } else {
                Node* pre = cur->left;
                while (pre->right && pre->right != cur) pre = pre->right;
                if (!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = nullptr;
                    if (cur->data >= l && cur->data <= r) sum += cur->data;
                    cur = cur->right;
                }
            }
        }
        return sum;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each node visited at most twice
* **Auxiliary Space:** 💾 O(1) - No extra space for recursion or stack

### ✅ **Why This Approach?**

* True O(1) space complexity without recursion
* Suitable for memory-constrained environments
* Advanced technique demonstrating threading concept

## 📊 **4️⃣ Level Order Traversal (BFS)**

### 💡 Algorithm Steps:

1. Use queue for breadth-first level order traversal.
2. Process nodes level by level from root to leaves.
3. Check each node against range and accumulate sum for valid nodes.
4. Add children to queue only if they can potentially fall in range.

```cpp
class Solution {
public:
    int nodeSum(Node* root, int l, int r) {
        if (!root) return 0;
        queue<Node*> q;
        q.push(root);
        int sum = 0;
        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();
            if (cur->data >= l && cur->data <= r) sum += cur->data;
            if (cur->left && cur->data > l) q.push(cur->left);
            if (cur->right && cur->data < r) q.push(cur->right);
        }
        return sum;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Process each relevant node once
* **Auxiliary Space:** 💾 O(w) - Queue space proportional to maximum width

### ✅ **Why This Approach?**

* Level-by-level processing can be useful for debugging
* Natural for problems requiring level information
* Different traversal perspective than DFS

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🌲 **Recursive DFS**              | 🟢 O(n)                | 🟡 O(h)                 | 🎯 Clean and intuitive            | 📚 Recursion stack overhead          |
| 🔄 **Iterative Stack**            | 🟢 O(n)                | 🟡 O(h)                 | 🚫 No recursion limits            | 🔧 More verbose code                 |
| 🧵 **Morris Traversal**           | 🟢 O(n)                | 🟢 O(1)                 | ⭐ True O(1) space                | 🎭 Complex implementation            |
| 📊 **Level Order BFS**            | 🟢 O(n)                | 🟡 O(w)                 | 📖 Level-wise processing          | 💾 Width-based space usage           |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Standard balanced tree**                         | 🥇 **Recursive DFS**                 | ★★★★★                     |
| 🌳 **Very deep tree**                                 | 🥈 **Iterative Stack**               | ★★★★☆                     |
| 💾 **Memory constrained**                             | 🥉 **Morris Traversal**              | ★★★★★                     |
| 📊 **Need level information**                         | 🏅 **Level Order BFS**               | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int nodeSum(Node root, int l, int r) {
        if (root == null) return 0;
        if (root.data < l) return nodeSum(root.right, l, r);
        if (root.data > r) return nodeSum(root.left, l, r);
        return root.data + nodeSum(root.left, l, r) + nodeSum(root.right, l, r);
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def nodeSum(self, root, l, r):
        if not root: return 0
        if root.data < l: return self.nodeSum(root.right, l, r)
        if root.data > r: return self.nodeSum(root.left, l, r)
        return root.data + self.nodeSum(root.left, l, r) + self.nodeSum(root.right, l, r)
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" alt="Visitor counter" />
</p>
