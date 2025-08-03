---
title: "🔢 2D Difference Array | GFG Solution 🔍"
keywords🏷️: ["🔢 2D difference array", "🔍 range updates", "📍 prefix sum", "📈 matrix operations", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the 2D Difference Array problem: efficiently apply multiple range updates on 2D matrix using difference array technique with 2D prefix sum optimization. 🚀"
date: 📅 2025-08-03
---

# *03. 2D Difference Array*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/2-d-difference-array/1)

## **🧩 Problem Description**

You are given a 2D integer matrix `mat[][]` of size `n × m` and a list of `q` operations `opr[][]`. Each operation is represented as an array `[v, r1, c1, r2, c2]`, where:

- `v` is the value to be added
- `(r1, c1)` is the top-left cell of a submatrix
- `(r2, c2)` is the bottom-right cell of the submatrix (inclusive)

For each of the `q` operations, add `v` to every element in the submatrix from `(r1, c1)` to `(r2, c2)`. Return the final matrix after applying all operations.

## **📘 Examples**

### Example 1

```cpp
Input: mat[][] = [[1, 2, 3],    opr[][] = [[2, 0, 0, 1, 1], [-1, 1, 0, 2, 2]]
                  [1, 1, 0],
                  [4,-2, 2]]
Output: [[3, 4, 3],
         [2, 2, -1],
         [3, -3, 1]]
Explanation: 
- First operation: Add 2 to submatrix from (0,0) to (1,1)
- Second operation: Add -1 to submatrix from (1,0) to (2,2)
```

## **🔒 Constraints**

* $1 \le n \times m, q \le 10^5$
* $0 \le r1 \le r2 \le n - 1$
* $0 \le c1 \le c2 \le m - 1$
* $-10^4 \le \text{mat}[i][j], v \le 10^4$

## **✅ My Approach**

The optimal approach uses the **2D Difference Array** technique combined with **2D Prefix Sum** to efficiently handle multiple range update operations:

### **2D Difference Array + 2D Prefix Sum**

1. **Initialize Difference Matrix:**
   * Create a difference matrix `d[][]` of size `(n+1) × (m+1)` initialized with zeros.
   * This extra padding helps avoid boundary checks during operations.

2. **Apply Range Updates:**
   * For each operation `[v, r1, c1, r2, c2]`, use the 4-point technique:
     - Add `v` at `d[r1][c1]` (top-left corner)
     - Subtract `v` at `d[r1][c2+1]` (right boundary)
     - Subtract `v` at `d[r2+1][c1]` (bottom boundary)
     - Add `v` at `d[r2+1][c2+1]` (bottom-right corner)

3. **Compute 2D Prefix Sum:**
   * Convert difference array to actual values using 2D prefix sum:
   * `d[i][j] = d[i][j] + d[i-1][j] + d[i][j-1] - d[i-1][j-1]`
   * This applies inclusion-exclusion principle for 2D arrays.

4. **Apply to Original Matrix:**
   * Add the computed difference values to the original matrix elements.

5. **Return Result:**
   * The modified matrix contains all range updates applied efficiently.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(q + n×m), where q is the number of operations and n×m is the matrix size. We process each operation in O(1) time and then perform a single pass through the matrix for 2D prefix sum computation.
* **Expected Auxiliary Space Complexity:** O(n×m), as we create a difference matrix of size (n+1)×(m+1) to store the difference values before applying them to the original matrix.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat, vector<vector<int>>& opr) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));
        
        for (auto& q : opr) {
            int v = q[0], r1 = q[1], c1 = q[2], r2 = q[3], c2 = q[4];
            d[r1][c1] += v;
            d[r1][c2 + 1] -= v;
            d[r2 + 1][c1] -= v;
            d[r2 + 1][c2 + 1] += v;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i) d[i][j] += d[i - 1][j];
                if (j) d[i][j] += d[i][j - 1];
                if (i && j) d[i][j] -= d[i - 1][j - 1];
                mat[i][j] += d[i][j];
            }
        }
        return mat;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Separate Prefix Sum Approach**

### 💡 Algorithm Steps:

1. Create difference matrix and apply 4-point technique for all operations.
2. Compute row-wise prefix sums first across all rows.
3. Compute column-wise prefix sums to get final difference values.
4. Add difference matrix to original matrix for final result.

```cpp
class Solution {
public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat, vector<vector<int>>& opr) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> diff(n, vector<int>(m, 0));
        
        for (auto& op : opr) {
            int val = op[0], r1 = op[1], c1 = op[2], r2 = op[3], c2 = op[4];
            diff[r1][c1] += val;
            if (c2 + 1 < m) diff[r1][c2 + 1] -= val;
            if (r2 + 1 < n) diff[r2 + 1][c1] -= val;
            if (r2 + 1 < n && c2 + 1 < m) diff[r2 + 1][c2 + 1] += val;
        }
        
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                diff[i][j] += diff[i][j - 1];
        
        for (int j = 0; j < m; j++)
            for (int i = 1; i < n; i++)
                diff[i][j] += diff[i - 1][j];
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mat[i][j] += diff[i][j];
        
        return mat;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(q + n×m) - q operations + matrix traversal
* **Auxiliary Space:** 💾 O(n×m) - Separate difference matrix

## 📊 **3️⃣ Optimized Single Pass Approach**

### 💡 Algorithm Steps:

1. Create difference matrix and apply all range operations using 4-point updates.
2. Combine row and column prefix sum computation in single traversal.
3. Use inclusion-exclusion principle for 2D prefix sum calculation.
4. Apply computed differences to original matrix in same pass.

```cpp
class Solution {
public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat, vector<vector<int>>& opr) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<long long>> d(n + 1, vector<long long>(m + 1, 0));
        
        for (const auto& op : opr) {
            long long v = op[0];
            int r1 = op[1], c1 = op[2], r2 = op[3], c2 = op[4];
            d[r1][c1] += v;
            d[r1][c2 + 1] -= v;
            d[r2 + 1][c1] -= v;
            d[r2 + 1][c2 + 1] += v;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                d[i][j] += (i ? d[i-1][j] : 0) + (j ? d[i][j-1] : 0) - (i && j ? d[i-1][j-1] : 0);
                mat[i][j] += d[i][j];
            }
        }
        return mat;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(q + n×m) - Single pass optimization
* **Auxiliary Space:** 💾 O(n×m) - Difference matrix with overflow protection

## 📊 **4️⃣ Naive Brute Force Approach**

### 💡 Algorithm Steps:

1. For each operation, iterate through the entire submatrix range.
2. Add the value `v` to each cell in the specified rectangular region.
3. Continue for all operations sequentially.
4. Return the modified matrix.

```cpp
class Solution {
public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat, vector<vector<int>>& opr) {
        for (auto& op : opr) {
            int val = op[0], r1 = op[1], c1 = op[2], r2 = op[3], c2 = op[4];
            for (int i = r1; i <= r2; i++) {
                for (int j = c1; j <= c2; j++) {
                    mat[i][j] += val;
                }
            }
        }
        return mat;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(q × n × m) - For each operation, traverse submatrix
* **Auxiliary Space:** 💾 O(1) - No extra space needed

### ⚠️ **Why Not This Approach?**

* Extremely slow for large matrices and many operations.
* Time complexity can become O(q × n × m) in worst case.
* Not suitable for competitive programming constraints.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **2D Difference Array**        | 🟢 O(q + n×m)          | 🟡 O(n×m)               | 🚀 Single traversal, optimal      | 🔧 Complex index handling            |
| 🔄 **Separate Prefix**            | 🟢 O(q + n×m)          | 🟡 O(n×m)               | 📖 Clear logic separation         | 🐌 Multiple matrix passes            |
| 🔑 **Single Pass**                | 🟢 O(q + n×m)          | 🟡 O(n×m)               | ⭐ Overflow protection            | 🧮 Complex prefix calculation        |
| 💀 **Brute Force**                | 🔴 O(q × n × m)        | 🟢 O(1)                 | 📝 Simple to understand           | ⏰ Extremely slow for large inputs   |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **2D Difference Array**           | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **Separate Prefix**               | ★★★★☆                     |
| 🎯 **Large values/overflow risk**                     | 🏅 **Single Pass**                   | ★★★★★                     |
| 🎓 **Learning/educational purposes**                  | 🎖️ **Brute Force**                   | ★★☆☆☆                     |

</details>


## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<ArrayList<Integer>> applyDiff2D(int[][] mat, int[][] opr) {
        int n = mat.length, m = mat[0].length;
        long[][] d = new long[n + 1][m + 1];
        
        for (int[] op : opr) {
            int v = op[0], r1 = op[1], c1 = op[2], r2 = op[3], c2 = op[4];
            d[r1][c1] += v;
            d[r1][c2 + 1] -= v;
            d[r2 + 1][c1] -= v;
            d[r2 + 1][c2 + 1] += v;
        }
        
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> row = new ArrayList<>();
            for (int j = 0; j < m; j++) {
                if (i > 0) d[i][j] += d[i - 1][j];
                if (j > 0) d[i][j] += d[i][j - 1];
                if (i > 0 && j > 0) d[i][j] -= d[i - 1][j - 1];
                row.add(mat[i][j] + (int)d[i][j]);
            }
            res.add(row);
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def applyDiff2D(self, mat, opr):
        n, m = len(mat), len(mat[0])
        d = [[0] * (m + 1) for _ in range(n + 1)]
        
        for v, r1, c1, r2, c2 in opr:
            d[r1][c1] += v
            d[r1][c2 + 1] -= v
            d[r2 + 1][c1] -= v
            d[r2 + 1][c2 + 1] += v
        
        for i in range(n):
            for j in range(m):
                if i: d[i][j] += d[i - 1][j]
                if j: d[i][j] += d[i][j - 1]
                if i and j: d[i][j] -= d[i - 1][j - 1]
                mat[i][j] += d[i][j]
        return mat
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

