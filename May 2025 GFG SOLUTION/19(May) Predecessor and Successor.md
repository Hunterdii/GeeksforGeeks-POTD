# *19. Predecessor and Successor*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/predecessor-and-successor/1)


## **🧩 Problem Description**

Given the root of a Binary Search Tree (BST) and an integer key, find the inorder predecessor and successor of the key in the BST.

* The **predecessor** is the largest value in the BST smaller than the key.
* The **successor** is the smallest value in the BST larger than the key.
* If predecessor or successor does not exist, return `NULL`.

### **Example 1:**

**Input:**
`root = [8, 1, 9, N, 4, N, 10, 3, N, N, N], key = 8`

<img src="https://github.com/user-attachments/assets/f8dcc4c4-0cac-4f23-a203-665bde8f1352" width="30%">


**Output:**
`4 9`

**Explanation:**
The inorder predecessor of 8 is 4, and the inorder successor is 9.

### **Example 2:**

**Input:**
`root = [10, 2, 11, 1, 5, N, N, N, N, 3, 6, N, 4, N, N], key = 11`

<img src="https://github.com/user-attachments/assets/204dd524-f03e-41d6-983e-9db2718d1650" width="30%">


**Output:**
`10 -1`

**Explanation:**
The inorder predecessor of 11 is 10, and successor does not exist.

### **Example 3:**

**Input:**
`root = [2, 1, 3], key = 3`

<img src="https://github.com/user-attachments/assets/894d634e-0ec6-4472-bd46-8e86ca7bfd71" width="30%">


**Output:**
`2 -1`

**Explanation:**
The inorder predecessor of 3 is 2, and successor does not exist.

## **🔒 Constraints**

* \$1 \leq \text{Number of Nodes} \leq 10^4\$
* $1 <= node->data <= 10^6$
* \$1 \leq \text{Key Value} \leq 10^5\$


## **✅ My Approach**

### **Iterative BST Search Using BST Properties**

The BST property allows us to find predecessor and successor without full traversal:

* **Predecessor:** The last node encountered with value less than `key` during a search down the tree.
* **Successor:** The last node encountered with value greater than `key` during a search down the tree.

### **Algorithm Steps:**

1. Initialize two pointers: `pre` and `suc` to `nullptr`.
2. To find predecessor:

   * Start from root.
   * Move right if current node's value `< key`, update `pre` to current node.
   * Else move left.
3. To find successor:

   * Start from root.
   * Move left if current node's value `> key`, update `suc` to current node.
   * Else move right.
4. Return the pair `{pre, suc}`.

This approach leverages BST ordering and runs in time proportional to the height of the tree, typically O(log N) for balanced BSTs.

## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(h), where `h` is the height of the BST, as each search for predecessor and successor traverses at most from root to leaf.
* **Expected Auxiliary Space Complexity:** O(1), as we use only a fixed number of pointers and no extra data structures.


## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node *pre = nullptr, *suc = nullptr;
        Node* curr = root;
        while (curr) {
            if (curr->data < key) {
                pre = curr;
                curr = curr->right;
            } else curr = curr->left;
        }
        curr = root;
        while (curr) {
            if (curr->data > key) {
                suc = curr;
                curr = curr->left;
            } else curr = curr->right;
        }
        return {pre, suc};
    }
};
```


<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Recursive Traversal Method**

### **Algorithm Steps:**

1. Initialize `pre` and `suc` to `nullptr`.
2. Recursively traverse the BST:

   * If `node->data == key`:

     * Go to the **rightmost** node in left subtree for predecessor.
     * Go to the **leftmost** node in right subtree for successor.
   * If `node->data < key`: update `pre` and move right.
   * If `node->data > key`: update `suc` and move left.

```cpp
class Solution {
  void find(Node* root, Node*& pre, Node*& suc, int key) {
    if (!root) return;
    if (root->data == key) {
        Node* l = root->left;
        while (l) pre = l, l = l->right;
        Node* r = root->right;
        while (r) suc = r, r = r->left;
    } else if (root->data > key) {
        suc = root;
        find(root->left, pre, suc, key);
    } else {
        pre = root;
        find(root->right, pre, suc, key);
    }
  }

  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node *pre = nullptr, *suc = nullptr;
        find(root, pre, suc, key);
        return {pre, suc};
    }
};
```

### ✅ **Why This Approach?**

* Easy to implement and reason about.
* Handles edge cases (node with given key exists) clearly.

#### 📝 **Complexity Analysis:**

* **Time:** 🔸 O(h)
* **Auxiliary Space:** 🔸 O(h) (recursion stack)


## 📊 **3️⃣ Inorder Traversal + Linear Scan**

### **Algorithm Steps:**

1. Perform **inorder traversal** and store nodes in a vector.
2. Scan through vector:

   * Last node with value `< key` → predecessor.
   * First node with value `> key` → successor.

```cpp
class Solution {
  void inorder(Node* root, vector<Node*>& nodes) {
    if (!root) return;
    inorder(root->left, nodes);
    nodes.push_back(root);
    inorder(root->right, nodes);
  }

  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> nodes;
        inorder(root, nodes);
        Node *pre = nullptr, *suc = nullptr;
        for (Node* node : nodes) {
            if (node->data < key) pre = node;
            else if (node->data > key) {
                suc = node;
                break;
            }
        }
        return {pre, suc};
    }
};
```

### ✅ **Why This Approach?**

* Very intuitive.
* Allows easy post-processing or reuse of full traversal data.

#### 📝 **Complexity Analysis:**

* **Time:** 🔸 O(N)
* **Auxiliary Space:** 🔸 O(N)


## 📊 **4️⃣ Morris Inorder Traversal (O(1) Space)**

### **Algorithm Steps:**

1. Use **Morris traversal** to visit nodes in-order **without recursion or stack**.
2. While visiting:

   * Keep track of last node `< key` as predecessor.
   * First node `> key` becomes successor.

```cpp
class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node *pre = nullptr, *suc = nullptr, *curr = root;

        while (curr) {
            if (!curr->left) {
                if (curr->data < key) pre = curr;
                else if (curr->data > key && !suc) suc = curr;
                curr = curr->right;
            } else {
                Node* pred = curr->left;
                while (pred->right && pred->right != curr)
                    pred = pred->right;

                if (!pred->right) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = nullptr;
                    if (curr->data < key) pre = curr;
                    else if (curr->data > key && !suc) suc = curr;
                    curr = curr->right;
                }
            }
        }

        return {pre, suc};
    }
};
```

### ✅ **Why This Approach?**

* Best when minimizing auxiliary space is required.
* No stack or recursion—constant space.

#### 📝 **Complexity Analysis:**

* **Time:** 🔸 O(N)
* **Auxiliary Space:** 🟢 O(1)


## 🆚 Comparison


| **Approach**          | ⏱️ **Time** | 🗂️ **Space** | ✅ **Pros**                      | ⚠️ **Cons**                          |
| --------------------- | ----------- | ------------- | ------------------------------- | ------------------------------------ |
| Iterative BST Walk    | 🟢 O(h)     | 🟢 O(1)       | Fastest and clean               | Doesn’t handle exact-key node logic  |
| Recursive Traversal   | 🟢 O(h)     | 🔸 O(h)       | Handles key match subtree logic | Extra space from recursion           |
| Inorder + Linear Scan | 🔸 O(N)     | 🔸 O(N)       | Simple to code                  | Inefficient for large balanced trees |
| Morris Traversal      | 🔸 O(N)     | 🟢 O(1)       | True constant-space             | Trickier to implement                |


### ✅ **Best Choice by Scenario**

| **Scenario**                       | **Recommended Approach** |
| ---------------------------------- | ------------------------ |
| 🚀 Time-efficient & minimal memory | 🥇 Iterative BST Walk    |
| 🎯 Need to handle exact key logic  | 🥈 Recursive Traversal   |
| 📊 Want to reuse full inorder list | 🥉 Inorder + Linear Scan |
| 💡 Memory-constrained environment  | 🏅 Morris Traversal      |


</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public ArrayList<Node> findPreSuc(Node root, int key) {
        Node pre = null, suc = null, curr = root;
        while (curr != null) {
            if (curr.data < key) {
                pre = curr;
                curr = curr.right;
            } else {
                curr = curr.left;
            }
        }
        curr = root;
        while (curr != null) {
            if (curr.data > key) {
                suc = curr;
                curr = curr.left;
            } else {
                curr = curr.right;
            }
        }
        ArrayList<Node> res = new ArrayList<>();
        res.add(pre);
        res.add(suc);
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def findPreSuc(self, root, key):
        pre = suc = None
        curr = root
        while curr:
            if curr.data < key:
                pre = curr
                curr = curr.right
            else:
                curr = curr.left
        curr = root
        while curr:
            if curr.data > key:
                suc = curr
                curr = curr.left
            else:
                curr = curr.right
        return [pre, suc]
```


## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

--- 

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
