---
title: "⚡ Max XOR Subarray of size K | GFG Solution 🎯"
keywords🏷️: ["⚡ xor subarray", "🔍 sliding window", "📊 bitwise operations", "📈 fixed window", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Max XOR Subarray of size K: find maximum XOR value among all subarrays of fixed size using efficient sliding window technique. 🚀"
date: 📅 2025-03-04
---

# *04. Max XOR Subarray of size K*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/max-xor-subarray-of-size-k/1)

## **🧩 Problem Description**

Given an array of integers `arr[]` and a number `k`, return the **maximum XOR** of a subarray of size `k`.

**Note:** A subarray is a contiguous part of any given array.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [2, 5, 8, 1, 1, 3], k = 3
Output: 15
Explanation: arr[0] ^ arr[1] ^ arr[2] = 2 ^ 5 ^ 8 = 15, which is maximum.
```

### Example 2

```cpp
Input: arr[] = [1, 2, 4, 5, 6], k = 2
Output: 6
Explanation: arr[1] ^ arr[2] = 2 ^ 4 = 6, which is maximum.
```

### Example 3

```cpp
Input: arr[] = [3, 7, 1, 5], k = 2
Output: 6
Explanation: arr[0] ^ arr[1] = 3 ^ 7 = 4, arr[1] ^ arr[2] = 7 ^ 1 = 6, 
arr[2] ^ arr[3] = 1 ^ 5 = 4. Maximum is 6.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^6$
* $0 \le \text{arr}[i] \le 10^6$
* $1 \le k \le \text{arr.size()}$

## **✅ My Approach**

The optimal solution uses **Sliding Window with XOR Properties**:

### **Sliding Window Technique**

1. **Key XOR Property:**
   * XOR is self-inverse: `a ^ b ^ b = a`
   * To remove an element from XOR, simply XOR it again.
   * This allows efficient window sliding in O(1) time.

2. **Window Management:**
   * Maintain current XOR of window elements.
   * When adding new element: `currentXOR ^= arr[i]`
   * When removing old element: `currentXOR ^= arr[i-k]`

3. **Algorithm Steps:**
   * Start with empty XOR (0).
   * For each position, add new element to window XOR.
   * If window size exceeds k, remove leftmost element.
   * Track maximum XOR value seen.

4. **Optimization:**
   * Single loop handles both initialization and sliding.
   * No separate first window computation needed.
   * Constant time per element.

**Why This Works:** The XOR self-inverse property means we can efficiently add and remove elements from the running XOR value without recalculating from scratch.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We make a single pass through the array, performing constant time XOR operations for each element.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of extra space for variables like current XOR, maximum XOR, and loop counters.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int xr = 0, res = 0;
        for (int i = 0; i < arr.size(); i++) {
            xr ^= arr[i];
            if (i >= k) xr ^= arr[i - k];
            if (i >= k - 1) res = max(res, xr);
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Two-Phase Sliding Window**

### 💡 Algorithm Steps:

1. Compute XOR of first k elements separately.
2. Initialize maximum with first window XOR.
3. Slide window: add new element, remove old element.
4. Update maximum after each slide.

```cpp
class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        int currXor = 0;
        for (int i = 0; i < k; i++)
            currXor ^= arr[i];
        int maxXor = currXor;
        for (int i = k; i < n; i++) {
            currXor ^= arr[i];
            currXor ^= arr[i - k];
            maxXor = max(maxXor, currXor);
        }
        return maxXor;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear traversal
* **Auxiliary Space:** 💾 O(1) - Constant space

### ✅ **Why This Approach?**

* Clear separation of initialization and sliding
* Easy to understand window concept
* Traditional sliding window pattern

## 📊 **3️⃣ Brute Force Approach**

### 💡 Algorithm Steps:

1. Try all possible subarrays of size k.
2. For each subarray, compute XOR from scratch.
3. Track maximum XOR value found.
4. Return the maximum.

```cpp
class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size(), maxXor = 0;
        for (int i = 0; i <= n - k; i++) {
            int xr = 0;
            for (int j = i; j < i + k; j++)
                xr ^= arr[j];
            maxXor = max(maxXor, xr);
        }
        return maxXor;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × k) - Nested loops
* **Auxiliary Space:** 💾 O(1) - Constant space

### ✅ **Why This Approach?**

* Simplest to understand
* No window sliding concept needed
* Good for very small k values

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110/1111 test cases due to time constraints).


## 📊 **4️⃣ Prefix XOR Array**

### 💡 Algorithm Steps:

1. Build prefix XOR array where prefix[i] = arr[0] ^ arr[1] ^ ... ^ arr[i-1].
2. XOR of subarray [i, i+k-1] = prefix[i+k] ^ prefix[i].
3. Try all windows and track maximum.
4. Return maximum XOR found.

```cpp
class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] ^ arr[i];
        int maxXor = 0;
        for (int i = 0; i <= n - k; i++)
            maxXor = max(maxXor, prefix[i + k] ^ prefix[i]);
        return maxXor;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear preprocessing and traversal
* **Auxiliary Space:** 💾 O(n) - Prefix array storage

### ✅ **Why This Approach?**

* Demonstrates prefix XOR concept
* Useful for multiple queries
* Clean mathematical formulation

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Single Loop Sliding**        | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Most efficient, elegant        | 🔧 Requires XOR property knowledge   |
| 📊 **Two-Phase Sliding**          | 🟢 O(n)                | 🟢 O(1)                 | 📖 Clear window pattern           | 🔧 Two separate loops                |
| 🔄 **Brute Force**                | 🔴 O(n × k)            | 🟢 O(1)                 | 🎯 Simplest logic                 | 🐌 Inefficient for large k           |
| 📈 **Prefix XOR**                 | 🟢 O(n)                | 🔴 O(n)                 | 🔍 Good for multiple queries      | 💾 Extra space required              |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Single Loop Sliding**           | ★★★★★                     |
| 📖 **Learning sliding window**                        | 🥈 **Two-Phase Sliding**             | ★★★★★                     |
| 🎯 **Understanding basics**                           | 🥉 **Brute Force**                   | ★★★☆☆                     |
| 🔍 **Multiple queries on same array**                 | 🏅 **Prefix XOR**                    | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int maxSubarrayXOR(int[] arr, int k) {
        int xr = 0, res = 0;
        for (int i = 0; i < arr.length; i++) {
            xr ^= arr[i];
            if (i >= k) xr ^= arr[i - k];
            if (i >= k - 1) res = Math.max(res, xr);
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxSubarrayXOR(self, arr, k):
        xr = res = 0
        for i in range(len(arr)):
            xr ^= arr[i]
            if i >= k:
                xr ^= arr[i - k]
            if i >= k - 1:
                res = max(res, xr)
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
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" alt="Visitor counter" />
</p>
