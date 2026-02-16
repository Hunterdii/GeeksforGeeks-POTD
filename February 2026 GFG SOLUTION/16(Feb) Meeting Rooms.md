---
title: "📅 Meeting Rooms | GFG Solution 🔍"
keywords🏷️: ["📅 meeting rooms", "🔍 interval scheduling", "📍 sorting", "⏰ time intervals", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Meeting Rooms problem: check if a person can attend all meetings without overlap using interval sorting and conflict detection. 🚀"
date: 📅 2025-02-16
---

# *16. Meeting Rooms*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/attend-all-meetings/1)

## **🧩 Problem Description**

Given a 2D array `arr[][]`, where `arr[i][0]` is the starting time of the ith meeting and `arr[i][1]` is the ending time of the ith meeting, the task is to check if it is possible for a person to attend all the meetings such that he can attend only one meeting at a particular time.

**Note:** A person can attend a meeting if its starting time is greater than or equal to the previous meeting's ending time.

## **📘 Examples**

### Example 1

```cpp
Input: arr[][] = [[1, 4], [10, 15], [7, 10]]
Output: true
Explanation: Since all the meetings are held at different times, it is possible to attend all the meetings.
```

### Example 2

```cpp
Input: arr[][] = [[2, 4], [9, 12], [6, 10]]
Output: false
Explanation: Since the second and third meeting overlap, a person cannot attend all the meetings.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $0 \le \text{arr}[i] \le 2 \times 10^6$

## **✅ My Approach**

The optimal approach uses **Interval Sorting** to efficiently detect meeting conflicts:

### **Sorting-Based Conflict Detection**

1. **Sort Meetings:**
   * Sort all meetings by their start times in ascending order.
   * This brings potentially conflicting meetings adjacent to each other.

2. **Check Adjacent Meetings:**
   * Iterate through the sorted meetings from index 1 to n-1.
   * For each meeting, compare its start time with the previous meeting's end time.

3. **Detect Overlap:**
   * If current meeting's start time is less than previous meeting's end time, there's an overlap.
   * Return false immediately as the person cannot attend both meetings.

4. **All Meetings Compatible:**
   * If no overlaps are found after checking all adjacent pairs, return true.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the number of meetings. The sorting operation dominates the time complexity, while the linear scan through sorted meetings takes O(n) time.
* **Expected Auxiliary Space Complexity:** O(1), as we only use constant extra space for iteration variables. The sorting is done in-place, requiring no additional data structures beyond the input array.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    bool canAttend(vector<vector<int>> &arr) {
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++)
            if (arr[i - 1][1] > arr[i][0]) return false;
        return true;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ End-Time Sorting Approach**

### 💡 Algorithm Steps:

1. Sort meetings by their end times instead of start times.
2. Track when the last meeting ended using a variable.
3. For each meeting, check if it starts before the previous meeting ends.
4. If any meeting starts before the previous one ends, return false indicating an overlap.

```cpp
class Solution {
public:
    bool canAttend(vector<vector<int>> &arr) {
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) { return a[1] < b[1]; });
        for (int i = 1; i < arr.size(); i++)
            if (arr[i][0] < arr[i - 1][1]) return false;
        return true;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting dominates the time complexity
* **Auxiliary Space:** 💾 O(1) - Only constant extra space for sorting

### ✅ **Why This Approach?**

* Works equally well for interval scheduling problems
* Useful when optimizing for maximum meetings attended
* Different perspective on the same problem

## 📊 **3️⃣ Explicit End-Time Tracking**

### 💡 Algorithm Steps:

1. Sort intervals by start time using default comparison.
2. Handle edge case: if less than 2 meetings, always return true.
3. Store the end time of the first meeting in a variable.
4. Iterate through remaining meetings checking if start time conflicts with stored end time.
5. Update the end time variable after each successful check.

```cpp
class Solution {
public:
    bool canAttend(vector<vector<int>> &arr) {
        if (arr.size() < 2) return true;
        sort(arr.begin(), arr.end());
        int end = arr[0][1];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i][0] < end) return false;
            end = arr[i][1];
        }
        return true;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting operation dominates
* **Auxiliary Space:** 💾 O(1) - Constant space with single variable tracking

### ✅ **Why This Approach?**

* Tracks end time explicitly for clarity
* Avoids repeated array access in loop
* Slight optimization in memory access patterns


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Start-Time Sort**            | 🟢 O(n log n)          | 🟢 O(1)                 | 🚀 Optimal & intuitive            | 🔧 Modifies input order              |
| 🔍 **End-Time Sort**              | 🟢 O(n log n)          | 🟢 O(1)                 | 📖 Alternative perspective        | 🔧 Custom comparator needed          |
| 📊 **Explicit Tracking**          | 🟢 O(n log n)          | 🟢 O(1)                 | 🎯 Clear state management         | 🔧 Slightly more code                |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General use & interviews**                       | 🥇 **Start-Time Sort**               | ★★★★★                     |
| 📖 **Scheduling optimization problems**               | 🥈 **End-Time Sort**                 | ★★★★★                     |
| 🎯 **Clear state management**                         | 🏅 **Explicit Tracking**             | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    static boolean canAttend(int[][] arr) {
        Arrays.sort(arr, (a, b) -> a[0] - b[0]);
        for (int i = 1; i < arr.length; i++)
            if (arr[i - 1][1] > arr[i][0]) return false;
        return true;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def canAttend(self, arr):
        arr.sort()
        for i in range(1, len(arr)):
            if arr[i - 1][1] > arr[i][0]: return False
        return True
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
