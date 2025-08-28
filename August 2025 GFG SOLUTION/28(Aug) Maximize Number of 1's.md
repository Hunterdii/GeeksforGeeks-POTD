---
title: "🔢 Maximize Number of 1's | GFG Solution 🔍"
keywords🏷️: ["🔢 binary array", "🔍 sliding window", "📍 two pointers", "📈 flip zeros", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Maximize Number of 1's problem: find maximum consecutive 1's by flipping at most k zeros using optimized sliding window technique. 🚀"
date: 📅 2025-08-28
---

# *28. Maximize Number of 1's*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximize-number-of-1s0905/1)

## **🧩 Problem Description**

You are given a **binary array** `arr[]` containing only 0s and 1s and an integer `k`. You are allowed to **flip at most k 0s to 1s**. Your task is to find the **maximum number of consecutive 1's** that can be obtained in the array after performing the operation at most k times.

A flip operation changes a 0 to 1. The goal is to maximize the length of the longest contiguous subarray of 1's after optimally choosing which zeros to flip.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 0, 1], k = 1
Output: 3
Explanation: By flipping the zero at index 1, we get the longest subarray from index 0 to 2 containing all 1's.
```

### Example 2

```cpp
Input: arr[] = [1, 0, 0, 1, 0, 1, 0, 1], k = 2
Output: 5
Explanation: By flipping the zeroes at indices 4 and 6, we get the longest subarray from index 3 to 7 containing all 1's.
```

### Example 3

```cpp
Input: arr[] = [1, 1], k = 2
Output: 2
Explanation: Since the array is already having the max consecutive 1's, hence we don't need to perform any operation. Hence the answer is 2.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $0 \le k \le \text{arr.size()}$
* $0 \le \text{arr}[i] \le 1$

## **✅ My Approach**

The optimal approach uses the **Sliding Window** technique to efficiently find the maximum window that contains at most `k` zeros:

### **Optimized Sliding Window**

1. **Initialize Variables:**
   * Use two pointers: `l` (left/start) and `r` (right/end) for the sliding window.
   * Maintain `zeros` counter to track zeros in current window.
   * Track `maxLen` to store the maximum window length found.

2. **Expand Window:**
   * Move `r` pointer and increment `zeros` if `arr[r]` is 0.
   * This represents including more elements in our potential flip window.

3. **Contract Window:**
   * If `zeros > k` (exceeded flip limit), shrink window from left.
   * Move `l` pointer and decrement `zeros` if `arr[l]` was 0.
   * Continue until `zeros <= k` (valid window restored).

4. **Update Result:**
   * After each valid window expansion, update `maxLen` with current window size `(r - l + 1)`.

5. **Continue Until End:**
   * Repeat until `r` pointer covers the entire array.

**Key Insight:** Instead of actually flipping zeros, we find the longest subarray containing at most `k` zeros. This subarray represents the optimal segment where we can flip all zeros to get maximum consecutive 1's.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. Each element is visited at most twice - once by the right pointer during expansion and once by the left pointer during contraction.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables (pointers and counters).


## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {
        int l = 0, zeros = 0, maxLen = 0;
        for (int r = 0; r < arr.size(); r++) {
            zeros += (arr[r] == 0);
            while (zeros > k) zeros -= (arr[l++] == 0);
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Two-Pass Approach**

### 💡 Algorithm Steps:

1. First pass: Calculate prefix sum of zeros up to each position.
2. Use binary search or two pointers to find valid window for each position.
3. Track maximum window size across all valid positions.
4. Return the maximum length found.

```cpp
class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size(), maxLen = 0;
        vector<int> zeros;
        for (int i = 0; i < n; i++) if (arr[i] == 0) zeros.push_back(i);
        if (zeros.size() <= k) return n;
        for (int i = 0; i <= zeros.size() - k; i++) {
            int start = (i == 0) ? 0 : zeros[i - 1] + 1;
            int end = (i + k == zeros.size()) ? n - 1 : zeros[i + k] - 1;
            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with zero position tracking
* **Auxiliary Space:** 💾 O(z) - Space for zero positions where z ≤ n

### ✅ **Why This Approach?**

* Handles edge cases efficiently when zeros ≤ k
* Clear separation of zero position identification and window calculation
* Good for sparse arrays with few zeros

## 📊 **3️⃣ Deque-Based Sliding Window**

### 💡 Algorithm Steps:

1. Use deque to maintain positions of zeros in current window.
2. Expand window by adding elements and tracking zero positions.
3. When zeros exceed k, shrink window from left using deque front.
4. Track maximum window size throughout the process.

```cpp
class Solution {
public:
    int maxOnes(vector<int>& arr, int k) {
        deque<int> zeroPos;
        int l = 0, maxLen = 0;
        for (int r = 0; r < arr.size(); r++) {
            if (arr[r] == 0) zeroPos.push_back(r);
            while (zeroPos.size() > k) {
                l = zeroPos.front() + 1;
                zeroPos.pop_front();
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each element processed once
* **Auxiliary Space:** 💾 O(k) - Deque stores at most k zero positions

### ✅ **Why This Approach?**

* Explicit tracking of zero positions for better control
* Efficient window management with deque operations
* Clear visualization of sliding window boundaries


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Optimized Sliding Window**    | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Clean and efficient           | 🔧 Standard approach                  |
| 🔍 **Two-Pass Zero Tracking**      | 🟢 O(n)                | 🟡 O(z)                 | 📖 Handles sparse arrays well    | 💾 Extra space for zero positions    |
| 📊 **Deque-Based**                | 🟢 O(n)                | 🟡 O(k)                 | 🎯 Explicit position tracking    | 🐌 Deque overhead                     |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General optimization**                       | 🥇 **Optimized Sliding Window**      | ★★★★★                     |
| 📖 **Sparse arrays (few zeros)**                  | 🥈 **Two-Pass Zero Tracking**        | ★★★★☆                     |
| 🔧 **Need explicit position tracking**            | 🥉 **Deque-Based**                   | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int maxOnes(int arr[], int k) {
        int l = 0, zeros = 0, maxLen = 0;
        for (int r = 0; r < arr.length; r++) {
            if (arr[r] == 0) zeros++;
            while (zeros > k) if (arr[l++] == 0) zeros--;
            maxLen = Math.max(maxLen, r - l + 1);
        }
        return maxLen;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxOnes(self, arr, k):
        l = zeros = maxLen = 0
        for r in range(len(arr)):
            zeros += (arr[r] == 0)
            while zeros > k:
                zeros -= (arr[l] == 0)
                l += 1
            maxLen = max(maxLen, r - l + 1)
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















