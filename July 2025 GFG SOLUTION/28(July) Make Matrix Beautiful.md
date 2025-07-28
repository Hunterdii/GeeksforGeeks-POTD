---
title: "🎨 Make Matrix Beautiful | GFG Solution ✨"
keywords🏷️: ["🎨 matrix manipulation", "🔄 optimization", "📊 row column sum", "🧮 greedy algorithm", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Make Matrix Beautiful problem: find minimum operations to make all row and column sums equal using greedy optimization approach. 🚀"
date: 📅 2025-07-28
---

# *28. Make Matrix Beautiful*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/make-matrix-beautiful-1587115620/1)

## **🧩 Problem Description**

A beautiful matrix is defined as a square matrix in which the **sum of elements in every row and every column is equal**. Given a square matrix `mat[][]`, your task is to determine the minimum number of operations required to make the matrix beautiful.

In one operation, you are allowed to **increment the value of any single cell by 1**.

## **📘 Examples**

### Example 1

```cpp
Input: mat[][] = [[1, 2], 
                  [3, 4]]
Output: 4
Explanation: 
Increment value of cell(0, 0) by 3, 
Increment value of cell(0, 1) by 1. 
Matrix after the operations: [[4, 3], 
                              [3, 4]]
Here, sum of each row and column is 7.
Hence total 4 operations are required.
```

### Example 2

```cpp
Input: mat[][] = [[1, 2, 3],
                  [4, 2, 3],
                  [3, 2, 1]]
Output: 6
Explanation: 
Increment value of cell(0, 0) by 1, 
Increment value of cell(0, 1) by 2, 
Increment value of cell(2, 1) by 1, 
Increment value of cell(2, 2) by 2. 
Matrix after the operations: [[2, 4, 3], 
                              [4, 2, 3],
                              [3, 3, 3]] 
Here, sum of each row and column is 9.
Hence total 6 operations are required.
```

## **🔒 Constraints**

* $1 \le \text{mat.size()} \le 900$
* $0 \le \text{mat}[i][j] \le 10^6$

## **✅ My Approach**

The optimal approach uses a **Greedy Strategy** to find the maximum sum among all rows and columns, then calculate the minimum operations needed:

### **Greedy Maximum Sum Strategy**

1. **Find Maximum Sum:**
   * Calculate the sum of each row and find the maximum.
   * Calculate the sum of each column and find the maximum.
   * The target sum for all rows and columns should be this maximum value.

2. **Key Insight:**
   * Since we can only increment values (never decrement), the target sum must be at least the maximum of all current row and column sums.
   * Any smaller target would be impossible to achieve for rows/columns that already exceed it.

3. **Calculate Operations:**
   * For each row, if its current sum is less than the target maximum, we need `(max - current_sum)` operations.
   * Since we're only incrementing row elements, the total operations equals the sum of deficits for all rows.

4. **Why This Works:**
   * When we increment elements in rows to match the target, the column sums automatically increase.
   * The greedy choice of using the maximum possible sum ensures feasibility.
   * This approach guarantees the minimum number of operations.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n²), where n is the size of the matrix. We traverse the matrix three times: once for row sums, once for column sums, and once for calculating the result.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables regardless of the matrix size.

## **🔧 Code (C)**

```c
int balanceSum(int n, int mat[][n]) {
    int max = 0, res = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) sum += mat[i][j];
        if (sum > max) max = sum;
    }
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < n; i++) sum += mat[i][j];
        if (sum > max) max = sum;
    }
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) sum += mat[i][j];
        res += max - sum;
    }
    return res;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size(), max = 0, res = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) sum += mat[i][j];
            max = sum > max ? sum : max;
        }
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) sum += mat[i][j];
            max = sum > max ? sum : max;
        }
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) sum += mat[i][j];
            res += max - sum;
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Single Pass with Storage Approach**

### 💡 Algorithm Steps:

1. Calculate all row sums in first pass and store them
2. Calculate all column sums in second pass and find maximum
3. Calculate result using stored row sums to avoid recalculation
4. Trades space for one less matrix traversal

```cpp
class Solution {
public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size(), max = 0, res = 0;
        vector<int> rowSums(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) rowSums[i] += mat[i][j];
            max = rowSums[i] > max ? rowSums[i] : max;
        }
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) sum += mat[i][j];
            max = sum > max ? sum : max;
        }
        for (int sum : rowSums) res += max - sum;
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Two matrix traversals instead of three
* **Auxiliary Space:** 💾 O(n) - Extra array to store row sums

### ✅ **Why This Approach?**

* Reduces matrix traversals from 3 to 2
* Better cache locality with stored sums
* Good balance between time and space optimization

## 📊 **3️⃣ Transpose Matrix Approach**

### 💡 Algorithm Steps:

1. Create transpose of matrix to convert column operations to row operations
2. Process both original and transposed matrix with same row logic
3. Find maximum sum from both matrices efficiently
4. Calculate result using original matrix row sums

```cpp
class Solution {
public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size(), max = 0, res = 0;
        vector<vector<int>> trans(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += mat[i][j];
                trans[j][i] = mat[i][j];
            }
            max = sum > max ? sum : max;
        }
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) sum += trans[i][j];
            max = sum > max ? sum : max;
        }
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) sum += mat[i][j];
            res += max - sum;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Three passes but with better memory access pattern
* **Auxiliary Space:** 💾 O(n²) - Additional matrix for transpose

### ✅ **Why This Approach?**

* Converts column operations to row operations for better cache performance
* Uniform processing logic for both dimensions
* Better memory access patterns

## 📊 **4️⃣ Prefix Sum Optimization**

### 💡 Algorithm Steps:

1. Build prefix sums for rows and columns simultaneously in one pass
2. Use prefix sums to calculate row and column totals instantly
3. Find maximum from precomputed sums without recalculation
4. Calculate final result using prefix sum differences

```cpp
class Solution {
public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size(), max = 0, res = 0;
        vector<int> rowSum(n, 0), colSum(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            max = rowSum[i] > max ? rowSum[i] : max;
            max = colSum[i] > max ? colSum[i] : max;
        }
        for (int i = 0; i < n; i++) res += max - rowSum[i];
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Single matrix traversal plus linear operations
* **Auxiliary Space:** 💾 O(n) - Two arrays for row and column sums

### ✅ **Why This Approach?**

* Most efficient with single matrix pass
* Optimal memory access pattern
* Minimal redundant calculations

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Greedy Summation**           | 🟢 O(n²)                | 🟢 O(1)                 | 🚀 No extra space                | 🔄 Three matrix traversals            |
| 🔍 **Single Pass Storage**        | 🟢 O(n²)                | 🟡 O(n)                 | 📈 Fewer traversals               | 💾 Extra space for row sums          |
| 📊 **Transpose Matrix**           | 🟢 O(n²)                | 🔴 O(n²)                | 🎯 Better cache locality         | 💾 Significant extra space           |
| 🔄 **Prefix Sum**                 | 🟢 O(n²)                | 🟡 O(n)                 | ⭐ Most efficient traversal       | 🔧 Slightly more complex logic       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Memory constrained**                         | 🥇 **Greedy Summation**               | ★★★★★                     |
| 📖 **Performance critical**                       | 🥈 **Prefix Sum**                     | ★★★★★                     |
| 🔧 **Large matrices**                             | 🥉 **Single Pass Storage**            | ★★★★☆                     |
| 🎯 **Cache optimization**                         | 🏅 **Transpose Matrix**               | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public static int balanceSums(int[][] mat) {
        int n = mat.length, max = 0, res = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) sum += mat[i][j];
            max = Math.max(sum, max);
        }
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) sum += mat[i][j];
            max = Math.max(sum, max);
        }
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) sum += mat[i][j];
            res += max - sum;
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def balanceSums(self, mat):
        n, max_sum, res = len(mat), 0, 0
        for i in range(n):
            sum_val = sum(mat[i])
            max_sum = max(sum_val, max_sum)
        for j in range(n):
            sum_val = sum(mat[i][j] for i in range(n))
            max_sum = max(sum_val, max_sum)
        for i in range(n):
            res += max_sum - sum(mat[i])
        return res
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

