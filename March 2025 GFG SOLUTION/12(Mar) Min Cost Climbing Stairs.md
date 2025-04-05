# _12. Min Cost Climbing Stairs_

The problem can be found at the following link: [Question Link](https://leetcode.com/problems/min-cost-climbing-stairs/)

## **Problem Description**

Given an array of integers `cost[]`, where `cost[i]` represents the cost of the `i-th` step on a staircase, you can either:

- Pay the cost at `i-th` step and move **one step** forward.
- Pay the cost at `i-th` step and move **two steps** forward.

Return the **minimum cost** required to reach the top of the floor.

📌 **Assumptions:**

- **0-based indexing**
- You can start either from **step 0** or **step 1**

## **Examples**

### **Example 1:**

#### **Input:**

```cpp
cost[] = [10, 15, 20]
```

#### **Output:**

```cpp
15
```

#### **Explanation:**

The cheapest way is:

- Start at `cost[1] = 15`
- Jump **2 steps** to the top (no cost at the top)

<img src="https://github.com/user-attachments/assets/70112a65-01f8-4b37-9d6e-b9740c45049a" width="30%">

### **Example 2:**

#### **Input:**

```cpp
cost[] = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
```

#### **Output:**

```cpp
6
```

#### **Explanation:**

The cheapest way is:  
1 → 3 → 4 → 6 → 7 → 9 (Total cost = `1 + 1 + 1 + 1 + 1 + 1 = 6`)

<img src="https://github.com/user-attachments/assets/4cc857d1-2e6e-44df-ad87-35521adaff27" width="30%">

## **Constraints:**

- $\(2 \leq \text{cost.length} \leq 1000\)$
- $2 ≤ cost.size() ≤ 10^5$
- $\(0 \leq \text{cost[i]} \leq 999\)$

## **My Approach**

### **Algorithm Steps:**

1. **Use two variables** `a` and `b` to keep track of the **minimum cost** of the last two steps.
2. **Iterate through the cost array**, updating `b` using the recurrence relation:
   - `b = cost[i] + min(a, b)`
   - `a = previous b` (before update)
3. **Return** `min(a, b)`, representing the minimum cost to reach the top.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(N)`, as we iterate through the `cost` array once.
- **Expected Auxiliary Space Complexity:** `O(1)`, as we use only a constant amount of extra space (`a` and `b`).

## **Code (C++)**

```cpp
class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = cost[0], b = cost[1];
        for (int i = 2; i < cost.size(); i++)
            tie(a, b) = make_tuple(b, cost[i] + min(a, b));
        return min(a, b);
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **1️⃣ Dynamic Programming (O(N) Time, O(N) Space) — Tabulation**

### **Algorithm Steps:**

1. **Use an array `dp[]`** to store the minimum cost at each step.
2. **Base cases:**
   - `dp[0] = cost[0]`
   - `dp[1] = cost[1]`
3. **Recurrence relation:**  
   $\[
   \text{dp[i]} = \text{cost[i]} + \min(\text{dp[i-1]}, \text{dp[i-2]})
   $\]

```cpp
class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0], dp[1] = cost[1];
        for (int i = 2; i < n; i++)
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        return min(dp[n - 1], dp[n - 2]);
    }
};
```

✅ **Time Complexity:** `O(N)`  
✅ **Space Complexity:** `O(N)`

## **2️⃣ Recursive + Memoization (O(N) Time, O(N) Space)**

### **Algorithm Steps:**

1. **Use recursion with memoization** to avoid repeated calculations.
2. **Base cases:**
   - If `i < 0`, return `0`
   - If `i == 0 || i == 1`, return `cost[i]`
3. **Store computed results** in a `dp[]` array to prevent redundant calls.

```cpp
class Solution {
  public:
    vector<int> dp;
    int solve(vector<int>& cost, int i) {
        if (i < 0) return 0;
        if (i == 0 || i == 1) return cost[i];
        if (dp[i] != -1) return dp[i];
        return dp[i] = cost[i] + min(solve(cost, i - 1), solve(cost, i - 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        dp.assign(cost.size(), -1);
        int n = cost.size();
        return min(solve(cost, n - 1), solve(cost, n - 2));
    }
};
```

✅ **Time Complexity:** `O(N)`  
✅ **Space Complexity:** `O(N)`

## **3️⃣ Iterative Approach Without Extra Variables (O(N) Time, O(1) Space)**

### **Algorithm Steps:**

1. **Modify the input array `cost[]`** in-place to store the **cumulative minimum cost**.

```cpp
class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        for (int i = 2; i < cost.size(); i++)
            cost[i] += min(cost[i - 1], cost[i - 2]);
        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};
```

✅ **Time Complexity:** `O(N)`  
✅ **Space Complexity:** `O(1)`

## **Comparison of Approaches**

| **Approach**                         | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                         | ⚠️ **Cons**                     |
| ------------------------------------ | ---------------------- | ----------------------- | ----------------------------------- | ------------------------------- |
| **Iterative DP (Space Optimized)**   | 🟡 `O(N)`              | 🟢 `O(1)`               | Simple and fastest iterative method | Limited to Fibonacci-like logic |
| **Dynamic Programming (Tabulation)** | 🟡 `O(N)`              | 🔴 `O(N)`               | Easy to understand and implement    | Consumes extra space            |
| **Recursive + Memoization**          | 🟡 `O(N)`              | 🔴 `O(N)`               | Natural recursive logic             | Higher recursion overhead       |
| **Iterative In-Place Update**        | 🟡 `O(N)`              | 🟢 `O(1)`               | No extra variables used             | Modifies input array            |

## 💡 **Best Choice?**

✅ **For simplicity and efficiency:** Use **Iterative DP (Space Optimized)**.  
✅ **For an alternative approach without extra space:** Use **In-Place Iterative DP**.  
✅ **For understanding step-by-step execution:** Use **Tabulation DP**.

</details>

## **Code (Java)**

```java
class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int a = cost[0], b = cost[1];
        for (int i = 2; i < cost.length; i++) {
            int temp = b;
            b = cost[i] + Math.min(a, b);
            a = temp;
        }
        return Math.min(a, b);
    }
}
```

## **Code (Python)**

```python
class Solution:
    def minCostClimbingStairs(self, cost):
        for i in range(2, len(cost)):
            cost[i] += min(cost[i - 1], cost[i - 2])
        return min(cost[-1], cost[-2])
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
