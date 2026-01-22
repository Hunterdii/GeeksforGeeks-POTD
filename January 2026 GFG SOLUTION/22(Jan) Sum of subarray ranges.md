---
title: "🔢 Sum of Subarray Ranges | GFG Solution 🔍"
keywords🏷️: ["🔢 subarray ranges", "📚 monotonic stack", "🎯 contribution technique", "📈 stack optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Sum of Subarray Ranges problem: calculate sum of ranges across all subarrays using monotonic stack technique for optimal O(n) performance. 🚀"
date: 📅 2025-01-22
---

# *22. Sum of Subarray Ranges*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/sum-of-subarray-ranges/1)

## **🧩 Problem Description**

Given an integer array `arr[]`, the **range** of a subarray is defined as the difference between the largest and smallest elements within that subarray. Your task is to return the **sum of the ranges** of all possible subarrays in the array.

A subarray is a contiguous sequence of elements within an array. The goal is to efficiently compute this sum for potentially large arrays.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 2, 3]
Output: 4
Explanation: The 6 subarrays of arr are:
[1], range = 1 - 1 = 0
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1, 2], range = 2 - 1 = 1
[2, 3], range = 3 - 2 = 1
[1, 2, 3], range = 3 - 1 = 2
Sum of all ranges = 0 + 0 + 0 + 1 + 1 + 2 = 4
```

### Example 2

```cpp
Input: arr[] = [-32, 0, -2, 72]
Output: 318
Explanation: 
[-32], range = 0
[-32, 0], range = 32
[-32, 0, -2], range = 32
[-32, 0, -2, 72], range = 104
[0], range = 0
[0, -2], range = 2
[0, -2, 72], range = 74
[-2], range = 0
[-2, 72], range = 74
[72], range = 0
Sum of all ranges = 318
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^6$
* $-10^9 \le \text{arr}[i] \le 10^9$

## **✅ My Approach**

The optimal approach uses the **Monotonic Stack with Contribution Technique** to efficiently calculate the sum:

### **Monotonic Stack Contribution Method**

1. **Core Insight:**
   * Range of a subarray = Maximum element - Minimum element
   * Sum of all ranges = (Sum of all maximums) - (Sum of all minimums)
   * Calculate contribution of each element as maximum and minimum separately

2. **Calculate Minimum Contributions:**
   * Use monotonic increasing stack to find previous and next smaller elements
   * For each element at index j, find how many subarrays have it as minimum
   * Left count = distance to previous smaller element
   * Right count = distance to next smaller element
   * Contribution = arr[j] × left_count × right_count

3. **Calculate Maximum Contributions:**
   * Use monotonic decreasing stack to find previous and next greater elements
   * For each element at index j, find how many subarrays have it as maximum
   * Apply same counting logic as minimum contributions
   * Contribution = arr[j] × left_count × right_count

4. **Final Result:**
   * Subtract total minimum contributions from total maximum contributions
   * This gives the sum of ranges across all subarrays

5. **Stack Processing:**
   * Process elements with dummy element at end (index n) to flush remaining stack
   * Track indices in stack for distance calculations
   * Use previous element index from stack or -1 if stack is empty

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. Each element is pushed and popped from the stack at most once in each of the two passes (one for minimums, one for maximums), resulting in linear time complexity.
* **Expected Auxiliary Space Complexity:** O(n), as we use a stack to store indices during processing. In the worst case, all elements might be stored in the stack before any are popped.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    long long subarrayRanges(vector<int>& a) {
        int n = a.size();
        long long res = 0;
        stack<int> s;
        for (int i = 0; i <= n; i++) {
            while (!s.empty() && (i == n || a[s.top()] > a[i])) {
                int j = s.top(); s.pop();
                int k = s.empty() ? -1 : s.top();
                res -= (long long)a[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = 0; i <= n; i++) {
            while (!s.empty() && (i == n || a[s.top()] < a[i])) {
                int j = s.top(); s.pop();
                int k = s.empty() ? -1 : s.top();
                res += (long long)a[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Four Arrays Contribution Method**

### 💡 Algorithm Steps:

1. Compute left and right boundaries for each element as minimum.
2. Compute left and right boundaries for each element as maximum.
3. Calculate contribution of each element in both roles separately.
4. Return difference between total maximum and minimum contributions.

```cpp
class Solution {
public:
    long long subarrayRanges(vector<int>& a) {
        int n = a.size();
        vector<int> lMin(n), rMin(n), lMax(n), rMax(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[s.top()] >= a[i]) s.pop();
            lMin[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && a[s.top()] > a[i]) s.pop();
            rMin[i] = s.empty() ? n - i : s.top() - i;
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[s.top()] <= a[i]) s.pop();
            lMax[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && a[s.top()] < a[i]) s.pop();
            rMax[i] = s.empty() ? n - i : s.top() - i;
            s.push(i);
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += (long long)a[i] * lMax[i] * rMax[i];
            res -= (long long)a[i] * lMin[i] * rMin[i];
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Four linear passes with stack
* **Auxiliary Space:** 💾 O(n) - Four arrays and stack storage

### ✅ **Why This Approach?**

* Clear separation of min and max calculations
* Easy to understand boundary computation
* Similar to reference code structure

## 📊 **3️⃣ Separate Sum Calculation with Lambda**

### 💡 Algorithm Steps:

1. Create reusable lambda function for sum calculation.
2. Calculate sum of all subarray maximums using monotonic stack.
3. Calculate sum of all subarray minimums using monotonic stack.
4. Return difference between maximum sum and minimum sum.

```cpp
class Solution {
public:
    long long subarrayRanges(vector<int>& a) {
        int n = a.size();
        auto calc = [&](bool isMax) {
            long long res = 0;
            stack<int> s;
            for (int i = 0; i <= n; i++) {
                while (!s.empty() && (i == n || (isMax ? a[s.top()] < a[i] : a[s.top()] > a[i]))) {
                    int j = s.top(); s.pop();
                    int k = s.empty() ? -1 : s.top();
                    res += (long long)a[j] * (i - j) * (j - k);
                }
                s.push(i);
            }
            return res;
        };
        return calc(true) - calc(false);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Two linear passes with stack operations
* **Auxiliary Space:** 💾 O(n) - Stack storage for processing

### ✅ **Why This Approach?**

* Most compact and modular code
* Reusable logic reduces code duplication
* Clean functional programming style

## 📊 **4️⃣ Direct Contribution Without Extra Arrays**

### 💡 Algorithm Steps:

1. Process array once to find minimum contributions directly.
2. Process array again to find maximum contributions directly.
3. Use stack to track previous smaller and greater elements on the fly.
4. Accumulate contributions without storing intermediate arrays.

```cpp
class Solution {
public:
    long long subarrayRanges(vector<int>& a) {
        int n = a.size();
        long long res = 0;
        stack<int> s;
        vector<long long> dp(n);
        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[s.top()] >= a[i]) s.pop();
            int l = s.empty() ? -1 : s.top();
            dp[i] = (i - l) * (long long)a[i];
            if (!s.empty()) dp[i] += dp[l];
            s.push(i);
        }
        for (int i = 0; i < n; i++) res -= dp[i];
        while (!s.empty()) s.pop();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[s.top()] <= a[i]) s.pop();
            int l = s.empty() ? -1 : s.top();
            dp[i] = (i - l) * (long long)a[i];
            if (!s.empty()) dp[i] += dp[l];
            s.push(i);
        }
        for (int i = 0; i < n; i++) res += dp[i];
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Two passes through array
* **Auxiliary Space:** 💾 O(n) - Single DP array and stack

### ✅ **Why This Approach?**

* Dynamic programming approach
* Space efficient with single working array
* Cumulative contribution tracking

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 📚 **Two-Pass Stack**             | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Most efficient                 | 🧩 Complex stack logic                |
| 🔢 **Four Arrays Method**         | 🟢 O(n)                | 🟡 O(n)                 | 📖 Clear structure                | 💾 More space usage                   |
| 🎯 **Lambda Function**            | 🟢 O(n)                | 🟡 O(n)                 | ⭐ Clean and modular              | 🔧 Functional style                   |
| 💡 **DP Contribution**            | 🟢 O(n)                | 🟡 O(n)                 | 🎓 DP approach                    | 🧩 Requires DP understanding          |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Competitive programming**                        | 🥇 **Two-Pass Stack**                | ★★★★★                     |
| 📖 **Interview/Learning**                             | 🥈 **Four Arrays Method**            | ★★★★☆                     |
| 🔧 **Production code**                                | 🥉 **Lambda Function**               | ★★★★★                     |
| 🎯 **DP practice**                                    | 🏅 **DP Contribution**               | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int subarrayRanges(int[] a) {
        int n = a.length;
        long res = 0;
        Stack<Integer> s = new Stack<>();
        for (int i = 0; i <= n; i++) {
            while (!s.isEmpty() && (i == n || a[s.peek()] > a[i])) {
                int j = s.pop();
                int k = s.isEmpty() ? -1 : s.peek();
                res -= (long)a[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        s.clear();
        for (int i = 0; i <= n; i++) {
            while (!s.isEmpty() && (i == n || a[s.peek()] < a[i])) {
                int j = s.pop();
                int k = s.isEmpty() ? -1 : s.peek();
                res += (long)a[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        return (int)res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def subarrayRanges(self, a):
        n = len(a)
        res = 0
        s = []
        for i in range(n + 1):
            while s and (i == n or a[s[-1]] > a[i]):
                j = s.pop()
                k = s[-1] if s else -1
                res -= a[j] * (i - j) * (j - k)
            s.append(i)
        s.clear()
        for i in range(n + 1):
            while s and (i == n or a[s[-1]] < a[i]):
                j = s.pop()
                k = s[-1] if s else -1
                res += a[j] * (i - j) * (j - k)
            s.append(i)
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
