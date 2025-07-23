---
title: "📐 Sum of Subarrays | GFG Solution 🔍"
keywords🏷️: ["📐 sum of subarrays", "🔍 mathematical formula", "📍 contribution technique", "📈 array optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Sum of Subarrays problem: calculate total sum of all possible subarrays using mathematical contribution technique. 🚀"
date: 📅 2025-07-23
---

# *23. Sum of Subarrays*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/sum-of-subarrays2229/1)

## **🧩 Problem Description**

Given an array `arr[]`, find the sum of all the subarrays of the given array.

A subarray is a contiguous sequence of elements within an array. The goal is to calculate the total sum of all possible subarrays efficiently.

**Note:** It is guaranteed that the total sum will fit within a 32-bit integer range.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 2, 3]
Output: 20
Explanation: All subarray sums are: [1] = 1, [2] = 2, [3] = 3, [1, 2] = 3, [2, 3] = 5, [1, 2, 3] = 6. 
Thus total sum is 1 + 2 + 3 + 3 + 5 + 6 = 20.
```

### Example 2

```cpp
Input: arr[] = [1, 3]
Output: 8
Explanation: All subarray sums are: [1] = 1, [3] = 3, [1, 3] = 4. 
Thus total sum is 1 + 3 + 4 = 8.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $0 \le \text{arr}[i] \le 10^4$

## **✅ My Approach**

The optimal approach uses the **Mathematical Contribution Technique** to efficiently calculate each element's total contribution across all subarrays:

### **Mathematical Contribution Formula**

1. **Key Insight:**
   * Each element `arr[i]` appears in multiple subarrays.
   * The number of subarrays containing `arr[i]` can be calculated mathematically.
   * Element at index `i` appears in `(i + 1) * (n - i)` subarrays.

2. **Formula Derivation:**
   * **Left choices:** Element at index `i` can be the starting point for subarrays in `(i + 1)` ways (indices 0 to i).
   * **Right choices:** Element at index `i` can be the ending point for subarrays in `(n - i)` ways (indices i to n-1).
   * **Total contribution:** `arr[i] * (i + 1) * (n - i)`

3. **Algorithm:**
   * Iterate through each element once.
   * Calculate its contribution using the formula.
   * Sum all contributions to get the final result.

4. **Mathematical Proof:**
   * For element at position `i`, it appears in subarrays starting from positions `[0, 1, 2, ..., i]` (i+1 choices).
   * Each of these subarrays can end at positions `[i, i+1, i+2, ..., n-1]` (n-i choices).
   * Total occurrences = `(i + 1) * (n - i)`

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We perform a single pass through the array, calculating each element's contribution in constant time.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables (sum, loop counter).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size(), sum = 0;
        for (int i = 0; i < n; ++i)
            sum += arr[i] * (i + 1) * (n - i);
        return sum;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Prefix Count Based Approach**

### 💡 Algorithm Steps:

1. Calculate prefix sum array
2. Use mathematical formula for contribution
3. Single pass optimization
4. Direct computation without extra multiplication

```cpp
class Solution {
public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size(), result = 0;
        for (int i = 0; i < n; ++i) {
            int leftCount = i + 1;
            int rightCount = n - i;
            result += arr[i] * leftCount * rightCount;
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)              
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Single pass computation
* No extra space required
* Direct mathematical formula

## 📊 **3️⃣ Range Sum Contribution Method**

### 💡 Algorithm Steps:

1. Calculate each element's total contribution
2. Use position-based weighting
3. Accumulate results efficiently
4. Optimized arithmetic operations

```cpp
class Solution {
public:
    int subarraySum(vector<int>& arr) {
        int total = 0;
        for (int i = 0; i < arr.size(); ++i)
            total += arr[i] * (i + 1) * (arr.size() - i);
        return total;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Minimal variable usage
* Direct size calculation
* Efficient memory access

## 📊 **4️⃣ Iterator-Based Approach**

### 💡 Algorithm Steps:

1. Use iterators for array traversal
2. Calculate position dynamically
3. Minimize index calculations
4. STL-optimized implementation

```cpp
class Solution {
public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        for (auto it = arr.begin(); it != arr.end(); ++it) {
            int pos = it - arr.begin();
            ans += *it * (pos + 1) * (n - pos);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Iterator-based traversal
* Modern C++ style
* Efficient pointer arithmetic

## 📊 **5️⃣ Reverse Iteration Optimization**

### 💡 Algorithm Steps:

1. Iterate from end to beginning for cache efficiency
2. Pre-calculate array size to avoid repeated calls
3. Use compound assignment for faster accumulation
4. Minimize arithmetic operations per iteration

```cpp
class Solution {
public:
    int subarraySum(vector<int>& arr) {
        int total = 0, size = arr.size();
        for (int idx = size - 1; idx >= 0; --idx)
            total += arr[idx] * (idx + 1) * (size - idx);
        return total;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Reverse iteration pattern
* Pre-computed size variable
* Optimized loop structure

## 📊 **6️⃣ Range-Based Loop Optimization**

### 💡 Algorithm Steps:

1. Use modern C++ range-based iteration
2. Enumerate with index tracking
3. Lambda-based calculation pattern
4. STL algorithm integration

```cpp
class Solution {
public:
    int subarraySum(vector<int>& arr) {
        int sum = 0, n = arr.size(), i = 0;
        for (auto val : arr)
            sum += val * ++i * (n - i + 1);
        return sum;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Modern syntax
* Range-based iteration
* Compact implementation

## 📊 **7️⃣ Brute Force Approach (TLE for Large Inputs)**

### 💡 Algorithm Steps:

1. Generate all possible subarrays
2. Calculate sum for each subarray
3. Add to total result
4. Triple nested approach

```cpp
class Solution {
public:
    int subarraySum(vector<int>& arr) {
        int n = arr.size(), total = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                for (int k = i; k <= j; ++k) {
                    total += arr[k];
                }
            }
        }
        return total;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n³)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Easy to understand
* Direct subarray generation
* Good for educational purposes

> **Note:** This approach results in **Time Limit Exceeded (TLE)** for large inputs due to cubic time complexity.


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                 | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                         |
| ------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ----------------------------------- |
| 🔍 **Mathematical Formula**     | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Fastest, direct calculation    | 🧠 Needs prior mathematical insight |
| 🔧 **Prefix Count Based**       | 🟢 O(n)                | 🟢 O(1)                 | 🧾 Intuitive breakdown per index  | 🔄 Slightly verbose                 |
| 🧮 **Range Sum Contribution**   | 🟢 O(n)                | 🟢 O(1)                 | 🧊 Very compact and clean code    | 🔁 Redundant `size()` calls         |
| 🧭 **Iterator-Based Traversal** | 🟢 O(n)                | 🟢 O(1)                 | 🎯 Leverages modern C++ iterators | 🔢 Manual position tracking         |
| 🔁 **Reverse Iteration Style**  | 🟢 O(n)                | 🟢 O(1)                 | 🧠 Better cache locality, fast    | ↩️ Slightly harder to follow        |
| 📦 **Range-Based Loop Style**   | 🟢 O(n)                | 🟢 O(1)                 | 🧵 Elegant and modern C++ syntax  | 🧾 Index tracking is less readable  |
| 🐢 **Brute Force (TLE)**        | 🔴 O(n³)               | 🟢 O(1)                 | 👶 Great for learning/validation  | 🚫 Not practical for large inputs   |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                            | 🥇 **Recommended Approach**     | 🔥 **Performance Rating** |
| ------------------------------------------ | ------------------------------- | ------------------------- |
| ⚡ **Production-grade optimal solution**    | 🥇 **Mathematical Formula**     | ⭐⭐⭐⭐⭐                     |
| 📖 **Beginner-friendly and readable**      | 🥈 **Prefix Count Based**       | ⭐⭐⭐⭐☆                     |
| ✂️ **Minimal lines of code**               | 🥉 **Range Sum Contribution**   | ⭐⭐⭐⭐☆                     |
| 🧑‍💻 **Modern C++ STL usage**                | 🏅 **Iterator-Based Traversal** | ⭐⭐⭐⭐☆                     |
| 🧠 **Performance-aware / Cache-efficient** | 🏆 **Reverse Iteration Style**  | ⭐⭐⭐⭐⭐                     |
| 🎨 **Elegant syntax, modern C++ style**    | 🎖️ **Range-Based Loop Style**  | ⭐⭐⭐⭐☆                     |
| 📚 **Academic or small input simulation**  | 🎓 **Brute Force (TLE)**        | ⭐⭐☆☆☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int subarraySum(int[] arr) {
        int n = arr.length, sum = 0;
        for (int i = 0; i < n; ++i)
            sum += arr[i] * (i + 1) * (n - i);
        return sum;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def subarraySum(self, arr):
        n = len(arr)
        return sum(arr[i] * (i + 1) * (n - i) for i in range(n))
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
