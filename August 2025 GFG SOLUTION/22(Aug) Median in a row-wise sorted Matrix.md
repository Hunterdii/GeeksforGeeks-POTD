---
title: "🔢 Median in a Row-wise Sorted Matrix | GFG Solution 🔍"
keywords🏷️: ["🔢 matrix median", "🔍 binary search", "📍 sorted matrix", "📈 upper bound", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to find median in a row-wise sorted matrix: efficiently find the median element using binary search on answer technique. 🚀"
date: 📅 2025-08-22
---

# *22. Median in a Row-wise Sorted Matrix*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1)

## **🧩 Problem Description**

Given a row-wise sorted matrix `mat[][]` of size `n*m`, where the number of rows and columns is always odd. Your task is to find the **median of the matrix**.

The median is the middle element when all matrix elements are arranged in sorted order. Since the total number of elements is always odd, there will be exactly one median element.

## **📘 Examples**

### Example 1

```cpp
Input: mat[][] = [[1, 3, 5], 
                  [2, 6, 9], 
                  [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. 
Hence, 5 is median (middle element at position 4 in 0-indexed array).
```

### Example 2

```cpp
Input: mat[][] = [[2, 4, 9],
                  [3, 6, 7],
                  [4, 7, 10]]
Output: 6
Explanation: Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10]. 
Hence, 6 is median (middle element at position 4 in 0-indexed array).
```

### Example 3

```cpp
Input: mat = [[3], [4], [8]]
Output: 4
Explanation: Sorting matrix elements gives us [3, 4, 8]. 
Hence, 4 is median (middle element at position 1 in 0-indexed array).
```

## **🔒 Constraints**

* $1 \le n, m \le 400$
* $1 \le \text{mat}[i][j] \le 2000$
* Both n and m are always odd

## **✅ My Approach**

The optimal approach uses **Binary Search on Answer** technique combined with **upper_bound** to efficiently find the median without actually sorting all elements:

### **Binary Search on Answer + Upper Bound**

1. **Initialize Search Range:**
   * Find minimum element: `lo = min(mat[i][0])` for all rows (leftmost elements).
   * Find maximum element: `hi = max(mat[i][m-1])` for all rows (rightmost elements).
   * Calculate required position: `req = (n * m + 1) / 2` (median position).

2. **Binary Search on Possible Values:**
   * For each candidate value `mid` in range `[lo, hi]`, count elements ≤ `mid`.
   * Use `upper_bound` on each row to count elements efficiently.

3. **Count Elements ≤ Mid:**
   * For each row, use `upper_bound(mat[i].begin(), mat[i].end(), mid)` to find position.
   * Sum up counts from all rows to get total elements ≤ `mid`.

4. **Adjust Search Range:**
   * If `count < req`: median is larger, so `lo = mid + 1`.
   * Else: median could be `mid` or smaller, so `hi = mid`.

5. **Convergence:**
   * When `lo == hi`, we found the median value.

**Key Insight:** Since each row is sorted, we can use binary search (`upper_bound`) to count elements ≤ any value in O(log m) time per row.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(32 * n * log(m)), where n is the number of rows and m is the number of columns. The factor 32 comes from the maximum number of binary search iterations needed for the range of possible values (since values are bounded by 2000, we need at most log₂(2000) ≈ 11 iterations, but we use 32 as a safe upper bound). For each iteration, we perform upper_bound on n rows, each taking O(log m) time.

* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables like lo, hi, mid, cnt, and req, regardless of the matrix size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int median(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int lo = mat[0][0], hi = mat[0][m-1];
        for (int i = 1; i < n; i++) {
            lo = min(lo, mat[i][0]);
            hi = max(hi, mat[i][m-1]);
        }
        int req = (n * m + 1) >> 1;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1), cnt = 0;
            for (int i = 0; i < n; i++)
                cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            if (cnt < req) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Linear Search with Count Array**

### 💡 Algorithm Steps:

1. Find min and max elements across all rows in the matrix.
2. For each possible value from min to max, count occurrences.
3. Find the value where cumulative count reaches the median position.
4. Return that value as the matrix median.

```cpp
class Solution {
public:
    int median(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> all;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                all.push_back(mat[i][j]);
        sort(all.begin(), all.end());
        return all[(n * m) / 2];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n*m*log(n*m)) - Due to sorting all elements
* **Auxiliary Space:** 💾 O(n*m) - Additional space for storing all elements

### ✅ **Why This Approach?**

* Simple and straightforward implementation
* Easy to understand and debug
* Works for any type of matrix (sorted or unsorted)

## 📊 **3️⃣ Merge K Sorted Arrays**

### 💡 Algorithm Steps:

1. Use priority queue to merge all sorted rows efficiently.
2. Extract elements one by one in sorted order.
3. Keep track of position to find the median element.
4. Return the element at median position.

```cpp
class Solution {
public:
    int median(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        priority_queue<pair<int, pair<int, int>>, 
                      vector<pair<int, pair<int, int>>>, 
                      greater<pair<int, pair<int, int>>>> pq;
        
        for (int i = 0; i < n; i++)
            pq.push({mat[i][0], {i, 0}});
        
        for (int cnt = 0; cnt < (n * m) / 2; cnt++) {
            auto top = pq.top(); pq.pop();
            int i = top.second.first, j = top.second.second;
            if (j + 1 < m)
                pq.push({mat[i][j + 1], {i, j + 1}});
        }
        return pq.top().first;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n*m*log(n)) - Priority queue operations
* **Auxiliary Space:** 💾 O(n) - Priority queue space

### ✅ **Why This Approach?**

* Efficient for large matrices with many rows
* Leverages the sorted property of rows
* Memory efficient compared to storing all elements

## 📊 **4️⃣ Range Binary Search with Optimization**

### 💡 Algorithm Steps:

1. Instead of searching entire range, use row-wise binary search for tighter bounds.
2. Apply binary search on the answer with optimized counting.
3. Use early termination when exact median position is found.
4. Optimize counting using binary search on each row.

```cpp
class Solution {
public:
    int median(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        auto count = [&](int x) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                int pos = upper_bound(mat[i].begin(), mat[i].end(), x) - mat[i].begin();
                cnt += pos;
            }
            return cnt;
        };
        
        int lo = INT_MAX, hi = INT_MIN;
        for (int i = 0; i < n; i++) {
            lo = min(lo, mat[i][0]);
            hi = max(hi, mat[i][m-1]);
        }
        
        int target = (n * m + 1) / 2;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (count(mid) >= target) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(32 * n * log(m)) - Binary search with optimized bounds
* **Auxiliary Space:** 💾 O(1) - Only constant extra space

### ✅ **Why This Approach?**

* Most optimized time complexity for sorted matrix
* Space efficient with constant auxiliary space
* Handles large value ranges efficiently

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Binary Search**              | 🟢 O(32*n*log(m))      | 🟢 O(1)                 | 🚀 Optimal for sorted matrix     | 🔧 Complex logic                     |
| 📋 **Linear Search**              | 🔴 O(n*m*log(n*m))     | 🔴 O(n*m)               | 📖 Simple implementation         | 🐌 High time & space complexity     |
| 🔀 **Priority Queue**             | 🟡 O(n*m*log(n))       | 🟡 O(n)                 | ⚡ Good for sparse matrices       | 💾 Extra space for heap             |
| 🎯 **Optimized Binary**           | 🟢 O(32*n*log(m))      | 🟢 O(1)                 | ⭐ Best overall performance       | 🔧 Most complex implementation      |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Large sorted matrices**                      | 🥇 **Binary Search**                 | ★★★★★                     |
| 📖 **Small matrices/Simplicity**                  | 🥈 **Linear Search**                 | ★★★☆☆                     |
| 🔧 **Memory constrained**                         | 🥉 **Binary Search**                 | ★★★★★                     |
| 🎯 **Interview/Competitive**                      | 🏅 **Optimized Binary**              | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int median(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        int lo = mat[0][0], hi = mat[0][m-1];
        for (int i = 1; i < n; i++) {
            lo = Math.min(lo, mat[i][0]);
            hi = Math.max(hi, mat[i][m-1]);
        }
        int req = (n * m + 1) / 2;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2, cnt = 0;
            for (int i = 0; i < n; i++) {
                int left = 0, right = m;
                while (left < right) {
                    int center = left + (right - left) / 2;
                    if (mat[i][center] <= mid) left = center + 1;
                    else right = center;
                }
                cnt += left;
            }
            if (cnt < req) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
}
```

## **🐍 Code (Python)**

```python
import bisect
class Solution:
    def median(self, mat):
        n, m = len(mat), len(mat[0])
        lo = min(row[0] for row in mat)
        hi = max(row[m-1] for row in mat)
        req = (n * m + 1) // 2
        while lo < hi:
            mid = (lo + hi) // 2
            cnt = sum(bisect.bisect_right(row, mid) for row in mat)
            if cnt < req:
                lo = mid + 1
            else:
                hi = mid
        return lo
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




















