---
title: "➕ Count pairs Sum in matrices | GFG Solution 🧮"
keywords🏷️: ["🔢 matrix pair sum", "💡 2D array", "🧠 two-pointer", "💥 brute-force", "📈 sorted matrix", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution for counting valid pairs from two matrices such that their sum equals X. Includes optimized two-pointer logic and more. 🚀"
date: 📅 2025-06-01
---

# *01. Count pairs Sum in matrices*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/count-pairs-sum-in-matrices/1)



## **🧩 Problem Description**

Given two matrices `mat1[][]` and `mat2[][]` of size `n x n`, where elements in each matrix are arranged in strictly ascending order (each row is sorted, and the last element of a row is smaller than the first element of the next row). You are given a target value `x`. Count all pairs `{a, b}` such that `a` is from `mat1` and `b` is from `mat2`, and `a + b = x`.



## **📘 Examples**

### Example 1

```
Input:
n = 3, x = 21
mat1 = [
  [1,  5,  6],
  [8, 10, 11],
  [15,16, 18]
]
mat2 = [
  [2,  4,  7],
  [9, 10, 12],
  [13,16, 20]
]

Output: 4
Explanation:
Pairs summing to 21 are: (1,20), (5,16), (8,13), (11,10).
```

### Example 2

```
Input:
n = 2, x = 10
mat1 = [
  [1, 2],
  [3, 4]
]
mat2 = [
  [4, 5],
  [6, 7]
]

Output: 2
Explanation:
Pairs summing to 10 are: (4,6), (3,7).
```



## **🔒 Constraints**

* \$1 \le n \le 100\$
* \$1 \le \text{mat1}\[i]\[j], ,\text{mat2}\[i]\[j] \le 10^5\$
* \$1 \le x \le 10^5\$
* Both matrices are sorted in row-major ascending order (strictly).



## **✅ My Approach: Two-Pointer Style Traversal (Optimized)**

### 💡 Idea:

We treat both matrices as flattened lists and scan from opposite ends — start from top-left of `a[][]` and bottom-right of `b[][]`, moving in a two-pointer fashion based on the sum.

### 🧠 Algorithm Steps:

1. Initialize:

   * Pointer `r1 = 0, c1 = 0` for matrix `a`
   * Pointer `r2 = n-1, c2 = m-1` for matrix `b`
   * A `cnt` variable to store valid pair count.
2. While within bounds:

   * Compute `sum = a[r1][c1] + b[r2][c2]`
   * If sum matches `x`, increment `cnt`, move both pointers.
   * If sum < x, move `c1` forward in `a`; if out-of-bounds, reset `c1 = 0`, increment `r1`
   * If sum > x, move `c2` backward in `b`; if out-of-bounds, reset `c2 = m-1`, decrement `r2`
3. Stop when either matrix is exhausted.
4. Return `cnt`



## 📝 **Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(n²), because in the worst-case each of the `n²` elements in `mat1` and `mat2` is visited once by the two pointers.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of extra space for pointers and counters.



## **🧑‍💻 Code (C++)**

```cpp
class Solution {
  public:
    int countPairs(vector<vector<int>> &a, vector<vector<int>> &b, int x) {
        int r1 = 0, c1 = 0, r2 = b.size() - 1, c2 = b[0].size() - 1, cnt = 0;
        while (r1 < a.size() && r2 >= 0) {
            int sum = a[r1][c1] + b[r2][c2];
            if (sum == x) ++cnt, ++c1, --c2;
            else if (sum < x) ++c1;
            else --c2;
            if (c1 == a[0].size()) c1 = 0, ++r1;
            if (c2 < 0) c2 = b[0].size() - 1, --r2;
        }
        return cnt;
    }
};
```


<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>


## 📊 **2️⃣ Hash Map (Value Frequency Counter)**

### 💡 Algorithm Steps:

1. Traverse all elements of `mat2` and store their frequencies in a `unordered_map<int, int>`.
2. Iterate over `mat1` and for each element `a[i][j]`, compute `rem = x - a[i][j]`.
3. Increment count by frequency of `rem` in the map.

```cpp
class Solution {
  public:
    int countPairs(vector<vector<int>> &a, vector<vector<int>> &b, int x) {
        unordered_map<int, int> freq;
        for (auto &row : b)
            for (int val : row) ++freq[val];
        int cnt = 0;
        for (auto &row : a)
            for (int val : row) cnt += freq[x - val];
        return cnt;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²)
* **Auxiliary Space:** 💾 O(n²)

### ✅ **Why This Approach?**

* Efficient for unsorted matrices.
* Leverages constant-time hashmap lookup.




## 📊 **3️⃣ Sort + Two Pointer on Flattened Grids**

### 💡 Algorithm Steps:

1. Flatten both matrices into 1D arrays.
2. Sort `a_flat` in ascending and `b_flat` in descending order.
3. Use two pointers to count pairs summing to `x`.

```cpp
class Solution {
  public:
    int countPairs(vector<vector<int>> &a, vector<vector<int>> &b, int x) {
        vector<int> v1, v2;
        for (auto &r : a) v1.insert(v1.end(), r.begin(), r.end());
        for (auto &r : b) v2.insert(v2.end(), r.begin(), r.end());
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end(), greater<int>());
        int i = 0, j = 0, cnt = 0;
        while (i < v1.size() && j < v2.size()) {
            int sum = v1[i] + v2[j];
            if (sum == x) ++cnt, ++i, ++j;
            else if (sum < x) ++i;
            else ++j;
        }
        return cnt;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n² log n)
* **Auxiliary Space:** 💾 O(n²)

### ✅ **Why This Approach?**

* Good balance of time and space if flattening is viable.
* Works when matrix values are disorganized.

## 📊 **4️⃣ Brute Force (Double Nested Loops)**

### 💡 Algorithm Steps:

1. Use two nested loops to try every combination of elements from `mat1` and `mat2`.
2. Count all pairs whose sum equals `x`.

```cpp
class Solution {
  public:
    int countPairs(vector<vector<int>> &a, vector<vector<int>> &b, int x) {
        int cnt = 0;
        for (auto &row1 : a)
            for (int val1 : row1)
                for (auto &row2 : b)
                    for (int val2 : row2)
                        if (val1 + val2 == x) ++cnt;
        return cnt;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n⁴)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Works universally without needing sorting or extra space.
* Very inefficient for large matrices.

### ⚠️ Warning: TLE on Large Inputs
#### ✅ Test Cases Passed: 1010 / 1115
##### ❌ Result: Time Limit Exceeded (TLE) 
###### 🕓 Issue: Brute-force algorithm exceeded time constraints on larger test cases due to O(n⁴) complexity Won’t pass when `n` approaches 100 due to time explosion.



## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**         | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                      | ⚠️ **Cons**                     |
| ----------------------- | ---------------------- | ----------------------- | ------------------------------- | ------------------------------- |
| 🔍 **Two Pointer**      | 🟢 O(n²)               | 🟢 O(1)                 | Fast for sorted matrices        | Needs sorted grid               |
| 📦 **Hash Map**         | 🟢 O(n²)               | 🟡 O(n²)                | Best for unsorted matrices      | Extra memory                    |
| 🧮 **Sort + 2-Pointer** | 🟡 O(n² log n)         | 🟡 O(n²)                | Efficient for disjoint matrices | Needs full flatten and sort     |
| 🐢 **Brute Force (TLE)**      | 🔴 O(n⁴)               | 🟢 O(1)                 | Simplest universal logic        | Extremely slow for large inputs |


### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                     | 🥇 **Recommended Approach** |
| ----------------------------------- | --------------------------- |
| ✅ Both matrices sorted                | 🥇 Two Pointer               |
| 📋 Matrices unsorted                   | 🥈 Hash Map                  |
| 💥 Arrays easily flattenable           | 🥉 Sort + Two Pointer        |
| 🔍 Small size or brute force benchmark | 🎖️ Brute Force (TLE)              |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    int countPairs(int[][] a, int[][] b, int x) {
        int r1 = 0, c1 = 0, r2 = b.length - 1, c2 = b[0].length - 1, cnt = 0;
        while (r1 < a.length && r2 >= 0) {
            int sum = a[r1][c1] + b[r2][c2];
            if (sum == x) { cnt++; c1++; c2--; }
            else if (sum < x) c1++;
            else c2--;
            if (c1 == a[0].length) { c1 = 0; r1++; }
            if (c2 < 0) { c2 = b[0].length - 1; r2--; }
        }
        return cnt;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def countPairs(self, a, b, x):
        r1 = c1 = 0
        r2, c2 = len(b) - 1, len(b[0]) - 1
        cnt = 0
        while r1 < len(a) and r2 >= 0:
            s = a[r1][c1] + b[r2][c2]
            if s == x:
                cnt += 1
                c1 += 1
                c2 -= 1
            elif s < x:
                c1 += 1
            else:
                c2 -= 1
            if c1 == len(a[0]):
                c1 = 0
                r1 += 1
            if c2 < 0:
                c2 = len(b[0]) - 1
                r2 -= 1
        return cnt
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
