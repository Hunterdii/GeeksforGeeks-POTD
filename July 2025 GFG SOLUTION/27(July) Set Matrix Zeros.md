---
title: "⚙️ Set Matrix Zeroes | GFG Solution 🔍"
keywords🏷️: ["⚙️ matrix manipulation", "🔍 in-place algorithm", "📍 space optimization", "📈 2D array", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Set Matrix Zeroes problem: modify matrix to set entire rows and columns to zero when encountering a zero element using optimal space approach. 🚀"
date: 📅 2025-07-27
---

# *27. Set Matrix Zeroes*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1)

## **🧩 Problem Description**

You are given a 2D matrix `mat[][]` of size `n x m`. The task is to modify the matrix such that if `mat[i][j]` is 0, all the elements in the **i-th row** and **j-th column** are set to 0.

The challenge is to solve this **in-place** without using extra space proportional to the matrix size.

## **📘 Examples**

### Example 1

```cpp
Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
Output: [[1, 0, 1], [0, 0, 0], [1, 0, 1]]
Explanation: mat[1][1] = 0, so all elements in row 1 and column 1 are updated to zeroes.
```

### Example 2

```cpp
Input: mat = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
Output: [[0, 0, 0, 0], [0, 4, 5, 0], [0, 3, 1, 0]]
Explanation: mat[0][0] and mat[0][3] are 0s, so all elements in row 0, column 0 and column 3 are updated to zeroes.
```

## **🔒 Constraints**

* $1 \le n, m \le 500$
* $-2^{31} \le \text{mat}[i][j] \le 2^{31} - 1$

## **✅ My Approach**

The optimal approach uses the **first row and first column as markers** to track which rows and columns should be zeroed, achieving **O(1) space complexity**:

### **In-Place Flagging with Boundary Tracking**

1. **Track Boundary States:**
   * Use boolean flags `firstRow` and `firstCol` to remember if the first row or first column originally contained zeros.
   * This prevents confusion when using them as markers.

2. **Mark Using Matrix Itself:**
   * Iterate through the matrix starting from `(1,1)`.
   * When finding a zero at `mat[i][j]`, mark `mat[i][0] = 0` and `mat[0][j] = 0`.
   * This uses the first row and column as a "marking system".

3. **Apply Zeros Based on Markers:**
   * For each cell `mat[i][j]` (excluding first row/column), if either `mat[i][0]` or `mat[0][j]` is zero, set `mat[i][j] = 0`.

4. **Handle Boundaries:**
   * If `firstRow` was true, zero out the entire first row.
   * If `firstCol` was true, zero out the entire first column.

5. **Why This Works:**
   * We use the matrix's own space to store marking information.
   * By handling boundaries separately, we avoid overwriting critical marker data.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n×m), where n and m are the dimensions of the matrix. We traverse the matrix a constant number of times (3-4 passes).
* **Expected Auxiliary Space Complexity:** O(1), as we only use two boolean variables for boundary tracking, regardless of matrix size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    void setMatrixZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        bool firstRow = false, firstCol = false;
        for (int i = 0; i < n; ++i) firstCol |= mat[i][0] == 0;
        for (int j = 0; j < m; ++j) firstRow |= mat[0][j] == 0;
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                if (mat[i][j] == 0)
                    mat[i][0] = mat[0][j] = 0;
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                if (!mat[i][0] || !mat[0][j])
                    mat[i][j] = 0;
        if (firstRow) fill(begin(mat[0]), end(mat[0]), 0);
        if (firstCol) for (int i = 0; i < n; ++i) mat[i][0] = 0;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Single Pass Marking with Flags**

### 💡 Algorithm Steps:

1. Use first row/column as markers in single pass
2. Track original state of boundaries separately
3. Apply zeroes based on markers
4. Handle boundaries last

```cpp
class Solution {
public:
    void setMatrixZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        bool firstRow = false, firstCol = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    if (i == 0) firstRow = true;
                    if (j == 0) firstCol = true;
                    mat[i][0] = mat[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; i++)
            if (mat[i][0] == 0)
                for (int j = 1; j < m; j++) mat[i][j] = 0;
        for (int j = 1; j < m; j++)
            if (mat[0][j] == 0)
                for (int i = 1; i < n; i++) mat[i][j] = 0;
        if (firstRow) for (int j = 0; j < m; j++) mat[0][j] = 0;
        if (firstCol) for (int i = 0; i < n; i++) mat[i][0] = 0;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n×m)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Clear separation of boundary handling
* Easy to understand logic flow
* Minimal branching in inner loops

## 📊 **3️⃣ Reverse Order Processing**

### 💡 Algorithm Steps:

1. Mark positions using matrix itself
2. Process from bottom-right to top-left
3. Avoid overwriting needed markers
4. Handle special cases efficiently

```cpp
class Solution {
public:
    void setMatrixZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        bool zeroFirstRow = false, zeroFirstCol = false;
        for (int i = 0; i < n; i++) if (mat[i][0] == 0) zeroFirstCol = true;
        for (int j = 0; j < m; j++) if (mat[0][j] == 0) zeroFirstRow = true;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        for (int i = n - 1; i >= 1; i--) {
            for (int j = m - 1; j >= 1; j--) {
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }
        if (zeroFirstCol) for (int i = 0; i < n; i++) mat[i][0] = 0;
        if (zeroFirstRow) for (int j = 0; j < m; j++) mat[0][j] = 0;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n×m)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Avoids marker conflicts
* Cache-friendly access pattern
* Symmetric processing logic

## 📊 **4️⃣ Bitwise Optimization**

### 💡 Algorithm Steps:

1. Use bitwise operations for flag management
2. Combine row and column checks efficiently
3. Minimal memory access patterns
4. Optimized for performance

```cpp
class Solution {
public:
    void setMatrixZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int boundary = 0;
        for (int i = 0; i < n; i++) if (mat[i][0] == 0) boundary |= 1;
        for (int j = 0; j < m; j++) if (mat[0][j] == 0) boundary |= 2;
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (mat[i][j] == 0) mat[i][0] = mat[0][j] = 0;
        for (int i = 1; i < n; i++) {
            if (mat[i][0] == 0) {
                for (int j = 1; j < m; j++) mat[i][j] = 0;
            }
        }
        for (int j = 1; j < m; j++) {
            if (mat[0][j] == 0) {
                for (int i = 1; i < n; i++) mat[i][j] = 0;
            }
        }
        if (boundary & 1) for (int i = 0; i < n; i++) mat[i][0] = 0;
        if (boundary & 2) for (int j = 0; j < m; j++) mat[0][j] = 0;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n×m)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Minimal variable usage
* Bitwise flag operations
* Optimized memory footprint


## 📊 **5️⃣ Extra Space Approach (Naive)**

### 💡 Algorithm Steps:

1. Store all zero positions first
2. Mark entire rows and columns
3. Simple but uses extra space
4. Good for understanding the problem

```cpp
class Solution {
public:
    void setMatrixZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<bool> zeroRows(n, false), zeroCols(m, false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    zeroRows[i] = true;
                    zeroCols[j] = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (zeroRows[i] || zeroCols[j]) {
                    mat[i][j] = 0;
                }
            }
        }
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n×m)
* **Auxiliary Space:** 💾 O(n+m)

### ✅ **Why This Approach?**

* Easiest to understand and implement
* Clear separation of logic
* Good for learning the problem pattern

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **In-place Flagging**         | 🟢 O(n×m)             | 🟢 O(1)                 | 🚀 Optimal space, fastest        | 💾 Complex boundary logic            |
| 🔺 **Single Pass Marking**        | 🟢 O(n×m)             | 🟢 O(1)                 | 🔧 Clear logic flow              | 💾 Multiple condition checks         |
| ⏰ **Reverse Order Processing**    | 🟢 O(n×m)             | 🟢 O(1)                 | 🚀 Cache-friendly access         | 🔄 Reverse iteration complexity      |
| 📊 **Bitwise Optimization**       | 🟢 O(n×m)             | 🟢 O(1)                 | ⚡ Minimal memory usage          | 🔧 Less readable code               |
| 📈 **Extra Space Approach**       | 🟢 O(n×m)             | 🟡 O(n+m)               | 📚 Easy to understand            | 💾 Uses additional arrays           |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| ⚡ **Performance Critical / Interview**           | 🥇 **In-place Flagging**            | ★★★★★                     |
| 📊 **Code Readability**                          | 🥈 **Single Pass Marking**           | ★★★★☆                     |
| 🎯 **Memory Constrained Systems**                | 🥉 **Bitwise Optimization**          | ★★★★☆                     |
| 📚 **Learning / Understanding**                   | 🏅 **Extra Space Approach**          | ★★★☆☆                     |
| 🔧 **Production Code**                           | 🎖️ **Reverse Order Processing**            | ★★★★★                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public void setMatrixZeroes(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        boolean row0 = false, col0 = false;
        for (int i = 0; i < n; i++) if (mat[i][0] == 0) col0 = true;
        for (int j = 0; j < m; j++) if (mat[0][j] == 0) row0 = true;
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (mat[i][j] == 0)
                    mat[i][0] = mat[0][j] = 0;
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (mat[i][0] == 0 || mat[0][j] == 0)
                    mat[i][j] = 0;
        if (row0) Arrays.fill(mat[0], 0);
        if (col0) for (int i = 0; i < n; i++) mat[i][0] = 0;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def setMatrixZeroes(self, mat):
        n, m = len(mat), len(mat[0])
        row0 = any(mat[0][j] == 0 for j in range(m))
        col0 = any(mat[i][0] == 0 for i in range(n))
        for i in range(1, n):
            for j in range(1, m):
                if mat[i][j] == 0:
                    mat[i][0] = mat[0][j] = 0
        for i in range(1, n):
            for j in range(1, m):
                if mat[i][0] == 0 or mat[0][j] == 0:
                    mat[i][j] = 0
        if row0:
            for j in range(m): mat[0][j] = 0
        if col0:
            for i in range(n): mat[i][0] = 0
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
