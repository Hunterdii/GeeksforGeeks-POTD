---
title: "🌳 BST to Greater Sum Tree | GFG Solution 🔍"
keywords🏷️: ["🌳 binary search tree", "🔄 tree transformation", "📊 reverse inorder", "🎯 greater sum tree", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the BST to Greater Sum Tree problem: transform each node to contain sum of all greater nodes using reverse inorder traversal. 🚀"
date: 📅 2025-10-17
---

# *17. BST to Greater Sum Tree*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/bst-to-greater-sum-tree/1)

## **🧩 Problem Description**

Given the root of a **Binary Search Tree (BST)** with unique node values, transform it into a **greater sum tree** where each node contains the sum of all nodes greater than that node.

A greater sum tree is a modified BST where every node's value is replaced by the sum of all node values that are strictly greater than the current node's value in the original BST.

## **📘 Examples**

### Example 1

```cpp
Input: root = [11, 2, 29, 1, 7, 15, 40, N, N, N, N, N, N, 35, N]
Output: [119, 137, 75, 139, 130, 104, 0, N, N, N, N, N, N, 40, N]
Explanation: Every node is replaced with the sum of nodes greater than itself.
```

### Example 2

```cpp
Input: root = [2, 1, 6, N, N, 3, 7]
Output: [16, 18, 7, N, N, 13, 0]
Explanation: Every node is replaced with the sum of nodes greater than itself.
```

## **🔒 Constraints**

* $1 \le \text{node->data} \le 3 \times 10^4$
* $1 \le \text{number of nodes} \le 3 \times 10^4$

## **✅ My Approach**

The optimal approach uses **Reverse Inorder Traversal** to process nodes in descending order, maintaining a running sum of all processed nodes:

### **Reverse Inorder Traversal**

1. **Traversal Order:**
   * Process right subtree first (larger values).
   * Then process current node.
   * Finally process left subtree (smaller values).

2. **Maintain Running Sum:**
   * Keep a cumulative sum variable that tracks total of all nodes processed so far.
   * Since we traverse from largest to smallest, this sum represents all greater values.

3. **Update Node Values:**
   * Store current node's original value temporarily.
   * Replace node's value with current cumulative sum (sum of all greater nodes).
   * Add original value to cumulative sum for next iterations.

4. **Recursive Processing:**
   * Base case: If node is null, return immediately.
   * Recursively process right subtree, update current node, then process left subtree.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of nodes in the BST. We visit each node exactly once during the reverse inorder traversal.
* **Expected Auxiliary Space Complexity:** O(h), where h is the height of the tree. This space is used by the recursion call stack. In the worst case (skewed tree), h = n, and in the best case (balanced tree), h = log(n).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    void transformTree(Node* root) {
        int s = 0;
        function<void(Node*)> f = [&](Node* n) {
            if (!n) return;
            f(n->right);
            int temp = n->data;
            n->data = s;
            s += temp;
            f(n->left);
        };
        f(root);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Iterative Stack-Based Approach**

### 💡 Algorithm Steps:

1. Use a stack to simulate reverse in-order traversal (right-root-left).
2. Push all right-most nodes onto the stack first.
3. Process each node by storing current sum before adding node value.
4. Move to left subtree and repeat until all nodes are processed.

```cpp
class Solution {
public:
    void transformTree(Node* root) {
        stack<Node*> st;
        Node* curr = root;
        int sum = 0;
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->right;
            }
            curr = st.top();
            st.pop();
            int temp = curr->data;
            curr->data = sum;
            sum += temp;
            curr = curr->left;
        }
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Visit each node exactly once
* **Auxiliary Space:** 💾 O(h) - Stack space proportional to tree height

### ✅ **Why This Approach?**

* Avoids recursion overhead and stack overflow for deep trees
* Explicit control over traversal order
* Better for very deep or skewed trees

## 📊 **3️⃣ Morris Traversal (Threaded Tree)**

### 💡 Algorithm Steps:

1. Use Morris traversal for O(1) space reverse in-order traversal.
2. Create temporary links (threads) to enable traversal without stack or recursion.
3. Process nodes in right-root-left order storing sum before updating.
4. Restore tree structure by removing temporary threads after processing.

```cpp
class Solution {
public:
    void transformTree(Node* root) {
        int sum = 0;
        Node* curr = root;
        while (curr) {
            if (!curr->right) {
                int temp = curr->data;
                curr->data = sum;
                sum += temp;
                curr = curr->left;
            } else {
                Node* pred = curr->right;
                while (pred->left && pred->left != curr)
                    pred = pred->left;
                if (!pred->left) {
                    pred->left = curr;
                    curr = curr->right;
                } else {
                    pred->left = nullptr;
                    int temp = curr->data;
                    curr->data = sum;
                    sum += temp;
                    curr = curr->left;
                }
            }
        }
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each edge traversed at most twice
* **Auxiliary Space:** 💾 O(1) - No extra space for recursion or stack

### ✅ **Why This Approach?**

* Achieves true constant space complexity
* Ideal for memory-constrained environments
* Advanced technique demonstrating deep tree understanding

## 📊 **4️⃣ Helper Function Approach**

### 💡 Algorithm Steps:

1. Create a separate helper function that takes sum as reference parameter.
2. Perform reverse in-order traversal (right-root-left).
3. Store sum before adding current node value.
4. Pass accumulated sum through recursion using reference.

```cpp
class Solution {
public:
    void helper(Node* n, int& sum) {
        if (!n) return;
        helper(n->right, sum);
        int temp = n->data;
        n->data = sum;
        sum += temp;
        helper(n->left, sum);
    }
    
    void transformTree(Node* root) {
        int sum = 0;
        helper(root, sum);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single traversal of all nodes
* **Auxiliary Space:** 💾 O(h) - Recursion stack depth

### ✅ **Why This Approach?**

* Clean separation of concerns with helper function
* Easy to understand and debug
* Traditional recursive pattern

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔄 **Lambda Recursive**           | 🟢 O(n)                | 🟡 O(h)                 | 🚀 Concise and elegant            | 💾 Recursion overhead                |
| 📚 **Iterative Stack**            | 🟢 O(n)                | 🟡 O(h)                 | 🎯 No recursion limits            | 🔧 More verbose code                 |
| 🧵 **Morris Traversal**           | 🟢 O(n)                | 🟢 O(1)                 | ⭐ True constant space            | 🔧 Complex implementation            |
| 🛠️ **Helper Function**            | 🟢 O(n)                | 🟡 O(h)                 | 📖 Easy to understand             | 🔧 Extra function overhead           |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Clean code priority**                            | 🥇 **Lambda Recursive**              | ★★★★★                     |
| 📖 **Deep tree handling**                             | 🥈 **Iterative Stack**               | ★★★★☆                     |
| 💾 **Memory constraints**                             | 🥉 **Morris Traversal**              | ★★★★★                     |
| 🎓 **Learning/Understanding**                         | 🏅 **Helper Function**               | ★★★★☆                     |

</details>


## **☕ Code (Java)**

```java
class Solution {
    int s = 0;
    public void transformTree(Node root) {
        if (root == null) return;
        transformTree(root.right);
        int temp = root.data;
        root.data = s;
        s += temp;
        transformTree(root.left);
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def transformTree(self, root):
        self.s = 0
        def f(n):
            if not n: return
            f(n.right)
            temp = n.data
            n.data = self.s
            self.s += temp
            f(n.left)
        f(root)
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
