---
title: "🌳 Kth Smallest Element in BST | GFG Solution 🔍"
keywords🏷️: ["🌳 binary search tree", "🔍 inorder traversal", "📍 iterative stack", "📈 tree traversal", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Kth Smallest Element in BST problem: find the kth smallest element in a binary search tree using iterative inorder traversal with stack. 🚀"
date: 📅 2025-10-15
---

# *15. Kth Smallest Element in BST*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1)

## **🧩 Problem Description**

Given the root of a **Binary Search Tree (BST)** and an integer `k`, the task is to find the **kth smallest element** in the BST. If there is no kth smallest element present, return `-1`.

A BST is a tree where for each node, all elements in the left subtree are smaller and all elements in the right subtree are greater. An inorder traversal of a BST yields elements in sorted (ascending) order.

## **📘 Examples**

### Example 1

```cpp
Input: root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], k = 3
Output: 10
Explanation: The inorder traversal of the BST is [4, 8, 10, 12, 14, 20, 22].
The 3rd smallest element is 10.
```

### Example 2

```cpp
Input: root = [2, 1, 3], k = 5
Output: -1
Explanation: There is no 5th smallest element in the BST as the size of BST is 3.
```

## **🔒 Constraints**

* $1 \le \text{number of nodes, k} \le 10^4$
* $1 \le \text{node->data} \le 10^4$

## **✅ My Approach**

The optimal approach uses **Iterative Inorder Traversal** with an explicit stack to efficiently find the kth smallest element:

### **Iterative Stack-Based Inorder Traversal**

1. **Initialize Variables:**
   * Use an explicit stack to simulate the recursion call stack.
   * Maintain a counter `c` initialized to 0 to track visited nodes.
   * Use pointer `n` to traverse the tree starting from root.

2. **Traverse to Leftmost Node:**
   * Push all left children onto the stack while moving to the leftmost node.
   * This ensures we visit nodes in ascending order.

3. **Process Current Node:**
   * Pop a node from the stack.
   * Increment the counter `c`.
   * If `c` equals `k`, we've found the kth smallest element—return its value.

4. **Move to Right Subtree:**
   * Move to the right child of the current node.
   * Repeat the process for the right subtree.

5. **Early Termination:**
   * The algorithm stops as soon as the kth element is found.
   * No need to traverse the entire tree, making it efficient for small values of k.

6. **Return Result:**
   * If k exceeds the number of nodes, return `-1`.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(k), as we only traverse k nodes in the worst case. For a balanced BST with height h, we visit at most h nodes to reach the leftmost node, then k-1 more nodes to find the kth smallest element. In the best case (when k is small), we stop early without traversing the entire tree.
* **Expected Auxiliary Space Complexity:** O(h), where h is the height of the BST. The stack stores at most h nodes (the height of the tree) at any point during traversal. For a balanced BST, h = O(log n), and for a skewed BST, h = O(n).

## **Ⓜ️ Code (C)**

```c
int kthSmallest(struct Node* root, int k) {
    int s[100000], t = 0, c = 0;
    struct Node* n = root;
    while (n || t) {
        while (n) s[t++] = (long)n, n = n->left;
        n = (struct Node*)s[--t];
        if (++c == k) return n->data;
        n = n->right;
    }
    return -1;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int kthSmallest(Node *root, int k) {
        stack<Node*> s;
        Node* n = root;
        int c = 0;
        while (n || !s.empty()) {
            while (n) {
                s.push(n);
                n = n->left;
            }
            n = s.top(); s.pop();
            if (++c == k) return n->data;
            n = n->right;
        }
        return -1;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Morris Traversal Approach**

### 💡 Algorithm Steps:

1. Use Morris inorder traversal for O(1) space complexity.
2. Create threaded binary tree by linking rightmost nodes of left subtrees.
3. Visit nodes in sorted order without recursion or stack.
4. Return kth node encountered during traversal.
5. Restore tree structure by removing temporary links.

```cpp
class Solution {
public:
    int kthSmallest(Node* root, int k) {
        Node* c = root;
        int cnt = 0;
        while (c) {
            if (!c->left) {
                if (++cnt == k) return c->data;
                c = c->right;
            } else {
                Node* p = c->left;
                while (p->right && p->right != c) p = p->right;
                if (!p->right) {
                    p->right = c;
                    c = c->left;
                } else {
                    p->right = NULL;
                    if (++cnt == k) return c->data;
                    c = c->right;
                }
            }
        }
        return -1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear traversal of tree
* **Auxiliary Space:** 💾 O(1) - No extra space used

### ✅ **Why This Approach?**

* Space optimal with O(1) memory
* No recursion or stack needed
* Modifies tree temporarily but restores it

## 📊 **3️⃣ Augmented BST Approach**

### 💡 Algorithm Steps:

1. Count nodes in the left subtree for each recursive call.
2. Compare k with left subtree size to decide navigation direction.
3. If k equals left count + 1, current node is the answer.
4. If k is smaller, recurse to left subtree.
5. If k is larger, recurse to right subtree with adjusted k value.

```cpp
class Solution {
public:
    int kthSmallest(Node* root, int k) {
        if (!root) return -1;
        int lc = countNodes(root->left);
        if (k == lc + 1) return root->data;
        if (k <= lc) return kthSmallest(root->left, k);
        return kthSmallest(root->right, k - lc - 1);
    }
    
    int countNodes(Node* n) {
        return n ? 1 + countNodes(n->left) + countNodes(n->right) : 0;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Counting nodes takes linear time per call
* **Auxiliary Space:** 💾 O(h) - Recursion stack depth

### ✅ **Why This Approach?**

* Efficient for multiple queries on same tree
* Binary search style navigation
* Clear recursive logic

## 📊 **4️⃣ Reverse Inorder for Kth Largest**

### 💡 Algorithm Steps:

1. First count total nodes in the tree.
2. Convert kth smallest problem to (n-k+1)th largest.
3. Perform reverse inorder traversal (right-root-left).
4. Count nodes while traversing in descending order.
5. Return node when counter matches converted target.

```cpp
class Solution {
public:
    int kthSmallest(Node* root, int k) {
        int n = countNodes(root);
        int c = 0;
        return helper(root, c, n - k + 1);
    }
    
    int helper(Node* r, int& c, int k) {
        if (!r) return -1;
        int ri = helper(r->right, c, k);
        if (ri != -1) return ri;
        if (++c == k) return r->data;
        return helper(r->left, c, k);
    }
    
    int countNodes(Node* n) {
        return n ? 1 + countNodes(n->left) + countNodes(n->right) : 0;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Full tree traversal needed
* **Auxiliary Space:** 💾 O(h) - Recursion stack

### ✅ **Why This Approach?**

* Useful when kth largest queries are common
* Simple modification of standard pattern
* Easy to extend for range queries

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Iterative Stack**           | 🟢 O(k)                | 🟡 O(h)                 | 🚀 Stops early at kth element     | 💾 Stack space needed                |
| 🔍 **Morris Traversal**           | 🟡 O(n)                | 🟢 O(1)                 | ⭐ No extra space                 | 🔧 Temporarily modifies tree         |
| 📊 **Augmented BST**              | 🟡 O(n)                | 🟡 O(h)                 | 🎯 Efficient for multiple queries | 🐌 Counts nodes each time            |
| 🔄 **Reverse Inorder**            | 🟡 O(n)                | 🟡 O(h)                 | 📖 Simple variant                 | 🐌 Must traverse entire tree         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal time for small k**                       | 🥇 **Iterative Stack**               | ★★★★★                     |
| 📖 **Memory constrained**                             | 🥈 **Morris Traversal**              | ★★★★★                     |
| 🔧 **Multiple queries on same tree**                  | 🥉 **Augmented BST**                 | ★★★★☆                     |
| 🎯 **Interview standard**                             | 🏅 **Iterative Stack**               | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int kthSmallest(Node root, int k) {
        Stack<Node> s = new Stack<>();
        Node n = root;
        int c = 0;
        while (n != null || !s.isEmpty()) {
            while (n != null) {
                s.push(n);
                n = n.left;
            }
            n = s.pop();
            if (++c == k) return n.data;
            n = n.right;
        }
        return -1;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def kthSmallest(self, root, k): 
        s, n, c = [], root, 0
        while n or s:
            while n:
                s.append(n)
                n = n.left
            n = s.pop()
            c += 1
            if c == k: return n.data
            n = n.right
        return -1
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
