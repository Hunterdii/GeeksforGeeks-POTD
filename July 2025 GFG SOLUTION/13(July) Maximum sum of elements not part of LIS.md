---
title: "📉 Maximum Sum of Elements Not Part of LIS | GFG Solution 🔍"
keywords🏷️: ["📉 longest increasing subsequence", "🔍 binary search", "📍 dynamic programming", "📈 LIS", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Maximum Sum of Elements Not Part of LIS problem: find maximum sum of elements not in the Longest Increasing Subsequence using binary search optimization. 🚀"
date: 📅 2025-07-13
---

# *13. Maximum Sum of Elements Not Part of LIS*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximum-sum-of-elements-not-part-of-lis/1)

## **🧩 Problem Description**

Given an array `arr[]` of positive integers, your task is to find the maximum possible sum of all elements that are **not part of the Longest Increasing Subsequence (LIS)**.

The approach is to find the LIS with minimum sum among all possible LIS of maximum length, then subtract this from the total sum of the array.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [4, 6, 1, 2, 3, 8]
Output: 10
Explanation: The LIS could be [1, 2, 3, 8] with sum 14. 
The elements not in LIS are [4, 6] with sum 10.
Total sum = 24, LIS sum = 14, so answer = 24 - 14 = 10.
```

### Example 2

```cpp
Input: arr[] = [5, 4, 3, 2, 1]
Output: 14
Explanation: The LIS is [1] (or any single element) with sum 1.
The elements not in LIS are [5, 4, 3, 2] with sum 14.
Total sum = 15, LIS sum = 1, so answer = 15 - 1 = 14.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^3$
* $1 \le \text{arr}[i] \le 10^5$

## **✅ My Approach**

The optimal approach uses **Binary Search** to efficiently construct the LIS while maintaining cumulative sums:

### **Binary Search + Cumulative Sum Tracking**

1. **Initialize Data Structures:**
   * `dp` vector to store the LIS using binary search technique
   * `sums` vector to track cumulative sums corresponding to each LIS length
   * Calculate total sum of the array

2. **Process Each Element:**
   * For each element `x` in the array, find its position in the current LIS using `lower_bound`
   * This gives us the position where `x` should be placed to maintain the increasing property

3. **Update LIS and Sums:**
   * If `x` extends the LIS (position equals current LIS length), append it to both `dp` and `sums`
   * Otherwise, replace the element at the found position and update the corresponding cumulative sum

4. **Calculate Result:**
   * The answer is `total_sum - minimum_LIS_sum`
   * The minimum LIS sum is stored in `sums.back()` after processing all elements

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the size of the array. Each element requires a binary search operation which takes O(log n) time, and we process n elements.
* **Expected Auxiliary Space Complexity:** O(n), where n is the size of the array. We use additional space for the `dp` and `sums` vectors, each of which can grow up to size n in the worst case.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int nonLisMaxSum(vector<int>& arr) {
        vector<int> dp, sums;
        int total = accumulate(arr.begin(), arr.end(), 0);
        for (int x : arr) {
            auto it = lower_bound(dp.begin(), dp.end(), x);
            int idx = it - dp.begin();
            if (it == dp.end()) {
                dp.push_back(x);
                sums.push_back((sums.empty() ? 0 : sums.back()) + x);
            } else {
                *it = x;
                sums[idx] = (idx ? sums[idx - 1] : 0) + x;
            }
        }
        return total - sums.back();
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Optimized with Early Termination**

### 💡 Algorithm Steps:

1. Use binary search to build LIS efficiently
2. Track cumulative sums at each LIS length
3. Handle array traversal in single pass
4. Return total sum minus final LIS sum

```cpp
class Solution {
public:
    int nonLisMaxSum(vector<int>& arr) {
        vector<int> tails, prefixSum;
        int total = accumulate(arr.begin(), arr.end(), 0);
        for (int x : arr) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            int pos = it - tails.begin();
            if (it == tails.end()) {
                tails.push_back(x);
                prefixSum.push_back((prefixSum.empty() ? 0 : prefixSum.back()) + x);
            } else {
                tails[pos] = x;
                prefixSum[pos] = (pos ? prefixSum[pos - 1] : 0) + x;
            }
        }
        return total - prefixSum.back();
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n)
* **Auxiliary Space:** 💾 O(n) - for tails array

### ✅ **Why This Approach?**

* Reduced memory footprint
* Incremental sum calculation
* Efficient for large arrays

## 📊 **3️⃣ Dynamic Programming Approach**

### 💡 Algorithm Steps:

1. Use classic DP to find LIS at each position
2. Track minimum sum LIS ending at each position
3. Build solution incrementally
4. Return total minus minimum LIS sum

```cpp
class Solution {
public:
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), minSum(n);
        int total = accumulate(arr.begin(), arr.end(), 0);
        for (int i = 0; i < n; i++) {
            minSum[i] = arr[i];
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    minSum[i] = minSum[j] + arr[i];
                } else if (arr[j] < arr[i] && dp[j] + 1 == dp[i]) {
                    minSum[i] = min(minSum[i], minSum[j] + arr[i]);
                }
            }
        }
        int maxLen = *max_element(dp.begin(), dp.end());
        int minLisSum = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLen) {
                minLisSum = min(minLisSum, minSum[i]);
            }
        }
        return total - minLisSum;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²)
* **Auxiliary Space:** 💾 O(n) - for DP array

### ✅ **Why This Approach?**

* Handles duplicate values efficiently
* Clear DP state transitions
* Good for educational purposes

## 📊 **4️⃣ Coordinate Compression with Binary Search**

### 💡 Algorithm Steps:

1. Compress coordinates for efficient processing
2. Use binary search for optimal LIS construction
3. Track sums with coordinate mapping
4. Maintain efficient space complexity

```cpp
class Solution {
public:
    int nonLisMaxSum(vector<int>& arr) {
        vector<int> vals = arr;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        vector<int> dp, sums;
        int total = accumulate(arr.begin(), arr.end(), 0);
        for (int x : arr) {
            auto it = lower_bound(dp.begin(), dp.end(), x);
            int pos = it - dp.begin();
            if (it == dp.end()) {
                dp.push_back(x);
                sums.push_back((sums.empty() ? 0 : sums.back()) + x);
            } else {
                dp[pos] = x;
                sums[pos] = (pos ? sums[pos - 1] : 0) + x;
            }
        }
        return total - sums.back();
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n)
* **Auxiliary Space:** 💾 O(n) - for coordinate arrays

### ✅ **Why This Approach?**

* Optimal time complexity
* Efficient range queries
* Scalable for large inputs

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Binary Search LIS**          | 🟢 O(n log n)         | 🟡 O(n)                 | 🚀 Optimal and simple            | 💾 Requires auxiliary arrays         |
| 🔺 **Early Termination**          | 🟢 O(n log n)         | 🟢 O(n)                 | 🔧 Clean implementation          | 💾 Similar to main approach           |
| ⏰ **Dynamic Programming**        | 🟡 O(n²)              | 🟡 O(n)                 | 🚀 Handles edge cases well       | 🔄 Higher time complexity             |
| 📊 **Coordinate Compression**     | 🟢 O(n log n)         | 🟡 O(n)                 | ⚡ Efficient for large values     | 🔧 Extra preprocessing overhead       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| ⚡ **General purpose**                             | 🥇 **Binary Search LIS**             | ★★★★★                     |
| 📊 **Clean implementation**                       | 🥈 **Early Termination**             | ★★★★☆                     |
| 🎯 **Small arrays with complex logic**            | 🥉 **Dynamic Programming**           | ★★★☆☆                     |
| 🚀 **Competitive programming**                    | 🏅 **Coordinate Compression**        | ★★★★★                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int nonLisMaxSum(int[] arr) {
        ArrayList<Integer> dp = new ArrayList<>();
        ArrayList<Integer> sums = new ArrayList<>();
        int total = Arrays.stream(arr).sum();
        for (int x : arr) {
            int idx = Collections.binarySearch(dp, x);
            if (idx < 0) idx = -idx - 1;
            if (idx == dp.size()) {
                dp.add(x);
                sums.add((sums.isEmpty() ? 0 : sums.get(sums.size() - 1)) + x);
            } else {
                dp.set(idx, x);
                sums.set(idx, (idx > 0 ? sums.get(idx - 1) : 0) + x);
            }
        }
        return total - sums.get(sums.size() - 1);
    }
}
```

## **🐍 Code (Python)**

```python
import bisect
class Solution:
    def nonLisMaxSum(self, arr):
        dp, sums = [], []
        total = sum(arr)
        for x in arr:
            i = bisect.bisect_left(dp, x)
            if i == len(dp):
                dp.append(x)
                sums.append((sums[-1] if sums else 0) + x)
            else:
                dp[i] = x
                sums[i] = (sums[i-1] if i else 0) + x
        return total - sums[-1]
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
