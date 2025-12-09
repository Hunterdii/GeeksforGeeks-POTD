---
title: "🔢 Count Set Bits | GFG Solution 🔍"
keywords🏷️: ["🔢 count set bits", "🔍 bit manipulation", "📍 binary representation", "📈 mathematical pattern", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Count Set Bits problem: find total count of set bits from 1 to n using mathematical pattern recognition and bit manipulation. 🚀"
date: 📅 2025-11-29
---

# *29. Count Set Bits*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1)

## **🧩 Problem Description**

You are given a number `n`. Find the total count of set bits for all numbers from 1 to n (both inclusive).

A set bit refers to a bit in the binary representation of a number that is 1. The task is to efficiently count all such bits across the entire range.

## **📘 Examples**

### Example 1

```cpp
Input: n = 4
Output: 5
Explanation: For numbers from 1 to 4:
- 1: 0 0 1 => 1 set bit
- 2: 0 1 0 => 1 set bit
- 3: 0 1 1 => 2 set bits
- 4: 1 0 0 => 1 set bit
Therefore, the total set bits are 1 + 1 + 2 + 1 = 5.
```

### Example 2

```cpp
Input: n = 17
Output: 35
Explanation: From numbers 1 to 17 (both inclusive), the total number of set bits are 35.
```

## **🔒 Constraints**

* $1 \le n \le 10^8$

## **✅ My Approach**

The optimal approach uses **Mathematical Pattern Recognition** with **Bit Manipulation** to efficiently count set bits:

### **Recursive Pattern Recognition**

1. **Mathematical Insight:**
   * For any number n, we can find the highest power of 2 less than or equal to n (let's call it 2^x).
   * Count set bits in three parts:
     - Full pattern from 0 to (2^x - 1)
     - Contribution of the most significant bit from 2^x to n
     - Remaining set bits after removing the highest bit

2. **Pattern Formula:**
   * For numbers from 0 to (2^x - 1): Total set bits = x * 2^(x-1)
   * This is because each bit position i (0 to x-1) is set exactly 2^(x-1) times
   * MSB contribution from 2^x to n: (n - 2^x + 1) times the MSB is set

3. **Recursive Strategy:**
   * Find highest bit position x using log2(n)
   * Calculate full pattern bits: x * 2^(x-1)
   * Calculate MSB contribution: (n - 2^x + 1)
   * Recursively solve for remaining: countSetBits(n - 2^x)

4. **Base Case:**
   * If n == 0, return 0
   * This ensures termination of recursion

5. **Optimization:**
   * Using bit operations (1 << x instead of pow(2, x)) for faster computation
   * Logarithmic recursion depth ensures efficient performance

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(log n), as we recursively process the number by removing the highest bit in each step, leading to logarithmic depth recursion.
* **Expected Auxiliary Space Complexity:** O(log n), due to the recursion stack space. Each recursive call processes a smaller subproblem, resulting in log n depth.

## **🔧 Code (C)**

```c
int countSetBits(int n) {
    if (!n) return 0;
    int x = 0, temp = n;
    while (temp >>= 1) x++;
    return x * (1 << (x - 1)) + (n - (1 << x) + 1) + countSetBits(n - (1 << x));
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int countSetBits(int n) {
        if (!n) return 0;
        int x = log2(n);
        return x * (1 << (x - 1)) + (n - (1 << x) + 1) + countSetBits(n - (1 << x));
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Iterative Pattern Recognition**

### 💡 Algorithm Steps:

1. Use iterative approach to avoid recursion stack overhead.
2. For each bit position i, calculate how many times it appears as set bit in range [1, n].
3. Pattern: In every (2^(i+1)) numbers, bit i is set exactly 2^i times.
4. Accumulate contributions from all bit positions.

```cpp
class Solution {
public:
    int countSetBits(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i <<= 1) {
            int total = n + 1;
            int pairs = total / (i << 1);
            int rem = total % (i << 1);
            cnt += pairs * i + max(0, rem - i);
        }
        return cnt;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(log n) - Iterate through all bit positions once
* **Auxiliary Space:** 💾 O(1) - Constant space, no recursion

### ✅ **Why This Approach?**

* No recursion overhead or stack space
* More cache-friendly with iterative processing
* Direct pattern-based calculation

## 📊 **3️⃣ Mathematical Formula Approach**

### 💡 Algorithm Steps:

1. Increment n by 1 to simplify calculations (count from 0 to n).
2. For each bit position, calculate complete cycles and remaining elements.
3. Each cycle of length 2^(i+1) contributes 2^i set bits at position i.
4. Add remaining contribution if elements exceed complete cycles.

```cpp
class Solution {
public:
    int countSetBits(int n) {
        n++;
        int cnt = 0, pw = 1;
        while (pw <= n) {
            int total = (n / (pw * 2)) * pw;
            int rem = n % (pw * 2);
            if (rem > pw) total += rem - pw;
            cnt += total;
            pw <<= 1;
        }
        return cnt;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(log n) - Process each bit position once
* **Auxiliary Space:** 💾 O(1) - Only variables needed

### ✅ **Why This Approach?**

* Clean mathematical formula
* No recursion or complex branching
* Efficient bit manipulation

## 📊 **4️⃣ DP Memoization Approach**

### 💡 Algorithm Steps:

1. Use memoization to cache previously computed results.
2. Apply same recursive logic but store intermediate results.
3. Before computing, check if result exists in cache.
4. Significantly faster for multiple queries or repeated subproblems.

```cpp
class Solution {
public:
    unordered_map<int, int> memo;
    int countSetBits(int n) {
        if (n == 0) return 0;
        if (memo.count(n)) return memo[n];
        int x = log2(n);
        int pw = 1 << x;
        int res = x * (pw >> 1) + (n - pw + 1) + countSetBits(n - pw);
        return memo[n] = res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(log n) - Each unique subproblem solved once
* **Auxiliary Space:** 💾 O(log n) - Memoization map storage

### ✅ **Why This Approach?**

* Optimal for multiple queries on overlapping ranges
* Avoids redundant calculations
* Good balance between time and space


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Recursive Pattern**          | 🟢 O(log n)            | 🟡 O(log n)             | 🚀 Clean mathematical formula     | 🔧 Recursion stack overhead          |
| 🔄 **Iterative Pattern**          | 🟢 O(log n)            | 🟢 O(1)                 | ⚡ No recursion overhead          | 🔧 Slightly complex logic            |
| 🔍 **Mathematical Formula**       | 🟢 O(log n)            | 🟢 O(1)                 | 📖 Optimal bit manipulation       | 🔧 Requires pattern understanding    |
| 📊 **DP Memoization**             | 🟢 O(log n)            | 🟡 O(log n)             | 🎯 Good for multiple queries      | 💾 Extra space for memoization       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Iterative Pattern**             | ★★★★★                     |
| 📖 **Code clarity**                                   | 🥈 **Recursive Pattern**             | ★★★★☆                     |
| 🔧 **Multiple queries**                               | 🥉 **DP Memoization**                | ★★★★☆                     |
| 🎯 **Interview/Competitive**                          | 🏅 **Mathematical Formula**          | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public static int countSetBits(int n) {
        if (n == 0) return 0;
        int x = (int)(Math.log(n) / Math.log(2));
        return x * (1 << (x - 1)) + (n - (1 << x) + 1) + countSetBits(n - (1 << x));
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def countSetBits(self, n):
        ans = 0
        while n:
            x = n.bit_length() - 1
            if x == 0:
                ans += 1
                break
            ans += x * (1 << (x - 1)) + (n - (1 << x) + 1)
            n -= 1 << x
        return ans
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
