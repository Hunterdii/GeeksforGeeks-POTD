# *18. Level Order in spiral form*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1)

## **🧩 Problem Description**

Given a binary tree, return its spiral (zigzag) level-order traversal.
In spiral order traversal:

* At even-indexed levels (0-based), traverse nodes **from right to left**.
* At odd-indexed levels, traverse nodes **from left to right**.

Return a list containing all node values in spiral order.

<img src="https://github.com/user-attachments/assets/b1969c68-98a2-4251-9151-2d5d2d8f1b78" width="30%">

## **📘 Examples**

### **Example 1:**

#### **Input:**

`root = [1, 3, 2]`

<img src="https://github.com/user-attachments/assets/836b9d62-2c1d-4eb1-8bf0-7d4194c6451e" width="30%">

#### **Output:**

`[1, 3, 2]`

#### **Explanation:**

Level 0 (even) → right to left: `1`
Level 1 (odd) → left to right: `3 2`


### **Example 2:**

#### **Input:**

`root = [10, 20, 30, 40, 60]`

<img src="https://github.com/user-attachments/assets/e007d5b3-9e0d-4ba6-a3d3-293828c56eb8" width="30%">

#### **Output:**

`[10, 20, 30, 60, 40]`


### **Example 3:**

#### **Input:**

`root = [1, 2, N, 4]`

<img src="https://github.com/user-attachments/assets/84061eac-bf90-4ce2-af9c-c92f0fa83898" width="30%">

#### **Output:**

`[1, 2, 4]`


## **🔒 Constraints**

* 1 ≤ number of nodes ≤ 10⁵
* 0 ≤ node->data ≤ 10⁵


## **✅ My Approach**

### **Using Double-Ended Queue (Deque)**

We use a `deque` to simulate two-directional traversal:

* For **even-indexed levels**, we traverse from right to left using `pop_back()` and push children to the **front**.
* For **odd-indexed levels**, we traverse from left to right using `pop_front()` and push children to the **back**.

We alternate the direction at each level using a boolean flag.


### **Algorithm Steps:**

1. Initialize deque `q` and push root node.
2. While `q` is not empty:

   * Traverse the current level based on direction:

     * If flag is `True` (even), pop from back and push right→left children to front.
     * If flag is `False` (odd), pop from front and push left→right children to back.
   * Flip the flag at the end of each level.


## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(n), as we visit each node exactly once in level order.
* **Expected Auxiliary Space Complexity:** O(n), due to storing up to an entire level of nodes in the deque.


## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    vector<int> findSpiral(Node* r) {
        if (!r) return {};
        vector<int> a;
        deque<Node*> q{r};
        bool f = 1;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                Node* x = f ? q.back() : q.front();
                f ? q.pop_back() : q.pop_front();
                a.push_back(x->data);
                if (f) {
                    if (x->right) q.push_front(x->right);
                    if (x->left) q.push_front(x->left);
                } else {
                    if (x->left) q.push_back(x->left);
                    if (x->right) q.push_back(x->right);
                }
            }
            f = !f;
        }
        return a;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Using Two Stacks**

Use two stacks `s1` and `s2` to alternate directions per level:

* Push nodes of one level to `s1`, children to `s2` in appropriate order, and swap.

```cpp
class Solution {
  public:
    vector<int> findSpiral(Node* r) {
        if (!r) return {};
        vector<int> res;
        stack<Node*> s1, s2;
        s1.push(r);
        while (!s1.empty() || !s2.empty()) {
            while (!s1.empty()) {
                Node* t = s1.top(); s1.pop();
                res.push_back(t->data);
                if (t->right) s2.push(t->right);
                if (t->left) s2.push(t->left);
            }
            while (!s2.empty()) {
                Node* t = s2.top(); s2.pop();
                res.push_back(t->data);
                if (t->left) s1.push(t->left);
                if (t->right) s1.push(t->right);
            }
        }
        return res;
    }
};
```

#### 📝 **Complexity Analysis**

### **Time Complexity:** O(n)

### **Auxiliary Space Complexity:** O(n)


## 🆚 Comparison

| **Approach**           | ⏱️ **Time** | 🗂️ **Space** | ✅ **Pros**              | ⚠️ **Cons**          |
| ---------------------- | ----------- | ------------- | ----------------------- | -------------------- |
| Deque Zigzag Traversal | 🟢 O(n)        | 🟢 O(n)          | Clean, single container | Requires deque logic |
| Two Stack Zigzag       | 🟢 O(n)        | 🟢 O(n)          | Stack-based alternative | Slightly verbose     |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    public ArrayList<Integer> findSpiral(Node r) {
        if (r == null) return new ArrayList<>();
        ArrayList<Integer> a = new ArrayList<>();
        Deque<Node> q = new ArrayDeque<>();
        q.add(r);
        boolean f = true;
        while (!q.isEmpty()) {
            int n = q.size();
            while (n-- > 0) {
                Node x = f ? q.pollLast() : q.pollFirst();
                a.add(x.data);
                if (f) {
                    if (x.right != null) q.addFirst(x.right);
                    if (x.left != null) q.addFirst(x.left);
                } else {
                    if (x.left != null) q.addLast(x.left);
                    if (x.right != null) q.addLast(x.right);
                }
            }
            f = !f;
        }
        return a;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def findSpiral(self, r):
        if not r: return []
        a, q, f = [], deque([r]), True
        while q:
            for _ in range(len(q)):
                x = q.pop() if f else q.popleft()
                a.append(x.data)
                if f:
                    if x.right: q.appendleft(x.right)
                    if x.left: q.appendleft(x.left)
                else:
                    if x.left: q.append(x.left)
                    if x.right: q.append(x.right)
            f = not f
        return a
```
