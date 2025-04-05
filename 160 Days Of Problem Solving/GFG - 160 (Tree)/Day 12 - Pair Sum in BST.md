---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Tree
  - Binary Search Tree
---

# 🚀 _Day 12. Pair Sum in BST_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/find-a-pair-with-given-target-in-bst)

## 💡 **Problem Description:**

Given a **Binary Search Tree (BST)** and a target value, check whether there exists a **pair of nodes** in the BST whose sum equals the given target.

## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**

```
        7
       / \
      3   8
     / \    \
    2   4    9
```

Target = `12`

<img src="https://github.com/user-attachments/assets/aacf824a-2b30-4bba-bf21-dffb9e684328" width="30%">

#### **Output:**

```
True
```

#### **Explanation:**

In the given BST, there exist two nodes **(8 and 4)** that sum up to 12.

### **Example 2:**

#### **Input:**

```
        9
       / \
      5   10
     / \     \
    2   6     12
```

Target = `23`

<img src="https://github.com/user-attachments/assets/085824bb-b0da-46fe-9288-1bc5430e9e5a" width="30%">

#### **Output:**

```
False
```

#### **Explanation:**

No pair of nodes in the BST sum up to 23.

### **Constraints:**

- $\(1 \leq \text{Number of Nodes} \leq 10^5\)$
- $\(1 \leq \text{target} \leq 10^6\)$

## 🎯 **My Approach:**

### **Optimized Two-Pointer on Inorder Traversal (`O(N)` Time, `O(N)` Space)**

1. **Convert BST to sorted array** using inorder traversal.
2. **Use two-pointer approach** (left and right) to find the target sum efficiently.

### **Algorithm Steps:**

1. **Perform an inorder traversal** and store the BST elements in a sorted list.
2. Use **two pointers** (`left` at the start, `right` at the end) and check the sum:
   - If `arr[left] + arr[right] == target`, return `true`.
   - If `arr[left] + arr[right] < target`, move `left++`.
   - If `arr[left] + arr[right] > target`, move `right--`.
3. If no such pair exists, return `false`.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(N)`, since we traverse each node once.
- **Expected Auxiliary Space Complexity:** `O(N)`, due to storing the inorder traversal.

## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
public:
    bool findTarget(Node* root, int target) {
        vector<int> inorder;
        function<void(Node*)> traverse = [&](Node* node) {
            if (!node) return;
            traverse(node->left);
            inorder.push_back(node->data);
            traverse(node->right);
        };
        traverse(root);
        int left = 0, right = inorder.size() - 1;
        while (left < right) {
            int sum = inorder[left] + inorder[right];
            if (sum == target) return true;
            sum < target ? left++ : right--;
        }
        return false;
    }
};
```

<details>
  <summary><h2 align="center">🌲 Alternative Approaches</h2></summary>

## **2️⃣ Optimized Hash Set Approach (`O(N)` Time, `O(H)` Space)**

1. **Use DFS to traverse the tree** while maintaining a **hash set** of visited values.
2. **Check if (target - current node value) exists** in the set, if yes, return `true`.
3. **Insert the current node value** into the set and continue.

```cpp
class Solution {
public:
    bool findTarget(Node* root, int target) {
        unordered_set<int> seen;
        return dfs(root, target, seen);
    }

    bool dfs(Node* root, int target, unordered_set<int>& seen) {
        if (!root) return false;
        if (seen.count(target - root->data)) return true;
        seen.insert(root->data);
        return dfs(root->left, target, seen) || dfs(root->right, target, seen);
    }
};
```

🔹 **Avoids extra space for storing inorder traversal**  
🔹 **Uses Hash Set for `O(1)` lookup**

## **3️⃣ BST Iterator + Two-Pointer (`O(N)` Time, `O(H)` Space)**

1. **Use two iterators:** one for **inorder (left to right)** and one for **reverse inorder (right to left)**.
2. **Move iterators towards each other** until the pair is found or iterators cross.

```cpp
class BSTIterator {
    stack<Node*> st;
    bool reverse;
public:
    BSTIterator(Node* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        Node* node = st.top(); st.pop();
        if (!reverse) pushAll(node->right);
        else pushAll(node->left);
        return node->data;
    }

    bool hasNext() { return !st.empty(); }

private:
    void pushAll(Node* node) {
        while (node) {
            st.push(node);
            node = reverse ? node->right : node->left;
        }
    }
};

class Solution {
public:
    bool findTarget(Node* root, int target) {
        BSTIterator l(root, false), r(root, true);
        int i = l.next(), j = r.next();
        while (i < j) {
            int sum = i + j;
            if (sum == target) return true;
            sum < target ? i = l.next() : j = r.next();
        }
        return false;
    }
};
```

🔹 **Optimized space using `O(H)` stack instead of `O(N)` vector**  
🔹 **Uses BST Iterators for an efficient two-pointer search**

## **Comparison of Approaches**

| **Approach**                     | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ⚡ **Method** | ✅ **Pros**                      | ⚠️ **Cons**          |
| -------------------------------- | ---------------------- | ----------------------- | ------------- | -------------------------------- | -------------------- |
| **Two-Pointer on Inorder Array** | 🟢 `O(N)`              | 🟡 `O(N)`               | Two Pointers  | Simple and efficient             | Extra space for list |
| **Hash Set (DFS)**               | 🟢 `O(N)`              | 🟡 `O(N)`               | Hashing       | Faster lookup, no sorting needed | Hashing overhead     |
| **BST Iterator (Two-Pointer)**   | 🟡 `O(N^2)`            | 🟢 `O(H)`               | Recursion     | No extra storage used            | Slow for large BSTs  |

---

## 💡 **Best Choice?**

- **For simplicity:** ✅ **Two-Pointer on Inorder Array** is easiest to understand.
- **For faster lookups:** ✅ **Hash Set (`O(H)` space)** avoids sorting overhead.
- **For minimal space:** ✅ **BST Iterator (`O(H)` space, `O(N)` time)** avoids extra space but is slow for large BSTs.

</details>

## Code (Java)

```java
class Solution {
    public boolean findTarget(Node root, int target) {
        List<Integer> inorder = new ArrayList<>();
        inorderTraversal(root, inorder);
        int left = 0, right = inorder.size() - 1;
        while (left < right) {
            int sum = inorder.get(left) + inorder.get(right);
            if (sum == target) return true;
            if (sum < target) left++;
            else right--;
        }
        return false;
    }

    private void inorderTraversal(Node node, List<Integer> inorder) {
        if (node == null) return;
        inorderTraversal(node.left, inorder);
        inorder.add(node.data);
        inorderTraversal(node.right, inorder);
    }
}
```

## Code (Python)

```python
class Solution:
    def findTarget(self, root, target):
        inorder = []
        def inorderTraversal(node):
            if not node:
                return
            inorderTraversal(node.left)
            inorder.append(node.data)
            inorderTraversal(node.right)

        inorderTraversal(root)
        left, right = 0, len(inorder) - 1
        while left < right:
            total = inorder[left] + inorder[right]
            if total == target:
                return True
            if total < target:
                left += 1
            else:
                right -= 1
        return False
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
