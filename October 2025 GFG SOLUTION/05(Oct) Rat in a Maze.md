---
title: "🐭 Rat in a Maze | GFG Solution 🔍"
keywords🏷️: ["🐭 rat in maze", "🔍 backtracking", "📍 DFS", "🔄 recursion", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Rat in a Maze problem: find all possible paths from source to destination using backtracking and DFS technique. 🚀"
date: 📅 2025-10-05
---

# *05. Rat in a Maze*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1)

## **🧩 Problem Description**

Consider a rat placed at position **(0, 0)** in an **n x n** square matrix `maze[][]`. The rat's goal is to reach the destination at position **(n-1, n-1)**. The rat can move in four possible directions: **'U'** (up), **'D'** (down), **'L'** (left), **'R'** (right).

The matrix contains only two possible values:
- **0**: A blocked cell through which the rat cannot travel.
- **1**: A free cell that the rat can pass through.

Your task is to find **all possible paths** the rat can take to reach the destination, starting from **(0, 0)** and ending at **(n-1, n-1)**, under the condition that the rat cannot revisit any cell along the same path. The rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.

If no path exists, return an empty list.

**Note:** Return the final result vector in **lexicographically smallest order**.

## **📘 Examples**

### Example 1

```cpp
Input: maze[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - 
DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
```

### Example 2

```cpp
Input: maze[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists as the destination cell (1, 1) is blocked.
```

### Example 3

```cpp
Input: maze[][] = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
Output: ["DDRR", "RRDD"]
Explanation: The rat has two possible paths to reach the destination: DDRR and RRDD.
```

## **🔒 Constraints**

* $2 \le n \le 5$
* $0 \le \text{maze}[i][j] \le 1$

## **✅ My Approach**

The optimal approach uses **Backtracking with DFS (Depth-First Search)** to explore all possible paths from source to destination:

### **Backtracking + DFS**

1. **Initial Check:**
   * Verify if the starting cell `(0, 0)` and destination cell `(n-1, n-1)` are both open (value = 1).
   * If either is blocked, return an empty result immediately.

2. **Mark as Visited:**
   * Before exploring from a cell, mark it as visited by setting `maze[i][j] = 0`.
   * This prevents the rat from revisiting the same cell in the current path.

3. **Explore Four Directions:**
   * Try all four directions in lexicographical order: **D (Down), L (Left), R (Right), U (Up)**.
   * For each direction, check if the next cell is valid (within bounds and not blocked).
   * Recursively explore the next cell by appending the direction character to the current path.

4. **Base Case - Destination Reached:**
   * When the rat reaches `(n-1, n-1)`, add the current path string to the result list.

5. **Backtrack:**
   * After exploring all paths from the current cell, restore it by setting `maze[i][j] = 1`.
   * This allows the cell to be used in other potential paths.

6. **Return All Paths:**
   * The result naturally maintains lexicographical order due to the direction exploration sequence.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(4^(n²)), as in the worst case, we explore all four directions from each cell. The total number of cells is n², and at each cell, we have up to 4 choices, leading to an exponential time complexity.
* **Expected Auxiliary Space Complexity:** O(n²), where the recursion stack can go as deep as n² in the worst case (visiting all cells), and we modify the maze in-place for marking visited cells.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<string> ratInMaze(vector<vector<int>>& m) {
        vector<string> res;
        int n = m.size();
        if (!m[0][0] || !m[n-1][n-1]) return res;
        string p = "";
        solve(0, 0, m, n, p, res);
        return res;
    }
    
    void solve(int i, int j, vector<vector<int>>& m, int n, string p, vector<string>& res) {
        if (i == n-1 && j == n-1) {
            res.push_back(p);
            return;
        }
        m[i][j] = 0;
        if (i+1 < n && m[i+1][j]) solve(i+1, j, m, n, p+'D', res);
        if (j-1 >= 0 && m[i][j-1]) solve(i, j-1, m, n, p+'L', res);
        if (j+1 < n && m[i][j+1]) solve(i, j+1, m, n, p+'R', res);
        if (i-1 >= 0 && m[i-1][j]) solve(i-1, j, m, n, p+'U', res);
        m[i][j] = 1;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Visited Array Approach**

### 💡 Algorithm Steps:

1. Use a separate boolean visited array instead of modifying the maze.
2. Mark cells as visited during exploration to avoid cycles.
3. Recursively explore all four directions in lexicographical order.
4. Backtrack by unmarking visited cells after exploring all paths.

```cpp
class Solution {
public:
    vector<string> ratInMaze(vector<vector<int>>& m) {
        vector<string> ans;
        int n = m.size();
        if (!m[0][0] || !m[n-1][n-1]) return ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        dfs(0, 0, m, vis, "", ans, n);
        return ans;
    }
    
    void dfs(int r, int c, vector<vector<int>>& m, vector<vector<int>>& vis, string path, vector<string>& ans, int n) {
        if (r == n-1 && c == n-1) {
            ans.push_back(path);
            return;
        }
        vis[r][c] = 1;
        if (r+1 < n && !vis[r+1][c] && m[r+1][c]) dfs(r+1, c, m, vis, path+'D', ans, n);
        if (c-1 >= 0 && !vis[r][c-1] && m[r][c-1]) dfs(r, c-1, m, vis, path+'L', ans, n);
        if (c+1 < n && !vis[r][c+1] && m[r][c+1]) dfs(r, c+1, m, vis, path+'R', ans, n);
        if (r-1 >= 0 && !vis[r-1][c] && m[r-1][c]) dfs(r-1, c, m, vis, path+'U', ans, n);
        vis[r][c] = 0;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(4^(n²)) - At each cell, we have 4 choices (worst case)
* **Auxiliary Space:** 💾 O(n²) - Extra visited matrix and recursion stack

### ✅ **Why This Approach?**

* Preserves original maze input without modification
* Clear separation of concerns with dedicated visited tracking
* Easier to debug and understand state changes

## 📊 **3️⃣ Direction Array with Loop**

### 💡 Algorithm Steps:

1. Define direction vectors and corresponding characters in arrays.
2. Use a single loop to iterate through all four directions.
3. Check validity and recursively explore each valid direction.
4. Automatically maintains lexicographical order with proper array ordering.

```cpp
class Solution {
public:
    vector<string> ratInMaze(vector<vector<int>>& m) {
        vector<string> result;
        int n = m.size();
        if (!m[0][0] || !m[n-1][n-1]) return result;
        helper(0, 0, "", m, result);
        return result;
    }
    
    void helper(int x, int y, string path, vector<vector<int>>& m, vector<string>& result) {
        int n = m.size();
        if (x == n-1 && y == n-1) {
            result.push_back(path);
            return;
        }
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};
        char dir[] = {'D', 'L', 'R', 'U'};
        m[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && m[nx][ny]) {
                helper(nx, ny, path + dir[i], m, result);
            }
        }
        m[x][y] = 1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(4^(n²)) - Exploring all possible paths
* **Auxiliary Space:** 💾 O(n²) - Recursion stack depth

### ✅ **Why This Approach?**

* Compact and maintainable with direction arrays
* Easy to modify directions or add new ones
* Cleaner code structure with loop-based exploration

## 📊 **4️⃣ Bitmasking Visited State**

### 💡 Algorithm Steps:

1. Use bitmasking to represent visited cells efficiently.
2. Each cell position is mapped to a bit in an integer.
3. Set bit when visiting, unset during backtracking.
4. Memory efficient for smaller maze sizes (up to 5x5).

```cpp
class Solution {
public:
    vector<string> ratInMaze(vector<vector<int>>& m) {
        vector<string> paths;
        int n = m.size();
        if (!m[0][0] || !m[n-1][n-1]) return paths;
        search(0, 0, 0, "", m, paths, n);
        return paths;
    }
    
    void search(int r, int c, int mask, string curr, vector<vector<int>>& m, vector<string>& paths, int n) {
        if (r == n-1 && c == n-1) {
            paths.push_back(curr);
            return;
        }
        int pos = r * n + c;
        mask |= (1 << pos);
        int dr[] = {1, 0, 0, -1}, dc[] = {0, -1, 1, 0};
        string d = "DLRU";
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            int npos = nr * n + nc;
            if (nr >= 0 && nc >= 0 && nr < n && nc < n && m[nr][nc] && !(mask & (1 << npos))) {
                search(nr, nc, mask, curr + d[i], m, paths, n);
            }
        }
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(4^(n²)) - Same path exploration complexity
* **Auxiliary Space:** 💾 O(n²) - Recursion stack only (O(1) extra for bitmask)

### ✅ **Why This Approach?**

* Space-efficient visited state representation
* No need for separate visited array
* Excellent for competitive programming with size constraints

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **In-place Modification**      | 🟢 O(4^(n²))           | 🟢 O(n²)                | 🚀 Minimal extra space            | 🔧 Modifies input maze               |
| 🔍 **Visited Array**              | 🟢 O(4^(n²))           | 🟡 O(n²)                | 📖 Preserves original maze        | 💾 Extra array overhead              |
| 📊 **Direction Array**            | 🟢 O(4^(n²))           | 🟢 O(n²)                | 🎯 Clean maintainable code        | 🔧 Slightly more initialization      |
| 🔄 **Bitmasking**                 | 🟢 O(4^(n²))           | 🟢 O(n²)                | ⭐ Space efficient tracking       | 🐌 Limited to smaller mazes          |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal space usage**                            | 🥇 **In-place Modification**         | ★★★★★                     |
| 📖 **Input preservation needed**                      | 🥈 **Visited Array**                 | ★★★★☆                     |
| 🔧 **Scalability & Maintenance**                      | 🥉 **Direction Array**               | ★★★★☆                     |
| 🎯 **Competitive Programming**                        | 🏅 **Bitmasking**                    | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<String> ratInMaze(int[][] m) {
        ArrayList<String> res = new ArrayList<>();
        int n = m.length;
        if (m[0][0] == 0 || m[n-1][n-1] == 0) return res;
        solve(0, 0, m, n, "", res);
        return res;
    }
    
    void solve(int i, int j, int[][] m, int n, String p, ArrayList<String> res) {
        if (i == n-1 && j == n-1) {
            res.add(p);
            return;
        }
        m[i][j] = 0;
        if (i+1 < n && m[i+1][j] == 1) solve(i+1, j, m, n, p+'D', res);
        if (j-1 >= 0 && m[i][j-1] == 1) solve(i, j-1, m, n, p+'L', res);
        if (j+1 < n && m[i][j+1] == 1) solve(i, j+1, m, n, p+'R', res);
        if (i-1 >= 0 && m[i-1][j] == 1) solve(i-1, j, m, n, p+'U', res);
        m[i][j] = 1;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def ratInMaze(self, m):
        res = []
        n = len(m)
        if not m[0][0] or not m[n-1][n-1]: return res
        self.solve(0, 0, m, n, "", res)
        return res
    
    def solve(self, i, j, m, n, p, res):
        if i == n-1 and j == n-1:
            res.append(p)
            return
        m[i][j] = 0
        if i+1 < n and m[i+1][j]: self.solve(i+1, j, m, n, p+'D', res)
        if j-1 >= 0 and m[i][j-1]: self.solve(i, j-1, m, n, p+'L', res)
        if j+1 < n and m[i][j+1]: self.solve(i, j+1, m, n, p+'R', res)
        if i-1 >= 0 and m[i-1][j]: self.solve(i-1, j, m, n, p+'U', res)
        m[i][j] = 1
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
