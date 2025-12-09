---
title: "🔗 Longest Common Increasing Subsequence | GFG Solution 🎯"
keywords🏷️: ["🔗 LCIS", "📊 dynamic programming", "🔄 subsequence", "📈 optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Longest Common Increasing Subsequence problem: find the length of the longest subsequence that is common to both arrays and strictly increasing using dynamic programming. 🚀"
date: 📅 2025-11-16
---

# *16. Longest Common Increasing Subsequence*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/longest-common-increasing-subsequence1437/1)

## **🧩 Problem Description**

Given two arrays, `a[]` and `b[]`, find the length of the **Longest Common Increasing Subsequence (LCIS)**. 

An LCIS refers to a subsequence that is present in both arrays and strictly increases. A subsequence is derived by selecting elements from the array in the same order (not necessarily contiguous).

## **📘 Examples**

### Example 1

```cpp
Input: a[] = [3, 4, 9, 1], b[] = [5, 3, 8, 9, 10, 2, 1]
Output: 2
Explanation: The longest increasing subsequence that is common is [3, 9] and its length is 2.
```

### Example 2

```cpp
Input: a[] = [1, 1, 4, 3], b[] = [1, 1, 3, 4]
Output: 2
Explanation: There are two common subsequences [1, 4] and [1, 3] both of length 2.
```

## **🔒 Constraints**

* $1 \le \text{a.size()}, \text{b.size()} \le 10^3$
* $1 \le \text{a}[i], \text{b}[i] \le 10^4$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming** with space optimization to efficiently compute the LCIS:

### **Optimized Dynamic Programming**

1. **Initialize DP Array:**
   * Create a `dp[]` array of size `n` (length of array `b`) initialized to 0.
   * `dp[j]` represents the length of the longest common increasing subsequence ending with element `b[j]`.

2. **Iterate Through Array `a`:**
   * For each element `a[i]`, maintain a variable `cur` to track the maximum length of LCIS ending before current position.
   * This `cur` variable stores the best LCIS length we can extend if we find a matching element.

3. **Inner Loop Through Array `b`:**
   * **Case 1 - Match Found (`a[i] == b[j]`):** 
     * Update `dp[j] = max(dp[j], cur + 1)` because we can extend the previous LCIS by including this common element.
   * **Case 2 - Potential Extension (`b[j] < a[i]`):** 
     * Update `cur = max(cur, dp[j])` to track the best LCIS length that can be extended in future matches.
   * Track the maximum value in `dp[]` as the result.

4. **Key Insight:**
   * For each element in `a`, we scan through `b` and:
     - When elements match, we can form a longer LCIS
     - When `b[j] < a[i]`, we update our "best so far" for potential extensions
   * This ensures we maintain the increasing property while finding common elements.

5. **Return Result:**
   * The maximum value encountered in the DP array represents the length of LCIS.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(m × n), where m is the size of array `a` and n is the size of array `b`. We iterate through each element of `a` and for each element, scan through array `b` once.
* **Expected Auxiliary Space Complexity:** O(n), as we use a single DP array of size n to store the lengths of LCIS ending at each position in array `b`.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int LCIS(vector<int> &a, vector<int> &b) {
        int m = a.size(), n = b.size(), res = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < m; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                if (a[i] == b[j]) {
                    dp[j] = max(dp[j], cur + 1);
                }
                if (b[j] < a[i]) {
                    cur = max(cur, dp[j]);
                }
                res = max(res, dp[j]);
            }
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Memoized Recursion**

### 💡 Algorithm Steps:

1. Recursively explore all possible common increasing subsequences.
2. Use memoization to cache computed states.
3. Track last element to ensure increasing property.
4. Return maximum length found across all paths.

```cpp
class Solution {
public:
    int solve(vector<int> &a, vector<int> &b, int i, int j, int last,
              map<tuple<int,int,int>,int> &memo) {
        if (i == a.size() || j == b.size()) return 0;
        auto key = make_tuple(i, j, last);
        if (memo.count(key)) return memo[key];
        int res = max(
            solve(a, b, i + 1, j, last, memo),
            solve(a, b, i, j + 1, last, memo)
        );
        
        if (a[i] == b[j] && a[i] > last) {
            res = max(res, 1 + solve(a, b, i + 1, j + 1, a[i], memo));
        }
        return memo[key] = res;
    }
    int LCIS(vector<int> &a, vector<int> &b) {
        map<tuple<int,int,int>,int> memo;
        return solve(a, b, 0, 0, INT_MIN, memo);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m × n × k) - Where k is range of values
* **Auxiliary Space:** 💾 O(m × n × k) - Memoization storage

### ✅ **Why This Approach?**

* Clear recursive structure
* Easy to understand the state transitions
* Good for explaining the problem logic

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1010/1070 test cases due to time constraints).

## 📊 **3️⃣ Space Optimized DP with Single Variable**

### 💡 Algorithm Steps:

1. Optimize space by reusing single tracking variable.
2. Update DP states in forward pass only.
3. Eliminate need for separate current length tracking.
4. Compute result on-the-fly during iteration.

```cpp
class Solution {
public:
    int LCIS(vector<int> &a, vector<int> &b) {
        int n = b.size(), result = 0;
        vector<int> dp(n, 0);
        for (int x : a) {
            int maxLen = 0;
            for (int j = 0; j < n; j++) {
                if (x == b[j]) {
                    dp[j] = maxLen + 1;
                } else if (b[j] < x) {
                    maxLen = max(maxLen, dp[j]);
                }
                result = max(result, dp[j]);
            }
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m × n) - Linear scan through both arrays
* **Auxiliary Space:** 💾 O(n) - Single DP array

### ✅ **Why This Approach?**

* Most space efficient DP solution
* Clean iteration with range-based loop
* On-the-fly result computation

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach** | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros** | ⚠️ **Cons** |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Optimized DP** | 🟢 O(m × n) | 🟢 O(n) | 🚀 Optimal time & space | 🔧 Requires careful state management |
| 📊 **Memoized Recursion** | 🟡 O(m × n × k) | 🟡 O(m × n × k) | 🎯 Intuitive logic | 🐌 Higher space overhead, TLE risk |
| 🔄 **Space Optimized** | 🟢 O(m × n) | 🟢 O(n) | ⭐ Cleanest code | 🔧 Less explicit tracking |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario** | 🎖️ **Recommended Approach** | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed** | 🥇 **Optimized DP** | ★★★★★ |
| 📖 **Readability priority** | 🥈 **Space Optimized** | ★★★★★ |
| 🔧 **Learning/Understanding** | 🥉 **Memoized Recursion** | ★★★☆☆ |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int LCIS(int[] a, int[] b) {
        int m = a.length, n = b.length, res = 0;
        int[] dp = new int[n];
        for (int i = 0; i < m; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                if (a[i] == b[j]) {
                    dp[j] = Math.max(dp[j], cur + 1);
                }
                if (b[j] < a[i]) {
                    cur = Math.max(cur, dp[j]);
                }
                res = Math.max(res, dp[j]);
            }
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def LCIS(self, a, b):
        m, n = len(a), len(b)
        dp = [0] * n
        res = 0
        for i in range(m):
            cur = 0
            for j in range(n):
                if a[i] == b[j]:
                    dp[j] = max(dp[j], cur + 1)
                if b[j] < a[i]:
                    cur = max(cur, dp[j])
                res = max(res, dp[j])
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
