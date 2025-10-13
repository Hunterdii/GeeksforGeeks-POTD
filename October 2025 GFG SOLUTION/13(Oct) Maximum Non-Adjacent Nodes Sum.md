---
title: "🌳 Maximum Non-Adjacent Nodes Sum | GFG Solution 🔍"
keywords🏷️: ["🌳 binary tree", "🔍 dynamic programming", "📍 tree dp", "📈 recursion", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Maximum Non-Adjacent Nodes Sum problem: find maximum sum of nodes in a binary tree where no two adjacent nodes are selected using dynamic programming on trees. 🚀"
date: 📅 2025-10-13
---

# *13. Maximum Non-Adjacent Nodes Sum*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1)

## **🧩 Problem Description**

Given the root of a binary tree with integer values, your task is to select a subset of nodes such that the sum of their values is maximized, with the condition that **no two selected nodes are directly connected**. That is, if a node is included in the subset, neither its parent nor its children can be included.

A node and its immediate parent or children form adjacent pairs in the tree structure. The goal is to maximize the sum while respecting this non-adjacency constraint.

## **📘 Examples**

### Example 1

```cpp
Input: root = [11, 1, 2]
Output: 11
Explanation: The maximum sum is obtained by selecting the node 11.
```

### Example 2

```cpp
Input: root = [1, 2, 3, 4, N, 5, 6]
Output: 16
Explanation: The maximum sum is obtained by selecting the nodes 1, 4, 5 and 6, 
which are not directly connected to each other. Their total sum is 16.
```

## **🔒 Constraints**

* $1 \le \text{number of nodes} \le 10^4$
* $1 \le \text{node.data} \le 10^5$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming on Trees** with a recursive strategy to compute two states for each node:

### **Tree DP with State Tracking**

1. **Define States:**
   * For each node, maintain two values:
     * **Include**: Maximum sum when current node is included (children must be excluded).
     * **Exclude**: Maximum sum when current node is excluded (children can be either included or excluded).

2. **Recursive Computation:**
   * Base case: If node is NULL, return (0, 0) representing both states as 0.
   * For each node, recursively compute states for left and right children.

3. **State Transition:**
   * **Include current node**: Add node's value to the sum of excluded states of both children.
     * `include = node->data + left_exclude + right_exclude`
   * **Exclude current node**: Take maximum of both states for each child.
     * `exclude = max(left_include, left_exclude) + max(right_include, right_exclude)`

4. **Return Result:**
   * Return pair of (include, exclude) for each node.
   * Final answer is the maximum of both states at root.

5. **Post-Order Traversal:**
   * Process children before parent to ensure bottom-up computation.
   * Each node uses computed results from its subtrees.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of nodes in the binary tree. We visit each node exactly once during the post-order traversal, performing constant time operations at each node.
* **Expected Auxiliary Space Complexity:** O(h), where h is the height of the binary tree. This space is used by the recursion call stack. In the worst case of a skewed tree, h can be O(n), but for a balanced tree, it is O(log n).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int getMaxSum(Node* root) {
        function<pair<int,int>(Node*)> dfs = [&](Node* node) -> pair<int,int> {
            if (!node) return {0, 0};
            auto [li, le] = dfs(node->left);
            auto [ri, re] = dfs(node->right);
            return {node->data + le + re, max(li, le) + max(ri, re)};
        };
        auto [inc, exc] = dfs(root);
        return max(inc, exc);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Dynamic Programming with Memoization**

### 💡 Algorithm Steps:

1. Use a map to cache computed results for each node.
2. For each node, compute two states: including and excluding current node.
3. Return cached result if node is already processed.
4. Recursively solve for left and right subtrees with memoization.

```cpp
class Solution {
public:
    unordered_map<Node*, pair<int,int>> dp;
    int getMaxSum(Node* root) {
        if (!root) return 0;
        if (dp.count(root)) return max(dp[root].first, dp[root].second);
        getMaxSum(root->left);
        getMaxSum(root->right);
        int inc = root->data + (root->left ? dp[root->left].second : 0) + (root->right ? dp[root->right].second : 0);
        int exc = (root->left ? max(dp[root->left].first, dp[root->left].second) : 0) + (root->right ? max(dp[root->right].first, dp[root->right].second) : 0);
        dp[root] = {inc, exc};
        return max(inc, exc);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Visit each node once
* **Auxiliary Space:** 💾 O(n) - HashMap storage for memoization

### ✅ **Why This Approach?**

* Avoids recomputation with caching
* Good for repeated queries on same tree
* Clear separation of state management

## 📊 **3️⃣ Bottom-Up Array Return**

### 💡 Algorithm Steps:

1. Post-order traversal returning array for each subtree.
2. Index 0 stores maximum sum including root.
3. Index 1 stores maximum sum excluding root.
4. Combine left and right results at each node.

```cpp
class Solution {
public:
    vector<int> solve(Node* root) {
        if (!root) return {0, 0};
        vector<int> l = solve(root->left);
        vector<int> r = solve(root->right);
        return {root->data + l[1] + r[1], max(l[0], l[1]) + max(r[0], r[1])};
    }
    int getMaxSum(Node* root) {
        vector<int> res = solve(root);
        return max(res[0], res[1]);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single traversal of tree
* **Auxiliary Space:** 💾 O(h) - Recursion stack height

### ✅ **Why This Approach?**

* Clean separation of helper and main function
* Easy to understand state representation
* Standard DP on trees pattern

## 📊 **4️⃣ Iterative Post-Order with Stack**

### 💡 Algorithm Steps:

1. Use stack to simulate post-order traversal iteratively.
2. Store state for each node in separate map.
3. Process children before parent to maintain bottom-up order.
4. Compute include and exclude states from children states.

```cpp
class Solution {
public:
    int getMaxSum(Node* root) {
        if (!root) return 0;
        stack<Node*> st;
        unordered_map<Node*, pair<int,int>> m;
        st.push(root);
        while (!st.empty()) {
            Node* node = st.top();
            if ((node->left && !m.count(node->left)) || (node->right && !m.count(node->right))) {
                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
            } else {
                st.pop();
                int inc = node->data + (node->left ? m[node->left].second : 0) + (node->right ? m[node->right].second : 0);
                int exc = (node->left ? max(m[node->left].first, m[node->left].second) : 0) + (node->right ? max(m[node->right].first, m[node->right].second) : 0);
                m[node] = {inc, exc};
            }
        }
        return max(m[root].first, m[root].second);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each node visited once
* **Auxiliary Space:** 💾 O(n) - Stack and map storage

### ✅ **Why This Approach?**

* Avoids recursion stack overflow for deep trees
* More control over traversal order
* Useful when recursion depth is limited

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Pair Return**                | 🟢 O(n)                | 🟢 O(h)                 | 🚀 Clean and concise              | 🔧 Modern C++ features required      |
| 💾 **Memoization**                | 🟢 O(n)                | 🟡 O(n)                 | 🔄 Reusable cache                 | 💾 Extra space for map               |
| 📊 **Array Return**               | 🟢 O(n)                | 🟢 O(h)                 | 📖 Clear state representation     | 🔧 Extra vector allocations          |
| 🔄 **Iterative**                  | 🟢 O(n)                | 🟡 O(n)                 | 🛡️ No recursion limit            | 🐌 Complex implementation            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Modern C++ competitive coding**                  | 🥇 **Pair Return**                   | ★★★★★                     |
| 📖 **Learning DP on trees**                           | 🥈 **Array Return**                  | ★★★★☆                     |
| 🔧 **Deep tree scenarios**                            | 🥉 **Iterative**                     | ★★★★☆                     |
| 🎯 **Multiple queries on same tree**                  | 🏅 **Memoization**                   | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int getMaxSum(Node root) {
        int[] res = helper(root);
        return Math.max(res[0], res[1]);
    }
    private int[] helper(Node node) {
        if (node == null) return new int[]{0, 0};
        int[] l = helper(node.left);
        int[] r = helper(node.right);
        int inc = node.data + l[1] + r[1];
        int exc = Math.max(l[0], l[1]) + Math.max(r[0], r[1]);
        return new int[]{inc, exc};
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def getMaxSum(self, root):
        def helper(node):
            if not node: return (0, 0)
            l = helper(node.left)
            r = helper(node.right)
            inc = node.data + l[1] + r[1]
            exc = max(l) + max(r)
            return (inc, exc)
        return max(helper(root))
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
