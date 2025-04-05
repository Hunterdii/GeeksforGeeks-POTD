---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Tree
---

# 🚀 _Day 15. Serialize and deserialize a binary tree_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/serialize-and-deserialize-a-binary-tree)

## 💡 **Problem Description:**

Serialization is the process of converting a **binary tree** into an **array** so it can be stored or transmitted efficiently.  
Deserialization is the process of **reconstructing the tree** back from the serialized array.

Your task is to **implement** the following functions:

1. **serialize()**: Stores the tree into an array and returns the array.
2. **deSerialize()**: Restores the tree from the array and returns the root.

**Note:**

- Multiple nodes can have the **same data values**.
- Node values are **always positive integers**.
- The **in-order traversal** of the tree returned by `deSerialize(serialize(root))` should match the in-order traversal of the input tree.

## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**

Binary Tree:

```
    1
   / \
  2   3
```

<img src="https://github.com/user-attachments/assets/595020dc-c2c6-491d-a6b6-c4aef40b2419" width="30%">

#### **Output:**

Inorder Traversal of Deserialized Tree: `[2, 1, 3]`

### **Example 2:**

#### **Input:**

Binary Tree:

```
        10
       /  \
      20   30
     /  \
    40  60
```

<img src="https://github.com/user-attachments/assets/266a65d7-34bb-4f49-a50c-d60ce22e5bf2" width="30%">

#### **Output:**

Inorder Traversal of Deserialized Tree: `[40, 20, 60, 10, 30]`

### **Constraints:**

- $\(1 \leq \text{Number of Nodes} \leq 10^4\)$
- $\(1 \leq \text{Data of a Node} \leq 10^9\)$

## 🎯 **My Approach:**

### **Recursive Preorder Traversal**

1. **Serialize:**

   - Perform **preorder traversal**.
   - Store each node’s value.
   - If a node is `NULL`, store `-1` to indicate missing nodes.

2. **Deserialize:**
   - Read values from the serialized list.
   - Construct nodes recursively.
   - When `-1` is encountered, return `NULL`.

### **Algorithm Steps:**

1. **Serialization:**

   - Traverse the tree using **preorder** (Root → Left → Right).
   - Store `-1` for **NULL** nodes.
   - Append each node’s value to a list.

2. **Deserialization:**
   - Read values one by one.
   - If a value is `-1`, return `NULL`.
   - Otherwise, create a new node and recursively set left and right children.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N), since we traverse each node once.
- **Expected Auxiliary Space Complexity:** O(N), due to storing the entire tree structure in a list.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
  public:
    void serializeUtil(Node *root, vector<int> &a) {
        if (!root) { a.push_back(-1); return; }
        a.push_back(root->data);
        serializeUtil(root->left, a);
        serializeUtil(root->right, a);
    }

    vector<int> serialize(Node *root) {
        vector<int> a;
        serializeUtil(root, a);
        return a;
    }

    Node *buildTree(vector<int> &a, int &i) {
        if (i >= a.size() || a[i] == -1) return i++, nullptr;
        Node *root = new Node(a[i++]);
        root->left = buildTree(a, i);
        root->right = buildTree(a, i);
        return root;
    }

    Node *deSerialize(vector<int> &a) {
        int i = 0;
        return buildTree(a, i);
    }
};
```

<details>
  <summary><h2 align="center">🌲 Alternative Approaches</h2></summary>

## **2️⃣ Level Order Traversal (O(N) Time, O(N) Space)**

1. Use **queue-based level order traversal** to **serialize** the tree.
2. Insert `-1` for `NULL` nodes.
3. For **deserialization**, reconstruct nodes **level by level** using a queue.

```cpp
class Solution {
public:
    vector<int> serialize(Node* root) {
        vector<int> res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front(); q.pop();
            if (node) {
                res.push_back(node->data);
                q.push(node->left);
                q.push(node->right);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }

    Node* deSerialize(vector<int>& data) {
        if (data.empty() || data[0] == -1) return nullptr;
        Node* root = new Node(data[0]);
        queue<Node*> q;
        q.push(root);
        int i = 1;
        while (!q.empty()) {
            Node* node = q.front(); q.pop();
            if (data[i] != -1) {
                node->left = new Node(data[i]);
                q.push(node->left);
            }
            i++;
            if (data[i] != -1) {
                node->right = new Node(data[i]);
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};
```

🔹 **Uses level order traversal** instead of recursion.  
🔹 **Handles large trees efficiently**.  
🔹 **Better suited for balanced trees**.

## **Comparison of Approaches**

| **Approach**           | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ⚡ **Method** | ✅ **Pros**                  | ⚠️ **Cons**                |
| ---------------------- | ---------------------- | ----------------------- | ------------- | ---------------------------- | -------------------------- |
| **Recursive Preorder** | 🟢 O(N)                | 🟡 O(N)                 | Recursion     | Simple and easy to implement | High stack memory usage    |
| **Level Order Queue**  | 🟢 O(N)                | 🟡 O(N)                 | Queue-Based   | Efficient for large trees    | Requires extra queue space |

## 💡 **Best Choice?**

- ✅ **For simplicity:** **Recursive Preorder**.
- ✅ **For large trees:** **Level Order Traversal (Queue-based)** avoids stack overflow.

</details>

## **Code (Java)**

```java
class Tree {
    public ArrayList<Integer> serialize(Node r) {
        ArrayList<Integer> a = new ArrayList<>();
        s(r, a);
        return a;
    }
    void s(Node r, ArrayList<Integer> a) {
        if(r==null){a.add(-1); return;}
        a.add(r.data);
        s(r.left, a);
        s(r.right, a);
    }
    public Node deSerialize(ArrayList<Integer> a) {
        int[] i = {0};
        return d(a, i);
    }
    Node d(ArrayList<Integer> a, int[] i) {
        if(i[0]>=a.size() || a.get(i[0])==-1){i[0]++; return null;}
        Node r = new Node(a.get(i[0]++));
        r.left = d(a, i);
        r.right = d(a, i);
        return r;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def serialize(self, root):
        a = []
        def s(r):
            if not r:
                a.append(-1)
                return
            a.append(r.data)
            s(r.left)
            s(r.right)
        s(root)
        return a

    def deSerialize(self, arr):
        self.i = 0
        def d():
            if self.i >= len(arr) or arr[self.i] == -1:
                self.i += 1
                return None
            r = Node(arr[self.i])
            self.i += 1
            r.left = d()
            r.right = d()
            return r
        return d()
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
