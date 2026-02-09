---
title: "🔄 Find Kth Rotation | GFG Solution 🔍"
keywords🏷️: ["🔄 rotation count", "🔍 binary search", "📊 sorted array", "🔢 pivot finding", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Find Kth Rotation problem: determine how many times a sorted array has been rotated using efficient binary search technique. 🚀"
date: 📅 2025-02-09
---

# *09. Find Kth Rotation*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/rotation4723/1)

## **🧩 Problem Description**

Given an increasing sorted rotated array `arr[]` of distinct integers, find the value of `k` where the array has been right-rotated `k` times.

A rotated sorted array is an array that was originally sorted in increasing order but has been rotated (shifted) some number of positions to the right. For example, `[1, 2, 3, 4, 5]` rotated 2 times becomes `[4, 5, 1, 2, 3]`.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [5, 1, 2, 3, 4]
Output: 1
Explanation: The original sorted array is [1, 2, 3, 4, 5]. The array was rotated 1 time 
to the right, resulting in [5, 1, 2, 3, 4].
```

### Example 2

```cpp
Input: arr[] = [1, 2, 3, 4, 5]
Output: 0
Explanation: The given array is not rotated, hence k = 0.
```

### Example 3

```cpp
Input: arr[] = [6, 9, 2, 4]
Output: 2
Explanation: The original array [2, 4, 6, 9] was rotated 2 times to get [6, 9, 2, 4].
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^7$

## **✅ My Approach**

The optimal approach uses **Binary Search** to find the index of the minimum element, which represents the number of rotations:

### **Binary Search for Pivot Point**

1. **Key Observation:**
   * In a rotated sorted array, the minimum element is the pivot point.
   * The index of this minimum element equals the number of rotations.
   * All elements to the left of pivot are greater than elements to the right.

2. **Initialize Pointers:**
   * Set `left = 0` and `right = n - 1` to represent the search range.

3. **Binary Search Logic:**
   * Calculate middle index: `mid = (left + right) / 2`.
   * **If `arr[mid] > arr[right]`:** The minimum is in the right half (including mid+1), so move `left = mid + 1`.
   * **Else:** The minimum is in the left half (including mid), so move `right = mid`.

4. **Termination:**
   * When `left == right`, we've found the minimum element's index.
   * Return `left` as the rotation count.

5. **Why This Works:**
   * A sorted array has `arr[0] <= arr[n-1]`.
   * After rotation, there's a break point where `arr[i] > arr[i+1]`.
   * Binary search efficiently locates this break point.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(log n), where n is the size of the array. We use binary search which divides the search space in half with each iteration, resulting in logarithmic time complexity.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for storing pointers and the middle index regardless of the input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int l = 0, r = arr.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (arr[m] > arr[r]) l = m + 1;
            else r = m;
        }
        return l;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Binary Search with Early Termination**

### 💡 Algorithm Steps:

1. Check if array is already sorted by comparing first and last elements.
2. If sorted, return 0 as there is no rotation.
3. Use binary search to find the pivot point where rotation occurred.
4. Compare middle element with its neighbors to determine if it's the minimum.
5. Adjust search boundaries based on which half is sorted.

```cpp
class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int l = 0, r = arr.size() - 1;
        while (l <= r) {
            if (arr[l] <= arr[r]) return l;
            int m = l + (r - l) / 2;
            int next = (m + 1) % arr.size();
            int prev = (m - 1 + arr.size()) % arr.size();
            if (arr[m] <= arr[next] && arr[m] <= arr[prev]) return m;
            if (arr[m] <= arr[r]) r = m - 1;
            else l = m + 1;
        }
        return 0;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(log n) - Binary search with boundary checks
* **Auxiliary Space:** 💾 O(1) - Constant extra space

### ✅ **Why This Approach?**

* Early termination for non-rotated arrays saves computation.
* Explicit neighbor checking ensures correctness for edge cases.
* Handles circular indexing elegantly.

## 📊 **3️⃣ Linear Scan Approach**

### 💡 Algorithm Steps:

1. Traverse array from start to end sequentially.
2. Find the position where current element is greater than next element.
3. This position indicates the end of rotation; next index is the answer.
4. If no such position exists, array is not rotated, return 0.

```cpp
class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1]) return i + 1;
        return 0;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single traversal of array
* **Auxiliary Space:** 💾 O(1) - No additional space required

### ✅ **Why This Approach?**

* Extremely simple and straightforward logic.
* No complex binary search conditions.
* Perfect for small arrays or quick prototyping.

## 📊 **4️⃣ Minimum Value Tracking Approach**

### 💡 Algorithm Steps:

1. Initialize variables to track minimum value and its index.
2. Use binary search to efficiently locate the minimum element.
3. Compare and update minimum value whenever a smaller element is found.
4. Return the index of the minimum element as rotation count.

```cpp
class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int l = 0, r = arr.size() - 1, idx = 0, minVal = INT_MAX;
        while (l <= r) {
            if (arr[l] <= arr[r]) {
                if (arr[l] < minVal) {
                    minVal = arr[l];
                    idx = l;
                }
                break;
            }
            int m = l + (r - l) / 2;
            if (arr[l] <= arr[m]) {
                if (arr[l] < minVal) {
                    minVal = arr[l];
                    idx = l;
                }
                l = m + 1;
            } else {
                if (arr[m] < minVal) {
                    minVal = arr[m];
                    idx = m;
                }
                r = m - 1;
            }
        }
        return idx;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(log n) - Binary search with value tracking
* **Auxiliary Space:** 💾 O(1) - Only tracking variables used

### ✅ **Why This Approach?**

* Explicitly tracks minimum value for clarity.
* Robust against edge cases and variations.
* Good for understanding the underlying concept.

## 📊 **5️⃣ Recursive Binary Search**

### 💡 Algorithm Steps:

1. Use recursion to divide the problem into smaller subproblems.
2. Base case checks if current segment has only one element.
3. Recursively search in the unsorted half of the array.
4. Return the index where minimum element is located.

```cpp
class Solution {
public:
    int helper(vector<int> &arr, int l, int r) {
        if (l >= r) return l;
        int m = l + (r - l) / 2;
        if (arr[m] > arr[r]) return helper(arr, m + 1, r);
        return helper(arr, l, m);
    }
    int findKRotation(vector<int> &arr) {
        return helper(arr, 0, arr.size() - 1);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(log n) - Recursive binary search
* **Auxiliary Space:** 💾 O(log n) - Recursion call stack

### ✅ **Why This Approach?**

* Clean recursive implementation.
* Easier to understand for some programmers.
* Demonstrates divide and conquer paradigm.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Iterative Binary Search**    | 🟢 O(log n)            | 🟢 O(1)                 | 🚀 Optimal and clean              | 🔧 Requires understanding BS logic   |
| 🎯 **Early Termination**          | 🟢 O(log n)            | 🟢 O(1)                 | ⭐ Handles sorted arrays fast     | 📝 More code complexity              |
| 📊 **Linear Scan**                | 🟡 O(n)                | 🟢 O(1)                 | 📖 Simplest to understand         | 🐌 Slower for large arrays           |
| 🔍 **Minimum Tracking**           | 🟢 O(log n)            | 🟢 O(1)                 | 🎯 Explicit minimum tracking      | 🔧 More variables to manage          |
| 🔄 **Recursive**                  | 🟢 O(log n)            | 🟡 O(log n)             | 💡 Clean divide and conquer       | 💾 Extra stack space                 |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Iterative Binary Search**       | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **Linear Scan**                   | ★★★☆☆                     |
| 🔧 **Production code**                                | 🥉 **Early Termination**             | ★★★★★                     |
| 🎯 **Interview/Competitive**                          | 🏅 **Iterative Binary Search**       | ★★★★★                     |
| 📚 **Learning purposes**                              | 🎓 **Recursive**                     | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int findKRotation(int arr[]) {
        int l = 0, r = arr.length - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (arr[m] > arr[r]) l = m + 1;
            else r = m;
        }
        return l;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def findKRotation(self, arr):
        l, r = 0, len(arr) - 1
        while l < r:
            m = (l + r) // 2
            if arr[m] > arr[r]: l = m + 1
            else: r = m
        return l
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



