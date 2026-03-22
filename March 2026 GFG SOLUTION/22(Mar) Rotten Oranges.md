---
title: "🍊 Rotten Oranges | GFG Solution 🔍"
keywords🏷️: ["🍊 rotten oranges", "🔍 multi-source BFS", "📍 matrix traversal", "📈 level-order BFS", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Rotten Oranges problem: find minimum time for all oranges to rot using multi-source BFS level-by-level traversal. 🚀"
date: 📅 2025-03-22
---

# *22. Rotten Oranges*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/rotten-oranges2536/1)

## **🧩 Problem Description**

You are given a matrix `mat[][]` where each cell has one of three values:

* `0` — Empty cell
* `1` — Cell with a **fresh** orange
* `2` — Cell with a **rotten** orange

A rotten orange at index `(i, j)` can rot adjacent fresh oranges at `(i-1, j)`, `(i+1, j)`, `(i, j-1)`, `(i, j+1)` in **one unit of time**.

Your task is to determine the **minimum time** required so that all the oranges become rotten. If it is impossible to rot every orange, return `-1`.

## **📘 Examples**

### Example 1

```
Input: mat[][] = [[2, 1, 0, 2, 1],
                  [1, 0, 1, 2, 1],
                  [1, 0, 0, 2, 1]]
Output: 2
Explanation: Oranges at (0,0), (0,3), (1,3), and (2,3) rot adjacent fresh oranges in successive 
time frames. All fresh oranges become rotten after 2 units of time.
```

### Example 2

```
Input: mat[][] = [[2, 1, 0, 2, 1],
                  [0, 0, 1, 2, 1],
                  [1, 0, 0, 2, 1]]
Output: -1
Explanation: The fresh orange at (2,0) can never be reached by any rotten orange, 
so not all oranges can rot.
```

## **🔒 Constraints**

* $1 \le \text{mat.size()} \le 500$
* $1 \le \text{mat[0].size()} \le 500$
* $\text{mat}[i][j] \in \{0, 1, 2\}$

## **✅ My Approach**

The optimal approach uses **Multi-Source BFS** (Breadth-First Search) — treating all initially rotten oranges as simultaneous BFS starting points and spreading rot level by level:

### **Multi-Source BFS (Level-Order Traversal)**

1. **Initialize:**
   * Scan the entire matrix. Push all rotten orange positions `(i, j)` into the queue and count all fresh oranges.
   * If `fresh == 0` initially, return `0` immediately.

2. **BFS Level by Level:**
   * Each BFS level represents one unit of time.
   * For every rotten orange in the current level, try to rot all 4 adjacent fresh neighbors.
   * Mark newly rotted oranges as `2`, decrement `fresh`, and push them into the queue for the next level.

3. **Early Exit:**
   * The outer `while` loop has condition `!q.empty() && fresh > 0`, so BFS stops as soon as all fresh oranges are rotted — no unnecessary iterations.

4. **Final Check:**
   * If `fresh > 0` after BFS completes, isolated fresh oranges exist — return `-1`.
   * Otherwise return `time` (number of BFS levels processed).

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × m), as every cell in the matrix is visited at most once during the BFS traversal, where n and m are the number of rows and columns respectively.
* **Expected Auxiliary Space Complexity:** O(n × m), as the BFS queue can hold at most all cells of the matrix in the worst case when all oranges are initially rotten.

## **🖥️ Code (C)**

```c
typedef struct {
    int x, y;
} Point;

int orangesRotting(int** mat, int n, int m) {
    Point q[n * m];
    int front = 0, back = 0, fresh = 0, time = 0;
    int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 2) q[back++] = (Point){i, j};
            else if (mat[i][j] == 1) fresh++;
        }
    while (front < back && fresh) {
        time++;
        int sz = back - front;
        while (sz--) {
            Point p = q[front++];
            for (int d = 0; d < 4; d++) {
                int nx = p.x+dx[d], ny = p.y+dy[d];
                if (nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]==1)
                    mat[nx][ny] = 2, fresh--, q[back++] = (Point){nx, ny};
            }
        }
    }
    return fresh ? -1 : time;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), fresh = 0, time = 0;
        queue<pair<int,int>> q;
        int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) q.push({i, j});
                else if (mat[i][j] == 1) fresh++;
            }
        while (!q.empty() && fresh) {
            time++;
            for (int sz = q.size(); sz--;) {
                auto [x, y] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x+dx[d], ny = y+dy[d];
                    if (nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]==1)
                        mat[nx][ny] = 2, fresh--, q.push({nx, ny});
                }
            }
        }
        return fresh ? -1 : time;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ BFS Without Modifying Input (Distance Array)**

### 💡 Algorithm Steps:

1. Allocate a `dist[][]` grid initialized to `-1` to track earliest rot time for each cell, leaving the original matrix untouched.
2. Push all initially rotten positions into the queue and set their `dist` to `0`.
3. Standard BFS: for each dequeued cell, attempt to rot all 4 unvisited fresh neighbors, setting `dist[nx][ny] = dist[x][y] + 1`.
4. Track the maximum distance seen. If `fresh` is still non-zero after BFS, return `-1`.

```cpp
class Solution {
public:
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), fresh = 0, ans = 0;
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int,int>> q;
        int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) { dist[i][j] = 0; q.push({i,j}); }
                else if (mat[i][j] == 1) fresh++;
            }
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x+dx[d], ny = y+dy[d];
                if (nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]==1 && dist[nx][ny]==-1) {
                    dist[nx][ny] = dist[x][y]+1;
                    ans = max(ans, dist[nx][ny]);
                    fresh--;
                    q.push({nx, ny});
                }
            }
        }
        return fresh ? -1 : ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m) — Each cell is enqueued and dequeued at most once
* **Auxiliary Space:** 💾 O(n × m) — Extra distance grid plus the BFS queue

### ✅ **Why This Approach?**

* Completely non-destructive — the original matrix is never modified
* The distance grid is useful when you need to know *when* each cell rotted
* Cleaner separation between input data and BFS state

---

## 📊 **3️⃣ BFS Using Index Encoding (No Pair Overhead)**

### 💡 Algorithm Steps:

1. Encode cell `(i, j)` as a single integer `i*m + j` to store in a plain integer queue, avoiding `pair` or struct allocation.
2. During BFS, decode with `x = encoded / m`, `y = encoded % m` for neighbor computation.
3. Track fresh count and BFS levels identically to the main approach.
4. Return `-1` if fresh remains, else return the number of levels elapsed.

```cpp
class Solution {
public:
    int orangesRot(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), fresh = 0, time = 0;
        queue<int> q;
        int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) q.push(i*m+j);
                else if (mat[i][j] == 1) fresh++;
            }
        while (!q.empty() && fresh) {
            time++;
            for (int sz = q.size(); sz--;) {
                int x = q.front()/m, y = q.front()%m; q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x+dx[d], ny = y+dy[d];
                    if (nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]==1)
                        mat[nx][ny]=2, fresh--, q.push(nx*m+ny);
                }
            }
        }
        return fresh ? -1 : time;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m) — Single complete BFS pass
* **Auxiliary Space:** 💾 O(n × m) — Integer queue can hold at most all cells

### ✅ **Why This Approach?**

* Integer queue is more cache-friendly than a pair queue — each element is 4 bytes vs 8 bytes
* Compact encoding reduces queue memory footprint by half
* Preferred in competitive programming where constant factors matter

---

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach** | ⏱️ **Time** | 💾 **Space** | ✅ **Pros** | ⚠️ **Cons** |
|---|---|---|---|---|
| 🏷️ **Fresh-Count BFS (Main)** | 🟢 O(n×m) | 🟢 O(n×m) | 🚀 Early exit, clean logic | 🔧 Mutates input matrix |
| 🗺️ **Distance Array BFS** | 🟢 O(n×m) | 🟡 O(n×m) extra | 📖 Non-destructive, debug-friendly | 💾 Extra distance grid needed |
| 🔢 **Index-Encoded BFS** | 🟢 O(n×m) | 🟢 O(n×m) | ⭐ Cache-friendly, minimal overhead | 🔧 Manual encode/decode logic |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario** | 🎖️ **Recommended** | 🔥 **Rating** |
|---|---|---|
| 🏅 **General / Interviews** | 🥇 **Fresh-Count BFS** | ★★★★★ |
| 🔒 **Read-only input constraint** | 🥈 **Distance Array BFS** | ★★★★☆ |
| ⚡ **Competitive / Tight memory** | 🥉 **Index-Encoded BFS** | ★★★★☆ |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int orangesRot(int[][] mat) {
        int n = mat.length, m = mat[0].length, fresh = 0, time = 0;
        Queue<int[]> q = new ArrayDeque<>();
        int[] dx = {0,0,1,-1}, dy = {1,-1,0,0};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) q.add(new int[]{i, j});
                else if (mat[i][j] == 1) fresh++;
            }
        while (!q.isEmpty() && fresh > 0) {
            time++;
            for (int sz = q.size(); sz-- > 0;) {
                int[] p = q.poll();
                for (int d = 0; d < 4; d++) {
                    int nx = p[0]+dx[d], ny = p[1]+dy[d];
                    if (nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]==1) {
                        mat[nx][ny] = 2; fresh--; q.add(new int[]{nx, ny});
                    }
                }
            }
        }
        return fresh > 0 ? -1 : time;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def orangesRot(self, mat):
        from collections import deque
        n, m = len(mat), len(mat[0])
        q, fresh = deque(), 0
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 2: q.append((i, j))
                elif mat[i][j] == 1: fresh += 1
        time, dirs = 0, [(0,1),(0,-1),(1,0),(-1,0)]
        while q and fresh:
            time += 1
            for _ in range(len(q)):
                x, y = q.popleft()
                for dx, dy in dirs:
                    nx, ny = x+dx, y+dy
                    if 0<=nx<n and 0<=ny<m and mat[nx][ny]==1:
                        mat[nx][ny] = 2; fresh -= 1; q.append((nx, ny))
        return -1 if fresh else time
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
