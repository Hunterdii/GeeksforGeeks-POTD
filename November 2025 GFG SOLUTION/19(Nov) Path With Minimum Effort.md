---
title: "🗺️ Path With Minimum Effort | GFG Solution 🔍"
keywords🏷️: ["🗺️ path finding", "🔍 dijkstra", "📍 graph traversal", "📈 priority queue", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Path With Minimum Effort problem: find minimum cost path where cost is maximum absolute difference between consecutive cells using Dijkstra's algorithm. 🚀"
date: 📅 2025-11-19
---

# *19. Path With Minimum Effort*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1)

## **🧩 Problem Description**

You are given a 2D array `mat[][]` of size `n*m`. Your task is to find the **minimum possible path cost** from the top-left cell (0, 0) to the bottom-right cell (n-1, m-1) by moving up, down, left, or right between adjacent cells.

**Note:** The cost of a path is defined as the **maximum absolute difference** between the values of any two consecutive cells along that path.

## **📘 Examples**

### Example 1

```cpp
Input: mat[][] = [[7, 2, 6, 5],
                  [3, 1, 10, 8]]
Output: 4
Explanation: The route of [7, 3, 1, 2, 6, 5, 8] has a minimum value of maximum absolute 
difference between any two consecutive cells in the route, i.e., 4.
```

### Example 2

```cpp
Input: mat[][] = [[2, 2, 2, 1],
                  [8, 1, 2, 7],
                  [2, 2, 2, 8],
                  [2, 1, 4, 7],
                  [2, 2, 2, 2]]
Output: 0
Explanation: The route of [2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2] has a minimum value of 
maximum absolute difference between any two consecutive cells in the route, i.e., 0.
```

## **🔒 Constraints**

* $1 \le n, m \le 100$
* $0 \le \text{mat}[i][j] \le 10^6$

## **✅ My Approach**

The optimal approach uses **Dijkstra's Algorithm** with a **Priority Queue** to find the path with minimum effort:

### **Dijkstra's Algorithm with Modified Cost**

1. **Initialize Data Structures:**
   * Create a `dist` array initialized with infinity (1e9) to track minimum effort to reach each cell.
   * Use a min-heap priority queue storing tuples of (effort, x-coordinate, y-coordinate).
   * Start from (0, 0) with effort 0.

2. **Process Cells:**
   * Pop the cell with minimum effort from priority queue.
   * If destination (n-1, m-1) is reached, return the effort.
   * Skip if current effort is greater than recorded distance (already processed optimally).

3. **Explore Neighbors:**
   * For each of 4 directions (up, down, left, right):
     * Calculate new effort as maximum of current effort and absolute difference with neighbor.
     * If new effort is less than recorded distance for neighbor, update and push to queue.

4. **Cost Calculation:**
   * Path cost = maximum absolute difference encountered along the entire path.
   * Update using: `new_effort = max(current_effort, abs(mat[next] - mat[current]))`.

5. **Return Result:**
   * Return the minimum effort recorded for destination cell.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × m × log(n × m)), where n and m are the dimensions of the matrix. Each cell is processed at most once, and priority queue operations take O(log(n × m)) time. In the worst case, we may push each cell into the priority queue multiple times before finding the optimal path.
* **Expected Auxiliary Space Complexity:** O(n × m), as we maintain a distance array of size n × m and the priority queue can hold at most O(n × m) elements in the worst case.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minCostPath(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        while (!pq.empty()) {
            auto [d, x, y] = pq.top(); pq.pop();
            if (x == n - 1 && y == m - 1) return d;
            if (d > dist[x][y]) continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nd = max(d, abs(mat[nx][ny] - mat[x][y]));
                    if (nd < dist[nx][ny]) {
                        dist[nx][ny] = nd;
                        pq.push({nd, nx, ny});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Binary Search + BFS Approach**

### 💡 Algorithm Steps:

1. Binary search on the answer range from 0 to maximum possible difference.
2. For each mid value, check if we can reach destination with max cost ≤ mid.
3. Use BFS to verify if a path exists with the given cost constraint.
4. Narrow down the search space based on whether path exists or not.

```cpp
class Solution {
public:
    bool canReach(vector<vector<int>>& mat, int maxCost) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        queue<pair<int,int>> q;
        q.push({0, 0});
        vis[0][0] = true;
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (x == n - 1 && y == m - 1) return true;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    if (abs(mat[nx][ny] - mat[x][y]) <= maxCost) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return false;
    }
    int minCostPath(vector<vector<int>>& mat) {
        int lo = 0, hi = 1e9, ans = hi;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canReach(mat, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n*m*log(max_val)) - Binary search with BFS traversal
* **Auxiliary Space:** 💾 O(n*m) - Visited array for BFS

### ✅ **Why This Approach?**

* Efficient when answer range is large
* Clear separation of concerns with helper function
* Predictable memory usage pattern

## 📊 **3️⃣ Modified Dijkstra with Array**

### 💡 Algorithm Steps:

1. Use tuple with cost stored first for natural ordering in priority queue.
2. Track visited cells to avoid redundant processing.
3. Early termination when destination is reached from priority queue.
4. Compact representation using array initialization for directions.

```cpp
class Solution {
public:
    int minCostPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        pq.push({0, 0, 0});
        cost[0][0] = 0;
        while (!pq.empty()) {
            auto [c, x, y] = pq.top(); pq.pop();
            if (x == n - 1 && y == m - 1) return c;
            if (c > cost[x][y]) continue;
            for (auto [dx, dy] : vector<pair<int,int>>{{-1,0},{1,0},{0,-1},{0,1}}) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nc = max(c, abs(mat[nx][ny] - mat[x][y]));
                    if (nc < cost[nx][ny]) {
                        cost[nx][ny] = nc;
                        pq.push({nc, nx, ny});
                    }
                }
            }
        }
        return cost[n - 1][m - 1];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n*m*log(n*m)) - Priority queue operations dominate
* **Auxiliary Space:** 💾 O(n*m) - Cost array and priority queue

### ✅ **Why This Approach?**

* Cleaner syntax with array and structured bindings
* More readable direction handling
* Standard Dijkstra pattern with modern C++ features

## 📊 **4️⃣ Dynamic Programming Bottom-Up**

### 💡 Algorithm Steps:

1. Process cells in multiple passes to propagate minimum costs.
2. For each cell, update neighbors based on current minimum cost.
3. Repeat until no updates occur indicating convergence.
4. Return the cost at destination cell after stabilization.

```cpp
class Solution {
public:
    int minCostPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        dp[0][0] = 0;
        bool changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (dp[i][j] == 1e9) continue;
                    for (auto [di, dj] : vector<pair<int,int>>{{-1,0},{1,0},{0,-1},{0,1}}) {
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                            int newCost = max(dp[i][j], abs(mat[ni][nj] - mat[i][j]));
                            if (newCost < dp[ni][nj]) {
                                dp[ni][nj] = newCost;
                                changed = true;
                            }
                        }
                    }
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n*m*k) - k is number of iterations until convergence
* **Auxiliary Space:** 💾 O(n*m) - DP table only

### ✅ **Why This Approach?**

* No priority queue or complex data structures
* Iterative relaxation similar to Bellman-Ford
* Good for teaching shortest path concepts

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110/1115 test cases due to time constraints).


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Dijkstra's Algorithm**              | 🟡 O(n*m*log(n*m))                | 🟢 O(n*m)                 | 🚀 Guaranteed optimal solution           | 🔧 Priority queue overhead              |
| 🔍 **Binary Search + BFS**                  | 🟡 O(n*m*log(max))                | 🟢 O(n*m)                 | 📖 Works well for large ranges             | 💾 Multiple complete traversals              |
| 📊 **Modified Dijkstra**                    | 🟡 O(n*m*log(n*m))          | 🟢 O(n*m)                 | 🎯 Clean modern C++ syntax        | 🐌 Similar performance to basic            |
| 🔄 **DP Bottom-Up**                | 🔴 O(n*m*k)                | 🟢 O(n*m)                 | ⭐ Simple iterative approach               | 🔧 Unpredictable iterations            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General optimal solution**                     | 🥇 **Dijkstra's Algorithm**                 | ★★★★★                     |
| 📖 **Large value ranges**                           | 🥈 **Binary Search + BFS**                     | ★★★★☆                     |
| 🔧 **Modern C++ preferred**                            | 🥉 **Modified Dijkstra**                     | ★★★★★                     |
| 🎯 **Educational/Simple logic**                          | 🏅 **DP Bottom-Up**                 | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int minCostPath(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        int[][] dist = new int[n][m];
        for (int[] row : dist) Arrays.fill(row, Integer.MAX_VALUE);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{0, 0, 0});
        dist[0][0] = 0;
        int[] dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int d = curr[0], x = curr[1], y = curr[2];
            if (x == n - 1 && y == m - 1) return d;
            if (d > dist[x][y]) continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nd = Math.max(d, Math.abs(mat[nx][ny] - mat[x][y]));
                    if (nd < dist[nx][ny]) {
                        dist[nx][ny] = nd;
                        pq.offer(new int[]{nd, nx, ny});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
}
```

## **🐍 Code (Python)**

```python
from heapq import heappush, heappop

class Solution:
    def minCostPath(self, mat):
        n, m = len(mat), len(mat[0])
        dist = [[float('inf')] * m for _ in range(n)]
        pq = [(0, 0, 0)]
        dist[0][0] = 0
        dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
        while pq:
            d, x, y = heappop(pq)
            if x == n - 1 and y == m - 1: return d
            if d > dist[x][y]: continue
            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]
                if 0 <= nx < n and 0 <= ny < m:
                    nd = max(d, abs(mat[nx][ny] - mat[x][y]))
                    if nd < dist[nx][ny]:
                        dist[nx][ny] = nd
                        heappush(pq, (nd, nx, ny))
        return dist[n - 1][m - 1]
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
