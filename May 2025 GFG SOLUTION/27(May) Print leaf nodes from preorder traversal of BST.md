# *27. Print Leaf Nodes from Preorder Traversal of BST*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/print-leaf-nodes-from-preorder-traversal-of-bst2657/1)

## **🧩 Problem Description**

Given the preorder traversal of a Binary Search Tree (BST), print all the leaf nodes of this BST **without** actually reconstructing the tree.

### ❗Note:

* It is guaranteed that the input preorder is of a **valid BST**.
* The output order must follow the **order of the leaf nodes as they appear during preorder traversal**.


## **📘 Examples**

### **Example 1:**

* **Input:** `preorder = [5, 2, 10]`
* **Output:** `[2, 10]`
* **Explanation:**
  The BST is:

  ```
      5
     / \
    2   10
  ```

<img src="https://github.com/user-attachments/assets/511c10ef-05f4-4337-b0cf-37f11a28a996" width="22%">



  Leaf nodes are `2` and `10`.

### **Example 2:**

* **Input:** `preorder = [4, 2, 1, 3, 6, 5]`
* **Output:** `[1, 3, 5]`
* **Explanation:**
  The BST is:

  ```
        4
       / \
      2   6
     / \  /
    1   3 5
  ```

<img src="https://github.com/user-attachments/assets/e8338cd6-3fdc-4b37-b45e-eaeb869e37d8" width="22%">


  Leaf nodes are `1, 3, 5`.

### **Example 3:**

* **Input:** `preorder = [8, 2, 5, 10, 12]`
* **Output:** `[5, 12]`
* **Explanation:**
  The BST is:

  ```
       8
      / \
     2   10
      \    \
       5    12
  ```

<img src="https://github.com/user-attachments/assets/a06492e0-dc3b-4fc0-b791-daa95774fc54" width="22%">

  Leaf nodes are `5` and `12`.


## **🔒 Constraints**

* $`1 ≤ preorder.size() ≤ 10^3`$
* $`1 ≤ preorder[i] ≤ 10^3`$


## **✅ My Approach**

### **Single-Pass Stack Sweep**

We can determine leaf nodes directly by observing when a node’s value is “popped over” by a larger successor in preorder. Maintain a stack of ancestors; whenever the next value exceeds stack-top, the previous node is a leaf.

### **Algorithm Steps:**

1. Initialize an empty stack `st` and an empty result list `leafs`.
2. Iterate index `i` from `0` to `preorder.size() - 2`:

   * Let `cur = preorder[i]`, `nxt = preorder[i+1]`.
   * If `cur > nxt`, push `cur` onto `st`.
   * Else (i.e., `nxt > cur`):

     1. While `!st.empty()` and `nxt > st.top()`, pop `st` and mark a flag.
     2. If flag was set (we popped at least once), **record** `cur` as a leaf.
3. After loop, **always** append the last element `preorder.back()` as a leaf.
4. Return `leafs`.


## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(n), as we scan the array once and each element is pushed and popped at most once.
* **Expected Auxiliary Space Complexity:** O(n), as in the worst case (strictly decreasing preorder) all elements go into the stack.


## 🧠 **Code (C++)**

```cpp
class Solution {
  public:
    vector<int> leafNodes(vector<int>& p) {
        stack<int> s;
        vector<int> r;
        for (int i = 0, j = 1; j < p.size(); i++, j++) {
            bool f = 0;
            if (p[i] > p[j]) s.push(p[i]);
            else while (!s.empty() && p[j] > s.top()) s.pop(), f = 1;
            if (f) r.push_back(p[i]);
        }
        r.push_back(p.back());
        return r;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>


## 📊 **2️⃣ Recursive BST Reconstruction + DFS**

### **Algorithm Steps:**

1. **Reconstruct BST** from `preorder` using a helper `build(preorder, idx, bound)`:

   * If `idx == n` or `preorder[idx] > bound`, return `nullptr`.
   * Create node `u` with `preorder[idx++]`.
   * `u->left  = build(preorder, idx, u->val);`
   * `u->right = build(preorder, idx, bound);`
2. **DFS** on this tree:

   * If `u` has no children, record `u->val` in `leafs`.
   * Recurse on `u->left` then `u->right`.

```cpp
class Solution {
  public:
    struct Node { int v; Node *l,*r; Node(int x):v(x),l(0),r(0){} };
    Node* build(vector<int>& P, int& i, int UB) {
        if (i==P.size()||P[i]>UB) return nullptr;
        Node* n=new Node(P[i++]);
        n->l=build(P,i,n->v);
        n->r=build(P,i,UB);
        return n;
    }
    void dfs(Node* u, vector<int>& L) {
        if(!u) return;
        if(!u->l&&!u->r) L.push_back(u->v);
        dfs(u->l,L); dfs(u->r,L);
    }
    vector<int> leafNodes(vector<int>& P) {
        int i=0; auto root=build(P,i,INT_MAX);
        vector<int> L; dfs(root,L);
        return L;
    }
};
```

### ✅ **Why This Approach?**

* 🏗️ Builds the exact BST structure for clarity.
* 🔍 Separates tree construction from leaf-collection.

#### 📝 **Complexity Analysis:**

* **Time:** 🟢 O(n) — each element inserted once, each visited once in DFS.
* **Auxiliary Space:** 🔸 O(n) — recursion stack + newly allocated nodes.


## 📊 **3️⃣ Divide & Conquer on Array**

### **Algorithm Steps:**

1. Define `void solve(l, r)` over subarray `preorder[l…r]`.
2. If `l == r`, record `preorder[l]` as leaf and return.
3. Find `m` = first index in `(l+1…r]` such that `preorder[m] > preorder[l]`.
4. Recurse on `[l+1, m-1]` (left subtree) and `[m, r]` (right subtree).

```cpp
class Solution {
  public:
    void dc(int l, int r, vector<int>& P, vector<int>& L) {
        if (l>r) return;
        if (l==r) { L.push_back(P[l]); return; }
        int m = l+1;
        while (m<=r && P[m]<P[l]) ++m;
        dc(l+1,m-1,P,L);
        dc(m,r,P,L);
    }
    vector<int> leafNodes(vector<int>& P) {
        vector<int> L;
        dc(0,P.size()-1,P,L);
        return L;
    }
};
```

### ✅ **Why This Approach?**

* 📏 Works purely on the array, no extra DS beyond call stack.
* 🎯 Directly identifies leaves by subarray bounds.

#### 📝 **Complexity Analysis:**

* **Time:** 🔸 O(n²) worst-case (e.g., sorted preorder).
* **Auxiliary Space:** 🔸 O(n) recursion depth.



## 🆚 **Comparison of Approaches**

| **Approach**                 | ⏱️ **Time**    | 🗂️ **Space** | ✅ **Pros**                           | ⚠️ **Cons**                     |
| ---------------------------- | -------------- | ------------- | ------------------------------------ | ------------------------------- |
| ▶️ Stack Sweep               | 🟢 O(n)        | 🟢 O(n)       | Single pass, no tree nodes allocated | Uses auxiliary stack            |
| 🔁 Recursive BST + DFS       | 🟢 O(n)        | 🟢 O(n)       | Clean separation, true BST structure | Allocates nodes, recursion cost |
| 🪜 Divide & Conquer on Array | 🔸 O(n²) worst | 🟢 O(n)       | No extra DS, direct on array         | Quadratic on pathological input |


### ✅ **Best Choice by Scenario**

| **Scenario**                             | **Recommended**          |
| ---------------------------------------- | ------------------------ |
| 🏆 Fastest and simplest                  | 🥇 Stack Sweep           |
| 📚 Need explicit BST structure           | 🥈 Recursive BST + DFS   |
| 💡 Working purely on array without nodes | 🥉 Divide & Conquer      |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    public ArrayList<Integer> leafNodes(int[] p) {
        Stack<Integer> st = new Stack<>();
        ArrayList<Integer> r = new ArrayList<>();
        for (int i = 0, j = 1; j < p.length; i++, j++) {
            boolean f = false;
            if (p[i] > p[j]) st.push(p[i]);
            else {
                while (!st.isEmpty() && p[j] > st.peek()) {
                    st.pop();
                    f = true;
                }
            }
            if (f) r.add(p[i]);
        }
        r.add(p[p.length-1]);
        return r;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def leafNodes(self, preorder):
        s, r = [], []
        for i in range(len(preorder)-1):
            f = False
            if preorder[i] > preorder[i+1]:
                s.append(preorder[i])
            else:
                while s and preorder[i+1] > s[-1]:
                    s.pop()
                    f = True
            if f:
                r.append(preorder[i])
        r.append(preorder[-1])
        return r
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
