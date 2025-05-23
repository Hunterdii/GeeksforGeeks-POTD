# *23. Dice throw*

The problem can be found at the following link: 🔗 **[Question Link](https://www.geeksforgeeks.org/problems/dice-throw5349/1)**


## **🧩 Problem Description**

Given `n` dice, each having faces numbered from `1` to `m`, find the number of ways to get a total sum `x` when all the dice are thrown.

You must count every distinct sequence of face-up values (order matters).

You are given:

* `n` dice,
* each having `m` faces numbered from 1 to `m`,
* and a target sum `x`.

Find the number of ways to get the sum `x` using the `n` dice. The result can be large, so **return it modulo 10⁹+7**.




## **📘 Examples**

### **Example 1:**

#### **Input:**

```
m = 6, n = 3, x = 12
```

#### **Output:**

```
25
```

#### **Explanation:**

There are 25 distinct sequences of three 6-faced dice that sum up to 12.


### **Example 2:**

#### **Input:**

```
m = 2, n = 3, x = 6
```

#### **Output:**

```
1
```

#### **Explanation:**

Only the sequence \[2,2,2] sums to 6 when using three 2-faced dice.


## **🔒 Constraints**

* \$1 \leq m, n, x \leq 50\$
* \$1 \leq x \leq 2500\$


## **✅ My Approach**

### **Classic 2D Dynamic Programming**

We use a classic **bottom-up dynamic programming** strategy.
Let `dp[i][j]` represent the number of ways to get sum `j` using `i` dice.

### **Recurrence Relation:**

To get a sum of `j` with `i` dice, try all face values `k = 1...m`, and add ways to get `j - k` with `i - 1` dice:

```
dp[i][j] = ∑ dp[i-1][j-k] for all 1 ≤ k ≤ m and j−k ≥ 0
```

### **Algorithm Steps:**

1. Create a 2D vector `dp[n+1][x+1]` and initialize `dp[0][0] = 1`.
2. Loop `i` from `1` to `n` (number of dice).
3. Loop `j` from `1` to `x` (target sum).
4. For each `k` from `1` to `m`, if `j ≥ k`, add `dp[i-1][j-k]` to `dp[i][j]`.
5. Return `dp[n][x]`.


## **🧮 Time and Auxiliary Space Complexity**

* **Time Complexity:** O(n × x × m)
  We compute each state `(i, j)` using up to `m` previous states.

* **Auxiliary Space Complexity:** O(n × x)
  We use a 2D DP table with `n+1` rows and `x+1` columns.


## **🧑‍💻 Code (C++)**

```cpp
class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        const int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(x + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= x; ++j)
                for (int k = 1; k <= m && k <= j; ++k)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
        return dp[n][x];
    }
};
```


<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>


## 📊 **2️⃣ Space Optimized DP**

Instead of using a 2D table, use two 1D arrays: `dp` and `tmp`.

### **Algorithm Steps:**

1. Use two 1D arrays `dp` and `tmp`, where `dp[j]` represents the number of ways to form sum `j` using `i-1` dice.
2. Initialize `dp[0] = 1` since there's one way to reach sum 0 with 0 dice.
3. For each die `i` from 1 to `n`, do the following:

   * Clear the `tmp` array.
   * For each target sum `j` from 1 to `x`:

     * Loop through each face value `k` from 1 to `m` (and `k <= j`) and accumulate ways from `dp[j - k]` to `tmp[j]`.
4. After processing a die, assign `tmp` to `dp`.
5. Return `dp[x]`, which holds the number of ways to get sum `x` with `n` dice.

```cpp
class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        const int mod = 1e9 + 7;
        vector<int> dp(x + 1), tmp(x + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fill(tmp.begin(), tmp.end(), 0);
            for (int j = 1; j <= x; ++j)
                for (int k = 1; k <= m && k <= j; ++k)
                    tmp[j] = (tmp[j] + dp[j - k]) % mod;
            dp = tmp;
        }
        return dp[x];
    }
};
```

### ✅ **Why This Approach?**

* Minimizes memory use with only two rows (1D arrays).
* Retains full accuracy and efficiency of 2D dynamic programming.
* Especially useful for large `n` and `x`.

#### 📝 **Complexity Analysis:**

* **Time:** O(n × x × m) — Three nested loops for each die, each sum, and each face.
* **Auxiliary Space:** O(x) — Only two 1D arrays of size `x + 1` are used.



## 📊 **3️⃣ Recursive + Memoization**

### **Algorithm Steps:**

### **Algorithm Steps:**

1. Use recursion to simulate choosing each face for every die.
2. At each recursive call:

   * If `n == 0`, return 1 if `x == 0`, else return 0.
   * If `x < 0`, return 0 (invalid state).
   * Use memoization to store and reuse previously computed results.
3. Try all face values from 1 to `m` and recurse with `n - 1` dice and `x - face`.

```cpp
class Solution {
  public:
    int dp[51][2501];
    int mod = 1e9 + 7;
    
    int solve(int n, int x, int m) {
        if (n == 0) return x == 0;
        if (x < 0) return 0;
        if (dp[n][x] != -1) return dp[n][x];
        int res = 0;
        for (int i = 1; i <= m; ++i)
            res = (res + solve(n - 1, x - i, m)) % mod;
        return dp[n][x] = res;
    }

    int noOfWays(int m, int n, int x) {
        memset(dp, -1, sizeof(dp));
        return solve(n, x, m);
    }
};
```

### ✅ **Why This Approach?**

* Naturally expresses the problem as a recursive decision tree.
* Easy to understand, especially when learning recursion + memoization.
* Less control over performance and higher overhead due to recursion stack.

#### 📝 **Complexity Analysis:**

* **Time:** O(n × x × m) — Each state `(n, x)` is computed once with up to `m` choices.
* **Auxiliary Space:** O(n × x) — For memoization + recursion stack.



## 🆚 **Comparison of Approaches**

| **Approach**               | ⏱️ **Time** | 🗂️ **Space** | ✅ **Pros**                 | ⚠️ **Cons**                          |
| -------------------------- | ----------- | ------------- | -------------------------- | ------------------------------------ |
| 📈 Classic 2D DP           | 🟢 O(n·x·m) | 🔸 O(n·x)     | Easy to understand and implement | More space than needed          |
| ➿ Space-Optimized DP       | 🟢 O(n·x·m) | 🟢 O(x)      | Fast and memory-efficient        | Slightly less intuitive         |
| 🔁 Recursive + Memoization | 🟢 O(n·x·m) | 🔸 O(n·x)     | Good for learning and debugging  | Stack overflow risk for large n |

### ✅ **Best Choice by Scenario**

| **Scenario**                       | **Recommended Approach**   |
| ---------------------------------- | -------------------------- |
| 🏆 Minimize both time & memory     | 🥇 Space-Optimized DP      |
| 📚 Simplicity and clarity             | 🥈 Classic 2D DP           |
| 💡 Recursive problem-solving focus | 🥉 Recursive + Memoization |

</details>


## **🧑‍💻 Code (Java)**

```java
class Solution {
    static int noOfWays(int m, int n, int x) {
        int mod = (int)1e9 + 7;
        int[][] dp = new int[n + 1][x + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= x; ++j)
                for (int k = 1; k <= m && k <= j; ++k)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
        return dp[n][x];
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def noOfWays(self, m, n, x):
        mod = 10**9 + 7
        dp = [[0] * (x + 1) for _ in range(n + 1)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            for j in range(1, x + 1):
                for k in range(1, min(m, j) + 1):
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod
        return dp[n][x]
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
