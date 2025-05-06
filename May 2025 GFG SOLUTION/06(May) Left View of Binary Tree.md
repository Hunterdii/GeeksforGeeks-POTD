# *6. Left View of Binary Tree*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1)


## **🧩 Problem Description**

You are given the root of a binary tree. Your task is to return the **left view** of the binary tree.
The left view is defined as the set of nodes visible when the tree is observed from the **left side**.

If the tree is empty, return an empty list.


## **📘 Examples**

### **Example 1:**

#### **Input:**

`root[] = [1, 2, 3, 4, 5, N, N]`

<img src="https://github.com/user-attachments/assets/b37094b1-99cb-49dd-bf01-d4032939d3e0" width="30%">

#### **Output:**

`[1, 2, 4]`

#### **Explanation:**

From the left side of the tree, the visible nodes are: 1 (level 0), 2 (level 1), and 4 (level 2).

<img src="https://github.com/user-attachments/assets/4c1b1e9a-cee6-4623-bb2c-24a0936e50cb" width="30%">


### **Example 2:**

#### **Input:**

`root[] = [1, 2, 3, N, N, 4, N, N, 5, N, N]`

<img src="https://github.com/user-attachments/assets/f835d22e-7312-4a00-93a2-b4b099771780" width="30%">

#### **Output:**

`[1, 2, 4, 5]`

#### **Explanation:**

Only one node at each level is visible from the left side, namely: 1, 2, 4, and 5.

<img src="https://github.com/user-attachments/assets/b5d42a3b-ca93-4391-b139-e0d522e58151" width="30%">


### **Example 3:**

#### **Input:**

`root[] = [N]`

#### **Output:**

`[]`


### 🔒 Constraints:

* \$0 \leq\$ Number of nodes \$\leq 10^6\$
* \$0 \leq\$ Node \$\rightarrow\$ data \$\leq 10^5\$

## ✅ **My Approach**

### **BFS Level Order Traversal**

We use level-order traversal (BFS) to traverse the binary tree. For each level, we keep track of the **first node** encountered and add it to the result list.

### **Algorithm Steps:**

1. Initialize an empty queue and push the root node.
2. For each level in the tree:

   * Record the first node's value at the front of the queue.
   * Add all children (left first, then right) to the queue.
3. Repeat for all levels and return the result list.


## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(N), as we visit every node exactly once during level-order traversal.
* **Expected Auxiliary Space Complexity:** O(W), where W is the maximum width of the binary tree (maximum number of nodes at any level due to the queue used in BFS).

## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    vector<int> leftView(Node *root) {
        if (!root) return {};
        vector<int> res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* cur = q.front(); q.pop();
                if (i == 0) res.push_back(cur->data);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return res;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>


## 📊 **2️⃣ DFS with First Node at Each Level**

### **Algorithm Steps:**

1. Use DFS and maintain a level counter.
2. Track the **maximum level visited so far**.
3. If the current node is the first at its level, add it to the result.



```cpp
class Solution {
  void dfs(Node* node, int level, vector<int>& res) {
      if (!node) return;
      if (level == res.size()) res.push_back(node->data);
      dfs(node->left, level + 1, res);
      dfs(node->right, level + 1, res);
  }
public:
  vector<int> leftView(Node *root) {
      vector<int> res;
      dfs(root, 0, res);
      return res;
  }
};
```

### ✅ **Why This Approach?**

* Does not use a queue (no level-order), just recursion.
* Very elegant and recursive.

### 📝 **Complexity Analysis**

| Metric              | DFS Recursive Approach     |
| ------------------- | -------------------------- |
| **Time Complexity** | O(N)                       |
| **Auxiliary Space** | O(H) recursion stack       |
|                     | (`H` = height of the tree) |


## 🆚 **Comparison of Approaches**

| **Approach**      | ⏱️ **Time Complexity** | 🗂️ **Auxiliary Space** | ✅ **Pros**                       | ⚠️ **Cons**                      |
| ----------------- | ---------------------- | ----------------------- | -------------------------------- | -------------------------------- |
| BFS (Level Order) | 🟢 O(N)                   | 🟢 O(W)                    | Simple, iterative                | Needs queue memory (width `W`)   |
| DFS (Recursive)   | 🟢 O(N)                   | 🟡 O(H)                    | Cleaner recursion, minimal logic | Uses recursion stack (depth `H`) |

> * `N`: Number of nodes
> * `H`: Height of tree
> * `W`: Maximum width of tree (BFS queue size)


### ✅ **Best Choice?**

| **Scenario**                             | **Recommended Approach** |
| ---------------------------------------- | ------------------------ |
| Balanced trees or breadth-first use case | 🥇 BFS                   |
| Memory-efficient depth-first preference  | 🥈 DFS                   |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    ArrayList<Integer> leftView(Node root) {
        if (root == null) return new ArrayList<>();
        ArrayList<Integer> res = new ArrayList<>();
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node cur = q.poll();
                if (i == 0) res.add(cur.data);
                if (cur.left != null) q.add(cur.left);
                if (cur.right != null) q.add(cur.right);
            }
        }
        return res;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def LeftView(self, root):
        if not root: return []
        res, q = [], [root]
        while q:
            res.append(q[0].data)
            q = [child for node in q for child in (node.left, node.right) if child]
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
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
