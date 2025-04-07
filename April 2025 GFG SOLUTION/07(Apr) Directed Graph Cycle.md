# *7. Directed Graph Cycle*

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1)


## **Problem Description**

Given a **Directed Graph** with **V** vertices (numbered from 0 to V-1) and **E** edges, determine whether the graph contains any cycle.  
The graph is represented as a 2D vector `edges[][]`, where each entry `edges[i] = [u, v]` denotes an edge from vertex **u** to **v**.

> Note: Sorry for uploading late, my Final Sem exam is going on.


## **Examples**

### **Example 1:**

#### **Input:**
```
V = 4, edges[][] = [[0, 1], [1, 2], [2, 3], [3, 3]]
```

<img src="https://github.com/user-attachments/assets/21442886-5a6a-4278-86ae-bc2b7d397a96" width="40%">

#### **Output:**
```
true
```

#### **Explanation:**
There is a self-loop at vertex 3 (3 -> 3) which forms a cycle.


### **Example 2:**

#### **Input:**
```
V = 3, edges[][] = [[0, 1], [1, 2]]
```

<img src="https://github.com/user-attachments/assets/e029ecbb-377d-4dcb-bf42-01eed3f04149" width="40%">

#### **Output:**
```
false
```

#### **Explanation:**
There is no cycle in the graph.


## **Approach**

### **Kahn’s Algorithm (BFS-based Cycle Detection)**

1. **Build the Graph and Compute In-Degrees:**  
   - Convert the edge list into an adjacency list.
   - Compute the in-degree for each vertex.

2. **Initialize a Queue:**  
   - Add all vertices with zero in-degree into a queue.

3. **Process Vertices:**  
   - While the queue is not empty, remove a vertex and decrement the in-degree of its neighbors.
   - If any neighbor’s in-degree becomes zero, add it to the queue.
   - Count the number of vertices processed.

4. **Cycle Check:**  
   - If the count of processed vertices is not equal to V, a cycle exists.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(V + E), since each vertex and edge is processed once.
- **Expected Auxiliary Space Complexity:** O(V + E), due to the in-degree array, adjacency list, and queue.


## **Code (C)**

```c
bool isCycle(struct graph *g, int n, int m) {
    int in[N] = {}, q[N], f = 0, r = 0, c = 0;
    for (int i = 0; i < n; i++)
        for (struct ListNode *p = g->head[i]; p; p = p->next)
            in[p->data]++;
    for (int i = 0; i < n; i++) if (!in[i]) q[r++] = i;
    while (f < r) {
        int u = q[f++];
        c++;
        for (struct ListNode *p = g->head[u]; p; p = p->next)
            if (--in[p->data] == 0) q[r++] = p->data;
    }
    return c != n;
}
```


## **Code (C++)**

```cpp
class Solution {
public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> g(V);
        vector<int> in(V);
        for (auto& e : edges) g[e[0]].push_back(e[1]), in[e[1]]++;
        queue<int> q;
        for (int i = 0; i < V; i++) if (!in[i]) q.push(i);
        int c = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop(); c++;
            for (int v : g[u]) if (--in[v] == 0) q.push(v);
        }
        return c != V;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ DFS-Based Cycle Detection (Recursive)**

#### **Algorithm Steps:**

1. Build an adjacency list from the edge list.
2. Use two arrays: `visited` (to mark processed nodes) and `recStack` (to track nodes in the current DFS recursion).
3. For each unvisited node, run a DFS.
4. If you reach a node that is already in the recursion stack, a cycle exists.

```cpp
class Solution {
    bool dfs(int u, vector<vector<int>>& g, vector<bool>& vis, vector<bool>& recStack) {
        vis[u] = recStack[u] = true;
        for (int v : g[u]) {
            if (!vis[v] && dfs(v, g, vis, recStack))
                return true;
            else if (recStack[v])
                return true;
        }
        recStack[u] = false;
        return false;
    }
public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> g(V);
        for (auto &e : edges)
            g[e[0]].push_back(e[1]);
        vector<bool> vis(V, false), recStack(V, false);
        for (int i = 0; i < V; i++)
            if (!vis[i] && dfs(i, g, vis, recStack))
                return true;
        return false;
    }
};
```

#### 📝 **Complexity Analysis:**

- **Time Complexity:** `O(V + E)`
- **Space Complexity:** `O(V)` for recursion stack and visited tracking

#### ✅ **Why This Approach?**

This DFS-based method is intuitive for cycle detection and often simpler to implement, but may face recursion depth issues for very deep graphs.



## 📊 **3️⃣ DFS-Based Cycle Detection (Iterative using Stack)**

#### **Algorithm Steps:**

1. Convert the edge list into an adjacency list.
2. Instead of recursion, use an explicit stack along with two marker arrays to track visited nodes and nodes currently in the stack.
3. Check for back edges indicating a cycle.

```cpp
class Solution {
public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> g(V);
        for (auto &e : edges)
            g[e[0]].push_back(e[1]);
        vector<bool> vis(V, false), inStack(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                stack<int> st;
                st.push(i);
                while (!st.empty()) {
                    int u = st.top();
                    if (!vis[u]) {
                        vis[u] = inStack[u] = true;
                    }
                    bool found = false;
                    for (int v : g[u]) {
                        if (!vis[v]) {
                            st.push(v);
                            found = true;
                            break;
                        } else if (inStack[v]) {
                            return true;
                        }
                    }
                    if (!found) {
                        inStack[u] = false;
                        st.pop();
                    }
                }
            }
        }
        return false;
    }
};
```

#### 📝 **Complexity Analysis:**

- **Time Complexity:** `O(V + E)`
- **Space Complexity:** `O(V)`

#### ✅ **Why This Approach?**

It avoids recursion by using an explicit stack, which is useful in environments with limited recursion depth, though the logic can be slightly more complex.



### 🆚 **Comparison of Approaches**

| **Approach**                      | ⏱️ **Time Complexity** | 🗂️ **Space Complexity**  | ✅ **Pros**                               | ⚠️ **Cons**                                      |
|-----------------------------------|-------------------------|---------------------------|--------------------------------------------|--------------------------------------------------|
| **Kahn’s Algorithm (BFS)**         | 🟢 O(V + E)                | 🟡 O(V + E)                  | Iterative; detects cycles via topological order | Requires extra space for the in-degree array     |
| **DFS (Recursive)**               | 🟢 O(V + E)                | 🟢 O(V)                      | Simple; intuitive for cycle detection      | Risk of stack overflow on deep graphs            |
| **DFS (Iterative using Stack)**   | 🟢 O(V + E)                | 🟢 O(V)                      | Avoids recursion; explicit stack control   | Slightly more complex to implement               |

✅ **Best Choice?**

- Use **Kahn’s Algorithm** when you also need topological ordering or a fully iterative solution.
- Use **DFS (Recursive)** for simpler implementations on smaller or moderately sized graphs.
- Use **DFS (Iterative)** in environments where recursion depth is a concern.

</details>


## **Code (Java)**

```java
class Solution {
    public boolean isCyclic(int V, int[][] edges) {
        List<Integer>[] g = new ArrayList[V];
        int[] in = new int[V];
        for (int i = 0; i < V; i++) g[i] = new ArrayList<>();
        for (int[] e : edges) { g[e[0]].add(e[1]); in[e[1]]++; }
        Queue<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < V; i++) if (in[i] == 0) q.add(i);
        int c = 0;
        while (!q.isEmpty()) {
            int u = q.poll(); c++;
            for (int v : g[u]) if (--in[v] == 0) q.add(v);
        }
        return c != V;
    }
}
```


## **Code (Python)**

```python
class Solution:
    def isCycle(self, V, edges):
        g = [[] for _ in range(V)]
        in_d = [0]*V
        for u, v in edges: g[u].append(v); in_d[v] += 1
        q = [i for i in range(V) if in_d[i] == 0]
        c = 0
        while q:
            u = q.pop(0); c += 1
            for v in g[u]:
                in_d[v] -= 1
                if in_d[v] == 0: q.append(v)
        return c != V
```



## **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
