---
title: "🔢 Max Sum Increasing Subsequence | GFG Solution 🔍"
keywords🏷️: ["🔢 max sum", "📈 increasing subsequence", "🔍 dynamic programming", "📊 DP optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Max Sum Increasing Subsequence problem: find maximum sum of strictly increasing subsequence using dynamic programming and optimized approaches. 🚀"
date: 📅 2025-11-17
---

# *17. Max Sum Increasing Subsequence*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1)

## **🧩 Problem Description**

You are given an array `arr[]` consisting of positive integers. Your task is to find the **maximum sum** of a subsequence such that the elements of the subsequence form a **strictly increasing sequence**.

In other words, among all strictly increasing subsequences of the array, return the one with the largest possible sum.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 101, 2, 3, 100]
Output: 106
Explanation: The maximum sum of an increasing sequence is obtained from [1, 2, 3, 100].
```

### Example 2

```cpp
Input: arr[] = [4, 1, 2, 3]
Output: 6
Explanation: The maximum sum of an increasing sequence is obtained from [1, 2, 3].
```

### Example 3

```cpp
Input: arr[] = [4, 1, 2, 4]
Output: 7
Explanation: The maximum sum of an increasing sequence is obtained from [1, 2, 4].
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^3$
* $1 \le \text{arr}[i] \le 10^5$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming** to efficiently build up the maximum sum for increasing subsequences ending at each position:

### **Dynamic Programming Approach**

1. **Initialize DP Array:**
   - Create a `dp[]` array where `dp[i]` represents the maximum sum of increasing subsequence ending at index `i`.
   - Initially, set `dp[i] = arr[i]` as each element can form a subsequence by itself.

2. **Build DP Table:**
   - For each position `i`, iterate through all previous positions `j` (where `j < i`).
   - If `arr[j] < arr[i]` (strictly increasing condition), update `dp[i] = max(dp[i], dp[j] + arr[i])`.
   - This means we can extend the subsequence ending at `j` by including `arr[i]`.

3. **Track Maximum:**
   - Maintain a variable `res` to track the maximum value in the `dp[]` array.
   - Update `res` after computing each `dp[i]`.

4. **Return Result:**
   - The answer is the maximum value in the `dp[]` array, representing the largest sum achievable.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n²), where n is the size of the array. We use nested loops to compare each element with all previous elements to build the DP table.
* **Expected Auxiliary Space Complexity:** O(n), as we use a DP array of size n to store the maximum sum ending at each position.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = arr[i];
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i])
                    dp[i] = max(dp[i], dp[j] + arr[i]);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ TreeMap-Based Approach**

### 💡 Algorithm Steps:

1. Use a TreeMap to maintain the maximum sum for each value encountered.
2. For each element, find the best sum from all smaller elements using lower_bound.
3. Update the map with the new sum and remove redundant entries.
4. Track the maximum sum throughout the process.

```cpp
class Solution {
public:
    int maxSumIS(vector<int>& arr) {
        map<int, int> mp;
        int ans = 0;
        for (int x : arr) {
            auto it = mp.lower_bound(x);
            int best = 0;
            if (it != mp.begin()) best = prev(it)->second;
            int sum = best + x;
            if (mp[x] < sum) {
                mp[x] = sum;
                auto nxt = mp.upper_bound(x);
                while (nxt != mp.end() && nxt->second <= sum)
                    nxt = mp.erase(nxt);
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - TreeMap operations for each element
* **Auxiliary Space:** 💾 O(n) - Space for map storage

### ✅ **Why This Approach?**

* Efficient for large value ranges
* Automatically maintains sorted order
* Prunes suboptimal solutions dynamically

## 📊 **3️⃣ Binary Indexed Tree Approach**

### 💡 Algorithm Steps:

1. Coordinate compress array values to handle large ranges.
2. Use BIT to query maximum sum ending at values less than current.
3. Update BIT with new maximum sum at current value position.
4. Return the maximum sum found across all updates.

```cpp
class Solution {
public:
    int maxSumIS(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int n = sorted.size();
        vector<int> bit(n + 1, 0);
        auto update = [&](int i, int val) {
            for (i++; i <= n; i += i & -i)
                bit[i] = max(bit[i], val);
        };
        auto query = [&](int i) {
            int res = 0;
            for (i++; i > 0; i -= i & -i)
                res = max(res, bit[i]);
            return res;
        };
        int ans = 0;
        for (int x : arr) {
            int idx = lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
            int sum = query(idx - 1) + x;
            update(idx, sum);
            ans = max(ans, sum);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting and BIT operations
* **Auxiliary Space:** 💾 O(n) - BIT and coordinate arrays

### ✅ **Why This Approach?**

* Handles duplicates efficiently
* Scalable for competitive programming
* Clean separation of concerns

## 📊 **4️⃣ Segment Tree Approach**

### 💡 Algorithm Steps:

1. Compress coordinates to map values to indices.
2. Build segment tree to maintain maximum sums for ranges.
3. Query maximum sum for all values less than current element.
4. Update segment tree with current element's maximum sum.

```cpp
class Solution {
public:
    int maxSumIS(vector<int>& arr) {
        vector<int> vals = arr;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int m = vals.size();
        vector<int> seg(4 * m, 0);
        function<void(int, int, int, int, int)> update = [&](int idx, int l, int r, int pos, int value) {
            if (l == r) {
                seg[idx] = max(seg[idx], value);
                return;
            }
            int mid = (l + r) / 2;
            if (pos <= mid)
                update(idx * 2, l, mid, pos, value);
            else
                update(idx * 2 + 1, mid + 1, r, pos, value);
            seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
        };
        function<int(int, int, int, int, int)> query = [&](int idx, int l, int r, int ql, int qr) {
            if (qr < l || ql > r) return 0;
            if (ql <= l && r <= qr) return seg[idx];
            int mid = (l + r) / 2;
            return max(
                query(idx * 2, l, mid, ql, qr),
                query(idx * 2 + 1, mid + 1, r, ql, qr)
            );
        };
        int ans = 0;
        for (int x : arr) {
            int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
            int sum = query(1, 0, m - 1, 0, idx - 1) + x;
            update(1, 0, m - 1, idx, sum);
            ans = max(ans, sum);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Coordinate compression and segment tree queries
* **Auxiliary Space:** 💾 O(n) - Segment tree storage

### ✅ **Why This Approach?**

* Powerful for range queries
* Extensible to more complex problems
* Industry-standard data structure

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach** | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros** | ⚠️ **Cons** |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Dynamic Programming** | 🟡 O(n²) | 🟢 O(n) | 📖 Simple and intuitive | 🐌 Slower for large inputs |
| 🌳 **TreeMap-Based** | 🟢 O(n log n) | 🟡 O(n) | ⚡ Fast with optimization | 🔧 Complex logic |
| 📊 **Binary Indexed Tree** | 🟢 O(n log n) | 🟡 O(n) | 🎯 Efficient queries | 🧩 Requires compression |
| 🔺 **Segment Tree** | 🟢 O(n log n) | 🟡 O(n) | 💪 Versatile structure | 🔨 Implementation heavy |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario** | 🎖️ **Recommended Approach** | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Small arrays (n ≤ 1000)** | 🥇 **Dynamic Programming** | ★★★★★ |
| 📖 **Large arrays with optimization** | 🥈 **TreeMap-Based** | ★★★★★ |
| 🔧 **Competitive programming** | 🥉 **Binary Indexed Tree** | ★★★★☆ |
| 🎯 **Complex range queries needed** | 🏅 **Segment Tree** | ★★★★☆ |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int maxSumIS(int[] arr) {
        int n = arr.length;
        int res = 0;
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) {
            dp[i] = arr[i];
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i])
                    dp[i] = Math.max(dp[i], dp[j] + arr[i]);
            }
            res = Math.max(res, dp[i]);
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxSumIS(self, arr):
        n = len(arr)
        dp = arr[:]  
        for i in range(n):
            for j in range(i):
                if arr[j] < arr[i]:
                    dp[i] = max(dp[i], dp[j] + arr[i])
        return max(dp)
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

