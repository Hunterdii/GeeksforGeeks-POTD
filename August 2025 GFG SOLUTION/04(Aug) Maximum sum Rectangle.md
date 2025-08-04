---
title: "📐 Maximum Sum Rectangle | GFG Solution 🔍"
keywords🏷️: ["📐 maximum sum rectangle", "🔍 column compression", "🧠 dynamic programming",  "📍 kadane's algorithm", "📈 submatrix sum", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Maximum Sum Rectangle problem: find maximum possible sum of any submatrix using column compression and Kadane's algorithm. 🚀"
date: 📅 2025-08-04
---

# *04. Maximum Sum Rectangle*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1)

## **🧩 Problem Description**

Given a 2D matrix `mat[][]` with dimensions `n×m`, find the **maximum possible sum** of any submatrix within the given matrix.

A submatrix is any contiguous rectangular region within the matrix. The goal is to find the submatrix with the largest sum of all its elements.

## **📘 Examples**

### Example 1

```cpp
Input: mat[][] = [[1, 2, -1, -4, -20], [-8, -3, 4, 2, 1], [3, 8, 10, 1, 3], [-4, -1, 1, 7, -6]]
Output: 29
Explanation: The matrix is as follows and the green rectangle denotes the maximum sum rectangle 
which is equal to 29.
```

### Example 2

```cpp
Input: mat[][] = [[-1, -2], [-3, -4]]
Output: -1
Explanation: Taking only the first cell is the optimal choice.
```

## **🔒 Constraints**

* $1 \le n, m \le 300$
* $-1000 \le \text{mat}[i][j] \le 1000$

## **✅ My Approach**

The optimal approach uses **Column Compression** technique combined with **Kadane's Algorithm** to efficiently find the maximum sum rectangle:

### **Column Compression + Kadane's Algorithm**

1. **Fix Column Boundaries:**
   * Use two pointers `l` (left column) and `r` (right column) to define column boundaries.
   * For each pair of columns, we compress the 2D problem into a 1D problem.

2. **Column Compression:**
   * Create a temporary array `temp[]` of size `m` (number of rows).
   * For columns from `l` to `r`, sum all elements row-wise into `temp[]`.
   * This converts the 2D submatrix problem into finding maximum subarray in 1D.

3. **Apply Kadane's Algorithm:**
   * On the compressed 1D array `temp[]`, apply Kadane's algorithm to find maximum subarray sum.
   * This gives us the maximum sum rectangle with column boundaries from `l` to `r`.

4. **Track Global Maximum:**
   * Update the global maximum across all possible column boundary combinations.
   * Continue until all column pairs are processed.

5. **Algorithm Flow:**
   * Outer loop: Fix left column boundary `l`
   * Inner loop: Extend right column boundary `r` 
   * For each (`l`, `r`) pair, compress and apply Kadane's
   * Return the maximum sum found

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n²m), where n is the number of columns and m is the number of rows. We iterate through all possible column pairs O(n²) and for each pair, we apply Kadane's algorithm which takes O(m) time.
* **Expected Auxiliary Space Complexity:** O(m), where m is the number of rows. We use a temporary array of size m to store the compressed column sums.


## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxRectSum(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = INT_MIN;
        for (int l = 0; l < n; l++) {
            vector<int> temp(m, 0);
            for (int r = l; r < n; r++) {
                for (int i = 0; i < m; i++) temp[i] += mat[i][r];
                int sum = 0, maxSum = temp[0];
                for (int x : temp) {
                    sum = max(x, sum + x);
                    maxSum = max(maxSum, sum);
                }
                res = max(res, maxSum);
            }
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Brute Force All Rectangles**

### 💡 Algorithm Steps:

1. Check every possible rectangle by fixing top-left and bottom-right corners.
2. Calculate sum of each rectangle using nested loops.
3. Track the maximum sum found across all possible rectangles.
4. Direct approach without additional data structures.

```cpp
class Solution {
public:
    int maxRectSum(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = INT_MIN;
        for (int r1 = 0; r1 < m; r1++) {
            for (int c1 = 0; c1 < n; c1++) {
                for (int r2 = r1; r2 < m; r2++) {
                    for (int c2 = c1; c2 < n; c2++) {
                        int sum = 0;
                        for (int i = r1; i <= r2; i++)
                            for (int j = c1; j <= c2; j++)
                                sum += mat[i][j];
                        res = max(res, sum);
                    }
                }
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m²n²) - Four nested loops to check all rectangles
* **Auxiliary Space:** 💾 O(1) - No extra space needed

### ✅ **Why This Approach?**

* Simple and straightforward implementation
* No complex data structures or algorithms
* Easy to debug and understand logic flow

> **Note:** This approach results in **Time Limit Exceeded (TLE)** for large inputs _(fails ~1005 /1110 test cases due to time constraints)_.

## 📊 **3️⃣ Row-wise Kadane Approach**

### 💡 Algorithm Steps:

1. Fix top and bottom row boundaries for each possible row range.
2. Compress the 2D problem into 1D by summing elements column-wise.
3. Apply Kadane's algorithm on the compressed 1D array to find maximum subarray.
4. Track global maximum across all possible row boundary combinations.

```cpp
class Solution {
public:
    int maxRectSum(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = INT_MIN;
        for (int top = 0; top < m; top++) {
            vector<int> temp(n, 0);
            for (int bottom = top; bottom < m; bottom++) {
                for (int j = 0; j < n; j++) temp[j] += mat[bottom][j];
                int sum = 0, maxSum = temp[0];
                for (int x : temp) {
                    sum = max(x, sum + x);
                    maxSum = max(maxSum, sum);
                }
                res = max(res, maxSum);
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m²n) - Row pairs times Kadane's algorithm
* **Auxiliary Space:** 💾 O(n) - Temporary array for column compression

### ✅ **Why This Approach?**

* Alternative perspective fixing rows instead of columns
* Efficient when matrix has more columns than rows
* Clear separation of 2D to 1D transformation

## 📊 **4️⃣ Optimized Single Pass**

### 💡 Algorithm Steps:

1. Use the main column compression approach but with inline optimizations.
2. Combine array updates with Kadane's algorithm in single loop.
3. Eliminate unnecessary variable assignments and function calls.
4. Minimize memory access patterns for better cache performance.

```cpp
class Solution {
public:
    int maxRectSum(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), res = INT_MIN;
        for (int l = 0; l < n; l++) {
            vector<int> temp(m, 0);
            for (int r = l; r < n; r++) {
                int currMax = INT_MIN, sum = 0;
                for (int i = 0; i < m; i++) {
                    temp[i] += mat[i][r];
                    sum = max(temp[i], sum + temp[i]);
                    currMax = max(currMax, sum);
                }
                res = max(res, currMax);
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²m) - Same complexity with better constant factors
* **Auxiliary Space:** 💾 O(m) - Single temporary array with optimized access

### ✅ **Why This Approach?**

* Maximum performance optimization within same complexity
* Reduced variable assignments and memory access
* Best balance of readability and efficiency

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Column Compression**         | 🟢 O(n²m)              | 🟢 O(m)                 | 🚀 Optimal for most cases        | 🔧 Requires understanding Kadane's   |
| 🔍 **Brute Force**                | 🟡 O(m²n²)             | 🟢 O(1)                 | 📖 Simple to understand          | 🐌 Higher time complexity            |
| 📊 **Row-wise Kadane**            | 🟢 O(m²n)              | 🟢 O(n)                 | 🎯 Good for wide matrices        | 🔧 Different approach pattern        |
| 🔄 **Optimized Single Pass**      | 🟢 O(n²m)              | 🟢 O(m)                 | ⭐ Best constant factors         | 🔧 Slightly more complex logic       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General optimal performance**                   | 🥇 **Column Compression**            | ★★★★★                     |
| 📖 **Learning/Simple implementation**                | 🥈 **Brute Force**                   | ★★★☆☆                     |
| 🔧 **Wide matrices (n >> m)**                        | 🥉 **Row-wise Kadane**               | ★★★★☆                     |
| 🎯 **Maximum optimization needed**                   | 🏅 **Optimized Single Pass**         | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int maxRectSum(int mat[][]) {
        int m = mat.length, n = mat[0].length, res = Integer.MIN_VALUE;
        for (int l = 0; l < n; l++) {
            int[] temp = new int[m];
            for (int r = l; r < n; r++) {
                for (int i = 0; i < m; i++) temp[i] += mat[i][r];
                int sum = 0, maxSum = temp[0];
                for (int x : temp) {
                    sum = Math.max(x, sum + x);
                    maxSum = Math.max(maxSum, sum);
                }
                res = Math.max(res, maxSum);
            }
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxRectSum(self, mat):
        m, n, res = len(mat), len(mat[0]), float('-inf')
        for l in range(n):
            temp = [0] * m
            for r in range(l, n):
                for i in range(m):
                    temp[i] += mat[i][r]
                sum_val, max_sum = 0, temp[0]
                for x in temp:
                    sum_val = max(x, sum_val + x)
                    max_sum = max(max_sum, sum_val)
                res = max(res, max_sum)
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
