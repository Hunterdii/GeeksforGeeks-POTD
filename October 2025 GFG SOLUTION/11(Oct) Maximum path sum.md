---
title: "🌳 Maximum Path Sum | GFG Solution 🔍"
keywords🏷️: ["🌳 binary tree", "🔍 path sum", "📍 recursion", "📈 DFS", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Maximum Path Sum problem: find maximum sum path between any two nodes in a binary tree using recursive DFS technique. 🚀"
date: 📅 2025-10-11
---

# *11. Maximum Path Sum*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1)

## **🧩 Problem Description**

You are given the `root` of a binary tree. Your task is to find the **maximum path sum**. The path may start and end at **any node** in the tree.

A path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

## **📘 Examples**

### Example 1

```cpp
Input: root[] = [10, 2, 10, 20, 1, N, -25, N, N, N, N, 3, 4]
Output: 42
Explanation: The maximum path sum is 20 + 2 + 10 + 10 = 42 
(represented by green nodes in the tree).
```

### Example 2

```cpp
Input: root[] = [-17, 11, 4, 20, -2, 10]
Output: 31
Explanation: The maximum path sum is 20 + 11 = 31 
(represented by green nodes in the tree).
```

## **🔒 Constraints**

* $1 \le \text{number of nodes} \le 10^3$
* $-10^4 \le \text{node->data} \le 10^4$

## **✅ My Approach**

The optimal approach uses **Recursive Depth-First Search (DFS)** to efficiently calculate the maximum path sum:

### **Recursive DFS**

1. **Base Case:**
   * If the current node is null, return 0 (no contribution to path sum).

2. **Recursive Exploration:**
   * Recursively calculate the maximum path sum from the left subtree.
   * Recursively calculate the maximum path sum from the right subtree.
   * Use `max(0, subtree_sum)` to ignore negative contributions (only include positive paths).

3. **Update Global Maximum:**
   * At each node, calculate the path sum that passes through the current node: `node->data + left_sum + right_sum`.
   * Update the global maximum result with this value.

4. **Return Value:**
   * Return the maximum single path contribution going upward: `node->data + max(left_sum, right_sum)`.
   * This allows the parent node to extend the path further.

5. **Final Result:**
   * After the complete traversal, return the global maximum path sum found.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of nodes in the binary tree. We visit each node exactly once during the DFS traversal.
* **Expected Auxiliary Space Complexity:** O(h), where h is the height of the binary tree. This space is used by the recursion call stack. In the worst case (skewed tree), h can be O(n), and in the best case (balanced tree), h is O(log n).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int findMaxSum(Node *root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
    
    int dfs(Node *node, int &res) {
        if (!node) return 0;
        int l = max(0, dfs(node->left, res));
        int r = max(0, dfs(node->right, res));
        res = max(res, node->data + l + r);
        return node->data + max(l, r);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Iterative Post-Order Traversal**

### 💡 Algorithm Steps:

1. Use two stacks to simulate post-order traversal iteratively.
2. Store subtree maximum path sums in a map for each node.
3. Calculate path sum when both children are processed.
4. Track global maximum throughout traversal.

```cpp
class Solution {
public:
    int findMaxSum(Node *root) {
        if (!root) return 0;
        stack<Node*> st;
        unordered_map<Node*, int> mp;
        int res = root->data;
        st.push(root);
        while (!st.empty()) {
            Node* node = st.top();
            if ((node->left && !mp.count(node->left)) || (node->right && !mp.count(node->right))) {
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
            } else {
                st.pop();
                int l = node->left ? max(0, mp[node->left]) : 0;
                int r = node->right ? max(0, mp[node->right]) : 0;
                res = max(res, node->data + l + r);
                mp[node] = node->data + max(l, r);
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Visit each node once
* **Auxiliary Space:** 💾 O(n) - Stack and map storage

### ✅ **Why This Approach?**

* Avoids recursion stack overflow for deep trees
* Explicit control over traversal order
* Useful when recursion depth is limited

## 📊 **3️⃣ Modified Recursion with Pair Return**

### 💡 Algorithm Steps:

1. Return both maximum path through node and path ending at node.
2. Use pair to communicate both values simultaneously.
3. Calculate path sum including current node at each step.
4. Update global maximum with path through current node.

```cpp
class Solution {
public:
    int findMaxSum(Node *root) {
        return helper(root).first;
    }
    
    pair<int, int> helper(Node* node) {
        if (!node) return {INT_MIN, 0};
        auto [lMax, lPath] = helper(node->left);
        auto [rMax, rPath] = helper(node->right);
        int pathThrough = node->data + max(0, lPath) + max(0, rPath);
        int maxSoFar = max({lMax, rMax, pathThrough});
        int pathEnd = node->data + max({0, lPath, rPath});
        return {maxSoFar, pathEnd};
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single traversal of tree
* **Auxiliary Space:** 💾 O(h) - Recursion stack height

### ✅ **Why This Approach?**

* No global variable needed
* Pure functional style without side effects
* Returns complete information at each level

## 📊 **4️⃣ Single Pass with Lambda**

### 💡 Algorithm Steps:

1. Define recursive lambda function inside main function.
2. Capture result variable by reference for updates.
3. Compute left and right subtree contributions inline.
4. Return maximum single path contribution upward.

```cpp
class Solution {
public:
    int findMaxSum(Node *root) {
        int res = INT_MIN;
        function<int(Node*)> solve = [&](Node* n) {
            if (!n) return 0;
            int l = max(0, solve(n->left)), r = max(0, solve(n->right));
            res = max(res, n->data + l + r);
            return n->data + max(l, r);
        };
        solve(root);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Process each node once
* **Auxiliary Space:** 💾 O(h) - Recursion depth

### ✅ **Why This Approach?**

* Compact code with lambda expression
* Modern C++ style programming
* Self-contained logic within single function

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Recursive DFS**              | 🟢 O(n)                | 🟢 O(h)                 | 🚀 Simple and efficient           | 📝 Uses global variable              |
| 🔄 **Iterative Post-Order**       | 🟢 O(n)                | 🟡 O(n)                 | 🛡️ No recursion limits            | 💾 Extra space for map               |
| 📦 **Pair Return**                | 🟢 O(n)                | 🟢 O(h)                 | 🎯 No global state                | 🔧 More complex return type          |
| ⚡ **Lambda Function**            | 🟢 O(n)                | 🟢 O(h)                 | 📖 Compact modern code            | 🆕 Requires C++11 or later           |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General purpose optimal**                        | 🥇 **Recursive DFS**                 | ★★★★★                     |
| 🛡️ **Very deep trees**                               | 🥈 **Iterative Post-Order**          | ★★★★☆                     |
| 🎯 **Functional programming**                         | 🥉 **Pair Return**                   | ★★★★☆                     |
| 📖 **Modern C++ style**                               | 🏅 **Lambda Function**               | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    int res;
    
    int findMaxSum(Node root) {
        res = Integer.MIN_VALUE;
        dfs(root);
        return res;
    }
    
    int dfs(Node node) {
        if (node == null) return 0;
        int l = Math.max(0, dfs(node.left));
        int r = Math.max(0, dfs(node.right));
        res = Math.max(res, node.data + l + r);
        return node.data + Math.max(l, r);
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def findMaxSum(self, root): 
        self.res = float('-inf')
        
        def dfs(node):
            if not node: return 0
            l = max(0, dfs(node.left))
            r = max(0, dfs(node.right))
            self.res = max(self.res, node.data + l + r)
            return node.data + max(l, r)
        
        dfs(root)
        return self.res
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
