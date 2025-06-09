---
title: "🌳 BST with Dead End | GFG Solution 🚧"
keywords🏷️: ["🌳 BST", "🚧 dead end", "🧠 recursion", "📘 GFG", "✅ binary tree", "🔍 DFS", "🧬 tree traversal", "📚 DSA", "🏁 competitive programming"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to BST with Dead End: detect if a BST has any dead-end node where no more insertions are possible while maintaining BST properties. 🚀"
date: 📅 2025-06-09
---

# *09. BST with Dead End*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1)


## **🧩 Problem Description**

You are given a **Binary Search Tree (BST)** that contains **only unique positive integers greater than 0**. A **dead end** is a **leaf node** such that no further node can be inserted under it while still maintaining the BST property and constraint that node values must be **> 0**.

Your task is to determine whether the BST contains any such **dead end**.


## **📘 Examples**

### Example 1

`
Input: root[] = [8, 5, 9, 2, 7, N, N, 1]
`

<img src="https://github.com/user-attachments/assets/15ef4c6d-28f4-422b-85da-cc783922fcef" width="30%">

`
Output: true
`

`
Explanation: Node 1 is a dead end since 0 is not allowed and 2 already exists.
`

### Example 2

`
Input: root[] = [8, 7, 10, 2, N, 9, 13]
`

<img src="https://github.com/user-attachments/assets/c5c10602-fc6e-4b1e-9f8b-67c2fe3ecdba" width="30%">

`
Output: true
`

`
Explanation: Node 9 is a dead end as no new node can be inserted below it.
`


## **🔒 Constraints**

* \$1 \leq \text{Number of nodes} \leq 3000\$
* \$1 \leq \text{Node->data} \leq 10^5\$


## ✅ **My Approach**

### DFS with Dynamic Range \[Low, High]

We recursively traverse the tree, carrying two bounds:

* `l`: the lowest possible value a child node can take
* `r`: the highest possible value a child node can take

If we encounter a **leaf node** where `l == r`, it means:

* There is **no space left** to insert any node under this leaf while obeying BST rules and positivity constraint.

### 💡 Logic:

* Initially call: `dfs(root, 1, INT_MAX)`
* For each node:

  * Check left: `dfs(root->left, l, root->data - 1)`
  * Check right: `dfs(root->right, root->data + 1, r)`
* If `l == r` at a leaf ⇒ Dead End found.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), as we visit each node exactly once.
* **Expected Auxiliary Space Complexity:** O(h), where `h` is the height of the BST due to recursion stack.


## **🧑‍💻 Code (C++)**

```cpp
class Solution {
  public:
    bool dfs(Node* root, int l, int r) {
        if (!root) return false;
        if (!root->left && !root->right && l == r) return true;
        return dfs(root->left, l, root->data - 1) || dfs(root->right, root->data + 1, r);
    }
    bool isDeadEnd(Node* root) {
        return dfs(root, 1, INT_MAX);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ HashSet + Inorder Traversal**

### 💡 Algorithm Steps:

1. Traverse the BST and store all nodes and leaf nodes in `unordered_set<int>`:

   * `all` for every node
   * `leaves` for leaf nodes
2. After traversal, check for each leaf if `leaf+1` and `leaf-1` both exist in `all` set — this indicates a dead end.

```cpp
class Solution {
  public:
    void traverse(Node* root, unordered_set<int>& all, unordered_set<int>& leaf) {
        if (!root) return;
        all.insert(root->data);
        if (!root->left && !root->right) leaf.insert(root->data);
        traverse(root->left, all, leaf);
        traverse(root->right, all, leaf);
    }
    
    bool isDeadEnd(Node* root) {
        unordered_set<int> all, leaf;
        all.insert(0);
        traverse(root, all, leaf);
        for (int val : leaf)
            if (all.count(val - 1) && all.count(val + 1))
                return true;
        return false;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Space:** 💾 O(n) (due to sets)

### ✅ **Why This Approach?**

* Tracks all nodes and leaves to verify dead ends directly.
* Effective when recursive range-check logic is hard to trace.


## 📊 **3️⃣ Bottom-Up BST Recursion with Early Return**

### 💡 Algorithm Steps:

1. Use recursion to return `true` if dead end exists in either left or right subtree.
2. At each node, check if `min == max` (boundary restriction met).

```cpp
class Solution {
  public:
    bool check(Node* root, int min, int max) {
        if (!root) return false;
        if (min == max) return true;
        return check(root->left, min, root->data - 1) || 
               check(root->right, root->data + 1, max);
    }
    bool isDeadEnd(Node* root) {
        return check(root, 1, INT_MAX);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Space:** 💾 O(h) (recursive stack)

### ✅ **Why This Approach?**

* Clean, concise, and leverages BST property via boundary propagation.
* Matches the original reference approach.


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**            | ⏱️ **Time** | 💾 **Space** | ✅ **Pros**                     | ⚠️ **Cons**                                 |
| -------------------------- | ----------- | ------------ | ------------------------------ | ------------------------------------------- |
| 🔍 **DFS with Boundaries** | 🟢 O(n)        | 🟢 O(h)         | Efficient, no extra memory     | Requires correct range management           |
| 📦 **HashSet + Traverse**  | 🟢 O(n)        | 🟢 O(n)         | Simple logic with pre-checking | Uses more memory                            |
| 🧮 **Bottom-Up Recursion** | 🟢 O(n)        | 🟡 O(h)         | Clear condition checking       | Conceptually similar to 1st but less direct |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                       | 🎖️ **Recommended Approach**      |
| ------------------------------------- | --------------------------------- |
| 👍 For concise & optimal solution     | 🥇 DFS with boundaries            |
| 🧪 For readability and debugging ease | 🥈 HashSet leaf checking          |
| 📘 When working with deep tree logic  | 🥉 Bottom-Up recursion            |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    boolean dfs(Node root, int l, int r) {
        if (root == null) return false;
        if (root.left == null && root.right == null && l == r) return true;
        return dfs(root.left, l, root.data - 1) || dfs(root.right, root.data + 1, r);
    }
    
    public boolean isDeadEnd(Node root) {
        return dfs(root, 1, Integer.MAX_VALUE);
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def dfs(self, root, l, r):
        if not root: return False
        if not root.left and not root.right and l == r: return True
        return self.dfs(root.left, l, root.data - 1) or self.dfs(root.right, root.data + 1, r)

    def isDeadEnd(self, root):
        return self.dfs(root, 1, float('inf'))
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
