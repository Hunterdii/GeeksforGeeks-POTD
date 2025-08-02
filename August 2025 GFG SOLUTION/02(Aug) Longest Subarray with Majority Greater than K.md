---
title: "📊 Longest Subarray with Majority Greater than K | GFG Solution 🔍"
keywords🏷️: ["📊 longest subarray", "🔍 prefix sum", "📍 hash map", "📈 majority element", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Longest Subarray with Majority Greater than K problem: find maximum length subarray where count of elements > k exceeds count of elements ≤ k using prefix sum technique. 🚀"
date: 📅 2025-08-02
---

# *02. Longest Subarray with Majority Greater than K*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/longest-subarray-with-majority-greater-than-k/1)

## **🧩 Problem Description**

You are given an array `arr[]` and an integer `k`. Your task is to find the length of the **longest subarray** in which the count of elements greater than `k` is **more than** the count of elements less than or equal to `k`.

A subarray is a contiguous sequence of elements within an array. The goal is to find the maximum possible length of such a subarray where elements > k have majority over elements ≤ k.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 2, 3, 4, 1], k = 2
Output: 3
Explanation: The subarray [2, 3, 4] or [3, 4, 1] satisfy the given condition. 
In [2, 3, 4]: elements > 2 are [3, 4] (count = 2), elements ≤ 2 are [2] (count = 1).
Since 2 > 1, this subarray is valid with length 3.
```

### Example 2

```cpp
Input: arr[] = [6, 5, 3, 4], k = 2
Output: 4
Explanation: In the subarray [6, 5, 3, 4], there are 4 elements > 2 and 0 elements ≤ 2.
Since 4 > 0, the entire array satisfies the condition with length 4.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^6$
* $1 \le \text{arr}[i] \le 10^6$
* $0 \le k \le 10^6$

## **✅ My Approach**

The optimal approach uses the **Prefix Sum** technique with a **Hash Map** to efficiently track the balance between elements greater than k and elements less than or equal to k:

### **Prefix Sum + Hash Map**

1. **Transform Problem:**
   * Convert each element to +1 if `arr[i] > k`, otherwise -1 if `arr[i] ≤ k`.
   * This transforms the problem to finding the longest subarray with positive sum.

2. **Running Balance:**
   * Maintain a running sum where we add +1 for elements > k and -1 for elements ≤ k.
   * A positive sum indicates more elements > k than elements ≤ k.

3. **Hash Map for Optimization:**
   * Store the first occurrence of each sum value with its index.
   * For current sum `s`, if we need sum > 0, we look for previous occurrence of `s-1`.
   * This gives us the longest subarray ending at current position with positive balance.

4. **Key Insights:**
   * If current sum > 0, the entire prefix from start has majority > k.
   * If current sum ≤ 0, we look for a previous position where sum was `current_sum - 1`.
   * The subarray between that position and current position will have sum = 1 (positive).

5. **Edge Case Handling:**
   * Initialize map with sum 0 at index -1 to handle cases where entire prefix is valid.
   * Only store first occurrence of each sum to maximize subarray length.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We make a single pass through the array, and each hash map operation takes O(1) average time.
* **Expected Auxiliary Space Complexity:** O(n), where n is the size of the array. In the worst case, we might store all different sum values in the hash map, which can be at most n different values.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size(), ans = 0, sum = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            sum += arr[i] <= k ? -1 : 1;
            if (sum > 0) ans = i + 1;
            else if (mp.count(sum - 1)) ans = max(ans, i - mp[sum - 1]);
            if (!mp.count(sum)) mp[sum] = i;
        }
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Two Pointer Sliding Window**

### 💡 Algorithm Steps:

1. Use running sum where ≤k adds -1 and >k adds +1 for balance calculation
2. Track count of elements ≤ k vs elements > k in current window
3. Expand window and update maximum when balance is positive
4. Use hash map to find previous positions with required balance

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int ans = 0, balance = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < arr.size(); ++i) {
            balance += arr[i] <= k ? -1 : 1;
            if (balance > 0) ans = i + 1;
            else if (mp.count(balance - 1)) ans = max(ans, i - mp[balance - 1]);
            if (!mp.count(balance)) mp[balance] = i;
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with hash map lookups
* **Auxiliary Space:** 💾 O(n) - Hash map for balance tracking

### ✅ **Why This Approach?**

* Clear balance tracking logic
* Similar to original approach but different implementation
* Good for understanding prefix sum concept


## 📊 **3️⃣ Optimized Single Pass**

### 💡 Algorithm Steps:

1. Maintain running sum where ≤k adds -1 and >k adds +1
2. Use only essential variables to minimize memory overhead
3. Track maximum length when sum becomes positive
4. Use map only when necessary for negative sum lookups

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        int s = 0, res = 0;
        m[0] = -1;
        for (int i = 0; i < arr.size(); ++i) {
            s += arr[i] <= k ? -1 : 1;
            if (s > 0) res = i + 1;
            else if (m.find(s - 1) != m.end()) res = max(res, i - m[s - 1]);
            if (m.find(s) == m.end()) m[s] = i;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single traversal with hash map operations
* **Auxiliary Space:** 💾 O(n) - Hash map for sum tracking

### ✅ **Why This Approach?**

* Minimal variable usage for better performance
* Clean implementation with essential logic only
* Good balance of readability and efficiency

## 📊 **4️⃣ Brute Force Approach**

### 💡 Algorithm Steps:

1. Check all possible subarrays using nested loops
2. For each subarray, count elements > k and elements ≤ k
3. Update maximum length when count(>k) > count(≤k)
4. Return the maximum length found

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            int countGreater = 0, countLessEqual = 0;
            for (int j = i; j < n; j++) {
                if (arr[j] > k) countGreater++;
                else countLessEqual++;
                if (countGreater > countLessEqual) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Nested loops to check all subarrays
* **Auxiliary Space:** 💾 O(1) - Only using constant extra space

### ✅ **Why This Approach?**

* Simple to understand and implement
* No additional data structures needed
* Good for small input sizes or educational purposes

> **Note:** This approach results in **Time Limit Exceeded (TLE)** for large inputs _(fails ~1110 /1115 test cases due to time constraints)_.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🗺️ **Hash Map**                   | 🟢 O(n)                | 🟡 O(n)                 | 🎯 Handles all cases optimally    | 💾 Extra space for hash map          |
| 🔄 **Alternative Hash Map**        | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Different implementation       | 💾 Same space complexity             |
| ⚡ **Optimized Single Pass**       | 🟢 O(n)                | 🟡 O(n)                 | 🧠 Minimal variable usage         | 💾 Still requires hash map           |
| 🐌 **Brute Force**                 | 🔴 O(n²)               | 🟢 O(1)                 | 💡 Simple, no extra space        | ⏰ Inefficient for large inputs      |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General optimal solution**                   | 🥇 **Hash Map**                       | ★★★★★                     |
| 💾 **Alternative implementation**                 | 🥈 **Alternative Hash Map**           | ★★★★☆                     |
| 🎓 **Minimal code complexity**                    | 🏅 **Optimized Single Pass**          | ★★★★☆                     |
| 📚 **Educational/Small inputs**                   | 🏅 **Brute Force**                    | ★★☆☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int longestSubarray(int[] arr, int k) {
        int n = arr.length, ans = 0, sum = 0;
        Map<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            sum += (arr[i] > k) ? 1 : -1;
            if (sum > 0) ans = i + 1;
            else if (mp.containsKey(sum - 1)) ans = Math.max(ans, i - mp.get(sum - 1));
            mp.putIfAbsent(sum, i);
        }
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def longestSubarray(self, arr, k):
        mp, ans, s = {0: -1}, 0, 0
        for i, x in enumerate(arr):
            s += -1 if x <= k else 1
            if s > 0: ans = i + 1
            elif s - 1 in mp: ans = max(ans, i - mp[s - 1])
            mp.setdefault(s, i)
        return ans
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
