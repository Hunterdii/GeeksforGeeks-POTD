---
title: "🪙 Coin Piles | GFG Solution 🎯"
keywords🏷️: ["🪙 coin piles", "🎯 sliding window", "📊 sorting", "🔄 two pointers", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Coin Piles problem: minimize coins removed to maintain difference ≤ k between any two piles using sliding window technique. 🚀"
date: 📅 2025-06-17
---

# *17. Coin Piles*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/coin-piles5152/1)

## **🧩 Problem Description**

You are given an array `arr[]` of integers, where each element represents the number of coins in a pile. You are also given an integer `k`. Your task is to remove the **minimum number of coins** such that the absolute difference between the number of coins in any two updated piles is **at most k**.

**Note:** You can also remove a pile by removing all the coins of that pile.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [2, 2, 2, 2], k = 0
Output: 0
Explanation: For any two piles the difference in the number of coins is <= 0. 
So no need to remove any coin.
```

### Example 2

```cpp
Input: arr[] = [1, 5, 1, 2, 5, 1], k = 3
Output: 2
Explanation: If we remove one coin each from both the piles containing 5 coins, 
then for any two piles the absolute difference in the number of coins is <= 3.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^4$
* $0 \le k \le 10^4$

## **✅ My Approach**

The optimal approach uses **Sorting** combined with **Sliding Window** technique to find the minimum coins to remove:

### **Sliding Window with Range Optimization**

1. **Sort the Array:**
   * Sort the array to group similar pile sizes together.
   * This allows us to consider contiguous ranges where max - min ≤ k.

2. **Calculate Total Sum:**
   * Store the total sum of all coins for reference.
   * This helps in calculating removal costs efficiently.

3. **Sliding Window Technique:**
   * For each possible starting position `s`, find the maximum range `[s, e)` where `arr[e-1] - arr[s] ≤ k`.
   * All piles in this range can coexist without violating the constraint.

4. **Optimization Strategy:**
   * **Keep piles in range:** Sum of coins in window `[s, e)`.
   * **Remove prefix:** All coins before position `s`.
   * **Adjust suffix:** Reduce piles after position `e` to `arr[s] + k` (or remove if too small).

5. **Cost Calculation:**
   * Prefix removal cost: Sum of `arr[0]` to `arr[s-1]`
   * Window preservation: Keep all coins in `[s, e)`
   * Suffix adjustment: `max(0, remaining_sum - (n-e) * (arr[s] + k))`

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the array size. Sorting takes O(n log n) and the sliding window traversal takes O(n) with each element visited at most twice.
* **Expected Auxiliary Space Complexity:** O(1), as we only use constant extra space for variables (excluding the input array sorting space).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minimumCoins(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size(), t = accumulate(a.begin(), a.end(), 0), res = t, w = 0, p = 0, e = 0;
        for (int s = 0; s < n; s++) {
            while (e < n && a[e] - a[s] <= k) w += a[e++];
            int r = max(0, (t - p - w) - (n - e) * (a[s] + k));
            res = min(res, p + r);
            if (e == s) e++; else w -= a[s];
            p += a[s];
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Two Pointer with Prefix Sum**

### 💡 Algorithm Steps:

1. Sort array and calculate total sum.
2. Use two pointers to maintain valid window.
3. Track prefix sum and window sum separately.

```cpp
class Solution {
public:
    int minimumCoins(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size(), t = accumulate(a.begin(), a.end(), 0), res = t, l = 0, r = 0, w = 0, p = 0;
        while (l < n) {
            while (r < n && a[r] - a[l] <= k) w += a[r++];
            res = min(res, p + max(0, (t - p - w) - (n - r) * (a[l] + k)));
            w -= a[l], p += a[l++];
            if (r <= l && r < n) w += a[r++];
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Clear separation of concerns.
* Easier to debug and maintain.

## 📊 **3️⃣ Sliding Window with Deque**

### 💡 Algorithm Steps:

1. Use deque to maintain window elements.
2. Efficiently add/remove elements from both ends.
3. Track sum using deque operations.

```cpp
class Solution {
public:
    int minimumCoins(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size(), t = accumulate(a.begin(), a.end(), 0), res = t, p = 0, w = 0;
        deque<int> d;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && a[j] - a[i] <= k) d.push_back(a[j]), w += a[j++];
            res = min(res, p + max(0, (t - p - w) - (n - j) * (a[i] + k)));
            if (!d.empty()) w -= d.front(), d.pop_front();
            p += a[i];
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n)
* **Auxiliary Space:** 💾 O(n)

### ✅ **Why This Approach?**

* Explicit window management.
* Good for understanding the algorithm.

## 📊 **4️⃣ Mathematical Optimization**

### 💡 Algorithm Steps:

1. Pre-calculate cumulative sums.
2. Use mathematical formulas to avoid repeated calculations.
3. Optimize with bit operations where possible.

```cpp
class Solution {
public:
    int minimumCoins(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size();
        vector<int> pf(n + 1, 0);
        for (int i = 0; i < n; i++) pf[i + 1] = pf[i] + a[i];
        int res = pf[n];
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && a[j] - a[i] <= k) j++;
            res = min(res, pf[i] + max(0, (pf[n] - pf[j]) - (n - j) * (a[i] + k)));
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n)
* **Auxiliary Space:** 💾 O(n)

### ✅ **Why This Approach?**

* Cleaner mathematical operations.
* Reduced function call overhead.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                          | ⚠️ **Cons**                    |
| ---------------------------------- | ---------------------- | ----------------------- | ----------------------------------- | ----------------------------- |
| 🔍 **Ultra-Optimized Sliding**     | 🟢 O(n log n)          | 🟢 O(1)                 | ⚡ Minimal memory, fastest runtime   | 🧮 Single-letter variables    |
| 🔄 **Two Pointer Approach**        | 🟢 O(n log n)          | 🟢 O(1)                 | 🔧 Clear logic separation           | 🐢 Slightly more operations   |
| 📊 **Deque Window**                | 🟢 O(n log n)          | 🔸 O(n)                 | 🏎️ Explicit window management       | 💾 Extra space overhead       |
| 🧮 **Mathematical Optimization**   | 🟢 O(n log n)          | 🔸 O(n)                 | 📈 Clean mathematical operations     | 💾 Prefix sum space           |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                           | 🎖️ **Recommended Approach**      | 🔥 **Performance Rating** |
| ---------------------------------------- | -------------------------------- | ------------------------- |
| ⚡ Maximum performance, memory critical   | 🥇 **Ultra-Optimized Sliding**   | ★★★★★                     |
| 🔧 Code clarity with good performance     | 🥈 **Two Pointer Approach**      | ★★★★☆                     |
| 🏎️ Educational/debugging purposes        | 🥉 **Deque Window**              | ★★★☆☆                     |
| 📊 Mathematical elegance                  | 🏅 **Mathematical Optimization** | ★★★★☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int minimumCoins(int[] a, int k) {
        Arrays.sort(a);
        int n = a.length, t = Arrays.stream(a).sum(), res = t, w = 0, p = 0, e = 0;
        for (int s = 0; s < n; s++) {
            while (e < n && a[e] - a[s] <= k) w += a[e++];
            int r = Math.max(0, (t - p - w) - (n - e) * (a[s] + k));
            res = Math.min(res, p + r);
            if (e == s) e++; else w -= a[s];
            p += a[s];
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minimumCoins(self, a, k):
        a.sort()
        n, t, res, w, p, e = len(a), sum(a), sum(a), 0, 0, 0
        for s in range(n):
            while e < n and a[e] - a[s] <= k:
                w += a[e]
                e += 1
            r = max(0, (t - p - w) - (n - e) * (a[s] + k))
            res = min(res, p + r)
            if e == s: e += 1
            else: w -= a[s]
            p += a[s]
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
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
