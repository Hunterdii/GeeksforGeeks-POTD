---
title: "🔢 All Numbers with Specific Difference | GFG Solution 🎯"
keywords🏷️: ["🔢 binary search", "📊 digit sum", "📈 optimization", "🔍 search algorithm", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to All Numbers with Specific Difference: count numbers where difference between number and sum of digits meets threshold using binary search. 🚀"
date: 📅 2025-02-15
---

# *15. All Numbers with Specific Difference*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/all-numbers-with-specific-difference3558/1)

## **🧩 Problem Description**

Given a positive number `n` and a number `d`, find the count of positive numbers smaller or equal to `n` such that the **difference between the number and sum of its digits** is greater than or equal to the given specific value `d`.

In mathematical terms, find count of numbers `x` where: `1 ≤ x ≤ n` and `x - sumOfDigits(x) ≥ d`

## **📘 Examples**

### Example 1

```cpp
Input: n = 13, d = 2
Output: 4
Explanation: There are 4 numbers satisfying the conditions. These are 10, 11, 12 and 13.
- 10 - (1+0) = 9 ≥ 2 ✓
- 11 - (1+1) = 9 ≥ 2 ✓
- 12 - (1+2) = 9 ≥ 2 ✓
- 13 - (1+3) = 9 ≥ 2 ✓
```

### Example 2

```cpp
Input: n = 14, d = 3
Output: 5
Explanation: There are 5 numbers satisfying the conditions. These are 10, 11, 12, 13 and 14.
```

### Example 3

```cpp
Input: n = 100, d = 10
Output: 81
Explanation: Numbers from 20 to 100 satisfy the condition (81 numbers total).
```

## **🔒 Constraints**

* $1 \le n \le 10^9$
* $1 \le d \le 10^9$

## **✅ My Approach**

The optimal solution uses **Binary Search** to find the smallest number satisfying the condition:

### **Binary Search on Answer**

1. **Key Observation:**
   * For any number `x`, the value `x - sumOfDigits(x)` increases monotonically as `x` increases.
   * Sum of digits grows much slower (logarithmically) compared to the number itself.
   * This monotonic property allows us to use binary search.

2. **Binary Search Setup:**
   * Search for the **smallest number** `k` where `k - sumOfDigits(k) ≥ d`
   * All numbers from `k` to `n` will satisfy the condition.
   * Answer = `n - k + 1`

3. **Search Logic:**
   * `low = 1`, `high = n`
   * For each `mid`, check if `mid - sumOfDigits(mid) >= d`
   * If true: condition satisfied, search for smaller numbers (move `high` left)
   * If false: need larger numbers (move `low` right)

4. **Result Calculation:**
   * After binary search, `low` points to the first valid number.
   * Count = `n - low + 1` = `n - high` (where high is last invalid position)

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(log²n), where the outer binary search runs in O(log n) iterations, and each digit sum calculation takes O(log n) time for a number with log n digits.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables, regardless of input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int getCount(int n, int d) {
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2, sum = 0, temp = mid;
            while (temp) sum += temp % 10, temp /= 10;
            if (mid - sum >= d) hi = mid - 1;
            else lo = mid + 1;
        }
        return n - hi;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Helper Function Approach**

### 💡 Algorithm Steps:

1. Create a separate helper function to calculate sum of digits.
2. Use binary search to find the threshold number.
3. Binary search finds the largest number NOT satisfying the condition.
4. Return count of numbers from threshold to n.

```cpp
class Solution {
public:
    int sumOfDigit(int K) {
        int sod = 0;
        while (K) {
            sod += K % 10;
            K /= 10;
        }
        return sod;
    }
    
    int getCount(int n, int d) {
        int low = 1, high = n;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mid - sumOfDigit(mid) < d)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return n - high;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(log²n) - Binary search with digit sum calculation
* **Auxiliary Space:** 💾 O(1) - Constant space usage

### ✅ **Why This Approach?**

* Clean separation of concerns with helper function
* Easy to test and debug digit sum logic independently
* More readable code structure

## 📊 **3️⃣ Iterative Refinement**

### 💡 Algorithm Steps:

1. Start with full range [1, n] for binary search.
2. For each iteration, compute digit sum inline without helper.
3. Narrow search range based on condition satisfaction.
4. Track the boundary between valid and invalid numbers.

```cpp
class Solution {
public:
    int getCount(int n, int d) {
        int l = 1, r = n, ans = n + 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int digitSum = 0, x = m;
            while (x > 0) digitSum += x % 10, x /= 10;
            if (m - digitSum >= d) ans = m, r = m - 1;
            else l = m + 1;
        }
        return n - ans + 1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(log²n) - Logarithmic search with digit processing
* **Auxiliary Space:** 💾 O(1) - No extra data structures

### ✅ **Why This Approach?**

* Explicitly tracks first valid answer
* Clear boundary management
* Alternative calculation method (n - ans + 1)

## 📊 **4️⃣ Mathematical Optimization**

### 💡 Algorithm Steps:

1. Observe that for most numbers, digit sum is relatively small.
2. Use binary search but optimize digit sum calculation.
3. Cache intermediate results where beneficial.
4. Return precise count using boundary analysis.

```cpp
class Solution {
public:
    int getCount(int n, int d) {
        auto digitSum = [](int num) {
            int sum = 0;
            for (; num; num /= 10) sum += num % 10;
            return sum;
        };
        
        int left = 1, right = n, threshold = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid - digitSum(mid) >= d) threshold = mid, right = mid - 1;
            else left = mid + 1;
        }
        return threshold ? n - threshold + 1 : 0;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(log²n) - Binary search dominates
* **Auxiliary Space:** 💾 O(1) - Only variables used

### ✅ **Why This Approach?**

* Modern C++ lambda for cleaner code
* Handles edge case where no valid numbers exist
* Functional programming style

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Inline Binary Search**       | 🟢 O(log²n)            | 🟢 O(1)                 | 🚀 Most concise code              | 🔧 Less readable for beginners       |
| 🔄 **Helper Function**            | 🟢 O(log²n)            | 🟢 O(1)                 | 📖 Clear separation of logic      | 🔧 Slightly more lines               |
| 📊 **Iterative Refinement**       | 🟢 O(log²n)            | 🟢 O(1)                 | ⭐ Explicit answer tracking       | 🔧 Different calculation method      |
| 🧮 **Mathematical Optimization**  | 🟢 O(log²n)            | 🟢 O(1)                 | 🎨 Modern C++ features            | 🔧 Lambda overhead (minimal)         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Competitive programming**                        | 🥇 **Inline Binary Search**          | ★★★★★                     |
| 📖 **Interview clarity**                              | 🥈 **Helper Function**               | ★★★★★                     |
| 🔧 **Production code**                                | 🥉 **Mathematical Optimization**     | ★★★★☆                     |
| 🎯 **Learning purposes**                              | 🏅 **Iterative Refinement**          | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int getCount(int n, int d) {
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2, sum = 0, temp = mid;
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }
            if (mid - sum >= d) hi = mid - 1;
            else lo = mid + 1;
        }
        return n - hi;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def getCount(self, n, d):
        lo, hi = 1, n
        while lo <= hi:
            mid = (lo + hi) // 2
            digit_sum = sum(int(digit) for digit in str(mid))
            if mid - digit_sum >= d:
                hi = mid - 1
            else:
                lo = mid + 1
        return n - hi
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
