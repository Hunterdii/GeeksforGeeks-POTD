---
title: "🔢 AND In Range | GFG Solution 🔍"
keywords🏷️: ["🔢 bitwise AND", "🔍 bit manipulation", "📍 range query", "📈 Brian Kernighan", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the AND In Range problem: find bitwise AND of all numbers in range [l, r] using efficient bit manipulation techniques. 🚀"
date: 📅 2025-11-26
---

# *26. AND In Range*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/and-operation5726/1)

## **🧩 Problem Description**

You are given two integers `l` and `r`. Find the result after applying the series of **Bitwise AND ( & )** operation on every natural number between the range `l` to `r` (including both).

The bitwise AND operation compares each bit of two numbers and returns 1 only if both bits are 1. When we perform AND on a series of consecutive numbers, the result preserves only the common high-order bits (the common binary prefix) while all differing lower-order bits become 0.

## **📘 Examples**

### Example 1

```cpp
Input: l = 8, r = 13
Output: 8
Explanation: 
8 AND 9 AND 10 AND 11 AND 12 AND 13 = 8.
Binary: 1000 & 1001 & 1010 & 1011 & 1100 & 1101 = 1000 (which is 8)
```

### Example 2

```cpp
Input: l = 2, r = 3
Output: 2
Explanation: 
2 AND 3 = 2.
Binary: 10 & 11 = 10 (which is 2)
```

## **🔒 Constraints**

* $1 \le l \le r \le 10^9$

## **✅ My Approach**

The optimal approach uses **Brian Kernighan's Algorithm** to efficiently find the common binary prefix of all numbers in the range:

### **Brian Kernighan's Bit Clearing**

1. **Understanding the Pattern:**
   * When performing AND on consecutive numbers, bits from right to left start differing.
   * The result is the common prefix of bits shared by all numbers in range.
   * Example: For [12,13,14,15], binary is [1100, 1101, 1110, 1111] → common prefix is 1100.

2. **Algorithm:**
   * Use Brian Kernighan's technique: `r &= (r - 1)` clears the rightmost set bit.
   * Keep clearing bits from `r` until `r` becomes less than or equal to `l`.
   * This efficiently removes all differing bits from right side.

3. **Why It Works:**
   * `r & (r-1)` removes the rightmost 1-bit from r.
   * In a range [l, r], all bits that differ between l and r will eventually be cleared.
   * The remaining value is the common prefix - our answer.

4. **Optimization:**
   * Each iteration removes one differing bit from right.
   * Loop terminates when all differing bits are cleared.
   * Result is the largest number ≤ r that can be formed using only common prefix bits.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(log(r - l)), where the loop runs proportional to the number of differing bits between l and r. In the worst case, this is O(log n) where n is the maximum value of r. The algorithm clears one bit per iteration until r becomes less than or equal to l.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables l and r, with no extra data structures required.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int andInRange(int l, int r) {
        while (l < r) r &= r - 1;
        return r;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Bit Shifting Approach**

### 💡 Algorithm Steps:

1. Continue right shifting both numbers until they become equal.
2. Count the number of shifts performed during this process.
3. Left shift the result back by the same count.
4. This finds the common prefix of bits in binary representation.

```cpp
class Solution {
public:
    int andInRange(int l, int r) {
        int shift = 0;
        while (l != r) {
            l >>= 1;
            r >>= 1;
            shift++;
        }
        return l << shift;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(log n) - Based on number of bits
* **Auxiliary Space:** 💾 O(1) - Constant space usage

### ✅ **Why This Approach?**

* Clear logic based on common bit prefix
* Easy to understand and visualize
* Standard approach for range AND problems

## 📊 **3️⃣ XOR-Based Approach**

### 💡 Algorithm Steps:

1. Find XOR of l and r to identify differing bits.
2. Find the position of most significant bit in XOR result.
3. Create a mask to clear all bits from that position onwards.
4. Apply mask to either l or r to get the common prefix.

```cpp
class Solution {
public:
    int andInRange(int l, int r) {
        int xor_val = l ^ r;
        int msb = 0;
        while (xor_val) {
            xor_val >>= 1;
            msb++;
        }
        int mask = (~0) << msb;
        return l & mask;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(log n) - Iterating through bits
* **Auxiliary Space:** 💾 O(1) - Only using constants

### ✅ **Why This Approach?**

* Uses XOR to identify bit differences
* Mathematical approach to find common prefix
* Good for understanding bit manipulation

## 📊 **4️⃣ Alternative Kernighan's Algorithm**

### 💡 Algorithm Steps:

1. Use two's complement property: `r & -r` isolates the rightmost set bit.
2. Subtract this isolated bit from r to clear it.
3. Continue until r becomes less than or equal to l.
4. This achieves the same result as `r &= (r-1)` but uses different bit manipulation.

```cpp
class Solution {
public:
    int andInRange(int l, int r) {
        while (l < r) r -= r & -r;
        return r;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(log n) - Number of set bits to clear
* **Auxiliary Space:** 💾 O(1) - Constant space

### ✅ **Why This Approach?**

* Very concise implementation
* Uses two's complement bit trick
* Alternative formulation of bit clearing

## 📊 **5️⃣ Most Significant Bit Approach**

### 💡 Algorithm Steps:

1. Find the position where l and r first differ in their binary representation.
2. Calculate the common prefix length by comparing bits from left to right.
3. Create a mask with all 1s up to the common prefix length.
4. Apply this mask to l (or r) to extract the common prefix.

```cpp
class Solution {
public:
    int andInRange(int l, int r) {
        int shift = 0;
        while ((l >> shift) != (r >> shift)) shift++;
        return (l >> shift) << shift;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(log n) - Finding differing bit position
* **Auxiliary Space:** 💾 O(1) - Constant space

### ✅ **Why This Approach?**

* Direct approach to find common prefix
* Clear separation of finding and reconstructing prefix
* Good for educational purposes

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Brian Kernighan (r&=r-1)**  | 🟢 O(log n)            | 🟢 O(1)                 | 🚀 Shortest code                  | 🔧 Less intuitive logic              |
| 🔍 **Bit Shifting**               | 🟢 O(log n)            | 🟢 O(1)                 | 📖 Clear and intuitive            | 📝 Slightly more code                |
| 📊 **XOR-Based**                  | 🟢 O(log n)            | 🟢 O(1)                 | 🎯 Mathematical insight           | 🐌 More operations required          |
| 🔄 **Alternative Kernighan**      | 🟢 O(log n)            | 🟢 O(1)                 | ⭐ Very concise                   | 🔧 Uses two's complement             |
| 🎯 **MSB Approach**               | 🟢 O(log n)            | 🟢 O(1)                 | 📚 Educational value              | 🔍 More explicit logic               |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Shortest code needed**                        | 🥇 **Brian Kernighan (r&=r-1)**      | ★★★★★                     |
| 📖 **Readability priority**                        | 🥈 **Bit Shifting**                  | ★★★★★                     |
| 🔧 **Interview explanation**                       | 🥉 **Bit Shifting**                  | ★★★★☆                     |
| 🎯 **Competitive Programming**                     | 🏅 **Brian Kernighan**               | ★★★★★                     |
| 📚 **Learning bit manipulation**                   | 🎖️ **XOR-Based**                     | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int andInRange(int l, int r) {
        while (l < r) r &= r - 1;
        return r;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def andInRange(self, l, r):
        while l < r: r &= r - 1
        return r
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

