---
title: "👷 Minimum Number of Workers | GFG Solution 🔧"
keywords🏷️: ["👷 minimum workers", "📍 interval coverage", "🔍 greedy algorithm", "📈 sorting", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Minimum Number of Workers problem using greedy interval coverage. Efficiently determine the minimum workers needed to cover the entire day. 🚀"
date: 📅 2025-01-16
---


# *16. Minimum Number of Workers*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/minimum-sprinklers/1)

## **🧩 Problem Description**

You are given an array `arr[]`, where `arr[i]` denotes the range of working hours a person at position `i` can cover.

- If `arr[i] ≠ -1`, the person at index `i` can work and cover the time interval `[i - arr[i], i + arr[i]]`.
- If `arr[i] = -1`, the person is unavailable and cannot cover any time.

The task is to find the **minimum number of people** required to cover the entire working day from `0` to `n - 1`. If it is not possible to fully cover the day, return `-1`.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 2, 1, 0]
Output: 1
Explanation: The person at index 1 can cover the interval [-1, 3]. After adjusting to valid 
bounds, this becomes [0, 3], which fully covers the entire working day 0 to n-1. Therefore, 
only 1 person is required to cover the whole day.
```

### Example 2

```cpp
Input: arr[] = [2, 3, 4, -1, 2, 0, 0, -1, 0]
Output: -1
Explanation: Persons up to index 2 cover interval [0…6], but working hour 7 cannot be covered 
as arr[7] = -1. Since the 7th hour cannot be covered by any person, it is impossible to cover 
the full working day.
```

### Example 3

```cpp
Input: arr[] = [0, 1, 0, -1]
Output: -1
Explanation: The last hour cannot be covered by any person, so it is impossible to cover the 
full working day.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $-1 \le \text{arr}[i] \le \text{arr.size()}$

## **✅ My Approach**

This problem is a classic **Interval Coverage Problem** that can be optimally solved using a **Greedy Algorithm** combined with **Interval Merging**:

### **Greedy Interval Selection**

1. **Generate Coverage Intervals:**
   * For each valid worker (where `arr[i] ≠ -1`), calculate their coverage range: `[max(0, i - arr[i]), min(n-1, i + arr[i])]`.
   * Store these intervals as pairs of `(start, end)` positions.

2. **Sort Intervals:**
   * Sort all intervals by their starting position to process them in order.
   * This allows us to greedily select workers that extend coverage as far as possible.

3. **Greedy Selection:**
   * Initialize `pos = -1` (representing the last covered position) and `cnt = 0` (worker count).
   * While `pos < n - 1`:
     - Find all workers whose intervals start at or before `pos + 1` (they can extend current coverage).
     - Among these workers, select the one that extends coverage the farthest.
     - If no such worker exists, return `-1` (impossible to cover).
     - Increment worker count and update `pos` to the new farthest reachable position.

4. **Validation:**
   * If we successfully reach `pos >= n - 1`, return the worker count.
   * Otherwise, return `-1`.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the size of the array. The sorting of intervals dominates the time complexity, while the greedy selection pass takes O(n) time as each interval is processed at most once.
* **Expected Auxiliary Space Complexity:** O(n), as we store at most n intervals in the vector for workers who can cover some range (arr[i] ≠ -1).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                v.push_back({max(0, i - arr[i]), min(n - 1, i + arr[i])});
            }
        }
        if (v.empty()) return -1;
        sort(v.begin(), v.end());
        int cnt = 0, pos = -1, i = 0;
        while (pos < n - 1) {
            if (i >= v.size() || v[i].first > pos + 1) return -1;
            int reach = pos;
            while (i < v.size() && v[i].first <= pos + 1) reach = max(reach, v[i++].second);
            cnt++;
            pos = reach;
        }
        return cnt;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Greedy with Early Termination**

### 💡 Algorithm Steps:

1. Create intervals for each worker based on their coverage range.
2. Sort intervals by start position for efficient processing.
3. Use greedy selection to pick workers with maximum coverage extension.
4. Track covered positions and select minimal workers needed.

```cpp
class Solution {
public:
    int minMen(vector<int>& arr) {
        vector<pair<int, int>> intervals;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                intervals.push_back({i - arr[i], i + arr[i]});
            }
        }
        if (intervals.empty()) return -1;
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a.first != b.first ? a.first < b.first : a.second > b.second;
        });
        int workers = 0, covered = -1, idx = 0;
        while (covered < n - 1) {
            if (idx == intervals.size() || intervals[idx].first > covered + 1) return -1;
            int farthest = covered;
            while (idx < intervals.size() && intervals[idx].first <= covered + 1) {
                farthest = max(farthest, min(n - 1, intervals[idx++].second));
            }
            if (farthest == covered) return -1;
            workers++;
            covered = farthest;
        }
        return workers;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting dominates the time complexity
* **Auxiliary Space:** 💾 O(n) - Storage for intervals array

### ✅ **Why This Approach?**

* Early termination on impossible coverage scenarios
* Clearer boundary handling with explicit range clamping
* Enhanced sorting comparator for optimal interval selection

## 📊 **3️⃣ Stack-Based Interval Selection**

### 💡 Algorithm Steps:

1. Generate coverage intervals for all available workers.
2. Sort intervals and use stack to track coverage progression.
3. Select workers that extend coverage beyond current maximum.
4. Validate complete coverage from position 0 to n-1.

```cpp
class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> worker;
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) worker.push_back({max(0, i - arr[i]), min(n - 1, i + arr[i])});
        }
        if (worker.empty()) return -1;
        sort(worker.begin(), worker.end());
        int ans = 0, curr = -1, i = 0, m = worker.size();
        while (curr < n - 1 && i < m) {
            if (worker[i].first > curr + 1) return -1;
            int extend = curr;
            while (i < m && worker[i].first <= curr + 1) extend = max(extend, worker[i++].second);
            if (extend <= curr) return -1;
            ans++;
            curr = extend;
        }
        return curr >= n - 1 ? ans : -1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting is the bottleneck operation
* **Auxiliary Space:** 💾 O(n) - Space for worker interval storage

### ✅ **Why This Approach?**

* Additional validation at the end for complete coverage
* Clear progression tracking with extend variable
* Explicit check for coverage improvement

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Basic Greedy**               | 🟢 O(n log n)          | 🟢 O(n)                 | 🚀 Simple and efficient           | 🔧 Minimal error checking            |
| 🛡️ **Early Termination**          | 🟢 O(n log n)          | 🟢 O(n)                 | ✅ Robust error handling          | 📊 Slightly more complex             |
| 📚 **Stack-Based**                | 🟢 O(n log n)          | 🟢 O(n)                 | ⭐ Comprehensive validation       | 🐌 Additional final check            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Competitive programming**                        | 🥇 **Basic Greedy**                  | ★★★★★                     |
| 📖 **Production code**                                | 🥈 **Early Termination**             | ★★★★★                     |
| 🎯 **High reliability needed**                        | 🏅 **Stack-Based**                   | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int minMen(int arr[]) {
        int n = arr.length;
        List<int[]> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                v.add(new int[]{Math.max(0, i - arr[i]), Math.min(n - 1, i + arr[i])});
            }
        }
        if (v.isEmpty()) return -1;
        v.sort((a, b) -> a[0] - b[0]);
        int cnt = 0, pos = -1, i = 0;
        while (pos < n - 1) {
            if (i >= v.size() || v.get(i)[0] > pos + 1) return -1;
            int reach = pos;
            while (i < v.size() && v.get(i)[0] <= pos + 1) reach = Math.max(reach, v.get(i++)[1]);
            cnt++;
            pos = reach;
        }
        return cnt;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minMen(self, arr):
        n = len(arr)
        v = []
        for i in range(n):
            if arr[i] != -1:
                v.append((max(0, i - arr[i]), min(n - 1, i + arr[i])))
        if not v: return -1
        v.sort()
        cnt, pos, i = 0, -1, 0
        while pos < n - 1:
            if i >= len(v) or v[i][0] > pos + 1: return -1
            reach = pos
            while i < len(v) and v[i][0] <= pos + 1:
                reach = max(reach, v[i][1])
                i += 1
            cnt += 1
            pos = reach
        return cnt
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
