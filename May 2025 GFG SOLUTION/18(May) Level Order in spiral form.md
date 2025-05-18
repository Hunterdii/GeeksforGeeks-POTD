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
  
## 📊 **2️⃣ Two-Stacks Method**

### **Algorithm Steps:**

1. If `root` is null, return `{}`.
2. Initialize two stacks: `s1` (for current level), `s2` (for next level).
3. Push `root` to `s1`.
4. While either `s1` or `s2` is non-empty:

   * **Process `s1`** (right→left):

     1. While `s1` isn’t empty:

        * Pop `u` from `s1`, append `u->data`.
        * Push `u->right` then `u->left` onto `s2`.
   * **Process `s2`** (left→right):

     1. While `s2` isn’t empty:

        * Pop `u` from `s2`, append `u->data`.
        * Push `u->left` then `u->right` onto `s1`.
5. Return the combined result.

```cpp
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        if (!root) return {};
        vector<int> ans;
        stack<Node*> s1, s2;
        s1.push(root);
        while (!s1.empty() || !s2.empty()) {
            while (!s1.empty()) {
                Node* u = s1.top(); s1.pop();
                ans.push_back(u->data);
                if (u->right) s2.push(u->right);
                if (u->left)  s2.push(u->left);
            }
            while (!s2.empty()) {
                Node* u = s2.top(); s2.pop();
                ans.push_back(u->data);
                if (u->left)  s1.push(u->left);
                if (u->right) s1.push(u->right);
            }
        }
        return ans;
    }
};
```

### ✅ **Why This Approach?**

* Clear separation of two traversal directions via two stacks.
* No deque operations—pure LIFO.

#### 📝 **Complexity Analysis:**

* **Time:** 🔸 O(N)
* **Auxiliary Space:** 🔸 O(N)



## 📊 **3️⃣ Level-Collection + Reverse**

### **Algorithm Steps:**

1. Perform a standard level-order traversal using a queue, but **collect each level** into its own vector.
2. After collecting all levels in `levels[]`, iterate through `levels`:

   * If level index is even → reverse that level.
   * Append elements in order to final answer.

```cpp
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        if (!root) return {};
        vector<vector<int>> levels;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> lvl;
            for (int i = 0; i < sz; ++i) {
                Node* u = q.front(); q.pop();
                lvl.push_back(u->data);
                if (u->left)  q.push(u->left);
                if (u->right) q.push(u->right);
            }
            levels.push_back(lvl);
        }
        vector<int> ans;
        for (int i = 0; i < levels.size(); ++i) {
            if (i % 2 == 0)
                reverse(levels[i].begin(), levels[i].end());
            ans.insert(ans.end(), levels[i].begin(), levels[i].end());
        }
        return ans;
    }
};
```

### ✅ **Why This Approach?**

* Simple to reason about by separating concerns.
* Useful if you need per-level data later.

#### 📝 **Complexity Analysis:**

* **Time:** 🔸 O(N)
* **Auxiliary Space:** 🔸 O(N) (for both queue and `levels`)


## 🆚 Comparison

| **Approach**           | ⏱️ **Time** | 🗂️ **Space** | ✅ **Pros**              | ⚠️ **Cons**          |
| ---------------------- | ----------- | ------------- | ----------------------- | -------------------- |
| Deque Zigzag Traversal | 🟢 O(n)        | 🟢 O(n)          | Clean, single container | Requires deque logic |
| Two Stack Zigzag       | 🟢 O(n)        | 🟢 O(n)          | Stack-based alternative | Slightly verbose     |
| Level-Collect + Reverse | 🔸 O(N)     | 🔸 O(N)       | Simple to implement               | Needs extra storage for all levels |

### ✅ **Best Choice by Scenario**

| **Scenario**                    | **Recommended Approach**   |
| ------------------------------- | -------------------------- |
| 🚀 Performance & minimal passes | 🥇 Deque-Based Traversal (Optimal)   |
| 🎓 Clarity in interview demos   | 🥈 Two-Stacks              |
| 📊 Need per-level data retained | 🥉 Level-Collect + Reverse |

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
