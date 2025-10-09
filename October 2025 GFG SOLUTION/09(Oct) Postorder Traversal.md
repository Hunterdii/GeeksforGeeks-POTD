---
title: "🌳 Postorder Traversal | GFG Solution 🔍"  
keywords🏷️: ["🌳 binary tree", "🔄 postorder traversal", "🔍 morris traversal", "📊 tree traversal", "📘 GFG", "🏁 competitive programming", "📚 DSA"]  
author: "✍️ Het Patel (Hunterdii)"  
description: "✅ GFG solution to the Postorder Traversal problem: traverse binary tree in postorder using Morris Traversal technique with O(1) space complexity. 🚀"  
date: 📅 2025-10-09  
---

# *09. Postorder Traversal*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/postorder-traversal/1)

## **🧩 Problem Description**

Given the root of a Binary Tree, your task is to return its **Postorder Traversal**.

A postorder traversal first visits the left child (including its entire subtree), then visits the right child (including its entire subtree), and finally visits the node itself.

## **📘 Examples**

### Example 1

```cpp
Input: root = [19, 10, 8, 11, 13]
Output: [11, 13, 10, 8, 19]
Explanation: The postorder traversal of the given binary tree is [11, 13, 10, 8, 19].
```

### Example 2

```cpp
Input: root = [11, 15, N, 7]
Output: [7, 15, 11]
Explanation: The postorder traversal of the given binary tree is [7, 15, 11].
```

## **🔒 Constraints**

* $1 \le \text{number of nodes} \le 3 \times 10^4$
* $0 \le \text{node->data} \le 10^5$

## **✅ My Approach**

The optimal approach uses **Morris Traversal** technique to achieve postorder traversal with constant space complexity:

### **Morris Traversal for Postorder**

1. **Initialize Variables:**
   * Use a current pointer starting at root.
   * Maintain a result array to store the traversal.

2. **Traverse Using Right-Left Mirror:**
   * For postorder, we traverse in reverse (root-right-left) and then reverse the result.
   * If current node has no right child, add it to result and move to left child.

3. **Create Threading:**
   * If right child exists, find the inorder predecessor (leftmost node in right subtree).
   * If predecessor's left is null, create thread by linking it to current node.
   * Add current node to result and move to right child.

4. **Remove Threading:**
   * If predecessor's left already points to current, remove the thread.
   * Move current to left child.

5. **Reverse Result:**
   * After traversal completes, reverse the result array to get correct postorder sequence.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of nodes in the binary tree. Each node is visited at most twice - once for creating thread and once for removing it, making it linear time complexity.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for pointers. The result array is not counted as auxiliary space since it's required for output. No recursion stack or additional data structures are used.

## **Ⓜ️ Code (C)**

```c
#define MAX_SIZE 100000

int* postOrder(struct Node* root, int* size) {
    int* res = (int*)malloc(MAX_SIZE * sizeof(int));
    *size = 0;
    struct Node* curr = root;
    while (curr) {
        if (!curr->right) {
            res[(*size)++] = curr->data;
            curr = curr->left;
        } else {
            struct Node* pred = curr->right;
            while (pred->left && pred->left != curr) pred = pred->left;
            if (!pred->left) {
                res[(*size)++] = curr->data;
                pred->left = curr;
                curr = curr->right;
            } else {
                pred->left = NULL;
                curr = curr->left;
            }
        }
    }
    for (int i = 0, j = *size - 1; i < j; i++, j--) {
        int temp = res[i];
        res[i] = res[j];
        res[j] = temp;
    }
    return res;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> postOrder(Node *root) {
        vector<int> res;
        Node *curr = root;
        while (curr) {
            if (!curr->right) {
                res.push_back(curr->data);
                curr = curr->left;
            } else {
                Node *pred = curr->right;
                while (pred->left && pred->left != curr) pred = pred->left;
                if (!pred->left) {
                    res.push_back(curr->data);
                    pred->left = curr;
                    curr = curr->right;
                } else {
                    pred->left = NULL;
                    curr = curr->left;
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Iterative Two Stack Approach**

### 💡 Algorithm Steps:

1. Use two stacks to simulate postorder traversal iteratively.
2. Push root to first stack and process nodes by transferring to second stack.
3. For each node popped from first stack, push left then right child.
4. Final result is obtained by popping all elements from second stack.

```cpp
class Solution {
public:
    vector<int> postOrder(Node *root) {
        vector<int> res;
        if (!root) return res;
        stack<Node*> s1, s2;
        s1.push(root);
        while (!s1.empty()) {
            Node* node = s1.top();
            s1.pop();
            s2.push(node);
            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }
        while (!s2.empty()) {
            res.push_back(s2.top()->data);
            s2.pop();
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each node processed once
* **Auxiliary Space:** 💾 O(n) - Two stacks storage

### ✅ **Why This Approach?**

* Straightforward iterative implementation
* No tree modification required
* Easy to understand and implement

## 📊 **3️⃣ Single Stack with Last Visited**

### 💡 Algorithm Steps:

1. Maintain single stack and track last visited node.
2. Traverse left subtree pushing nodes onto stack.
3. Check if right child exists and hasn't been visited yet.
4. Process node when both children are handled or absent.

```cpp
class Solution {
public:
    vector<int> postOrder(Node *root) {
        vector<int> res;
        if (!root) return res;
        stack<Node*> st;
        Node* curr = root;
        Node* last = nullptr;
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            Node* peek = st.top();
            if (peek->right && last != peek->right) {
                curr = peek->right;
            } else {
                res.push_back(peek->data);
                last = peek;
                st.pop();
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear time traversal
* **Auxiliary Space:** 💾 O(h) - Height-dependent stack space

### ✅ **Why This Approach?**

* More memory efficient than two stacks
* Optimal space for balanced trees
* Standard iterative pattern

## 📊 **4️⃣ Recursive DFS**

### 💡 Algorithm Steps:

1. Base case returns if node is null.
2. Recursively process left subtree completely.
3. Recursively process right subtree completely.
4. Add current node's data to result after subtrees.

```cpp
class Solution {
public:
    void dfs(Node* node, vector<int>& res) {
        if (!node) return;
        dfs(node->left, res);
        dfs(node->right, res);
        res.push_back(node->data);
    }
    
    vector<int> postOrder(Node *root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Visit every node once
* **Auxiliary Space:** 💾 O(h) - Recursion stack depth

### ✅ **Why This Approach?**

* Cleanest and most readable code
* Natural recursive tree traversal
* Standard textbook implementation

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Morris Traversal**           | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Constant space usage           | 🔧 Temporarily modifies tree          |
| 🔍 **Two Stack**                  | 🟢 O(n)                | 🟡 O(n)                 | 📖 Clear iterative logic          | 💾 Double stack overhead             |
| 📊 **Single Stack**               | 🟢 O(n)                | 🟢 O(h)                 | 🎯 Efficient space usage          | 🐌 Complex visited tracking          |
| 🔄 **Recursive**                  | 🟢 O(n)                | 🟢 O(h)                 | ⭐ Most readable                  | 🔧 Stack overflow for deep trees     |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Minimal memory required**                        | 🥇 **Morris Traversal**              | ★★★★★                     |
| 📖 **Code simplicity priority**                       | 🥈 **Recursive DFS**                 | ★★★★★                     |
| 🔧 **Tree immutability needed**                       | 🥉 **Single Stack**                  | ★★★★☆                     |
| 🎯 **Learning fundamentals**                          | 🏅 **Two Stack**                     | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<Integer> postOrder(Node root) {
        ArrayList<Integer> res = new ArrayList<>();
        Node curr = root;
        while (curr != null) {
            if (curr.right == null) {
                res.add(curr.data);
                curr = curr.left;
            } else {
                Node pred = curr.right;
                while (pred.left != null && pred.left != curr) pred = pred.left;
                if (pred.left == null) {
                    res.add(curr.data);
                    pred.left = curr;
                    curr = curr.right;
                } else {
                    pred.left = null;
                    curr = curr.left;
                }
            }
        }
        Collections.reverse(res);
        return res;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def postOrder(self, root):
        res = []
        curr = root
        while curr:
            if not curr.right:
                res.append(curr.data)
                curr = curr.left
            else:
                pred = curr.right
                while pred.left and pred.left != curr:
                    pred = pred.left
                if not pred.left:
                    res.append(curr.data)
                    pred.left = curr
                    curr = curr.right
                else:
                    pred.left = None
                    curr = curr.left
        res.reverse()
        return res
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
