# _7. Longest Palindromic Subsequence_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1)

## **Problem Description**

Given a string `s`, return the length of the **longest palindromic subsequence**.

A **subsequence** is a sequence derived from the given sequence by deleting some or no elements without changing the order of the remaining elements.  
A **palindromic subsequence** reads the same forwards and backwards.

## **Examples**

### **Example 1:**

#### **Input:**

`s = "bbabcbcab"`

#### **Output:**

`7`

#### **Explanation:**

The longest palindromic subsequence is `"babcbab"`, which has a length of **7**.

### **Example 2:**

#### **Input:**

`s = "abcd"`

#### **Output:**

`1`

#### **Explanation:**

The longest palindromic subsequence is any single character, which has a length of **1**.

### **Example 3:**

#### **Input:**

`s = "agbdba"`

#### **Output:**

`5`

#### **Explanation:**

The longest palindromic subsequence is `"abdba"`, which has a length of **5**.

### **Constraints:**

- $1 \leq s.size() \leq 1000$
- The string contains only lowercase letters.

## **My Approach**

### **DP - Bottom-Up 2D Table**

### **Algorithm Steps:**

1. Create a **2D DP table**, where `dp[i][j]` stores the **length of the longest palindromic subsequence** in substring `s[i...j]`.
2. Initialize **diagonal elements (`dp[i][i]`) to 1**, since a single character is always a palindrome of length 1.
3. Iterate over substrings of increasing lengths.
4. For each substring `s[i...j]`:
   - If `s[i] == s[j]`, the length extends by 2 (both characters can form a palindrome around the inner subsequence `s[i+1...j-1]`).
   - Otherwise, take the maximum palindromic subsequence length by either excluding `s[i]` or excluding `s[j]`.
5. Final answer is stored in `dp[0][n-1]` — the longest palindromic subsequence in the entire string.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** $O(N^2)$, as we fill a 2D DP table for all substrings, and each cell is filled in constant time.

- **Expected Auxiliary Space Complexity:** $O(N^2)$, for storing the DP table, which tracks the longest palindromic subsequence length for each substring.

## **Code (C++)**

```cpp
class Solution {
public:
    int longestPalinSubseq(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Space Optimized Dynamic Programming (O(N²) Time, O(N) Space)**

### **Algorithm Steps:**

- We only need the **current and previous rows**, so the 2D table can be reduced to **two 1D arrays**.
- Iterate over `i` (backwards) and `j` (forwards), and fill only the current row using the previous row.
- This reduces space from **O(N²)** to **O(N)**.

```cpp
class Solution {
public:
    int longestPalinSubseq(string &s) {
        int n = s.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == s[n - j])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            swap(prev, curr);
        }
        return prev[n];
    }
};
```

## **3️⃣ Recursive + Memoization (O(N²) Time, O(N²) Space)**

### **Algorithm Steps:**

- Use **recursive DFS with memoization**.
- If characters match, extend the palindrome.
- Otherwise, check both possibilities (exclude either character).
- Cache results to avoid redundant work.

```cpp
class Solution {
public:
    int helper(string &s, int i, int j, vector<vector<int>> &dp) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == s[j])
            return dp[i][j] = 2 + helper(s, i + 1, j - 1, dp);
        return dp[i][j] = max(helper(s, i + 1, j, dp), helper(s, i, j - 1, dp));
    }

    int longestPalinSubseq(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(s, 0, n - 1, dp);
    }
};
```

## 📊 **Comparison of Approaches**

| **Approach**                | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**             | ⚠️ **Cons**                    |
| --------------------------- | ---------------------- | ----------------------- | ----------------------- | ------------------------------ |
| **2D DP Table**             | 🟡 O(N²)               | 🔴 O(N²)                | Simple & intuitive      | High space usage               |
| **Space Optimized 1D DP**   | 🟡 O(N²)               | 🟢 O(N)                 | Lower space             | Slightly trickier to implement |
| **Recursive + Memoization** | 🟡 O(N²)               | 🔴 O(N²)                | Natural recursive logic | Recursion overhead             |

## 💡 **Best Choice?**

- ✅ **For balanced space and time:** Use **Space Optimized 1D DP**.
- ✅ **For simplicity and clarity:** Use **2D DP Table**.
- ✅ **For recursive enthusiasts:** Use **Recursive + Memoization**.

</details>

## **Code (Java)**

```java
class Solution {
    public int longestPalinSubseq(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s.charAt(i) == s.charAt(j))
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
}
```

## **Code (Python)**

```python
class Solution:
    def longestPalinSubseq(self, s):
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            dp[i][i] = 1
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    dp[i][j] = 2 + dp[i + 1][j - 1]
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
        return dp[0][n - 1]
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
