## 13. Shortest Path in Weighted Undirected Graph

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1)

### Problem Description

You are given a weighted undirected graph having `n` vertices numbered from `1` to `n` and `m` edges along with their weights. Find the shortest path between the vertex `1` and the vertex `n`, if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element `-1`.

**Examples:**

Input:

```
n = 5, m = 6
edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
```

Output:

```
5
```

Explanation:
The shortest path from 1 to 5 is by the path 1 -> 4 -> 3 -> 5 whose weight is 5.

### My Approach

1. **Graph Representation:**

- Create a graph using an adjacency list to store the vertices and their respective weights.

2. **Dijkstra's Algorithm:**

- Use Dijkstra's algorithm to find the shortest path from vertex `1` to vertex `n`.
- Initialize the distance for the starting vertex `1` as `0` and all other vertices as `infinity`.
- Use a priority queue to explore the vertices based on the minimum distance.

3. **Path Reconstruction:**

- Keep track of the parent of each vertex to reconstruct the path once the shortest path to vertex `n` is found.
- If the distance to vertex `n` remains `infinity`, return `[-1]` indicating no path exists.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(m \* log(n)), as Dijkstra's algorithm explores each edge in logarithmic time.
- **Expected Auxiliary Space Complexity:** O(n + m), as we store the graph representation and additional data structures for Dijkstra's algorithm.

### Code

#### C++ Code

```cpp
class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (auto& edge : edges) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }

        vector<int> dist(n + 1, INT_MAX), parent(n + 1, -1);
        dist[1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, 1);

        while (!pq.empty()) {
            pair<int, int> current = pq.top();
            pq.pop();
            int weight = current.first;
            int node = current.second;

            if (weight > dist[node]) continue;

            for (auto& neighbor : graph[node]) {
                int adj = neighbor.first;
                int d = neighbor.second;
                if (dist[adj] > weight + d) {
                    dist[adj] = weight + d;
                    pq.emplace(dist[adj], adj);
                    parent[adj] = node;
                }
            }
        }

        vector<int> path;
        if (dist[n] == INT_MAX) {
            path.push_back(-1);
            return path;
        }

        for (int at = n; at != -1; at = parent[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());
        path.insert(path.begin(), dist[n]);

        return path;
    }
};
```

#### Java Code

```java
class Solution {
    public List<Integer> shortestPath(int n, int m, int edges[][]) {
        List<List<int[]>> graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            graph.get(edge[0]).add(new int[]{edge[1], edge[2]});
            graph.get(edge[1]).add(new int[]{edge[0], edge[2]});
        }

        int[] dist = new int[n + 1];
        int[] parent = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[1] = 0;

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[1]));
        pq.add(new int[]{1, 0});

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int node = current[0];
            int weight = current[1];

            if (weight > dist[node]) continue;

            for (int[] neighbor : graph.get(node)) {
                int adj = neighbor[0];
                int d = neighbor[1];
                if (dist[adj] > weight + d) {
                    dist[adj] = weight + d;
                    pq.add(new int[]{adj, dist[adj]});
                    parent[adj] = node;
                }
            }
        }

        List<Integer> path = new ArrayList<>();
        if (dist[n] == Integer.MAX_VALUE) {
            path.add(-1);
            return path;
        }

        for (int at = n; at != 0; at = parent[at]) {
            path.add(at);
        }
        Collections.reverse(path);
        path.add(0, dist[n]);

        return path;
    }
}
```

#### Python Code

```python
from collections import defaultdict
from heapq import heappush, heappop
from typing import List

class Solution:
    def shortestPath(self, n: int, m: int, edges: List[List[int]]) -> List[int]:
        par = [-1] * (n + 1)
        inf = float('inf')
        dist = [inf] * (n + 1)

        gp = defaultdict(list)
        for a, b, w in edges:
            gp[a].append((b, w))
            gp[b].append((a, w))

        pq = []
        heappush(pq, (0, 1, -1))
        while pq:
            w, node, p = heappop(pq)
            if w > dist[node]:
                continue
            dist[node] = w
            par[node] = p

            for adj, d in gp[node]:
                if dist[adj] > w + d:
                    dist[adj] = w + d
                    heappush(pq, (w + d, adj, node))

        if dist[n] == inf:
            return [-1]

        ans = []
        p = n
        while p != -1:
            ans.append(p)
            p = par[p]

        ans.append(dist[n])
        ans.reverse()
        return ans
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
