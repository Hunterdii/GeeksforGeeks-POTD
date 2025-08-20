---
title: "🔍 Search in Fully Rotated Sorted 2D Matrix | GFG Solution 🎯"
keywords🏷️: ["🔍 matrix search", "🌀 rotated matrix", "📍 binary search", "📈 2D array", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Search in Fully Rotated Sorted 2D Matrix: efficiently find target element in rotated sorted matrix using modified binary search technique. 🚀"
date: 📅 2025-08-20
---

# *20. Search in Fully Rotated Sorted 2D Matrix*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/search-in-fully-rotated-sorted-2d-matrix/1)

## **🧩 Problem Description**

You are given a 2D matrix `mat[][]` of size `n x m` that was initially filled in the following manner:

- Each row is sorted in increasing order from left to right.
- The first element of every row is greater than the last element of the previous row.

This implies that if the matrix is flattened row-wise, it forms a strictly sorted 1D array. Later, this sorted 1D array was rotated at some unknown pivot. The rotated array was then written back into the matrix row-wise to form the current matrix.

Given such a matrix `mat[][]` and an integer `x`, determine whether `x` exists in the matrix.

## **📘 Examples**

### Example 1

```cpp
Input: x = 3,
mat[][] = [[7, 8, 9, 10],           
          [11, 12, 13, 1],
          [2, 3, 4, 5]] 
Output: true
Explanation: 3 is located at the 3rd row and 2nd column.
```

### Example 2

```cpp
Input: x = 10,
mat[][] = [[6, 7, 8],                         
          [9, 1, 2],
          [3, 4, 5]]
Output: false
Explanation: The value 10 does not exist in the matrix.
```

## **🔒 Constraints**

* $1 \le n \times m \le 10^5$
* $1 \le \text{mat}[i][j], x \le 10^6$

## **✅ My Approach**

The optimal approach treats the 2D matrix as a flattened 1D rotated sorted array and applies **Modified Binary Search** for rotated arrays:

### **Modified Binary Search on Rotated Matrix**

1. **Matrix Flattening Concept:**
   * Treat the 2D matrix as a 1D array using index mapping: `mat[mid/m][mid%m]`
   * Use binary search pointers `l = 0` and `r = n*m - 1`

2. **Rotated Array Binary Search Logic:**
   * At each iteration, determine which half is sorted by comparing `mat[l/m][l%m]` with `mat[mid/m][mid%m]`
   * If left half is sorted: check if target lies in the left sorted portion
   * If right half is sorted: check if target lies in the right sorted portion

3. **Decision Making:**
   * **Left half sorted** (`mat[l/m][l%m] <= mat[mid/m][mid%m]`):
     - If `mat[l/m][l%m] <= x < mat[mid/m][mid%m]`: search left half (`r = mid - 1`)
     - Otherwise: search right half (`l = mid + 1`)
   * **Right half sorted**:
     - If `mat[mid/m][mid%m] < x <= mat[r/m][r%m]`: search right half (`l = mid + 1`)
     - Otherwise: search left half (`r = mid - 1`)

4. **Index Conversion:**
   * Convert 1D index `i` to 2D coordinates: `row = i/m`, `col = i%m`
   * This allows seamless navigation through the matrix as a linear array

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(log(n*m)), where n*m is the total number of elements in the matrix. We perform binary search on the flattened matrix, reducing search space by half in each iteration.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables like pointers and temporary values, regardless of the matrix size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size();
        int l = 0, r = n * m - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mat[mid / m][mid % m];
            if (val == x) return true;
            if (mat[l / m][l % m] <= val) {
                if (mat[l / m][l % m] <= x && x < val) r = mid - 1;
                else l = mid + 1;
            } else {
                if (val < x && x <= mat[r / m][r % m]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return false;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Find Pivot + Binary Search**

### 💡 Algorithm Steps:

1. Find the pivot point where the array rotation occurs in the flattened matrix.
2. Determine which half contains the target based on pivot position.
3. Apply standard binary search on the identified sorted half.
4. Handle edge cases where no rotation exists.

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size();
        int pivot = findPivot(mat, n, m);
        if (pivot == 0) return binarySearch(mat, 0, n * m - 1, x, n, m);
        if (mat[0][0] <= x && x <= mat[(pivot-1)/m][(pivot-1)%m])
            return binarySearch(mat, 0, pivot - 1, x, n, m);
        return binarySearch(mat, pivot, n * m - 1, x, n, m);
    }
    int findPivot(vector<vector<int>>& mat, int n, int m) {
        int l = 0, r = n * m - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (mat[mid/m][mid%m] > mat[r/m][r%m]) l = mid + 1;
            else r = mid;
        }
        return l;
    }
    bool binarySearch(vector<vector<int>>& mat, int l, int r, int x, int n, int m) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mat[mid/m][mid%m];
            if (val == x) return true;
            if (val < x) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(log(n*m)) - Two binary searches
* **Auxiliary Space:** 💾 O(1) - Constant space usage

### ✅ **Why This Approach?**

* Clear separation of pivot finding and searching
* Easy to understand and debug
* Reuses standard binary search logic

## 📊 **3️⃣ Row-wise Rotated Search**

### 💡 Algorithm Steps:

1. Check each row individually to see if target can exist in that row.
2. For each valid row, apply rotated array binary search.
3. Use the property that each row is a rotated sorted array.
4. Return true as soon as target is found in any row.

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        for (auto& row : mat) {
            if (searchInRotatedArray(row, x)) return true;
        }
        return false;
    }
    bool searchInRotatedArray(vector<int>& arr, int x) {
        int l = 0, r = arr.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == x) return true;
            if (arr[l] <= arr[mid]) {
                if (arr[l] <= x && x < arr[mid]) r = mid - 1;
                else l = mid + 1;
            } else {
                if (arr[mid] < x && x <= arr[r]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return false;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n * log m) - Binary search on each row
* **Auxiliary Space:** 💾 O(1) - Constant space usage

### ✅ **Why This Approach?**

* Leverages row-wise rotation property
* Modular design with separate functions
* Good when matrix has few rows

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Modified Binary Search**     | 🟢 O(log(n*m))        | 🟢 O(1)                 | 🚀 Optimal time complexity       | 🔧 Complex rotation handling         |
| 🔍 **Pivot + Binary Search**      | 🟢 O(log(n*m))        | 🟢 O(1)                 | 📖 Clear logic separation        | 🛠️ More code to maintain            |
| 📊 **Row-wise Search**            | 🟡 O(n * log m)       | 🟢 O(1)                 | 🎯 Leverages row structure       | 🐌 Slower for wide matrices         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                 | 🥇 **Modified Binary Search**        | ★★★★★                     |
| 📖 **Code clarity priority**                      | 🥈 **Pivot + Binary Search**         | ★★★★☆                     |
| 🔧 **Row-oriented data processing**               | 🥉 **Row-wise Search**               | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public boolean searchMatrix(int[][] mat, int x) {
        int n = mat.length, m = mat[0].length;
        int l = 0, r = n * m - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = mat[mid / m][mid % m];
            if (val == x) return true;
            if (mat[l / m][l % m] <= val) {
                if (mat[l / m][l % m] <= x && x < val) r = mid - 1;
                else l = mid + 1;
            } else {
                if (val < x && x <= mat[r / m][r % m]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return false;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def searchMatrix(self, mat, x):
        n, m = len(mat), len(mat[0])
        l, r = 0, n * m - 1
        while l <= r:
            mid = l + (r - l) // 2
            val = mat[mid // m][mid % m]
            if val == x: return True
            if mat[l // m][l % m] <= val:
                if mat[l // m][l % m] <= x < val: r = mid - 1
                else: l = mid + 1
            else:
                if val < x <= mat[r // m][r % m]: l = mid + 1
                else: r = mid - 1
        return False
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
