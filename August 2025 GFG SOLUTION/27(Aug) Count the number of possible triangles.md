---
title: "🔺 Count the Number of Possible Triangles | GFG Solution 📐"
keywords🏷️: ["🔺 triangle counting", "🔍 two pointers", "📊 sorting", "📈 geometric properties", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to count possible triangles problem: find number of valid triangles using triangle inequality theorem with efficient two-pointer technique. 🚀"
date: 📅 2025-08-27
---

# *27. Count the Number of Possible Triangles*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/count-possible-triangles-1587115620/1)

## **🧩 Problem Description**

Given an integer array `arr[]`, find the number of triangles that can be formed with three different array elements as lengths of three sides of the triangle. A triangle with three given sides is only possible if the sum of any two sides is always greater than the third side (Triangle Inequality Theorem).

For three sides `a`, `b`, and `c` to form a valid triangle:
- `a + b > c`
- `a + c > b` 
- `b + c > a`

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [4, 6, 3, 7]
Output: 3
Explanation: There are three triangles possible [3, 4, 6], [4, 6, 7] and [3, 6, 7]. 
Note that [3, 4, 7] is not a possible triangle since 3 + 4 = 7, which violates the triangle inequality.
```

### Example 2

```cpp
Input: arr[] = [10, 21, 22, 100, 101, 200, 300]
Output: 6
Explanation: There can be 6 possible triangles: [10, 21, 22], [21, 100, 101], [22, 100, 101], 
[10, 100, 101], [100, 101, 200] and [101, 200, 300].
```

### Example 3

```cpp
Input: arr[] = [1, 2, 3]
Output: 0
Explanation: No triangles are possible since 1 + 2 = 3, which doesn't satisfy the strict inequality.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^3$
* $0 \le \text{arr}[i] \le 10^5$

## **✅ My Approach**

The optimal approach uses **Sorting** combined with **Two Pointers** technique to efficiently count valid triangles:

### **Sorting + Two Pointers (Backward Iteration)**

1. **Sort the Array:**
   * Sort the array in ascending order to apply triangle inequality efficiently.
   * After sorting, for any three elements at indices `i < j < k`, we have `arr[i] ≤ arr[j] ≤ arr[k]`.

2. **Fix the Largest Side:**
   * Iterate from the largest element backwards (index `k` from `n-1` to `2`).
   * Fix `arr[k]` as the largest side of potential triangles.

3. **Apply Triangle Inequality:**
   * For a sorted array, if `arr[i] + arr[j] > arr[k]` (where `i < j < k`), then all elements between `i` and `j` will also satisfy this condition with `arr[j]`.
   * Use two pointers: `i = 0` (left) and `j = k-1` (right).

4. **Count Valid Triangles:**
   * If `arr[i] + arr[j] > arr[k]`: All triangles formed by fixing `j` and `k`, and choosing any element from index `i` to `j-1` are valid. Add `(j - i)` to count.
   * If `arr[i] + arr[j] ≤ arr[k]`: Move left pointer right to increase the sum.

5. **Optimize with Two Pointers:**
   * Move pointers based on triangle inequality validation to avoid redundant checks.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n²), where n is the size of the array. The outer loop runs n times, and the inner two-pointer traversal takes O(n) time for each iteration. Sorting takes O(n log n), but the overall complexity is dominated by O(n²).
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables. The sorting is typically done in-place.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int countTriangles(vector<int>& a) {
        sort(a.begin(), a.end());
        int c = 0, n = a.size();
        for (int k = n - 1; k >= 2; --k) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (a[i] + a[j] > a[k]) {
                    c += j - i;
                    --j;
                } else ++i;
            }
        }
        return c;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Forward Iteration Approach**

### 💡 Algorithm Steps:

1. Sort array to enable two-pointer technique with triangle inequality.
2. Fix largest side as rightmost element and use two pointers from left.
3. If sum of two smaller sides > largest, count all valid combinations.
4. Adjust pointers based on triangle inequality validation.

```cpp
class Solution {
public:
    int countTriangles(vector<int>& a) {
        sort(a.begin(), a.end());
        int res = 0;
        for (int i = 2; i < a.size(); ++i) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (a[l] + a[r] > a[i]) {
                    res += r - l;
                    --r;
                } else ++l;
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Nested loops with two-pointer optimization
* **Auxiliary Space:** 💾 O(1) - Sorting in-place with constant extra space

### ✅ **Why This Approach?**

* Classic two-pointer pattern for triangle counting
* Forward iteration matches intuitive array traversal
* Easy to understand progression through array

## 📊 **3️⃣ Binary Search Optimization**

### 💡 Algorithm Steps:

1. Sort array to enable binary search for third side bounds.
2. Fix two sides and binary search for valid third sides.
3. Find upper bound where triangle inequality holds.
4. Count all elements between current position and upper bound.

```cpp
class Solution {
public:
    int countTriangles(vector<int>& a) {
        sort(a.begin(), a.end());
        int cnt = 0, n = a.size();
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                int sum = a[i] + a[j];
                int k = upper_bound(a.begin() + j + 1, a.end(), sum - 1) - a.begin();
                cnt += k - j - 1;
            }
        }
        return cnt;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n² log n) - Two loops with binary search
* **Auxiliary Space:** 💾 O(1) - Constant space with binary search

### ✅ **Why This Approach?**

* Reduces inner loop complexity using binary search
* Good for theoretical optimization in certain scenarios
* Demonstrates advanced search optimization techniques

## 📊 **4️⃣ Brute Force Approach**

### 💡 Algorithm Steps:

1. Use three nested loops to check all possible triplets.
2. For each triplet (i, j, k), verify triangle inequality conditions.
3. Check all three conditions: a+b>c, a+c>b, b+c>a.
4. Count valid triangles that satisfy all conditions.

```cpp
class Solution {
public:
    int countTriangles(vector<int>& a) {
        int cnt = 0, n = a.size();
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (a[i] + a[j] > a[k] && 
                        a[i] + a[k] > a[j] && 
                        a[j] + a[k] > a[i]) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n³) - Three nested loops
* **Auxiliary Space:** 💾 O(1) - No extra space needed

### ✅ **Why This Approach?**

* Simple and straightforward implementation
* No need for sorting or complex logic
* Good for small datasets or educational purposes

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110 /1120 test cases due to time constraints).


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔄 **Backward Two-Pointer**        | 🟢 O(n²)               | 🟢 O(1)                 | 🚀 Optimal for this problem      | 🔧 Slightly different logic flow     |
| ➡️ **Forward Two-Pointer**         | 🟢 O(n²)               | 🟢 O(1)                 | 📖 Intuitive array traversal     | 🔄 Same complexity as backward       |
| 🎯 **Binary Search**              | 🟡 O(n² log n)         | 🟢 O(1)                 | ⭐ Advanced optimization concept  | 🔧 More complex, not always faster   |
| 🔢 **Brute Force**                | 🔴 O(n³)               | 🟢 O(1)                 | 📚 Simple to understand          | ⏰ Too slow for large inputs         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Backward Two-Pointer**          | ★★★★★                     |
| 📖 **Code readability priority**                      | 🥈 **Forward Two-Pointer**           | ★★★★★                     |
| 🎓 **Learning/Educational purpose**                   | 🎖️ **Brute Force**                   | ★★★☆☆                     |
| 🚀 **Theoretical optimization**                       | 🏅 **Binary Search**                 | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int countTriangles(int[] a) {
        Arrays.sort(a);
        int c = 0, n = a.length;
        for (int k = n - 1; k >= 2; --k) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (a[i] + a[j] > a[k]) {
                    c += j - i;
                    --j;
                } else ++i;
            }
        }
        return c;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def countTriangles(self, a):
        a.sort()
        c, n = 0, len(a)
        for k in range(n - 1, 1, -1):
            i, j = 0, k - 1
            while i < j:
                if a[i] + a[j] > a[k]:
                    c += j - i
                    j -= 1
                else:
                    i += 1
        return c
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
