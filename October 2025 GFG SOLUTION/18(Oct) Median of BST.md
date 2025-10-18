---
title: "🌳 Median of BST | GFG Solution 🔍"
keywords🏷️: ["🌳 binary search tree", "🔍 morris traversal", "📍 inorder traversal", "📈 median finding", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Median of BST problem: find median element in a BST using space-efficient Morris Traversal technique without recursion or stack. 🚀"
date: 📅 2025-10-18
---

# *18. Median of BST*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/median-of-bst/1)

## **🧩 Problem Description**

You are given the root of a **Binary Search Tree (BST)**. Your task is to find the **median** of the BST.

When the nodes of the BST are written in ascending order (inorder traversal) as V₁, V₂, V₃, …, Vₙ, where n is the total number of nodes:

- **If n is odd:** return V₍ₙ₊₁₎/₂
- **If n is even:** return Vₙ/₂

## **📘 Examples**

### Example 1

```cpp
Input: root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14]
Output: 12
Explanation: The inorder of given BST is 4, 8, 10, 12, 14, 20, 22. 
Here, n = 7 (odd), so median will be ((7+1)/2)th value = 4th value = 12.
```

### Example 2

```cpp
Input: root = [5, 4, 8, 1]
Output: 4
Explanation: The inorder of given BST is 1, 4, 5, 8. 
Here, n = 4 (even), so median will be (4/2)th value = 2nd value = 4.
```

## **🔒 Constraints**

* $1 \le \text{number of nodes} \le 10^5$
* $1 \le \text{node.data} \le 10^5$

## **✅ My Approach**

The optimal approach uses **Morris Traversal** - a space-efficient method that performs inorder traversal without using recursion or stack:

### **Morris Traversal Technique**

1. **First Pass - Count Total Nodes:**
   * Traverse the tree using Morris Traversal algorithm.
   * Count all nodes while traversing without using extra space.
   * Morris Traversal temporarily modifies tree structure to create threading.

2. **Calculate Median Position:**
   * Based on total count `n`, calculate median index `k = (n + 1) / 2`.
   * This formula works for both odd and even number of nodes.

3. **Second Pass - Find Median:**
   * Perform Morris Traversal again to reach the kth element.
   * Track current position during traversal.
   * Return the value when position matches median index.

4. **Morris Traversal Details:**
   * For each node, if left child doesn't exist, visit node and move right.
   * If left child exists, find inorder predecessor (rightmost node in left subtree).
   * Create temporary thread from predecessor to current node.
   * Follow the thread and break it after visiting to restore tree structure.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of nodes in the BST. Morris Traversal visits each edge at most twice - once to create the thread and once to traverse it, resulting in O(n) operations overall despite appearing to have nested loops.
* **Expected Auxiliary Space Complexity:** O(1), as Morris Traversal uses only a constant amount of extra space (a few pointers) and doesn't require recursion stack or auxiliary data structures. The tree structure is temporarily modified but restored during traversal.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int findMedian(Node* root) {
        int n = 0, k = 0, med = -1;
        Node* c = root;
        while (c) {
            if (!c->left) { n++; c = c->right; }
            else {
                Node* p = c->left;
                while (p->right && p->right != c) p = p->right;
                if (!p->right) { p->right = c; c = c->left; }
                else { p->right = nullptr; n++; c = c->right; }
            }
        }
        k = (n + 1) / 2;
        c = root;
        while (c) {
            if (!c->left) {
                if (++med == k - 1) return c->data;
                c = c->right;
            } else {
                Node* p = c->left;
                while (p->right && p->right != c) p = p->right;
                if (!p->right) { p->right = c; c = c->left; }
                else {
                    p->right = nullptr;
                    if (++med == k - 1) return c->data;
                    c = c->right;
                }
            }
        }
        return -1;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Inorder Array Storage**

### 💡 Algorithm Steps:

1. Perform inorder traversal to collect all node values in sorted order.
2. Store values in a vector during traversal.
3. Calculate median index based on total count.
4. Return the element at median position from the stored array.

```cpp
class Solution {
public:
    void inorder(Node* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    int findMedian(Node* root) {
        vector<int> v;
        inorder(root, v);
        return v[(v.size() - 1) / 2];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single traversal of all nodes
* **Auxiliary Space:** 💾 O(n) - Storage for all node values

### ✅ **Why This Approach?**

* Simple recursive implementation
* Easy to understand and debug
* Natural fit for BST inorder traversal

## 📊 **3️⃣ Kth Smallest Element**

### 💡 Algorithm Steps:

1. Count total nodes using recursive traversal.
2. Calculate median position as kth smallest element.
3. Perform inorder traversal with counter.
4. Return value when counter matches median position.

```cpp
class Solution {
public:
    int countNodes(Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    void findKth(Node* root, int& k, int& res) {
        if (!root || k == 0) return;
        findKth(root->left, k, res);
        if (--k == 0) res = root->data;
        findKth(root->right, k, res);
    }
    int findMedian(Node* root) {
        int n = countNodes(root);
        int k = (n + 1) / 2, res = -1;
        findKth(root, k, res);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Two passes through tree
* **Auxiliary Space:** 💾 O(h) - Recursion stack space where h is height

### ✅ **Why This Approach?**

* Clean separation of counting and finding logic
* Uses recursion which is natural for trees
* Stack space proportional to tree height not node count

## 📊 **4️⃣ Single Pass with Stack**

### 💡 Algorithm Steps:

1. Use iterative inorder traversal with explicit stack.
2. Count nodes during first pass through tree.
3. Reset and perform second pass to find median.
4. Track position counter and return at median index.

```cpp
class Solution {
public:
    int findMedian(Node* root) {
        stack<Node*> st;
        Node* c = root;
        int cnt = 0;
        while (c || !st.empty()) {
            while (c) { st.push(c); c = c->left; }
            c = st.top(); st.pop();
            cnt++;
            c = c->right;
        }
        int k = (cnt + 1) / 2;
        c = root; cnt = 0;
        while (c || !st.empty()) {
            while (c) { st.push(c); c = c->left; }
            c = st.top(); st.pop();
            if (++cnt == k) return c->data;
            c = c->right;
        }
        return -1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Two complete traversals
* **Auxiliary Space:** 💾 O(h) - Stack space for tree height

### ✅ **Why This Approach?**

* Iterative approach avoids recursion overhead
* Explicit stack gives more control over traversal
* Good for environments with limited stack depth

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Morris Traversal**           | 🟢 O(n)                | 🟢 O(1)                 | 🚀 No extra space needed          | 🔧 Temporarily modifies tree          |
| 🔍 **Array Storage**               | 🟢 O(n)                | 🟡 O(n)                 | 📖 Simple and clear               | 💾 Stores all values                  |
| 📊 **Kth Smallest**                | 🟢 O(n)                | 🟢 O(h)                 | 🎯 Natural recursion              | 🔄 Two separate passes                |
| 🔄 **Stack Iteration**             | 🟢 O(n)                | 🟢 O(h)                 | ⭐ No recursion limit             | 🐌 Two complete traversals            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Memory constrained systems**                     | 🥇 **Morris Traversal**              | ★★★★★                     |
| 📖 **Quick implementation**                           | 🥈 **Array Storage**                 | ★★★★☆                     |
| 🔧 **Recursive preference**                           | 🥉 **Kth Smallest**                  | ★★★★☆                     |
| 🎯 **Deep trees**                                     | 🏅 **Stack Iteration**               | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int findMedian(Node root) {
        int n = 0, k = 0, med = -1;
        Node c = root;
        while (c != null) {
            if (c.left == null) { n++; c = c.right; }
            else {
                Node p = c.left;
                while (p.right != null && p.right != c) p = p.right;
                if (p.right == null) { p.right = c; c = c.left; }
                else { p.right = null; n++; c = c.right; }
            }
        }
        k = (n + 1) / 2;
        c = root;
        while (c != null) {
            if (c.left == null) {
                if (++med == k - 1) return c.data;
                c = c.right;
            } else {
                Node p = c.left;
                while (p.right != null && p.right != c) p = p.right;
                if (p.right == null) { p.right = c; c = c.left; }
                else {
                    p.right = null;
                    if (++med == k - 1) return c.data;
                    c = c.right;
                }
            }
        }
        return -1;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def findMedian(self, root):
        n, c = 0, root
        while c:
            if not c.left:
                n += 1
                c = c.right
            else:
                p = c.left
                while p.right and p.right != c:
                    p = p.right
                if not p.right:
                    p.right = c
                    c = c.left
                else:
                    p.right = None
                    n += 1
                    c = c.right
        k, med, c = (n + 1) // 2, -1, root
        while c:
            if not c.left:
                med += 1
                if med == k - 1:
                    return c.data
                c = c.right
            else:
                p = c.left
                while p.right and p.right != c:
                    p = p.right
                if not p.right:
                    p.right = c
                    c = c.left
                else:
                    p.right = None
                    med += 1
                    if med == k - 1:
                        return c.data
                    c = c.right
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
