---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Tree
  - Binary Search Tree
---

# 🚀 _Day 11. k-th Smallest in BST_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/find-k-th-smallest-element-in-bst)

## 💡 **Problem Description:**

Given a **Binary Search Tree (BST)** and an integer **k**, the task is to find the **k-th smallest element** in the BST.  
If there is **no k-th smallest element** present, return `-1`.

## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**

```
        2
       / \
      1   3
k = 2
```

<img src="https://github.com/user-attachments/assets/1fe38e2a-319a-4341-8e86-ce6a684e8c05" width="30%">

#### **Output:**

```
2
```

#### **Explanation:**

The elements in ascending order are `[1, 2, 3]`. The 2nd smallest element is `2`.

### **Example 2:**

#### **Input:**

```
        2
       / \
      1   3
k = 5
```

<img src="https://github.com/user-attachments/assets/29a82ac1-c034-409c-b613-974c78334f0d" width="30%">

#### **Output:**

```
-1
```

#### **Explanation:**

The BST contains only 3 elements. Hence, there is **no 5th smallest element**.

### **Example 3:**

#### **Input:**

```
            20
           /  \
          8    22
         / \
        4   12
           /  \
         10   14
k = 3
```

<img src="https://github.com/user-attachments/assets/9d1a42b6-beee-4b2d-9125-575094385d0c" width="30%">

#### **Output:**

```
10
```

#### **Explanation:**

The in-order traversal of the BST is `[4, 8, 10, 12, 14, 20, 22]`.  
The 3rd smallest element is `10`.

## **Constraints:**

- 1 ≤ number of nodes, k ≤ $10^5$
- 1 ≤ node->data ≤ $10^5$

## 🎯 **My Approach:**

### **Morris Inorder Traversal (O(1) Space)**

- **Morris Traversal** allows in-order traversal without using a stack or recursion, thus achieving **O(1) space complexity**.
- It temporarily modifies the tree structure but restores it before completion.

#### **Algorithm Steps:**

1. Start from the root node.
2. If the left child is `NULL`:
   - **Visit the current node** (decrement `k`).
   - If `k == 0`, return the current node's value.
   - Move to the right child.
3. If the left child exists:
   - Find the **rightmost node** in the left subtree (inorder predecessor).
   - If the rightmost node's right is `NULL`:
     - Make the current node its right child (create a temporary thread).
     - Move to the left child.
   - If the rightmost node’s right is the current node (thread exists):
     - Remove the thread (restore the original tree).
     - **Visit the current node** (decrement `k`).
     - If `k == 0`, return the current node's value.
     - Move to the right child.
4. If the traversal completes without finding the k-th smallest, return `-1`.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(N)` We visit each node exactly twice (once to create a thread and once to remove it), which is linear with respect to the number of nodes.

- **Expected Auxiliary Space Complexity:** `O(1)` No additional stack or recursion is used. Only a few pointers are manipulated.

## 📝 **Solution Code**

## Code (C)

```c
int kthSmallest(struct Node* root, int k) {
    while (root) {
        if (!root->left) {
            if (--k == 0) return root->data;
            root = root->right;
        } else {
            struct Node *pre = root->left;
            while (pre->right && pre->right != root) pre = pre->right;
            if (!pre->right) {
                pre->right = root;
                root = root->left;
            } else {
                pre->right = NULL;
                if (--k == 0) return root->data;
                root = root->right;
            }
        }
    }
    return -1;
}
```

## Code (C++)

```cpp
class Solution {
  public:
    int kthSmallest(Node* root, int k) {
        while (root) {
            if (!root->left) {
                if (--k == 0) return root->data;
                root = root->right;
            } else {
                Node* pre = root->left;
                while (pre->right && pre->right != root) pre = pre->right;
                if (!pre->right) {
                    pre->right = root;
                    root = root->left;
                } else {
                    pre->right = NULL;
                    if (--k == 0) return root->data;
                    root = root->right;
                }
            }
        }
        return -1;
    }
};
```

<details>
  <summary><h2 align="center">🌲 Alternative Approaches</h2></summary>

## **2️⃣ Recursive Inorder Traversal**

```cpp
class Solution {
public:
    int kthSmallest(Node* root, int &k) {
        if (!root) return -1;
        int left = kthSmallest(root->left, k);
        if (k == 0) return left;
        if (--k == 0) return root->data;
        return kthSmallest(root->right, k);
    }
};
```

🔹 **Optimized by using `k` as a reference, reducing redundant calculations.**

## **3️⃣ Iterative Inorder Traversal (Using Stack)**

```cpp
class Solution {
public:
    int kthSmallest(Node* root, int k) {
        if (!root) return -1;
        stack<Node*> st;
        while (true) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            if (st.empty()) return -1;
            root = st.top(); st.pop();
            if (--k == 0) return root->data;
            root = root->right;
        }
    }
};
```

🔹 **Handles larger trees efficiently without recursion depth issues.**

## **Comparison of Approaches**

| **Approaches**                   | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ⚡ **Method**  | ✅ **Pros**                   | ⚠️ **Cons**                 |
| -------------------------------- | ---------------------- | ----------------------- | -------------- | ----------------------------- | --------------------------- |
| **Morris Traversal (Optimized)** | 🟢 `O(N)`              | 🟢 `O(1)`               | No extra space | No extra space used           | Modifies tree temporarily   |
| **Recursive Inorder**            | 🟢 `O(N)`              | 🟡 `O(H)`               | Recursion      | Simple and concise            | Stack space for recursion   |
| **Iterative Inorder (Stack)**    | 🟢 `O(H + K)`          | 🟡 `O(H)`               | Stack-based    | Avoids recursion depth issues | Uses extra memory for stack |

## 💡 **Best Choice?**

- **For space efficiency:** ✅ Morris Traversal (`O(1)` space).
- **For simplicity:** ✅ Recursive Inorder Traversal is intuitive.
- **For large/deep trees:** ✅ Iterative Inorder Traversal (Stack) avoids recursion depth issues.

</details>

## Code (Java)

```java
class Solution {
    public int kthSmallest(Node root, int k) {
        while (root != null) {
            if (root.left == null) {
                if (--k == 0) return root.data;
                root = root.right;
            } else {
                Node pre = root.left;
                while (pre.right != null && pre.right != root) pre = pre.right;
                if (pre.right == null) {
                    pre.right = root;
                    root = root.left;
                } else {
                    pre.right = null;
                    if (--k == 0) return root.data;
                    root = root.right;
                }
            }
        }
        return -1;
    }
}
```

## Code (Python)

```python
class Solution:
    def kthSmallest(self, root, k):
        while root:
            if not root.left:
                k -= 1
                if k == 0:
                    return root.data
                root = root.right
            else:
                pre = root.left
                while pre.right and pre.right != root:
                    pre = pre.right
                if not pre.right:
                    pre.right = root
                    root = root.left
                else:
                    pre.right = None
                    k -= 1
                    if k == 0:
                        return root.data
                    root = root.right
        return -1
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
