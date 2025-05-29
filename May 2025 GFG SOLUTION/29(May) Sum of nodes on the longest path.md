---
title: "Sum of Nodes on the Longest Path | GFG Solution"
keywords🏷️ : ["binary tree", "DFS", "longest path", "root to leaf", "sum path", "tree traversal", "GFG", "coding interview", "DSA", "sum of longest bloodline"]
author: "Het Patel (Hunterdii)"
description: "GFG solution to the Sum of Nodes on the Longest Path problem using DFS."
date: 2025-05-29
---


# *29. Sum of nodes on the longest path*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1)

## **🧩 Problem Description**

Given a binary tree, find the **sum of the nodes** on the **longest path** from the root to any leaf.

* If there are multiple root-to-leaf paths of the same maximum length, return the maximum sum among them.


## **📘 Examples**

### Example 1

```
Input: root = [4,2,5,7,1,2,3,null,null,6]
```
<img src="https://github.com/user-attachments/assets/0abeb953-31eb-41eb-88fa-b23a1ca0fc62" alt="Binary tree example for longest path sum" width="22%">

```
Output: 13
Explanation:
```

<img src="https://github.com/user-attachments/assets/27794395-3e70-4198-be82-765307334613" alt="Binary tree example for longest path sum" width="22%">

```
Longest path is 4 → 2 → 1 → 6, sum = 4+2+1+6 = 13
```

### Example 2

```
Input: root = [1,2,3,4,5,6,7]
```
<img src="https://github.com/user-attachments/assets/960ee6a7-4569-49c6-b6f0-abdfce68f2f0" alt="Binary tree example for longest path sum" width="22%">

```
Output: 11
Explanation:
```
<img src="https://github.com/user-attachments/assets/0cb23992-45d8-4bb1-9a06-cce228c063a4" alt="Binary tree example for longest path sum" width="22%">

```
Longest path is 1 → 3 → 7, sum = 1+3+7 = 11
```

### Example 3

```
Input: root = [10,5,15,3,7,null,20,1]
```
<img src="https://github.com/user-attachments/assets/b72807f0-b75e-48ea-92ac-377c48a2b2d3" alt="Binary tree example for longest path sum" width="22%">


```
Output: 19
Explanation:
```
<img src="https://github.com/user-attachments/assets/473912f0-b4b7-4da4-99e2-6195faf35fb7" alt="Binary tree example for longest path sum" width="22%">

```
Longest path is 10 → 5 → 3 → 1, sum = 10+5+3+1 = 19
```


## **🔒 Constraints**

* Number of nodes in the tree: \$1 \le N \le 10^6\$
* Node values: \$0 \le \text{data} \le 10^4\$


## **✅ My Approach**

### **DFS Returning (Length, Sum)**

1. **Idea:**

   * For each subtree, compute a pair `(maxDepth, maxSum)`, where `maxDepth` is the maximum root-to-leaf depth, and `maxSum` is the maximum sum along any path of that depth.
2. **Recurrence:**

   * If left depth > right depth: take `(left.depth+1, left.sum + node->data)`.
   * If right depth > left depth: take `(right.depth+1, right.sum + node->data)`.
   * If equal: take `(left.depth+1, max(left.sum, right.sum) + node->data)`.
3. **Answer:**

   * After processing the root, its `second` component is the desired sum.


## 📝 **Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(N), as we visit each node exactly once.
* **Expected Auxiliary Space Complexity:** O(H), where H = height of the tree (recursion stack).


## **🧑‍💻 Code (C++)**

```cpp
class Solution {
  public:
    pair<int, int> dfs(Node* root) {
        if (!root) return {0, 0};
        auto l = dfs(root->left), r = dfs(root->right);
        if (l.first > r.first) return {l.first + 1, l.second + root->data};
        if (r.first > l.first) return {r.first + 1, r.second + root->data};
        return {l.first + 1, max(l.second, r.second) + root->data};
    }
    int sumOfLongRootToLeafPath(Node* root) {
        return dfs(root).second;
    }
};
```


<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>


## 📊 **2️⃣ Recursive with global state**

### **💡 Algorithm Steps:**

1. Maintain two global variables:

   * `maxLen` = maximum depth seen so far
   * `maxSum` = maximum sum for paths of length `maxLen`
2. Define helper `void dfs(Node* node, int curLen, int curSum)`:

   * If `node == nullptr`:

     * If `curLen > maxLen`, update `maxLen = curLen`, `maxSum = curSum`.
     * Else if `curLen == maxLen`, `maxSum = max(maxSum, curSum)`.
     * Return.
   * Recurse on `node->left` with `(curLen+1, curSum + node->data)`.
   * Recurse on `node->right` with `(curLen+1, curSum + node->data)`.
3. Call `dfs(root, 0, 0)` and return `maxSum`.

```cpp
class Solution {
  public:
    void sumOfRootToLeaf(Node* r, int s, int l, int& ml, int& ms) {
        if (!r) {
            if (l > ml) ml = l, ms = s;
            else if (l == ml && s > ms) ms = s;
            return;
        }
        sumOfRootToLeaf(r->left, s + r->data, l + 1, ml, ms);
        sumOfRootToLeaf(r->right, s + r->data, l + 1, ml, ms);
    }
    int sumOfLongRootToLeafPath(Node* root) {
        int ms = INT_MIN, ml = 0;
        sumOfRootToLeaf(root, 0, 0, ml, ms);
        return ms;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** 🟢 O(N)
* **Auxiliary Space:** 🔸 O(H) (recursion depth)

### ✅ **Why This Approach?**

* Simple to implement and reason about.
* Directly tracks global best without packing/unpacking pairs.

## 🆚 **Comparison of Approaches**

| **Approach**                   | ⏱️ **Time** | 🗂️ **Auxiliary Space** | ✅ **Pros**                                  | ⚠️ **Cons**                                  |
| ------------------------------ | ----------- | ----------------------- | ------------------------------------------- | -------------------------------------------- |
| 🔁 DFS Returning Pair          | 🟢 O(N)     | 🟢 O(H)                 | Pure functional, no globals                 | Slightly more code to return and unpack pair |
| ▶️ Recursive with Global State | 🟢 O(N)     | 🔸 O(H)                 | Very straightforward, minimal return values | Uses mutable global variables                |

### ✅ **Best Choice?**

| **Scenario**                          | **Recommended Approach**  |
| ------------------------------------- | ------------------------- |
| 🏆 Clean, side-effect-free logic      | 🥇 DFS Returning Pair     |
| ⚡️ Quick implementation & readability | 🥈 Recursive with Globals |

</details>



## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int sumOfLongRootToLeafPath(Node root) {
        return dfs(root)[1];
    }

    int[] dfs(Node node) {
        if (node == null) return new int[]{0, 0};
        int[] l = dfs(node.left), r = dfs(node.right);
        if (l[0] > r[0]) return new int[]{l[0] + 1, l[1] + node.data};
        if (r[0] > l[0]) return new int[]{r[0] + 1, r[1] + node.data};
        return new int[]{l[0] + 1, Math.max(l[1], r[1]) + node.data};
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def sumOfLongRootToLeafPath(self, root):
        def dfs(node):
            if not node: return (0, 0)
            l = dfs(node.left)
            r = dfs(node.right)
            if l[0] > r[0]: return (l[0] + 1, l[1] + node.data)
            if r[0] > l[0]: return (r[0] + 1, r[1] + node.data)
            return (l[0] + 1, max(l[1], r[1]) + node.data)
        return dfs(root)[1]
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
