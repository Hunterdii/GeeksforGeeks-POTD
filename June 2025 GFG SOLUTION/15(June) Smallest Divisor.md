---
title: "🧮 Smallest Divisor | GFG Solution 🎯"
keywords🏷️: ["🧮 smallest divisor", "🔍 binary search", "📈 array", "🎯 optimization", "📉 greedy", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Smallest Divisor problem: find the smallest divisor such that sum of ceiling divisions is ≤ k using binary search. 🚀"
date: 📅 2025-06-15
---

# *15. Smallest Divisor*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/smallest-divisor/1)

## **🧩 Problem Description**

Given an integer array `arr[]` and an integer `k` (where `k ≥ arr.length`), find the **smallest positive integer divisor** such that the sum of the ceiling values of each element in `arr[]` divided by this divisor is **less than or equal to k**.

For a divisor `d`, the sum is calculated as: `⌈arr[0]/d⌉ + ⌈arr[1]/d⌉ + ... + ⌈arr[n-1]/d⌉ ≤ k`

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 2, 5, 9], k = 6
Output: 5
Explanation: 5 is the smallest divisor having sum of quotients:
⌈1/5⌉ + ⌈2/5⌉ + ⌈5/5⌉ + ⌈9/5⌉ = 1 + 1 + 1 + 2 = 5 ≤ 6
```

### Example 2

```cpp
Input: arr[] = [1, 1, 1, 1], k = 4
Output: 1
Explanation: 1 is the smallest divisor having sum of quotients:
⌈1/1⌉ + ⌈1/1⌉ + ⌈1/1⌉ + ⌈1/1⌉ = 1 + 1 + 1 + 1 = 4 ≤ 4
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^6$
* $\text{arr.size()} \le k \le 10^6$

## **✅ My Approach**

The optimal approach uses **Binary Search** on the answer space. Since we need the smallest divisor, we can search in the range `[1, max(arr)]`:

### **Binary Search**

1. **Define Search Space:**
   * Lower bound: `l = 1` (smallest positive divisor)
   * Upper bound: `h = max(arr)` (largest possible needed divisor)

2. **Binary Search Logic:**
   * For each mid value `m`, calculate the sum of ceiling divisions
   * Use the formula: `⌈a/b⌉ = (a + b - 1) / b` for efficient ceiling calculation
   * If sum ≤ k, try smaller divisors (move right boundary)
   * If sum > k, need larger divisors (move left boundary)

3. **Ceiling Division Optimization:**
   * Instead of using `ceil(arr[i]/m)`, use `(arr[i] + m - 1) / m`
   * This avoids floating-point operations and is more efficient

4. **Termination:**
   * When `l >= h`, we found the smallest valid divisor

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n * log(max_element)), where n is the array size. Binary search runs in O(log(max_element)) iterations, and each iteration requires O(n) time to calculate the sum of ceiling divisions.
* **Expected Auxiliary Space Complexity:** O(1), as we only use constant extra space for variables like left, right, mid, and sum.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int smallestDivisor(vector<int>& arr, int k) {
        int l = 1, h = *max_element(arr.begin(), arr.end()), n = arr.size();
        while (l < h) {
            int m = l + (h - l) / 2, s = 0;
            for (int i = 0; i < n; ++i)
                s += (arr[i] + m - 1) / m;
            if (s <= k) h = m;
            else l = m + 1;
        }
        return l;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Binary Search with Math Ceiling**

### 💡 Algorithm Steps:

1. Use mathematical ceiling function for division.
2. Standard binary search template.
3. Explicit ceiling calculation.

```cpp
class Solution {
public:
    int smallestDivisor(vector<int>& arr, int k) {
        int l = 1, h = *max_element(arr.begin(), arr.end()), r = h;
        while (l <= h) {
            int m = l + (h - l) / 2, s = 0;
            for (int x : arr) s += (x % m == 0) ? x / m : x / m + 1;
            if (s <= k) r = m, h = m - 1;
            else l = m + 1;
        }
        return r;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n * log(max_element))
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* More readable ceiling division logic.
* Classical binary search pattern.

## 📊 **3️⃣ Ternary Search Approach**

### 💡 Algorithm Steps:

1. Divide search space into three parts instead of two.
2. Compare function values at two mid points.
3. Eliminate one-third of search space each iteration.

```cpp
class Solution {
public:
    int smallestDivisor(vector<int>& arr, int k) {
        int l = 1, h = *max_element(arr.begin(), arr.end());
        while (h - l > 2) {
            int m1 = l + (h - l) / 3, m2 = h - (h - l) / 3, s1 = 0, s2 = 0;
            for (int x : arr) s1 += (x + m1 - 1) / m1, s2 += (x + m2 - 1) / m2;
            if (s1 <= k) h = m1;
            else if (s2 <= k) l = m1, h = m2;
            else l = m2;
        }
        for (int d = l; d <= h; d++) {
            int s = 0;
            for (int x : arr) s += (x + d - 1) / d;
            if (s <= k) return d;
        }
        return h;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n * log₃(max_element))
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Theoretically faster convergence than binary search.
* Reduces search space by 1/3 each iteration.

## 📊 **4️⃣ Square Root Decomposition**

### 💡 Algorithm Steps:

1. Divide array into √n blocks.
2. Precompute partial sums for blocks.
3. Use binary search with block-wise calculation.

```cpp
class Solution {
public:
    int smallestDivisor(vector<int>& arr, int k) {
        int n = arr.size(), b = sqrt(n) + 1;
        vector<vector<int>> blocks(b);
        for (int i = 0; i < n; i++) blocks[i / b].push_back(arr[i]);
        
        int l = 1, h = *max_element(arr.begin(), arr.end());
        while (l < h) {
            int m = l + (h - l) / 2, s = 0;
            for (auto& block : blocks)
                for (int x : block) s += (x + m - 1) / m;
            s <= k ? h = m : l = m + 1;
        }
        return l;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n * log(max_element))
* **Auxiliary Space:** 💾 O(n)

### ✅ **Why This Approach?**

* Better cache locality for large arrays.
* Potential for parallelization.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**           | ⏱️ **Time Complexity**           | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ------------------------- | -------------------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Binary Search(Ultra-Optimized)**    | 🟢 O(n * log(max))               | 🟢 O(1)                 | ⚡ Fastest runtime, minimal ops    | 🧮 Less readable                     |
| 🔄 **Math Ceiling**       | 🟢 O(n * log(max))               | 🟢 O(1)                 | 🔧 Clear division logic            | 🐢 More operations per iteration      |
| 🔺 **Ternary Search**     | 🟢 O(n * log₃(max))              | 🟢 O(1)                 | 🚀 Faster theoretical convergence  | 🧮 Complex implementation            |
| 📊 **Sqrt Decomposition** | 🟢 O(n * log(max))               | 🔸 O(n)                 | 🏎️ Better cache locality          | 💾 Extra space overhead              |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**    | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------- | ------------------------- |
| ⚡ Maximum performance, large datasets             | 🥇 **Binary Search**          | ★★★★★                     |
| 🔧 Code clarity with good performance              | 🥈 **Math Ceiling**             | ★★★★☆                     |
| 📊 Theoretical optimization                        | 🥉 **Ternary Search**           | ★★★★☆                     |
| 🏎️ Cache-sensitive large arrays                   | 🏅 **Sqrt Decomposition**       | ★★★☆☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    int smallestDivisor(int[] arr, int k) {
        int l = 1, h = Arrays.stream(arr).max().getAsInt();
        while (l < h) {
            int m = l + (h - l) / 2, s = 0;
            for (int x : arr)
                s += (x + m - 1) / m;
            if (s <= k) h = m;
            else l = m + 1;
        }
        return l;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def smallestDivisor(self, arr, k):
        l, h = 1, max(arr)
        while l < h:
            m, s = l + (h - l) // 2, 0
            for x in arr:
                s += (x + m - 1) // m
            if s <= k:
                h = m
            else:
                l = m + 1
        return l
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
