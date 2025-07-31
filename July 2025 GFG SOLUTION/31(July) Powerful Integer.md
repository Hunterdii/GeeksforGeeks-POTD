---
title: "🔢 Powerful Integer | GFG Solution 🔍"
keywords🏷️: ["🔢 powerful integer", "🔍 sweep line", "📍 difference array", "📈 interval overlap", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Powerful Integer problem: find maximum integer appearing in at least k intervals using sweep line technique with difference array. 🚀"
date: 📅 2025-07-30
---


# *31. Powerful Integer*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/powerfull-integer--170647/1)

## **🧩 Problem Description**

You are given a 2D integer array `intervals[][]` of length n, where each `intervals[i] = [start, end]` represents a closed interval (i.e., all integers from start to end, inclusive). You are also given an integer `k`. An integer is called **Powerful** if it appears in at least `k` intervals. Find the **maximum Powerful Integer**.

**Note:** If no integer occurs at least k times return -1.

## **📘 Examples**

### Example 1

```cpp
Input: n = 3, intervals[][] = [[1, 3], [4, 6], [3, 4]], k = 2
Output: 4
Explanation: Integers 3 and 4 appear in 2 intervals. The maximum is 4.
```

### Example 2

```cpp
Input: n = 4, intervals[][] = [[1, 4], [12, 45], [3, 8], [10, 12]], k = 3
Output: -1
Explanation: No integer appears in at least 3 intervals.
```

### Example 3

```cpp
Input: n = 5, intervals[][] = [[16, 21], [5, 8], [12, 17], [17, 29], [9, 24]], k = 3
Output: 21
Explanation: Integers 16, 17, 18, 19, 20 and 21 appear in at least 3 intervals. The maximum is 21.
```

## **🔒 Constraints**

* $1 \le n \le 10^5$
* $1 \le \text{intervals}[i][0] \le \text{intervals}[i][1] \le 10^9$
* $1 \le k \le 10^5$

## **✅ My Approach**

The optimal approach uses the **Sweep Line** technique with **Difference Array** to efficiently track interval overlaps and find the maximum powerful integer:

### **Sweep Line + Difference Array**

1. **Create Events:**
   * For each interval `[start, end]`, create two events:
     * `+1` at position `start` (interval begins)
     * `-1` at position `end + 1` (interval ends)

2. **Process Events in Order:**
   * Use a map to store events and process them in sorted order of positions.
   * Maintain a running count of active intervals at each position.

3. **Track Powerful Integers:**
   * When processing `+1` events, increment count and check if count ≥ k.
   * When processing `-1` events, check if previous position had count ≥ k before decrementing.
   * Keep track of the maximum position where count ≥ k.

4. **Handle Edge Cases:**
   * If no position satisfies count ≥ k, return -1.
   * Properly handle interval boundaries using `end + 1` for closing events.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the number of intervals. We create 2n events and process them in sorted order using a map, which takes O(n log n) time for sorting and O(log n) for each map operation.
* **Expected Auxiliary Space Complexity:** O(n), as we store at most 2n events in the map for processing the sweep line algorithm.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        map<int, int> events;
        for (auto& i : intervals) {
            events[i[0]]++;
            events[i[1] + 1]--;
        }
        int count = 0, result = -1;
        for (auto& e : events) {
            if (e.second > 0) {
                count += e.second;
                if (count >= k) result = e.first;
            } else {
                if (count >= k) result = e.first - 1;
                count += e.second;
            }
        }
        return result;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Coordinate Compression + Difference Array**

### 💡 Algorithm Steps:

1. Extract all unique coordinates from intervals and sort them
2. Use coordinate compression to map coordinates to indices
3. Apply difference array technique on compressed coordinates
4. Find the rightmost position where overlap count ≥ k

```cpp
class Solution {
public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        set<int> coords;
        for (auto& i : intervals) {
            coords.insert(i[0]);
            coords.insert(i[1] + 1);
        }
        vector<int> sorted_coords(coords.begin(), coords.end());
        vector<int> diff(sorted_coords.size(), 0);
        
        for (auto& i : intervals) {
            int start_idx = lower_bound(sorted_coords.begin(), sorted_coords.end(), i[0]) - sorted_coords.begin();
            int end_idx = lower_bound(sorted_coords.begin(), sorted_coords.end(), i[1] + 1) - sorted_coords.begin();
            diff[start_idx]++;
            if (end_idx < diff.size()) diff[end_idx]--;
        }
        
        int count = 0, result = -1;
        for (int i = 0; i < diff.size(); i++) {
            count += diff[i];
            if (count >= k && i + 1 < sorted_coords.size()) 
                result = sorted_coords[i + 1] - 1;
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting coordinates and binary search
* **Auxiliary Space:** 💾 O(n) - Storage for coordinates and difference array

### ✅ **Why This Approach?**

* Better for sparse intervals with large coordinate ranges
* Explicit coordinate handling for better debugging
* Cleaner separation of compression and processing logic

## 📊 **3️⃣ Priority Queue Based Sweep Line**

### 💡 Algorithm Steps:

1. Create events for interval starts (+1) and ends (-1) with timestamps
2. Sort events by position, with end events processed before start events at same position
3. Use running count to track current overlap at each position
4. Maintain the rightmost position where overlap count ≥ k

```cpp
class Solution {
public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        vector<pair<int, int>> events;
        for (auto& i : intervals) {
            events.push_back({i[0], 1});
            events.push_back({i[1] + 1, -1});
        }
        sort(events.begin(), events.end());
        
        int count = 0, result = -1, prev_pos = -1;
        for (auto& e : events) {
            if (count >= k && e.first > prev_pos) {
                result = e.first - 1;
            }
            count += e.second;
            prev_pos = e.first;
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting events
* **Auxiliary Space:** 💾 O(n) - Storage for events

### ✅ **Why This Approach?**

* Classic sweep line algorithm pattern
* Handles edge cases naturally with event ordering
* Scales well with large coordinate ranges

## 📊 **4️⃣ Brute Force with Range Sweeping**

### 💡 Algorithm Steps:

1. Find the minimum and maximum coordinates across all intervals
2. For each integer position in the range, count overlapping intervals
3. Track the rightmost position where overlap count meets threshold k
4. Return the rightmost valid position found

```cpp
class Solution {
public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        if (intervals.empty()) return -1;
        
        int min_coord = INT_MAX, max_coord = INT_MIN;
        for (auto& i : intervals) {
            min_coord = min(min_coord, i[0]);
            max_coord = max(max_coord, i[1]);
        }
        
        int result = -1;
        for (int pos = min_coord; pos <= max_coord; pos++) {
            int count = 0;
            for (auto& i : intervals) {
                if (pos >= i[0] && pos <= i[1]) count++;
            }
            if (count >= k) result = pos;
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n * m) - Where m is the coordinate range
* **Auxiliary Space:** 💾 O(1) - Only constant extra space

### ✅ **Why This Approach?**

* Simple and intuitive logic
* Good for small coordinate ranges
* Easy to understand and verify correctness

> **Note:** This approach results in **Time Limit Exceeded (TLE)** for large inputs _(fails on large coordinate ranges due to time constraints)_.

## 📊 **5️⃣ Segment Tree Range Query**

### 💡 Algorithm Steps:

1. Use coordinate compression to map all coordinates to a smaller range
2. Build a segment tree on the compressed coordinates
3. For each interval, perform range update (+1) on the segment tree
4. Query each position to find the maximum position with count ≥ k

```cpp
class Solution {
    vector<int> tree, lazy;
    void build(int node, int start, int end) {
        if (start == end) tree[node] = lazy[node] = 0;
        else {
            int mid = (start + end) / 2;
            build(2*node, start, mid);
            build(2*node+1, mid+1, end);
            tree[node] = lazy[node] = 0;
        }
    }
    void updateLazy(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    void updateRange(int node, int start, int end, int l, int r, int val) {
        updateLazy(node, start, end);
        if (start > r || end < l) return;
        if (start >= l && end <= r) {
            lazy[node] += val;
            updateLazy(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        updateRange(2*node, start, mid, l, r, val);
        updateRange(2*node+1, mid+1, end, l, r, val);
    }
    int query(int node, int start, int end, int idx) {
        updateLazy(node, start, end);
        if (start == end) return tree[node];
        int mid = (start + end) / 2;
        if (idx <= mid) return query(2*node, start, mid, idx);
        return query(2*node+1, mid+1, end, idx);
    }
public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        set<int> coords;
        for (auto& i : intervals) {
            coords.insert(i[0]);
            coords.insert(i[1]);
        }
        vector<int> sorted_coords(coords.begin(), coords.end());
        int n = sorted_coords.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(1, 0, n - 1);
        for (auto& i : intervals) {
            int start_idx = lower_bound(sorted_coords.begin(), sorted_coords.end(), i[0]) - sorted_coords.begin();
            int end_idx = lower_bound(sorted_coords.begin(), sorted_coords.end(), i[1]) - sorted_coords.begin();
            updateRange(1, 0, n - 1, start_idx, end_idx, 1);
        }
        int result = -1;
        for (int i = 0; i < n; i++) {
            if (query(1, 0, n - 1, i) >= k) {
                result = sorted_coords[i];
            }
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Coordinate compression and segment tree operations
* **Auxiliary Space:** 💾 O(n) - Segment tree storage

### ✅ **Why This Approach?**

* Powerful for complex range queries
* Supports dynamic updates efficiently
* Good for multiple query scenarios

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Sweep Line with Difference Array**       | 🟢 O(n log n)          | 🟢 O(n)                 | 🚀 Simple and clean               | 🔧 Map overhead                       |
| 🔍 **Coordinate Compression**      | 🟢 O(n log n)          | 🟡 O(n)                 | 📖 Explicit coordinate handling   | 💾 More complex implementation       |
| 🔄 **Priority Queue Sweep**       | 🟢 O(n log n)          | 🟢 O(n)                 | ⭐ Classic sweep line pattern     | 🔧 Complex event handling            |
| 📊 **Brute Force (TLE)**          | 🔴 O(n * range)        | 🟢 O(1)                 | 🎯 Simple and intuitive           | 🐌 Poor performance on large ranges  |
| 🌳 **Segment Tree**               | 🟢 O(n log n)          | 🟡 O(n)                 | 🔧 Powerful for complex queries   | 💾 Complex implementation            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General purpose solution**                   | 🥇 **Sweep Line with Difference Array**          | ★★★★★                     |
| 📖 **Large sparse coordinates**                   | 🥈 **Coordinate Compression**         | ★★★★☆                     |
| 🔧 **Small coordinate range**                     | 🥉 **Brute Force (TLE)**             | ★★★☆☆                     |
| 🎯 **Interview/Learning sweep line**              | 🏅 **Priority Queue Sweep**          | ★★★★★                     |
| 🌳 **Multiple complex queries**                   | 🎖️ **Segment Tree**                   | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int powerfulInteger(int[][] intervals, int k) {
        TreeMap<Integer, Integer> events = new TreeMap<>();
        for (int[] i : intervals) {
            events.put(i[0], events.getOrDefault(i[0], 0) + 1);
            events.put(i[1] + 1, events.getOrDefault(i[1] + 1, 0) - 1);
        }
        int count = 0, result = -1;
        for (Map.Entry<Integer, Integer> e : events.entrySet()) {
            if (e.getValue() > 0) {
                count += e.getValue();
                if (count >= k) result = e.getKey();
            } else {
                if (count >= k) result = e.getKey() - 1;
                count += e.getValue();
            }
        }
        return result;
    }
}
```

## **🐍 Code (Python)**

```python
from collections import defaultdict

class Solution:
    def powerfulInteger(self, intervals, k):
        events = defaultdict(int)
        for start, end in intervals:
            events[start] += 1
            events[end + 1] -= 1
        
        count, result = 0, -1
        for pos in sorted(events.keys()):
            if events[pos] > 0:
                count += events[pos]
                if count >= k:
                    result = pos
            else:
                if count >= k:
                    result = pos - 1
                count += events[pos]
        return result
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
