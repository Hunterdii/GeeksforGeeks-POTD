---
title: "🔄 Max Sum in the Configuration | GFG Solution 🔍"
keywords🏷️: ["🔄 array rotation", "🧮 mathematical formula", "📊 optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Max Sum in the Configuration problem: find maximum value of sum of i*arr[i] among all rotations using mathematical optimization technique. 🚀"
date: 📅 2025-02-07
---

# *07. Max Sum in the Configuration*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/max-sum-in-the-configuration/1)

## **🧩 Problem Description**

Given an integer array `arr[]`. Find the maximum value of the sum of `i*arr[i]` for all `0 ≤ i ≤ arr.size()-1`. The only operation allowed is to rotate (clockwise or counterclockwise) the array any number of times.

A rotation shifts all elements of the array by one position either to the left or right, with the element at the boundary wrapping around to the other end.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [3, 1, 2, 8]
Output: 29
Explanation: Out of all the possible configurations by rotating the elements: 
arr[] = [3, 1, 2, 8] here (3*0) + (1*1) + (2*2) + (8*3) = 29 is maximum.
```

### Example 2

```cpp
Input: arr[] = [1, 2, 3]
Output: 8
Explanation: Out of all the possible configurations by rotating the elements: 
arr[] = [1, 2, 3] here (1*0) + (2*1) + (3*2) = 8 is maximum.
```

### Example 3

```cpp
Input: arr[] = [4, 13]
Output: 13
Explanation: The configuration [13, 4] gives (13*0) + (4*1) = 4, while 
[4, 13] gives (4*0) + (13*1) = 13, which is maximum.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^4$
* $1 \le \text{arr}[i] \le 20$

## **✅ My Approach**

The optimal approach uses a **Mathematical Formula** to avoid simulating each rotation explicitly:

### **Mathematical Optimization Pattern**

1. **Compute Initial Values:**
   * Calculate the sum of all array elements: `sum = Σ arr[i]`
   * Calculate initial weighted sum: `val = Σ (i * arr[i])` for the original configuration.
   * Initialize result `res = val`.

2. **Derive Rotation Formula:**
   * When we rotate the array left by one position, the new weighted sum can be derived from the previous one.
   * Mathematical relation: `next_val = current_val + sum - n * arr[n-i]`
   * This formula eliminates the need to recalculate the entire sum for each rotation.

3. **Iterate Through Rotations:**
   * For each rotation from `i = 1` to `n-1`:
     * Apply the formula: `val = val + sum - n * arr[n-i]`
     * Update maximum: `res = max(res, val)`

4. **Return Result:**
   * After checking all rotations, return the maximum value found.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We compute the initial sum and weighted sum in O(n), then iterate through n-1 rotations, each taking O(1) time to update using the mathematical formula.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space to store variables like sum, val, and res regardless of input size.



## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxSum(vector<int>& arr) {
        int n = arr.size(), sum = 0, val = 0, res;
        for (int i = 0; i < n; i++) sum += arr[i], val += i * arr[i];
        res = val;
        for (int i = 1; i < n; i++) {
            val += sum - n * arr[n - i];
            res = max(res, val);
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>


## 📊 **2️⃣ Prefix Sum Optimization**

### 💡 Algorithm Steps:

1. Precompute cumulative sum for efficient rotation calculations.
2. Use mathematical formula to derive next rotation value.
3. Apply transition formula: next = current + total_sum - n * last_element.
4. Track maximum across all computed values.

```cpp
class Solution {
public:
    int maxSum(vector<int>& arr) {
        int n = arr.size(), total = accumulate(arr.begin(), arr.end(), 0);
        int curr = 0, res;
        for (int i = 0; i < n; i++) curr += i * arr[i];
        res = curr;
        for (int i = 0; i < n - 1; i++) {
            curr = curr + total - n * arr[n - 1 - i];
            res = max(res, curr);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with formula application
* **Auxiliary Space:** 💾 O(1) - Only variables stored

### ✅ **Why This Approach?**

* Uses standard library for cleaner code
* Mathematical derivation of rotation formula
* Efficient single-pass solution

## 📊 **3️⃣ Reverse Iteration Pattern**

### 💡 Algorithm Steps:

1. Calculate initial sum and weighted sum in first pass.
2. Iterate from end to beginning for rotation simulation.
3. Update value using: new_val = old_val - (sum - last) + last * (n-1).
4. Maximize result at each step.

```cpp
class Solution {
public:
    int maxSum(vector<int>& arr) {
        int n = arr.size(), s = 0, v = 0;
        for (int i = 0; i < n; i++) s += arr[i], v += i * arr[i];
        int mx = v;
        for (int i = n - 1; i > 0; i--) {
            v += s - n * arr[i];
            mx = max(mx, v);
        }
        return mx;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear scan with constant updates
* **Auxiliary Space:** 💾 O(1) - In-place computation

### ✅ **Why This Approach?**

* Alternative iteration direction for variety
* Compact variable naming for brevity
* Same optimal complexity with different style

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🧮 **Mathematical Formula**        | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal performance            | 🧠 Requires formula derivation        |
| 📊 **Prefix Sum**                 | 🟢 O(n)                | 🟢 O(1)                 | 🎯 Clean STL usage                | 📚 Similar to main approach           |
| ↩️ **Reverse Iteration**          | 🟢 O(n)                | 🟢 O(1)                 | ✨ Compact code                   | 🔧 Same logic, different direction    |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Competitive Programming**                    | 🥇 **Mathematical Formula**          | ★★★★★                     |
| 🎯 **Production Code**                            | 🥈 **Prefix Sum**                   | ★★★★★                     |
| 💡 **Interview Settings**                         | 🥉 **Mathematical Formula**          | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    int maxSum(int[] arr) {
        int n = arr.length, sum = 0, val = 0;
        for (int i = 0; i < n; i++) { sum += arr[i]; val += i * arr[i]; }
        int res = val;
        for (int i = 1; i < n; i++) {
            val += sum - n * arr[n - i];
            res = Math.max(res, val);
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxSum(self, arr): 
        n, s, v = len(arr), sum(arr), sum(i * arr[i] for i in range(len(arr)))
        res = v
        for i in range(1, n):
            v += s - n * arr[n - i]
            res = max(res, v)
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











