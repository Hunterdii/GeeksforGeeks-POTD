---
title: "🚶 Unique Paths in a Grid | GFG Solution 🚧"
keywords🏷️: ["🚶 unique paths", "📊 dynamic programming", "🔄 DP", "📈 grid traversal", "📘 GFG", "🧩 obstacle grid", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Unique Paths in a Grid problem: count ways to traverse a grid with obstacles using optimized DP."
date: 📅 2025-06-02
---

# *02. Unique Paths in a Grid*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/unique-paths-in-a-grid--170647/1)

## **🧩 Problem Description**

You are given a 2D list `grid[][]` of size `n × m` consisting of values `0` and `1`.

* A value of `0` means that you can enter that cell.
* A value of `1` implies that entry to that cell is not allowed (an obstacle).

You start at the upper-left corner of the grid `(1, 1)` and you have to reach the bottom-right corner `(n, m)` by moving only **right** or **down** at each step.
Your task is to calculate the total number of ways to reach the target.

**Note:** The first `(1, 1)` and last `(n, m)` cells of the grid can also be `1`. It is guaranteed that the total number of ways will fit within a 32-bit integer.


## **📘 Examples**

### Example 1

```
Input: n = 3, m = 3,
grid = [
  [0, 0, 0],
  [0, 1, 0],
  [0, 0, 0]
]
```

```
Output: 2
Explanation:
There are two ways to reach the bottom-right corner:
1. Right → Right → Down → Down
2. Down → Down → Right → Right
```

### Example 2

```
Input: n = 1, m = 3,
grid = [[1, 0, 1]]
```

```
Output: 0
Explanation:
The start cell (1,1) is blocked by an obstacle (value = 1), so no path exists.
```


## **🔒 Constraints**

* $1 \le n \times m \le 10^6$
* Each `grid[i][j]` is either `0` or `1`.
* The result will fit in a 32-bit integer.


## **✅ My Approach**

We use **dynamic programming** with a **1D rolling array** to count the number of ways to reach each cell, optimizing space.

### **💡 Idea:**

* Let `dp[j]` represent the number of ways to reach cell `(i, j)` in the current row `i`.
* We iterate row by row. For each cell:

  1. If `grid[i][j] == 1` (obstacle), set `dp[j] = 0` (no way).
  2. Else, if `j > 0`, add `dp[j - 1]` (ways from the left) to `dp[j]` (which already holds ways from above).
* Initialize `dp[0]` as `1` if `grid[0][0] == 0`, else `0`.

This effectively uses the previous row’s `dp[j]` values (ways from above) and the current row’s left neighbor `dp[j - 1]` (ways from left).

### **⚙️ Algorithm Steps:**

1. Let `r = n`, `c = m`. Create a 1D array `dp` of size `c`, initialized to all zeros.
2. If `grid[0][0] == 0`, set `dp[0] = 1`; otherwise `dp[0] = 0`.
3. For each row `i` from `0` to `r - 1`:

   * For each column `j` from `0` to `c - 1`:

     1. If `grid[i][j] == 1`:

        * `dp[j] = 0` (no paths through an obstacle).
     2. Else if `j > 0`:

        * `dp[j] += dp[j - 1]` (add ways from the left).
4. At the end, `dp[c - 1]` holds the number of ways to reach `(r - 1, c - 1)`.


## 📝 **Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(n × m), as we process each of the $n \times m$ cells exactly once.
* **Expected Auxiliary Space Complexity:** O(m), since we use a single array of size `m` for DP.


## **🧑‍💻 Code (C++)**

```cpp
class Solution {
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        int r = grid.size(), c = grid[0].size();
        vector<int> dp(c);
        dp[0] = grid[0][0] == 0;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (grid[i][j]) dp[j] = 0;
                else if (j) dp[j] += dp[j - 1];
        return dp[c - 1];
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>


## 📊 **2️⃣ 2D Dynamic Programming (Tabulation)**

We use a 2D `dp` array where `dp[i][j]` denotes number of ways to reach cell `(i,j)`.

### 💡 Algorithm Steps:

1. Initialize a 2D `dp` array of size `r × c` with zeros.
2. If `grid[0][0]` is not blocked, set `dp[0][0] = 1`.
3. For the first row and first column, set `dp[i][0]` and `dp[0][j]` to 1 if no obstacles block the path; else 0.
4. For each cell `(i, j)`, if no obstacle, set `dp[i][j] = dp[i-1][j] + dp[i][j-1]`.
5. Return `dp[r-1][c-1]`.

```cpp
class Solution {
  public:
    int uniquePaths(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));
        if (grid[0][0]) return 0;
        dp[0][0] = 1;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (!grid[i][j]) {
                    if (i) dp[i][j] += dp[i - 1][j];
                    if (j) dp[i][j] += dp[i][j - 1];
                }
        return dp[r - 1][c - 1];
    }
};
```


### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m × n)
* **Auxiliary Space:** 💾 O(m × n)

### ✅ **Why This Approach?**

* Simple and straightforward.
* Useful when readability is more important than space optimization.


## 📊 **3️⃣ In-Place Grid Modification**

Instead of using extra arrays, overwrite `grid` itself to store the count of paths.

### 💡 Algorithm Steps:

1. If `grid[0][0] == 1`, return 0 immediately.
2. Set `grid[0][0] = 1` to represent path count.
3. Update first row and column to carry forward path counts until obstacles are found.
4. For other cells, update `grid[i][j] = grid[i-1][j] + grid[i][j-1]` if not blocked; else 0.
5. Return `grid[r-1][c-1]`.

```cpp
class Solution {
  public:
    int uniquePaths(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        if (grid[0][0] == 1) return 0;
        grid[0][0] = 1;
        for (int j = 1; j < c; ++j)
            grid[0][j] = (grid[0][j] == 1 ? 0 : grid[0][j - 1]);
        for (int i = 1; i < r; ++i)
            grid[i][0] = (grid[i][0] == 1 ? 0 : grid[i - 1][0]);
        for (int i = 1; i < r; ++i)
            for (int j = 1; j < c; ++j)
                grid[i][j] = (grid[i][j] == 1 ? 0 : grid[i - 1][j] + grid[i][j - 1]);
        return grid[r - 1][c - 1];
    }
};
```


### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m × n)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* No extra space is needed.
* Best when modifying the input grid is allowed.


## 📊 **4️⃣ Top-Down Recursion with Memoization**

Use recursion to explore paths from `(0,0)` to `(r-1,c-1)` and store results in a memo table to avoid recomputation.

### 💡 Algorithm Steps:

1. Use a 2D memo array initialized with -1.
2. Define recursive `dfs(i, j)` that:

   * Returns 0 if out of bounds or on an obstacle.
   * Returns 1 if at the start (0,0).
   * Otherwise returns sum of `dfs(i-1, j)` and `dfs(i, j-1)`.
3. Cache results to avoid recomputation.
4. Call `dfs(r-1, c-1)`.

```cpp
class Solution {
  public:
    int r, c;
    vector<vector<int>> memo;
    vector<vector<int>> *g;

    int dfs(int i, int j) {
        if (i < 0 || j < 0 || (*g)[i][j] == 1) return 0;
        if (i == 0 && j == 0) return 1;
        if (memo[i][j] != -1) return memo[i][j];
        int up = dfs(i - 1, j);
        int left = dfs(i, j - 1);
        return memo[i][j] = up + left;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        g = &grid;
        r = grid.size(); c = grid[0].size();
        memo.assign(r, vector<int>(c, -1));
        return dfs(r - 1, c - 1);
    }
};
```


### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m × n)
* **Auxiliary Space:** O(m × n) memo + O(m+n) recursion stack


### ✅ **Why This Approach?**

* Good for understanding recursion and memoization.
* Avoids unnecessary computation on blocked paths.





## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                             | ⚠️ **Cons**                              |
| ---------------------------------- | ---------------------- | ----------------------- | -------------------------------------- | ---------------------------------------- |
| 🔢 **1D DP (Rolling Array)**       | 🟢 O(n × m)            | 🟢 O(m)                 | Space-optimized, easy implementation   | Slightly less intuitive than 2D DP       |
| 📊 **2D DP (Tabulation)**          | 🟢 O(n × m)            | 🟡 O(n × m)             | Very intuitive, straightforward        | High space usage for large grids         |
| 🏗️ **In-Place Grid Modification** | 🟢 O(n × m)            | 🟢 O(1)                 | No extra space needed                  | Modifies input grid (side effect)        |
| 🔄 **Top-Down Memoized Recursion** | 🟢 O(n × m)            | 🔴 O(n × m) + recursion | Clear recursion logic with memoization | Extra stack space, overhead of recursion |

### 🏆 **Best Choice by Scenario**

| 🎯 **Scenario**                                     | 🥇 **Recommended Approach**     |
| --------------------------------------------------- | ------------------------------- |
| 🏁 Memory-constrained, large grids                  | 🥇 1D DP Rolling Array          |
| 💻 Prioritize clarity and debugging                 | 🥈 2D DP Tabulation             |
| ⚡ Strict space limitation and can modify input grid | 🥉 In-Place Grid Modification   |
| 🔍 Learning recursion and memoization               | 🎖️ Top-Down Memoized Recursion |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int uniquePaths(int[][] grid) {
        int r = grid.length, c = grid[0].length;
        int[] dp = new int[c];
        dp[0] = grid[0][0] == 0 ? 1 : 0;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (grid[i][j] == 1) dp[j] = 0;
                else if (j > 0) dp[j] += dp[j - 1];
        return dp[c - 1];
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def uniquePaths(self, grid):
        r, c = len(grid), len(grid[0])
        dp = [0] * c
        dp[0] = 1 if grid[0][0] == 0 else 0
        for i in range(r):
            for j in range(c):
                if grid[i][j] == 1:
                    dp[j] = 0
                elif j > 0:
                    dp[j] += dp[j - 1]
        return dp[-1]
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
