---
title: "💹 Maximum Subarray Sum with Length Constraints | GFG Solution 🔍"
keywords🏷️: ["💹 maximum subarray", "🔍 sliding window", "📍 monotonic deque", "📈 prefix sum", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Maximum Subarray Sum with Length Constraints problem: find maximum sum of subarray with length between a and b using monotonic deque optimization. 🚀"
date: 📅 2025-09-29
---

# *29. Maximum Subarray Sum 2*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximum-subarray-sum--110820/1)

## **🧩 Problem Description**

You are given an array `arr[]` of integers and two integers `a` and `b`. Your task is to find the **maximum possible sum** of a contiguous subarray whose length is **at least a** and **at most b**.

A subarray is a contiguous sequence of elements within an array. The goal is to efficiently find the maximum sum among all valid subarrays satisfying the length constraints.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [4, 5, -1, -2, 6], a = 2, b = 4
Output: 9
Explanation: The subarray [4, 5] has length 2 and sum 9, which is the maximum among 
all subarrays of length between 2 and 4.
```

### Example 2

```cpp
Input: arr[] = [-1, 3, -1, -2, 5, 3, -5, 2, 2], a = 3, b = 5
Output: 8
Explanation: The subarray [3, -1, -2, 5, 3] has length 5 and sum 8, which is the 
maximum among all subarrays of length between 3 and 5.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $-10^5 \le \text{arr}[i] \le 10^5$
* $1 \le a \le b \le \text{arr.size()}$

## **✅ My Approach**

The optimal approach uses **Prefix Sum** combined with a **Monotonic Deque** to efficiently track the minimum prefix sum in a sliding window:

### **Monotonic Deque with Prefix Sum**

1. **Compute Prefix Sums:**
   * Build a prefix sum array where `pre[i]` represents the sum of elements from index 0 to i-1.
   * This allows O(1) calculation of any subarray sum as `pre[j] - pre[i]`.

2. **Initialize Deque:**
   * Use a deque to maintain indices of prefix sums in increasing order.
   * The deque helps find the minimum prefix sum in the valid window efficiently.

3. **Iterate Through Ending Positions:**
   * For each position `i` from `a` to `n`, consider it as the ending position of a subarray.
   * Calculate valid starting position range: `[max(0, i-b), i-a]`.

4. **Maintain Monotonic Property:**
   * Remove indices from deque back if their prefix values are greater than or equal to current prefix.
   * This ensures deque maintains increasing order of prefix values.
   * Add current valid starting position to deque.

5. **Remove Invalid Indices:**
   * Remove indices from deque front if they fall outside the valid window range.
   * The front of deque always contains the minimum prefix in valid range.

6. **Calculate Maximum Sum:**
   * Compute subarray sum as `pre[i] - pre[dq.front()]` where `dq.front()` gives minimum prefix in valid window.
   * Update result with maximum sum found.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), as each element is added to and removed from the deque at most once, resulting in amortized constant time operations per element. The prefix sum computation also takes O(n) time.
* **Expected Auxiliary Space Complexity:** O(n), as we use additional space for the prefix sum array of size n+1 and a deque that can hold at most n elements in the worst case.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size(), res = INT_MIN;
        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + arr[i];
        deque<int> dq;
        for (int i = a; i <= n; i++) {
            int l = max(0, i - b), r = i - a;
            while (!dq.empty() && pre[dq.back()] >= pre[r]) dq.pop_back();
            dq.push_back(r);
            while (!dq.empty() && dq.front() < l) dq.pop_front();
            res = max(res, pre[i] - pre[dq.front()]);
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Sliding Window with Min-Tracking**

### 💡 Algorithm Steps:

1. Compute prefix sums for efficient range sum queries.
2. Use a sliding window of valid start positions for each end position.
3. Track minimum prefix sum in the valid window using a monotonic deque.
4. Calculate maximum difference between current prefix and minimum prefix in range.

```cpp
class Solution {
public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size(), ans = INT_MIN;
        vector<int> p(n + 1);
        for (int i = 0; i < n; i++) p[i + 1] = p[i] + arr[i];
        deque<pair<int, int>> dq;
        dq.push_back({0, 0});
        for (int i = a; i <= n; i++) {
            while (!dq.empty() && dq.front().second < i - b) dq.pop_front();
            ans = max(ans, p[i] - dq.front().first);
            if (i < n) {
                while (!dq.empty() && dq.back().first >= p[i - a + 1]) dq.pop_back();
                dq.push_back({p[i - a + 1], i - a + 1});
            }
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with amortized O(1) deque operations
* **Auxiliary Space:** 💾 O(n) - Prefix array and deque storage

### ✅ **Why This Approach?**

* Explicit window boundary tracking
* Pairs store both value and index for clarity
* Easy to debug and verify correctness

## 📊 **3️⃣ Two-Pointer with Segment Tree**

### 💡 Algorithm Steps:

1. Build a segment tree for range minimum queries on prefix sums.
2. For each ending position, query minimum prefix in valid range.
3. Calculate subarray sum using difference of prefix sums.
4. Update maximum sum found across all valid subarrays.

```cpp
class Solution {
    vector<int> seg;
    void build(vector<int>& p, int i, int l, int r) {
        if (l == r) { seg[i] = p[l]; return; }
        int m = (l + r) / 2;
        build(p, 2 * i, l, m);
        build(p, 2 * i + 1, m + 1, r);
        seg[i] = min(seg[2 * i], seg[2 * i + 1]);
    }
    int query(int i, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return INT_MAX;
        if (ql <= l && r <= qr) return seg[i];
        int m = (l + r) / 2;
        return min(query(2 * i, l, m, ql, qr), query(2 * i + 1, m + 1, r, ql, qr));
    }
public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size(), ans = INT_MIN;
        vector<int> p(n + 1);
        for (int i = 0; i < n; i++) p[i + 1] = p[i] + arr[i];
        seg.resize(4 * (n + 1));
        build(p, 1, 0, n);
        for (int i = a; i <= n; i++) {
            int minPre = query(1, 0, n, max(0, i - b), i - a);
            ans = max(ans, p[i] - minPre);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Segment tree build and queries
* **Auxiliary Space:** 💾 O(n) - Segment tree storage

### ✅ **Why This Approach?**

* Generalizes to dynamic updates
* Clear separation of concerns
* Useful when array modifications are needed

## 📊 **4️⃣ Brute Force with Optimization**

### 💡 Algorithm Steps:

1. Enumerate all subarrays with length between a and b.
2. Calculate sum for each valid subarray length.
3. Use prefix sums to compute range sums in O(1) time.
4. Track and return the maximum sum encountered.

```cpp
class Solution {
public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size(), res = INT_MIN;
        vector<int> p(n + 1);
        for (int i = 0; i < n; i++) p[i + 1] = p[i] + arr[i];
        for (int len = a; len <= b; len++) {
            for (int i = 0; i + len <= n; i++) {
                res = max(res, p[i + len] - p[i]);
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × (b - a)) - Nested loops over lengths and positions
* **Auxiliary Space:** 💾 O(n) - Prefix array only

### ✅ **Why This Approach?**

* Straightforward and easy to implement
* Good for small constraint ranges
* No complex data structures required

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110 /1111 test cases due to time constraints).

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Monotonic Deque**            | 🟢 O(n)                | 🟢 O(n)                 | 🚀 Optimal linear time            | 🔧 Complex deque maintenance         |
| 🔍 **Sliding Window**             | 🟢 O(n)                | 🟢 O(n)                 | 📖 Clear window logic             | 🔧 Extra space for pairs             |
| 📊 **Segment Tree**               | 🟡 O(n log n)          | 🟢 O(n)                 | 🎯 Supports dynamic updates       | 🐌 Slower for static queries         |
| 🔄 **Brute Force**                | 🔴 O(n × (b-a))        | 🟢 O(n)                 | ⭐ Simple implementation          | 🐌 Poor performance for large ranges |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Monotonic Deque**               | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **Sliding Window**                | ★★★★☆                     |
| 🔧 **Dynamic array updates**                          | 🥉 **Segment Tree**                  | ★★★★☆                     |
| 🎯 **Small constraints**                              | 🏅 **Brute Force**                   | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int maxSubarrSum(int[] arr, int a, int b) {
        int n = arr.length, res = Integer.MIN_VALUE;
        int[] pre = new int[n + 1];
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + arr[i];
        Deque<Integer> dq = new ArrayDeque<>();
        for (int i = a; i <= n; i++) {
            int l = Math.max(0, i - b), r = i - a;
            while (!dq.isEmpty() && pre[dq.peekLast()] >= pre[r]) dq.pollLast();
            dq.offerLast(r);
            while (!dq.isEmpty() && dq.peekFirst() < l) dq.pollFirst();
            res = Math.max(res, pre[i] - pre[dq.peekFirst()]);
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxSubarrSum(self, arr, a, b):
        n, res = len(arr), float('-inf')
        pre = [0] * (n + 1)
        for i in range(n): pre[i + 1] = pre[i] + arr[i]
        dq = []
        for i in range(a, n + 1):
            l, r = max(0, i - b), i - a
            while dq and pre[dq[-1]] >= pre[r]: dq.pop()
            dq.append(r)
            while dq and dq[0] < l: dq.pop(0)
            res = max(res, pre[i] - pre[dq[0]])
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




