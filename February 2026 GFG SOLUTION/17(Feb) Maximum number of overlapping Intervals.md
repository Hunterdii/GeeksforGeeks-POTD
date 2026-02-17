---
title: "📅 Maximum Number of Overlapping Intervals | GFG Solution 🔍"
keywords🏷️: ["📅 overlapping intervals", "🔍 difference array", "📍 sweep line", "📈 prefix sum", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Maximum Number of Overlapping Intervals problem: find the maximum number of intervals that overlap at any point using the difference array (sweep line) technique. 🚀"
date: 📅 2025-02-17
---

# *17. Maximum Number of Overlapping Intervals*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/intersecting-intervals/1)

## **🧩 Problem Description**

You are given an array `arr[][]` of intervals, where each interval is represented by two integers `[start, end]` (inclusive). Your task is to return the **maximum number of intervals that overlap at any point in time**.

Two intervals overlap if they share at least one common point on the number line (endpoints are included, so `[1, 2]` and `[2, 4]` do overlap at point `2`).

## **📘 Examples**

### Example 1

```cpp
Input: arr[][] = [[1, 2], [2, 4], [3, 6]]
Output: 2
Explanation: The maximum overlapping intervals are 2 (between [1, 2] and [2, 4] at point 2, 
or between [2, 4] and [3, 6] between points 3 and 4).
```

### Example 2

```cpp
Input: arr[][] = [[1, 8], [2, 5], [5, 6], [3, 7]]
Output: 4
Explanation: The maximum overlapping intervals are 4 (all four intervals overlap between 
points 5 and 5: [1,8], [2,5], [5,6], and [3,7]).
```

## **🔒 Constraints**

* $2 \le \text{arr.size()} \le 2 \times 10^4$
* $1 \le \text{arr}[i][0] < \text{arr}[i][1] \le 4 \times 10^6$

## **✅ My Approach**

The optimal approach uses the **Difference Array (Sweep Line)** technique to efficiently count the maximum simultaneous overlaps in a single pass:

### **Difference Array + Prefix Sum (Sweep Line)**

1. **Find Maximum Endpoint:**
   * Traverse all intervals to find the global maximum endpoint `mx`. This determines the size of the difference array.

2. **Build Difference Array:**
   * Create a `diff` array of size `mx + 2`, initialized to zeros.
   * For each interval `[start, end]`, increment `diff[start]` by 1 (interval begins) and decrement `diff[end + 1]` by 1 (interval ends after `end`).

3. **Compute Prefix Sum:**
   * Traverse the `diff` array from left to right, maintaining a running sum `cur`.
   * At each index, `cur` represents the count of active (overlapping) intervals at that point.

4. **Track Maximum:**
   * At every step, update the result `res` with `max(res, cur)`.

5. **Return Result:**
   * `res` holds the maximum number of intervals overlapping at any single point.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n + mx), where n is the number of intervals and mx is the maximum endpoint value. We iterate over all intervals once to build the difference array and then iterate over the range `[0, mx]` once to compute the prefix sum.
* **Expected Auxiliary Space Complexity:** O(mx), as we allocate a difference array of size proportional to the maximum endpoint value (`mx + 2`).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int overlapInt(vector<vector<int>>& arr) {
        int mx = 0;
        for (auto& a : arr) mx = max(mx, a[1]);
        vector<int> diff(mx + 2, 0);
        for (auto& a : arr) { diff[a[0]]++; diff[a[1] + 1]--; }
        int res = 0, cur = 0;
        for (int x : diff) res = max(res, cur += x);
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Sorted Events (Coordinate Compression) Approach**

### 💡 Algorithm Steps:

1. Create a list of events: for each interval `[start, end]`, add `(start, +1)` and `(end+1, -1)` as events.
2. Sort all events by their coordinate; break ties by putting decrements before increments to handle edge-touching intervals correctly.
3. Sweep through sorted events, maintaining a running active count.
4. Track the maximum active count seen during the sweep.

```cpp
class Solution {
public:
    int overlapInt(vector<vector<int>> &arr) {
        vector<pair<int,int>> events;
        for (auto& a : arr) {
            events.push_back({a[0], 1});
            events.push_back({a[1] + 1, -1});
        }
        sort(events.begin(), events.end());
        int cur = 0, ans = 0;
        for (auto& [pos, delta] : events) {
            cur += delta;
            ans = max(ans, cur);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting 2n events dominates
* **Auxiliary Space:** 💾 O(n) - Event list of size 2n

### ✅ **Why This Approach?**

* Works efficiently even for very large coordinate ranges (no giant array allocation)
* Natural event-based sweep line model
* Easily extended to track which intervals are active at peak

## 📊 **3️⃣ Sorted Start/End Arrays (Two-Pointer) Approach**

### 💡 Algorithm Steps:

1. Extract all start and end values into two separate arrays.
2. Sort both arrays independently.
3. Use two pointers `i` (into starts) and `j` (into ends) to simulate the sweep: if `starts[i] <= ends[j]`, a new interval begins — increment active count and advance `i`; otherwise an interval ends — decrement active count and advance `j`.
4. Track the maximum active count throughout.

```cpp
class Solution {
public:
    int overlapInt(vector<vector<int>> &arr) {
        int n = arr.size();
        vector<int> starts(n), ends(n);
        for (int i = 0; i < n; i++) starts[i] = arr[i][0], ends[i] = arr[i][1];
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int i = 0, j = 0, cur = 0, ans = 0;
        while (i < n) {
            if (starts[i] <= ends[j]) { cur++; i++; }
            else { cur--; j++; }
            ans = max(ans, cur);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Two independent sorts plus linear sweep
* **Auxiliary Space:** 💾 O(n) - Two auxiliary arrays of size n

### ✅ **Why This Approach?**

* No dependency on maximum coordinate value — safe for arbitrarily large ranges
* Classic two-pointer pattern, highly cache-friendly
* Easily adaptable to related interval scheduling problems

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                             | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                                      | ⚠️ **Cons**                                      |
| ------------------------------------------- | ---------------------- | ----------------------- | ----------------------------------------------- | ------------------------------------------------ |
| 🏷️ **Difference Array + Prefix Sum**       | 🟡 O(n + M)            | 🔴 O(M)                 | 🚀 Single-pass prefix sum, simplest to code     | 🔧 Allocates huge array when M is large          |
| 🔍 **Sorted Events (Coord. Compression)**  | 🟢 O(n log n)          | 🟢 O(n)                 | 📖 Memory-safe for large ranges, flexible model | 🔧 Requires explicit event list construction     |
| 📊 **Sorted Start/End (Two-Pointer)**      | 🟢 O(n log n)          | 🟢 O(n)                 | 🎯 No extra events needed, cache-friendly       | 🔧 Two separate arrays; tie-breaking less obvious |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                              | 🎖️ **Recommended Approach**                  | 🔥 **Performance Rating** |
| ------------------------------------------------------------ | ---------------------------------------------- | ------------------------- |
| 🏅 **Small coordinate range (M ≤ 10⁶)**                     | 🥇 **Difference Array + Prefix Sum**           | ★★★★★                     |
| 📖 **Large or unbounded coordinate range**                   | 🥈 **Sorted Events (Coord. Compression)**      | ★★★★★                     |
| 🎯 **Memory-constrained / classic interview pattern**        | 🏅 **Sorted Start/End (Two-Pointer)**          | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public static int overlapInt(int[][] arr) {
        int mx = 0;
        for (int[] a : arr) mx = Math.max(mx, a[1]);
        int[] diff = new int[mx + 2];
        for (int[] a : arr) { diff[a[0]]++; diff[a[1] + 1]--; }
        int res = 0, cur = 0;
        for (int x : diff) res = Math.max(res, cur += x);
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def overlapInt(self, arr):
        mx = max(a[1] for a in arr)
        diff = [0] * (mx + 2)
        for a in arr:
            diff[a[0]] += 1
            diff[a[1] + 1] -= 1
        res = cur = 0
        for x in diff:
            cur += x
            res = max(res, cur)
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

