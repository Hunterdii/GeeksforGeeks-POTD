---
title: "🔢 Josephus Problem | GFG Solution 🎯"
keywords🏷️: ["🔢 josephus problem", "🔄 recursion", "🔁 dynamic programming", "🎯 mathematical formula", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Josephus Problem: find the survivor's position in a circular elimination game using iterative DP, recursion, and mathematical optimization. 🚀"
date: 📅 2025-01-24
---

# *24. Josephus Problem*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/josephus-problem/1)

## **🧩 Problem Description**

You are playing a game with `n` people standing in a circle, numbered from 1 to n. Starting from person 1, every `k`th person is eliminated in a circular fashion. The process continues until only one person remains.

Given integers `n` and `k`, return the position (1-based index) of the person who will survive.

## **📘 Examples**

### Example 1

```cpp
Input: n = 5, k = 2
Output: 3
Explanation: Firstly, the person at position 2 is killed, then the person at position 4 is killed, 
then the person at position 1 is killed. Finally, the person at position 5 is killed. 
So the person at position 3 survives.
```

### Example 2

```cpp
Input: n = 7, k = 3
Output: 4
Explanation: The elimination order is 3 → 6 → 2 → 7 → 5 → 1, and the person at position 4 survives.
```

## **🔒 Constraints**

* $1 \le n, k \le 500$

## **✅ My Approach**

The optimal approach uses **Iterative Dynamic Programming** to build the solution from the base case upward:

### **Iterative DP Solution**

1. **Base Case Understanding:**
   * When only 1 person remains (n=1), the survivor is at position 0 in 0-indexed notation.
   * We need to convert this to 1-indexed for the final answer.

2. **Build Solution Iteratively:**
   * Start with the base case: `pos = 0` (survivor position for 1 person in 0-indexed).
   * For each number of people from 2 to n, calculate the survivor position.
   * Use the recurrence relation: `pos = (pos + k) % i`, where `i` is the current number of people.

3. **Mathematical Insight:**
   * After eliminating one person from a circle of n people, we have n-1 people remaining.
   * The problem reduces to finding the survivor in a circle of n-1 people.
   * The position shifts by k due to the elimination pattern.
   * The modulo operation handles the circular nature of the arrangement.

4. **Convert to 1-Based Index:**
   * Add 1 to the final 0-indexed position to get the 1-based answer.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), as we iterate from 2 to n, performing constant-time operations in each iteration to calculate the survivor position.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space to store the position variable and loop counter, independent of input size.

## **⚙️ Code (C)**

```c
int josephus(int n, int k) {
    int pos = 0;
    for (int i = 2; i <= n; i++) pos = (pos + k) % i;
    return pos + 1;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int josephus(int n, int k) {
        int pos = 0;
        for (int i = 2; i <= n; i++) pos = (pos + k) % i;
        return pos + 1;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Recursive Approach**

### 💡 Algorithm Steps:

1. Base case: If only one person remains (n=1), they are at position 1.
2. Recursively solve for n-1 people to find the survivor position in a smaller circle.
3. Adjust the position by adding k steps and taking modulo n to handle circular wrapping.
4. Convert from 0-indexed to 1-indexed result by proper adjustment.

```cpp
class Solution {
public:
    int josephus(int n, int k) {
        return n == 1 ? 1 : (josephus(n - 1, k) + k - 1) % n + 1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Makes n recursive calls, one for each person eliminated
* **Auxiliary Space:** 💾 O(n) - Recursion call stack depth proportional to number of people

### ✅ **Why This Approach?**

* Intuitive recursive logic that directly mirrors the problem definition
* Natural translation from the mathematical recurrence relation
* Easy to understand the step-by-step elimination process
* Good for educational purposes and small inputs

## 📊 **3️⃣ Zero-Indexed Iterative**

### 💡 Algorithm Steps:

1. Initialize position to 0, representing the survivor in a circle of 1 person (0-indexed).
2. Iteratively build solution from 1 to n people, updating position at each step.
3. Use the formula: `pos = (pos + k) % i` where i is the current circle size.
4. Convert final 0-indexed position to 1-indexed by adding 1.

```cpp
class Solution {
public:
    int josephus(int n, int k) {
        int res = 0;
        for (int i = 1; i <= n; i++) res = (res + k) % i;
        return res + 1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single loop iterating through all circle sizes from 1 to n
* **Auxiliary Space:** 💾 O(1) - Only uses a constant number of variables

### ✅ **Why This Approach?**

* Clean separation between 0-indexed calculation and final conversion
* Standard iterative dynamic programming pattern with clear logic flow
* Minimal variable usage maximizes cache efficiency
* Easier to trace and debug compared to recursion

## 📊 **4️⃣ Mathematical Direct Formula (k=2)**

### 💡 Algorithm Steps:

1. Special optimization when k equals 2 (every second person eliminated).
2. Find the highest power of 2 that is less than or equal to n.
3. Calculate survivor position using closed-form formula: `2 * (n - power_of_2) + 1`.
4. For general k, fall back to iterative approach.

```cpp
class Solution {
public:
    int josephus(int n, int k) {
        if (k == 2) {
            int p = 1;
            while (p * 2 <= n) p *= 2;
            return 2 * (n - p) + 1;
        }
        int pos = 0;
        for (int i = 2; i <= n; i++) pos = (pos + k) % i;
        return pos + 1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(log n) for k=2 due to power-of-2 calculation, O(n) for general k
* **Auxiliary Space:** 💾 O(1) - Uses constant extra space regardless of input size

### ✅ **Why This Approach?**

* Extremely efficient for the common k=2 case with logarithmic time
* Demonstrates deep mathematical insight into the problem structure
* Useful for competitive programming where k=2 is frequently tested
* Shows how problem-specific optimizations can dramatically improve performance

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔁 **Iterative DP**               | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal space, no stack risk   | 🔧 Less intuitive than recursion     |
| 🔄 **Recursive**                  | 🟢 O(n)                | 🟡 O(n)                 | 📖 Natural problem mapping        | 💾 Stack overflow risk for large n   |
| 0️⃣ **Zero-Indexed**              | 🟢 O(n)                | 🟢 O(1)                 | 🎯 Clean separation of concerns   | 🔧 Extra conversion step             |
| 🧮 **Math Formula (k=2)**         | 🟢 O(log n)            | 🟢 O(1)                 | ⭐ Lightning fast for k=2         | 📍 Only works for specific k value   |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General optimal solution**                       | 🥇 **Iterative DP**                  | ★★★★★                     |
| 📖 **Learning/Understanding**                         | 🥈 **Recursive**                     | ★★★★☆                     |
| 🔧 **Code clarity and debugging**                     | 🥉 **Zero-Indexed**                  | ★★★★☆                     |
| 🎯 **Competitive programming (k=2)**                  | 🏅 **Math Formula**                  | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int josephus(int n, int k) {
        int pos = 0;
        for (int i = 2; i <= n; i++) pos = (pos + k) % i;
        return pos + 1;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def josephus(self, n, k):
        pos = 0
        for i in range(2, n + 1): pos = (pos + k) % i
        return pos + 1
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
