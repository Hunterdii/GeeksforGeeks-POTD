---
title: "📏 Longest Bounded-Difference Subarray | GFG Solution 🔍"
keywords🏷️: ["📏 longest subarray", "🔍 sliding window", "📍 two pointers", "🔄 monotonic deque", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Longest Bounded-Difference Subarray problem: find maximum length subarray where absolute difference between any two elements ≤ x using monotonic deque technique. 🚀"
date: 📅 2025-09-28
---

# *28. Longest Bounded-Difference Subarray*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/longest-bounded-difference-subarray/1)

## **🧩 Problem Description**

Given an array of positive integers `arr[]` and a non-negative integer `x`, the task is to find the **longest sub-array** where the **absolute difference between any two elements** is not greater than `x`.

If multiple such subarrays exist, return the one that starts at the **smallest index**.

A subarray is considered valid if for any two elements `arr[i]` and `arr[j]` in the subarray, `|arr[i] - arr[j]| ≤ x`.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [8, 4, 5, 6, 7], x = 3
Output: [4, 5, 6, 7]
Explanation: The sub-array described by index [1..4], i.e. [4, 5, 6, 7]
contains no two elements whose absolute difference is greater than 3.
Max difference = 7 - 4 = 3, which is ≤ x.
```

### Example 2

```cpp
Input: arr[] = [1, 10, 12, 13, 14], x = 2
Output: [12, 13, 14]
Explanation: The sub-array described by index [2..4], i.e. [12, 13, 14]
contains no two elements whose absolute difference is greater than 2.
Max difference = 14 - 12 = 2, which is ≤ x.
```

### Example 3

```cpp
Input: arr[] = [5, 5, 5, 5], x = 0
Output: [5, 5, 5, 5]
Explanation: All elements are identical, so the absolute difference between
any two elements is 0, which satisfies the condition x = 0.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^9$
* $0 \le x \le 10^9$

## **✅ My Approach**

The optimal approach uses the **Sliding Window** technique with **Monotonic Deques** to efficiently track minimum and maximum elements in the current window:

### **Sliding Window + Monotonic Deques**

1. **Initialize Data Structures:**
   * Use two deques: `minQ` (maintains indices in increasing order of values) and `maxQ` (maintains indices in decreasing order of values).
   * Use two pointers: `l` (left boundary) and `r` (right boundary) of the sliding window.
   * Track `maxLen` and `start` position for the result.

2. **Expand Window (Right Pointer):**
   * For each `r`, maintain monotonic property:
     - Remove indices from `minQ` back while `arr[back] >= arr[r]`
     - Remove indices from `maxQ` back while `arr[back] <= arr[r]`
   * Add current index `r` to both deques.

3. **Contract Window (Left Pointer):**
   * While `arr[maxQ.front()] - arr[minQ.front()] > x`:
     - Remove outdated indices from deque fronts if they equal `l`
     - Increment `l` to shrink window from left

4. **Update Result:**
   * After each valid window, update `maxLen` and `start` position if current window is larger.

5. **Return Result:**
   * Extract subarray from `start` to `start + maxLen`.

**Key Insight:** In any subarray, the maximum absolute difference equals `max_element - min_element`. Using monotonic deques allows O(1) access to min/max values in the current window.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. Each element is added and removed from deques at most once, making it linear time.
* **Expected Auxiliary Space Complexity:** O(n), where n is the maximum number of elements that can be stored in the deques in the worst case.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        deque<int> minQ, maxQ;
        int n = arr.size(), l = 0, r = 0, start = 0, len = 0;
        while (r < n) {
            while (!minQ.empty() && arr[minQ.back()] >= arr[r]) minQ.pop_back();
            while (!maxQ.empty() && arr[maxQ.back()] <= arr[r]) maxQ.pop_back();
            minQ.push_back(r);
            maxQ.push_back(r);
            while (arr[maxQ.front()] - arr[minQ.front()] > x) {
                if (l == minQ.front()) minQ.pop_front();
                if (l == maxQ.front()) maxQ.pop_front();
                l++;
            }
            if (r - l + 1 > len) {
                len = r - l + 1;
                start = l;
            }
            r++;
        }
        return vector<int>(arr.begin() + start, arr.begin() + start + len);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Brute Force Nested Loops**

### 💡 Algorithm Steps:

1. For each starting position `i`, iterate through all possible ending positions `j`.
2. Track minimum and maximum values in the current subarray `[i...j]`.
3. If `max - min > x`, break the inner loop as extending further won't be valid.
4. Update the longest valid subarray found so far.
5. Return the subarray with maximum length (prefer smaller starting index).

```cpp
class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size(), maxLen = 0, bestStart = 0;
        for (int i = 0; i < n; i++) {
            int minVal = arr[i], maxVal = arr[i];
            for (int j = i; j < n; j++) {
                minVal = min(minVal, arr[j]);
                maxVal = max(maxVal, arr[j]);
                if (maxVal - minVal > x) break;
                if (j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    bestStart = i;
                }
            }
        }
        return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + maxLen);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Nested loops for each subarray
* **Auxiliary Space:** 💾 O(1) - Only tracking min/max values

### ✅ **Why This Approach?**

* Simple nested loop logic, easy to understand
* No complex data structures needed
* Good for small arrays or when simplicity is preferred

## 📊 **3️⃣ Two Pointer with TreeMap**

### 💡 Algorithm Steps:

1. Use TreeMap to maintain sorted elements in current window.
2. Expand right pointer and add elements to map.
3. Contract left pointer when max-min difference exceeds x.
4. Track maximum window size throughout the process.

```cpp
class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        map<int, int> freq;
        int n = arr.size(), l = 0, start = 0, maxLen = 0;
        for (int r = 0; r < n; r++) {
            freq[arr[r]]++;
            while (freq.rbegin()->first - freq.begin()->first > x) {
                freq[arr[l]]--;
                if (freq[arr[l]] == 0) freq.erase(arr[l]);
                l++;
            }
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start = l;
            }
        }
        return vector<int>(arr.begin() + start, arr.begin() + start + maxLen);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Map operations take log n time
* **Auxiliary Space:** 💾 O(n) - Map storage for unique elements

### ✅ **Why This Approach?**

* Automatically maintains sorted order
* Handles duplicate values naturally
* Clean sliding window implementation

## 📊 **4️⃣ Sparse Table with Binary Search**

### 💡 Algorithm Steps:

1. Precompute sparse table for range min/max queries.
2. For each starting position, binary search for maximum valid length.
3. Use O(1) range queries to check if subarray is valid.
4. Build result from optimal positions found.

```cpp
class Solution {
public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        int n = arr.size(), maxLen = 0, bestStart = 0;
        vector<vector<int>> minSt(n, vector<int>(20));
        vector<vector<int>> maxSt(n, vector<int>(20));
        
        for (int i = 0; i < n; i++) minSt[i][0] = maxSt[i][0] = arr[i];
        
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                minSt[i][j] = min(minSt[i][j-1], minSt[i + (1 << (j-1))][j-1]);
                maxSt[i][j] = max(maxSt[i][j-1], maxSt[i + (1 << (j-1))][j-1]);
            }
        }
        
        auto query = [&](int l, int r) -> pair<int,int> {
            int len = r - l + 1, k = 31 - __builtin_clz(len);
            int minVal = min(minSt[l][k], minSt[r - (1 << k) + 1][k]);
            int maxVal = max(maxSt[l][k], maxSt[r - (1 << k) + 1][k]);
            return {minVal, maxVal};
        };
        
        for (int i = 0; i < n; i++) {
            int left = i, right = n - 1, best = i;
            while (left <= right) {
                int mid = (left + right) / 2;
                auto [minVal, maxVal] = query(i, mid);
                if (maxVal - minVal <= x) {
                    best = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (best - i + 1 > maxLen) {
                maxLen = best - i + 1;
                bestStart = i;
            }
        }
        return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + maxLen);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - Preprocessing + n binary searches
* **Auxiliary Space:** 💾 O(n log n) - Sparse table storage

### ✅ **Why This Approach?**

* Optimal for multiple queries
* O(1) range min/max queries
* Efficient for large datasets

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Monotonic Queue**            | 🟢 O(n)                | 🟢 O(n)                 | 🚀 Optimal linear time            | 🔧 Complex deque management           |
| 🔍 **Brute Force Nested**         | 🔴 O(n²)               | 🟢 O(1)                 | 📖 Simple to understand & code    | 🐌 Quadratic time, slow for large n  |
| 📊 **TreeMap Sliding**           | 🟡 O(n log n)          | 🟡 O(n)                 | 🎯 Clean sliding window           | 🔧 Map overhead                       |
| 🔄 **Sparse Table**              | 🟡 O(n log n)          | 🟡 O(n log n)           | ⭐ O(1) range queries             | 💾 High space complexity             |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Single query optimal**                       | 🥇 **Monotonic Queue**               | ★★★★★                     |
| 📖 **Learning/Educational purposes**              | 🥈 **Brute Force Nested**            | ★★★☆☆                     |
| 🔧 **Duplicate handling**                         | 🥉 **TreeMap Sliding**               | ★★★★☆                     |
| 🎯 **Multiple queries**                           | 🏅 **Sparse Table**                  | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<Integer> longestSubarray(int[] arr, int x) {
        ArrayDeque<Integer> minQ = new ArrayDeque<>(), maxQ = new ArrayDeque<>();
        int n = arr.length, l = 0, start = 0, maxLen = 0;
        for (int r = 0; r < n; r++) {
            while (!minQ.isEmpty() && arr[minQ.peekLast()] >= arr[r]) minQ.removeLast();
            while (!maxQ.isEmpty() && arr[maxQ.peekLast()] <= arr[r]) maxQ.removeLast();
            minQ.addLast(r);
            maxQ.addLast(r);
            while (arr[maxQ.peekFirst()] - arr[minQ.peekFirst()] > x) {
                if (l == minQ.peekFirst()) minQ.removeFirst();
                if (l == maxQ.peekFirst()) maxQ.removeFirst();
                l++;
            }
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start = l;
            }
        }
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = start; i < start + maxLen; i++) result.add(arr[i]);
        return result;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def longestSubarray(self, arr, x):
        from collections import deque
        minQ, maxQ = deque(), deque()
        n, l, start, maxLen = len(arr), 0, 0, 0
        for r in range(n):
            while minQ and arr[minQ[-1]] >= arr[r]: minQ.pop()
            while maxQ and arr[maxQ[-1]] <= arr[r]: maxQ.pop()
            minQ.append(r)
            maxQ.append(r)
            while arr[maxQ[0]] - arr[minQ[0]] > x:
                if l == minQ[0]: minQ.popleft()
                if l == maxQ[0]: maxQ.popleft()
                l += 1
            if r - l + 1 > maxLen:
                maxLen = r - l + 1
                start = l
        return arr[start:start + maxLen]
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


