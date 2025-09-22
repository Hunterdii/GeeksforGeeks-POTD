---
title: "📏 Max of Min for Every Window Size | GFG Solution 📊"
keywords🏷️: ["📏 window size", "📊 stack optimization", "📈 monotonic stack", "🔍 sliding window", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Max of Min for Every Window Size problem: find maximum of minimum values for all possible window sizes using monotonic stack technique. 🚀"
date: 📅 2025-09-22
---

# *22. Max of Min for Every Window Size*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1)

## **🧩 Problem Description**

You are given an integer array `arr[]`. The task is to find the **maximum of minimum values** for every window size `k` where `1 ≤ k ≤ arr.size()`.

For each window size `k`, consider all contiguous subarrays of length `k`, determine the minimum element in each subarray, and then take the maximum among all these minimums.

Return the results as an array, where the element at index `i` represents the answer for window size `i+1`.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [10, 20, 30, 50, 10, 70, 30]
Output: [70, 30, 20, 10, 10, 10, 10]
Explanation: 
Window size 1: minimums are [10, 20, 30, 50, 10, 70, 30], maximum of minimums is 70.
Window size 2: minimums are [10, 20, 30, 10, 10, 30], maximum of minimums is 30.
Window size 3: minimums are [10, 20, 10, 10, 10], maximum of minimums is 20.
Window size 4-7: minimums are [10, 10, 10, 10], maximum of minimums is 10.
```

### Example 2

```cpp
Input: arr[] = [10, 20, 30]
Output: [30, 20, 10]
Explanation: 
Window size 1: minimums of [10], [20], [30], maximum of minimums is 30.
Window size 2: minimums of [10, 20], [20, 30], maximum of minimums is 20.
Window size 3: minimums of [10, 20, 30], maximum of minimums is 10.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^6$

## **✅ My Approach**

The optimal approach uses **Monotonic Stack** to efficiently find the span of each element as a minimum in subarrays:

### **Single Pass Stack Algorithm**

1. **Key Insight:**
   * For each element `arr[i]`, find the maximum window size where it can be the minimum element.
   * This happens in the range from its previous smaller element to its next smaller element.

2. **Stack Processing:**
   * Use a monotonic stack to process elements in a single pass.
   * When we encounter a smaller element, it means the current element's span as minimum has ended.
   * Calculate the window size where the popped element was minimum.

3. **Window Size Calculation:**
   * For element at index `mid`, if previous smaller is at `prev` and next smaller is at `next`:
   * Window size = `next - prev - 1`
   * Update the maximum value for this window size with `arr[mid]`.

4. **Fill Missing Windows:**
   * Some window sizes might not have any elements as minimums.
   * Fill these gaps by propagating values from larger windows to smaller windows.
   * If window size `i` has no answer, it inherits from window size `i+1`.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. Each element is pushed and popped from the stack exactly once, making it a linear time solution.
* **Expected Auxiliary Space Complexity:** O(n), where n is the size of the array. We use additional space for the stack and auxiliary arrays to store results and maximum values for each window size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> maxOfMins(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n), mx(n + 1);
        stack<int> st;
        
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || a[st.top()] >= a[i])) {
                int mid = st.top(); st.pop();
                int w = i - (st.empty() ? -1 : st.top()) - 1;
                mx[w] = max(mx[w], a[mid]);
            }
            st.push(i);
        }
        
        for (int i = 1; i <= n; i++) ans[i-1] = mx[i];
        for (int i = n-2; i >= 0; i--) ans[i] = max(ans[i], ans[i+1]);
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Two-Pass Stack Approach**

### 💡 Algorithm Steps:

1. Use two passes to find previous and next smaller elements for each position.
2. Calculate window size where each element is minimum using these boundaries.
3. Store maximum element for each possible window size.
4. Fill gaps by propagating values from larger to smaller windows.

```cpp
class Solution {
public:
    vector<int> maxOfMins(vector<int>& a) {
        int n = a.size();
        vector<int> prev(n, -1), next(n, n), res(n), len(n+1);
        stack<int> s;
        
        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[s.top()] >= a[i]) s.pop();
            prev[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        
        while (!s.empty()) s.pop();
        
        for (int i = n-1; i >= 0; i--) {
            while (!s.empty() && a[s.top()] >= a[i]) s.pop();
            next[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        
        for (int i = 0; i < n; i++) {
            int w = next[i] - prev[i] - 1;
            len[w] = max(len[w], a[i]);
        }
        
        for (int i = 1; i <= n; i++) res[i-1] = len[i];
        for (int i = n-2; i >= 0; i--) res[i] = max(res[i], res[i+1]);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Three linear passes through the array
* **Auxiliary Space:** 💾 O(n) - Extra arrays for prev/next smaller elements

### ✅ **Why This Approach?**

* Clear separation of concerns with distinct phases
* Easier to debug and understand step by step
* Good for educational purposes and interviews

## 📊 **3️⃣ Brute Force Approach (For Reference)**

### 💡 Algorithm Steps:

1. For each window size `k` from 1 to n:
   * Consider all subarrays of length `k`
   * Find minimum in each subarray
   * Track maximum of all minimums
2. This approach helps understand the problem but is not optimal.

```cpp
class Solution {
public:
    vector<int> maxOfMins(vector<int>& a) {
        int n = a.size();
        vector<int> result(n);
        
        for (int k = 1; k <= n; k++) {
            int maxOfMin = 0;
            for (int i = 0; i <= n - k; i++) {
                int minVal = INT_MAX;
                for (int j = i; j < i + k; j++) {
                    minVal = min(minVal, a[j]);
                }
                maxOfMin = max(maxOfMin, minVal);
            }
            result[k-1] = maxOfMin;
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n³) - Triple nested loops
* **Auxiliary Space:** 💾 O(1) - Only result array

### ⚠️ **Why Not This Approach?**

* Extremely inefficient for large inputs
* Will cause Time Limit Exceeded (TLE)
* Only useful for understanding the problem

> **Note:** This approach results in **Time Limit Exceeded (TLE)** for large inputs _(fails ~1010 /1115 test cases due to time constraints)_.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Single Pass Stack**          | 🟢 O(n)                | 🟢 O(n)                 | 🚀 Optimal linear solution        | 🔧 Complex stack manipulation        |
| 🔍 **Two-Pass Stack**             | 🟢 O(n)                | 🟡 O(n)                 | 📖 Clear step separation          | 💾 Multiple auxiliary arrays         |
| 🐌 **Brute Force**                | 🔴 O(n³)               | 🟢 O(1)                 | 📚 Easy to understand             | ⏰ Extremely slow, TLE for large inputs |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Production/Competitive**                     | 🥇 **Single Pass Stack**             | ★★★★★                     |
| 📖 **Learning/Interview**                         | 🥈 **Two-Pass Stack**                | ★★★★☆                     |
| 📚 **Understanding Problem**                      | 🥉 **Brute Force**                   | ★☆☆☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<Integer> maxOfMins(int[] a) {
        int n = a.length;
        ArrayList<Integer> ans = new ArrayList<>();
        int[] mx = new int[n + 1];
        Stack<Integer> st = new Stack<>();
        
        for (int i = 0; i <= n; i++) {
            while (!st.isEmpty() && (i == n || a[st.peek()] >= a[i])) {
                int mid = st.pop();
                int w = i - (st.isEmpty() ? -1 : st.peek()) - 1;
                mx[w] = Math.max(mx[w], a[mid]);
            }
            st.push(i);
        }
        
        for (int i = 1; i <= n; i++) ans.add(mx[i]);
        for (int i = n - 2; i >= 0; i--) {
            ans.set(i, Math.max(ans.get(i), ans.get(i + 1)));
        }
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxOfMins(self, a):
        n = len(a)
        ans, mx, st = [], [0] * (n + 1), []
        
        for i in range(n + 1):
            while st and (i == n or a[st[-1]] >= a[i]):
                mid = st.pop()
                w = i - (st[-1] if st else -1) - 1
                mx[w] = max(mx[w], a[mid])
            st.append(i)
        
        ans = mx[1:n+1]
        for i in range(n - 2, -1, -1):
            ans[i] = max(ans[i], ans[i + 1])
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
