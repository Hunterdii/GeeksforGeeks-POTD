---
title: "🔮 Maximum Non-Overlapping Odd Palindrome Sum | GFG Solution 🎯"
keywords🏷️: ["🔮 palindrome", "🎯 string processing", "📈 dynamic programming", "🧮 manacher algorithm", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Maximum Non-Overlapping Odd Palindrome Sum problem: find maximum sum of lengths of two non-overlapping odd palindromes using Manacher's algorithm. 🚀"
date: 📅 2025-08-11
---

# *11. Maximum Non-Overlapping Odd Palindrome Sum*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximum-non-overlapping-odd-palindrome-sum/1)

## **🧩 Problem Description**

Given a string `s` consisting of lowercase English letters, find the maximum possible sum of the lengths of any two **non-empty** and **non-overlapping** palindromic substrings of **odd length**.

Formally, choose any two substrings `s[i...j]` and `s[k...l]` such that `1 ≤ i ≤ j < k ≤ l ≤ s.size()`, both substrings are palindromes of odd length, and they do not overlap. Return the maximum sum of their lengths.

**Note:** A palindrome is a string that reads the same forward and backward. A substring is a contiguous sequence of characters within the string.

## **📘 Examples**

### Example 1

```cpp
Input: s = "xyabacbcz"
Output: 6
Explanation: "aba" and "cbc" are non-overlapping odd-length palindromes. 
Their lengths are 3 and 3 which gives the sum as 6.
```

### Example 2

```cpp
Input: s = "gfgforgeeks"
Output: 4
Explanation: "gfg" and "g" are non-overlapping odd-length palindromes. 
Their lengths are 3 and 1 which gives the sum as 4.
```

## **🔒 Constraints**

* $2 \le s.size() \le 10^5$
* String consists of lowercase English letters only

## **✅ My Approach**

The optimal approach uses **Manacher's Algorithm** combined with **Dynamic Programming** to efficiently find all palindromes and determine the maximum sum:

### **Manacher's Algorithm + Dynamic Programming**

1. **Palindrome Detection:**
   * Use Manacher's algorithm to find all odd-length palindromes in linear time.
   * For each center position, compute the radius of the longest palindrome.

2. **Left Segment Processing:**
   * For each palindrome, mark its ending position with the palindrome length.
   * Propagate maximum lengths from right to left, ensuring we track the longest palindrome ending at or before each position.

3. **Right Segment Processing:**
   * For each palindrome, mark its starting position with the palindrome length.
   * Propagate maximum lengths from left to right, ensuring we track the longest palindrome starting at or after each position.

4. **Optimal Split Point:**
   * For each valid split position, combine the maximum palindrome from the left segment with the maximum palindrome from the right segment.
   * Return the maximum sum across all split points.

### **Key Insights:**
- Manacher's algorithm processes palindromes in O(n) time by avoiding redundant comparisons
- Dynamic programming ensures we maintain optimal palindrome lengths for each segment
- The algorithm handles edge cases by ensuring non-overlapping constraints

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the string. Manacher's algorithm runs in linear time, and the dynamic programming phases also process each position once.
* **Expected Auxiliary Space Complexity:** O(n), as we use three arrays (left, right, rad) of size n to store palindrome information and segment maximums.


## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxSum(string& s) {
        int n = s.size();
        vector<int> left(n, 1), right(n, 1), rad(n);
        
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(rad[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
            rad[i] = k--;
            if (i + k > r) l = i - k, r = i + k;
        }
        
        for (int i = 0; i < n; i++) {
            int len = rad[i] * 2 - 1;
            int end = i + rad[i] - 1;
            if (end < n) left[end] = max(left[end], len);
        }
        
        for (int i = n - 2; i >= 0; i--) left[i] = max(left[i], left[i + 1] - 2);
        for (int i = 1; i < n; i++) left[i] = max(left[i], left[i - 1]);
        
        for (int i = n - 1; i >= 0; i--) {
            int len = rad[i] * 2 - 1;
            int start = i - rad[i] + 1;
            if (start >= 0) right[start] = max(right[start], len);
        }
        
        for (int i = 1; i < n; i++) right[i] = max(right[i], right[i - 1] - 2);
        for (int i = n - 2; i >= 0; i--) right[i] = max(right[i], right[i + 1]);
        
        int ans = 1;
        for (int i = 0; i + 1 < n; i++) ans = max(ans, left[i] + right[i + 1]);
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Expand Around Centers Approach (Optimized Brute Force)**

### 💡 Algorithm Steps:

1. For each position, expand around center to find all odd palindromes.
2. Use dynamic programming to track maximum palindrome lengths for left and right segments.
3. Combine results from both segments to find optimal split point.
4. Optimize by maintaining running maximums instead of recomputing.

```cpp
class Solution {
public:
    int maxSum(string& s) {
        int n = s.size();
        vector<int> leftMax(n, 1), rightMax(n, 1);
        
        for (int c = 0; c < n; c++) {
            for (int r = 1; c - r >= 0 && c + r < n && s[c - r] == s[c + r]; r++) {
                int len = 2 * r + 1;
                leftMax[c + r] = max(leftMax[c + r], len);
                rightMax[c - r] = max(rightMax[c - r], len);
            }
        }
        
        for (int i = n - 2; i >= 0; i--) leftMax[i] = max(leftMax[i], leftMax[i + 1] - 2);
        for (int i = 1; i < n; i++) leftMax[i] = max(leftMax[i], leftMax[i - 1]);
        
        for (int i = 1; i < n; i++) rightMax[i] = max(rightMax[i], rightMax[i - 1] - 2);
        for (int i = n - 2; i >= 0; i--) rightMax[i] = max(rightMax[i], rightMax[i + 1]);
        
        int result = 1;
        for (int i = 0; i + 1 < n; i++) result = max(result, leftMax[i] + rightMax[i + 1]);
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Expansion around each center
* **Auxiliary Space:** 💾 O(n) - Two arrays for left and right tracking

### ✅ **Why This Approach?**

* Intuitive palindrome detection method
* No complex string preprocessing required
* Easy to debug and understand logic flow

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110 /1120 test cases due to time constraints).


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Manacher's Algorithm**        | 🟢 O(n)                | 🟢 O(n)                 | 🚀 Optimal linear time            | 🔧 Complex implementation            |
| 🔍 **Expand Around Centers (TLE)**       | 🟡 O(n²)               | 🟢 O(n)                 | 📖 Intuitive approach            | 🐌 Quadratic time complexity         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Large input sizes**                          | 🥇 **Manacher's Algorithm**          | ★★★★★                     |
| 📖 **Interview/Learning**                         | 🥈 **Expand Around Centers**         | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int maxSum(String s) {
        int n = s.length();
        int[] left = new int[n], right = new int[n], rad = new int[n];
        Arrays.fill(left, 1);
        Arrays.fill(right, 1);
        
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : Math.min(rad[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s.charAt(i - k) == s.charAt(i + k)) k++;
            rad[i] = k--;
            if (i + k > r) { l = i - k; r = i + k; }
        }
        
        for (int i = 0; i < n; i++) {
            int len = rad[i] * 2 - 1;
            int end = i + rad[i] - 1;
            if (end < n) left[end] = Math.max(left[end], len);
        }
        
        for (int i = n - 2; i >= 0; i--) left[i] = Math.max(left[i], left[i + 1] - 2);
        for (int i = 1; i < n; i++) left[i] = Math.max(left[i], left[i - 1]);
        
        for (int i = n - 1; i >= 0; i--) {
            int len = rad[i] * 2 - 1;
            int start = i - rad[i] + 1;
            if (start >= 0) right[start] = Math.max(right[start], len);
        }
        
        for (int i = 1; i < n; i++) right[i] = Math.max(right[i], right[i - 1] - 2);
        for (int i = n - 2; i >= 0; i--) right[i] = Math.max(right[i], right[i + 1]);
        
        int ans = 1;
        for (int i = 0; i + 1 < n; i++) ans = Math.max(ans, left[i] + right[i + 1]);
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxSum(self, s):
        n = len(s)
        left, right, rad = [1] * n, [1] * n, [0] * n
        l, r = 0, -1
        for i in range(n):
            k = 1 if i > r else min(rad[l + r - i], r - i + 1)
            while i - k >= 0 and i + k < n and s[i - k] == s[i + k]:
                k += 1
            rad[i] = k
            k -= 1
            if i + k > r:
                l, r = i - k, i + k

        for i in range(n):
            length = rad[i] * 2 - 1
            end = i + rad[i] - 1
            if end < n:
                left[end] = max(left[end], length)
        
        for i in range(n - 2, -1, -1):
            left[i] = max(left[i], left[i + 1] - 2)
        for i in range(1, n):
            left[i] = max(left[i], left[i - 1])
        
        for i in range(n - 1, -1, -1):
            length = rad[i] * 2 - 1
            start = i - rad[i] + 1
            if start >= 0:
                right[start] = max(right[start], length)
        
        for i in range(1, n):
            right[i] = max(right[i], right[i - 1] - 2)
        for i in range(n - 2, -1, -1):
            right[i] = max(right[i], right[i + 1])
        
        ans = 1
        for i in range(n - 1):
            ans = max(ans, left[i] + right[i + 1])
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













