---
title: "🔗 Longest Span in two Binary Arrays | GFG Solution 🧮"
keywords🏷️: ["🔢 longest span", "⚖️ equal sum subarray", "🧮 binary arrays", "📊 prefix sums", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to find the longest span where two binary arrays have equal sum in the span. 🚀"
date: 📅 2025-06-07
---

# *07. Longest Span in two Binary Arrays*

The problem can be found here: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays5142/1)

## **🧩 Problem Description**

Given two binary arrays `a1[]` and `a2[]` of the same size, find the length of the longest span `(i, j)` such that the sum of elements from `a1[i]` to `a1[j]` is equal to the sum of elements from `a2[i]` to `a2[j]`.

## **📘 Examples**

### Example 1

```

Input: a1 = [0, 1, 0, 0, 0, 0], a2 = [1, 0, 1, 0, 0, 1]
Output: 4
Explanation: The longest span with same sum is from index 1 to 4.

```

### Example 2

```

Input: a1 = [0, 1, 0, 1, 1, 1, 1], a2 = [1, 1, 1, 1, 1, 0, 1]
Output: 6
Explanation: The longest span with same sum is from index 1 to 6.

````

## **🔒 Constraints**

* $1 \leq \text{a1.size()} = \text{a2.size()} \leq 10^6$
* $a1[i], a2[i] \in \{0,1\}$

## **✅ My Approach**

### **Prefix Sum and Hash Map of Differences**

### **💡 Idea:**

  If the sums of `a1` and `a2` over some subarray are equal, then the difference of their prefix sums at two indices will be the same.

- **Detailed Explanation:**

  1. Calculate prefix sums for both arrays, but instead of storing separately, compute the **difference** of prefix sums `diff = prefixSum_a1 - prefixSum_a2`.
  2. If at two different indices `i` and `j` the difference is the same, it means the subarray `(i+1, j)` has equal sums in both arrays.
  3. Track the first occurrence of each difference in a hash map.
  4. When you encounter the same difference again, compute the span length and update the maximum span.
  5. Special case: if difference is zero at index `i`, update max span to `i + 1`.

- This reduces the problem to finding the **longest subarray with zero sum in the difference array**.

### **⚙️ Algorithm Steps:**

- Initialize `maxLen = 0`, `sum1 = 0`, `sum2 = 0`.
- Use a hash map `diffMap` to store first occurrence of difference `(sum1 - sum2)`.
- Traverse arrays from `i = 0` to `n-1`:
  - Update `sum1 += a1[i]`, `sum2 += a2[i]`.
  - Compute `diff = sum1 - sum2`.
  - If `diff == 0`, update `maxLen = i + 1`.
  - Else if `diff` seen before at index `prevIndex`, update `maxLen = max(maxLen, i - prevIndex)`.
  - Else store `diff` with current index in `diffMap`.


## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), as we traverse arrays once and perform O(1) average lookups in the hash map.
* **Expected Auxiliary Space Complexity:** O(n), for storing the hash map of prefix sum differences.



## **🧑‍💻 Code (C++)**

```cpp
class Solution {
  public:
    int longestCommonSum(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size(), res = 0;
        unordered_map<int, int> diffMap;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            sum1 += arr1[i];
            sum2 += arr2[i];
            int diff = sum1 - sum2;
            if (diff == 0) res = i + 1;
            else if (diffMap.count(diff)) res = max(res, i - diffMap[diff]);
            else diffMap[diff] = i;
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>


## 📊 **2️⃣ Difference Array + Zero-Sum Subarray**

Transform the problem into finding the **longest subarray with sum 0** using a difference array.

### 💡 Algorithm Steps:

1. Construct a new array `diff[i] = arr1[i] - arr2[i]`.
2. Find the longest subarray in `diff` whose sum is zero:

   * Use a `prefix_sum` and store the **first index** where each sum appears in a `hash map`.
   * If at any point, `prefix_sum == 0`, update result to `i + 1`.
   * If `prefix_sum` seen before, `res = max(res, i - first_index[prefix_sum])`.

### 📌 Key Insight:

If two prefix sums at indices `i` and `j` are the same, then subarray sum between `(i, j]` is 0.
This trick works beautifully for difference arrays!

```cpp
class Solution {
  public:
    int longestCommonSum(vector<int> &arr1, vector<int> &arr2) {
        int n = arr1.size(), res = 0;
        vector<int> diff(n);
        for (int i = 0; i < n; i++)
            diff[i] = arr1[i] - arr2[i];

        unordered_map<int, int> prefix;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i];
            if (sum == 0)
                res = i + 1;
            else if (prefix.count(sum))
                res = max(res, i - prefix[sum]);
            else
                prefix[sum] = i;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(n) — to store first index of each prefix sum.

### ✅ **Why This Approach?**

* Transforms the original problem into a **classic subarray sum problem**.
* More readable than prefix diff directly on sums.
* Leverages prefix tricks for optimal performance.



## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                       | ⏱️ **Time** | 💾 **Space** | ✅ **Pros**                          | ⚠️ **Cons**                |
| ------------------------------------- | ----------- | ------------ | ----------------------------------- | -------------------------- |
| 🔄 **Prefix Sum + HashMap** | 🟢 O(n)        | 🟢 O(n)         | Most intuitive and efficient        | —                          |
| ✂️ **Diff Array + Zero-Sum Subarray** | 🟢 O(n)        | 🟡 O(n)         | Turns into classic zero-sum problem | Slight extra preprocessing |

### 🏆 **Best Choice by Scenario**

| 🎯 **Scenario**                         | 🥇 **Recommended Approach**       |
| --------------------------------------- | --------------------------------- |
| 🧠 Want clarity and optimal performance | 🥇 Prefix Sum + HashMap           |
| ♻️ Familiar with zero-sum tricks        | 🥈 Diff Array + Zero-Sum Subarray |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int longestCommonSum(int[] arr1, int[] arr2) {
        int n = arr1.length, sum1 = 0, sum2 = 0, res = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            sum1 += arr1[i];
            sum2 += arr2[i];
            int diff = sum1 - sum2;
            if (diff == 0)
                res = i + 1;
            else if (map.containsKey(diff))
                res = Math.max(res, i - map.get(diff));
            else
                map.put(diff, i);
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def longestCommonSum(self, arr1, arr2):
        n = len(arr1)
        sum1 = sum2 = res = 0
        diff_map = {}
        for i in range(n):
            sum1 += arr1[i]
            sum2 += arr2[i]
            diff = sum1 - sum2
            if diff == 0:
                res = i + 1
            elif diff in diff_map:
                res = max(res, i - diff_map[diff])
            else:
                diff_map[diff] = i
        return res
```


## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
