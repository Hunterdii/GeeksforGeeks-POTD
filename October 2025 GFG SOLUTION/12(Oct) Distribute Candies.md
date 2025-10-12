---
title: "🍬 Distribute Candies | GFG Solution 🌳"
keywords🏷️: ["🍬 distribute candies", "🌳 binary tree", "🔄 DFS", "⚖️ balance calculation", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Distribute Candies in Binary Tree problem: find minimum moves to distribute candies such that each node has exactly one candy using post-order DFS traversal. 🚀"
date: 📅 2025-10-12
---

# *12. Distribute Candies*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1)

## **🧩 Problem Description**

You are given the root of a binary tree with `n` nodes, where each node contains a certain number of candies, and the total number of candies across all nodes is `n`. In one move, you can select any two adjacent nodes and transfer one candy from one node to the other. The transfer can occur between a parent and child in either direction.

The task is to determine the **minimum number of moves** required to ensure that every node in the tree has exactly one candy.

**Note:** The testcases are framed such that it is always possible to achieve a configuration in which every node has exactly one candy, after some moves.

## **📘 Examples**

### Example 1

```cpp
Input: root = [5, 0, 0, N, N, 0, 0]
Output: 6
Explanation:
Move 1 candy from root to left child
Move 1 candy from root to right child
Move 1 candy from right child to root->right->left node
Move 1 candy from root to right child
Move 1 candy from right child to root->right->right node
Move 1 candy from root to right child
So, total 6 moves required.
```

### Example 2

```cpp
Input: root = [2, 0, 0, N, N, 3, 0]
Output: 4
Explanation:
Move 1 candy from root to left child
Move 1 candy from root->right->left node to root->right node
Move 1 candy from root->right node to root->right->right node
Move 1 candy from root->right->left node to root->right node
So, total 4 moves required.
```

## **🔒 Constraints**

* $1 \le n \le 3 \times 10^3$
* $0 \le \text{Node->data} \le n$
* The sum of all Node->data = n

## **✅ My Approach**

The optimal approach uses **Post-Order DFS Traversal** with **Balance Calculation** to efficiently compute the minimum number of candy distribution moves:

### **Post-Order DFS with Balance Tracking**

1. **Base Case:**
   * If the current node is null, return 0 (no candies to balance).

2. **Recursive Traversal:**
   * Recursively compute the balance for the left subtree.
   * Recursively compute the balance for the right subtree.
   * Balance represents excess (positive) or deficit (negative) candies.

3. **Calculate Node Balance:**
   * For each node, calculate: `balance = node->data - 1 + leftBalance + rightBalance`
   * The `-1` accounts for the one candy that should remain at the current node.
   * `leftBalance` and `rightBalance` represent candies flowing from children.

4. **Count Moves:**
   * Add `abs(balance)` to the total moves counter.
   * The absolute value represents candies that must pass through this node's edge with its parent.

5. **Return Balance:**
   * Return the computed balance to the parent node for further calculation.

### **Key Insight:**
* Each edge between parent and child will transfer exactly `|balance|` candies.
* The direction (up or down) doesn't matter; we only count the number of transfers.
* Post-order traversal ensures children are processed before parents.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of nodes in the binary tree. We visit each node exactly once during the DFS traversal to calculate balance and accumulate moves.
* **Expected Auxiliary Space Complexity:** O(h), where h is the height of the binary tree. This space is used by the recursion call stack during DFS traversal. In the worst case of a skewed tree, h = n, making it O(n). For a balanced tree, h = log(n), making it O(log n).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int distCandy(Node* root) {
        int moves = 0;
        function<int(Node*)> dfs = [&](Node* n) {
            if (!n) return 0;
            int bal = n->data - 1 + dfs(n->left) + dfs(n->right);
            moves += abs(bal);
            return bal;
        };
        dfs(root);
        return moves;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Post-Order Traversal with Balance Tracking**

### 💡 Algorithm Steps:

1. Process children nodes before parent using post-order traversal.
2. Calculate excess or deficit candies at each node.
3. Accumulate absolute values of imbalances as total moves.
4. Propagate net balance upward to parent nodes.

```cpp
class Solution {
public:
    int distCandy(Node* root) {
        int result = 0;
        auto balance = [&](auto& self, Node* node) -> int {
            if (!node) return 0;
            int left = self(self, node->left);
            int right = self(self, node->right);
            int excess = node->data + left + right - 1;
            result += abs(left) + abs(right);
            return excess;
        };
        balance(balance, root);
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Visit each node exactly once
* **Auxiliary Space:** 💾 O(h) - Recursion stack depth equals tree height

### ✅ **Why This Approach?**

* Clear separation of balance calculation and move counting
* Lambda recursion pattern for modern C++
* Easy to trace flow of candy redistribution

## 📊 **3️⃣ Iterative Stack-Based Approach**

### 💡 Algorithm Steps:

1. Use explicit stack to simulate post-order traversal iteratively.
2. Track visited nodes to ensure children are processed first.
3. Calculate balance for each node after processing children.
4. Sum absolute balances to get total distribution moves.

```cpp
class Solution {
public:
    int distCandy(Node* root) {
        if (!root) return 0;
        stack<Node*> st;
        unordered_map<Node*, int> bal;
        Node* last = nullptr;
        Node* curr = root;
        int moves = 0;
        while (!st.empty() || curr) {
            if (curr) {
                st.push(curr);
                curr = curr->left;
            } else {
                Node* top = st.top();
                if (top->right && last != top->right) {
                    curr = top->right;
                } else {
                    int l = top->left ? bal[top->left] : 0;
                    int r = top->right ? bal[top->right] : 0;
                    bal[top] = top->data + l + r - 1;
                    moves += abs(l) + abs(r);
                    last = top;
                    st.pop();
                }
            }
        }
        return moves;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each node pushed and popped once
* **Auxiliary Space:** 💾 O(n) - Stack and hashmap storage

### ✅ **Why This Approach?**

* Avoids recursion for large trees
* Explicit control over traversal order
* Useful when recursion depth is a concern

## 📊 **4️⃣ Post-Order with HashMap Storage**

### 💡 Algorithm Steps:

1. Perform post-order traversal storing balance in hashmap.
2. Calculate balance for left and right children from hashmap.
3. Store current node's balance for parent lookup.
4. Accumulate moves based on absolute child balances.

```cpp
class Solution {
public:
    int distCandy(Node* root) {
        int moves = 0;
        unordered_map<Node*, int> balance;
        function<void(Node*)> postorder = [&](Node* n) {
            if (!n) return;
            postorder(n->left);
            postorder(n->right);
            int l = n->left ? balance[n->left] : 0;
            int r = n->right ? balance[n->right] : 0;
            balance[n] = n->data + l + r - 1;
            moves += abs(l) + abs(r);
        };
        postorder(root);
        return moves;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through all nodes
* **Auxiliary Space:** 💾 O(n) - Hashmap for balance storage

### ✅ **Why This Approach?**

* Explicit post-order pattern demonstration
* Balance storage for potential further operations
* Clear separation of concerns in logic

## 📊 **5️⃣ Helper Function Approach**

### 💡 Algorithm Steps:

1. Create separate helper function to handle recursion.
2. Pass moves counter by reference to update across calls.
3. Calculate balance and update moves in helper function.
4. Return balance value for parent node calculation.

```cpp
class Solution {
public:
    int helper(Node* n, int& moves) {
        if (!n) return 0;
        int l = helper(n->left, moves);
        int r = helper(n->right, moves);
        moves += abs(l) + abs(r);
        return n->data + l + r - 1;
    }
    
    int distCandy(Node* root) {
        int moves = 0;
        helper(root, moves);
        return moves;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Visit each node once
* **Auxiliary Space:** 💾 O(h) - Recursion stack space

### ✅ **Why This Approach?**

* Traditional recursive pattern
* Easy to understand for beginners
* Clear separation between main and helper functions

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Lambda DFS**                 | 🟢 O(n)                | 🟢 O(h)                 | 🚀 Most concise & elegant         | 🔧 Requires C++11 features           |
| 🔄 **Balance Tracking**           | 🟢 O(n)                | 🟢 O(h)                 | 📖 Clear logic flow               | 📝 Slightly verbose                  |
| 📚 **Iterative Stack**            | 🟢 O(n)                | 🟡 O(n)                 | 🎯 No recursion limits            | 🐌 More complex implementation       |
| 🧵 **Post-Order Map**             | 🟢 O(n)                | 🟡 O(n)                 | ⭐ Balance reusability            | 💾 Extra space overhead              |
| 🔧 **Helper Function**            | 🟢 O(n)                | 🟢 O(h)                 | 📖 Traditional & clear            | 📝 More lines of code                |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal code brevity**                       | 🥇 **Lambda DFS**                    | ★★★★★                     |
| 📖 **Interview explanation**                      | 🥈 **Balance Tracking**              | ★★★★★                     |
| 🔧 **Deep recursion concern**                     | 🥉 **Iterative Stack**               | ★★★☆☆                     |
| 🎯 **Competitive programming**                    | 🏅 **Lambda DFS**                    | ★★★★★                     |
| 📚 **Learning/Educational**                       | 🎖️ **Helper Function**               | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    int moves = 0;
    public int distCandy(Node root) {
        dfs(root);
        return moves;
    }
    int dfs(Node n) {
        if (n == null) return 0;
        int bal = n.data - 1 + dfs(n.left) + dfs(n.right);
        moves += Math.abs(bal);
        return bal;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def distCandy(self, root):
        self.moves = 0
        def dfs(n):
            if not n: return 0
            bal = n.data - 1 + dfs(n.left) + dfs(n.right)
            self.moves += abs(bal)
            return bal
        dfs(root)
        return self.moves
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
