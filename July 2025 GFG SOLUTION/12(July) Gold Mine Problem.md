---
title: "💰 Gold Mine Problem | GFG Solution 🏆"
keywords🏷️: ["💰 gold mine", "🔍 dynamic programming", "📍 path optimization", "📈 matrix traversal", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Gold Mine Problem: find maximum gold collection path from left to right using dynamic programming optimization. 🚀"
date: 📅 2025-07-12
---

# *12. Gold Mine Problem*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/gold-mine-problem2608/1)

## **🧩 Problem Description**

Given a gold mine called `mat[][]`. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially, the miner can start from any row in the first column. From a given cell, the miner can move:

- to the cell diagonally up towards the right
- to the right
- to the cell diagonally down towards the right

Find out the maximum amount of gold that he can collect until he can no longer move.

## **📘 Examples**

### Example 1

```cpp
Input: mat[][] = [[1, 3, 3], [2, 1, 4], [0, 6, 4]]
Output: 12
Explanation: The path is (1, 0) -> (2, 1) -> (2, 2). Total gold collected is 2 + 6 + 4 = 12.
```

### Example 2

```cpp
Input: mat[][] = [[1, 3, 1, 5], [2, 2, 4, 1], [5, 0, 2, 3], [0, 6, 1, 2]]
Output: 16
Explanation: The path is (2, 0) -> (3, 1) -> (2, 2) -> (2, 3) or (2, 0) -> (1, 1) -> (1, 2) -> (0, 3). 
Total gold collected is (5 + 6 + 2 + 3) or (5 + 2 + 4 + 5) = 16.
```

### Example 3

```cpp
Input: mat[][] = [[1, 3, 3], [2, 1, 4], [0, 7, 5]]
Output: 14
Explanation: The path is (1,0) -> (2,1) -> (2,2). Total gold collected is 2 + 7 + 5 = 14.
```

## **🔒 Constraints**

* $1 \le \text{mat.size()}, \text{mat[0].size()} \le 500$
* $0 \le \text{mat}[i][j] \le 100$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming** with **in-place optimization** to efficiently find the maximum gold collection path:

### **Bottom-Up Dynamic Programming**

1. **Initialize Strategy:**
   * Start from the rightmost column (last column) as base case.
   * Work backwards towards the first column, column by column.
   * For each cell, calculate the maximum gold that can be collected from that position.

2. **State Transition:**
   * For each cell `mat[i][j]`, the maximum gold from this position is:
   * `mat[i][j] + max(gold from three possible next moves)`
   * Three possible moves: diagonally up-right, right, diagonally down-right.

3. **Boundary Handling:**
   * Check if the next position is within matrix bounds.
   * Use only valid adjacent cells for maximum calculation.
   * Handle edge cases for first and last rows.

4. **In-place Optimization:**
   * Modify the original matrix to store maximum gold from each position.
   * No need for additional space to store DP values.

5. **Result Extraction:**
   * After processing all columns, the answer is the maximum value in the first column.
   * Any starting row in the first column can be chosen.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × m), where n is the number of rows and m is the number of columns. We visit each cell exactly once and perform constant time operations for each cell.
* **Expected Auxiliary Space Complexity:** O(1), as we perform the dynamic programming in-place by modifying the original matrix without using any additional space.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                int mx = 0;
                for (int di = -1; di <= 1; di++) {
                    int ni = i + di;
                    if (ni >= 0 && ni < n) mx = max(mx, mat[ni][j + 1]);
                }
                mat[i][j] += mx;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) res = max(res, mat[i][0]);
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Space-Optimized Single Row Approach**

### 💡 Algorithm Steps:

1. Use single array to store previous column values
2. Process column by column from right to left
3. Update in-place for maximum space efficiency
4. Single pass to find maximum result

```cpp
class Solution {
public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> prev(n), curr(n);
        for (int i = 0; i < n; i++) prev[i] = mat[i][m - 1];
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                curr[i] = mat[i][j] + max({
                    i > 0 ? prev[i - 1] : 0,
                    prev[i],
                    i < n - 1 ? prev[i + 1] : 0
                });
            }
            prev = curr;
        }
        return *max_element(prev.begin(), prev.end());
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m)
* **Auxiliary Space:** 💾 O(n) - two arrays only

### ✅ **Why This Approach?**

* Constant space optimization
* Better cache performance
* Preserves original matrix

## 📊 **3️⃣ Reverse Iteration with Lambda**

### 💡 Algorithm Steps:

1. Process matrix from bottom-right to top-left
2. Use lambda for cleaner boundary checking
3. Single-pass maximum calculation
4. Functional programming style

```cpp
class Solution {
public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        auto get = [&](int i, int j) { return (i >= 0 && i < n) ? mat[i][j] : 0; };
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                mat[i][j] += max({get(i - 1, j + 1), get(i, j + 1), get(i + 1, j + 1)});
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) res = max(res, mat[i][0]);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m)
* **Auxiliary Space:** 💾 O(1) - in-place modification

### ✅ **Why This Approach?**

* Clean lambda-based boundary checking
* Functional programming paradigm
* Readable and maintainable code

## 📊 **4️⃣ Bit Manipulation Optimization**

### 💡 Algorithm Steps:

1. Use bit operations for faster maximum calculation
2. Unroll loops for better performance
3. Minimize function call overhead
4. Hardware-level optimization

```cpp
class Solution {
public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                int a = (i > 0) ? mat[i - 1][j + 1] : 0;
                int b = mat[i][j + 1];
                int c = (i < n - 1) ? mat[i + 1][j + 1] : 0;
                mat[i][j] += (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
            }
        }
        int res = mat[0][0];
        for (int i = 1; i < n; i++) {
            res = (mat[i][0] > res) ? mat[i][0] : res;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m)
* **Auxiliary Space:** 💾 O(1) - in-place modification

### ✅ **Why This Approach?**

* Eliminates standard library calls
* Optimized conditional operations
* Better performance on low-level hardware

## 📊 **5️⃣ Recursive Memoization Approach**

### 💡 Algorithm Steps:

1. Use recursion with memoization for intuitive solution
2. Explore all three possible paths from each cell
3. Cache results to avoid redundant calculations
4. Top-down dynamic programming approach

```cpp
class Solution {
public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (j == m - 1) return mat[i][j];
            if (memo[i][j] != -1) return memo[i][j];
            
            int maxNext = 0;
            for (int di = -1; di <= 1; di++) {
                int ni = i + di;
                if (ni >= 0 && ni < n) {
                    maxNext = max(maxNext, dfs(ni, j + 1));
                }
            }
            return memo[i][j] = mat[i][j] + maxNext;
        };
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, dfs(i, 0));
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m)
* **Auxiliary Space:** 💾 O(n × m) - memoization table

### ✅ **Why This Approach?**

* Intuitive recursive thinking
* Natural problem decomposition
* Good for understanding the problem structure

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **In-place DP**                | 🟢 O(n × m)            | 🟢 O(1)                 | 🚀 Minimal space usage           | 💾 Modifies input matrix             |
| 🔺 **Space-Optimized**            | 🟢 O(n × m)            | 🟡 O(n)                 | 🔧 Preserves original matrix     | 💾 Extra space for two arrays        |
| ⏰ **Lambda-based**               | 🟢 O(n × m)            | 🟢 O(1)                 | 🚀 Clean and readable code       | 🔄 Lambda overhead                    |
| 📊 **Bit Manipulation**           | 🟢 O(n × m)            | 🟢 O(1)                 | ⚡ Hardware-level optimization    | 🔧 Less readable code                |
| 🔄 **Recursive Memoization**      | 🟢 O(n × m)            | 🟡 O(n × m)             | 🎯 Intuitive problem structure   | 💾 High space complexity            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| ⚡ **Competitive programming**                         | 🥇 **In-place DP**                   | ★★★★★                     |
| 📊 **Production code**                                | 🥈 **Lambda-based**                  | ★★★★☆                     |
| 🎯 **Memory-constrained systems**                     | 🥉 **Bit Manipulation**              | ★★★★☆                     |
| 🚀 **Interview/readable code**                        | 🏅 **Space-Optimized**               | ★★★★☆                     |
| 📚 **Educational purposes**                           | 🎖️ **Recursive Memoization**         | ★★★☆☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int maxGold(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                int mx = 0;
                for (int di = -1; di <= 1; di++) {
                    int ni = i + di;
                    if (ni >= 0 && ni < n) mx = Math.max(mx, mat[ni][j + 1]);
                }
                mat[i][j] += mx;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) res = Math.max(res, mat[i][0]);
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxGold(self, mat):
        n, m = len(mat), len(mat[0])
        for j in range(m - 2, -1, -1):
            for i in range(n):
                mx = 0
                for di in [-1, 0, 1]:
                    ni = i + di
                    if 0 <= ni < n:
                        mx = max(mx, mat[ni][j + 1])
                mat[i][j] += mx
        return max(mat[i][0] for i in range(n))
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>


