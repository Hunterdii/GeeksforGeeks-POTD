# *22. Minimum Deletions*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/minimum-deletitions1648/1)


## **🧩 Problem Description**

Given a string `s`, the task is to determine the minimum number of characters that must be **deleted** from `s` to convert it into a **palindrome**. The **relative order of remaining characters must be preserved**.

To solve this, we must **maximize** the length of the longest palindromic subsequence (LPS) and subtract its length from the original string length.

### 💬 Key Insight:

* The minimum number of deletions = `len(s) - LPS(s)`
* Where **LPS(s)** is the length of the **Longest Palindromic Subsequence** of `s`.


## **📘 Examples**

### **Example 1:**

#### **Input:**

`s = "aebcbda"`

#### **Output:**

`2`

#### **Explanation:**

The LPS is `"abcba"` (length = 5). Minimum deletions = `7 - 5 = 2`.


### **Example 2:**

#### **Input:**

`s = "geeksforgeeks"`

#### **Output:**

`8`

#### **Explanation:**

The LPS is `"eeggee"` or `"eefeef"` (length = 5). Deletions = `13 - 5 = 8`.


## **🔒 Constraints**

* \$1 \leq \text{length of } s \leq 10^3\$


## **✅ My Approach**

### **Bottom-Up 1D Dynamic Programming (Longest Palindromic Subsequence)**

We compute the **Longest Palindromic Subsequence** (LPS) using dynamic programming.
This optimized implementation uses only two 1D arrays (`dp` and `prev`) to store intermediate LPS lengths.

### **Algorithm Steps:**

1. Initialize two 1D arrays of size `n`: `dp` and `prev`.
2. Start from the end of the string and move backward:

   * For each character `s[i]`:

     * Set `dp[i] = 1` (each character is a palindrome of length 1).
     * Iterate `j` from `i+1` to `n-1`:

       * If `s[i] == s[j]`, set `dp[j] = prev[j-1] + 2`.
       * Else, set `dp[j] = max(prev[j], dp[j-1])`.
   * Copy `dp` to `prev` for the next iteration.
3. Return `n - dp[n-1]`, which is the minimum number of deletions.


## **🧮 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(n²), because we compute values for all pairs `(i, j)` where `i < j`.
* **Expected Auxiliary Space Complexity:** O(n), as we only use two arrays of size `n`.



## **🧠 Code (C++)**

```cpp
class Solution {
  public:
    int minDeletions(string &s) {
        int n = s.size();
        vector<int> dp(n), prev(n);
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = i + 1; j < n; ++j)
                dp[j] = s[i] == s[j] ? prev[j - 1] + 2 : max(prev[j], dp[j - 1]);
            prev = dp;
        }
        return n - dp[n - 1];
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>


## 📊 **2️⃣ LCS with Reversed String (Bottom-Up 2D DP)**

### **Algorithm Steps:**

1. Reverse the input string `s` to get `t`.
2. Compute the **Longest Common Subsequence** (LCS) between `s` and `t` using a 2D table.
3. The LCS of `s` and its reverse is the **Longest Palindromic Subsequence (LPS)**.
4. Return `s.length() - LPS`.

```cpp
class Solution {
  public:
    int minDeletions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dp[i][j] = s[i - 1] == t[j - 1] ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]);
        return n - dp[n][n];
    }
};
```

### ✅ **Why This Approach?**

* Classic LCS technique reused to find LPS.
* Easy to understand and debug.

#### 📝 **Complexity Analysis:**

* **Time:** O(n²)
* **Auxiliary Space:** O(n²)


## 📊 **3️⃣ LCS with Reversed String (Space Optimized)**

### **Algorithm Steps:**

1. Reverse the string `s` to get `t`.
2. Use two 1D vectors to compute LCS between `s` and `t` in a space-optimized way.
3. Result = `s.length() - LCS`.

```cpp
class Solution {
  public:
    int minDeletions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector<int> prev(n + 1), curr(n + 1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)
                curr[j] = s[i - 1] == t[j - 1] ? 1 + prev[j - 1] : max(prev[j], curr[j - 1]);
            swap(prev, curr);
        }
        return n - prev[n];
    }
};
```

### ✅ **Why This Approach?**

* Minimizes memory use with only two rows.
* Retains full accuracy and speed of 2D DP.

#### 📝 **Complexity Analysis:**

* **Time:** O(n²)
* **Auxiliary Space:** O(n)


## 🆚 **Comparison of Approaches**

| **Approach**                        | ⏱️ **Time** | 🗂️ **Space** | ✅ **Pros**                        | ⚠️ **Cons**                   |
| ----------------------------------- | ----------- | ------------- | --------------------------------- | ----------------------------- |
| Original (1D DP from end)           | 🟢 O(n²)    | 🟢 O(n)       | Compact, direct LPS logic         | Harder to grasp for beginners |
| LCS with Reversed (2D DP)           | 🟢 O(n²)    | 🔸 O(n²)      | Classic, easy to write            | Higher memory usage           |
| LCS with Reversed (Space Optimized) | 🟢 O(n²)    | 🟢 O(n)       | Balanced: space-efficient + clear | Slightly longer to implement  |


### ✅ **Best Choice?**

| **Scenario**                             | **Recommended Approach**         |
| ---------------------------------------- | -------------------------------- |
| Space optimized solution                 | 🥇 Original 1D DP from end       |
| Beginner-friendly or educational purpose | 🥈 LCS with Reversed (2D DP)     |
| Balanced readability + performance       | 🥉 LCS with Reversed (Optimized) |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    static int minDeletions(String s) {
        int n = s.length();
        int[] dp = new int[n], prev = new int[n];
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1;
            for (int j = i + 1; j < n; ++j)
                dp[j] = s.charAt(i) == s.charAt(j) ? prev[j - 1] + 2 : Math.max(prev[j], dp[j - 1]);
            prev = dp.clone();
        }
        return n - dp[n - 1];
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minDeletions(self, s):
        n = len(s)
        dp = [0] * n
        prev = [0] * n
        for i in range(n - 1, -1, -1):
            dp[i] = 1
            for j in range(i + 1, n):
                dp[j] = prev[j - 1] + 2 if s[i] == s[j] else max(prev[j], dp[j - 1])
            prev = dp[:]
        return n - dp[-1]
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
