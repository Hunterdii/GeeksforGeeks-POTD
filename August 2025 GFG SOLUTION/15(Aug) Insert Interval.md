---
title: "🗓️ Insert Interval | GFG Solution 🔍"
keywords🏷️: ["🗓️ insert interval", "🔍 interval merging", "📍 two pointers", "📈 array manipulation", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Insert Interval problem: efficiently insert and merge overlapping intervals in a sorted array using linear traversal technique. 🚀"
date: 📅 2025-08-13
---

# *15. Insert Interval*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/insert-interval-1666733333/1)

## **🧩 Problem Description**

Geek has an array of non-overlapping intervals `intervals[][]` where `intervals[i] = [starti, endi]` represent the start and the end of the ith event and intervals is sorted in ascending order by `starti`. He wants to add a new interval `newInterval[] = [newStart, newEnd]` where `newStart` and `newEnd` represent the start and end of this interval.

Help Geek to insert `newInterval` into intervals such that intervals is still sorted in ascending order by `starti` and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

## **📘 Examples**

### Example 1

```cpp
Input: intervals[][] = [[1, 3], [4, 5], [6, 7], [8, 10]], newInterval[] = [5, 6]
Output: [[1, 3], [4, 7], [8, 10]]
Explanation: The newInterval [5, 6] overlaps with [4, 5] and [6, 7]. 
So, they are merged into one interval [4, 7].
```

### Example 2

```cpp
Input: intervals[][] = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]], newInterval[] = [4, 9]
Output: [[1, 2], [3, 10], [12, 16]]
Explanation: The new interval [4, 9] overlaps with [3, 5], [6, 7] and [8, 10]. 
So, they are merged into one interval [3, 10].
```

## **🔒 Constraints**

* $1 \le \text{intervals.size()} \le 10^5$
* $0 \le \text{starti} \le \text{endi} \le 10^9$
* $0 \le \text{newStart} \le \text{newEnd} \le 10^9$

## **✅ My Approach**

The optimal approach uses **Linear Traversal with Three-Phase Processing** to efficiently handle interval insertion and merging:

### **Three-Phase Linear Processing**

1. **Phase 1 - Add Non-overlapping Intervals Before:**
   * Traverse intervals from left and add all intervals that end before `newInterval` starts.
   * Condition: `intervals[i][1] < newInterval[0]`
   * These intervals don't overlap with `newInterval`.

2. **Phase 2 - Merge Overlapping Intervals:**
   * Process all intervals that overlap with `newInterval`.
   * Condition: `intervals[i][0] <= newInterval[1]`
   * Merge by taking minimum start and maximum end.
   * Update `newInterval` bounds during merging process.

3. **Phase 3 - Add Remaining Intervals:**
   * Add all remaining intervals after the overlap region.
   * These intervals start after `newInterval` ends.

4. **Insert Merged Interval:**
   * Add the final merged `newInterval` between phases 2 and 3.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of intervals. We traverse the intervals array exactly once, processing each interval in constant time.
* **Expected Auxiliary Space Complexity:** O(n), where n is the number of intervals. In the worst case, we need to store all intervals in the result array. The algorithm uses constant extra space beyond the output storage.

## **🔧 Code (C)**

```c
Interval* insertInterval(Interval* intervals, int intervalsSize, Interval newInterval, int* returnSize) {
    Interval* result = (Interval*)malloc((intervalsSize + 1) * sizeof(Interval));
    int i = 0, idx = 0;
    while (i < intervalsSize && intervals[i].end < newInterval.start)
        result[idx++] = intervals[i++];
    
    while (i < intervalsSize && intervals[i].start <= newInterval.end) {
        newInterval.start = (intervals[i].start < newInterval.start) ? intervals[i].start : newInterval.start;
        newInterval.end = (intervals[i].end > newInterval.end) ? intervals[i].end : newInterval.end;
        i++;
    }
    result[idx++] = newInterval;
    
    while (i < intervalsSize) result[idx++] = intervals[i++];
    
    *returnSize = idx;
    return result;
}
```


## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();
        
        while (i < n && intervals[i][1] < newInterval[0]) result.push_back(intervals[i++]);
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i++][1]);
        }
        result.push_back(newInterval);
        while (i < n) result.push_back(intervals[i++]);
        
        return result;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Binary Search + Merge Approach**

### 💡 Algorithm Steps:

1. Use binary search to find insertion point for newInterval start.
2. Use binary search to find all intervals that overlap with newInterval.
3. Merge overlapping intervals efficiently with single pass.
4. Construct result with non-overlapping intervals and merged interval.

```cpp
class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval, 
            [](const vector<int>& a, const vector<int>& b) { return a[1] < b[0]; });
        res.insert(res.end(), intervals.begin(), it);
        
        while (it != intervals.end() && (*it)[0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], (*it)[0]);
            newInterval[1] = max(newInterval[1], (*it)[1]);
            ++it;
        }
        
        res.push_back(newInterval);
        res.insert(res.end(), it, intervals.end());
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(log n + m) - Binary search + merge overlapping intervals
* **Auxiliary Space:** 💾 O(1) - Only constant extra space excluding result

### ✅ **Why This Approach?**

* Efficient for large datasets with few overlaps
* Leverages STL binary search capabilities
* Optimal when overlap region is small

## 📊 **3️⃣ Single Pass Iterator Approach**

### 💡 Algorithm Steps:

1. Use iterators to traverse intervals array once.
2. Copy non-overlapping intervals before newInterval directly.
3. Merge all overlapping intervals in single iteration.
4. Append remaining intervals after merge region.

```cpp
class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        auto it = intervals.begin();
        while (it != intervals.end() && (*it)[1] < newInterval[0]) 
            ans.push_back(*it++);
        
        while (it != intervals.end() && (*it)[0] <= newInterval[1]) {
            newInterval = {min(newInterval[0], (*it)[0]), max(newInterval[1], (*it)[1])};
            ++it;
        }
        ans.push_back(newInterval);
        ans.insert(ans.end(), it, intervals.end());
        
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through all intervals
* **Auxiliary Space:** 💾 O(1) - Constant space excluding result storage

### ✅ **Why This Approach?**

* Memory efficient with iterator usage
* Clean STL integration with insert operations
* Minimal temporary variable usage

## 📊 **4️⃣ In-Place Modification Approach**

### 💡 Algorithm Steps:

1. Find the insertion position and overlapping range in one pass.
2. Merge newInterval with overlapping intervals directly.
3. Use vector erase and insert operations to modify in-place.
4. Return reference to modified original vector.

```cpp
class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int start = 0, end = intervals.size() - 1;
        while (start <= end && intervals[start][1] < newInterval[0]) start++;
        while (end >= start && intervals[end][0] > newInterval[1]) end--;
        
        if (start <= end) {
            newInterval[0] = min(newInterval[0], intervals[start][0]);
            newInterval[1] = max(newInterval[1], intervals[end][1]);
            intervals.erase(intervals.begin() + start, intervals.begin() + end + 1);
        }
        
        intervals.insert(intervals.begin() + start, newInterval);
        return intervals;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear search plus vector operations
* **Auxiliary Space:** 💾 O(1) - Modifies input vector in-place

### ✅ **Why This Approach?**

* Space efficient by reusing input vector
* Good for memory-constrained environments
* Direct manipulation reduces allocation overhead

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Linear Three-Phase**         | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Simple and optimal             | 💾 Requires result array              |
| 🔍 **Binary Search**              | 🟡 O(log n + m)        | 🟡 O(n)                 | 📖 Efficient for sparse overlaps  | 💻 Complex STL usage                |
| 📊 **Iterator Based**             | 🟢 O(n)                | 🟡 O(n)                 | 🎯 Clean STL integration          | 🐌 Iterator overhead                 |
| 🔄 **In-Place**                   | 🟢 O(n)                | 🟢 O(1)                 | ⭐ Memory efficient               | 🔧 Modifies input                   |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General use case, interviews**               | 🥇 **Linear Three-Phase**            | ★★★★★                     |
| 📖 **Large arrays, few overlaps**                 | 🥈 **Binary Search**                 | ★★★★☆                     |
| 🔧 **STL preference, modern C++**                 | 🥉 **Iterator Based**                | ★★★★☆                     |
| 🎯 **Memory constraints**                         | 🏅 **In-Place**                      | ★★★★☆                     |

</details>


## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<int[]> insertInterval(int[][] intervals, int[] newInterval) {
        ArrayList<int[]> result = new ArrayList<>();
        int i = 0;
        while (i < intervals.length && intervals[i][1] < newInterval[0])
            result.add(intervals[i++]);
        
        while (i < intervals.length && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
            newInterval[1] = Math.max(newInterval[1], intervals[i++][1]);
        }
        result.add(newInterval);
        
        while (i < intervals.length) result.add(intervals[i++]);
        
        return result;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def insertInterval(self, intervals, newInterval):
        result = []
        i = 0
        while i < len(intervals) and intervals[i][1] < newInterval[0]:
            result.append(intervals[i])
            i += 1
        
        while i < len(intervals) and intervals[i][0] <= newInterval[1]:
            newInterval[0] = min(newInterval[0], intervals[i][0])
            newInterval[1] = max(newInterval[1], intervals[i][1])
            i += 1
        result.append(newInterval)
        
        while i < len(intervals):
            result.append(intervals[i])
            i += 1
            
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


