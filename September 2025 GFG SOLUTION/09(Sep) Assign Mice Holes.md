---
title: "🐭 Assign Mice Holes | GFG Solution 🕳️"
keywords🏷️: ["🐭 mice assignment", "🔍 greedy algorithm", "📊 sorting", "📈 optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Assign Mice Holes problem: find optimal assignment to minimize maximum time using greedy approach with sorting. 🚀"
date: 📅 2025-09-09
---

# *09. Assign Mice Holes*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/assign-mice-holes3053/1)

## **🧩 Problem Description**

You are given two arrays `mices[]` and `holes[]` of the same size. The array `mices[]` represents the positions of the mice on a straight line, while the array `holes[]` represents the positions of the holes on the same line. Each hole can accommodate exactly one mouse. 

A mouse can either stay in its current position, move one step to the right, or move one step to the left, and each move takes one minute. The task is to assign each mouse to a distinct hole in such a way that the time taken by the last mouse to reach its hole is minimized.

## **📘 Examples**

### Example 1

```cpp
Input: mices[] = [4, -4, 2], holes[] = [4, 0, 5]
Output: 4
Explanation: Assign the mouse at position 4 to the hole at position 4, so the time taken is 0 minutes. 
Assign the mouse at position −4 to the hole at position 0, so the time taken is 4 minutes. 
Assign the mouse at position 2 to the hole at position 5, so the time taken is 3 minutes. 
Hence, the maximum time required by any mouse is 4 minutes.
```

### Example 2

```cpp
Input: mices[] = [1, 2], holes[] = [20, 10]
Output: 18
Explanation: Assign the mouse at position 1 to the hole at position 10, so the time taken is 9 minutes. 
Assign the mouse at position 2 to the hole at position 20, so the time taken is 18 minutes. 
Hence, the maximum time required by any mouse is 18 minutes.
```

## **🔒 Constraints**

* $1 \le \text{mices.size()} = \text{holes.size()} \le 10^5$
* $-10^5 \le \text{mices}[i], \text{holes}[i] \le 10^5$

## **✅ My Approach**

The optimal approach uses a **Greedy Algorithm** with **Sorting** to achieve the minimum maximum time:

### **Greedy Sorting Strategy**

1. **Sort Both Arrays:**
   * Sort the `mices[]` array in ascending order.
   * Sort the `holes[]` array in ascending order.

2. **Greedy Assignment:**
   * Assign the i-th smallest mouse position to the i-th smallest hole position.
   * This ensures that mice don't "cross over" each other, which would increase travel time.

3. **Calculate Maximum Time:**
   * For each mouse-hole pair, calculate the absolute difference (travel time).
   * Track the maximum time among all assignments.

4. **Mathematical Proof:**
   * If we have sorted positions and try to swap any two assignments, it will either keep the same maximum time or increase it.
   * This greedy approach guarantees the optimal solution.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the size of the arrays. The sorting operations dominate the complexity, while the linear traversal to find maximum difference takes O(n) time.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables. The sorting is done in-place.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int assignHole(vector<int>& m, vector<int>& h) {
        sort(m.begin(), m.end());
        sort(h.begin(), h.end());
        int r = 0;
        for (int i = 0; i < m.size(); ++i) 
            r = max(r, abs(m[i] - h[i]));
        return r;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ STL Transform Approach**

### 💡 Algorithm Steps:

1. Sort both arrays to enable optimal greedy assignment.
2. Use STL transform to compute differences in a single pass.
3. Find maximum element using max_element iterator.
4. Return the maximum time required for any mouse.

```cpp
class Solution {
public:
    int assignHole(vector<int>& mice, vector<int>& holes) {
        sort(mice.begin(), mice.end());
        sort(holes.begin(), holes.end());
        vector<int> diff(mice.size());
        transform(mice.begin(), mice.end(), holes.begin(), diff.begin(),
                 [](int m, int h) { return abs(m - h); });
        return *max_element(diff.begin(), diff.end());
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting dominates the complexity
* **Auxiliary Space:** 💾 O(n) - Additional vector for differences

### ✅ **Why This Approach?**

* Functional programming style with STL algorithms
* Clear separation of computation steps
* Good for code readability and maintainability

## 📊 **3️⃣ Iterator-Based Approach**

### 💡 Algorithm Steps:

1. Sort both containers using iterators for flexibility.
2. Use iterator pairs to traverse both arrays simultaneously.
3. Track maximum difference without storing intermediate results.
4. Return the maximum time in a single traversal pass.

```cpp
class Solution {
public:
    int assignHole(vector<int>& mice, vector<int>& holes) {
        sort(mice.begin(), mice.end());
        sort(holes.begin(), holes.end());
        int maxTime = 0;
        auto m = mice.begin(), h = holes.begin();
        while (m != mice.end()) {
            maxTime = max(maxTime, abs(*m++ - *h++));
        }
        return maxTime;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Due to sorting operations
* **Auxiliary Space:** 💾 O(1) - Only iterator variables used

### ✅ **Why This Approach?**

* Iterator-based design for generic programming
* Memory efficient with constant space usage
* Demonstrates advanced C++ iterator concepts

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Direct Comparison**          | 🟢 O(n log n)          | 🟢 O(1)                 | 🚀 Optimal space, simple          | 📖 Basic implementation              |
| 🔍 **STL Transform**              | 🟢 O(n log n)          | 🟡 O(n)                 | 📊 Functional style               | 💾 Extra space for differences       |
| 📊 **Iterator-Based**             | 🟢 O(n log n)          | 🟢 O(1)                 | 🎯 Generic programming            | 🔧 More complex syntax               |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Competitive Programming**                       | 🥇 **Direct Comparison**             | ★★★★★                     |
| 📖 **Code Readability**                              | 🥈 **STL Transform**                 | ★★★★☆                     |
| 🔧 **Generic Programming**                           | 🥉 **Iterator-Based**               | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int assignHole(int[] m, int[] h) {
        Arrays.sort(m);
        Arrays.sort(h);
        int r = 0;
        for (int i = 0; i < m.length; i++)
            r = Math.max(r, Math.abs(m[i] - h[i]));
        return r;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def assignHole(self, m, h):
        m.sort()
        h.sort()
        return max(abs(a - b) for a, b in zip(m, h))
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






