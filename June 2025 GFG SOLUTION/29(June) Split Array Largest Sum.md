---
title: "📏 Split Array Largest Sum | GFG Solution 🔍"
keywords🏷️: ["📏 split array", "🔍 binary search", "📈 greedy algorithm", "📊 divide conquer", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Split Array Largest Sum problem: divide array into k subarrays minimizing maximum sum using binary search and greedy approach. 🚀"
date: 📅 2025-06-29
---

# *29. Split Array Largest Sum*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1)

## **🧩 Problem Description**

Given an array `arr[]` and an integer `k`, divide the array into **k contiguous subarrays** such that the **maximum sum among these subarrays is minimized**. Find this minimum possible maximum sum.

The goal is to split the array optimally to minimize the largest subarray sum across all possible k-way splits.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 2, 3, 4], k = 3
Output: 4
Explanation: Optimal Split is [1, 2], [3], [4]. 
Maximum sum of all subarrays is 4, which is minimum possible for 3 splits.
```

### Example 2

```cpp
Input: arr[] = [1, 1, 2], k = 2
Output: 2
Explanation: Splitting the array as [1, 1] and [2] is optimal. 
This results in a maximum sum subarray of 2.
```

## **🔒 Constraints**

* $1 \le k \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^4$

## **✅ My Approach**

The optimal approach uses **Binary Search on Answer** combined with a **Greedy Validation** function:

### **Binary Search + Greedy Validation**

1. **Define Search Space:**
   * **Lower bound**: Maximum element in array (minimum possible answer)
   * **Upper bound**: Sum of all elements (maximum possible answer when k=1)

2. **Binary Search on Answer:**
   * For each candidate maximum sum `mid`, check if it's possible to split array into ≤ k subarrays
   * If possible, try for a smaller maximum sum (move right boundary left)
   * If not possible, increase the maximum sum (move left boundary right)

3. **Greedy Validation:**
   * Try to fit elements into current subarray while sum ≤ `mid`
   * When adding next element would exceed `mid`, start a new subarray
   * Count total subarrays needed and check if ≤ k

4. **Monotonic Property:**
   * If we can split with maximum sum X, we can also split with any sum > X
   * This monotonic property enables binary search

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n * log(sum)), where n is the array size and sum is the total sum of array elements. Binary search runs in O(log(sum)) iterations, and each validation takes O(n) time.
* **Expected Auxiliary Space Complexity:** O(1), as we only use constant extra space for variables and pointers, without any additional data structures.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int splitArray(vector<int>& a, int k) {
        int l = *max_element(a.begin(), a.end()), r = accumulate(a.begin(), a.end(), 0);
        while (l < r) {
            int m = (l + r) / 2, s = 0, c = 1;
            for (int x : a) {
                if (s + x > m) c++, s = 0;
                s += x;
            }
            if (c <= k) r = m;
            else l = m + 1;
        }
        return l;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Optimized Binary Search with Early Termination**

### 💡 Algorithm Steps:

1. Use binary search on the answer range [max_element, sum_of_array]
2. For each candidate answer, check if it's possible to split array into ≤ k subarrays
3. Optimize bounds checking and use integer overflow prevention

```cpp
class Solution {
public:
    bool canSplit(vector<int>& arr, int k, int maxSum) {
        int subarrays = 1, currentSum = 0;
        for (int num : arr) {
            if (num > maxSum) return false;
            if (currentSum + num <= maxSum) {
                currentSum += num;
            } else {
                subarrays++;
                currentSum = num;
                if (subarrays > k) return false;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& arr, int k) {
        int left = *max_element(arr.begin(), arr.end());
        int right = accumulate(arr.begin(), arr.end(), 0);
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canSplit(arr, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n * log(sum - max))
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Prevents integer overflow with careful mid calculation
* Early termination in canSplit function
* Cleaner binary search template

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Binary Search + Greedy**     | 🟢 O(n * log(sum))     | 🟢 O(1)                 | ⚡ Fast, space efficient          | 🧮 Requires understanding of monotonicity |
| 🔄 **Optimized Split Check**      | 🟢 O(n * log(sum))     | 🟢 O(1)                 | 🔧 Cleaner code, overflow safe    | 🧮 Still requires binary search knowledge |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**    | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------- | ------------------------- |
| ⚡ Competitive programming, large inputs           | 🥇 **Binary Search + Greedy**  | ★★★★★                     |
| 🔧 Production code, readability important         | 🥈 **Optimized Split Check**   | ★★★★★                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int splitArray(int[] a, int k) {
        int l = 0, r = 0;
        for (int x : a) {
            l = Math.max(l, x);
            r += x;
        }
        while (l < r) {
            int m = (l + r) / 2, s = 0, c = 1;
            for (int x : a) {
                if (s + x > m) {
                    c++;
                    s = 0;
                }
                s += x;
            }
            if (c <= k) r = m;
            else l = m + 1;
        }
        return l;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def splitArray(self, a, k):
        l, r = max(a), sum(a)
        while l < r:
            m, s, c = (l + r) // 2, 0, 1
            for x in a:
                if s + x > m:
                    c += 1
                    s = 0
                s += x
            if c <= k: r = m
            else: l = m + 1
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
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
