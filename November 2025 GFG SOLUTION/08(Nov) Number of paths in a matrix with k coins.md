---
title: "🎯 Number of Paths in a Matrix with K Coins | GFG Solution 🔍"
keywords🏷️: ["🎯 matrix paths", "🔍 dynamic programming", "📍 path counting", "📈 space optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Number of Paths in a Matrix with K Coins problem: count paths from top-left to bottom-right collecting exactly k coins using optimized dynamic programming. 🚀"
date: 📅 2025-11-08
---

# *08. Number of Paths in a Matrix with K Coins*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1)

## **🧩 Problem Description**

You are given a matrix `mat[][]` of size `n x m`, where each cell contains some coins. Your task is to count the number of ways to collect **exactly k coins** while moving from the **top-left cell** to the **bottom-right cell**.

From a cell `(i, j)`, you can only move to:
- Cell `(i+1, j)` (down)
- Cell `(i, j+1)` (right)

## **📘 Examples**

### Example 1

```cpp
Input: k = 12, mat[][] = [[1, 2, 3],
                          [4, 6, 5],
                          [3, 2, 1]]
Output: 2
Explanation: There are 2 possible paths with exactly 12 coins:
- Path 1: 1 + 2 + 6 + 2 + 1 = 12
- Path 2: 1 + 2 + 3 + 5 + 1 = 12
```

### Example 2

```cpp
Input: k = 16, mat[][] = [[1, 2, 3], 
                          [4, 6, 5], 
                          [9, 8, 7]]
Output: 0
Explanation: There are no possible paths that sum to exactly 16 coins.
```

## **🔒 Constraints**

* $1 \le k \le 100$
* $1 \le n, m \le 100$
* $0 \le \text{mat}[i][j] \le 200$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming with Space Optimization** to efficiently count paths while tracking coin sums:

### **2D Row-Optimized DP**

1. **State Definition:**
   * `dp[j][s]` = number of ways to reach column `j` in current row with sum `s`
   * We only need to track the previous row, not the entire matrix history

2. **Initialization:**
   * Start at `(0, 0)` with `mat[0][0]` coins
   * Initialize first row by moving right, accumulating coins

3. **Row-by-Row Processing:**
   * For each new row, create a fresh DP table
   * For each cell `(i, j)`:
     - Can reach from left: `ndp[j-1][s - mat[i][j]]`
     - Can reach from top: `dp[j][s - mat[i][j]]`
   * Sum both contributions for total paths to `(i, j)` with sum `s`

4. **Space Optimization:**
   * Only maintain DP arrays for current and previous row
   * Reduces space from O(n × m × k) to O(m × k)

5. **Result Extraction:**
   * Return `dp[m-1][k]` = paths reaching bottom-right with exactly k coins

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × m × k), where n and m are matrix dimensions and k is the target sum. For each of the n × m cells, we iterate through all possible sums up to k to compute the number of paths.
* **Expected Auxiliary Space Complexity:** O(m × k), as we maintain only two rows of the DP table at any time (current and previous row), each storing states for m columns and k+1 possible sums. This is a significant optimization over the naive O(n × m × k) space approach.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(k + 1, 0));
        if (mat[0][0] <= k) dp[0][mat[0][0]] = 1;
        for (int j = 1; j < m; j++)
            for (int s = mat[0][j]; s <= k; s++)
                dp[j][s] = dp[j - 1][s - mat[0][j]];
        for (int i = 1; i < n; i++) {
            vector<vector<int>> ndp(m, vector<int>(k + 1, 0));
            if (mat[i][0] <= k)
                for (int s = mat[i][0]; s <= k; s++)
                    ndp[0][s] = dp[0][s - mat[i][0]];
            for (int j = 1; j < m; j++)
                for (int s = mat[i][j]; s <= k; s++)
                    ndp[j][s] = ndp[j - 1][s - mat[i][j]] + dp[j][s - mat[i][j]];
            dp = ndp;
        }
        return dp[m - 1][k];
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Standard 3D DP Approach**

### 💡 Algorithm Steps:

1. Create DP table indexed by position and current sum.
2. Base case: starting cell has one path with its value if within k.
3. For each cell, add ways from top and left positions.
4. Return count of paths ending at bottom-right with sum k.

```cpp
class Solution {
public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k + 1)));
        if (mat[0][0] <= k) dp[0][0][mat[0][0]] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int s = 0; s <= k; s++)
                    if (dp[i][j][s]) {
                        if (j + 1 < m && s + mat[i][j + 1] <= k)
                            dp[i][j + 1][s + mat[i][j + 1]] += dp[i][j][s];
                        if (i + 1 < n && s + mat[i + 1][j] <= k)
                            dp[i + 1][j][s + mat[i + 1][j]] += dp[i][j][s];
                    }
        return dp[n - 1][m - 1][k];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m × k) - Iterate through all states
* **Auxiliary Space:** 💾 O(n × m × k) - Full 3D array

### ✅ **Why This Approach?**

* Most intuitive DP formulation
* Clear state representation
* Easy to debug and verify

## 📊 **3️⃣ DFS with Memoization**

### 💡 Algorithm Steps:

1. Recursively explore paths from start to end.
2. Track current position and accumulated sum.
3. Cache results to avoid recomputation.
4. Count valid paths reaching target with sum k.

```cpp
class Solution {
public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        map<tuple<int,int,int>, int> memo;
        function<int(int, int, int)> solve = [&](int i, int j, int sum) -> int {
            if (i >= n || j >= m || sum > k) return 0;
            sum += mat[i][j];
            if (sum > k) return 0;
            if (i == n - 1 && j == m - 1) return sum == k;
            auto key = make_tuple(i, j, sum);
            if (memo.count(key)) return memo[key];
            return memo[key] = solve(i + 1, j, sum) + solve(i, j + 1, sum);
        };
        return solve(0, 0, 0);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m × k) - Each state visited once
* **Auxiliary Space:** 💾 O(n × m × k) - Memoization map and stack

### ✅ **Why This Approach?**

* Natural problem decomposition
* Flexible for variations
* Good for understanding recursion

## 📊 **4️⃣ Bottom-Up Iterative DP**

### 💡 Algorithm Steps:

1. Build solution from top-left to bottom-right.
2. For each cell and sum, compute ways to reach it.
3. Combine paths from top cell and left cell.
4. Extract final answer for target position and sum.

```cpp
class Solution {
public:
    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<vector<int>>> f(n, vector<vector<int>>(m, vector<int>(k + 1)));
        f[0][0][mat[0][0]] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int s = 0; s <= k; s++)
                    if (f[i][j][s]) {
                        if (i + 1 < n) {
                            int ns = s + mat[i + 1][j];
                            if (ns <= k) f[i + 1][j][ns] += f[i][j][s];
                        }
                        if (j + 1 < m) {
                            int ns = s + mat[i][j + 1];
                            if (ns <= k) f[i][j + 1][ns] += f[i][j][s];
                        }
                    }
        return f[n - 1][m - 1][k];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m × k) - Triple nested loops
* **Auxiliary Space:** 💾 O(n × m × k) - 3D DP array

### ✅ **Why This Approach?**

* Standard DP pattern
* No recursion overhead
* Clear forward progression

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **2D Row Optimization**       | 🟢 O(n × m × k)        | 🟢 O(m × k)             | 🚀 Good space-time balance        | 🔧 Moderate complexity               |
| 🔍 **Standard 3D DP**             | 🟢 O(n × m × k)        | 🔴 O(n × m × k)         | 📖 Most straightforward           | 💾 High memory usage                 |
| 📊 **DFS Memoization**            | 🟢 O(n × m × k)        | 🔴 O(n × m × k)         | 🎯 Intuitive recursion            | 🐌 Stack overhead                    |
| 🔄 **Bottom-Up DP**               | 🟢 O(n × m × k)        | 🔴 O(n × m × k)         | ⭐ No recursion                   | 💾 Full space requirement            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Production code**                                | 🥇 **2D Row Optimization**           | ★★★★★                     |
| 📖 **Learning/Teaching**                              | 🥈 **Standard 3D DP**                | ★★★★★                     |
| 🔧 **Interview discussion**                           | 🥉 **DFS Memoization**               | ★★★★☆                     |
| 🎯 **Contest/Speed coding**                           | 🏅 **Bottom-Up DP**                  | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int numberOfPath(int[][] mat, int k) {
        int n = mat.length, m = mat[0].length;
        int[][] dp = new int[m][k + 1];
        if (mat[0][0] <= k) dp[0][mat[0][0]] = 1;
        for (int j = 1; j < m; j++)
            for (int s = mat[0][j]; s <= k; s++)
                dp[j][s] = dp[j - 1][s - mat[0][j]];
        for (int i = 1; i < n; i++) {
            int[][] ndp = new int[m][k + 1];
            if (mat[i][0] <= k)
                for (int s = mat[i][0]; s <= k; s++)
                    ndp[0][s] = dp[0][s - mat[i][0]];
            for (int j = 1; j < m; j++)
                for (int s = mat[i][j]; s <= k; s++)
                    ndp[j][s] = ndp[j - 1][s - mat[i][j]] + dp[j][s - mat[i][j]];
            dp = ndp;
        }
        return dp[m - 1][k];
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def numberOfPath(self, mat, k):
        n, m = len(mat), len(mat[0])
        dp = [[0] * (k + 1) for _ in range(m)]
        if mat[0][0] <= k:
            dp[0][mat[0][0]] = 1
        for j in range(1, m):
            for s in range(mat[0][j], k + 1):
                dp[j][s] = dp[j - 1][s - mat[0][j]]
        for i in range(1, n):
            ndp = [[0] * (k + 1) for _ in range(m)]
            if mat[i][0] <= k:
                for s in range(mat[i][0], k + 1):
                    ndp[0][s] = dp[0][s - mat[i][0]]
            for j in range(1, m):
                for s in range(mat[i][j], k + 1):
                    ndp[j][s] = ndp[j - 1][s - mat[i][j]] + dp[j][s - mat[i][j]]
            dp = ndp
        return dp[m - 1][k]
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

