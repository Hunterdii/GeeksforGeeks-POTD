# _10. K Sum Paths_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/k-sum-paths/1)

## **Problem Description**

Given a binary tree and an integer **k**, determine the number of downward-only paths where the sum of the node values in the path equals **k**.  
A path can start and end at any node within the tree but must always move downward (from parent to child).

### **Example 1:**

#### **Input:**

```
       1
      / \
     2   3
```

k = 3

#### **Output:**

```
2
```

#### **Explanation:**

- **Path 1:** 1 → 2 (Sum = 3)
- **Path 2:** 3 (Sum = 3)

### **Example 2:**

#### **Input:** k = 7

```
         8
       /   \
      4     5
     / \     \
    3   2     2
   / \   \
  3  -2   1
```

<img src="https://github.com/user-attachments/assets/47109f3a-0212-4ed5-8693-239a8c6efec8" width="30%">

#### **Output:**

```
3
```

#### **Explanation:**

The following paths sum to k

<img src="https://github.com/user-attachments/assets/9d9c9ba5-174e-4b59-aa90-10df02e3ff33" width="30%">

### Constraints

- 1 ≤ number of nodes ≤ $10^4$
- -100 ≤ node value ≤ 100
- -109 ≤ k ≤ $10^9$

## **My Approach**

### **Prefix Sum DFS Approach**

1. **Traverse the Tree (DFS):**  
   Use depth-first search (DFS) to traverse the binary tree. As we move from the root to each node, maintain a running sum of node values.

2. **Maintain Prefix Sum Frequencies:**  
   Use a hash map (or dictionary) to store the frequency of each prefix sum encountered along the current path.

   - **Key:** The prefix sum value.
   - **Value:** The number of times this prefix sum has occurred.

3. **Check for Valid Paths:**  
   For each node visited, compute the current running sum. Then check if `(current sum - k)` exists in the hash map.

   - If it does, it indicates that there is a valid subpath ending at the current node whose sum equals **k**.
   - Increase the count by the frequency of `(current sum - k)`.

4. **Recurse and Backtrack:**
   - Recursively process the left and right children with the updated running sum.
   - After processing both subtrees, decrement the frequency of the current prefix sum in the hash map to backtrack (ensuring that paths in other branches are not affected).

## **Time and Auxiliary Space Complexity**

**Expected Time Complexity:** O(N), as each node is visited exactly once.  
**Expected Auxiliary Space Complexity:** O(H + N), where H is the height of the tree (for recursion) and N for the hash map.

## Code (C++)

```cpp
class Solution {
public:
    unordered_map<int, int> m;
    int cnt = 0;
    void dfs(Node* node, int k, int currSum) {
        if (!node) return;
        currSum += node->data;
        if (m.count(currSum - k))
            cnt += m[currSum - k];
        m[currSum]++;
        dfs(node->left, k, currSum);
        dfs(node->right, k, currSum);
        m[currSum]--;
    }
    int sumK(Node* root, int k) {
        m[0] = 1;
        dfs(root, k, 0);
        return cnt;
    }
};
```

<details>
  <summary><h2 align="center">🌲 Alternative Approaches</h2></summary>

### **2️⃣ Brute Force Recursive Approach**

```cpp
class Solution {
public:
    int countFrom(Node* node, int k) {
        if (!node) return 0;
        return (node->data == k) +
               countFrom(node->left, k - node->data) +
               countFrom(node->right, k - node->data);
    }
    int sumK(Node* root, int k) {
        if (!root) return 0;
        return countFrom(root, k) + sumK(root->left, k) + sumK(root->right, k);
    }
};
```

_Note:_ This approach recalculates many subpaths and is too slow for large trees.

- ✅ **Optimized than brute force but slower than the prefix sum approach**
- ⚠️ **Still has overlapping subproblems (may hit TLE in large trees).**
  > **Note**: Not Passing All Test Cases
- `Test Cases Passed: `
- `1110 /1120`
- `Time limit exceeded.`

---

### **3️⃣ Iterative DFS with Path Vector**

```cpp
class Solution {
public:
    int sumK(Node* root, int k) {
        if (!root) return 0;
        int cnt = 0;
        stack<pair<Node*, vector<int>>> st;
        st.push({root, {}});
        while (!st.empty()) {
            auto cur = st.top(); st.pop();
            Node* node = cur.first;
            vector<int> path = cur.second;
            path.push_back(node->data);
            int s = 0;
            for (int i = path.size() - 1; i >= 0; i--) {
                s += path[i];
                if (s == k) cnt++;
            }
            if (node->right) st.push({node->right, path});
            if (node->left) st.push({node->left, path});
        }
        return cnt;
    }
};
```

_Note:_ This method tracks the full path from the root, which leads to high memory usage and slower runtime.

- 🔥 **Iterative implementation avoids recursion stack overflow.**
- ⚠️ **Higher space complexity due to storing entire paths.**

## 📊 **Comparison of Approaches**

| Approach                                | Time Complexity | Space Complexity | Method         | Pros                           | Cons                              |
| --------------------------------------- | --------------- | ---------------- | -------------- | ------------------------------ | --------------------------------- |
| **1️⃣ Prefix Sum (Optimized)**           | 🟢 **O(N)**     | 🟡 **O(H + N)**  | DFS + HashMap  | Fastest, avoids redundant work | Slightly complex to implement     |
| **2️⃣ Count from Each Node (Recursive)** | 🟡 **O(N²)**    | 🟡 **O(H)**      | Pure Recursion | Simple, intuitive              | Overlapping subproblems, slower   |
| **3️⃣ Iterative DFS (Path Tracking)**    | 🟡 **O(N²)**    | 🔴 **O(N·H)**    | Stack-based    | No recursion depth issues      | High memory usage for large paths |

## 💡 **Best Choice?**

- **Balanced Trees / Small Input:**  
  ✅ **Approach 1 (Prefix Sum)** is the fastest.
  For optimal performance on large trees, use the Prefix Sum DFS approach.

- **Unbalanced / Deep Trees:**  
  ✅ **Approach 3 (Iterative DFS)** avoids stack overflow.

- **Simple Understanding:**  
  ✅ **Approach 2** helps with conceptual clarity but may be slow.

</details>

## Code (Java)

```java
class Solution {
    Map<Integer,Integer> m = new HashMap<>();
    int cnt = 0;
    void dfs(Node r, int k, int s) {
        if(r==null)return;
        s += r.data;
        if(m.containsKey(s-k)) cnt += m.get(s-k);
        m.put(s, m.getOrDefault(s,0)+1);
        dfs(r.left, k, s);
        dfs(r.right, k, s);
        m.put(s, m.get(s)-1);
        if(m.get(s)==0)m.remove(s);
    }
    public int sumK(Node r, int k) {
        m.put(0,1);
        dfs(r, k, 0);
        return cnt;
    }
}
```

## Code (Python)

```python
class Solution:
    def sumK(self, r, k):
        self.c = 0
        m = {0: 1}
        def dfs(r, s):
            if not r: return
            s += r.data
            self.c += m.get(s - k, 0)
            m[s] = m.get(s, 0) + 1
            dfs(r.left, s)
            dfs(r.right, s)
            m[s] -= 1
            if m[s] == 0: del m[s]
        dfs(r, 0)
        return self.c
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
