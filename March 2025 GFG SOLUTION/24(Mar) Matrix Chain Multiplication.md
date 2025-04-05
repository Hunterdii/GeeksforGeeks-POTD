# _24. Matrix Chain Multiplication_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1)

## **Problem Description**

Given an array `arr[]` where the `i`th matrix has the dimensions **(arr[i-1] × arr[i])** for `i ≥ 1`, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of scalar multiplications.

You need to find the **minimum number of multiplications** required to multiply the matrices.

## **Examples**

### **Example 1:**

#### **Input:**

```plaintext
arr[] = [2, 1, 3, 4]
```

#### **Output:**

```plaintext
20
```

#### **Explanation:**

We have three matrices:

- `M1 (2×1)`, `M2 (1×3)`, and `M3 (3×4)`.
- There are two ways to multiply them:

  1. **((M1 × M2) × M3)**

     - Cost = `(2 × 1 × 3) + (2 × 3 × 4) = 30`

  2. **(M1 × (M2 × M3))**
     - Cost = `(1 × 3 × 4) + (2 × 1 × 4) = 20`

The minimum cost is **20**.

### **Example 2:**

#### **Input:**

```plaintext
arr[] = [1, 2, 3, 4, 3]
```

#### **Output:**

```plaintext
30
```

#### **Explanation:**

We have four matrices:

- `M1 (1×2)`, `M2 (2×3)`, `M3 (3×4)`, and `M4 (4×3)`.
- The minimum multiplication cost is **30**.

### **Example 3:**

#### **Input:**

```plaintext
arr[] = [3, 4]
```

#### **Output:**

```plaintext
0
```

#### **Explanation:**

There is only **one** matrix, so no multiplication is required.

## **Constraints:**

- $\(2 \leq \text{arr.size()} \leq 100\)$
- $\(1 \leq \text{arr}[i] \leq 200\)$

## **My Approach**

## **Bottom-Up Dynamic Programming**

### **Key Idea:**

We define **`dp[i][j]`** as the minimum number of scalar multiplications required to multiply matrices **from index `i` to `j`**.

### **Algorithm Steps:**

1. **Create a DP table** `dp[i][j]`, initialized to 0.
2. Iterate over **chain lengths** (`len = 2` to `n-1`).
3. Iterate over **starting indices** (`i = 1` to `n-len`), setting `j = i + len - 1`.
4. Compute the **minimum cost** for multiplying matrices from `i` to `j` by iterating over possible partition points `k`.
5. **Return `dp[1][n-1]`**, which contains the minimum multiplication cost.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N³), since we iterate over `O(N²)` subproblems, and each subproblem requires `O(N)` operations.
- **Expected Auxiliary Space Complexity:** O(N²), for storing the DP table.

## **Code (C++)**

```cpp
class Solution {
public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len < n; len++) {
            for (int i = 1, j = len; j < n; i++, j++) {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                    dp[i][j] = min(dp[i][j], arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j]);
            }
        }
        return dp[1][n - 1];
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **1️⃣ Recursive + Memoization (Top-Down DP) – O(N³)**

### **Algorithm Steps:**

1. Use a `dp[i][j]` table to store results of subproblems.
2. If `dp[i][j]` is already computed, return it.
3. Otherwise, compute `solve(i, j)` recursively and store results.

### **Code (C++):**

```cpp
class Solution {
public:
    int dp[1005][1005];

    int solve(vector<int>& arr, int i, int j) {
        if (i == j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            int cost = arr[i-1] * arr[k] * arr[j] + solve(arr, i, k) + solve(arr, k+1, j);
            ans = min(ans, cost);
        }
        return dp[i][j] = ans;
    }

    int matrixMultiplication(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));
        return solve(arr, 1, arr.size() - 1);
    }
};
```

✅ **Time Complexity:** `O(N³)`  
✅ **Space Complexity:** `O(N²)`

## **Comparison of Approaches**

| **Approach**                | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                     | ⚠️ **Cons**               |
| --------------------------- | ---------------------- | ----------------------- | ------------------------------- | ------------------------- |
| **Bottom-Up DP**            | 🟢 O(N³)               | 🟡 O(N²)                | Efficient and easy to implement | Uses `O(N²)` space        |
| **Recursive + Memoization** | 🟢 O(N³)               | 🔴 O(N²)                | Reduces redundant calculations  | Still uses `O(N²)` memory |

✅ **Best Choice?**

- If **memory is not an issue**, use **Bottom-Up DP** (`O(N³) Time, O(N²) Space`).
- If **you need recursion**, use **Memoized DP** (`O(N³) Time, O(N²) Space`).
</details>


## **Code (Java)**

```java
class Solution {
    static int matrixMultiplication(int[] arr) {
        int n = arr.length;
        int[][] dp = new int[n][n];

        for (int len = 2; len < n; len++)
            for (int i = 1, j = len; j < n; i++, j++) {
                dp[i][j] = Integer.MAX_VALUE;
                for (int k = i; k < j; k++)
                    dp[i][j] = Math.min(dp[i][j], arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j]);
            }
        return dp[1][n - 1];
    }
}
```

## **Code (Python)**

```python
class Solution:
    def matrixMultiplication(self, arr):
        n, dp = len(arr), [[0] * len(arr) for _ in range(len(arr))]

        for l in range(2, n):
            for i in range(1, n - l + 1):
                j, dp[i][i + l - 1] = i + l - 1, float('inf')
                for k in range(i, j):
                    dp[i][j] = min(dp[i][j], arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j])

        return dp[1][n - 1]
```

## **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
