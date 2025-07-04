---
title: "🔢 Subarrays With At Most K Distinct Integers | GFG Solution 🔍"
keywords🏷️: ["🔢 subarrays", "🔍 sliding window", "📍 two pointers", "📈 hash map", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Subarrays With At Most K Distinct Integers problem: count subarrays containing at most k distinct elements using sliding window technique. 🚀"
date: 📅 2025-07-04
---

# *04. Subarrays With At Most K Distinct Integers*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/subarrays-with-at-most-k-distinct-integers/1)

## **🧩 Problem Description**

You are given an array `arr[]` of positive integers and an integer `k`. Your task is to find the number of **subarrays** in `arr[]` where the count of distinct integers is **at most k**.

A subarray is a contiguous part of an array. The goal is to efficiently count all valid subarrays without generating them explicitly.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 2, 2, 3], k = 2
Output: 9
Explanation: Subarrays with at most 2 distinct elements are: [1], [2], [2], [3], [1, 2], [2, 2], [2, 3], [1, 2, 2] and [2, 2, 3].
```

### Example 2

```cpp
Input: arr[] = [1, 1, 1], k = 1
Output: 6
Explanation: Subarrays with at most 1 distinct element are: [1], [1], [1], [1, 1], [1, 1] and [1, 1, 1].
```

### Example 3

```cpp
Input: arr[] = [1, 2, 1, 1, 3, 3, 4, 2, 1], k = 2
Output: 24
Explanation: There are 24 subarrays with at most 2 distinct elements.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 2 \times 10^4$
* $1 \le k \le 2 \times 10^4$
* $1 \le \text{arr}[i] \le 10^9$

## **✅ My Approach**

The optimal approach uses the **Sliding Window** technique with a **Hash Map** to efficiently count subarrays with at most k distinct elements:

### **Sliding Window + Hash Map**

1. **Initialize Variables:**
   * Use two pointers: `left` (start of window) and `right` (end of window).
   * Maintain a hash map to store frequency of elements in current window.
   * Use a counter to track distinct elements efficiently.

2. **Expand Window:**
   * Move `right` pointer and add `arr[right]` to the hash map.
   * If it's a new element (frequency becomes 1), decrement `k`.

3. **Contract Window:**
   * If `k` becomes negative (more than k distinct elements), shrink window from left.
   * Remove `arr[left]` from frequency map and increment `k` if element is completely removed.
   * Move `left` pointer forward.

4. **Count Subarrays:**
   * For each valid window ending at `right`, add `(right - left + 1)` to result.
   * This counts all subarrays ending at `right` with at most k distinct elements.

5. **Continue Until End:**
   * Repeat until `right` pointer reaches the end of array.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. Each element is visited at most twice by the sliding window pointers, making it linear time.
* **Expected Auxiliary Space Complexity:** O(k), where k is the maximum number of distinct elements allowed. In the worst case, the hash map stores at most k distinct elements with their frequencies.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size(), res = 0, left = 0;
        unordered_map<int, int> freq;
        for (int right = 0; right < n; right++) {
            if (freq[arr[right]]++ == 0) k--;
            while (k < 0) {
                if (--freq[arr[left]] == 0) k++;
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Array-Based Approach (For Limited Range)**

### 💡 Algorithm Steps:

1. Use a fixed-size array to track frequency when the range of elements is known
2. Maintain a count of distinct elements in the current window
3. Expand window by moving right pointer and shrink when necessary
4. Add valid subarray count for each position

```cpp
class Solution {
public:
    int countAtMostK(vector<int> &arr, int k) {
        int maxVal = *max_element(arr.begin(), arr.end());
        vector<int> freq(maxVal + 1, 0);
        int n = arr.size(), res = 0, left = 0, distinct = 0;
        for (int right = 0; right < n; right++) {
            if (freq[arr[right]]++ == 0) distinct++;
            while (distinct > k) {
                if (--freq[arr[left]] == 0) distinct--;
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + maxVal)
* **Auxiliary Space:** 💾 O(maxVal) - for frequency array

### ✅ **Why This Approach?**

* Faster access times with array indexing
* No hash collisions
* Better cache locality

## 📊 **3️⃣ Two-Pointer with Set Approach**

### 💡 Algorithm Steps:

1. Use an unordered_set to track distinct elements
2. Use an unordered_map to maintain frequencies
3. Expand and contract window based on distinct count
4. Calculate subarray count for each valid window

```cpp
class Solution {
public:
    int countAtMostK(vector<int> &arr, int k) {
        unordered_set<int> distinct;
        unordered_map<int, int> freq;
        int n = arr.size(), res = 0, left = 0;
        for (int right = 0; right < n; right++) {
            freq[arr[right]]++;
            distinct.insert(arr[right]);
            while (distinct.size() > k) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) distinct.erase(arr[left]);
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(k) - for set and map

### ✅ **Why This Approach?**

* Clear separation of concerns
* Easy to understand logic
* Explicit distinct element tracking

## 📊 **4️⃣ Optimized Single Map Approach**

### 💡 Algorithm Steps:

1. Use only one unordered_map to track both frequency and distinct count
2. Increment/decrement distinct count based on frequency changes
3. Maintain sliding window with efficient contraction
4. Calculate result in single pass

```cpp
class Solution {
public:
    int countAtMostK(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        int n = arr.size(), res = 0, left = 0;
        for (int right = 0; right < n; right++) {
            mp[arr[right]]++;
            while (mp.size() > k) {
                if (--mp[arr[left]] == 0) mp.erase(arr[left]);
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(k) - for map storage

### ✅ **Why This Approach?**

* Memory efficient with single data structure
* Clean and concise implementation
* Automatic distinct count via map size

## 📊 **5️⃣ Frequency Counter Optimization**

### 💡 Algorithm Steps:

1. Use a frequency counter variable to track distinct elements without using map size
2. Maintain frequency map for element counts
3. Efficiently update counter when elements are added/removed
4. Single pass solution with optimal space usage

```cpp
class Solution {
public:
    int countAtMostK(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        int n = arr.size(), res = 0, left = 0, distinctCount = 0;
        for (int right = 0; right < n; right++) {
            if (freq[arr[right]]++ == 0) distinctCount++;
            while (distinctCount > k) {
                if (--freq[arr[left]] == 0) distinctCount--;
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(k) - for frequency map

### ✅ **Why This Approach?**

* Avoids repeated map.size() calls
* Explicit control over distinct count
* Cleaner logic flow

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **HashMap Sliding Window**     | 🟢 O(n)                | 🟡 O(k)                 | 🚀 Works with any values          | 💾 HashMap overhead                   |
| 🔄 **Array-Based Approach**       | 🟢 O(n)                | 🟡 O(maxVal)            | ⚡ Fastest access, no collisions  | 📝 Limited to known range            |
| 🔺 **Two-Pointer with Set**       | 🟢 O(n)                | 🟡 O(k)                 | 🔧 Clear logic, explicit tracking| 💾 Extra space for set              |
| ⏰ **Single Map Approach**        | 🟢 O(n)                | 🟡 O(k)                 | 🚀 Memory efficient, clean code  | 🔄 Map erase operations              |
| 📊 **Frequency Counter**          | 🟢 O(n)                | 🟡 O(k)                 | ⚡ Avoids size() calls, optimal   | 🔧 Slightly more complex counter     |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| ⚡ **Maximum performance, known element range**       | 🥇 **Array-Based Approach**          | ★★★★★                     |
| 🔧 **General purpose, any integer values**            | 🥈 **HashMap Sliding Window**        | ★★★★☆                     |
| 📊 **Memory constrained environments**                | 🥉 **Single Map Approach**           | ★★★★☆                     |
| 🎯 **Educational purposes, clear logic**              | 🎖️ **Two-Pointer with Set**         | ★★★☆☆                     |
| 🚀 **Optimal performance, competitive programming**   | 🏅 **Frequency Counter**             | ★★★★★                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int countAtMostK(int arr[], int k) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        int n = arr.length, res = 0, left = 0;
        for (int right = 0; right < n; right++) {
            freq.put(arr[right], freq.getOrDefault(arr[right], 0) + 1);
            while (freq.size() > k) {
                freq.put(arr[left], freq.get(arr[left]) - 1);
                if (freq.get(arr[left]) == 0) freq.remove(arr[left]);
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def countAtMostK(self, arr, k):
        freq = {}
        n, res, left = len(arr), 0, 0
        for right in range(n):
            freq[arr[right]] = freq.get(arr[right], 0) + 1
            while len(freq) > k:
                freq[arr[left]] -= 1
                if freq[arr[left]] == 0:
                    del freq[arr[left]]
                left += 1
            res += right - left + 1
        return res
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
