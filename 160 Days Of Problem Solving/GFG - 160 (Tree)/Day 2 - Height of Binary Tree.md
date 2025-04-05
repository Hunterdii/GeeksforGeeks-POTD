---
Difficulty: Easy
Source: 160 Days of Problem Solving
Tags:
  - Tree
---

# 🚀 _Day 2. Height of Binary Tree_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/height-of-binary-tree)

## 💡 **Problem Description:**

Given a binary tree, find its height.  
The height of a tree is defined as the number of edges on the longest path from the root to a leaf node.  
A leaf node is a node that does not have any children.

## 🔍 **Example Walkthrough:**

**Example 1:**  
**Input:**  
`root[] = [12, 8, 18, 5, 11]`

<img src="https://github.com/user-attachments/assets/c29ca866-64ae-48b1-ad74-05d29ad7c1f0" width="30%">

**Output:**  
`2`  
**Explanation:**  
One of the longest paths from the root (node 12) goes through node 8 to node 5, which has 2 edges.

**Example 2:**  
**Input:**  
`root[] = [1, 2, 3, 4, N, N, 5, N, N, 6, 7]`

<img src="https://github.com/user-attachments/assets/9f828753-bfae-4306-9d86-6d129cb37ef4" width="30%">

**Output:**  
`3`  
**Explanation:**  
The longest path from the root (node 1) to a leaf node (node 6) contains 3 edges.

**Constraints:**

- 1 <= number of nodes <= $10^5$
- 0 <= node->data <= $10^5$

## 🎯 **My Approach:**

We can solve the problem using recursion by computing the height of the left and right subtrees and taking the maximum of the two.

- **Recursive DFS (Top-Down):**  
  Traverse the tree and for each node, return `1 + max(height(left), height(right))`.
- **Iterative BFS (Level Order):**  
  Use a queue to perform level order traversal and count the number of levels.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N), as each node is visited exactly once.
- **Expected Auxiliary Space Complexity:** O(H), where H is the height of the tree (space used in the recursion stack).

## 📝 **Solution Code**

### **1️⃣ Recursive DFS (Top-Down)**

## Code (C)

```c
int max(int a,int b){return a>b?a:b;}
int height(struct Node* node){return node?1+max(height(node->left),height(node->right)):-1;}
```

## Code (C++)

```cpp
class Solution {
public:
    int height(Node* node) {
        return node ? 1 + max(height(node->left), height(node->right)) : -1;
    }
};
```

<details>
  <summary><h2 align='center'>🌲 Alternative Approaches</h2></summary>

## **2️⃣ Iterative BFS (Level Order)**

```cpp
class Solution {
public:
    int height(Node* root) {
        if (!root) return -1;
        queue<Node*> q({root});
        int h = -1;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                Node* n = q.front(); q.pop();
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            h++;
        }
        return h;
    }
};
```

## **3️⃣ Recursive DFS (Bottom-Up)**

```cpp
class Solution {
public:
    int height(Node* node) {
        if (!node) return -1;
        int l = height(node->left), r = height(node->right);
        return 1 + max(l, r);
    }
};
```

**Comparison of Approaches**

| Approach                        | Time Complexity | Space Complexity | Method      | Pros                                      | Cons                                    |
| ------------------------------- | --------------- | ---------------- | ----------- | ----------------------------------------- | --------------------------------------- |
| **Recursive DFS (Top-Down)**    | 🟢 **O(N)**     | 🟡 **O(H)**      | Recursion   | Simple and concise                        | May cause stack overflow for deep trees |
| **Iterative BFS (Level Order)** | 🟢 **O(N)**     | 🔴 **O(W)**      | Queue-based | Avoids deep recursion issues              | Higher memory usage for wide trees      |
| **Recursive DFS (Bottom-Up)**   | 🟢 **O(N)**     | 🟡 **O(H)**      | Recursion   | Explicit computation, similar to Top-Down | Recursion stack usage remains           |

### **Best Choice?**

- **For balanced trees**, Top-Down DFS is fine.
- **For deep trees**, BFS is better (avoids stack overflow).
- **For clarity**, Bottom-Up DFS is explicit and structured.

</details>

## Code (Java)

```java
class Solution {
    int height(Node node){
        return node == null ? -1 : 1 + Math.max(height(node.left), height(node.right));
    }
}
```

## Code (Python)

```python
class Solution:
    def height(self, root):
        return -1 if not root else 1 + max(self.height(root.left), self.height(root.right))
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
