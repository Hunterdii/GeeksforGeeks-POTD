---
title: "🔢 Distance of Nearest Cell Having 1 | GFG Solution 🔍"
keywords🏷️: ["🔢 matrix distance", "🌊 BFS", "📍 multi-source BFS", "🗺️ grid traversal", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Distance of Nearest Cell Having 1 problem: find minimum distance to nearest 1 for every cell using multi-source BFS technique. 🚀"
date: 📅 2025-10-28
---

# *28. Distance of Nearest Cell Having 1*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1)

## **🧩 Problem Description**

You are given a binary grid `grid[][]`, where each cell contains either 0 or 1. Your task is to find the **distance of the nearest 1** for every cell in the grid.

The distance between two cells (i1, j1) and (i2, j2) is calculated as |i1 - i2| + |j1 - j2| (Manhattan distance). You need to return a matrix of the same size, where each cell (i, j) contains the minimum distance from grid[i][j] to the nearest cell having value 1.

## **📘 Examples**

### Example 1

```cpp
Input: grid[][] = [[0, 1, 1, 0], 
                   [1, 1, 0, 0], 
                   [0, 0, 1, 1]]
Output: [[1, 0, 0, 1], 
         [0, 0, 1, 1], 
         [1, 1, 0, 0]]
Explanation: 0's at (0,0), (0,3), (1,2), (1,3), (2,0) and (2,1) are at a distance 
of 1 from 1's at (0,1), (0,2), (0,2), (2,3), (1,0) and (1,1) respectively.
```

### Example 2

```cpp
Input: grid[][] = [[1, 0, 1], 
                   [1, 1, 0], 
                   [1, 0, 0]]
Output: [[0, 1, 0], 
         [0, 0, 1], 
         [0, 1, 2]]
Explanation: 0's at (0,1), (1,2), (2,1) and (2,2) are at a distance of 1, 1, 1 
and 2 from 1's at (0,0), (0,2), (2,0) and (1,1) respectively.
```

## **🔒 Constraints**

* $1 \le \text{grid.size()} \le 200$
* $1 \le \text{grid[0].size()} \le 200$

## **✅ My Approach**

The optimal approach uses **Multi-Source BFS** to efficiently compute distances from all cells containing 1 simultaneously:

### **Multi-Source BFS**

1. **Initialize Distance Matrix:**
   * Create a distance matrix initialized with -1 (unvisited marker).
   * Use a queue to store coordinates of cells.

2. **Mark All Source Cells:**
   * Traverse the entire grid to find all cells with value 1.
   * Set their distance to 0 and add them to the queue.
   * These act as multiple sources for BFS.

3. **BFS Traversal:**
   * Process each cell from the queue in level-order fashion.
   * Explore all 4 adjacent directions (up, down, left, right).
   * For each unvisited neighbor, calculate distance as current cell's distance + 1.
   * Mark the neighbor as visited and add to queue.

4. **Simultaneous Propagation:**
   * All cells with 1 propagate distances simultaneously.
   * This ensures each cell gets the minimum distance to any nearest 1.

5. **Return Result:**
   * The distance matrix contains minimum distances for all cells.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × m), where n is the number of rows and m is the number of columns. Each cell is visited exactly once during BFS traversal, and for each cell, we check at most 4 neighbors.
* **Expected Auxiliary Space Complexity:** O(n × m), as we use a queue that can hold all cells in the worst case, and a distance matrix of the same size as the input grid.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
        int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return dist;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Dynamic Programming Approach**

### 💡 Algorithm Steps:

1. First pass from top-left to bottom-right updating distances.
2. Consider distances from top and left neighbors only.
3. Second pass from bottom-right to top-left for reverse direction.
4. Consider distances from bottom and right neighbors for complete coverage.

```cpp
class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) dp[i][j] = 0;
                else {
                    if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                    if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
                }
        for (int i = n-1; i >= 0; i--)
            for (int j = m-1; j >= 0; j--) {
                if (i < n-1) dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
                if (j < m-1) dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
            }
        return dp;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n×m) - Two complete passes over grid
* **Auxiliary Space:** 💾 O(1) - Output array doesn't count

### ✅ **Why This Approach?**

* No queue overhead for memory efficiency
* Simple iterative logic without BFS complexity
* Better cache locality with sequential access

## 📊 **3️⃣ Brute Force Distance Calculation**

### 💡 Algorithm Steps:

1. For each cell in the grid iterate through all positions.
2. Calculate Manhattan distance to every cell containing 1.
3. Track minimum distance found across all 1 cells.
4. Store the minimum distance for current cell in result.

```cpp
class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m, 1e9));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int x = 0; x < n; x++)
                    for (int y = 0; y < m; y++)
                        if (grid[x][y] == 1)
                            res[i][j] = min(res[i][j], abs(i-x) + abs(j-y));
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²×m²) - Nested loops for all cell pairs
* **Auxiliary Space:** 💾 O(1) - Only output array used

### ✅ **Why This Approach?**

* Simplest to understand and implement
* No auxiliary data structures needed
* Works well for very small grids

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1010/1112 test cases due to time constraints).


## 📊 **4️⃣ Level-Order BFS with Distance Tracking**

### 💡 Algorithm Steps:

1. Initialize all cells with 1 to distance 0 and add to queue.
2. Process queue level by level maintaining current distance.
3. For each level increment distance counter before processing.
4. Update unvisited neighbors with current distance and enqueue them.

```cpp
class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            dist++;
            while (sz--) {
                auto [r, c] = q.front();
                q.pop();
                for (auto [dr, dc] : dirs) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc] == -1) {
                        ans[nr][nc] = dist;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n×m) - Each cell visited once
* **Auxiliary Space:** 💾 O(n×m) - Queue can hold all cells

### ✅ **Why This Approach?**

* Explicit level tracking for clarity
* Natural BFS pattern implementation
* Easy to understand distance propagation

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🌊 **Multi-Source BFS**           | 🟢 O(n×m)              | 🟡 O(n×m)               | 🚀 Optimal time complexity        | 💾 Queue space overhead              |
| 🔄 **Dynamic Programming**        | 🟢 O(n×m)              | 🟢 O(1)                 | 💾 Space efficient                | 🔧 Two-pass logic required           |
| 🔍 **Brute Force (TLE)**                | 🔴 O(n²×m²)            | 🟢 O(1)                 | 📖 Simple implementation          | 🐌 Very slow for large grids         |
| 📊 **Level-Order BFS**            | 🟢 O(n×m)              | 🟡 O(n×m)               | 🎯 Clear level tracking           | 💾 Extra distance variable           |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General optimal solution**                       | 🥇 **Multi-Source BFS**              | ★★★★★                     |
| 💾 **Memory constrained**                             | 🥈 **Dynamic Programming**           | ★★★★★                     |
| 📖 **Learning/Understanding**                         | 🥉 **Level-Order BFS**               | ★★★★☆                     |
| 🎓 **Small grids only**                               | 🏅 **Brute Force (TLE)**                   | ★★☆☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<ArrayList<Integer>> nearest(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        ArrayList<ArrayList<Integer>> dist = new ArrayList<>();
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            dist.add(new ArrayList<>());
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dist.get(i).add(0);
                    q.offer(new int[]{i, j});
                } else dist.get(i).add(-1);
            }
        }
        int[] dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0], y = cur[1];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist.get(nx).get(ny) == -1) {
                    dist.get(nx).set(ny, dist.get(x).get(y) + 1);
                    q.offer(new int[]{nx, ny});
                }
            }
        }
        return dist;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def nearest(self, grid):
        n, m = len(grid), len(grid[0])
        dist = [[-1] * m for _ in range(n)]
        q = []
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    dist[i][j] = 0
                    q.append((i, j))
        dx, dy = [0, 0, 1, -1], [1, -1, 0, 0]
        idx = 0
        while idx < len(q):
            x, y = q[idx]
            idx += 1
            for i in range(4):
                nx, ny = x + dx[i], y + dy[i]
                if 0 <= nx < n and 0 <= ny < m and dist[nx][ny] == -1:
                    dist[nx][ny] = dist[x][y] + 1
                    q.append((nx, ny))
        return dist
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
