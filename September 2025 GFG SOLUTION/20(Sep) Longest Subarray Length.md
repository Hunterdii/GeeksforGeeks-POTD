---
title: "🔢 Longest Subarray Length | GFG Solution 🔍"
keywords🏷️: ["🔢 longest subarray", "🔍 stack", "📍 monotonic stack", "📈 next greater element", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Longest Subarray Length problem: find maximum length subarray where all elements are ≤ subarray length using monotonic stack technique. 🚀"
date: 📅 2025-09-20
---

# *20. Longest Subarray Length*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/longest-subarray-length--202010/1)

## **🧩 Problem Description**

You are given an array of integers `arr[]`. Your task is to find the length of the **longest subarray** such that all the elements of the subarray are **smaller than or equal to the length of the subarray**.

A subarray is a contiguous sequence of elements within an array. The goal is to find the maximum possible length where every element in the subarray satisfies: `element ≤ subarray_length`.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 2, 3]
Output: 3
Explanation: The longest subarray is the entire array itself, which has a length of 3. 
All elements in the subarray are less than or equal to 3.
```

### Example 2

```cpp
Input: arr[] = [6, 4, 2, 5]
Output: 0
Explanation: There is no subarray where all elements are less than or equal to the length of the subarray. 
The longest subarray is empty, which has a length of 0.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^9$

## **✅ My Approach**

The optimal approach uses **Monotonic Stack** technique to efficiently find the boundaries where each element can be the maximum in a valid subarray:

### **Monotonic Stack Approach**

1. **Precompute Boundaries:**
   * For each index `i`, find the nearest smaller element on the left (`l[i]`) and right (`r[i]`).
   * Use monotonic stack to compute these boundaries in linear time.

2. **Calculate Subarray Length:**
   * For each element at index `i`, the maximum subarray where `arr[i]` is the largest element has length `r[i] - l[i] - 1`.

3. **Validate Condition:**
   * Check if the subarray length is greater than or equal to `arr[i]`.
   * If yes, this subarray satisfies our condition.

4. **Track Maximum:**
   * Keep track of the maximum valid subarray length found.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. Each element is pushed and popped from the stack at most once during the two passes.
* **Expected Auxiliary Space Complexity:** O(n), for storing the left and right boundary arrays and the stack space.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n = a.size(), res = 0;
        vector<int> l(n, -1), r(n, n);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && a[s.top()] <= a[i]) s.pop();
            if (!s.empty()) r[i] = s.top();
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[s.top()] <= a[i]) s.pop();
            if (!s.empty()) l[i] = s.top();
            s.push(i);
            int len = r[i] - l[i] - 1;
            if (len >= a[i]) res = max(res, len);
        }
        return res;
    }
};
```


## **☕ Code (Java)**

```java
class Solution {
    public static int longestSubarray(int[] a) {
        int n = a.length, res = 0;
        int[] l = new int[n], r = new int[n];
        Arrays.fill(l, -1);
        Arrays.fill(r, n);
        Stack<Integer> s = new Stack<>();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && a[s.peek()] <= a[i]) s.pop();
            if (!s.empty()) r[i] = s.peek();
            s.push(i);
        }
        s.clear();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[s.peek()] <= a[i]) s.pop();
            if (!s.empty()) l[i] = s.peek();
            s.push(i);
            int len = r[i] - l[i] - 1;
            if (len >= a[i]) res = Math.max(res, len);
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def longestSubarray(self, a):
        n, res = len(a), 0
        l, r, s = [-1] * n, [n] * n, []
        for i in range(n - 1, -1, -1):
            while s and a[s[-1]] <= a[i]: s.pop()
            if s: r[i] = s[-1]
            s.append(i)
        s.clear()
        for i in range(n):
            while s and a[s[-1]] <= a[i]: s.pop()
            if s: l[i] = s[-1]
            s.append(i)
            length = r[i] - l[i] - 1
            if length >= a[i]: res = max(res, length)
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























