## 06. Count ways to N'th Stair

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1)

### Problem Description

There are n stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways the person can reach the top (order does not matter).

**Example:**

Input:

```
n = 4
```

Output:

```
3
```

Explanation:
You can reach the 4th stair in 3 ways:

- 1, 1, 1, 1
- 1, 1, 2
- 2, 2

### Approach 1:

**My Approach:**

- We utilize dynamic programming to store the number of ways to reach each stair.
- We initialize a static vector `dp` with the number of ways to reach the first 11 stairs (as it is given until 10 in the problem statement).
- For \(n > 10\), the number of ways to reach the \(n\)th stair is \(1 + \left\lfloor\frac{n}{2}\right\rfloor\), as every alternate stair can be reached in 1 step.

**Time Complexity:**

- \(O(1)\), as we perform a constant number of operations regardless of the input \(n\).

**Code (C++):**

```cpp
class Solution {
public:
    long long countWays(int n) {
        static vector<long long> dp = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6};
        if (n <= 10) return dp[n];
        return 1 + (n / 2);
    }
};
```

### Approach 2:

**My Approach:**

- We utilize dynamic programming to store the number of ways to reach each stair.
- We initialize a dynamic array `dp` of size \(n + 1\) to store the number of ways to reach each stair.
- We iterate from the 2nd stair to the \(n\)th stair, and for each stair, the number of ways is the sum of the ways to reach the previous stair and, if the stair number is even, 1 (since we can also directly reach it from the stair before it).

**Time Complexity:**

- \(O(n)\), as we iterate through the stairs up to \(n\) to calculate the number of ways.

**Code (C++):**

```cpp
class Solution {
public:
    long long countWays(int n) {
        long long dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + (i % 2 == 0 ? 1 : 0);
        }
        return dp[n];
    }
};
```

### Approach 3:

**My Approach:**

- We directly compute the number of ways to reach the \(n\)th stair using the formula \(1 + \left\lfloor\frac{n}{2}\right\rfloor\), where \(\left\lfloor\frac{n}{2}\right\rfloor\) represents the integer division of \(n\) by 2.

**Time Complexity:**

- \(O(1)\), as we perform a constant number of operations regardless of the input \(n\).

**Code (C++):**

```cpp
class Solution {
public:
    long long countWays(int n) {
        return 1 + (n / 2);
    }
};
```

### Approach 4:

**My Approach:**

- We directly compute the number of ways to reach the \(n\)th stair using the formula \(1 + \left\lfloor\frac{n}{2}\right\rfloor\), where \(\left\lfloor\frac{n}{2}\right\rfloor\) represents the integer division of \(n\) by 2.

**Time Complexity:**

- \(O(1)\), as we perform a constant number of operations regardless of the input \(n\).

**Code (C++):**

```cpp
class Solution {
public:
    long long countWays(int n) {
        long long ways = 1 + (n / 2);
        return ways;
    }
};
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
