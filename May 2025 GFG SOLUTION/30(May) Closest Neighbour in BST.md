---
title: "🌳 Closest Neighbour in BST | GFG Solution 🧠"
keywords🏷️: ["🧩 binary search tree", "🌲 BST", "🤝 closest neighbour", "📉 floor value", "🔍 binary search", "📘 GFG", "🎯 coding interview", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Closest Neighbour in BST problem: find the greatest value ≤ k using BST properties. 🚀"
date: 📅 2025-05-30
---


# *30. Closest Neighbour in BST*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1)

## **🧩 Problem Description**

Given the root of a Binary Search Tree and a value `k`, find the **greatest node value** in the tree that is **less than or equal to** `k`. If no such node exists, return `-1`.


## **📘 Examples**

### Example 1
```

Input: root = [10,7,15,2,8,11,16], k = 14
```

<img src="https://github.com/user-attachments/assets/5f1630d5-f0f1-45d1-90c4-84478a0e565a" alt="Binary tree example for longest path sum" width="22%">

```
Output: 11
Explanation: The greatest element ≤ 14 is 11.

```

### Example 2
```

Input: root = [5,2,12,1,3,9,21,null,null,null,null,null,null,19,25], k = 24
```

<img src="https://github.com/user-attachments/assets/12f92c88-b5dd-438e-b299-da84f3429167" alt="Binary tree example for longest path sum" width="22%">

```
Output: 21
Explanation: The greatest element ≤ 24 is 21.

```

### Example 3
```

Input: root = [5,2,12,1,3,9,21,null,null,null,null,null,null,19,25], k = 4
```

<img src="https://github.com/user-attachments/assets/2986fbad-f9ba-412a-be0d-b2cbf9c1fd3a" alt="Binary tree example for longest path sum" width="22%">

```
Output: 3
Explanation: The greatest element ≤ 4 is 3.

````


## **🔒 Constraints**

* Number of nodes \(N\): $\(1 \le N \le 10^5\)$  
* Node values and \(k\): $\(1 \le \text{data}, k \le 10^5\)$  
* All node values are **unique**  


## **✅ My Approach**

### **Iterative BST Floor Search**

1. **Idea:**  
   * Leverage BST property: left subtree < node < right subtree.  
   * Keep a variable `res = -1`.  
   * Start at the root and traverse:
     - If `node->data == k`, it's the best possible floor → return `k`.
     - If `node->data < k`, record `res = node->data` and move **right** to look for a closer larger value ≤ k.
     - If `node->data > k`, move **left** to find smaller values.
2. **Why It Works:**  
   * Each step eliminates half of the tree, guaranteeing we never miss a closer candidate.
3. **Answer:**  
   * After the loop, `res` holds the greatest value ≤ k, or `-1` if none found.


## 📝 **Expected Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(H), where H = height of the tree, since we traverse at most one path down the BST.  
* **Expected Auxiliary Space Complexity:** O(1), as only a few variables are used.


## **🧑‍💻 Code (C++)**

```cpp
class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        int res = -1;
        while (root) {
            if (root->data == k) return k;
            if (root->data < k) {
                res = root->data;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return res;
    }
};
````

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>


## 📊 **2️⃣ Recursive DFS**

### 💡 Algorithm Steps:

1. If `root` is `null`, return `-1`.
2. If `root->data == k`, return `k`.
3. If `root->data < k`, recursively search in **right** subtree:

   ```cpp
   int x = findMaxFork(root->right, k);
   return (x == -1 ? root->data : x);
   ```
4. Else (value > k), search **left** subtree.

```cpp
class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        if (!root) return -1;
        if (root->data == k) return k;
        if (root->data < k) {
            int x = findMaxFork(root->right, k);
            return x == -1 ? root->data : x;
        }
        return findMaxFork(root->left, k);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** 🟢 O(H)
* **Auxiliary Space:** 🔸 O(H) due to recursion stack

### ✅ **Why This Approach?**

* Very concise and mirrors the BST property naturally.
* Easy to implement if recursion is preferred.


## 📊 **3️⃣ In-order Traversal with Early Exit**

### 💡 Algorithm Steps:

1. Initialize `res = -1`.
2. Perform **in-order** (sorted) traversal:

   * Recurse on left child.
   * If `node->data > k`, **stop** traversal (all further nodes are larger).
   * Else update `res = node->data` and recurse on right child.
3. Return `res`.

```cpp
class Solution {
  public:
    int res;
    void inorder(Node* node, int k) {
        if (!node) return;
        inorder(node->left, k);
        if (node->data > k) return;
        res = node->data;
        inorder(node->right, k);
    }
    int findMaxFork(Node* root, int k) {
        res = -1;
        inorder(root, k);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** 🟡 O(N) worst-case (skewed BST)
* **Auxiliary Space:** 🔸 O(H)

### ✅ **Why This Approach?**

* Utilizes sorted nature to stop early once values exceed `k`.
* Useful if you also need an ordered list of all values ≤ k.


## 🆚 **Comparison of Approaches**

| **Approach**             | ⏱️ **Time**   | 🗂️ **Auxiliary Space** | ✅ **Pros**                          | ⚠️ **Cons**                        |
| ------------------------ | ------------- | ----------------------- | ----------------------------------- | ---------------------------------- |
| 🔁 Iterative Traversal   | 🟢 O(H)       | 🟢 O(1)                 | Stack-safe, minimal memory          | —                                  |
| 🧠 Recursive DFS         | 🟢 O(H)       | 🔸 O(H)                 | Clear recursive logic               | Recursion depth risk               |
| 📋 In-order + Early Exit | 🟡 O(N) worst | 🔸 O(H)                 | Leverages sorted order, early break | May traverse many nodes if k large |

### ✅ **Best Choice?**

| **Scenario**                      | **Recommended Approach** |
| --------------------------------- | ------------------------ |
| ⚡ Performance & minimal memory    | 🥇 Iterative Traversal   |
| 🧵 Clear, direct BST logic        | 🥈 Recursive DFS         |
| 📋 Need sorted list of ≤ k values | 🥉 In-order Traversal    |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int findMaxFork(Node root, int k) {
        int res = -1;
        while (root != null) {
            if (root.data == k) return k;
            if (root.data < k) {
                res = root.data;
                root = root.right;
            } else {
                root = root.left;
            }
        }
        return res;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def findMaxFork(self, root, k):
        res = -1
        while root:
            if root.data == k:
                return k
            if root.data < k:
                res = root.data
                root = root.right
            else:
                root = root.left
        return res
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

