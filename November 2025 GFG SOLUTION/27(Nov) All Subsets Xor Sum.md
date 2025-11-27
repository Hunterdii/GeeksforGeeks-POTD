---
title: "🔢 All Subsets XOR Sum | GFG Solution 🔍"
keywords🏷️: ["🔢 subset xor sum", "🔍 bitwise operations", "📍 mathematical optimization", "📈 bit manipulation", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the All Subsets XOR Sum problem: calculate sum of XOR values across all subsets using optimal bitwise OR technique with mathematical insight. 🚀"
date: 📅 2025-11-27
---

# *27. All Subsets XOR Sum*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/sum-of-xor-of-all-possible-subsets/1)

## **🧩 Problem Description**

You are given an array `arr[]`. Your task is to find the sum of XOR of all elements for every possible subset of the array. Subsets with the same elements should be counted multiple times.

An array `a` is a subset of an array `b` if `a` can be obtained from `b` by deleting some (possibly zero) elements of `b`.

**Note:** The answer is guaranteed to fit within a 32-bit integer.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [7, 2]
Output: 14
Explanation: Subsets are: [[], [7], [2], [7, 2]]
Sum of all XOR's = 0 + 7 + 2 + (7 ^ 2) = 0 + 7 + 2 + 5 = 14.
```

### Example 2

```cpp
Input: arr[] = [1, 2, 3]
Output: 12
Explanation: Subsets are: [[], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]]
Sum of all XOR's = 0 + 1 + 2 + 3 + (1 ^ 2) + (1 ^ 3) + (2 ^ 3) + (1 ^ 2 ^ 3) = 12.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 30$
* $1 \le \text{arr}[i] \le 10^3$

## **✅ My Approach**

The optimal approach uses **Bitwise OR with Mathematical Optimization** to solve this problem in linear time:

### **Bitwise OR + Left Shift Technique**

1. **Mathematical Insight:**
   * For any bit position, if it's set (1) in the OR of all array elements, it will contribute to the final sum.
   * Each bit that is set in any element appears in exactly 2^(n-1) subsets.
   * The XOR sum equals: (OR of all elements) × 2^(n-1).

2. **Algorithm Steps:**
   * Compute the bitwise OR of all array elements.
   * This OR value represents all possible bits that can be set across any subset.
   * Left shift the OR result by (n-1) positions, equivalent to multiplying by 2^(n-1).
   * Return the computed result.

3. **Why This Works:**
   * XOR has the property that each set bit in the OR contributes independently.
   * Every element participates in exactly half of all 2^n subsets.
   * The mathematical formula simplifies brute force O(n × 2^n) to O(n).

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We perform a single pass through the array to compute the bitwise OR of all elements, which takes linear time.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables to store the OR result and perform the shift operation.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        int orVal = 0;
        for (int x : arr) orVal |= x;
        return orVal << (arr.size() - 1);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Single Pass OR Accumulation**

### 💡 Algorithm Steps:

1. Accumulate OR of all array elements in single pass.
2. Each set bit appears in exactly half of all subsets.
3. Multiply by 2^(n-1) using left shift operation.
4. Return the computed result directly.

```cpp
class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        int result = 0;
        for (int i = 0; i < arr.size(); i++) result |= arr[i];
        return result * (1 << (arr.size() - 1));
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single array traversal
* **Auxiliary Space:** 💾 O(1) - Only scalar variables

### ✅ **Why This Approach?**

* Optimal linear time complexity
* Mathematical insight into XOR properties
* Most efficient for large arrays

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Bitwise OR + Shift**         | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal time & space           | 🧠 Requires mathematical insight     |
| ➕ **OR Accumulation**             | 🟢 O(n)                | 🟢 O(1)                 | ⚡ Optimal performance             | 🧮 Less obvious approach             |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Bitwise OR + Shift**            | ★★★★★                     |
| 🎯 **Competitive programming**                        | 🥈 **OR Accumulation**               | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    int subsetXORSum(int arr[]) {
        int orVal = 0;
        for (int x : arr) orVal |= x;
        return orVal << (arr.length - 1);
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def subsetXORSum(self, arr):
        orVal = 0
        for x in arr: orVal |= x
        return orVal << (len(arr) - 1)
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


