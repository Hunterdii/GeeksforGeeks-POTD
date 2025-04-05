# _7. Inorder Traversal_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/inorder-traversal/1)

## Problem Description

Given a Binary Tree, your task is to return its In-Order Traversal.

An inorder traversal first visits the left subtree (including its entire subtree), then visits the node, and finally visits the right subtree (including its entire subtree).

## **Examples:**

- **Example 1:**

- **Input:** `root[] = [1, 2, 3, 4, 5]`

<img src="https://github.com/user-attachments/assets/7733cb99-7571-4602-b46d-4293412d4b7e" width="40%">

- **Output:** `[4, 2, 5, 1, 3]`
- **Explanation:** The in-order traversal of the given binary tree is `[4, 2, 5, 1, 3]`.

- **Example 2:**

- **Input:** `root[] = [8, 1, 5, N, 7, 10, 6, N, 10, 6]`

<img src="https://github.com/user-attachments/assets/a4f35d5c-2197-4bf3-af03-ef52d57bed50" width="40%">

- **Output:** `[1, 7, 10, 8, 6, 10, 5, 6]`
- **Explanation:** The in-order traversal of the given binary tree is `[1, 7, 10, 8, 6, 10, 5, 6]`.

## My Approach

1. **Recursive In-Order Traversal:**

   - **Visit Left Subtree:** Recursively traverse the left subtree.
   - **Process Current Node:** Once the left subtree is completely traversed, record the current node's data.
   - **Visit Right Subtree:** Recursively traverse the right subtree.

2. **Storing the Result:**

   - As each node is processed, add its data to a list (or array).
   - Return the list after completing the traversal.

3. **Handling Null Nodes:**
   - If a node is `null` (or `None` in Python), simply return without performing any action.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where n is the number of nodes in the binary tree, since every node is visited exactly once.
- **Expected Auxiliary Space Complexity:** O(1) in the worst case due to the recursion stack in a skewed tree. In a balanced tree, the recursion stack space is O(log n).

## Code (C)

```C
void rec(struct Node* r, int res[], int *i) {
    if (!r)
        return;
    rec(r->left, res, i);
    res[(*i)++] = r->data;
    rec(r->right, res, i);
}

void inOrder(struct Node* root, int res[]) {
    int i = 0;
    rec(root, res, &i);
    res[i] = -1; // Mark the end of the traversal
}
```

## Code (C++)

```cpp
class Solution {
public:
    void f(Node* r, vector<int>& a) {
        if (!r)
            return;
        f(r->left, a);
        a.push_back(r->data);
        f(r->right, a);
    }

    vector<int> inOrder(Node* r) {
        vector<int> a;
        f(r, a);
        return a;
    }
};
```

<details>
  <summary><h2 align="center">🌲 Alternative Approaches</h2></summary>

### **2️⃣ C++ - Recursive Approach**

```cpp
class Solution {
public:
    void inorderHelper(Node* root, vector<int>& result) {
        if (!root) return;
        inorderHelper(root->left, result);
        result.push_back(root->data);
        inorderHelper(root->right, result);
    }

    vector<int> inOrder(Node* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
};
```

### **3️⃣ C++ - Iterative Approach**

```cpp
class Solution {
public:
    vector<int> inOrder(Node* root) {
        vector<int> result;
        stack<Node*> st;
        Node* curr = root;

        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            result.push_back(curr->data);
            curr = curr->right;
        }

        return result;
    }
};
```

## **Comparison of Approaches**

| Approach                        | Time Complexity | Space Complexity | Method      | Pros                                                                               | Cons                                                  |
| ------------------------------- | --------------- | ---------------- | ----------- | ---------------------------------------------------------------------------------- | ----------------------------------------------------- |
| **Recursive DFS (Top-Down)**    | 🟢 **O(N)**     | 🟡 **O(H)**      | Recursion   | Simple and concise; directly follows the recursive definition of inorder traversal | May cause stack overflow for very deep (skewed) trees |
| **Iterative DFS (Using Stack)** | 🟢 **O(N)**     | 🟡 **O(H)**      | Stack-based | Avoids recursion depth issues; offers explicit control over traversal order        | Slightly more complex to implement than recursion     |

### **Best Choice?**

- **For balanced trees and standard use cases:**  
  The **Recursive DFS** approach is usually sufficient and more straightforward to implement.
- **For very deep or skewed trees:**  
  The **Iterative DFS (Using Stack)** approach is preferable to prevent potential stack overflow issues.

</details>

## Code (Java)

```java
class Solution {
    ArrayList<Integer> inOrder(Node r) {
        ArrayList<Integer> a = new ArrayList<>();
        f(r, a);
        return a;
    }
    void f(Node r, ArrayList<Integer> a) {
        if (r == null) return;
        f(r.left, a);
        a.add(r.data);
        f(r.right, a);
    }
}
```

## Code (Python)

```python
class Solution:
    def inOrder(self, root):
        a = []
        def f(r):
            if r:
                f(r.left)
                a.append(r.data)
                f(r.right)
        f(root)
        return a
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
