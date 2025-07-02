---
title: "🔢 Longest Subarray with At Most Two Distinct Integers | GFG Solution 🔍"
keywords🏷️: ["🔢 longest subarray", "🔍 sliding window", "📍 two pointers", "📈 hash map", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Longest Subarray with At Most Two Distinct Integers problem: find maximum length subarray containing at most 2 distinct elements using sliding window technique. 🚀"
date: 📅 2025-07-02
---

# *02. Longest Subarray with At Most Two Distinct Integers*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1)

## **🧩 Problem Description**

You are given an array `arr[]` consisting of positive integers. Your task is to find the length of the **longest subarray** that contains **at most two distinct integers**.

A subarray is a contiguous sequence of elements within an array. The goal is to find the maximum possible length of such a subarray where the number of unique elements does not exceed 2.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [2, 1, 2]
Output: 3
Explanation: The entire array [2, 1, 2] contains at most two distinct integers (2 and 1).
Hence, the length of the longest subarray is 3.
```

### Example 2

```cpp
Input: arr[] = [3, 1, 2, 2, 2, 2]
Output: 5
Explanation: The longest subarray containing at most two distinct integers is [1, 2, 2, 2, 2],
which has a length of 5.
```

### Example 3

```cpp
Input: arr[] = [1, 1, 1, 1]
Output: 4
Explanation: The entire array contains only one distinct integer (1), which satisfies 
the condition of at most two distinct integers.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^5$

## **✅ My Approach**

The optimal approach uses the **Sliding Window** technique with a **Hash Map** to efficiently track distinct elements and their frequencies:

### **Sliding Window + Hash Map**

1. **Initialize Variables:**
   * Use two pointers: `left` (start of window) and `right` (end of window).
   * Maintain a hash map to store frequency of elements in current window.
   * Track `maxLength` to store the result.

2. **Expand Window:**
   * Move `right` pointer and add `arr[right]` to the hash map.
   * Increment its frequency.

3. **Contract Window:**
   * If hash map size exceeds 2 (more than 2 distinct elements), shrink window from left.
   * Decrement frequency of `arr[left]` and remove it if frequency becomes 0.
   * Move `left` pointer forward.

4. **Update Result:**
   * After each valid window, update `maxLength` with current window size.

5. **Continue Until End:**
   * Repeat until `right` pointer reaches the end of array.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. Each element is visited at most twice (once by right pointer and once by left pointer).
* **Expected Auxiliary Space Complexity:** O(k), where k is the number of distinct elements in the current window. In the worst case, k ≤ 2, so effectively O(1) additional space.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int totalElements(vector<int> &arr) {
        unordered_map<int, int> mp;
        int i = 0, maxLen = 0;
        for (int j = 0; j < arr.size(); j++) {
            mp[arr[j]]++;
            while (mp.size() > 2) {
                if (--mp[arr[i]] == 0) mp.erase(arr[i]);
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Two Variable Tracking Approach**

### 💡 Algorithm Steps:

1. Initialize two variables `first` and `second` to represent the two distinct numbers allowed in the window, and `firstIdx`, `secondIdx` to store their most recent positions.
2. Traverse the array with a right pointer:
   * If the current element equals `first` or `second`, update the corresponding index.
   * If a third new element appears:
     * Determine which of the two existing numbers appeared earlier (minimum of `firstIdx` and `secondIdx`).
     * Move the left pointer just past that index to ensure only two distinct elements remain.
     * Replace the older number (`first` or `second`) with the new element and update its index.
3. Update the maximum length after each iteration.

```cpp
class Solution {
public:
    int totalElements(vector<int> &arr) {
        int n = arr.size(), maxLen = 0, left = 0;
        int first = -1, second = -1, firstIdx = -1, secondIdx = -1;
        for (int right = 0; right < n; right++) {
            if (arr[right] == first) firstIdx = right;
            else if (arr[right] == second) secondIdx = right;
            else if (first == -1) first = arr[right], firstIdx = right;
            else if (second == -1) second = arr[right], secondIdx = right;
            else {
                left = min(firstIdx, secondIdx) + 1;
                if (firstIdx < secondIdx) first = arr[right], firstIdx = right;
                else second = arr[right], secondIdx = right;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(1) - Constant space

### ✅ **Why This Approach?**

* Optimal space complexity with O(1) memory usage.
* No hash map overhead, direct variable tracking.
* Efficient for small distinct element tracking.

## 📊 **3️⃣ Frequency Array Optimization**

### 💡 Algorithm Steps:

1. Use a frequency array (e.g., `freq[100001]`) assuming all elements fall within a known small integer range.
2. Initialize variables: `left = 0`, `distinctCount = 0`, `maxLen = 0`.
3. Traverse using a right pointer:
   * If `arr[right]` is added to the window for the first time (`freq[arr[right]] == 0`), increment `distinctCount`.
   * Increase the count for `arr[right]`.
4. If `distinctCount > 2`, shrink the window:
   * Decrease the count of `arr[left]`.
   * If its count becomes 0, decrement `distinctCount`.
   * Move `left` forward.
5. At each iteration, update `maxLen` as the maximum valid window size.

```cpp
class Solution {
public:
    int totalElements(vector<int> &arr) {
        vector<int> freq(100001, 0);
        int distinctCount = 0, left = 0, maxLen = 0;
        for (int right = 0; right < arr.size(); right++) {
            if (freq[arr[right]]++ == 0) distinctCount++;
            while (distinctCount > 2) {
                if (--freq[arr[left]] == 0) distinctCount--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(k) where k = range of elements

### ✅ **Why This Approach?**

* Faster than hash map for known small ranges.
* Cache-friendly array access pattern.
* No need for key-value mapping—constant-time operations.

## 📊 **4️⃣ STL Set-Based Tracking**

### 💡 Algorithm Steps:

1. Use an `unordered_map<int, int>` to store frequency of elements and a `unordered_set<int>` to track the number of unique elements in the current window.
2. Initialize `left = 0`, `maxLen = 0`.
3. Traverse using a right pointer:
   * Add `arr[right]` to the map and insert into the set.
4. If the set size exceeds 2 (more than 2 distinct elements), shrink the window:
   * Decrease count of `arr[left]`.
   * If the count becomes 0, remove it from the set.
   * Move the `left` pointer forward.
5. At each step, update `maxLen` with the current valid window size.

```cpp
class Solution {
public:
    int totalElements(vector<int> &arr) {
        unordered_map<int, int> freq;
        unordered_set<int> distinct;
        int left = 0, maxLen = 0;
        for (int right = 0; right < arr.size(); right++) {
            freq[arr[right]]++;
            distinct.insert(arr[right]);
            while (distinct.size() > 2) {
                if (--freq[arr[left]] == 0) {
                    distinct.erase(arr[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(n)

### ✅ **Why This Approach?**

* Clear separation of concerns with set and map.
* Easy to trace which elements are currently active.
* Good for debugging and understanding logic flow.

## 5️⃣ 📝 **Ordered Map Sliding Window**

### 💡 Algorithm Steps:

1. Use a `std::map<int, int>` (ordered map) to count the elements within the sliding window.
2. Expand the window to the right by moving pointer `j`; increase the count for `a[j]`.
3. If the map contains more than 2 distinct elements, shrink the window from the left:
   * Decrement the count for `a[i]`.
   * If the count becomes 0, erase the element from the map.
4. Track the maximum window size during each iteration.

```cpp
class Solution {
public:
    int totalElements(vector<int>& a) {
        map<int,int> mp;
        int i = 0, res = 0;
        for (int j = 0; j < a.size(); ++j) {
            ++mp[a[j]];
            while (mp.size() > 2) {
                if (--mp[a[i]] == 0) mp.erase(a[i]);
                ++i;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log k), where k ≤ 2 here
* **Auxiliary Space:** 💾 O(k)

### ✅ **Why This Approach?**

* Maintains ordering automatically with `std::map`.
* Shrinks window cleanly using count + erase.
* Good readability and debugging via sorted structure.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Hash Map Sliding Window**    | 🟢 O(n)                | 🟡 O(k)                 | ⚡ Clean code, general solution   | 💾 Hash map overhead                 |
| 🔄 **Two Variable Tracking**      | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal space, fastest runtime | 🧮 Complex logic, harder to debug    |
| 🔺 **Frequency Array**            | 🟢 O(n)                | 🟡 O(range)             | ⚡ Cache-friendly, fast access    | 💾 Limited to known small ranges     |
| 🔑 **STL Set-Based**              | 🟢 O(n)                | 🟡 O(n)                 | 🔧 Clear logic, STL optimized     | 💾 Extra space for set structure     |
| ⏰ **Ordered Map Sliding Window** | 🟡 O(n log k)          | 🟢 O(1)                 | 🚀 Predictable, no hash collisions | 💾 Slightly slower per op     |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**    | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------- | ------------------------- |
| ⚡ **Maximum performance, competitive programming**    | 🥇 **Two Variable Tracking**   | ★★★★★                     |
| 🔧 **Production code, readability important**         | 🥈 **Hash Map Sliding Window** | ★★★★☆                     |
| 📊 **Known small element range**                      | 🥉 **Frequency Array**         | ★★★★☆                     |
| 🎯 **Educational purposes, clear logic**               | 🎖️ **STL Set-Based**           | ★★★☆☆                     |
| 📚 **Readability / simplicity**                    | 🏅 **Ordered Map Sliding Window**   | ★★★★☆              |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int totalElements(int[] arr) {
        Map<Integer, Integer> map = new HashMap<>();
        int i = 0, max = 0;
        for (int j = 0; j < arr.length; j++) {
            map.put(arr[j], map.getOrDefault(arr[j], 0) + 1);
            while (map.size() > 2) {
                map.put(arr[i], map.get(arr[i]) - 1);
                if (map.get(arr[i]) == 0) map.remove(arr[i]);
                i++;
            }
            max = Math.max(max, j - i + 1);
        }
        return max;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def totalElements(self, arr):
        mp = {}
        i = maxLen = 0
        for j in range(len(arr)):
            mp[arr[j]] = mp.get(arr[j], 0) + 1
            while len(mp) > 2:
                mp[arr[i]] -= 1
                if mp[arr[i]] == 0:
                    del mp[arr[i]]
                i += 1
            maxLen = max(maxLen, j - i + 1)
        return maxLen
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








