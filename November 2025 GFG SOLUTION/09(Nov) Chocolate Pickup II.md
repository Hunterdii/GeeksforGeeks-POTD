---
title: "🍫 Chocolate Pickup II | GFG Solution 🤖"
keywords🏷️: ["🍫 chocolate pickup", "🤖 two robots", "📍 dynamic programming", "📈 memoization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Chocolate Pickup II problem: maximize chocolates collected by a robot traveling to bottom-right and back to top-left using optimal path selection with DP. 🚀"
date: 📅 2025-11-09
---

# *09. Chocolate Pickup II*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/chocolate-pickup-ii/1)

## **🧩 Problem Description**

You are given a square matrix `mat[][]` of size `n × n`, where each cell represents either a blocked cell or a cell containing some chocolates. If `mat[i][j]` equals `-1`, then the cell is blocked and cannot be visited. Otherwise, `mat[i][j]` represents the number of chocolates present in that cell.

The task is to determine the **maximum number of chocolates** a robot can collect by:
1. Starting from the top-left cell `(0, 0)`
2. Moving to the bottom-right cell `(n-1, n-1)`
3. Returning back to `(0, 0)`

**Movement Rules:**
- **Forward journey** `(0,0) → (n-1,n-1)`: Robot can move only **right** `(i, j+1)` or **down** `(i+1, j)`
- **Return journey** `(n-1,n-1) → (0,0)`: Robot can move only **left** `(i, j-1)` or **up** `(i-1, j)`

**Important:** After collecting chocolates from a cell `(i, j)`, that cell becomes empty (`mat[i][j] = 0`) for the next visit. If there is no valid path for either journey, return `0`.

## **📘 Examples**

### Example 1

```cpp
Input: mat[][] = [[0, 1, -1], 
                  [1, 1, -1], 
                  [1, 1, 2]]
Output: 7
Explanation: Optimal path: (0,0) → (1,0) → (2,0) → (2,1) → (2,2) → (2,1) → (1,1) → (0,1) → (0,0)
Total chocolates = 0 + 1 + 1 + 1 + 2 + 0 + 1 + 1 + 0 = 7
```

### Example 2

```cpp
Input: mat[][] = [[1, 1, 0], 
                  [1, 1, 1], 
                  [0, 1, 1]]
Output: 7
Explanation: One optimal path collects chocolates: 1 + 1 + 0 + 1 + 1 + 1 + 1 + 1 + 0 = 7
```

### Example 3

```cpp
Input: mat[][] = [[1, 0, -1],
                  [2, -1, -1],
                  [1, -1, 3]]
Output: 0
Explanation: No valid path exists to reach (2,2) from (0,0) due to blocked cells.
```

## **🔒 Constraints**

* $1 \le n \le 50$
* $-1 \le \text{mat}[i][j] \le 100$

## **✅ My Approach**

The optimal solution treats this as a **simultaneous two-robot path problem** using **Dynamic Programming with Memoization**:

### **Coordinate Transformation Strategy**

1. **Key Insight:** Instead of simulating forward and return journeys separately, we can model this as two robots moving simultaneously from `(0,0)` to `(n-1,n-1)`.

2. **State Representation:**
   - Track robot 1 at position `(i1, j1)` and robot 2 at position `(i2, j2)`
   - Use coordinate transformation: If both robots have moved the same total distance, then `i1 + j1 = i2 + j2`
   - This reduces state space to `(i1, j1, j2)` where `i2 = i1 + j1 - j2`

3. **Movement Transitions:**
   - Each robot has 2 choices at each step: move **down** or move **right**
   - Total combinations: 2 × 2 = 4 possible transitions per state
   - Direction encoding: `d=0` means down, `d=1` means right

4. **Chocolate Collection:**
   - If robots are at the same cell `(i1 == i2 && j1 == j2)`: collect chocolates only once
   - If robots are at different cells: collect from both cells

5. **Base Cases:**
   - If any robot goes out of bounds or hits a blocked cell: return very negative value
   - If robot 1 reaches `(n-1, m-1)` and both robots are at the same position: return `mat[n-1][m-1]`

6. **Memoization:**
   - Cache results in 3D DP table `dp[i1][j1][j2]`
   - Avoid recomputation of overlapping subproblems

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × m² × 4), where n is the number of rows and m is the number of columns. We explore all possible states (i1, j1, j2) and for each state, we try 4 transitions (2 directions for each robot). Each state is computed only once due to memoization.
* **Expected Auxiliary Space Complexity:** O(n × m²), as we use a 3D DP table to store memoized results for all possible states of the two robots plus recursion stack space in case of recursive approach.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int chocolatePickup(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        function<int(int,int,int)> solve = [&](int i1, int j1, int j2) -> int {
            int i2 = i1 + j1 - j2;
            if (i1 >= n || i2 >= n || j1 >= m || j2 >= m || i2 < 0) return -1e8;
            if (mat[i1][j1] == -1 || mat[i2][j2] == -1) return -1e8;
            if (i1 == n - 1 && j1 == m - 1 && j2 == m - 1) return mat[i1][j1];
            if (dp[i1][j1][j2] != -1) return dp[i1][j1][j2];
            int res = -1e8;
            for (int d1 = 0; d1 < 2; d1++)
                for (int d2 = 0; d2 < 2; d2++)
                    res = max(res, solve(i1 + 1 - d1, j1 + d1, j2 + d2));
            res += mat[i1][j1];
            if (i1 != i2) res += mat[i2][j2];
            return dp[i1][j1][j2] = res;
        };
        return max(0, solve(0, 0, 0));
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Bottom-Up Iterative DP**

### 💡 Algorithm Steps:

1. Build 3D DP table iteratively from top to bottom without recursion.
2. Initialize base case at starting position (0,0,0).
3. For each state, compute all 4 possible transitions (down/right combinations).
4. Calculate second robot position using coordinate transformation formula.
5. Accumulate chocolates ensuring no double-counting when robots meet.

```cpp
class Solution {
public:
    int chocolatePickup(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, INT_MIN)));
        dp[0][0][0] = mat[0][0];
        for (int i = 0; i < n; i++) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    if (dp[i][j1][j2] == INT_MIN) continue;
                    int i2 = i + j1 - j2;
                    if (i2 < 0 || i2 >= n || mat[i][j1] == -1 || mat[i2][j2] == -1) continue;
                    for (int d1 = 0; d1 < 2; d1++) {
                        for (int d2 = 0; d2 < 2; d2++) {
                            int ni1 = i + 1 - d1, nj1 = j1 + d1;
                            int ni2 = i2 + 1 - d2, nj2 = j2 + d2;
                            if (ni1 >= n || ni2 >= n || nj1 >= m || nj2 >= m) continue;
                            if (mat[ni1][nj1] == -1 || mat[ni2][nj2] == -1) continue;
                            int val = dp[i][j1][j2] + mat[ni1][nj1];
                            if (ni1 != ni2) val += mat[ni2][nj2];
                            dp[ni1][nj1][nj2] = max(dp[ni1][nj1][nj2], val);
                        }
                    }
                }
            }
        }
        return max(0, dp[n - 1][m - 1][m - 1]);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n·m²·4) - Iterate through all states with 4 transition possibilities
* **Auxiliary Space:** 💾 O(n·m²) - 3D DP table storage

### ✅ **Why This Approach?**

* No recursion overhead or stack space usage
* Easier to trace and debug state transitions
* More intuitive forward-building DP pattern

## 📊 **3️⃣ Space-Optimized 2D DP**

### 💡 Algorithm Steps:

1. Reduce space complexity by maintaining only current and next layer states.
2. Use two 2D arrays instead of full 3D table for memory efficiency.
3. Process layer by layer, alternating between arrays.
4. Each layer depends only on previous layer in diagonal progression.
5. Extract final result from last computed layer.

```cpp
class Solution {
public:
    int chocolatePickup(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> cur(m, vector<int>(m, INT_MIN)), nxt(m, vector<int>(m, INT_MIN));
        cur[0][0] = mat[0][0];
        for (int i = 0; i < n - 1; i++) {
            fill(nxt.begin(), nxt.end(), vector<int>(m, INT_MIN));
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    if (cur[j1][j2] == INT_MIN) continue;
                    int i2 = i + j1 - j2;
                    if (i2 < 0 || i2 >= n || mat[i][j1] == -1 || mat[i2][j2] == -1) continue;
                    for (int d1 = 0; d1 < 2; d1++) {
                        for (int d2 = 0; d2 < 2; d2++) {
                            int ni1 = i + 1 - d1, nj1 = j1 + d1;
                            int ni2 = i2 + 1 - d2, nj2 = j2 + d2;
                            if (ni1 >= n || ni2 >= n || nj1 >= m || nj2 >= m) continue;
                            if (mat[ni1][nj1] == -1 || mat[ni2][nj2] == -1) continue;
                            int val = cur[j1][j2] + mat[ni1][nj1];
                            if (ni1 != ni2) val += mat[ni2][nj2];
                            nxt[nj1][nj2] = max(nxt[nj1][nj2], val);
                        }
                    }
                }
            }
            swap(cur, nxt);
        }
        return max(0, cur[m - 1][m - 1]);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n·m²·4) - Same time complexity as 3D approach
* **Auxiliary Space:** 💾 O(m²) - Only two 2D arrays maintained

### ✅ **Why This Approach?**

* Significant memory optimization for large grids
* Maintains same time efficiency as full DP
* Ideal for memory-constrained competitive programming

## 📊 **3️⃣ Path Coordinate Transformation**

### 💡 Algorithm Steps:

1. Transform problem using diagonal coordinate system for cleaner state representation.
2. Track robots using (row, col1, col2) instead of separate coordinates.
3. Use coordinate math to derive second robot position from first.
4. Apply standard DP with optimized state space traversal.
5. Handle boundary conditions using coordinate constraints.

```cpp
class Solution {
public:
    int chocolatePickup(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        map<tuple<int,int,int>, int> dp;
        function<int(int,int,int)> dfs = [&](int i1, int j1, int j2) -> int {
            int i2 = i1 + j1 - j2;
            if (i1 >= n || i2 >= n || i2 < 0 || j1 >= m || j2 >= m) return INT_MIN/2;
            if (mat[i1][j1] == -1 || mat[i2][j2] == -1) return INT_MIN/2;
            if (i1 == n - 1 && j1 == m - 1) return (j2 == m - 1) ? mat[i1][j1] : INT_MIN/2;
            auto key = make_tuple(i1, j1, j2);
            if (dp.count(key)) return dp[key];
            int res = INT_MIN/2;
            for (int d1 = 0; d1 < 2; d1++)
                for (int d2 = 0; d2 < 2; d2++)
                    res = max(res, dfs(i1 + 1 - d1, j1 + d1, j2 + d2));
            if (res > INT_MIN/2) {
                res += mat[i1][j1];
                if (i1 != i2) res += mat[i2][j2];
            }
            return dp[key] = res;
        };
        return max(0, dfs(0, 0, 0));
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n·m²·4) - All unique states computed with transitions
* **Auxiliary Space:** 💾 O(n·m²) - Map storage for sparse state space

### ✅ **Why This Approach?**

* Flexible memoization using map for sparse grids
* Clean coordinate transformation logic
* Easy to extend for variations of the problem

## 📊 **4️⃣ Optimized Recursive with Array DP**

### 💡 Algorithm Steps:

1. Combine recursion elegance with array-based memoization efficiency.
2. Pre-allocate DP array for faster access compared to map.
3. Use -1 as sentinel value to distinguish uncomputed states.
4. Implement tail-recursive pattern for better compiler optimization.
5. Cache results at return point for minimal overhead.

```cpp
class Solution {
    int n, m;
    int dp[100][100][100];
    int solve(int i1, int j1, int j2, vector<vector<int>>& mat) {
        int i2 = i1 + j1 - j2;
        if (i1 >= n || i2 >= n || i2 < 0 || j1 >= m || j2 >= m) return -1e8;
        if (mat[i1][j1] == -1 || mat[i2][j2] == -1) return -1e8;
        if (i1 == n - 1 && j1 == m - 1 && j2 == m - 1) return mat[i1][j1];
        if (dp[i1][j1][j2] != -1) return dp[i1][j1][j2];
        int res = -1e8;
        for (int d1 = 0; d1 < 2; d1++)
            for (int d2 = 0; d2 < 2; d2++)
                res = max(res, solve(i1 + 1 - d1, j1 + d1, j2 + d2, mat));
        res += mat[i1][j1];
        if (i1 != i2) res += mat[i2][j2];
        return dp[i1][j1][j2] = res;
    }
public:
    int chocolatePickup(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        memset(dp, -1, sizeof(dp));
        return max(0, solve(0, 0, 0, mat));
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n·m²·4) - Memoized recursion with constant time lookups
* **Auxiliary Space:** 💾 O(n·m²) - Fixed-size array allocation

### ✅ **Why This Approach?**

* Faster array access compared to map-based memoization
* Pre-allocated memory reduces allocation overhead
* Balance between recursion clarity and performance

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Lambda Recursion**           | 🟢 O(n·m²)             | 🟡 O(n·m²)              | 🚀 Clean modern C++ syntax        | 🔧 Lambda overhead                   |
| 🔍 **Bottom-Up DP**               | 🟢 O(n·m²)             | 🟡 O(n·m²)              | 📖 No recursion overhead          | 💾 Full 3D table needed              |
| 🔄 **Map Memoization**            | 🟢 O(n·m²)             | 🟡 O(n·m²)              | ⭐ Sparse state handling          | 🔧 Slower map operations             |
| 🎯 **Array Memoization**          | 🟢 O(n·m²)             | 🟡 O(n·m²)              | 💨 Fastest cache access           | 🔧 Fixed size constraints            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Competitive Programming**                        | 🥇 **Array Memoization**             | ★★★★★                     |
| 📖 **Code Readability**                               | 🥈 **Lambda Recursion**              | ★★★★★                     |
| 🎯 **Production Code**                                | 🥉 **Bottom-Up DP**                  | ★★★★☆                     |
| 🌟 **Interview Practice**                             | 🏅 **Lambda Recursion**              | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    int[][][] dp;
    int[][] mat;
    int n, m;
    
    int solve(int i1, int j1, int j2) {
        int i2 = i1 + j1 - j2;
        if (i1 >= n || i2 >= n || j1 >= m || j2 >= m || i2 < 0) return (int)-1e8;
        if (mat[i1][j1] == -1 || mat[i2][j2] == -1) return (int)-1e8;
        if (i1 == n - 1 && j1 == m - 1 && j2 == m - 1) return mat[i1][j1];
        if (dp[i1][j1][j2] != -1) return dp[i1][j1][j2];
        int res = (int)-1e8;
        for (int d1 = 0; d1 < 2; d1++)
            for (int d2 = 0; d2 < 2; d2++)
                res = Math.max(res, solve(i1 + 1 - d1, j1 + d1, j2 + d2));
        res += mat[i1][j1];
        if (i1 != i2) res += mat[i2][j2];
        return dp[i1][j1][j2] = res;
    }
    
    public int chocolatePickup(int[][] mat) {
        this.mat = mat;
        n = mat.length;
        m = mat[0].length;
        dp = new int[n][m][m];
        for (int[][] a : dp) for (int[] b : a) Arrays.fill(b, -1);
        return Math.max(0, solve(0, 0, 0));
    }
}
```

## **🐍 Code (Python)**

```python
class Solution: 
    def chocolatePickup(self, mat): 
        n, m = len(mat), len(mat[0])
        dp = [[[-1] * m for _ in range(m)] for _ in range(n)]
        
        def solve(i1, j1, j2):
            i2 = i1 + j1 - j2
            if i1 >= n or i2 >= n or j1 >= m or j2 >= m or i2 < 0:
                return -10**8
            if mat[i1][j1] == -1 or mat[i2][j2] == -1:
                return -10**8
            if i1 == n - 1 and j1 == m - 1 and j2 == m - 1:
                return mat[i1][j1]
            if dp[i1][j1][j2] != -1:
                return dp[i1][j1][j2]
            res = -10**8
            for d1 in range(2):
                for d2 in range(2):
                    res = max(res, solve(i1 + 1 - d1, j1 + d1, j2 + d2))
            res += mat[i1][j1]
            if i1 != i2:
                res += mat[i2][j2]
            dp[i1][j1][j2] = res
            return res
        
        return max(0, solve(0, 0, 0))
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












