---
title: "🎮 Game of XOR | GFG Solution 🔍"
keywords🏷️: ["🎮 game of xor", "🔢 bitwise xor", "📊 subarray contribution", "🧮 mathematical optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Game of XOR problem: compute the bitwise XOR of all subarray XORs using mathematical contribution analysis and parity optimization. 🚀"
date: 📅 2025-11-25
---

# *25. Game of XOR*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/game-of-xor1541/1)

## **🧩 Problem Description**

You are given an integer array `arr[]`. The value of a subarray is defined as the **bitwise XOR of all elements** in that subarray.

Your task is to compute the **bitwise XOR of the values of all possible subarrays** of `arr[]`.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 2, 3]
Output: 2
Explanation:
xor[1] = 1
xor[1, 2] = 3
xor[2, 3] = 1
xor[1, 2, 3] = 0
xor[2] = 2
xor[3] = 3
Result: 1 ^ 3 ^ 1 ^ 0 ^ 2 ^ 3 = 2
```

### Example 2

```cpp
Input: arr[] = [1, 2]
Output: 0
Explanation:
xor[1] = 1
xor[1, 2] = 3
xor[2] = 2
Result: 1 ^ 3 ^ 2 = 0
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $0 \le \text{arr}[i] \le 10^9$

## **✅ My Approach**

The optimal approach uses **mathematical contribution analysis** with **parity checking** to avoid the brute force generation of all subarrays:

### **Mathematical Contribution with Parity Optimization**

1. **Key Observation:**
   * Each element `arr[i]` appears in multiple subarrays.
   * The element at index `i` appears in exactly `(i + 1) * (n - i)` subarrays.
   * Due to XOR properties, an element only contributes to the final result if it appears an **odd number of times**.

2. **Parity Analysis:**
   * Since `a ^ a = 0`, if an element appears an even number of times, it cancels itself out.
   * We only need to XOR elements that appear an odd number of times across all subarrays.

3. **Efficient Calculation:**
   * For each element at index `i`, calculate its contribution count: `(i + 1) * (n - i)`.
   * Check if this count is odd using bitwise AND: `((i + 1) * (n - i)) & 1`.
   * If odd, include the element in the final XOR result.

4. **Single Pass Solution:**
   * Iterate through the array once, checking the parity condition for each element.
   * Accumulate the XOR of elements with odd contribution counts.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We perform a single traversal through the array, and for each element, we execute constant-time operations (multiplication, bitwise AND, and XOR).
* **Expected Auxiliary Space Complexity:** O(1), as we only use a fixed number of variables (`xor_sum`, `n`, `i`) regardless of the input size. No additional data structures are required.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int xor_sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (((i + 1) * (n - i)) & 1) xor_sum ^= arr[i];
        }
        return xor_sum;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Mathematical Contribution Count**

### 💡 Algorithm Steps:

1. Calculate contribution of each element based on subarray count.
2. Element at index i appears in (i+1) * (n-i) subarrays.
3. XOR only when contribution count is odd.
4. Return final XOR result.

```cpp
class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int res = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            int cnt = (i + 1) * (n - i);
            if (cnt % 2) res ^= arr[i];
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through array
* **Auxiliary Space:** 💾 O(1) - Constant space usage

### ✅ **Why This Approach?**

* Clear mathematical reasoning
* Easy to understand contribution logic
* Direct calculation without bit manipulation

## 📊 **3️⃣ Parity Check with Modulo**

### 💡 Algorithm Steps:

1. Check parity of both left count and right count separately.
2. Use modulo operation for explicit odd/even checking.
3. XOR element when both counts are odd.
4. Accumulate result and return.

```cpp
class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            if ((i + 1) % 2 && (arr.size() - i) % 2) ans ^= arr[i];
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear traversal
* **Auxiliary Space:** 💾 O(1) - No extra space

### ✅ **Why This Approach?**

* Explicit parity checking with modulo
* Readable condition structure
* Straightforward implementation

## 📊 **4️⃣ Bitwise AND Optimization**

### 💡 Algorithm Steps:

1. Use bitwise AND with 1 to check odd parity efficiently.
2. Check if both position and remaining elements are odd.
3. Apply XOR when condition satisfies.
4. Return accumulated XOR value.

```cpp
class Solution {
public:
    int subarrayXor(vector<int>& arr) {
        int result = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (((i + 1) & 1) && ((arr.size() - i) & 1)) result ^= arr[i];
        }
        return result;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single iteration
* **Auxiliary Space:** 💾 O(1) - Constant space

### ✅ **Why This Approach?**

* Bitwise operations for faster execution
* Compact and efficient condition checking
* Optimal for competitive programming

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔢 **Multiplication Check**       | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Most optimized                 | ➗ Extra multiplication              |
| 📐 **Count Calculation**          | 🟢 O(n)                | 🟢 O(1)                 | 📖 Clear mathematical logic       | 🔢 Redundant calculation             |
| ✔️ **Modulo Parity**             | 🟢 O(n)                | 🟢 O(1)                 | 🎯 Explicit condition check       | 🐌 Modulo slightly slower            |
| ⚡ **Bitwise AND**                | 🟢 O(n)                | 🟢 O(1)                 | ⭐ Fastest bitwise operations     | 🧩 Less readable for beginners       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Multiplication Check**          | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **Count Calculation**             | ★★★★☆                     |
| 🔧 **Learning purpose**                               | 🥉 **Modulo Parity**                 | ★★★★☆                     |
| 🎯 **Competitive programming**                        | 🏅 **Bitwise AND**                   | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int subarrayXor(int[] arr) {
        int xor_sum = 0;
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            if ((((i + 1) * (n - i)) & 1) == 1) xor_sum ^= arr[i];
        }
        return xor_sum;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def subarrayXor(self, arr):
        xor_sum = 0
        n = len(arr)
        for i in range(n):
            if ((i + 1) * (n - i)) & 1: xor_sum ^= arr[i]
        return xor_sum
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
