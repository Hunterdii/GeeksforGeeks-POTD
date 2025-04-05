## 07. Maximize Dot Product

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/maximize-dot-product2649/1)

### Problem Description

Given two arrays a and b of positive integers of size n and m where n >= m, the task is to maximize the dot product by inserting zeros in the second array but you cannot disturb the order of elements.

Dot product of array a and b of size n is a[0]*b[0] + a[1]*b[1] + ... + a[n-1]\*b[n-1].

**Example:**

Input:

```
n = 5, a[] = {2, 3, 1, 7, 8}
m = 3, b[] = {3, 6, 7}
```

Output:

```
107
```

Explanation:
We get maximum dot product after inserting 0 at first and third positions in the second array.
Therefore `b` becomes {0, 3, 0, 6, 7}.
Maximum dot product = \(2 \times 0 + 3 \times 3 + 1 \times 0 + 7 \times 6 + 8 \times 7\) = 107.

**Expected Time Complexity:** O(n \times m)
**Expected Auxiliary Space:** O(n \times m)

### My Approaches

#### Approach 1: Dynamic Programming

1. **Initialization:**
   - Create a 2D vector `dp` of size \((n + 1) \times (m + 1)\) and initialize all values to -1.
2. **Recursive Function:**
   - Implement a recursive function `solve()` that takes `n`, `m`, arrays `a` and `b`, and the `dp` vector as parameters.
   - Base Cases:
     - If `m` is 0, return 0.
     - If `n` is less than `m`, return \(\text{INT_MIN}\).
     - If the value for the current `n` and `m` combination is already calculated in `dp`, return it.
   - Recursive Cases:
     - Calculate two values, `t2` and `t3`.
       - `t2` represents the maximum dot product when the current element of array `a` is not chosen.
       - `t3` represents the maximum dot product when the current element of array `a` is chosen and multiplied with the current element of array `b`.
     - Return the maximum of `t2` and `t3`.
3. **Main Function:**
   - Initialize the `dp` vector and call the `solve()` function with appropriate parameters.

### Time and Auxiliary Space Complexity

#### Approach 1: Dynamic Programming

- **Expected Time Complexity:** O(n \* m), as we have to calculate values for each combination of `n` and `m`.
- **Expected Auxiliary Space Complexity:** O(n \* m), as we use a 2D vector of size \((n + 1) \times (m + 1)\) for memoization.

### Code (C++)

#### Approach 1: Dynamic Programming

```cpp
class Solution {
public:
    int maxDotProduct(int n, int m, int a[], int b[]) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, a, b, dp);
    }

    int solve(int n, int m, int a[], int b[], vector<vector<int>>& dp) {
        if (m == 0) {
            return 0;
        }
        if (n < m) {
            return INT_MIN;
        }
        if (dp[n][m] != -1) {
            return dp[n][m];
        }
        int t2 = solve(n - 1, m, a, b, dp);
        int t3 = a[n - 1] * b[m - 1] + solve(n - 1, m - 1, a, b, dp);
        return dp[n][m] = max(t2, t3);
    }
};
```

#### Approach 2: Another Recursive Approach

1. **Recursive Function:**
   - Implement a recursive function `solve()` that takes `n`, `m`, arrays `a` and `b` as parameters.
   - Base Cases:
     - If `m` is 0, return 0.
     - If `n` is less than `m`, return \(\text{INT_MIN}\).
   - Recursive Cases:
     - Calculate two values, `t2` and `t3`.
       - `t2` represents the maximum dot product when the current element of array `a` is not chosen.
       - `t3` represents the maximum dot product when the current element of array `a` is chosen and multiplied with the current element of array `b`.
     - Return the maximum of `t2` and `t3`.

#### Approach 2: Another Recursive Approach

- **Expected Time Complexity:** O(n \* m), as we explore all possible combinations of `n` and `m`.
- **Expected Auxiliary Space Complexity:** O(1), as we don't use any additional space other than the function call stack.

#### Approach 2: Another Recursive Approach

```cpp
class Solution{
public:
    int solve(int n, int m, int a[], int b[]) {
        if (m == 0) {
            return 0;
        }
        if (n < m) {
            return INT_MIN;
        }
        int t2 = solve(n - 1, m, a, b);
        int t3 = a[n - 1] * b[m - 1] + solve(n - 1, m - 1, a, b);
        return max(t2, t3);
    }

    int maxDotProduct(int n, int m, int a[], int b[]) {
        return solve(n, m, a, b);
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
