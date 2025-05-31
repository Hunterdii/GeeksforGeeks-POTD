---
title: "🔢 Kth Element in Matrix | GFG Solution 🎯"
keywords🏷️: ["🔢 kth smallest", "🔍 binary search", "🧮 matrix", "🧠 min-heap", "📈 sorted matrix", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Kth Element in Matrix problem: find the kth smallest in a sorted matrix using binary search or heap. 🚀"
date: 📅 2025-05-31
---


# *31. Kth Element in Matrix*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/kth-element-in-matrix/1)

## **🧩 Problem Description**

Given a `n x n` matrix in which **each row and column is sorted in ascending order**, find the **kth smallest element** in the matrix.

## **📘 Examples**

### Example 1

```
Input: n = 4, mat = [
  [16, 28, 60, 64],
  [22, 41, 63, 91],
  [27, 50, 87, 93],
  [36, 78, 87, 94]
], k = 3

Output: 27
Explanation: The 3rd smallest element in the sorted order is 27.
```

### Example 2

```
Input: n = 4, mat = [
  [10, 20, 30, 40],
  [15, 25, 35, 45],
  [24, 29, 37, 48],
  [32, 33, 39, 50]
], k = 7

Output: 30
Explanation: The 7th smallest element in the sorted order is 30.
```


## **🔒 Constraints**

* $1 \le n \le 500$
* $1 \le \text{mat}[i][j] \le 10^4$
* $1 \le k \le n^2$



## **✅ My Approach**

We have three common approaches for finding the kth smallest element in a row- and column-sorted matrix:

### 1️⃣ **Binary Search on Value Range**

1. **Idea:**

   * Let `low = mat[0][0]`, `high = mat[n-1][n-1]`.
   * Perform a binary search on the value range `[low, high]` to find the smallest `mid` such that at least `k` elements in the matrix are ≤ `mid`.
2. **Counting ≤ mid:**

   * For each row `i`, maintain a pointer `j` starting at `n-1`.
   * While `j ≥ 0` and `mat[i][j] > mid`, decrement `j`.
   * Count of elements ≤ `mid` in row `i` is `j + 1`.
   * Sum up counts over all rows.
3. **Binary Search Steps:**

   * Compute `mid = low + (high - low) / 2`.
   * If `count(mid) < k`, set `low = mid + 1`.
   * Else, set `high = mid`.
   * Continue until `low == high`.
4. **Result:**

   * Return `low`, which is the kth smallest element.



## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × log(max - min)), where `max` and `min` are the matrix's largest and smallest values respectively.
* **Expected Auxiliary Space Complexity:** O(1), since we do not use extra memory except 



## **🧑‍💻 Code (C++)**

```cpp
class Solution {
  public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), l = matrix[0][0], r = matrix[n-1][n-1];
        while (l < r) {
            int m = l + (r - l) / 2, cnt = 0;
            for (int i = 0, j = n - 1; i < n; ++i) {
                while (j >= 0 && matrix[i][j] > m) --j;
                cnt += j + 1;
            }
            if (cnt < k) l = m + 1;
            else r = m;
        }
        return l;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>



## 📊 **2️⃣ Min Heap (Priority Queue)**

### 💡 Algorithm Steps:

1. Create a min-heap (priority queue) of tuples `(value, row, col)`.
2. Push the first element of each row:

   ```cpp
   for (int i = 0; i < n; ++i)
       pq.emplace(matrix[i][0], i, 0);
   ```
3. Repeat `k-1` times:

   * Pop the smallest tuple `(val, r, c)`.
   * If `c+1 < n`, push `(matrix[r][c+1], r, c+1)` into the heap.
4. After `k-1` pops, the top of the heap holds the kth smallest element.

```cpp
class Solution {
  public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        for (int i = 0; i < n; ++i) 
            pq.emplace(matrix[i][0], i, 0);

        while (--k) {
            T top = pq.top(); 
            pq.pop();
            int val = get<0>(top), r = get<1>(top), c = get<2>(top);
            if (c + 1 < n) 
                pq.emplace(matrix[r][c + 1], r, c + 1);
        }
        return get<0>(pq.top());
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(k × log n)
* **Auxiliary Space:** 💾 O(n)

### ✅ **Why This Approach?**

* Leverages built-in min-heap for simplicity.
* Efficient when `k` is relatively small compared to `n²`.


## 📊 **3️⃣ Flatten + Sort**

### 💡 Algorithm Steps:

1. Flatten all elements of the matrix into a single 1D vector `flat`:

   ```cpp
   vector<int> flat;
   for (auto& row : matrix)
       flat.insert(flat.end(), row.begin(), row.end());
   ```
2. Sort `flat`:

   ```cpp
   sort(flat.begin(), flat.end());
   ```
3. Return `flat[k-1]`.

```cpp
class Solution {
  public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> flat;
        for (auto& row : matrix)
            flat.insert(flat.end(), row.begin(), row.end());
        sort(flat.begin(), flat.end());
        return flat[k - 1];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n² × log n)
* **Auxiliary Space:** 💾 O(n²)

### ✅ **Why This Approach?**

* Most straightforward: flatten, sort, index.
* Only suitable for small matrices due to O(n² log n).



## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**       | ⏱️ **Time Complexity**           | 💾 **Space Complexity** | ✅ **Pros**                            | ⚠️ **Cons**                                     |
| --------------------- | -------------------------------- | ----------------------- | ------------------------------------- | ----------------------------------------------- |
| 🔍 **Binary Search**  | 🟢 O(n × log(max\_val−min\_val)) | 🟢 O(1)                 | ⚡ Fastest for large matrices          | 🧮 Counting ≤ mid for each row                  |
| 📦 **Min Heap**       | 🟡 O(k × log n)                  | 🟢 O(n)                 | 🔧 Straightforward with built-in heap | 🐢 Slower if k is large (close to n²)           |
| 🧮 **Flatten + Sort** | 🔸 O(n² × log n)                 | 🔸 O(n²)                | 🪄 Simplest to implement              | 🚫 Inefficient for large n (time & space heavy) |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                   | 🎖️ **Recommended Approach** |
| ------------------------------------------------- | ---------------------------- |
| ⚡ Need fastest overall (large n, large k)         | 🥇 **Binary Search**         |
| 🧵 Prefer heap logic (k relatively small)         | 🥈 **Min Heap**              |
| 📋 Quick prototype/brute-force for small matrices | 🥉 **Flatten + Sort**        |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length, l = matrix[0][0], r = matrix[n - 1][n - 1];
        while (l < r) {
            int m = l + (r - l) / 2, cnt = 0, j = n - 1;
            for (int i = 0; i < n; ++i) {
                while (j >= 0 && matrix[i][j] > m) --j;
                cnt += j + 1;
            }
            if (cnt < k) l = m + 1;
            else r = m;
        }
        return l;
    }
}
```



## **🐍 Code (Python)**

```python
class Solution:
    def kthSmallest(self, matrix, k):
        n, l, r = len(matrix), matrix[0][0], matrix[-1][-1]
        while l < r:
            m = (l + r) // 2
            cnt, j = 0, n - 1
            for i in range(n):
                while j >= 0 and matrix[i][j] > m:
                    j -= 1
                cnt += j + 1
            if cnt < k:
                l = m + 1
            else:
                r = m
        return l
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
