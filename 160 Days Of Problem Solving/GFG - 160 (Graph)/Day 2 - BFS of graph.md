---
Difficulty: Easy
Source: 160 Days of Problem Solving
Tags:
  - Graph
  - BFS
---

# 🚀 _Day 2. BFS of Graph_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/bfs-traversal-of-graph)

## 💡 **Problem Description:**

Given a **connected undirected graph** represented by a **2D adjacency list `adj[][]`**, where `adj[i]` represents the list of vertices connected to vertex `i`.  
Perform a **Breadth First Search (BFS) traversal** starting from **vertex 0**, visiting vertices from left to right as per the given adjacency list.

Return a list containing the **BFS traversal** of the graph.

**Note:** Traverse nodes in the same order as given in the adjacency list.

> Note: Sorry for uploading late, my exam is going on.

## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**

```
adj = [[1, 2, 3],
       [0],
       [0, 4],
       [0],
       [2]]
```

<img src="https://github.com/user-attachments/assets/5ab8ff7f-c58c-4035-9993-4de191cf627b" width="40%">

#### **Output:**

```
[0, 1, 2, 3, 4]
```

#### **Explanation:**

Starting from vertex **0**:

- Visit **0** → Output: `[0]`
- Visit **2** (first neighbor of 0) → Output: `[0, 2]`
- Visit **3** (next neighbor of 0) → Output: `[0, 2, 3]`
- Visit **1** (next neighbor of 0) → Output: `[0, 2, 3]`
- Visit **4** (neighbor of 2) → Final Output: `[0, 2, 3, 1, 4]`

### **Example 2:**

#### **Input:**

```
adj = [[1, 2],
       [0, 3],
       [0, 3, 4],
       [1, 2],
       [2]]
```

<img src="https://github.com/user-attachments/assets/ab16fb62-988e-4cf6-be87-6aacb50fe9c5" width="40%">

#### **Output:**

```
[0, 1, 2, 3, 4]
```

#### **Explanation:**

Starting from vertex **0**:

- Visit **0** → Output: `[0]`
- Visit **1** (first neighbor of 0) → Output: `[0, 1]`
- Visit **2** (next neighbor of 0) → Output: `[0, 1, 2]`
- Visit **3** (first unvisited neighbor of 2) → Output: `[0, 1, 2, 3]`
- Visit **4** (next neighbor of 2) → Final Output: `[0, 1, 2, 3, 4]`

## **Constraints:**

- $1 \leq$ `adj.size()` $\leq 10^4$
- $1 \leq$ `adj[i][j]` $\leq 10^4$

## 🎯 **My Approach:**

### **Iterative BFS (Using Queue)**

### **Algorithm Steps:**

1. Maintain a **visited array** to track visited nodes.
2. Use a **queue** to process nodes in a FIFO manner.
3. Start BFS traversal from node `0` and enqueue it.
4. Process nodes from the queue and visit their unvisited neighbors in order.
5. Store the **BFS traversal sequence** in a list.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(V + E), since each vertex and edge is visited once.
- **Expected Auxiliary Space Complexity:** O(V), as we store the visited array and queue.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
  public:
    vector<int> bfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> res;
        vector<bool> vis(V, false);
        queue<int> q;

        q.push(0);
        vis[0] = true;

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            res.push_back(v);

            for (int u : adj[v]) {
                if (!vis[u]) {
                    vis[u] = true;
                    q.push(u);
                }
            }
        }
        return res;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Recursive BFS Approach**

#### **Algorithm Steps:**

1. Use a helper function for recursion.
2. Process the front element of the queue.
3. Enqueue unvisited neighbors and call the function recursively.

```cpp
class Solution {
public:
    void bfsUtil(queue<int>& q, vector<vector<int>>& adj, vector<int>& res, vector<bool>& vis) {
        if (q.empty()) return;
        int v = q.front();
        q.pop();
        res.push_back(v);
        for (int u : adj[v]) {
            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
            }
        }
        bfsUtil(q, adj, res, vis);
    }

    vector<int> bfs(vector<vector<int>>& adj) {
        vector<int> res;
        vector<bool> vis(adj.size(), false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        bfsUtil(q, adj, res, vis);
        return res;
    }
};
```

#### 📝 **Complexity Analysis:**

- ✅ **Time Complexity:** O(V + E) - Each vertex and edge are processed once.
- ✅ **Space Complexity:** O(V) - Due to the recursion stack.

#### ✅ **Why This Approach?**

- Uses recursion instead of iteration, which may be preferred in some functional programming paradigms.
- However, recursion depth could lead to **stack overflow for large graphs**.

## 🔄 **3️⃣ BFS for Disconnected Graphs**

#### **Algorithm Steps:**

1. Iterate through all vertices to ensure that all components are covered.
2. If a vertex is not visited, initiate BFS from it.
3. This ensures traversal of all disconnected components.

```cpp
class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> res;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                queue<int> q;
                q.push(i);
                vis[i] = true;
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    res.push_back(v);
                    for (int u : adj[v]) {
                        if (!vis[u]) {
                            vis[u] = true;
                            q.push(u);
                        }
                    }
                }
            }
        }
        return res;
    }
};
```

#### 📝 **Complexity Analysis:**

- ✅ **Time Complexity:** O(V + E) - Each vertex and edge are processed once.
- ✅ **Space Complexity:** O(V) - Due to the queue and visited array.

#### ✅ **Why This Approach?**

- **Handles disconnected graphs**, ensuring all components are explored.
- Slightly more complex than basic BFS but necessary for completeness.

## 📊 **4️⃣ BFS Using Deque (Optimized Queue Handling)**

#### **Algorithm Steps:**

1. Instead of `queue<int>`, we use `deque<int>` for optimized front and back operations.
2. The traversal logic remains the same as the standard BFS approach.

```cpp
class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> res;
        vector<int> vis(V, 0);
        deque<int> q;

        vis[0] = 1;
        q.push_back(0);

        while (!q.empty()) {
            int v = q.front();
            q.pop_front();
            res.push_back(v);

            for (int u : adj[v]) {
                if (!vis[u]) {
                    vis[u] = 1;
                    q.push_back(u);
                }
            }
        }
        return res;
    }
};
```

#### 📝 **Complexity Analysis:**

- ✅ **Time Complexity:** O(V + E) - Each vertex and edge are processed once.
- ✅ **Space Complexity:** O(V) - Due to the deque and visited array.

#### ✅ **Why This Approach?**

- Using a `deque` can slightly **improve performance** in some cases due to optimized operations compared to `queue<int>`.
- Useful when frequent push/pop operations from both ends are required.

### 🆚 **Comparison of Approaches**

| **Approach**                    | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                         | ⚠️ **Cons**                             |
| ------------------------------- | ---------------------- | ----------------------- | ----------------------------------- | --------------------------------------- |
| **Standard BFS (Queue)**        | 🟢 O(V + E)            | 🟡 O(V)                 | Simple and widely used              | Fails for disconnected graphs           |
| **Recursive BFS**               | 🟢 O(V + E)            | 🟡 O(V)                 | Recursive and intuitive             | Risk of stack overflow for large graphs |
| **BFS for Disconnected Graphs** | 🟢 O(V + E)            | 🟡 O(V)                 | Ensures traversal of all components | Slightly more complex than basic BFS    |
| **BFS Using (Deque)**           | 🟢 O(V + E)            | 🟡 O(V)                 | Optimized performance using `deque` | Marginal improvement over normal queue  |

✅ **Best Choice?**

- **Use Standard BFS** if the graph is **connected** and efficiency is the priority.
- **Use BFS for Disconnected Graphs** when handling **multiple components**.
- **Use Recursive BFS** only if recursion depth is not an issue.
- **Use Deque BFS** if frequent front and back operations are needed.

</details>

## **Code (Java)**

```java
class Solution {
    public ArrayList<Integer> bfs(ArrayList<ArrayList<Integer>> adj) {
        ArrayList<Integer> r = new ArrayList<>();
        boolean[] v = new boolean[adj.size()];
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        v[0] = true;

        while (!q.isEmpty()) {
            int i = q.poll();
            r.add(i);
            for (int j : adj.get(i)) {
                if (!v[j]) {
                    v[j] = true;
                    q.add(j);
                }
            }
        }
        return r;
    }
}
```

## **Code (Python)**

```python
from collections import deque

class Solution:
    def bfs(self, adj):
        r, v = [], [False] * len(adj)
        q = deque([0])
        v[0] = True
        while q:
            i = q.popleft()
            r.append(i)
            for j in adj[i]:
                if not v[j]:
                    v[j] = True
                    q.append(j)
        return r
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
