# *13. nCr*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/ncr1019/1)

## **🧩 Problem Description**

Given two integers `n` and `r`, return the value of the binomial coefficient C(n, r), defined as the number of ways to choose `r` objects from a set of `n` without regard to order. It is given by:

$$
C(n, r) = \frac{n!}{r!\,(n-r)!}
$$

If $r > n$, return 0. It is guaranteed that the result will fit within a 32-bit integer.

## **📘 Examples**

### **Example 1:**

#### **Input:**

```
n = 5, r = 2
```

#### **Output:**

```
10
```

#### **Explanation:**

$$
C(5,2) = \frac{5!}{2!\,3!} = \frac{120}{2\times6} = 10
$$

### **Example 2:**

#### **Input:**

```
n = 2, r = 4
```

#### **Output:**

```
0
```

#### **Explanation:**

Since $r > n$, $C(2,4)=0$.

### **Example 3:**

#### **Input:**

```
n = 5, r = 0
```

#### **Output:**

```
1
```

#### **Explanation:**

$$
C(5,0) = \frac{5!}{0!\,5!} = 1.
$$

## **🔒 Constraints**

* $1 \leq n \leq 100$
* $0 \leq r \leq 100$


## **✅ My Approach**

### **Modular Inverse + Factorials**

We compute factorials up to `n` modulo $10^9+7$, then use Fermat’s little theorem to find modular inverses in $O(n + \log(\text{MOD}))$:

1. Precompute `fact[i] = i! mod MOD` for $0 \le i \le n$.
2. Compute `inv[n] = fact[n]^(MOD-2) mod MOD` via fast exponentiation.
3. Build `inv[i-1] = inv[i] * i mod MOD` for $i = n$ down to 1 (inverse factorials).
4. Return

   $$
   C(n,r) = fact[n] \times inv[r] \times inv[n-r]\ \bmod\ \text{MOD}.
   $$


### **Algorithm Steps:**

1. **Handle** if $r > n$: return 0.
2. **Initialize** constants: `MOD = 10^9+7`.
3. **Allocate** two arrays of size `n+1`: `fact[]`, `inv[]`.
4. **Compute factorials**:

   ```
   fact[0] = 1
   for i in 1..n:
     fact[i] = fact[i-1] * i % MOD
   ```
5. **Compute inverse factorial of n**:

   ```
   inv[n] = pow_mod(fact[n], MOD-2)
   ```

   using binary exponentiation in $O(\log\,\text{MOD})$.
6. **Compute remaining inverses**:

   ```
   for i = n..1:
     inv[i-1] = inv[i] * i % MOD
   ```
7. **Combine**:

   ```
   return fact[n] * inv[r] % MOD * inv[n-r] % MOD
   ```


## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:**
  $O(n + \log(\text{MOD}))$, since we build factorials in $O(n)$, compute one modular exponentiation in $O(\log\,\text{MOD})$, and build inverse factorials in $O(n)$.

* **Expected Auxiliary Space Complexity:**
  $O(n)$, for storing `fact[]` and `inv[]` arrays of size $n+1$.


## **🧠 Code (C++)**

```cpp
class Solution {
    static const int MOD = 1e9+7;
    long long modexp(long long x, long long y) {
        long long res = 1;
        while (y) {
            if (y & 1) res = res * x % MOD;
            x = x * x % MOD;
            y >>= 1;
        }
        return res;
    }
public:
    int nCr(int n, int r) {
        if (r > n) return 0;
        vector<long long> fact(n+1, 1), inv(n+1);
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i-1] * i % MOD;
        inv[n] = modexp(fact[n], MOD-2);
        for (int i = n; i > 0; --i)
            inv[i-1] = inv[i] * i % MOD;
        return fact[n] * inv[r] % MOD * inv[n-r] % MOD;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>


## 📊 **2️⃣ DP Table (Pascal’s Triangle)**

### **Idea**

Use the identity $C(i, j) = C(i-1, j-1) + C(i-1, j)$ to build a DP table of size $(n+1)\times(r+1)$.

### **Algorithm Steps**

1. Allocate `C[n+1][r+1]`, initialize with zeros.
2. For each `i` in `0..n`:

   * For each `j` in `0..min(i,r)`:

     * If `j == 0` or `j == i`: `C[i][j]=1`.
     * Else: `C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD`.
3. Return `C[n][r]`.

```cpp
class Solution {
public:
    int nCr(int n, int r) {
        if (r > n) return 0;
        const int MOD = 1e9+7;
        vector<vector<int>> C(n+1, vector<int>(r+1, 0));
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= min(i, r); ++j) {
                if (j == 0 || j == i) C[i][j] = 1;
                else C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
            }
        }
        return C[n][r];
    }
};
```

⏱️ **Time:** $O(n \times r)$
🗂️ **Space:** $O(n \times r)$


## 📊 **3️⃣ Recursive + Memoization**

### **Idea**

Use recursion on the identity $C(n,r)=C(n-1,r-1)+C(n-1,r)$ with memoization to avoid recomputation.

### **Algorithm Steps**

1. Base: if `r == 0` or `r == n`, return 1.
2. If `dp[n][r]` is cached, return it.
3. Otherwise compute `(solve(n-1,r-1) + solve(n-1,r)) % MOD`, store in `dp[n][r]`.

```cpp
class Solution {
    static const int MOD = 1e9+7;
    int dp[101][101];
    int solve(int n, int r) {
        if (r == 0 || r == n) return 1;
        if (dp[n][r] != -1) return dp[n][r];
        return dp[n][r] = (solve(n-1, r-1) + solve(n-1, r)) % MOD;
    }
public:
    int nCr(int n, int r) {
        if (r > n) return 0;
        memset(dp, -1, sizeof dp);
        return solve(n, r);
    }
};
```

⏱️ **Time:** $O(n \times r)$
🗂️ **Space:** $O(n \times r)$



## 🆚 **Comparison of Approaches**

| **Approach**                 | ⏱️ **Time**                  | 🗂️ **Space**      | ✅ **Pros**                        | ⚠️ **Cons**                            |
| ---------------------------- | ---------------------------- | ------------------ | --------------------------------- | -------------------------------------- |
| Modular Inverse + Factorials | 🟢 $O(n + \log\,\text{MOD})$ | 🟢 $O(n)$          | Fast; handles large $n$; reusable | Requires mod exponentiation step       |
| DP Table                     | 🔸 $O(n \times r)$           | 🔸 $O(n \times r)$ | Simple; no exponentiation         | Higher time/memory for large inputs    |
| Recursive + Memoization      | 🔸 $O(n \times r)$           | 🔸 $O(n \times r)$ | Elegant recursion                 | Recursion/memo overhead; risk of stack |


### ✅ **Best Choice?**

| **Use Case**                           | **Recommended Approach**        |
| -------------------------------------- | ------------------------------- |
| Single query or multiple large queries | 🥇 Modular Inverse + Factorials |
| Educational/demo or small $n,r$        | 🥈 DP Table                     |
| Academic demonstration of recursion    | 🥉 Recursive + Memoization      |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    static final int MOD = (int)1e9+7;
    long modexp(long x, long y) {
        long res = 1;
        while (y > 0) {
            if ((y & 1) == 1) res = res * x % MOD;
            x = x * x % MOD;
            y >>= 1;
        }
        return res;
    }
    public int nCr(int n, int r) {
        if (r > n) return 0;
        long[] fact = new long[n+1], inv = new long[n+1];
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i-1] * i % MOD;
        inv[n] = modexp(fact[n], MOD-2);
        for (int i = n; i > 0; --i)
            inv[i-1] = inv[i] * i % MOD;
        return (int)(fact[n] * inv[r] % MOD * inv[n-r] % MOD);
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    MOD = 10**9 + 7

    def power(self, x, y):
        res = 1
        while y:
            if y & 1:
                res = res * x % self.MOD
            x = x * x % self.MOD
            y >>= 1
        return res

    def nCr(self, n: int, r: int) -> int:
        if r > n:
            return 0
        fact = [1] * (n+1)
        for i in range(1, n+1):
            fact[i] = fact[i-1] * i % self.MOD
        inv = [1] * (n+1)
        inv[n] = self.power(fact[n], self.MOD-2)
        for i in range(n, 0, -1):
            inv[i-1] = inv[i] * i % self.MOD
        return fact[n] * inv[r] % self.MOD * inv[n-r] % self.MOD
```


## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

--- 

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
