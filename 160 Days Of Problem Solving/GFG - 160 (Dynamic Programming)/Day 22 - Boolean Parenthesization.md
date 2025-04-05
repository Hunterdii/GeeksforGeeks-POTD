---
Difficulty: Hard
Source: 160 Days of Problem Solving
Tags:
  - Dynamic Programming
---

# 🚀 _Day 22. Boolean Parenthesization_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/boolean-parenthesization5610)

## 💡 **Problem Description:**

Given a **boolean expression** `s` consisting of:

- **Operands**:
  - `'T'` → **True**
  - `'F'` → **False**
- **Operators**:
  - `'&'` → **Boolean AND**
  - `'|'` → **Boolean OR**
  - `'^'` → **Boolean XOR**

Count the **number of ways** we can parenthesize the expression such that it evaluates to **True**.

## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**

```cpp
s = "T|T&F^T"
```

#### **Output:**

```cpp
4
```

#### **Explanation:**

The expression evaluates to **True** in **4 ways**:

1. `((T | T) & (F ^ T)) → (T | T) → T, (F ^ T) → T, T & T = T ✅`
2. `(T | (T & (F ^ T))) → (F ^ T) → T, (T & T) → T, T | T = T ✅`
3. `(((T | T) & F) ^ T) → (T | T) → T, (T & F) → F, F ^ T = T ✅`
4. `(T | ((T & F) ^ T)) → (T & F) → F, (F ^ T) → T, T | T = T ✅`

### **Example 2:**

#### **Input:**

```cpp
s = "T^F|F"
```

#### **Output:**

```cpp
2
```

#### **Explanation:**

The expression evaluates to **True** in **2 ways**:

1. `((T^F)|F)`
2. `(T^(F|F))`

## **Constraints:**

- $\(1 \leq |s| \leq 100\)$

## 🎯 **My Approach:**

The problem follows **optimal substructure** and **overlapping subproblems**, making **Dynamic Programming (DP)** the most efficient approach.

We use a **bottom-up DP approach** where we maintain two **2D DP tables**:

- `T[i][j]` → Number of ways to parenthesize `s[i:j]` to get **True**.
- `F[i][j]` → Number of ways to parenthesize `s[i:j]` to get **False**.

### **Algorithm Steps:**

1. **Initialize the DP tables**:

   - If `s[i] == 'T'`, set `T[i][i] = 1` (since a single `T` is always `True`).
   - If `s[i] == 'F'`, set `F[i][i] = 1` (since a single `F` is always `False`).

2. **Fill the DP tables using a bottom-up approach**:

   - Iterate over **subexpressions of increasing length (`l`)**, from **2 to n**.
   - For each subexpression `s[i:j]`, check **each operator `s[k]`** (where `k` is an odd index).
   - Compute `T[i][j]` and `F[i][j]` using **previously computed DP values**.

3. **Update DP values based on the operator `s[k]`**:

   - If `s[k] == '&'` (**AND operator**):
     - `T[i][j] += lt * rt` (both left and right must be True).
     - `F[i][j] += lt * rf + lf * rt + lf * rf` (any case where at least one is False).
   - If `s[k] == '|'` (**OR operator**):
     - `T[i][j] += lt * rt + lt * rf + lf * rt` (only both False make it False).
     - `F[i][j] += lf * rf`.
   - If `s[k] == '^'` (**XOR operator**):
     - `T[i][j] += lt * rf + lf * rt` (one True, one False).
     - `F[i][j] += lt * rt + lf * rf` (both True or both False).

4. **Return `T[0][n-1]`**, which gives the total ways to evaluate `s` to `True`.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N³), as we process all partitions `(i, k, j)` for each segment of `s`.
- **Expected Auxiliary Space Complexity:** O(N²), for storing `T` and `F` DP tables.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
  public:
    int countWays(string &s) {
        int n = s.size();
        vector<vector<int>> T(n, vector<int>(n)), F(n, vector<int>(n));
        for (int i = 0; i < n; i += 2) T[i][i] = s[i] == 'T', F[i][i] = s[i] == 'F';
        for (int l = 2; l < n; l += 2)
            for (int i = 0; i < n - l; i += 2)
                for (int k = i + 1, j = i + l; k < j; k += 2) {
                    int lt = T[i][k - 1], lf = F[i][k - 1], rt = T[k + 1][j], rf = F[k + 1][j];
                    if (s[k] == '&') T[i][j] += lt * rt, F[i][j] += lt * rf + lf * rt + lf * rf;
                    else if (s[k] == '|') T[i][j] += lt * rt + lt * rf + lf * rt, F[i][j] += lf * rf;
                    else T[i][j] += lt * rf + lf * rt, F[i][j] += lt * rt + lf * rf;
                }
        return T[0][n - 1];
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

### **1️⃣ Recursive + Memoization (O(N³) Time, O(N²) Space)**

#### **Algorithm Steps:**

1. Use **Recursion** to break the problem into smaller subproblems.
2. **Memoization** avoids recomputing subproblems.
3. **Base Case**:
   - If `s[i] == 'T'`, return `1`.
   - If `s[i] == 'F'`, return `0`.
4. **Recursive Case**:
   - Divide expression at each operator (`|`, `&`, `^`).
   - Compute left and right parts recursively.
   - Merge results based on the operator.

```cpp
class Solution {
  public:
    unordered_map<string, int> dp;

    int solve(string &s, int i, int j, bool isTrue) {
        if (i > j) return 0;
        if (i == j) return isTrue ? (s[i] == 'T') : (s[i] == 'F');
        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(isTrue);
        if (dp.count(key)) return dp[key];

        int ways = 0;
        for (int k = i + 1; k < j; k += 2) {
            int lt = solve(s, i, k - 1, true);
            int lf = solve(s, i, k - 1, false);
            int rt = solve(s, k + 1, j, true);
            int rf = solve(s, k + 1, j, false);

            if (s[k] == '&') ways += isTrue ? lt * rt : lt * rf + lf * rt + lf * rf;
            else if (s[k] == '|') ways += isTrue ? lt * rt + lt * rf + lf * rt : lf * rf;
            else if (s[k] == '^') ways += isTrue ? lt * rf + lf * rt : lt * rt + lf * rf;
        }
        return dp[key] = ways;
    }

    int countWays(string s) {
        return solve(s, 0, s.size() - 1, true);
    }
};
```

✅ **Time Complexity:** O(N³)  
✅ **Space Complexity:** O(N²)

## **Comparison of Approaches**

| **Approach**                | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                | ⚠️ **Cons**          |
| --------------------------- | ---------------------- | ----------------------- | -------------------------- | -------------------- |
| **DP (Bottom-Up Table)**    | 🟢 O(N³)               | 🟡 O(N²)                | Faster, avoids recursion   | Requires extra space |
| **Recursive + Memoization** | 🟡 O(N³)               | 🔴 O(N²)                | Simple, easy to understand | Uses extra memory    |

✅ **Best Choice?**

- If you want **best efficiency**: Use **DP (Bottom-Up Table)** approach.
- If you like **recursion with memoization**: Use **Recursive Approach**.

</details>

## **Code (Java)**

```java
class Solution {
    static int countWays(String s) {
        int n = s.length();
        int[][] T = new int[n][n], F = new int[n][n];
        for (int i = 0; i < n; i += 2) T[i][i] = s.charAt(i) == 'T' ? 1 : 0;
        for (int i = 0; i < n; i += 2) F[i][i] = s.charAt(i) == 'F' ? 1 : 0;
        for (int l = 2; l < n; l += 2)
            for (int i = 0; i < n - l; i += 2)
                for (int k = i + 1, j = i + l; k < j; k += 2) {
                    int lt = T[i][k - 1], lf = F[i][k - 1], rt = T[k + 1][j], rf = F[k + 1][j];
                    if (s.charAt(k) == '&') {
                        T[i][j] += lt * rt;
                        F[i][j] += lt * rf + lf * rt + lf * rf;
                    } else if (s.charAt(k) == '|') {
                        T[i][j] += lt * rt + lt * rf + lf * rt;
                        F[i][j] += lf * rf;
                    } else {
                        T[i][j] += lt * rf + lf * rt;
                        F[i][j] += lt * rt + lf * rf;
                    }
                }
        return T[0][n - 1];
    }
}
```

## **Code (Python)**

```python
class Solution:
    def countWays(self, s):
        n = len(s)
        T, F = [[0] * n for _ in range(n)], [[0] * n for _ in range(n)]
        for i in range(0, n, 2):
            T[i][i], F[i][i] = int(s[i] == 'T'), int(s[i] == 'F')
        for l in range(2, n, 2):
            for i in range(0, n - l, 2):
                for k, j in zip(range(i + 1, i + l, 2), [i + l] * (l // 2)):
                    lt, lf, rt, rf = T[i][k - 1], F[i][k - 1], T[k + 1][j], F[k + 1][j]
                    if s[k] == '&':
                        T[i][j] += lt * rt
                        F[i][j] += lt * rf + lf * rt + lf * rf
                    elif s[k] == '|':
                        T[i][j] += lt * rt + lt * rf + lf * rt
                        F[i][j] += lf * rf
                    else:
                        T[i][j] += lt * rf + lf * rt
                        F[i][j] += lt * rt + lf * rf
        return T[0][n - 1]
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
