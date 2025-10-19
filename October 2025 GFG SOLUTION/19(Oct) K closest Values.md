---
title: "🌲 K Closest Values | GFG Solution 🎯"
keywords🏷️: ["🌲 binary search tree", "🎯 k closest", "📍 two pointers", "🔍 inorder traversal", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the K Closest Values in BST problem: find k values closest to target using iterative inorder traversal and two-pointer technique. 🚀"
date: 📅 2025-10-19
---

# *19. K Closest Values*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/k-closest-values/1)

## **🧩 Problem Description**

Given the root of a **Binary Search Tree**, a target value, and an integer `k`, your task is to find the **k values** in the BST that are **closest to the target**.

The closest value is determined by the **minimum absolute difference** from the target. If two values have the same absolute difference, choose the **smaller value**. The target may or may not be present in the BST.

## **📘 Examples**

### Example 1

```cpp
Input: root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], target = 17, k = 3
Output: [14, 20, 12]
Explanation: Absolute difference of 17 with 14 and 20 is 3 each, but we choose 
the smaller value (14) first. Then 12 and 22 both have absolute difference 5, 
so we choose the smaller value (12).
```

### Example 2

```cpp
Input: root = [5, 4, 8, 1], target = 5, k = 2
Output: [5, 4]
Explanation: The absolute difference of 5 with itself is 0, and with 4 is 1.
```

## **🔒 Constraints**

* $1 \le \text{number of nodes, k} \le 10^4$
* $1 \le \text{node→data, target} \le 10^4$

## **✅ My Approach**

The optimal approach uses **Iterative Inorder Traversal** combined with **Binary Search** and **Two-Pointer Technique**:

### **Iterative Inorder + Binary Search + Two Pointers**

1. **Inorder Traversal:**
   * Use iterative inorder traversal with a stack to collect all BST values in sorted order.
   * This gives us a sorted array without recursion overhead.

2. **Find Starting Position:**
   * Use `lower_bound` (binary search) to find the position closest to or just greater than the target.
   * Adjust position to the closest element by comparing distances.

3. **Two-Pointer Expansion:**
   * Initialize two pointers: `left` at the found position and `right` at position + 1.
   * Compare absolute differences from target for elements at both pointers.
   * When distances are equal, prefer the smaller value (left pointer).
   * Pick k closest elements by expanding in both directions.

4. **Handle Edge Cases:**
   * Check boundary conditions when left pointer goes below 0 or right pointer exceeds array size.
   * Ensure tie-breaking favors smaller values.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n + log n + k), where n is the number of nodes in the BST. The inorder traversal takes O(n) time, binary search takes O(log n), and extracting k closest elements takes O(k) time.
* **Expected Auxiliary Space Complexity:** O(n + h), where n is for storing the inorder traversal and h is the height of the tree for the stack used during iterative traversal. In the worst case, h can be O(n) for a skewed tree, but for a balanced BST, h = O(log n).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int> in;
        stack<Node*> s;
        Node* curr = root;
        while (curr || !s.empty()) {
            while (curr) s.push(curr), curr = curr->left;
            curr = s.top(); s.pop();
            in.push_back(curr->data);
            curr = curr->right;
        }
        int n = in.size(), pos = lower_bound(in.begin(), in.end(), target) - in.begin();
        if (pos > 0 && (pos == n || abs(in[pos - 1] - target) <= abs(in[pos] - target))) pos--;
        vector<int> res;
        int l = pos, r = pos + 1;
        while (k--) {
            if (r >= n || (l >= 0 && abs(in[l] - target) <= abs(in[r] - target)))
                res.push_back(in[l--]);
            else
                res.push_back(in[r++]);
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Max Heap Priority Queue**

### 💡 Algorithm Steps:

1. Use a max heap to maintain k closest elements based on distance from target.
2. Traverse the BST using DFS and calculate absolute distance for each node.
3. If heap size is less than k, push the element with its distance and negated value.
4. If current element is closer or has same distance with smaller value, replace heap top.
5. Negate values to handle tie-breaking (smaller values preferred when distances are equal).

```cpp
class Solution {
public:
    void dfs(Node* node, int t, int k, priority_queue<pair<int,int>>& pq) {
        if (!node) return;
        int d = abs(node->data - t);
        if (pq.size() < k) pq.push({d, node->data});
        else if (d < pq.top().first || (d == pq.top().first && node->data < pq.top().second)) {
            pq.pop();
            pq.push({d, node->data});
        }
        dfs(node->left, t, k, pq);
        dfs(node->right, t, k, pq);
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        priority_queue<pair<int,int>> pq;
        dfs(root, target, k, pq);
        vector<int> res;
        while (!pq.empty()) res.push_back(pq.top().second), pq.pop();
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Expected Time Complexity:** O(n log k), where n is the number of nodes. Each node is visited once, and heap operations take O(log k) time.
* **Expected Auxiliary Space Complexity:** O(k + h), where k is for the heap and h is the recursion stack depth (tree height).

### ✅ **Why This Approach?**

* No need to store entire inorder traversal upfront.
* Memory efficient for large trees with small k values.
* Works with any tree traversal order, not just inorder.

## 📊 **3️⃣ Recursive Inorder with Binary Search**

### 💡 Algorithm Steps:

1. Recursively collect inorder traversal values in a vector.
2. Use binary search to find the index closest to or just greater than target.
3. Initialize two pointers from the found position expanding bidirectionally.
4. Compare absolute distances and pick k closest elements, preferring smaller values on ties.

```cpp
class Solution {
public:
    void inorder(Node* node, vector<int>& v) {
        if (!node) return;
        inorder(node->left, v);
        v.push_back(node->data);
        inorder(node->right, v);
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int> v;
        inorder(root, v);
        int n = v.size(), l = 0, r = n - 1, pos = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (v[m] <= target) pos = m, l = m + 1;
            else r = m - 1;
        }
        vector<int> res;
        l = pos; r = pos + 1;
        while (k--) {
            if (r >= n || (l >= 0 && abs(v[l] - target) <= abs(v[r] - target)))
                res.push_back(v[l--]);
            else
                res.push_back(v[r++]);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Expected Time Complexity:** O(n + log n + k), where n is for recursive inorder traversal, O(log n) for binary search, and O(k) for extracting k elements.
* **Expected Auxiliary Space Complexity:** O(n + h), where n is for storing inorder values and h is the recursion depth.

### ✅ **Why This Approach?**

* Clean separation of traversal and search logic.
* Standard recursive inorder implementation, easy to understand.
* Binary search provides efficient target position finding.

## 📊 **4️⃣ Direct Two-Way BST Traversal**

### 💡 Algorithm Steps:

1. Use two stacks to traverse predecessors and successors from target position.
2. Initialize predecessor stack with nodes less than target, successor stack with greater nodes.
3. For each of k iterations, compare top elements of both stacks by distance.
4. Pop the closer element and advance that stack's traversal appropriately.
5. This approach avoids storing entire inorder, processing only necessary nodes.

```cpp
class Solution {
public:
    void pushLeft(Node* node, stack<Node*>& s) {
        while (node) s.push(node), node = node->left;
    }
    void pushRight(Node* node, stack<Node*>& s) {
        while (node) s.push(node), node = node->right;
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        stack<Node*> pred, succ;
        Node* curr = root;
        while (curr) {
            if (curr->data < target) pred.push(curr), curr = curr->right;
            else succ.push(curr), curr = curr->left;
        }
        vector<int> res;
        while (k--) {
            if (pred.empty()) {
                Node* node = succ.top(); succ.pop();
                res.push_back(node->data);
                pushLeft(node->right, succ);
            } else if (succ.empty()) {
                Node* node = pred.top(); pred.pop();
                res.push_back(node->data);
                pushRight(node->left, pred);
            } else {
                int pVal = pred.top()->data, sVal = succ.top()->data;
                if (abs(pVal - target) <= abs(sVal - target)) {
                    res.push_back(pVal);
                    Node* node = pred.top(); pred.pop();
                    pushRight(node->left, pred);
                } else {
                    res.push_back(sVal);
                    Node* node = succ.top(); succ.pop();
                    pushLeft(node->right, succ);
                }
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Expected Time Complexity:** O(h + k), where h is the height of the tree for initial stack setup and k for extracting k closest elements. For balanced BST, h = O(log n).
* **Expected Auxiliary Space Complexity:** O(h), where h is for the two stacks. In balanced BST, this is O(log n).

### ✅ **Why This Approach?**

* Most space efficient for balanced trees with small k values.
* Avoids storing entire inorder traversal in memory.
* Optimal when k is significantly smaller than n.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔄 **Iterative Inorder**          | 🟢 O(n + k)            | 🟡 O(n)                 | 🎯 Simple implementation          | 💾 Stores all nodes                  |
| 🏔️ **Max Heap**                   | 🟡 O(n log k)          | 🟢 O(k)                 | 💾 Space efficient                | 🐌 Extra log k per node              |
| 🔍 **Binary Search**              | 🟢 O(n + log n + k)    | 🟡 O(n)                 | 📖 Clear logic flow               | 💾 Full traversal needed             |
| 🔀 **Two-Way Traversal**          | 🟢 O(h + k)            | 🟢 O(h)                 | ⭐ Optimal space for small k      | 🔧 Complex stack management          |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **k is small, large tree**                         | 🥇 **Two-Way Traversal**             | ★★★★★                     |
| 📖 **Simplicity and readability**                     | 🥈 **Iterative Inorder**             | ★★★★☆                     |
| 🔧 **Memory constrained**                             | 🥉 **Max Heap**                      | ★★★★☆                     |
| 🎯 **General purpose**                                | 🏅 **Binary Search**                 | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<Integer> getKClosest(Node root, int target, int k) {
        ArrayList<Integer> in = new ArrayList<>();
        Stack<Node> s = new Stack<>();
        Node curr = root;
        while (curr != null || !s.isEmpty()) {
            while (curr != null) {
                s.push(curr);
                curr = curr.left;
            }
            curr = s.pop();
            in.add(curr.data);
            curr = curr.right;
        }
        int n = in.size(), l = 0, r = n - 1, pos = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (in.get(m) <= target) {
                pos = m;
                l = m + 1;
            } else r = m - 1;
        }
        ArrayList<Integer> res = new ArrayList<>();
        l = pos; r = pos + 1;
        while (k-- > 0) {
            if (r >= n || (l >= 0 && Math.abs(in.get(l) - target) <= Math.abs(in.get(r) - target)))
                res.add(in.get(l--));
            else
                res.add(in.get(r++));
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def getKClosest(self, root, target, k):
        in_order, stack, curr = [], [], root
        while curr or stack:
            while curr:
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            in_order.append(curr.data)
            curr = curr.right
        n, l, r, pos = len(in_order), 0, len(in_order) - 1, 0
        while l <= r:
            m = (l + r) // 2
            if in_order[m] <= target:
                pos, l = m, m + 1
            else:
                r = m - 1
        res, l, r = [], pos, pos + 1
        while k:
            if r >= n or (l >= 0 and abs(in_order[l] - target) <= abs(in_order[r] - target)):
                res.append(in_order[l])
                l -= 1
            else:
                res.append(in_order[r])
                r += 1
            k -= 1
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
