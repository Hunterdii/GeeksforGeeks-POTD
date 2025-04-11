---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Graph
---

# 🚀 _Day 11. Dijkstra’s Algorithm_ 🧠


The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/implementing-dijkstra-set-1-adjacency-matrix)

## 💡 **Problem Description:**

Given an **undirected, weighted graph** with **V** vertices numbered from **0** to **V-1** and **E** edges, represented by a 2D array `edges[][]` (where each `edges[i] = [u, v, w]` represents an edge between nodes **u** and **v** with weight **w**), find the shortest distance from a given source vertex **src** to all other vertices.  
Return an array of integers where the *ith* element denotes the shortest distance from the source vertex **src** to vertex **i**.

> **Note:** The graph is connected and does not contain any negative weight edge.


> **Note:** Sorry for uploading late, my Final Sem exam is going on.


## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**
```
V = 3
edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]]
src = 2
```

#### **Output:**
```
[4, 3, 0]
```

#### **Explanation:**  

<img src="https://github.com/user-attachments/assets/c49bf243-bd02-4e76-90cf-a69be01c5e60" width="40%">


- For vertex **0**: The shortest path is `2 -> 1 -> 0` with total distance **4**.  
- For vertex **1**: The shortest path is `2 -> 1` with total distance **3**.  
- For vertex **2**: The distance is **0** as it is the source.


### **Example 2:**

#### **Input:**
```
V = 5
edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]]
src = 0
```

#### **Output:**
```
[0, 4, 8, 10, 10]
```

#### **Explanation:** 

<img src="https://github.com/user-attachments/assets/b91a8560-bedc-4b4c-9637-22de781f3bc7" width="40%">


- For vertex **1**: The shortest path is `0 -> 1` with total distance **4**.  
- For vertex **2**: The shortest path is `0 -> 2` with total distance **8**.  
- For vertex **3**: The shortest path is `0 -> 2 -> 3` with total distance **10**.  
- For vertex **4**: The shortest path is `0 -> 1 -> 4` with total distance **10**.

### **🔐 Constraints**

- $1 \leq V \leq 10^4$  
- $1 ≤ E = edges.size() ≤ 10^5$
- $0 ≤ edges[i][j] ≤ 10^4$  
- $0 \leq src < V$  
- Edge weights are non-negative


## 🎯 **My Approach:**

### **Optimized Dijkstra’s Algorithm (Min-Heap + Adjacency List)**
1. **Build the Graph:** Convert the given edge list into an adjacency list representation.
2. **Initialize Distances:** Set a distance vector `d[]` with high values and update `d[src] = 0`.
3. **Min-Heap (Priority Queue):** Use a min-heap to pick the node with the smallest tentative distance.
4. **Relaxation:** For each neighboring vertex, update its distance if a shorter path is found.

### **Algorithm Steps:**
1. Convert the edges into an adjacency list `g`.
2. Initialize a distance array `d` of size **V** with a large value (e.g., `1e9`), and set `d[src] = 0`.
3. Push `(0, src)` into a min-heap.
4. While the heap is not empty:
   - Pop the top element (with the smallest tentative distance).
   - If the current distance is greater than the recorded distance, continue to the next.
   - Otherwise, for each adjacent vertex, check if the path through the current vertex gives a smaller distance; update and push the new pair in the heap.
5. Return the distance array `d` as the result.


## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O((V + E) * log V), since each vertex and edge is processed, and insertion/extraction from the heap takes logarithmic time.
- **Expected Auxiliary Space Complexity:** O(V + E), for the adjacency list and the additional storage used by the heap.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
// ✅ Optimized Dijkstra’s Algorithm (Min-Heap + Adjacency List)
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> g(V);
        for (auto &e : edges) g[e[0]].emplace_back(e[1], e[2]);
        vector<int> d(V, 1e9); d[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, src);
        while (!q.empty()) {
            auto p = q.top(); q.pop();
            if (p.first > d[p.second]) continue;
            for (auto &x : g[p.second])
                if (p.first + x.second < d[x.first])
                    q.emplace(d[x.first] = p.first + x.second, x.first);
        }
        return d;
    }
};
```


<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Dijkstra using Set instead of Min-Heap**

#### **Algorithm Steps:**

1. Build an adjacency list `g` from the edges.
2. Initialize distance array `d` with large values, and set `d[src] = 0`.
3. Use a `std::set` to mimic a min-priority queue, which maintains sorted order automatically.
4. At each step, pick the node with the smallest tentative distance.
5. For each adjacent node, if a shorter path is found, update and insert the new pair.

```cpp
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> g(V);
        for (auto &e : edges) g[e[0]].emplace_back(e[1], e[2]);

        vector<int> d(V, 1e9);
        d[src] = 0;
        set<pair<int, int>> st;
        st.emplace(0, src);

        while (!st.empty()) {
            pair<int, int> p = *st.begin();
            int du = p.first;
            int u = p.second;
            st.erase(st.begin());

            for (int i = 0; i < g[u].size(); ++i) {
                int v = g[u][i].first;
                int w = g[u][i].second;

                if (du + w < d[v]) {
                    st.erase({d[v], v});
                    d[v] = du + w;
                    st.emplace(d[v], v);
                }
            }
        }

        return d;
    }
};
```

#### 📝 **Complexity Analysis:**

- **Expected Time Complexity:** O((V + E) * log V)
- **Expected Auxiliary Space Complexity:** O(V + E)

#### ✅ **Why This Approach?**
- Leverages `std::set` to ease decrease-key operations.
- Provides more control over updates at the cost of increased insertion/erase overhead compared to the min-heap.


### 🆚 **Comparison of Approaches**

| **Approach**                           | ⏱️ **Time Complexity**         | 🗂️ **Space Complexity**    | ✅ **Pros**                                     | ⚠️ **Cons**                                 |
|----------------------------------------|-------------------------------|---------------------------|------------------------------------------------|---------------------------------------------|
| **Min-Heap (Priority Queue)**          | 🟢 O((V + E) * log V)           | 🟡 O(V + E)                | Fast for sparse graphs, standard implementation | Slightly verbose STL usage                  |
| **Set-Based Approach**                 | 🟡 O((V + E) * log V)           | 🟡 O(V + E)                | Easy key updates using ordered set             | Set operations can be slower than heap push   |

✅ **Best Choice?**

- **Min-Heap (Priority Queue):** Best for most competitive and real-world graph problems.
- **Set-Based Approach:** Use when you require more explicit key updates.

</details>

## **Code (Java)**

```java
class Solution {
    public int[] dijkstra(int V, int[][] edges, int src) {
        List<int[]>[] g = new List[V];
        for (int i = 0; i < V; i++) g[i] = new ArrayList<>();
        for (int[] e : edges) g[e[0]].add(new int[]{e[1], e[2]});
        int[] d = new int[V];
        Arrays.fill(d, Integer.MAX_VALUE);
        d[src] = 0;
        PriorityQueue<int[]> q = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        q.offer(new int[]{0, src});
        while (!q.isEmpty()) {
            int[] p = q.poll();
            if (p[0] > d[p[1]]) continue;
            for (int[] x : g[p[1]])
                if (p[0] + x[1] < d[x[0]])
                    q.offer(new int[]{d[x[0]] = p[0] + x[1], x[0]});
        }
        return d;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def dijkstra(self, V, edges, src):
        from heapq import heappush, heappop
        g = [[] for _ in range(V)]
        for u, v, w in edges:
            g[u].append((v, w))
        d = [float('inf')] * V
        d[src] = 0
        q = [(0, src)]
        while q:
            du, u = heappop(q)
            if du > d[u]: continue
            for v, w in g[u]:
                if du + w < d[v]:
                    d[v] = du + w
                    heappush(q, (d[v], v))
        return d
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
