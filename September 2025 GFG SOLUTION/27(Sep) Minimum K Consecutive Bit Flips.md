---
title: "🔢 Minimum K Consecutive Bit Flips | GFG Solution 🔍"
keywords🏷️: ["🔢 bit flips", "🔍 greedy algorithm", "📍 sliding window", "📈 array manipulation", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Minimum K Consecutive Bit Flips problem: find minimum operations to convert all 0's to 1's using greedy approach with in-place marking. 🚀"
date: 📅 2025-09-27
---

# *27. Minimum K Consecutive Bit Flips*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/minimum-number-of-k-consecutive-bit-flips--171650/1)

## **🧩 Problem Description**

You are given a binary array `arr[]` (containing only 0's and 1's) and an integer `k`. In one operation, you can select a contiguous subarray of length `k` and flip all its bits (i.e., change every 0 to 1 and every 1 to 0).

Your task is to find the **minimum number** of such operations required to make the entire array consist of only 1's. If it is not possible, return -1.

## **📘 Examples**

### Example 1

```cpp
Input: arr = [1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1], k = 2
Output: 4
Explanation: 4 operations are required to convert all 0's to 1's.
Select subarray [2, 3] and flip all bits resulting array will be [1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1]
Select subarray [4, 5] and flip all bits resulting array will be [1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1]
Select subarray [5, 6] and flip all bits resulting array will be [1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1]
Select subarray [6, 7] and flip all bits resulting array will be [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
```

### Example 2

```cpp
Input: arr = [0, 0, 1, 1, 1, 0, 0], k = 3
Output: -1
Explanation: It is not possible to convert all elements to 1's by performing any number of operations.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^6$
* $1 \le k \le \text{arr.size()}$

## **✅ My Approach**

The optimal approach uses a **Greedy Algorithm** with **In-place Marking** to efficiently track flip operations without using extra space:

### **Greedy Algorithm + In-place Marking**

1. **Core Insight:**
   * Process the array from left to right (greedy approach).
   * When we encounter a 0 (after considering all previous flips), we must flip the subarray starting at that position.
   * Use the array itself to mark where flips have been applied.

2. **Tracking Flip State:**
   * Maintain a `flip` variable to track the current flip state.
   * When we start a new flip operation, toggle the flip state.
   * When a previous flip operation ends (after k positions), toggle the flip state again.

3. **In-place Marking:**
   * Mark flip start positions by setting `arr[i] = 2` (since original values are 0 or 1).
   * Check `arr[i - k] > 1` to detect when a flip operation ends.

4. **Decision Making:**
   * At each position, determine the effective value: `arr[i] ^ flip`.
   * If the effective value is 0, we need to start a flip operation.
   * If starting a flip would go beyond array bounds, return -1.

5. **Count Operations:**
   * Increment flip counter each time we start a new flip operation.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We make a single pass through the array, performing constant time operations at each position.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space (flip counter and flip state variable). The marking is done in-place within the input array.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int kBitFlips(vector<int>& a, int k) {
        int n = a.size(), flips = 0, flip = 0;
        for (int i = 0; i < n; i++) {
            if (i >= k && a[i - k] > 1) flip ^= 1;
            if ((a[i] ^ flip) == 0) {
                if (i + k > n) return -1;
                a[i] = 2;
                flip ^= 1;
                flips++;
            }
        }
        return flips;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Difference Array Approach**

### 💡 Algorithm Steps:

1. Use difference array technique to track flip operations efficiently.
2. Mark flip start positions and track cumulative flips at each position.
3. For each position, check if current state needs flipping based on cumulative operations.
4. Apply flip operation if needed and update difference array accordingly.

```cpp
class Solution {
public:
    int kBitFlips(vector<int>& a, int k) {
        int n = a.size(), flips = 0, current = 0;
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < n; i++) {
            current += diff[i];
            if ((a[i] + current) % 2 == 0) {
                if (i + k > n) return -1;
                diff[i]++;
                diff[i + k]--;
                current++;
                flips++;
            }
        }
        return flips;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through array
* **Auxiliary Space:** 💾 O(n) - Extra difference array

### ✅ **Why This Approach?**

* Clean separation of flip tracking logic
* Easy to understand difference array pattern
* Good for problems requiring range updates

## 📊 **3️⃣ Greedy With Counter**

### 💡 Algorithm Steps:

1. Use greedy approach processing left to right with flip counter.
2. Maintain active flip count using sliding window technique.
3. Check if current bit needs flipping considering active flips.
4. Apply flip operation when necessary and update counters.

```cpp
class Solution {
public:
    int kBitFlips(vector<int>& a, int k) {
        int n = a.size(), result = 0, active = 0;
        deque<int> flips;
        for (int i = 0; i < n; i++) {
            while (!flips.empty() && flips.front() <= i - k) 
                flips.pop_front();
            int current = a[i] ^ (flips.size() & 1);
            if (current == 0) {
                if (i + k > n) return -1;
                flips.push_back(i);
                result++;
            }
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear time with deque operations
* **Auxiliary Space:** 💾 O(k) - At most k elements in deque

### ✅ **Why This Approach?**

* Space efficient with bounded extra space
* Clear tracking of active flip windows
* Intuitive sliding window pattern

## 📊 **4️⃣ Bit Manipulation Optimized**

### 💡 Algorithm Steps:

1. Use XOR operations for efficient bit manipulation and state tracking.
2. Encode flip information directly in array values using bit tricks.
3. Process array in single pass with minimal extra variables.
4. Decode flip state using bitwise operations for optimal performance.

```cpp
class Solution {
public:
    int kBitFlips(vector<int>& a, int k) {
        int n = a.size(), ans = 0, flipped = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= k && a[i - k] == 2) flipped ^= 1;
            if (a[i] == flipped) {
                if (i + k > n) return -1;
                a[i] = 2;
                flipped ^= 1;
                ans++;
            }
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with constant operations
* **Auxiliary Space:** 💾 O(1) - Only few integer variables

### ✅ **Why This Approach?**

* Most space efficient solution possible
* Fast bit operations for optimal performance
* Minimal variable usage for memory efficiency

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **In-place Marking**           | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal space usage           | 🔧 Modifies input array              |
| 🔍 **Difference Array**           | 🟢 O(n)                | 🟡 O(n)                 | 📖 Clean logic separation        | 💾 Extra array space                 |
| 📊 **Deque Counter**              | 🟢 O(n)                | 🟡 O(k)                 | 🎯 Bounded space usage           | 🔧 Complex deque management          |
| 🔄 **Bit Manipulation**           | 🟢 O(n)                | 🟢 O(1)                 | ⭐ Most efficient overall        | 🧠 Requires bit operation knowledge   |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Memory constrained environment**                 | 🥇 **In-place Marking**              | ★★★★★                     |
| 📖 **Code readability priority**                      | 🥈 **Difference Array**              | ★★★★☆                     |
| 🔧 **Cannot modify input array**                      | 🥉 **Deque Counter**                 | ★★★★☆                     |
| 🎯 **Maximum performance needed**                      | 🏅 **Bit Manipulation**              | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int kBitFlips(int[] a, int k) {
        int n = a.length, flips = 0, flip = 0;
        for (int i = 0; i < n; i++) {
            if (i >= k && a[i - k] > 1) flip ^= 1;
            if ((a[i] ^ flip) == 0) {
                if (i + k > n) return -1;
                a[i] = 2;
                flip ^= 1;
                flips++;
            }
        }
        return flips;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def kBitFlips(self, a, k):
        n, flips, flip = len(a), 0, 0
        for i in range(n):
            if i >= k and a[i - k] > 1: flip ^= 1
            if (a[i] ^ flip) == 0:
                if i + k > n: return -1
                a[i] = 2
                flip ^= 1
                flips += 1
        return flips
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
