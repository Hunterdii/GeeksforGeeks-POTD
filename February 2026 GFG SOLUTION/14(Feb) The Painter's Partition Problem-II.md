---
title: "🎨 The Painter's Partition Problem-II | GFG Solution 🔍"
keywords🏷️: ["🎨 painter partition", "🔍 binary search", "📊 optimization", "📈 greedy", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to The Painter's Partition Problem-II: find minimum time to paint all boards by distributing work among k painters using binary search on answer technique. 🚀"
date: 📅 2025-02-14
---

# *14. The Painter's Partition Problem-II*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/the-painters-partition-problem1535/1)

## **🧩 Problem Description**

Given an array `arr[]` where each element denotes the length of a board, and an integer `k` representing the number of painters available. Each painter takes **1 unit of time** to paint **1 unit length** of a board.

Determine the **minimum amount of time** required to paint all the boards, under the constraint that each painter can paint only a **contiguous sequence of boards** (no skipping or splitting allowed).

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [5, 10, 30, 20, 15], k = 3
Output: 35
Explanation: The optimal allocation of boards among 3 painters is - 
Painter 1 → [5, 10] → time = 15
Painter 2 → [30] → time = 30
Painter 3 → [20, 15] → time = 35
Job will be done when all painters finish i.e. at time = max(15, 30, 35) = 35
```

### Example 2

```cpp
Input: arr[] = [10, 20, 30, 40], k = 2
Output: 60
Explanation: A valid optimal partition is - 
Painter 1 → [10, 20, 30] → time = 60
Painter 2 → [40] → time = 40
Job will be complete at time = max(60, 40) = 60
```

### Example 3

```cpp
Input: arr[] = [100, 200, 300, 400], k = 1
Output: 1000
Explanation: There is only one painter, so the painter must paint all boards sequentially. 
The total time taken will be the sum of all board lengths, i.e., 100 + 200 + 300 + 400 = 1000.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^4$
* $1 \le k \le 10^5$

## **✅ My Approach**

The optimal approach uses **Binary Search on Answer** combined with a **Greedy Validation** strategy:

### **Binary Search on Answer + Greedy Allocation**

1. **Define Search Space:**
   * Lower bound: Maximum board length (minimum possible time - at least one painter must paint the longest board)
   * Upper bound: Sum of all board lengths (maximum possible time - one painter paints everything)

2. **Binary Search Loop:**
   * Calculate mid value representing candidate answer (time limit per painter)
   * Check if this time limit allows completing all boards with at most k painters

3. **Feasibility Check (Greedy):**
   * Start with first painter and assign consecutive boards
   * If adding next board exceeds current painter's time limit, assign it to next painter
   * If any single board exceeds time limit, allocation is impossible
   * Count total painters needed for this time limit

4. **Adjust Search Range:**
   * If feasible with ≤ k painters: This could be answer, search for smaller time (move right pointer left)
   * If not feasible: Need more time, search in higher range (move left pointer right)

5. **Return Result:**
   * Binary search converges to minimum time where all boards can be painted with k painters

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × log(sum)), where n is the size of the array and sum is the total sum of all board lengths. The binary search operates over the range [max_element, sum], requiring O(log(sum)) iterations, and each feasibility check takes O(n) time to traverse the array.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables like pointers, counters, and sums, regardless of input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minTime(vector<int>& arr, int k) {
        int l = *max_element(arr.begin(), arr.end());
        int r = accumulate(arr.begin(), arr.end(), 0);
        auto canPaint = [&](int t) {
            int cnt = 1, sum = 0;
            for (int x : arr) {
                if (x > t) return false;
                if (sum + x > t) cnt++, sum = x;
                else sum += x;
            }
            return cnt <= k;
        };
        while (l < r) {
            int m = l + (r - l) / 2;
            canPaint(m) ? r = m : l = m + 1;
        }
        return l;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Binary Search with Inline Check**

### 💡 Algorithm Steps:

1. Initialize search range with max element as lower bound and sum as upper bound.
2. For each mid value, check if boards can be painted within that time.
3. Count painters needed by greedily assigning consecutive boards.
4. Adjust search range based on feasibility check result.

```cpp
class Solution {
public:
    int minTime(vector<int>& arr, int k) {
        int l = 0, r = 0;
        for (int x : arr) l = max(l, x), r += x;
        while (l < r) {
            int m = l + (r - l) / 2, p = 1, s = 0;
            bool valid = true;
            for (int x : arr) {
                if (x > m) { valid = false; break; }
                s + x > m ? (p++, s = x) : (s += x);
            }
            valid && p <= k ? r = m : l = m + 1;
        }
        return l;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × log(sum)) - Binary search over range with linear validation
* **Auxiliary Space:** 💾 O(1) - Constant space for variables

### ✅ **Why This Approach?**

* Inline feasibility check without lambda overhead
* Compact code with ternary operators
* Early exit optimization for invalid cases

## 📊 **3️⃣ Recursive Binary Search**

### 💡 Algorithm Steps:

1. Use recursive binary search pattern for cleaner code structure.
2. Base case returns when search range converges to single value.
3. Recursively search left or right half based on feasibility.
4. Return the minimum valid time found during recursion.

```cpp
class Solution {
public:
    bool check(vector<int>& arr, int t, int k) {
        int p = 1, s = 0;
        for (int x : arr) {
            if (x > t) return false;
            s + x > t ? (p++, s = x) : (s += x);
        }
        return p <= k;
    }
    int solve(vector<int>& arr, int k, int l, int r) {
        if (l >= r) return l;
        int m = l + (r - l) / 2;
        return check(arr, m, k) ? solve(arr, k, l, m) : solve(arr, k, m + 1, r);
    }
    int minTime(vector<int>& arr, int k) {
        return solve(arr, k, *max_element(arr.begin(), arr.end()), 
                     accumulate(arr.begin(), arr.end(), 0));
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × log(sum)) - Logarithmic recursive calls with linear check
* **Auxiliary Space:** 💾 O(log(sum)) - Recursion stack depth

### ✅ **Why This Approach?**

* Clean separation of concerns with helper functions
* Recursive pattern easy to understand and debug
* Functional programming style approach

## 📊 **4️⃣ Optimized Two-Pointer Style**

### 💡 Algorithm Steps:

1. Calculate initial bounds with single pass through array.
2. Use optimized loop structure with minimal conditional checks.
3. Track painter count and current sum simultaneously.
4. Converge to answer with tight loop bounds.

```cpp
class Solution {
public:
    int minTime(vector<int>& arr, int k) {
        int n = arr.size(), lo = 0, hi = 0;
        for (int i = 0; i < n; i++) lo = max(lo, arr[i]), hi += arr[i];
        int ans = hi;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1, painters = 1, sum = 0, i = 0;
            while (i < n && painters <= k) {
                if (arr[i] > mid) { painters = k + 1; break; }
                sum + arr[i] <= mid ? sum += arr[i++] : (painters++, sum = 0);
            }
            painters <= k ? (ans = mid, hi = mid - 1) : (lo = mid + 1);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × log(sum)) - Binary search with optimized validation
* **Auxiliary Space:** 💾 O(1) - Only loop variables used

### ✅ **Why This Approach?**

* Bit shift for division optimization
* Combined loop for bounds calculation
* Early termination when painter limit exceeded

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Lambda Binary Search**       | 🟢 O(n × log sum)      | 🟢 O(1)                 | 🚀 Modern C++ style               | 📝 Lambda syntax complexity          |
| 🔍 **Inline Check**               | 🟢 O(n × log sum)      | 🟢 O(1)                 | ⚡ No function call overhead      | 🔧 Less modular code                 |
| 📊 **Recursive**                  | 🟢 O(n × log sum)      | 🟡 O(log sum)           | 📖 Clean functional style         | 💾 Stack space overhead              |
| 🔄 **Two-Pointer Style**          | 🟢 O(n × log sum)      | 🟢 O(1)                 | ⭐ Optimized loop structure       | 🔧 More complex logic                |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Modern C++ projects**                            | 🥇 **Lambda Binary Search**          | ★★★★★                     |
| 📖 **Code competitions**                              | 🥈 **Inline Check**                  | ★★★★★                     |
| 🔧 **Recursive preference**                           | 🥉 **Recursive**                     | ★★★★☆                     |
| 🎯 **Maximum optimization**                           | 🏅 **Two-Pointer Style**             | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int minTime(int[] arr, int k) {
        int l = 0, r = 0;
        for (int x : arr) {
            l = Math.max(l, x);
            r += x;
        }
        while (l < r) {
            int m = l + (r - l) / 2, cnt = 1, sum = 0;
            boolean ok = true;
            for (int x : arr) {
                if (x > m) { ok = false; break; }
                if (sum + x > m) { cnt++; sum = x; }
                else sum += x;
            }
            if (ok && cnt <= k) r = m;
            else l = m + 1;
        }
        return l;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minTime(self, arr, k):
        l, r = max(arr), sum(arr)
        while l < r:
            m, cnt, s = l + (r - l) // 2, 1, 0
            ok = True
            for x in arr:
                if x > m:
                    ok = False
                    break
                if s + x > m:
                    cnt += 1
                    s = x
                else:
                    s += x
            if ok and cnt <= k:
                r = m
            else:
                l = m + 1
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
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" alt="Visitor counter" />
</p>
