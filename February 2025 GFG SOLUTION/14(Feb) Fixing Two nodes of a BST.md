# _14. Fixing Two nodes of a BST_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/fixed-two-nodes-of-a-bst)

## **Problem Description**

Given the root of a **Binary Search Tree (BST)**, where exactly **two nodes were swapped** by mistake, your task is to **fix (or correct) the BST** by swapping them back. The **structure of the tree should not change**.

## **Examples**

### **Example 1:**

#### **Input:**

```
        10
       /  \
      5    8
     /  \
    2    20
```

<img src="https://github.com/user-attachments/assets/b3a4854c-a13c-49a4-89ec-f21dd98fbade" width="30%">

#### **Output:**

```
1
```

<img src="https://github.com/user-attachments/assets/eec53814-0d5d-4047-b24c-f4be44041eb7" width="30%">

#### **Explanation:**

The nodes **20 and 8** were swapped by mistake. After swapping them back, the BST is restored correctly.

### **Example 2:**

#### **Input:**

```
        5
       / \
     10   20
     / \
    2   8
```

<img src="https://github.com/user-attachments/assets/de261078-d5c2-4412-ae17-8afb5cf71937" width="30%">

#### **Output:**

```
1
```

<img src="https://github.com/user-attachments/assets/6f588971-07ab-4702-8e1b-4756ba0123a4" width="30%">

#### **Explanation:**

The nodes **10 and 5** were swapped by mistake. After swapping them back, the BST is restored correctly.

### **Constraints:**

- $\(1 \leq \text{Number of Nodes} \leq 10^3\)$

## **My Approach**

### **Optimized Inorder Traversal (`O(N)` Time, `O(H)` Space)**

1. **Use an inorder traversal** to detect swapped nodes in the BST.
2. **Identify the two misplaced nodes:**
   - If a node appears **larger than the next node**, it's incorrectly placed.
   - Track the **first misplaced node** and the **second misplaced node**.
3. **Swap the values of the two misplaced nodes** to restore the BST.

### **Algorithm Steps:**

1. **Perform an inorder traversal** to find the two misplaced nodes.
2. If the first misplaced node is found, store it in `first`.
3. If a second misplaced node is found later, store it in `last`.
4. If there's no second misplaced node, use the `middle` node instead.
5. **Swap the values** of the two misplaced nodes.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(N)`, since we traverse each node once.
- **Expected Auxiliary Space Complexity:** `O(H)`, due to the recursion stack in the inorder traversal.

## **Code (C++)**

```cpp
class Solution {
public:
    void correctBST(Node* root) {
        Node *first = nullptr, *middle = nullptr, *last = nullptr, *prev = nullptr;
        function<void(Node*)> inorder = [&](Node* node) {
            if (!node) return;
            inorder(node->left);
            if (prev && node->data < prev->data) {
                if (!first) first = prev, middle = node;
                else last = node;
            }
            prev = node;
            inorder(node->right);
        };
        inorder(root);
        swap(first->data, last ? last->data : middle->data);
    }
};
```

<details>
  <summary><h2 align="center">🌲 Alternative Approaches</h2></summary>

## **2️⃣ Iterative Inorder Traversal (Stack)**

### **Approach**

1. **Use a stack for inorder traversal** (instead of recursion).
2. **Detect swapped nodes** by checking the inorder order.
3. **Swap the incorrect nodes back** to restore the BST.

```cpp
class Solution {
public:
    void correctBST(Node* root) {
        stack<Node*> st;
        Node *first = nullptr, *middle = nullptr, *last = nullptr, *prev = nullptr;

        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            if (prev && root->data < prev->data) {
                if (!first) first = prev, middle = root;
                else last = root;
            }
            prev = root;
            root = root->right;
        }

        swap(first->data, last ? last->data : middle->data);
    }
};
```

🔹 **Avoids recursion stack overflow issues using an explicit stack.**

## **3️⃣ Morris Traversal (`O(1)` Space)**

### **Approach**

1. **Use Morris Traversal** to perform an **inorder traversal without extra space**.
2. **Identify misplaced nodes** while modifying the BST structure temporarily.
3. **Restore the BST by swapping the misplaced nodes.**

```cpp
class Solution {
public:
    void correctBST(Node* root) {
        Node *first = nullptr, *middle = nullptr, *last = nullptr, *prev = nullptr;

        while (root) {
            if (!root->left) {
                if (prev && root->data < prev->data) {
                    if (!first) first = prev, middle = root;
                    else last = root;
                }
                prev = root;
                root = root->right;
            } else {
                Node* pre = root->left;
                while (pre->right && pre->right != root) pre = pre->right;
                if (!pre->right) {
                    pre->right = root;
                    root = root->left;
                } else {
                    pre->right = nullptr;
                    if (prev && root->data < prev->data) {
                        if (!first) first = prev, middle = root;
                        else last = root;
                    }
                    prev = root;
                    root = root->right;
                }
            }
        }
        swap(first->data, last ? last->data : middle->data);
    }
};
```

🔹 **Uses `O(1)` space without recursion or extra stack.**

## **Comparison of Approaches**

| **Approach**          | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ⚡ **Method**  | ✅ **Pros**                   | ⚠️ **Cons**                 |
| --------------------- | ---------------------- | ----------------------- | -------------- | ----------------------------- | --------------------------- |
| **Recursive Inorder** | 🟢 `O(N)`              | 🟡 `O(H)`               | Recursion      | Simple and easy to implement  | Uses recursion stack space  |
| **Iterative Inorder** | 🟢 `O(N)`              | 🟡 `O(H)`               | Stack-based    | Avoids recursion depth issues | Uses extra memory for stack |
| **Morris Traversal**  | 🟢 `O(N)`              | 🟢 `O(1)`               | No extra space | No additional memory needed   | Modifies tree temporarily   |

## 💡 **Best Choice?**

- ✅ **For space efficiency:** Morris Traversal (`O(1)` space).
- ✅ **For simplicity:** Recursive Inorder Traversal.
- ✅ **For large trees:** Iterative Inorder Traversal avoids recursion depth issues.

</details>

## **Code (Java)**

```java
class Solution {
    Node first, middle, last, prev;

    void inorder(Node root) {
        if (root == null) return;
        inorder(root.left);
        if (prev != null && root.data < prev.data) {
            if (first == null) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;
        inorder(root.right);
    }

    void correctBST(Node root) {
        first = middle = last = prev = null;
        inorder(root);
        int temp = first.data;
        first.data = (last != null) ? last.data : middle.data;
        if (last != null) last.data = temp;
        else middle.data = temp;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def correctBST(self, root):
        self.first = self.middle = self.last = self.prev = None

        def inorder(node):
            if not node:
                return
            inorder(node.left)
            if self.prev and node.data < self.prev.data:
                if not self.first:
                    self.first, self.middle = self.prev, node
                else:
                    self.last = node
            self.prev = node
            inorder(node.right)

        inorder(root)
        self.first.data, (self.last or self.middle).data = (self.last or self.middle).data, self.first.data
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
