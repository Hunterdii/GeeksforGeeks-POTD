---
title: "🔢 Number of Submatrix have Sum X | GFG Solution 🎯"
keywords🏷️: ["🔢 submatrix sum", "🔍 2D prefix sum", "📊 square submatrix", "📈 matrix computation", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Number of Submatrix have Sum X: count square submatrices with specific sum using 2D prefix sum technique. 🚀"
date: 📅 2025-02-27
---

# *27. Number of Submatrix have Sum X*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/number-of-submatrix-have-sum-k/1)

## **🧩 Problem Description**

Given a matrix `mat[][]` of size `n × m` and an integer `x`, find the number of **square submatrices** whose sum of elements is equal to `x`.

## **📘 Examples**

### Example 1

```cpp
Input: mat[][] = [[2, 4, 7, 8, 10], 
                  [3, 1, 1, 1, 1], 
                  [9, 11, 1, 2, 1], 
                  [12, -17, 1, 1, 1]], x = 10
Output: 3
Explanation: There are 3 square sub-matrices whose sum of elements equals 10.
```
<img width="272" height="240" alt="image" src="https://github.com/user-attachments/assets/bc89ecca-afed-448d-aa2d-350ee101d8d5" />


### Example 2

```cpp
Input: mat[][] = [[3, 3, 5, 3], 
                  [2, 2, 2, 6], 
                  [11, 2, 2, 4]], x = 1
Output: 0
Explanation: There is no square sub-matrix whose sum of elements is 1.
```

### Example 3

```cpp
Input: mat[][] = [[1, 1], [1, 1]], x = 4
Output: 1
Explanation: The entire 2×2 matrix has sum = 4.
```

## **🔒 Constraints**

* $1 \le n, m \le 100$
* $-10^3 \le \text{mat}[i] \le 10^3$
* $-10^9 \le x \le 10^9$

## **✅ My Approach**

The optimal solution uses **2D Prefix Sum with Square Enumeration**:

### **2D Prefix Sum Technique**

1. **Build 2D Prefix Sum:**
   * Create a prefix sum matrix where `pre[i][j]` stores sum of all elements from `(0,0)` to `(i-1,j-1)`.
   * Formula: `pre[i][j] = mat[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1]`

2. **Enumerate All Square Sizes:**
   * Try all possible square sizes from 1×1 to min(n,m) × min(n,m).
   * For each size, check all possible top-left positions.

3. **Calculate Square Sum:**
   * For a square of size `sz` ending at position `(i,j)`:
   * Sum = `pre[i][j] - pre[i-sz][j] - pre[i][j-sz] + pre[i-sz][j-sz]`
   * This uses inclusion-exclusion principle on prefix sums.

4. **Count Valid Squares:**
   * If calculated sum equals x, increment counter.
   * Return total count after checking all possible squares.

**Key Advantage:** 2D prefix sum allows O(1) submatrix sum calculation after O(n×m) preprocessing.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × m × min(n,m)²), where we build prefix sum in O(n×m), then check all squares. For each of O(min(n,m)) sizes, we check O(n×m) positions with O(1) sum calculation per position.
* **Expected Auxiliary Space Complexity:** O(n × m), as we use a 2D prefix sum array of the same size as the input matrix to store cumulative sums.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size(), cnt = 0;
        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                pre[i][j] = mat[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        for (int sz = 1; sz <= min(n, m); sz++)
            for (int i = sz; i <= n; i++)
                for (int j = sz; j <= m; j++)
                    if (pre[i][j] - pre[i-sz][j] - pre[i][j-sz] + pre[i-sz][j-sz] == x)
                        cnt++;
        return cnt;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Row Prefix Sum with Sliding Window**

### 💡 Algorithm Steps:

1. Compute row-wise prefix sums for efficient row sum calculation.
2. For each square size, use sliding window vertically.
3. Maintain cumulative sum of rows as we slide.
4. Count squares with sum equal to x.

```cpp
class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size(), res = 0;
        vector<vector<int>> rowPre = mat;
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                rowPre[i][j] += rowPre[i][j - 1];
        
        for (int sz = 1; sz <= min(n, m); sz++) {
            for (int c = 0; c <= m - sz; c++) {
                int sum = 0;
                for (int r = 0; r < n; r++) {
                    int rowSum = rowPre[r][c + sz - 1] - (c > 0 ? rowPre[r][c - 1] : 0);
                    sum += rowSum;
                    if (r >= sz - 1) {
                        if (sum == x) res++;
                        sum -= rowPre[r - sz + 1][c + sz - 1] - (c > 0 ? rowPre[r - sz + 1][c - 1] : 0);
                    }
                }
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m × min(n,m)) - Optimized sliding window
* **Auxiliary Space:** 💾 O(n × m) - Row prefix sum array

### ✅ **Why This Approach?**

* Efficient sliding window reduces redundant calculations
* Row prefix sum enables O(1) row range queries
* Good balance between complexity and performance

## 📊 **3️⃣ Brute Force Approach**

### 💡 Algorithm Steps:

1. For each possible top-left corner of square submatrix.
2. For each possible square size from that corner.
3. Calculate sum by iterating through all elements.
4. Count squares with sum equal to x.

```cpp
class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int sz = 1; i + sz <= n && j + sz <= m; sz++) {
                    int sum = 0;
                    for (int r = i; r < i + sz; r++)
                        for (int c = j; c < j + sz; c++)
                            sum += mat[r][c];
                    if (sum == x) cnt++;
                }
            }
        }
        return cnt;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n² × m² × min(n,m)) - Nested loops with sum calculation
* **Auxiliary Space:** 💾 O(1) - Constant extra space

### ✅ **Why This Approach?**

* Simple and straightforward implementation
* No preprocessing required
* Good for understanding the problem

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110/1113 test cases due to time constraints).

## 📊 **4️⃣ Optimized Brute Force with Incremental Sum**

### 💡 Algorithm Steps:

1. For each top-left corner and square size.
2. Build square sum incrementally by adding new row and column.
3. Reuse previous smaller square's sum.
4. Count valid squares efficiently.

```cpp
class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = 0;
                for (int sz = 1; i + sz <= n && j + sz <= m; sz++) {
                    for (int k = j; k < j + sz; k++)
                        sum += mat[i + sz - 1][k];
                    for (int k = i; k < i + sz - 1; k++)
                        sum += mat[k][j + sz - 1];
                    if (sum == x) cnt++;
                }
            }
        }
        return cnt;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m × min(n,m)²) - Incremental sum building
* **Auxiliary Space:** 💾 O(1) - Constant space

### ✅ **Why This Approach?**

* Better than pure brute force
* Incremental sum reduces redundant work
* Still easy to understand and implement

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **2D Prefix Sum**              | 🟢 O(n×m×min²)         | 🟡 O(n×m)               | 🚀 O(1) submatrix query           | 💾 Extra space for prefix array      |
| 📊 **Row Prefix + Sliding**       | 🟢 O(n×m×min)          | 🟡 O(n×m)               | ⚡ Most time efficient            | 🔧 Complex sliding logic             |
| 🔄 **Brute Force**                | 🔴 O(n²×m²×min)        | 🟢 O(1)                 | 📖 Simple to understand           | 🐌 Very slow for large inputs        |
| 📈 **Incremental Sum**            | 🟡 O(n×m×min²)         | 🟢 O(1)                 | 💾 Space efficient                | 🔧 Still multiple nested loops       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal time complexity**                        | 🥇 **Row Prefix + Sliding**          | ★★★★★                     |
| 📖 **Balanced performance**                           | 🥈 **2D Prefix Sum**                 | ★★★★★                     |
| 💾 **Memory constrained**                             | 🥉 **Incremental Sum**               | ★★★☆☆                     |
| 🎯 **Learning purposes**                              | 🏅 **Brute Force**                   | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int countSquare(int[][] mat, int x) {
        int n = mat.length, m = mat[0].length, cnt = 0;
        int[][] pre = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                pre[i][j] = mat[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        for (int sz = 1; sz <= Math.min(n, m); sz++)
            for (int i = sz; i <= n; i++)
                for (int j = sz; j <= m; j++)
                    if (pre[i][j] - pre[i-sz][j] - pre[i][j-sz] + pre[i-sz][j-sz] == x)
                        cnt++;
        return cnt;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def countSquare(self, mat, x):
        n, m, cnt = len(mat), len(mat[0]), 0
        pre = [[0] * (m + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                pre[i][j] = mat[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1]
        for sz in range(1, min(n, m) + 1):
            for i in range(sz, n + 1):
                for j in range(sz, m + 1):
                    if pre[i][j] - pre[i-sz][j] - pre[i][j-sz] + pre[i-sz][j-sz] == x:
                        cnt += 1
        return cnt
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
