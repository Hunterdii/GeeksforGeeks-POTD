---
title: "🔢 Subset XOR | GFG Solution 🔍"
keywords🏷️: ["🔢 subset xor", "🔍 bit manipulation", "📍 xor properties", "📈 mathematical pattern", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Subset XOR problem: find maximum size subset from 1 to n with XOR equal to n using mathematical XOR pattern recognition. 🚀"
date: 📅 2025-11-28
---

# *28. Subset XOR*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/subset-xor--175953/1)

## **🧩 Problem Description**

Given a positive integer `n`, find a subset of numbers from 1 to n (inclusive), where each number can be used at most once, such that:

- The XOR of all elements in the subset is exactly `n`.
- The size of the subset is as large as possible.
- If multiple such subsets exist, choose the lexicographically smallest one.

**Lexicographical Order:** A subset A[] is lexicographically smaller than subset B[] if at the first index where they differ, A[i] < B[i] (based on character ASCII/Unicode values). If all elements match but one subset ends earlier, the shorter subset is considered smaller.

## **📘 Examples**

### Example 1

```cpp
Input: n = 4
Output: [1, 2, 3, 4]
Explanation: We choose all the elements from 1 to 4. Its XOR value is equal to n (1^2^3^4 = 4). 
This is the maximum possible size of the subset.
```

### Example 2

```cpp
Input: n = 3
Output: [1, 2]
Explanation: 1 ^ 2 = 3. This is the smallest lexicographical answer possible with maximum 
size of subset i.e 2.
```

## **🔒 Constraints**

* $1 \le n \le 10^5$

## **✅ My Approach**

The optimal approach uses **XOR mathematical properties** to determine which element to exclude:

### **XOR Pattern Recognition**

1. **Mathematical Insight:**
   * XOR of consecutive numbers from 1 to n follows a pattern based on n % 4.
   * Pattern: 
     - n % 4 = 0: XOR(1 to n) = n
     - n % 4 = 1: XOR(1 to n) = 1
     - n % 4 = 2: XOR(1 to n) = n + 1
     - n % 4 = 3: XOR(1 to n) = 0

2. **Exclusion Strategy:**
   * To get XOR = n, we need to exclude specific element(s).
   * For n % 4 = 0: Include all (XOR already = n)
   * For n % 4 = 1: Exclude (n-1) to get XOR = n
   * For n % 4 = 2: Exclude 1 to get XOR = n
   * For n % 4 = 3: Exclude n to get XOR = n

3. **Implementation:**
   * Calculate n & 3 (equivalent to n % 4) for efficiency.
   * Determine start and end range based on pattern.
   * Build result array excluding the identified element.

4. **Lexicographical Order:**
   * Since we're building from smallest to largest and excluding specific elements, the result is naturally lexicographically smallest.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), as we iterate through the range from 1 to n once to build the result array.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables (excluding the output array which is required for the result).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> subsetXOR(int n) {
        vector<int> ans;
        int r = n & 3;
        int start = (r == 2) ? 2 : 1;
        int end = (r == 3) ? n - 1 : n;
        for (int i = start; i <= end; i++)
            if (r != 1 || i != n - 1) ans.push_back(i);
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>


## 📊 **2️⃣ Lookup Table Approach**

### 💡 Algorithm Steps:

1. Precompute which element to exclude for each n%4 case in a lookup array.
2. Calculate n % 4 to determine the pattern.
3. Iterate from 1 to n and exclude the predetermined element.
4. Build result in single pass using exclusion logic.

```cpp
class Solution {
public:
    vector<int> subsetXOR(int n) {
        vector<int> ans;
        int exclude[] = {-1, n - 1, 1, n};
        int mod = n % 4;
        for (int i = 1; i <= n; i++)
            if (i != exclude[mod]) ans.push_back(i);
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with conditional check
* **Auxiliary Space:** 💾 O(1) - Fixed size lookup array

### ✅ **Why This Approach?**

* Minimal branching with lookup table
* Cache-friendly pattern access
* Elegant solution using precomputation

## 📊 **3️⃣ Range Building with STL Approach**

### 💡 Algorithm Steps:

1. Determine start and end points based on n%4 value.
2. Use STL iota function to efficiently fill ranges.
3. Handle special case for n%4=1 separately with exclusion.
4. Optimize memory allocation by pre-sizing the result vector.

```cpp
class Solution {
public:
    vector<int> subsetXOR(int n) {
        vector<int> ans;
        int m = n % 4;
        if (m == 0) {
            ans.resize(n);
            iota(ans.begin(), ans.end(), 1);
        } else if (m == 2) {
            ans.resize(n - 1);
            iota(ans.begin(), ans.end(), 2);
        } else if (m == 3) {
            ans.resize(n - 1);
            iota(ans.begin(), ans.end(), 1);
        } else {
            for (int i = 1; i <= n; i++)
                if (i != n - 1) ans.push_back(i);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear range generation
* **Auxiliary Space:** 💾 O(1) - Constant space for computation

### ✅ **Why This Approach?**

* Uses STL algorithms for efficiency
* Minimal conditional branching
* Optimized memory allocation with resize

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Modulo Pattern**             | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Most compact code              | 🔧 Requires pattern knowledge        |
| 📊 **Lookup Table**               | 🟢 O(n)                | 🟢 O(1)                 | 🎯 Minimal branching              | 🔧 Extra array storage               |
| ⚡ **Range Building**             | 🟢 O(n)                | 🟢 O(1)                 | ⭐ STL optimization               | 🔧 More verbose code                 |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Modulo Pattern**                | ★★★★★                     |
| 🔧 **Code readability**                               | 🥈 **Lookup Table**                  | ★★★★☆                     |
| 🎯 **Interview/Competitive**                          | 🏅 **Modulo Pattern**                | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public static ArrayList<Integer> subsetXOR(int n) {
        ArrayList<Integer> ans = new ArrayList<>();
        int r = n & 3;
        int start = (r == 2) ? 2 : 1;
        int end = (r == 3) ? n - 1 : n;
        for (int i = start; i <= end; i++)
            if (r != 1 || i != n - 1) ans.add(i);
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def subsetXOR(self, n : int):
        ans, r = [], n & 3
        start = 2 if r == 2 else 1
        end = n - 1 if r == 3 else n
        for i in range(start, end + 1):
            if r != 1 or i != n - 1: ans.append(i)
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
