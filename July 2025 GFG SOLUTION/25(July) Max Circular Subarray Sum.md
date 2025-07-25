---
title: "🔄 Maximum Circular Subarray Sum | GFG Solution 🎯"
keywords🏷️: ["🔄 circular array", "📈 kadane algorithm", "🔍 subarray sum", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Maximum Circular Subarray Sum problem: find maximum subarray sum in circular array using Kadane's algorithm with circular optimization. 🚀"
date: 📅 2025-07-25
---

# *25. Maximum Circular Subarray Sum*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/1)

## **🧩 Problem Description**

You are given a circular array `arr[]` of integers. Your task is to find the maximum possible sum of a **non-empty subarray**. In a circular array, the subarray can start at the end and wrap around to the beginning. Return the maximum non-empty subarray sum, considering both **non-wrapping** and **wrapping** cases.

A circular array means that the end of the array wraps around to the beginning, allowing subarrays to span across this boundary.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
Output: 22
Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, 
we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.
```

### Example 2

```cpp
Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
Output: 23
Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].
```

### Example 3

```cpp
Input: arr[] = [5, -2, 3, 4]
Output: 12
Explanation: The circular subarray [3, 4, 5] gives the maximum sum of 12.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $-10^4 \le \text{arr}[i] \le 10^4$

## **✅ My Approach**

The optimal approach combines **Kadane's Algorithm** with **circular array optimization** using the concept of minimum subarray sum:

### **Kadane's Algorithm + Circular Optimization**

1. **Case 1 - Non-Circular Maximum:**
   * Apply standard Kadane's algorithm to find maximum subarray sum.
   * This handles cases where optimal subarray doesn't wrap around.

2. **Case 2 - Circular Maximum:**
   * Key insight: Maximum circular subarray = Total sum - Minimum subarray
   * Find minimum subarray sum using modified Kadane's (negate all elements).
   * Calculate circular maximum as: `totalSum - minSubarraySum`

3. **Edge Case Handling:**
   * If all elements are negative, circular sum would be 0 (empty subarray).
   * In this case, return the non-circular maximum (least negative element).

4. **Final Result:**
   * Return maximum of non-circular and circular maximum sums.

### **Algorithm Steps:**

1. Calculate maximum subarray sum using Kadane's algorithm.
2. Calculate total sum of all elements.
3. Negate all elements and find maximum subarray (which gives minimum of original).
4. Calculate circular maximum: `totalSum + maxOfNegated`
5. Handle edge case where all elements are negative.
6. Return maximum of both cases.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We perform two passes through the array - one for standard Kadane's algorithm and another for finding minimum subarray sum.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables like maxSum, totalSum, and temporary calculation variables.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxCircularSum(vector<int>& arr) {
        int n = arr.size();
        int maxKadane = kadane(arr);
        int totalSum = 0;
        for (int& x : arr) {
            totalSum += x;
            x = -x;
        }
        int maxCircular = totalSum + kadane(arr);
        return maxCircular == 0 ? maxKadane : max(maxKadane, maxCircular);
    }
private:
    int kadane(vector<int>& arr) {
        int maxSum = arr[0], currSum = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            currSum = max(arr[i], currSum + arr[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Single Pass Two-Pointer Approach**

### 💡 Algorithm Steps:

1. Calculate max and min subarray sums in single pass
2. Use total sum for circular calculation
3. Handle edge case where all elements are negative
4. Return maximum of linear and circular sums

```cpp
class Solution {
public:
    int maxCircularSum(vector<int>& arr) {
        int total = 0, maxSum = INT_MIN, minSum = INT_MAX;
        int currMax = 0, currMin = 0;
        for (int x : arr) {
            total += x;
            currMax = max(x, currMax + x);
            currMin = min(x, currMin + x);
            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);
        }
        return total == minSum ? maxSum : max(maxSum, total - minSum);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - single pass
* **Auxiliary Space:** 💾 O(1) - constant space

### ✅ **Why This Approach?**

* Minimal memory usage
* Single loop iteration
* Optimal for memory-constrained environments


## 📊 **3️⃣ Deque-Based Sliding Window**

### 💡 Algorithm Steps:

1. Use deque to maintain maximum in sliding windows
2. Calculate all possible circular sums efficiently
3. Compare with linear maximum subarray
4. Optimal for large arrays with repeated queries

```cpp
class Solution {
public:
    int maxCircularSum(vector<int>& arr) {
        int n = arr.size();
        int maxLinear = kadane(arr);
        deque<int> dq;
        vector<int> prefixSum(2*n + 1, 0);
        for (int i = 0; i < 2*n; i++) {
            prefixSum[i+1] = prefixSum[i] + arr[i % n];
        }
        int maxCircular = INT_MIN;
        for (int i = 0; i < 2*n; i++) {
            while (!dq.empty() && prefixSum[dq.back()] >= prefixSum[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            while (!dq.empty() && dq.front() <= i - n) {
                dq.pop_front();
            }
            if (i >= n-1) {
                maxCircular = max(maxCircular, prefixSum[i+1] - prefixSum[dq.front()]);
            }
        }
        return max(maxLinear, maxCircular);
    }
private:
    int kadane(vector<int>& arr) {
        int maxSum = arr[0], currSum = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            currSum = max(arr[i], currSum + arr[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - amortized
* **Auxiliary Space:** 💾 O(n) - deque and prefix array

### ✅ **Why This Approach?**

* Advanced sliding window technique
* Efficient for complex scenarios
* Demonstrates competitive programming skills

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Kadane with Negation**       | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Clean and optimal              | 💾 Modifies input array              |
| 🔺 **Single Pass Two-Pointer**    | 🟢 O(n)                | 🟢 O(1)                 | 🔧 No input modification         | 💾 Slightly more complex logic       |
| 🔑 **Deque Sliding Window**       | 🟢 O(n)                | 🟡 O(n)                 | ⚡ Advanced technique             | 🔧 More complex implementation       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| ⚡ **General use, optimal performance**               | 🥇 **Single Pass Two-Pointer**       | ★★★★★                     |
| 📊 **Memory constrained**                            | 🥈 **Kadane with Negation**          | ★★★★★                     |
| 🚀 **Competitive programming**                       | 🥉 **Deque Sliding Window**          | ★★★★☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int maxCircularSum(int arr[]) {
        int maxKadane = kadane(arr);
        int totalSum = 0;
        for (int i = 0; i < arr.length; i++) {
            totalSum += arr[i];
            arr[i] = -arr[i];
        }
        int maxCircular = totalSum + kadane(arr);
        for (int i = 0; i < arr.length; i++) {
            arr[i] = -arr[i];
        }
        return maxCircular == 0 ? maxKadane : Math.max(maxKadane, maxCircular);
    }
    
    private int kadane(int[] arr) {
        int maxSum = arr[0], currSum = arr[0];
        for (int i = 1; i < arr.length; i++) {
            currSum = Math.max(arr[i], currSum + arr[i]);
            maxSum = Math.max(maxSum, currSum);
        }
        return maxSum;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxCircularSum(self, arr):
        def kadane(a):
            max_sum = curr_sum = a[0]
            for i in range(1, len(a)):
                curr_sum = max(a[i], curr_sum + a[i])
                max_sum = max(max_sum, curr_sum)
            return max_sum
        
        max_kadane = kadane(arr)
        total_sum = sum(arr)
        for i in range(len(arr)):
            arr[i] = -arr[i]
        max_circular = total_sum + kadane(arr)
        for i in range(len(arr)):
            arr[i] = -arr[i]
        
        return max_kadane if max_circular == 0 else max(max_kadane, max_circular)
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
