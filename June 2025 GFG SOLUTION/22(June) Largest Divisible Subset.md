---
title: "🧩 Largest Divisible Subset | GFG Solution 📊"
keywords🏷️: ["🧩 largest divisible subset", "🔍 dynamic programming", "📍 subset", "📈 divisibility", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Largest Divisible Subset problem: find the largest subset where every pair divides each other using dynamic programming. 🚀"
date: 📅 2025-06-22
---

# *22. Largest Divisible Subset*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/largest-divisible-subset--170643/1)

## **🧩 Problem Description**

Given an array `arr[]` of distinct positive integers, find the **largest subset** such that for every pair of elements `(x, y)` in the subset, either `x` divides `y` or `y` divides `x`.

**Note:** If multiple subsets of the same maximum length exist, return the one that is **lexicographically greatest** after sorting the subset in ascending order.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 16, 7, 8, 4]
Output: [1, 4, 8, 16]
Explanation: The largest divisible subset is [1, 4, 8, 16], where each element divides the next one. This subset is already the lexicographically greatest one.
```

### Example 2

```cpp
Input: arr[] = [2, 4, 3, 8]
Output: [2, 4, 8]
Explanation: The largest divisible subset is [2, 4, 8], where each element divides the next one. This subset is already the lexicographically greatest one.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^3$
* $1 \le \text{arr}[i] \le 10^9$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming** with **Longest Increasing Subsequence (LIS)** concept applied to divisibility:

### **Dynamic Programming with Parent Tracking**

1. **Sort in Descending Order:**
   * Sort the array in descending order to ensure lexicographically greatest result.
   * This helps in getting the largest elements first when building the subset.

2. **Initialize DP Arrays:**
   * `dp[i]` = length of longest divisible subset ending at index `i`
   * `parent[i]` = previous index in the optimal subset chain ending at `i`
   * Initialize all `dp[i] = 1` and `parent[i] = -1`

3. **Fill DP Table:**
   * For each element `arr[i]`, check all previous elements `arr[j]` where `j < i`
   * If `arr[j] % arr[i] == 0` (since array is sorted in descending order), update:
     - `dp[i] = max(dp[i], dp[j] + 1)`
     - Store parent relationship for path reconstruction

4. **Find Maximum Length:**
   * Track the index with maximum `dp[i]` value
   * This gives us the ending point of the longest divisible subset

5. **Reconstruct Result:**
   * Use parent array to backtrack and build the actual subset
   * The result will be in descending order (lexicographically greatest)

### **Key Insight:**
If we sort in descending order, then for any valid divisible subset, if `a > b` and both are in the subset, then `a % b == 0`. This transforms the problem into finding the longest chain where each element divides the next smaller element.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n²), where n is the array size. We have nested loops where for each element, we check all previous elements to build the optimal subset.
* **Expected Auxiliary Space Complexity:** O(n), as we use additional arrays `dp[]` and `parent[]` of size n to store the dynamic programming states and parent relationships.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.rbegin(), arr.rend());
        vector<int> dp(n, 1), parent(n, -1);
        int maxIdx = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] % arr[i] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > dp[maxIdx]) maxIdx = i;
        }
        
        vector<int> result;
        for (int i = maxIdx; i != -1; i = parent[i]) {
            result.push_back(arr[i]);
        }
        return result;
    }
};
```

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public ArrayList<Integer> largestSubset(int[] arr) {
        int n = arr.length;
        Integer[] temp = new Integer[n];
        for (int i = 0; i < n; i++) temp[i] = arr[i];
        Arrays.sort(temp, Collections.reverseOrder());
        
        int[] dp = new int[n];
        int[] parent = new int[n];
        Arrays.fill(dp, 1);
        Arrays.fill(parent, -1);
        
        int maxIdx = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (temp[j] % temp[i] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > dp[maxIdx]) maxIdx = i;
        }
        
        ArrayList<Integer> result = new ArrayList<>();
        for (int i = maxIdx; i != -1; i = parent[i]) {
            result.add(temp[i]);
        }
        return result;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def largestSubset(self, arr):
        n = len(arr)
        arr.sort(reverse=True)
        dp = [1] * n
        parent = [-1] * n
        max_idx = 0
        for i in range(1, n):
            for j in range(i):
                if arr[j] % arr[i] == 0 and dp[j] + 1 > dp[i]:
                    dp[i] = dp[j] + 1
                    parent[i] = j
            if dp[i] > dp[max_idx]:
                max_idx = i
        result = []
        i = max_idx
        while i != -1:
            result.append(arr[i])
            i = parent[i]
        return result
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
