---
title: "🐸 Frog Jump | GFG Solution 🔍"
keywords🏷️: ["🐸 frog jump", "🔍 dynamic programming", "📍 space optimization", "📈 DP", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Frog Jump problem: find minimum cost for frog to reach last stair by jumping 1 or 2 steps using dynamic programming with space optimization. 🚀"
date: 📅 2025-11-04
---

# *04. Frog Jump*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/geek-jump/1)

## **🧩 Problem Description**

You are given an integer array `height[]` where `height[i]` represents the height of the i-th stair. A frog starts from the first stair and wants to reach the last stair. From any stair i, the frog has two options:
- Jump to the (i+1)th stair
- Jump to the (i+2)th stair

The cost of a jump is the absolute difference in height between the two stairs. Your task is to determine the **minimum total cost** required for the frog to reach the last stair.

## **📘 Examples**

### Example 1

```cpp
Input: heights[] = [20, 30, 40, 20]
Output: 20
Explanation: Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
jump from stair 0 to 1: cost = |30 - 20| = 10
jump from stair 1 to 3: cost = |20 - 30| = 10
Total Cost = 10 + 10 = 20
```

### Example 2

```cpp
Input: heights[] = [30, 20, 50, 10, 40]
Output: 30
Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
jump from stair 0 to 2: cost = |50 - 30| = 20
jump from stair 2 to 4: cost = |40 - 50| = 10
Total Cost = 20 + 10 = 30
```

## **🔒 Constraints**

* $1 \le \text{height.size()} \le 10^5$
* $0 \le \text{height}[i] \le 10^4$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming with Space Optimization** to efficiently compute the minimum cost:

### **Space Optimized Dynamic Programming**

1. **Identify the Problem Pattern:**
   * This is a classic DP problem where current state depends only on previous two states.
   * At each stair, we need to make an optimal decision based on cost from previous two stairs.

2. **Define State:**
   * Let `dp[i]` represent the minimum cost to reach stair `i`.
   * We only need to track last two values instead of entire array.

3. **Base Cases:**
   * Cost to reach stair 0 is 0 (starting position).
   * Cost to reach stair 1 is `|height[1] - height[0]|` (only one way to reach).

4. **Recurrence Relation:**
   * For each stair `i`, frog can arrive from stair `i-1` or `i-2`.
   * `dp[i] = min(dp[i-1] + |height[i] - height[i-1]|, dp[i-2] + |height[i] - height[i-2]|)`

5. **Space Optimization:**
   * Since we only need previous two states, use two variables `a` and `b` instead of array.
   * After computing current cost, shift values: `a = b`, `b = current`.

6. **Final Answer:**
   * The minimum cost to reach last stair will be stored in variable `b`.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of stairs. We traverse the array once, performing constant time operations at each stair to compute the minimum cost.
* **Expected Auxiliary Space Complexity:** O(1), as we only use two variables to track the previous two states instead of maintaining an entire DP array, resulting in constant space usage.

## **🧑‍💻 Code (C)**

```c
int minCost(int height[], int n) {
    if (n == 1) return 0;
    int a = 0, b = abs(height[1] - height[0]);
    for (int i = 2; i < n; i++) {
        int c = (b + abs(height[i] - height[i - 1]) < a + abs(height[i] - height[i - 2])) ? 
                b + abs(height[i] - height[i - 1]) : a + abs(height[i] - height[i - 2]);
        a = b;
        b = c;
    }
    return b;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if (n == 1) return 0;
        int a = 0, b = abs(height[1] - height[0]);
        for (int i = 2; i < n; i++) {
            int c = min(b + abs(height[i] - height[i - 1]), a + abs(height[i] - height[i - 2]));
            a = b;
            b = c;
        }
        return b;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Dynamic Programming (Tabulation)**

### 💡 Algorithm Steps:

1. Create a DP array where dp[i] represents minimum cost to reach position i.
2. Initialize base cases: dp[0] = 0 and dp[1] = cost from 0 to 1.
3. For each position, compute minimum of jumping from previous or two steps back.
4. Return the last element containing minimum cost to reach the end.

```cpp
class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if (n == 1) return 0;
        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = abs(height[1] - height[0]);
        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 1] + abs(height[i] - height[i - 1]),
                        dp[i - 2] + abs(height[i] - height[i - 2]));
        }
        return dp[n - 1];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through array
* **Auxiliary Space:** 💾 O(n) - DP array storage

### ✅ **Why This Approach?**

* Clear visualization of subproblem solutions
* Easy to debug and trace intermediate values
* Foundation for understanding space optimization

## 📊 **3️⃣ Recursive with Memoization**

### 💡 Algorithm Steps:

1. Define recursive function to compute minimum cost from position i to end.
2. Base case: if at last position, return 0.
3. Store computed results in memo array to avoid recomputation.
4. Return minimum of taking one step or two steps forward with respective costs.

```cpp
class Solution {
public:
    int solve(vector<int>& h, int i, vector<int>& memo) {
        if (i >= h.size() - 1) return 0;
        if (memo[i] != -1) return memo[i];
        int one = abs(h[i + 1] - h[i]) + solve(h, i + 1, memo);
        int two = (i + 2 < h.size()) ? abs(h[i + 2] - h[i]) + solve(h, i + 2, memo) : INT_MAX;
        return memo[i] = min(one, two);
    }
    int minCost(vector<int>& height) {
        vector<int> memo(height.size(), -1);
        return solve(height, 0, memo);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each state computed once with memoization
* **Auxiliary Space:** 💾 O(n) - Recursion stack and memo array

### ✅ **Why This Approach?**

* Natural top-down thinking process
* Easy to convert from pure recursion
* Good for understanding DP state transitions

## 📊 **4️⃣ Bottom-Up with Variable Names**

### 💡 Algorithm Steps:

1. Use descriptive variable names for previous two states instead of array indices.
2. Initialize first two positions as base cases.
3. Iterate forward computing optimal cost using previous results.
4. Update variables by shifting: second_prev becomes prev, current becomes new prev.

```cpp
class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        if (n == 1) return 0;
        int second_prev = 0;
        int prev = abs(height[1] - height[0]);
        for (int i = 2; i < n; i++) {
            int jump_one = prev + abs(height[i] - height[i - 1]);
            int jump_two = second_prev + abs(height[i] - height[i - 2]);
            int current = min(jump_one, jump_two);
            second_prev = prev;
            prev = current;
        }
        return prev;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear iteration through array
* **Auxiliary Space:** 💾 O(1) - Only constant variables used

### ✅ **Why This Approach?**

* Most readable with descriptive variable names
* Optimal space complexity
* Production-ready clean code

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Space Optimized DP**        | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal time & space           | 🔧 Less intuitive initially          |
| 🔍 **Tabulation DP**              | 🟢 O(n)                | 🟡 O(n)                 | 📖 Easy to visualize              | 💾 Extra space required              |
| 📊 **Memoization**                | 🟢 O(n)                | 🟡 O(n)                 | 🎯 Natural recursion flow         | 🐌 Stack overhead                    |
| 🔄 **Descriptive Variables**      | 🟢 O(n)                | 🟢 O(1)                 | ⭐ Best readability               | 🔧 Slightly more verbose             |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Space Optimized DP**            | ★★★★★                     |
| 📖 **Learning DP concepts**                           | 🥈 **Tabulation DP**                 | ★★★★☆                     |
| 🔧 **Understanding recursion**                        | 🥉 **Memoization**                   | ★★★★☆                     |
| 🎯 **Production code**                                | 🏅 **Descriptive Variables**         | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    int minCost(int[] height) {
        int n = height.length;
        if (n == 1) return 0;
        int a = 0, b = Math.abs(height[1] - height[0]);
        for (int i = 2; i < n; i++) {
            int c = Math.min(b + Math.abs(height[i] - height[i - 1]), 
                            a + Math.abs(height[i] - height[i - 2]));
            a = b;
            b = c;
        }
        return b;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minCost(self, height):
        n = len(height)
        if n == 1: return 0
        a, b = 0, abs(height[1] - height[0])
        for i in range(2, n):
            c = min(b + abs(height[i] - height[i - 1]), a + abs(height[i] - height[i - 2]))
            a, b = b, c
        return b
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
