# _6. Longest Common Subsequence_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1)

## **Problem Description**

Given **two strings** `s1` and `s2`, **return the length of their longest common subsequence (LCS)**. If there is no common subsequence, return `0`.

A **subsequence** is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements. For example, `"ABE"` is a subsequence of `"ABCDE"`.

## **Examples**

### **Example 1:**

#### **Input:**

```
s1 = "ABCDGH", s2 = "AEDFHR"
```

#### **Output:**

```
3
```

#### **Explanation:**

The longest common subsequence of `"ABCDGH"` and `"AEDFHR"` is **"ADH"**, which has a length of 3.

### **Example 2:**

#### **Input:**

```
s1 = "ABC", s2 = "AC"
```

#### **Output:**

```
2
```

#### **Explanation:**

The longest common subsequence of `"ABC"` and `"AC"` is **"AC"**, which has a length of 2.

### **Example 3:**

#### **Input:**

```
s1 = "XYZW", s2 = "XYWZ"
```

#### **Output:**

```
3
```

#### **Explanation:**

The longest common subsequences of `"XYZW"` and `"XYWZ"` are **"XYZ"** and **"XYW"**, both of length 3.

### **Constraints:**

- $\(1 \leq \text{length}(s1), \text{length}(s2) \leq 10^3\)$
- Both `s1` and `s2` contain only **uppercase English letters**.

## **My Approach**

### **Space-Optimized 1D DP**

### **Key Idea**

- Use **only two arrays (current and previous rows)** to store LCS lengths for substrings.
- The value at `dp[j]` represents the **LCS length of `s1[0..i-1]` and `s2[0..j-1]`**.
- Only **the previous row is needed** to compute the current row, so space is reduced to **O(M)**, where M is the length of the second string.

### **Algorithm Steps**

1. Use two **rolling 1D arrays** (or one array with a few variables) to store only the previous row and current row.
2. **Traverse** the strings from `i = 1..n` and `j = 1..m`:
   - If `s1[i - 1] == s2[j - 1]`, we do `curr[j] = prev[j - 1] + 1`.
   - Else, `curr[j] = max(prev[j], curr[j - 1])`.
3. **Swap** `prev` and `curr` at the end of each `i` iteration.
4. The result is `prev[m]`, which is the **length of LCS**.

This approach is more **space-efficient** than the standard `O(N * M)` DP table because it only keeps **two rows** (or one row with updates).

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(N * M)`, where `N` is the length of `s1` and `M` is the length of `s2`.
- **Expected Auxiliary Space Complexity:** `O(N)`, using the space-optimized approach (storing only one dimension).

## **Code (C++)**

```cpp
class Solution {
public:
    int lcs(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                curr[j] = s1[i - 1] == s2[j - 1] ? prev[j - 1] + 1 : max(prev[j], curr[j - 1]);
            }
            swap(prev, curr);
        }
        return prev[m];
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Dynamic Programming with 2D Table (O(N _ M) Time, O(N _ M) Space)**

### **Algorithm Steps:**

1. Create a 2D table `dp` where `dp[i][j]` stores the **length of the LCS of s1[0..i-1] and s2[0..j-1]**.
2. If characters match, `dp[i][j] = dp[i-1][j-1] + 1`.
3. If characters don't match, `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`.
4. Return `dp[n][m]`, the LCS length.

```cpp
class Solution {
public:
    int lcs(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};
```

🔹 **Easier to visualize** the DP table.  
🔹 **Simpler to reconstruct** the actual LCS if needed.

## **3️⃣ Recursive + Memoization (Top-Down DP, O(N \* M))**

### **Algorithm Steps:**

1. Define a function `helper(i, j)` that returns the LCS of `s1[0..i-1]` and `s2[0..j-1]`.
2. If characters match, `1 + helper(i-1, j-1)`.
3. Otherwise, `max(helper(i-1, j), helper(i, j-1))`.
4. Use a 2D memo array `dp[i][j]` to **avoid recalculations**.

```cpp
class Solution {
public:
    int lcs(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return helper(s1, s2, n, m, dp);
    }
    int helper(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if (i == 0 || j == 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (s1[i - 1] == s2[j - 1])
            return dp[i][j] = 1 + helper(s1, s2, i - 1, j - 1, dp);
        return dp[i][j] = max(helper(s1, s2, i - 1, j, dp), helper(s1, s2, i, j - 1, dp));
    }
};
```

🔹 **Top-down approach** can be more intuitive for some.  
🔹 **Same `O(N*M)` complexity** with memoization.

## **📊 Comparison of Approaches**

| **Approach**               | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**        | ⚠️ **Cons**              |
| -------------------------- | ---------------------- | ----------------------- | ------------------ | ------------------------ |
| **Space-Optimized 1D DP**  | 🟢 O(N \* M)           | 🟢 O(N)                 | Memory efficient   | No reconstruction        |
| **2D Dynamic Programming** | 🟢 O(N \* M)           | 🔴 O(N \* M)            | Full table stored  | Higher space usage       |
| **Memoized Recursive**     | 🟢 O(N \* M)           | 🟡 O(N \* M)            | Intuitive for some | Needs recursion overhead |

## 💡 **Best Choice?**

- ✅ Use **Space-Optimized 1D DP** for **length-only** queries.
- ✅ Use **2D DP with Backtracking** if you need to **recover the actual LCS string**.
- ✅ Use **Recursive + Memoization** for **simple coding competitions** (top-down is intuitive for some coders).

</details>

## **Code (Java)**

```java
class Solution {
    static int lcs(String s1, String s2) {
        int n = s1.length(), m = s2.length();
        int[] prev = new int[m + 1], curr = new int[m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                curr[j] = s1.charAt(i - 1) == s2.charAt(j - 1) ? prev[j - 1] + 1 : Math.max(prev[j], curr[j - 1]);
            }
            int[] temp = prev; prev = curr; curr = temp;
        }
        return prev[m];
    }
}
```

## **Code (Python)**

```python
class Solution:
    def lcs(self, s1, s2):
        m, n = len(s1), len(s2)
        dp = [0] * (n + 1)
        for i in range(m):
            prev = 0
            for j in range(n):
                temp = dp[j + 1]
                dp[j + 1] = prev + 1 if s1[i] == s2[j] else max(dp[j + 1], dp[j])
                prev = temp
        return dp[n]
```

## **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
