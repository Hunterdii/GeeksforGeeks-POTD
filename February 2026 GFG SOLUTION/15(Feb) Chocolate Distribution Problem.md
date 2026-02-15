---
title: "🍫 Chocolate Distribution Problem | GFG Solution 🎯"
keywords🏷️: ["🍫 chocolate distribution", "🔍 sliding window", "📊 sorting", "📈 greedy algorithm", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Chocolate Distribution Problem: minimize the difference between maximum and minimum chocolates distributed using sorting and sliding window technique. 🚀"
date: 📅 2025-02-15
---

# *15. Chocolate Distribution Problem*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1)

## **🧩 Problem Description**

You are given an array `arr[]` of positive integers, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are `m` students. Your task is to distribute chocolate packets among `m` students such that:
- Each student gets **exactly one packet**.
- The **difference** between the maximum number of chocolates given to a student and the minimum number of chocolates given to a student is **minimized**.

Return that minimum possible difference.

## **📘 Examples**

### Example 1

```cpp
Input: arr = [3, 4, 1, 9, 56, 7, 9, 12], m = 5
Output: 6
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 
by choosing following m packets: [3, 4, 9, 7, 9].
```

### Example 2

```cpp
Input: arr = [7, 3, 2, 4, 9, 12, 56], m = 3
Output: 2
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 4 - 2 = 2 
by choosing following m packets: [3, 2, 4].
```

### Example 3

```cpp
Input: arr = [3, 4, 1, 9, 56], m = 5
Output: 55
Explanation: With 5 packets for 5 students, each student will receive one packet, 
so the difference is 56 - 1 = 55.
```

## **🔒 Constraints**

* $1 \le m \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^9$

## **✅ My Approach**

The optimal approach uses **Sorting** combined with a **Sliding Window** technique to efficiently find the minimum difference:

### **Sorting + Sliding Window**

1. **Sort the Array:**
   * First, sort the array in ascending order.
   * This groups similar values together, making it easier to find contiguous packets with minimal difference.

2. **Initialize Variables:**
   * Set `res = INT_MAX` to track the minimum difference.
   * We need to select exactly `m` consecutive packets from the sorted array.

3. **Sliding Window Iteration:**
   * Iterate through all possible windows of size `m` in the sorted array.
   * For each window starting at index `i`, the window spans from `i` to `i + m - 1`.
   * The difference for this window is `arr[i + m - 1] - arr[i]` (max - min in the window).

4. **Update Minimum:**
   * Update `res` with the minimum of current `res` and the calculated difference.

5. **Return Result:**
   * After checking all valid windows, return `res` as the answer.

**Key Insight:** After sorting, any selection of `m` packets will have the minimum difference when they are consecutive in the sorted array. This is because sorting ensures that consecutive elements have the smallest possible gaps.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the size of the array. The sorting step dominates with O(n log n) complexity, while the sliding window traversal takes O(n) time.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables like `res` and loop counters. The sorting is done in-place in most implementations.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        sort(a.begin(), a.end());
        int res = INT_MAX;
        for (int i = 0; i + m <= a.size(); i++)
            res = min(res, a[i + m - 1] - a[i]);
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Optimized Single Pass After Sorting**

### 💡 Algorithm Steps:

1. Sort the array to enable window-based comparison.
2. Initialize the result with the difference of the first window of size m.
3. Iterate through remaining elements, updating the minimum difference incrementally.
4. This reduces redundant comparisons by starting with a valid initial window.

```cpp
class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        sort(a.begin(), a.end());
        int res = a[m - 1] - a[0];
        for (int i = m; i < a.size(); i++)
            res = min(res, a[i] - a[i - m + 1]);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting dominates the complexity
* **Auxiliary Space:** 💾 O(1) - Only constant extra space

### ✅ **Why This Approach?**

* Slightly cleaner iteration pattern
* Avoids initial INT_MAX comparison
* More intuitive window sliding visualization

## 📊 **3️⃣ Two Pointer Technique**

### 💡 Algorithm Steps:

1. Sort the array to group similar chocolate counts together.
2. Use two pointers: `left` at index 0 and `right` at index m-1 to define the window.
3. Calculate the initial difference and track it as minimum.
4. Slide both pointers forward together, maintaining window size m.
5. Update minimum difference for each new window position.

```cpp
class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        int n = a.size();
        if (m > n) return -1;
        sort(a.begin(), a.end());
        int left = 0, right = m - 1, res = INT_MAX;
        while (right < n) {
            res = min(res, a[right] - a[left]);
            left++; right++;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Sorting step required
* **Auxiliary Space:** 💾 O(1) - No extra data structures

### ✅ **Why This Approach?**

* Crystal clear window movement visualization
* Easy to explain in interviews
* Minimal variables with explicit pointer semantics

## 📊 **4️⃣ Range-Based For Loop**

### 💡 Algorithm Steps:

1. Sort the array for optimal packet grouping.
2. Use range-based iteration with proper boundary checking.
3. Calculate differences for all valid m-sized windows.
4. Track and return the minimum difference found.

```cpp
class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        int n = a.size();
        sort(a.begin(), a.end());
        int ans = INT_MAX;
        for (int i = 0; i <= n - m; i++)
            ans = min(ans, a[i + m - 1] - a[i]);
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Dominated by sorting
* **Auxiliary Space:** 💾 O(1) - Constant space only

### ✅ **Why This Approach?**

* Clean boundary condition checking (i <= n - m)
* Prevents out-of-bounds access explicitly
* Modern C++ style with clear intent

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Direct Sliding Window**      | 🟢 O(n log n)          | 🟢 O(1)                 | 🚀 Most concise code              | 🔧 Requires careful boundary handling |
| 🔄 **Optimized Single Pass**      | 🟢 O(n log n)          | 🟢 O(1)                 | 📊 Cleaner iteration              | 🔧 Similar complexity                |
| 👉 **Two Pointer**                | 🟢 O(n log n)          | 🟢 O(1)                 | 📖 Excellent for visualization    | 🔧 Extra pointer variable            |
| 🔍 **Range-Based Loop**           | 🟢 O(n log n)          | 🟢 O(1)                 | ⭐ Clear boundary conditions      | 🔧 No significant advantage          |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Competitive programming**                        | 🥇 **Direct Sliding Window**         | ★★★★★                     |
| 📖 **Interview clarity**                              | 🥈 **Two Pointer**                   | ★★★★★                     |
| 🔧 **Production code**                                | 🥉 **Optimized Single Pass**         | ★★★★☆                     |
| 🎯 **Teaching/Learning**                              | 🏅 **Range-Based Loop**              | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int findMinDiff(ArrayList<Integer> a, int m) {
        Collections.sort(a);
        int res = Integer.MAX_VALUE;
        for (int i = 0; i + m <= a.size(); i++)
            res = Math.min(res, a.get(i + m - 1) - a.get(i));
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def findMinDiff(self, a, m):
        a.sort()
        return min(a[i + m - 1] - a[i] for i in range(len(a) - m + 1))
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
