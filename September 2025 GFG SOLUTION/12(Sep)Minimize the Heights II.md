---
title: "🔢 Minimize the Heights II | GFG Solution 🔍"
keywords🏷️: ["🔢 minimize heights", "🔍 greedy algorithm", "📍 sorting", "📈 optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Minimize the Heights II problem: find minimum difference between tallest and shortest towers after mandatory height modifications using greedy approach. 🚀"
date: 📅 2025-09-12
---

# *12. Minimize the Heights II*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1)

## **🧩 Problem Description**

Given an array `arr[]` denoting heights of `n` towers and a positive integer `k`, you must perform exactly one of the following operations on each tower:

1. **Increase** the height of the tower by `k`
2. **Decrease** the height of the tower by `k`

Your task is to find the **minimum possible difference** between the height of the shortest and tallest towers after modification.

**Important:** After operations, the resultant array should not contain any negative integers.

## **📘 Examples**

### Example 1

```cpp
Input: k = 2, arr[] = [1, 5, 8, 10]
Output: 5
Explanation: The array can be modified as [1+k, 5-k, 8-k, 10-k] = [3, 3, 6, 8].
The difference between the largest and smallest is 8-3 = 5.
```

### Example 2

```cpp
Input: k = 3, arr[] = [3, 9, 12, 16, 20]
Output: 11
Explanation: The array can be modified as [3+k, 9+k, 12-k, 16-k, 20-k] = [6, 12, 9, 13, 17].
The difference between the largest and smallest is 17-6 = 11.
```

## **🔒 Constraints**

* $1 \le k \le 10^7$
* $1 \le n \le 10^5$
* $1 \le arr[i] \le 10^7$

## **✅ My Approach**

The optimal approach uses a **Greedy Algorithm** combined with **Sorting** to systematically evaluate all possible configurations:

### **Greedy Split-Point Strategy**

1. **Sort the Array:**
   * Sort towers by height to enable greedy decision making.
   * This allows us to analyze potential split points systematically.

2. **Initial Configuration:**
   * Calculate the difference with all towers increased by `k`: `arr[n-1] - arr[0]`.
   * This serves as our baseline answer.

3. **Evaluate Split Points:**
   * For each position `i` from 1 to n-1, consider splitting operations:
     * Towers `[0...i-1]`: Add `k` to their heights
     * Towers `[i...n-1]`: Subtract `k` from their heights
   * Skip configurations where `arr[i] - k < 0` (negative height constraint).

4. **Calculate Optimal Range:**
   * For each valid split:
     * **Minimum height:** `min(arr[0] + k, arr[i] - k)`
     * **Maximum height:** `max(arr[n-1] - k, arr[i-1] + k)`
   * Update answer with minimum difference found.

5. **Mathematical Insight:**
   * The optimal solution lies at one of the split points where we transition from adding `k` to subtracting `k`.
   * By testing all valid splits, we guarantee the optimal result.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the size of the array. The sorting operation dominates with O(n log n), followed by a linear scan of O(n).
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables and perform in-place sorting.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int getMinDiff(vector<int>& a, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        int ans = a[n-1] - a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] >= k) {
                int mn = min(a[0] + k, a[i] - k);
                int mx = max(a[n-1] - k, a[i-1] + k);
                ans = min(ans, mx - mn);
            }
        }
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Greedy Split Point**

### 💡 Algorithm Steps:

1. Sort array to enable greedy decision making
2. For each potential split point, calculate optimal heights
3. Choose operations that minimize global range
4. Track best result across all valid configurations

```cpp
class Solution {
public:
    int getMinDiff(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size(), diff = a[n-1] - a[0];
        for (int i = 0; i < n-1; i++) {
            if (a[i+1] - k < 0) continue;
            int maxVal = max(a[i] + k, a[n-1] - k);
            int minVal = min(a[0] + k, a[i+1] - k);
            diff = min(diff, maxVal - minVal);
        }
        return diff;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting with linear scan
* **Auxiliary Space:** 💾 O(1) - In-place processing

### ✅ **Why This Approach?**

* Intuitive greedy strategy
* Clear split-point logic
* Optimal for understanding problem structure

## 📊 **3️⃣ Range Compression**

### 💡 Algorithm Steps:

1. Pre-sort array for range analysis
2. Calculate compressed ranges after operations
3. Find optimal partition that minimizes max range
4. Use mathematical properties to avoid redundant calculations

```cpp
class Solution {
public:
    int getMinDiff(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size(), ans = a[n-1] - a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] < k) continue;
            ans = min(ans, max(a[i-1] + k, a[n-1] - k) - min(a[0] + k, a[i] - k));
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Standard sorting approach
* **Auxiliary Space:** 💾 O(1) - Minimal space usage

### ✅ **Why This Approach?**

* Mathematical optimization focus
* Compressed logic for better readability
* Eliminates unnecessary condition checks

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Standard Greedy**            | 🟢 O(n log n)          | 🟢 O(1)                 | 🚀 Simple and reliable            | 🔧 Basic optimization only           |
| 📊 **Greedy Split**               | 🟢 O(n log n)          | 🟢 O(1)                 | 🎯 Clear problem decomposition    | 🐌 May have redundant checks         |
| 🔄 **Range Compression**          | 🟢 O(n log n)          | 🟢 O(1)                 | ⭐ Mathematically optimized       | 🔧 Less intuitive for beginners     |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Interview/Contest**                          | 🥇 **Standard Greedy**               | ★★★★★                     |
| 🔧 **Production code**                            | 🥈 **Range Compression**             | ★★★★☆                     |
| 🎯 **Teaching/Explanation**                       | 🥉 **Greedy Split**                  | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int getMinDiff(int[] a, int k) {
        Arrays.sort(a);
        int n = a.length, ans = a[n-1] - a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] >= k) {
                int mn = Math.min(a[0] + k, a[i] - k);
                int mx = Math.max(a[n-1] - k, a[i-1] + k);
                ans = Math.min(ans, mx - mn);
            }
        }
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def getMinDiff(self, a, k):
        a.sort()
        n = len(a)
        ans = a[n-1] - a[0]
        for i in range(1, n):
            if a[i] >= k:
                mn = min(a[0] + k, a[i] - k)
                mx = max(a[n-1] - k, a[i-1] + k)
                ans = min(ans, mx - mn)
        return ans
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
