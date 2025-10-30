---
title: "🔄 Replace O's with X's | GFG Solution 🎯"
keywords🏷️: ["🔄 surrounded regions", "🌊 DFS", "📍 BFS", "🔗 graph traversal", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Replace O's with X's problem: replace all 'O' surrounded by 'X' using boundary traversal and DFS/BFS techniques. 🚀"
date: 📅 2025-10-30
---

# *30. Replace O's with X's*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1)

## **🧩 Problem Description**

You are given a grid[][] of size n*m, where every element is either 'O' or 'X'. Your task is to replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

## **📘 Examples**

### Example 1

```cpp
Input: 
grid[][] = [['X', 'X', 'X', 'X'], 
          ['X', 'O', 'X', 'X'], 
          ['X', 'O', 'O', 'X'], 
          ['X', 'O', 'X', 'X'], 
          ['X', 'X', 'O', 'O']]
Output: 
[['X', 'X', 'X', 'X'], 
['X', 'X', 'X', 'X'], 
['X', 'X', 'X', 'X'], 
['X', 'X', 'X', 'X'], 
['X', 'X', 'O', 'O']]
Explanation: We only changed those 'O' that are surrounded by 'X'
```

### Example 2

```cpp
Input: 
grid[][] = [['X', 'O', 'X', 'X'], 
          ['X', 'O', 'X', 'X'], 
          ['X', 'O', 'O', 'X'], 
          ['X', 'O', 'X', 'X'], 
          ['X', 'X', 'O', 'O']]
Output: 
[['X', 'O', 'X', 'X'], 
['X', 'O', 'X', 'X'], 
['X', 'O', 'O', 'X'], 
['X', 'O', 'X', 'X'], 
['X', 'X', 'O', 'O']]
Explanation: There's no 'O' that's surround by 'X'.
```

### Example 3

```cpp
Input: 
grid[][] = [['X', 'X', 'X'], 
          ['X', 'O', 'X'], 
          ['X', 'X', 'X']]
Output: 
[['X', 'X', 'X'], 
['X', 'X', 'X'], 
['X', 'X', 'X']]
Explanation: There's only one 'O' that's surround by 'X'.
```

## **🔒 Constraints**

* $1 \le \text{grid.size()} \le 100$
* $1 \le \text{grid[0].size()} \le 100$

## **✅ My Approach**

The optimal approach uses **boundary traversal with DFS/BFS** to identify 'O' cells that are NOT surrounded:

### **Boundary DFS Marking**

1. **Mark Safe Regions:**
   * Replace all 'O' cells with temporary marker '-' throughout the grid.
   * Any 'O' connected to boundary cannot be surrounded.

2. **Traverse Boundaries:**
   * Start DFS/BFS from all boundary cells containing '-'.
   * Mark all connected '-' cells back to 'O' as they are safe from replacement.

3. **Process Four Edges:**
   * Check top row, bottom row, left column, and right column.
   * For each '-' found on boundary, recursively mark all connected regions.

4. **Final Replacement:**
   * All remaining '-' cells are surrounded, so replace them with 'X'.
   * Cells marked as 'O' in step 2 remain unchanged.

5. **Key Insight:**
   * Instead of finding surrounded regions directly, find regions that touch boundaries.
   * Everything else is automatically surrounded.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(m×n), where m is the number of rows and n is the number of columns. Each cell is visited at most twice - once during marking and once during DFS traversal.
* **Expected Auxiliary Space Complexity:** O(m×n), as in the worst case the recursion stack can go as deep as the number of cells in the grid for DFS traversal.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    void fill(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size();
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (g[i][j] == 'O') g[i][j] = '-';
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || g[i][j] != '-') return;
            g[i][j] = 'O';
            dfs(i + 1, j); dfs(i - 1, j); dfs(i, j + 1); dfs(i, j - 1);
        };
        for (int i = 0; i < m; i++) { dfs(i, 0); dfs(i, n - 1); }
        for (int j = 0; j < n; j++) { dfs(0, j); dfs(m - 1, j); }
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (g[i][j] == '-') g[i][j] = 'X';
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ BFS Queue-Based Approach**

### 💡 Algorithm Steps:

1. Replace all 'O' with temporary marker '-' throughout the grid.
2. Use BFS from boundary cells to mark connected regions with 'O'.
3. Process cells level by level using a queue for breadth-first traversal.
4. Convert remaining '-' cells to 'X' as they are surrounded regions.

```cpp
class Solution {
public:
    void fill(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size();
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            if (g[i][j] == 'O') { g[i][j] = '-'; if (i == 0 || i == m - 1 || j == 0 || j == n - 1) q.push({i, j}); }
        }
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (g[x][y] != '-') continue;
            g[x][y] = 'O';
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && g[nx][ny] == '-') q.push({nx, ny});
            }
        }
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (g[i][j] == '-') g[i][j] = 'X';
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m×n) - Visit each cell at most once
* **Auxiliary Space:** 💾 O(m×n) - Queue can hold all boundary-connected cells

### ✅ **Why This Approach?**

* Iterative approach avoids stack overflow on large grids
* Level-by-level processing provides clear visualization
* Better for grids with deep connected components

## 📊 **3️⃣ Union-Find Disjoint Set**

### 💡 Algorithm Steps:

1. Create virtual dummy node for all boundary-connected regions.
2. Union all 'O' cells with their adjacent 'O' neighbors.
3. Union boundary 'O' cells with the dummy node.
4. Cells not connected to dummy node are surrounded regions.

```cpp
class Solution {
    vector<int> p;
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void unite(int a, int b) { p[find(a)] = find(b); }
public:
    void fill(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size();
        p.resize(m * n + 1);
        iota(p.begin(), p.end(), 0);
        int dummy = m * n;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            if (g[i][j] == 'O') {
                int idx = i * n + j;
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) unite(idx, dummy);
                if (i > 0 && g[i - 1][j] == 'O') unite(idx, (i - 1) * n + j);
                if (j > 0 && g[i][j - 1] == 'O') unite(idx, i * n + j - 1);
            }
        }
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
            if (g[i][j] == 'O' && find(i * n + j) != find(dummy)) g[i][j] = 'X';
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m×n×α(m×n)) - α is inverse Ackermann function (nearly constant)
* **Auxiliary Space:** 💾 O(m×n) - Parent array for union-find structure

### ✅ **Why This Approach?**

* Elegant mathematical approach using disjoint sets
* Natural way to group connected components
* Useful when multiple queries needed on connectivity

## 📊 **4️⃣ Iterative DFS with Stack**

### 💡 Algorithm Steps:

1. Mark all 'O' cells as temporary marker '-'.
2. Use explicit stack for DFS to avoid recursion overhead.
3. Process boundary cells and mark connected components.
4. Convert remaining '-' to 'X' for surrounded regions.

```cpp
class Solution {
public:
    void fill(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size();
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (g[i][j] == 'O') g[i][j] = '-';
        stack<pair<int,int>> st;
        for (int i = 0; i < m; i++) { if (g[i][0] == '-') st.push({i, 0}); if (g[i][n - 1] == '-') st.push({i, n - 1}); }
        for (int j = 0; j < n; j++) { if (g[0][j] == '-') st.push({0, j}); if (g[m - 1][j] == '-') st.push({m - 1, j}); }
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        while (!st.empty()) {
            auto [x, y] = st.top(); st.pop();
            if (x < 0 || x >= m || y < 0 || y >= n || g[x][y] != '-') continue;
            g[x][y] = 'O';
            for (int k = 0; k < 4; k++) st.push({x + dx[k], y + dy[k]});
        }
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (g[i][j] == '-') g[i][j] = 'X';
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m×n) - Each cell visited once
* **Auxiliary Space:** 💾 O(m×n) - Stack can hold all cells in worst case

### ✅ **Why This Approach?**

* Avoids recursion stack overflow issues
* More control over stack memory usage
* DFS benefits with iterative implementation safety

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔄 **Recursive DFS**              | 🟢 O(m×n)              | 🟡 O(m×n)               | 🎯 Clean and concise code         | ⚠️ Stack overflow risk on large grids |
| 🌊 **BFS Queue**                  | 🟢 O(m×n)              | 🟡 O(m×n)               | 🔒 No stack overflow              | 💾 Extra queue memory                |
| 🔗 **Union-Find**                 | 🟢 O(m×n×α)            | 🟡 O(m×n)               | 🧮 Mathematical elegance          | 🔧 Complex implementation            |
| 📚 **Iterative DFS**              | 🟢 O(m×n)              | 🟡 O(m×n)               | ⚡ DFS benefits without recursion | 🔨 More verbose code                 |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Small to medium grids**                      | 🥇 **Recursive DFS**                  | ★★★★★                     |
| 🔒 **Large grids or safety critical**             | 🥈 **BFS Queue**                      | ★★★★★                     |
| 🧮 **Multiple connectivity queries**              | 🥉 **Union-Find**                     | ★★★★☆                     |
| ⚡ **Balance between DFS and safety**             | 🏅 **Iterative DFS**                  | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public void fill(char[][] g) {
        int m = g.length, n = g[0].length;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (g[i][j] == 'O') g[i][j] = '-';
        for (int i = 0; i < m; i++) { dfs(g, i, 0, m, n); dfs(g, i, n - 1, m, n); }
        for (int j = 0; j < n; j++) { dfs(g, 0, j, m, n); dfs(g, m - 1, j, m, n); }
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (g[i][j] == '-') g[i][j] = 'X';
    }
    void dfs(char[][] g, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || g[i][j] != '-') return;
        g[i][j] = 'O';
        dfs(g, i + 1, j, m, n); dfs(g, i - 1, j, m, n); dfs(g, i, j + 1, m, n); dfs(g, i, j - 1, m, n);
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def fill(self, g):
        m, n = len(g), len(g[0])
        for i in range(m):
            for j in range(n):
                if g[i][j] == 'O': g[i][j] = '-'
        def dfs(i, j):
            if i < 0 or i >= m or j < 0 or j >= n or g[i][j] != '-': return
            g[i][j] = 'O'
            dfs(i + 1, j); dfs(i - 1, j); dfs(i, j + 1); dfs(i, j - 1)
        for i in range(m): dfs(i, 0); dfs(i, n - 1)
        for j in range(n): dfs(0, j); dfs(m - 1, j)
        for i in range(m):
            for j in range(n):
                if g[i][j] == '-': g[i][j] = 'X'
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


