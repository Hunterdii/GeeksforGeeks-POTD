---
title: "🔢 Longest Subarray with At Most Two Distinct Integers | GFG Solution 🎯"
keywords🏷️: ["🔢 longest subarray", "🔍 sliding window", "📊 two pointers", "📈 hash map", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Longest Subarray with At Most Two Distinct Integers: find maximum length subarray containing at most 2 distinct elements using sliding window technique. 🚀"
date: 📅 2025-03-03
---

# *03. Longest Subarray with At Most Two Distinct Integers*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1)

## **🧩 Problem Description**

Given an array `arr[]` consisting of positive integers, your task is to find the length of the **longest subarray** that contains **at most two distinct integers**.

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

The optimal approach uses the **Sliding Window** technique with a **Hash Map**:

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

**Key Insight:** The sliding window maintains at most 2 distinct elements. When a third element appears, we shrink from the left until we're back to 2 distinct elements.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. Each element is visited at most twice (once by right pointer and once by left pointer during window shrinking).
* **Expected Auxiliary Space Complexity:** O(1), as the hash map stores at most 3 elements at any time (2 valid + 1 being removed), which is constant space regardless of input size.

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

1. Track two most recent distinct elements and their last seen positions.
2. When a third element appears, calculate current window length.
3. Update window start based on which element appeared earlier.
4. Track maximum window length throughout.

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

* **Time:** ⏱️ O(n) - Single pass through array
* **Auxiliary Space:** 💾 O(1) - Constant space with only variables

### ✅ **Why This Approach?**

* Optimal space complexity with O(1) memory
* No hash map overhead
* Efficient for tracking exactly 2 distinct elements

## 📊 **3️⃣ Brute Force Approach**

### 💡 Algorithm Steps:

1. Try all possible subarrays starting from each position.
2. For each subarray, track distinct elements using a set.
3. If distinct count ≤ 2, update maximum length.
4. Return the maximum length found.

```cpp
class Solution {
public:
    int totalElements(vector<int> &arr) {
        int n = arr.size(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> s;
            for (int j = i; j < n; j++) {
                s.insert(arr[j]);
                if (s.size() <= 2)
                    maxLen = max(maxLen, j - i + 1);
                else
                    break;
            }
        }
        return maxLen;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Nested loops for all subarrays
* **Auxiliary Space:** 💾 O(1) - Set size bounded by 3 elements

### ✅ **Why This Approach?**

* Simple and straightforward
* Easy to understand conceptually
* Good for small arrays

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110/1120 test cases due to time constraints).


## 📊 **4️⃣ Ordered Map Approach**

### 💡 Algorithm Steps:

1. Use ordered map (map in C++) for automatic key ordering.
2. Apply sliding window technique with map.
3. Shrink window when map size exceeds 2.
4. Track maximum window size.

```cpp
class Solution {
public:
    int totalElements(vector<int> &arr) {
        map<int, int> mp;
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

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log 2) ≈ O(n) - Map operations with at most 2 elements
* **Auxiliary Space:** 💾 O(1) - Map size bounded by 2-3 elements

### ✅ **Why This Approach?**

* Maintains sorted order of keys
* Useful when order matters
* Clean implementation with STL

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Sliding Window + HashMap**   | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal and clean              | 🔧 Hash map overhead                 |
| 🔄 **Two Variable Tracking**      | 🟢 O(n)                | 🟢 O(1)                 | ⚡ Fastest, no hash map           | 🔧 Complex logic                     |
| 📊 **Brute Force**                | 🔴 O(n²)               | 🟢 O(1)                 | 📖 Easy to understand             | 🐌 Quadratic time                    |
| 🗂️ **Ordered Map**                | 🟢 O(n)                | 🟢 O(1)                 | 🎯 Maintains key order            | 🔧 Slightly slower than unordered    |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Sliding Window + HashMap**      | ★★★★★                     |
| 💾 **Minimal memory usage**                           | 🥈 **Two Variable Tracking**         | ★★★★★                     |
| 📖 **Learning/Understanding**                         | 🥉 **Brute Force**                   | ★★★☆☆                     |
| 🎯 **Need sorted keys**                               | 🏅 **Ordered Map**                   | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int totalElements(int[] arr) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        int i = 0, maxLen = 0;
        for (int j = 0; j < arr.length; j++) {
            mp.put(arr[j], mp.getOrDefault(arr[j], 0) + 1);
            while (mp.size() > 2) {
                mp.put(arr[i], mp.get(arr[i]) - 1);
                if (mp.get(arr[i]) == 0) mp.remove(arr[i]);
                i++;
            }
            maxLen = Math.max(maxLen, j - i + 1);
        }
        return maxLen;
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
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" alt="Visitor counter" />
</p>
