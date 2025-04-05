---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - prefix-sum
  - Arrays
  - Hash
  - Map
---

# 🚀 _Day 1. Longest Subarray with Sum K_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/prefix-sum-gfg-160/problem/longest-sub-array-with-sum-k0809)

## 💡 **Problem Description:**

Given an array `arr[]` containing integers and an integer `k`, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value `k`. If there is no subarray with sum equal to `k`, return `0`.

## 🔍 **Example Walkthrough:**

### **Example 1**

**Input:**  
`arr[] = [10, 5, 2, 7, 1, -10], k = 15`  
**Output:**  
`6`  
**Explanation:**  
Subarrays with sum `15` are `[5, 2, 7, 1]`, `[10, 5]`, and `[10, 5, 2, 7, 1, -10]`. The longest subarray has length `6`.

### **Example 2**

**Input:**  
`arr[] = [-5, 8, -14, 2, 4, 12], k = -5`  
**Output:**  
`5`  
**Explanation:**  
Only subarray with sum `-5` is `[-5, 8, -14, 2, 4]` of length `5`.

### **Example 3**

**Input:**  
`arr[] = [10, -10, 20, 30], k = 5`  
**Output:**  
`0`  
**Explanation:**  
No subarray with sum equal to `5` exists in `arr[]`.

## Constraints:

- $`1 ≤ arr.size() ≤ 10^5`$
- $`-10^4 ≤ arr[i] ≤ 10^4`$
- $`-10^9 ≤ k ≤ 10^9`$

## 🎯 **My Approach:**

1. **Hashmap-Based Sliding Window Algorithm**:

   - Use a hashmap (`mp`) to store the prefix sum and the earliest index at which it occurs.
   - Traverse the array, maintaining a running sum (`sum`) of the elements.
   - At each step, check:
     - If `sum == k`, the subarray starts from the beginning, so update the result as the current index + 1.
     - If `sum - k` exists in the hashmap, calculate the length of the subarray ending at the current index and update the result if it is longer than the previous maximum.
   - Store the current `sum` in the hashmap if it is not already present to maintain the earliest index of each prefix sum.

2. **Steps:**
   - Initialize a hashmap to store prefix sums and their earliest indices.
   - Traverse the array while calculating the prefix sum.
   - Use conditions to determine if a subarray with the required sum exists and update the result accordingly.
   - Return the maximum length.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n), where `n` is the size of the array. Each element is visited once, and hashmap operations are O(1).
- **Expected Auxiliary Space Complexity:** O(n), as we use a hashmap to store the prefix sums.

## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        int sum = 0, res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
            if (sum == k) res = i + 1;
            if (mp.count(sum - k)) res = max(res, i - mp[sum - k]);
            if (!mp.count(sum)) mp[sum] = i;
        }
        return res;
    }
};
```

## Code (Java)

```java
class Solution {
    public int longestSubarray(int[] arr, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        int sum = 0, res = 0;
        for (int i = 0; i < arr.length; ++i) {
            if ((sum += arr[i]) == k) res = i + 1;
            if (mp.containsKey(sum - k)) res = Math.max(res, i - mp.get(sum - k));
            mp.putIfAbsent(sum, i);
        }
        return res;
    }
}
```

## Code (Python)

```python
class Solution:
    def longestSubarray(self, arr, k):
        mp, sum, res = {}, 0, 0
        for i, num in enumerate(arr):
            sum += num
            if sum == k:
                res = i + 1
            if sum - k in mp:
                res = max(res, i - mp[sum - k])
            mp.setdefault(sum, i)
        return res
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
