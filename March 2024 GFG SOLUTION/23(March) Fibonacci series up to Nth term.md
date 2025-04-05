## 23. Fibonacci Series up to Nth Term

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/fibonacci-series-up-to-nth-term/1)

### Problem Description

Given an integer `n`, return the Fibonacci series up to the `n`th term. Since the terms can become very large, return the terms modulo \(10^9 + 7\).

**Example:**

Input:

```
n = 5
```

Output:

```
0 1 1 2 3 5
```

Explanation:
0 1 1 2 3 5 is the Fibonacci series up to the 5th term.

### My Approach

1. **Initialization:**
   - Create a vector `ans` to store the Fibonacci series up to the \(n\)th term.
   - Initialize the first two terms of the series, `ans[0]` and `ans[1]`, as 0 and 1 respectively.
2. **Fibonacci Calculation:**
   - Iterate from `i = 2` to `n`.
   - Calculate the \(i\)th term of the Fibonacci series as the sum of the previous two terms: \(ans[i] = (ans[i - 1] + ans[i - 2]) \% MOD\), where `MOD` is \(10^9 + 7\).
3. **Return:**
   - Return the vector `ans` containing the Fibonacci series up to the \(n\)th term.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the series up to the \(n\)th term.
- **Expected Auxiliary Space Complexity:** O(n), as we use a vector of size \(n + 1\) to store the Fibonacci series.

### Code (C++)

```cpp
class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> Series(int n) {
        vector<int> ans(n + 1);
        ans[0] = 0;
        ans[1] = 1;

        for (int i = 2; i <= n; ++i) {
            ans[i] = (ans[i - 1] + ans[i - 2]) % MOD;
        }

        return ans;
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
