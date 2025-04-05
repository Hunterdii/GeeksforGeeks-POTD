# 21. Shortest Path in Undirected Graph

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1)

## Note: Sorry for uploading late; my exam is going on.

### Problem Description

You are given an undirected graph with `n` nodes and `m` edges, all edges having a unit weight. Your task is to find the shortest path from a given source vertex `src` to all other vertices. If any vertex is unreachable from the source, return `-1` for that vertex.

**Example:**

**Input:**

```
n = 9, m = 10
edges = [[0,1],[0,3],[3,4],[4,5],[5,6],[1,2],[2,6],[6,7],[7,8],[6,8]]
src = 0
```

**Output:**

```
0 1 2 1 2 3 3 4 4
```

**Input:**

```
n = 4, m = 2
edges = [[1,3],[3,0]]
src = 3
```

**Output:**

```
1 1 -1 0
```

### Constraints:

- \(1 \leq n, m \leq 10^4\)
- \(0 \leq edges[i][j] \leq n-1\)

### My Approach

1. **Graph Representation:**

   - First, represent the graph using an adjacency list, where each vertex points to a list of its neighboring vertices.

2. **Breadth-First Search (BFS):**
   - Use BFS to explore the shortest path in an unweighted graph. Initialize a distance array `dist` with `INT_MAX` (or `float('inf')` in Python) to signify that the nodes are initially unreachable.
   - Start BFS from the source node `src`, setting its distance to `0`.
   - For each node, update the distance of its neighboring nodes if the current path offers a shorter distance.
   - If a node remains with `INT_MAX` distance after BFS, set its distance to `-1` to indicate that it is unreachable from the source.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(N + E), where `N` is the number of nodes and `E` is the number of edges, since we are performing a BFS traversal across the graph.
- **Expected Auxiliary Space Complexity:** O(N), as we store the adjacency list and the distance array, both of size `N`.

### Code (C++)

```cpp
class Solution {
public:
    std::vector<int> shortestPath(std::vector<std::vector<int>>& edges, int N, int M, int src) {
        std::vector<std::vector<int>> adj(N);
        for (int i = 0; i < M; ++i) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        std::vector<int> dist(N, INT_MAX);
        std::queue<int> q;
        dist[src] = 0;
        q.push(src);
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (dist[node] + 1 < dist[neighbor]) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;
    }
};
```

### Code (Java)

```java
import java.util.*;

class Solution {
    public int[] shortestPath(int[][] edges, int n, int m, int src) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            adj.get(edges[i][0]).add(edges[i][1]);
            adj.get(edges[i][1]).add(edges[i][0]);
        }
        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        Queue<Integer> q = new LinkedList<>();
        dist[src] = 0;
        q.add(src);
        while (!q.isEmpty()) {
            int node = q.poll();

            for (int neighbor : adj.get(node)) {
                if (dist[node] + 1 < dist[neighbor]) {
                    dist[neighbor] = dist[node] + 1;
                    q.add(neighbor);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (dist[i] == Integer.MAX_VALUE) dist[i] = -1;
        }

        return dist;
    }
}
```

### Code (Python)

```python
from collections import deque, defaultdict

class Solution:
    def shortestPath(self, edges, n, m, src):
        adj = defaultdict(list)
        for i in range(m):
            adj[edges[i][0]].append(edges[i][1])
            adj[edges[i][1]].append(edges[i][0])
        dist = [float('inf')] * n
        dist[src] = 0
        q = deque([src])
        while q:
            node = q.popleft()

            for neighbor in adj[node]:
                if dist[node] + 1 < dist[neighbor]:
                    dist[neighbor] = dist[node] + 1
                    q.append(neighbor)
        dist = [-1 if d == float('inf') else d for d in dist]

        return dist
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
